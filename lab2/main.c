//Lab2 - dretve i semafori

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

#include "postavke.h"
#include "slucajni_brojevi.h"
#include "medjuspremnik.h"

static int pocetno_postavljanje();
static void obradi_signal(int sig);
static void *posao_dretve(void *x);

static int kraj_rada = 0;
static int status = 0;
static pthread_t opisnik[BROJ_DRETVI];
sem_t sem, sem2[BROJ_DRETVI]; //svaka dretva ima svoj semafor
static long id_dretvi = 1; //svaka dretva uzima jedan id, pocevsi od 1

int main()
{
	sem_init(&sem, 0, 1); //potrebno zbog log -- na pocetku je semafor prolazan
	log("Pocetna inicijalizacija"); 
	if (pocetno_postavljanje())
		return -1;

	log("Inicijalizacija gotova, krecem s radom (PID=%ld)", (long) getpid());

	//stvori dretve
	// NAPRAVITI
	for (int i = 0; i < BROJ_DRETVI; i++) {
		if (pthread_create(&opisnik[i], NULL, posao_dretve, NULL) != 0) { //stvaraju se tri drevte koje paralelno izvode fju posao_dretve
			fprintf(stderr, "Ne mogu stvoriti novu dretvu!\n");
			exit(1);
		}
	}

	//čekaj na kraj rada dretvi
	// NAPRAVITI
	for (int i = 0; i < BROJ_DRETVI; i++) {
		pthread_join(opisnik[i], NULL);
	}


	//kraj_rada postavljen na SIGTERM, zapiši stanje
	FILE *fp = fopen("status.txt", "w");
	if (!fp) {
		fprintf(stderr, "Greska pri otvaranju status.txt");
		status = -1;
	}
	else {
		lcg_zapisi_stanje(fp);
		zapisi_stanje_medjuspremnika(fp);
		fclose(fp);
	}

	// unisti semafore
	sem_destroy(&sem);  // glavni semafor za log i kriticne sekcije
	for (int i = 0; i < BROJ_DRETVI; i++)
		sem_destroy(&sem2[i]);

	return status;
}

static void *posao_dretve(void *x)
{
	long id = __atomic_fetch_add(&id_dretvi, 1, __ATOMIC_SEQ_CST);

	log("Dretva %ld krece s radom", id);
	while (!kraj_rada) {

		long broj = lcg_gen();
		while ((broj & 1) == 0 || broj % 3 == 0 || broj % 5 == 0)  // preskace brojeve djeljive s 2, 3, 5
			broj = lcg_gen();
		
		while (!kraj_rada && dodaj_u_medjuspremnik(broj) == -1) {
			log("Dretva %ld: medjuspremnik pun, cekam", id);
			sem_wait(&sem2[id - 1]);
		}

		if (kraj_rada)
			break;

		log("Dretva %ld: dodao broj %ld", id, broj);
		sleep(1); // pauza radi preglednosti

	}

	log("Dretva %ld zavrsava", id);
	return NULL;
}


static int pocetno_postavljanje()
{
	//isto kao i prije, plus inicijalizacija semafora
	//ako postoji datoteka status.txt iz nje procitati stanje
	FILE *fp = fopen("status.txt", "r");

	/* Ocekivani format:
	<podaci generatora slucajnih brojeva>
	<podaci iz medjuspremnika>
	*/

	if (fp) {
		//postoji
		log("Ucitavam staro stanje iz status.txt");
		lcg_ucitaj_stanje(fp);
		otkljucaj();
		ucitaj_stanje_medjuspremnika(fp); //ovdje dva puta zakljucamo pa moramo i onda jos jednom otkljucati jer ce ostati zakljucano
		fclose(fp);
	}
	else {
		//ne postoji, inicijaliziraj generator slucajnih brojeva
		lcg_postavi((long long) time(NULL));
	}

	//postavi signale
	struct sigaction act;

	/* 1. maskiranje signala SIGUSR1 */
	act.sa_handler = obradi_signal;
	sigemptyset(&act.sa_mask); //nema blokiranja  -- tako da drugi signali (i isti) mogu doci tokom obrade
	act.sa_flags = 0;
	sigaction(SIGUSR1, &act, NULL);

	/* 2. maskiranje signala SIGTERM */
	act.sa_handler = obradi_signal;
	sigemptyset(&act.sa_mask);
	sigaction(SIGTERM, &act, NULL);

	/* 3. maskiranje signala SIGUSR2 */
	act.sa_handler = obradi_signal;
	sigemptyset(&act.sa_mask);
	sigaction(SIGUSR2, &act, NULL);

	/* 4. maskiranje signala SIGINT */
	act.sa_handler = obradi_signal;
	sigemptyset(&act.sa_mask);
	sigaction(SIGINT, &act, NULL);

	// inicijalizacija semafora za dretve
	for (int i = 0; i < BROJ_DRETVI; i++)
		sem_init(&sem2[i], 0, 0); // pocetno blokirane -  pocetna vrijednost semafora je nula, tj. zakljucan je.

	return 0;
}

static void posalji_signale_dretvama(int sig) // funkcija koja budi semafore
{
	int i;
	for (i = 0; i < BROJ_DRETVI; i++)
		sem_post(&sem2[i]); //svaka dretva koja je trenutno blokirana na sem_wait() ce nastaviti rad.

}
static void obradi_signal(int sig)
{
	if (sig == SIGUSR1) {
		log("\nsignal SIGUSR1");
		long broj = uzmi_iz_medjuspremnika();
		printf("%ld\n", broj);
		posalji_signale_dretvama(sig);
	}
	else if (sig == SIGUSR2) {
		// NAPRAVITI
		log("\nsignal SIGUSR2");
		while(1){
			long broj = uzmi_iz_medjuspremnika();
			if(broj == -1) break;
			else printf("%ld\n", broj);
		}
		posalji_signale_dretvama(sig);
	}
	else if (sig == SIGTERM) {
		// NAPRAVITI
		log("\nsignal SIGTERM");
		kraj_rada = 1; // dretve izlaze iz petlje.
		posalji_signale_dretvama(sig);
	}
	else if (sig == SIGINT) {
		// NAPRAVITI
		log("\nsignal SIGINT");
		while(1){
			long broj = uzmi_iz_medjuspremnika();
			if(broj == -1) break;
		}
		posalji_signale_dretvama(sig);
	}
}

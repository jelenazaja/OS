//lab3

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
static void stvori_dretve(int n);
static void *posao_dretve(void *x);

static int kraj_rada = 0;
static int status = 0;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER; //ne treba pthread_init
pthread_cond_t red = PTHREAD_COND_INITIALIZER;

static int broj_dretvi = BROJ_DRETVI; //koliko trenutno iman
static int postavljeni_broj_dretvi = BROJ_DRETVI; //koliko zelim
static long id_dretvi = 1;

int main()
{	
	log("Pocetna inicijalizacija");
	if (pocetno_postavljanje())
		return -1;

	log("Inicijalizacija gotova, krecem s radom (PID=%ld)", (long) getpid());

	//stvori dretve
	stvori_dretve(BROJ_DRETVI);

	//čekaj na kraj rada dretvi
	while (!kraj_rada)
		pause();

	//ako još koja dretva nije gotova
	sleep(1);

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

	pthread_mutex_destroy(&m);
	pthread_cond_destroy(&red);

	return status;
}

static void stvori_dretve(int n)
{
	pthread_t opisnik;

	for (int i = 0; i < n; i++) {
		if (pthread_create(&opisnik, NULL, posao_dretve, NULL) != 0) {
			perror("Greška pri stvaranju dretve");
			continue;
		}
	}
}


static void *posao_dretve(void *x)
{
	pthread_detach(pthread_self());
	long id = __atomic_fetch_add(&id_dretvi, 1, __ATOMIC_SEQ_CST);

	log("Dretva %ld krece s radom", id);

	while (!kraj_rada) {
	
		long broj = lcg_gen();
		while ((broj & 1) == 0 || broj % 3 == 0 || broj % 5 == 0)  // preskace brojeve djeljive s 2, 3, 5
			broj = lcg_gen();
		
	
		while (!kraj_rada && dodaj_u_medjuspremnik(broj) == -1) {
			log("Dretva %ld: medjuspremnik pun, cekam", id);

			zakljucaj();
			pthread_cond_wait(&red, &m);	
			
			if(broj_dretvi > postavljeni_broj_dretvi) //postoji li razlika -- treba ta dretva zavrsit s radom 
			{
				broj_dretvi--;
				otkljucaj();
				log("Dretva %ld zavrsava jer ih ima previse", id);
				pthread_exit(NULL);  //zavrsavamo s radom
			}
			
			otkljucaj();			
		}
		
		if (kraj_rada)
		{	
			 break;
		}
			

		log("Dretva %ld: dodao broj %ld", id, broj); 
		sleep(1); 
	
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
		ucitaj_stanje_medjuspremnika(fp); 
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


	return 0;
}

static void obradi_signal(int sig)
{  
	if (sig == SIGUSR1) {

		log("\nsignal SIGUSR1");
		long broj = uzmi_iz_medjuspremnika();
		printf("%ld\n", broj);

       int delta = (lcg_gen() % 5) + 1;
	   if (lcg_gen() % 2 == 0) {

            postavljeni_broj_dretvi += delta;
            log("Povecavam broj dretvi za %d", delta);
			
			stvori_dretve(delta);
			broj_dretvi += delta;

        } else 
		{ //nasumicno smanjimo
           if (postavljeni_broj_dretvi - delta < 1)
                delta = postavljeni_broj_dretvi - 1;

            postavljeni_broj_dretvi -= delta;
            log("Smanjujem broj dretvi za %d", delta);
        }

		pthread_cond_broadcast(&red);

	}
	else if (sig == SIGUSR2) {
		log("\nsignal SIGUSR2");
		while(1){
			long broj = uzmi_iz_medjuspremnika();
			if(broj == -1) break;
			else printf("%ld\n", broj);
		}
		
		pthread_cond_broadcast(&red); 
		
	}
	else if (sig == SIGTERM) {
		log("\nsignal SIGTERM");
		kraj_rada = 1; // dretve izlaze iz petlje.
		pthread_cond_broadcast(&red); 
		
	}
	else if (sig == SIGINT) {
		log("\nsignal SIGINT");
		while(1){
			long broj = uzmi_iz_medjuspremnika();
			if(broj == -1) break;
		}
		pthread_cond_broadcast(&red); 
	}
}

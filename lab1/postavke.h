//Neke postavke i makroi

#define DEBUG //komentirati ako se ne želi taj ispis
#define VEL_M	8

//da ne bi paralelno pristupali međuspremniku
//za sada problem može biti zbog signala
#include <signal.h>
#include <stdlib.h>

static inline void zakljucaj()
{
	sigset_t set;
	sigemptyset(&set); //prazan skup
	sigaddset(&set, SIGUSR1); //dodamo signale koje zelimo blokirati u skup
	sigaddset(&set, SIGTERM);
	sigaddset(&set, SIGUSR2);
	sigaddset(&set, SIGINT);
	sigprocmask(SIG_BLOCK, &set, NULL); //blokiramo te signale
}
static inline void otkljucaj()
{
	sigset_t set;
	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGTERM);
	sigaddset(&set, SIGUSR2);
	sigaddset(&set, SIGINT);
	sigprocmask(SIG_UNBLOCK, &set, NULL); //odblokiramo te signale
}

#ifdef DEBUG
#include <stdio.h>

//ispis, ali zelenom bojom
//korištenje: log = printf, uz \n na kraju (ne treba \n dodavati kad se koristi log)
#define log(format, ...)			\
do {						\
	zakljucaj();				\
	printf("\x1b[32m");			\
	printf(format "\n", ##__VA_ARGS__);	\
	printf("\x1b[39m");			\
	otkljucaj();				\
}						\
while(0)

#else

#define log(format, ...)

#endif

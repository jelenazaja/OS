Terminal 1:
	$ make pokreni


cc -Wall -MMD   -c -o main.o main.c
cc -Wall -MMD   -c -o medjuspremnik.o medjuspremnik.c
cc -Wall -MMD   -c -o slucajni_brojevi.o slucajni_brojevi.c
cc -O main.o medjuspremnik.o slucajni_brojevi.o -lm -lpthread -o main
Pocetna inicijalizacija
Inicijalizacija gotova, krecem s radom (PID=1668)
Dretva 1 krece s radom
Dretva 1: dodao broj 943116841
Dretva 2 krece s radom
Dretva 3 krece s radom
Dretva 3: dodao broj 1769715079
Dretva 2: dodao broj 929764411
Dretva 1: dodao broj 2712121933
Dretva 3: dodao broj 1242436001
Dretva 2: dodao broj 593452733
Dretva 1: dodao broj 605964143
Dretva 3: dodao broj 1717023193
Dretva 2: medjuspremnik pun, cekam
Dretva 1: medjuspremnik pun, cekam
Dretva 3: medjuspremnik pun, cekam

signal SIGUSR1
943116841
Dretva 3: medjuspremnik pun, cekam
Dretva 2: dodao broj 1717023193
Dretva 1: medjuspremnik pun, cekam
Dretva 2: medjuspremnik pun, cekam

signal SIGUSR2
1769715079
929764411
2712121933
1242436001
593452733
605964143
1717023193
1717023193
Dretva 1: dodao broj 1534234027
Dretva 3: dodao broj 2170620311
Dretva 2: dodao broj 3140842843
Dretva 2: dodao broj 593822903
Dretva 3: dodao broj 593822903
Dretva 1: dodao broj 1688449453
Dretva 2: dodao broj 2230413119
Dretva 3: dodao broj 1353324553
Dretva 1: medjuspremnik pun, cekam
Dretva 2: medjuspremnik pun, cekam
Dretva 3: medjuspremnik pun, cekam

signal SIGINT
Dretva 2: dodao broj 1778136673
Dretva 1: dodao broj 2103135733
Dretva 3: dodao broj 3920503019
Dretva 2: dodao broj 1867846243
Dretva 1: dodao broj 1785019169
Dretva 3: dodao broj 2967502933
Dretva 2: dodao broj 1494237307
Dretva 1: dodao broj 3361943591
Dretva 3: medjuspremnik pun, cekam
Dretva 2: medjuspremnik pun, cekam
Dretva 1: medjuspremnik pun, cekam

signal SIGTERM
Dretva 3 zavrsava
Dretva 1 zavrsava
Dretva 2 zavrsava

Terminal 2:
	$ kill -SIGUSR1 1668
	$ kill -SIGUSR2 1668
	$ kill -SIGINT 1668
	$ kill -SIGTERM 1668

Datoteka status.txt: 
	272594134229053
	8
	1778136673
	2103135733
	3920503019
	1867846243
	1785019169
	2967502933
	1494237307
	3361943591

Ponovno pokretanje:

Terminal 1:
	$ make pokreni

Pocetna inicijalizacija
Ucitavam staro stanje iz status.txt
Inicijalizacija gotova, krecem s radom (PID=1683)
Dretva 1 krece s radom
Dretva 2 krece s radom
Dretva 3 krece s radom
Dretva 3: medjuspremnik pun, cekam
Dretva 2: medjuspremnik pun, cekam
Dretva 1: medjuspremnik pun, cekam

signal SIGUSR1
1778136673
Dretva 1: dodao broj 4125994087
Dretva 3: medjuspremnik pun, cekam
Dretva 2: medjuspremnik pun, cekam
Dretva 1: medjuspremnik pun, cekam

signal SIGUSR2
2103135733
3920503019
1867846243
1785019169
2967502933
1494237307
3361943591
4125994087
Dretva 1: dodao broj 1078847227
Dretva 2: dodao broj 651497053
Dretva 3: dodao broj 4064678047
Dretva 1: dodao broj 2904295543
Dretva 2: dodao broj 4097411129
Dretva 3: dodao broj 2186561639
Dretva 1: dodao broj 1451835601
Dretva 2: dodao broj 23692391
Dretva 3: medjuspremnik pun, cekam
Dretva 1: medjuspremnik pun, cekam
Dretva 2: medjuspremnik pun, cekam

signal SIGINT
Dretva 1: dodao broj 2574028111
Dretva 2: dodao broj 186441907
Dretva 3: dodao broj 4041641099
Dretva 1: dodao broj 3183873001
Dretva 2: dodao broj 2528667173
Dretva 3: dodao broj 1020977477
Dretva 1: dodao broj 831975599
Dretva 2: dodao broj 2289493777
Dretva 3: medjuspremnik pun, cekam
Dretva 1: medjuspremnik pun, cekam
Dretva 2: medjuspremnik pun, cekam

signal SIGTERM
Dretva 2 zavrsava
Dretva 3 zavrsava
Dretva 1 zavrsava

Terminal 2:

	$ kill -SIGUSR1 1683
	$ kill -SIGUSR2 1683
	$ kill -SIGINT 1683
	$ kill -SIGTERM 1683

Datoteka status.txt:
	86285604711297
	8
	2574028111
	186441907
	4041641099
	3183873001
	2528667173
	1020977477
	831975599
	2289493777


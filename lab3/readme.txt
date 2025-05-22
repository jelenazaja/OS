Terminal 1:

$ make pokreni

Pocetna inicijalizacija
Inicijalizacija gotova, krecem s radom (PID=2438)
Dretva 1 krece s radom
Dretva 2 krece s radom
Dretva 3 krece s radom
Dretva 2: dodao broj 3391298327
Dretva 3: dodao broj 4200363191
Dretva 1: dodao broj 3835175011
Dretva 3: dodao broj 2557740013
Dretva 2: dodao broj 3758243021
Dretva 1: dodao broj 1291791691
Dretva 3: dodao broj 1912480403
Dretva 2: dodao broj 3757142377
Dretva 1: medjuspremnik pun, cekam
Dretva 3: medjuspremnik pun, cekam
Dretva 2: medjuspremnik pun, cekam

signal SIGUSR1
3391298327
Povecavam broj dretvi za 3
Dretva 4 krece s radom
Dretva 3: dodao broj 1506036251
Dretva 5 krece s radom
Dretva 6 krece s radom
Dretva 2: medjuspremnik pun, cekam
Dretva 4: medjuspremnik pun, cekam
Dretva 1: medjuspremnik pun, cekam
Dretva 6: medjuspremnik pun, cekam
Dretva 5: medjuspremnik pun, cekam
Dretva 3: medjuspremnik pun, cekam

signal SIGUSR1
4200363191
Povecavam broj dretvi za 3
Dretva 7 krece s radom
Dretva 8 krece s radom
Dretva 5: medjuspremnik pun, cekam
Dretva 1: medjuspremnik pun, cekam
Dretva 2: medjuspremnik pun, cekam
Dretva 9 krece s radom
Dretva 3: medjuspremnik pun, cekam
Dretva 4: dodao broj 1307383217
Dretva 9: medjuspremnik pun, cekam
Dretva 8: medjuspremnik pun, cekam
Dretva 6: medjuspremnik pun, cekam
Dretva 7: medjuspremnik pun, cekam
Dretva 4: medjuspremnik pun, cekam

signal SIGINT
Dretva 5: dodao broj 3009410009
Dretva 6: dodao broj 2778877231
Dretva 1: dodao broj 843473929
Dretva 9: dodao broj 1887897241
Dretva 7: dodao broj 451220389
Dretva 2: dodao broj 1479857539
Dretva 3: dodao broj 1502872481
Dretva 8: medjuspremnik pun, cekam
Dretva 4: dodao broj 3054325867
Dretva 5: medjuspremnik pun, cekam
Dretva 6: medjuspremnik pun, cekam
Dretva 1: medjuspremnik pun, cekam
Dretva 9: medjuspremnik pun, cekam
Dretva 7: medjuspremnik pun, cekam
Dretva 2: medjuspremnik pun, cekam
Dretva 3: medjuspremnik pun, cekam
Dretva 4: medjuspremnik pun, cekam

signal SIGUSR2
3009410009
2778877231
843473929
1887897241
451220389
1479857539
1502872481
3054325867
Dretva 4: dodao broj 1038384077
Dretva 2: dodao broj 3465869233
Dretva 9: dodao broj 1783126849
Dretva 3: dodao broj 1384811383
Dretva 1: dodao broj 136149659
Dretva 8: dodao broj 287720453
Dretva 6: dodao broj 3990184039
Dretva 5: dodao broj 60762299
Dretva 7: medjuspremnik pun, cekam
Dretva 4: medjuspremnik pun, cekam
Dretva 2: medjuspremnik pun, cekam
Dretva 9: medjuspremnik pun, cekam
Dretva 3: medjuspremnik pun, cekam
Dretva 1: medjuspremnik pun, cekam
Dretva 8: medjuspremnik pun, cekam
Dretva 6: medjuspremnik pun, cekam
Dretva 5: medjuspremnik pun, cekam

signal SIGUSR1
287720453
Smanjujem broj dretvi za 3
Dretva 4 zavrsava jer ih ima previse
Dretva 7 zavrsava jer ih ima previse
Dretva 9 zavrsava jer ih ima previse
Dretva 1: dodao broj 920387059
Dretva 6: medjuspremnik pun, cekam
Dretva 3: medjuspremnik pun, cekam
Dretva 5: medjuspremnik pun, cekam
Dretva 8: medjuspremnik pun, cekam
Dretva 2: medjuspremnik pun, cekam
Dretva 1: medjuspremnik pun, cekam

signal SIGTERM
Dretva 3 zavrsava
Dretva 6 zavrsava
Dretva 5 zavrsava
Dretva 2 zavrsava
Dretva 8 zavrsava
Dretva 1 zavrsava

Terminal 2: 

$ kill -SIGUSR1 2438
$ kill -SIGUSR1 2438
$ kill -SIGINT 2438
$ kill -SIGUSR2 2438
$ kill -SIGUSR1 2438
$ kill -SIGTERM 2438

Datoteka status.txt na kraju:
122859630355342
8
1038384077
3465869233
60762299
1783126849
3990184039
1384811383
136149659
920387059

Terminal 1:

$ make pokreni

Pocetna inicijalizacija
Ucitavam staro stanje iz status.txt
Inicijalizacija gotova, krecem s radom (PID=2461)
Dretva 1 krece s radom
Dretva 1: medjuspremnik pun, cekam
Dretva 3 krece s radom
Dretva 3: medjuspremnik pun, cekam
Dretva 2 krece s radom
Dretva 2: medjuspremnik pun, cekam

signal SIGUSR1
1038384077
Smanjujem broj dretvi za 1
Dretva 1 zavrsava jer ih ima previse
Dretva 3: dodao broj 2408324581
Dretva 2: medjuspremnik pun, cekam
Dretva 3: medjuspremnik pun, cekam

signal SIGUSR1
3465869233
Povecavam broj dretvi za 1
Dretva 4 krece s radom
Dretva 2: dodao broj 2105387167
Dretva 3: medjuspremnik pun, cekam
Dretva 4: medjuspremnik pun, cekam
Dretva 2: medjuspremnik pun, cekam

signal SIGUSR1
60762299
Smanjujem broj dretvi za 1
Dretva 3 zavrsava jer ih ima previse
Dretva 2: dodao broj 2507782211
Dretva 4: medjuspremnik pun, cekam
Dretva 2: medjuspremnik pun, cekam

signal SIGUSR1
1783126849
Smanjujem broj dretvi za 1
Dretva 4 zavrsava jer ih ima previse
Dretva 2: dodao broj 4130738527
Dretva 2: medjuspremnik pun, cekam

signal SIGUSR1
3990184039
Povecavam broj dretvi za 4
Dretva 5 krece s radom
Dretva 7 krece s radom
Dretva 8 krece s radom
Dretva 2: dodao broj 427575653
Dretva 6 krece s radom
Dretva 8: medjuspremnik pun, cekam
Dretva 7: medjuspremnik pun, cekam
Dretva 6: medjuspremnik pun, cekam
Dretva 5: medjuspremnik pun, cekam
Dretva 2: medjuspremnik pun, cekam

signal SIGTERM
Dretva 7 zavrsava
Dretva 8 zavrsava
Dretva 6 zavrsava
Dretva 2 zavrsava
Dretva 5 zavrsava

Terminal 2:

$ kill -SIGUSR1 2461
$ kill -SIGUSR1 2461
$ kill -SIGUSR1 2461
$ kill -SIGUSR1 2461
$ kill -SIGUSR1 2461
$ kill -SIGTERM 2461
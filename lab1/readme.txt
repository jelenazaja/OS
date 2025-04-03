Terminal 1:
$ make pokreni

Pocetna inicijalizacija
Inicijalizacija gotova, krecem s radom (PID=76)
dodan broj 416048603
dodan broj 4148987
dodan broj 2952541907
dodan broj 824671099
dodan broj 1068642469
dodan broj 1016090017
dodan broj 3096622889
dodan broj 1693060567

signal SIGINT
dodan broj 2170204007
dodan broj 686339347
dodan broj 625163573
dodan broj 2863142279
dodan broj 897152269
dodan broj 2433251939
dodan broj 3629016929
dodan broj 2286762487

signal SIGUSR2
2170204007
686339347
625163573
2863142279
897152269
2433251939
3629016929
2286762487
dodan broj 1605483539
dodan broj 4108583813
dodan broj 1900458871
dodan broj 1232647507
dodan broj 1058126129
dodan broj 3033420439
dodan broj 2618448061
dodan broj 1106604641

signal SIGUSR1
1605483539
dodan broj 1237319459

signal SIGTERM

Terminal 2:
$ kill -SIGINT 76
$ kill -SIGUSR2 76
$ kill -SIGUSR1 76
$ kill -SIGTERM 76

Sadržaj datoteke status.txt na kraju:

235864252944911
8
4108583813
1900458871
1232647507
1058126129
3033420439
2618448061
1106604641
1237319459

Nakon ponvnog porektanja bez brisanja (datoteka status.txt postoji pa se iz nje restaurira stanje):

Terminal 1:
$ make pokreni

Pocetna inicijalizacija
Inicijalizacija gotova, krecem s radom (PID=103)

signal SIGUSR2
4108583813
1900458871
1232647507
1058126129
3033420439
2618448061
1106604641
1237319459
dodan broj 3306916067
dodan broj 952293913
dodan broj 4240668073
dodan broj 2038309229
dodan broj 1049989343
dodan broj 2647116809
dodan broj 2235368969
dodan broj 4265687117

signal SIGTERM

Terminal 2:
$ kill -SIGUSR2 103
$ kill -SIGTERM 103




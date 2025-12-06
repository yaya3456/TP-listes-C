Compilation en C :

gcc -c -Wall liste.c
gcc -c -Wall test.c

Ou pour une vérification plus fine :
gcc -c -Wall -Wextra -Werror -Wconversion liste.c
gcc -c -Wall -Wextra -Werror -Wconversion test.c

Edition des liens et création de l'executable testl
gcc -o testl liste.o test.o 
CC=gcc
CFLAGS=-W -Wall -Werror

prog: sequence.o tableaudynamique.o testarbre.o arbre.o
	$(CC) ../Module_sequence/list_x86_64.o ../Module_sequence/hash_x86_64.o sequence.o tableaudynamique.o testarbre.o arbre.o -o prog -lm

arbre.o: arbre.c arbre.h
	$(CC) -c $(CFLAGS) arbre.c 

testarbre.o: testarbre.c arbre.h
	$(CC) -c $(CFLAGS) testarbre.c

tableaudynamique.o: ../Module_tableau_dynamique/tableaudynamique.c ../Module_tableau_dynamique/tableaudynamique.h
	$(CC) -c $(CFLAGS) ../Module_tableau_dynamique/tableaudynamique.c

sequence.o: ../Module_sequence/sequence.c ../Module_sequence/sequence.h
	$(CC) -c $(CFLAGS) ../Module_sequence/sequence.c 

clear:
	rm -f arbre.o testarbre.o tableaudynamique.o sequence.o prog
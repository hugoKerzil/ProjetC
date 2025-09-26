CC=gcc
CFLAGS=-W -Wall -Werror

prog2: test_tableau_auto.o tableaudynamique.o
	$(CC) test_tableau_auto.o tableaudynamique.o -o prog2 -lm

tableaudynamique.o: tableaudynamique.c tableaudynamique.h
	$(CC) -c $(CFLAGS) tableaudynamique.c 

test_tableau_d.o: test_tableau_d.c tableaudynamique.h
	$(CC) -c $(CFLAGS) test_tableau_d.c

test_tableau_auto.o: test_tableau_auto.c tableaudynamique.h
	$(CC) -c $(CFLAGS) test_tableau_auto.c

clear:
	rm -f test_tableau_auto.o tableaudynamique.o test_tableau_d.o prog
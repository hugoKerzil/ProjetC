CC=gcc
CFLAGS=-W -Wall -Werror

prog: testsequence.o sequence.o
	$(CC) testsequence.o sequence.o list_x86_64.o hash_x86_64.o -o prog -lm

sequence.o: sequence.c sequence.h
	$(CC) -c $(CFLAGS) sequence.c 

testsequence.o: testsequence.c sequence.h
	$(CC) -c $(CFLAGS) testsequence.c

clear:
	rm -f sequence.o testsequence.o prog
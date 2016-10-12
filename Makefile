CC=gcc
CFLAGS=-I.

prime_finder: prime_finder.o
	$(CC) -o prime_finder prime_finder.o $(CFLAGS)

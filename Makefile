CC=gcc
CPPC=g++
CFLAGS=-I.

default:: prime_finder.o
	$(CPPC) -o prime_finder prime_finder.o $(CFLAGS)

CC=gcc
CFLAGS=-Wall -pedantic -std=c89

all: objects
objects:
	$(CC) $(CFLAGS) CrackFile.c -o CrackFile.o
clean:
	rm $(objects)

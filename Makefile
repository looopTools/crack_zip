SHELL = /bin/sh

CC=gcc
CFLAGS=-Wall -pedantic

INSTALL=/usr/bin/install -c
INSTALLDATA = /usr/local/bin/install -c -m 644

all: objects
objects:
	$(CC) $(CFLAGS) CrackFile.c -o CrackFile.o
clean:
	rm *o

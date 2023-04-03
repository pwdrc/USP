CC=gcc
CFLAGS=-Wall -Wextra -std=c99 -g

all: programa

programa: main.o livro.o
	$(CC) $(CFLAGS) -o programa main.o livro.o

main.o: main.c livro.h
	$(CC) $(CFLAGS) -c main.c

livro.o: livro.c livro.h
	$(CC) $(CFLAGS) -c livro.c

clean:
	rm -f *.o programa

run:
	./programa
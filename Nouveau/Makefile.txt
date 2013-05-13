filename=main
CC=gcc
CFLAGS=-W -Wall -std=gnu99 $(DEBUG)
LFLAGS=

all: $(filename)
	@echo "Making $(filename) binary..."
	@echo "Using following CFLAGS : $(CFLAGS)"
	@echo "Using following LFLAGS : $(LFLAGS)"

main: main.o reseau1.o
	$(CC) -o main main.o reseau1.o $(LFLAGS)

main.o: main.c
	$(CC) -o main.o -c main.c $(CFLAGS)

reseau1.o: reseau1.c reseau1.h
	$(CC) -o reseau1.o -c reseau1.c $(CFLAGS)


.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(filename)

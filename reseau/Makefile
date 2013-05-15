filename=	main
CC=		gcc
CFLAGS=		-W -Wall -std=gnu99 $(DEBUG)
LFLAGS=
ECHO_MSG=	echo

all: $(filename)
	@${ECHO_MSG} "Making $(filename) binary..."
	@${ECHO_MSG} "Using following CFLAGS : $(CFLAGS)"
	@${ECHO_MSG} "Using following LFLAGS : $(LFLAGS)"

main: $(filename).o reseau.o
	$(CC) -o $(filename) $(filename).o reseau.o $(LFLAGS)

main.o: $(filename).c
	$(CC) -o $(filename).o -c $(filename).c $(CFLAGS)

reseau1.o: reseau1.c reseau1.h
	$(CC) -o reseau.o -c reseau.c $(CFLAGS)


.PHONY: clean mrproper $(filename)

clean:
	@rm -rf *.o
	@rm -rf *.core

mrproper: clean
	@rm -rf $(filename)
	@$(ECHO_MSG) "Cleaned $(filename) folder."

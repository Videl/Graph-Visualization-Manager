filename=ask_user_info
CC=gcc
CFLAGS=-W -Wall -std=gnu99

all: mrproper $(filename)
	@echo "Making $(filename) binary..."
    @echo "Using following \$(CFLAGS) : $CFLAGS"

ask_user_info: ask_user_info.o network_generation.o
	$(CC) -o ask_user_info ask_user_info.o network_generation.o $(CFLAGS)

ask_user_info.o: ask_user_info.c
	$(CC) -o ask_user_info.o -c ask_user_info.c $(CFLAGS)

network_generation.o: network_generation.c network_generation.h
	$(CC) -o network_generation.o -c network_generation.c $(CFLAGS)


.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(filename)

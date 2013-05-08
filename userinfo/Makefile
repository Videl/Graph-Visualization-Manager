filename=ask_user_info
CC=gcc
FLAGS=-W -Wall -ansi -pedantic

all: $(filename)
	@echo "Making $(filename) binary..."

ask_user_info: ask_user_info.o network_generation.o
	gcc -o ask_user_info ask_user_info.o network_generation.o

ask_user_info.o: ask_user_info.c
	gcc -o ask_user_info.o -c ask_user_info.c $(CFLAGS)

network_generation.o: network_generation.c network_generation.h
	gcc -o network_generation.o -c network_generation.c $(CFLAGS)


.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(filename)

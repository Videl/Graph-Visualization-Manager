filename=	ask_user_info
CC=		gcc
CFLAGS=		-W -Wall -std=gnu99 $(DEBUG)
LFLAGS=
ECHO_MSG=       echo

all: $(filename)
	@echo "Making $(filename) binary..."
	@echo "Using following CFLAGS : $(CFLAGS)"
	@echo "Using following LFLAGS : $(LFLAGS)"

$(filename): $(filename).o network_generation.o
	$(CC) -o $(filename) $(filename).o network_generation.o $(LFLAGS)

$(filename).o: $(filename).c
	$(CC) -o ask_user_info.o -c ask_user_info.c $(CFLAGS)

network_generation.o: network_generation.c network_generation.h
	$(CC) -o network_generation.o -c network_generation.c $(CFLAGS)


.PHONY: clean mrproper $(filename)

clean:
	@rm -rf *.o
	@rm -rf *.core
	@rm -rf *.plist

mrproper: clean
	@rm -rf $(filename)
	@$(ECHO_MSG) "Cleaned $(filename) folder."

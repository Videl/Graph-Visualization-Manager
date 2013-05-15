CC=gcc
CFLAGS=-W -Wall -std=gnu99 $(DEBUG)
LFLAGS=
EXEC=general
SUBDIRS=dot_maker reseau userinfo


all: dot_maker reseau userinfo $(EXEC).o
	$(CC) -o $(EXEC) $(EXEC).o $(LFLAGS)

$(EXEC).o: 
	$(CC) -c $(EXEC).c $(CFLAGS)

$(SUBDIRS):
	$(MAKE) -C $@

.PHONY: clean mrproper dot_maker reseau userinfo

clean:
	@for dir in $(SUBDIRS); do \
               $(MAKE) -C $$dir mrproper; \
             done
	@rm -rf *.o
	@rm -rf *.core

mrproper: clean
	@rm -rf $(EXEC)

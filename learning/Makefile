filename=   text_to_dot
CFLAGS=     -W -Wall -std=gnu99 $(DEBUG)
LFLAGS=
CC=         gcc
ECHO_MSG=   echo


all: ${filename}.o
	@${ECHO_MSG} "Compiling $(filename) with $(CC) compiler."
	${CC} -o ${filename} $(filename).c $(LFLAGS)

${filename}.o:
	${CC} -c ${filename}.c $(CFLAGS)


clean:
	rm -rf *.o

mrproper: clean
	rm -f $(filename)

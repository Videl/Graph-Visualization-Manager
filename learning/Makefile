filename=   text_to_dot
CFLAGS=     -W -Wall -std=gnu99
CC=         gcc
ECHO_MSG=   echo


all: ${filename}.o
	@${ECHO_MSG} "Compiling $(filename) with $(CC) compiler."
	${CC} -o ${filename} $(filename).c $(CFLAGS)

${filename}.o:
	${CC} -c ${filename}.c $(CFLAGS)


clean:
	@rm -rf *.o

mrclean:
	@rm -f $(filename)

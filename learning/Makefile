filename=text_to_dot
CFLAGS=-W -Wall

all: ${filename}.o
	gcc -o ${filename} $(filename).c $(CFLAGS);

${filename}.o:
	gcc -c ${filename}.c $(CFLAGS)


clean:
	rm *.o

mrclean:
	rm $(filename)

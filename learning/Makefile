filename=text_to_dot

all: ${filename}.o
	@gcc ${filename}.o -o ${filename}

${filename}.o:
	@gcc -c ${filename}.c


clean:
	@rm ${filename}.o
	@rm ${filename}

mrclean:
	@rm *~ 
	@rm *.jpg


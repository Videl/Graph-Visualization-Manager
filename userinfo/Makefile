filename=ask_user_info

all: ${filename}.o
	@gcc ${filename}.o -o ${filename}

${filename}.o:
	@gcc -c ${filename}.c


clean:
	@rm ${filename}.o
	@rm ${filename}


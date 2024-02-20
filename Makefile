all:
	clang-format -i *.c
	gcc -c -Wall -Werror -fpic printer.c
	gcc -shared -o libprinter.so printer.o
	gcc main.c -o a.out -ldl
clean:
	rm -f *.o *.so *.out

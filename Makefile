all: c
	clang -g -Wall -Wextra -fsanitize=address,undefined *.c && ./a.out
	clang -g -fsanitize=memory *.c && ./a.out
c:
	rm -rf *.o *.out mike.c

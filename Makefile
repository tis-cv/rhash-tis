all: c
	clang -Wall -Wextra -fsanitize=address,undefined *.c && ./a.out
	clang -fsanitize=memory *.c && ./a.out
c:
	rm -rf *.o *.out mike.c

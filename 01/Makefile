CC=g++
FLAGS=-std=c++17 -Wall -Werror -fsanitize=address -Wextra -Wno-unused-variable
all: my_prog

my_prog: test.o alloc.o
	$(CC) $(FLAGS) test.o alloc.o -o test

test.o: test.cpp alloc.h
	$(CC) $(FLAGS) -c test.cpp

alloc.o: alloc.cpp alloc.h
	$(CC) $(FLAGS) -c alloc.cpp
clean:
	rm -rf *.o my_prog

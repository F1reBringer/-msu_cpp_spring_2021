CC=g++
FLAGS=-std=c++17 -Wall -Werror -Wextra -Wno-unused-variable -fsanitize=address
all: test

test: parse.o test.o
	$(CC) $(FLAGS) -o test parse.o test.o
	./test

test.o: test.cpp parse.h
	$(CC) $(FLAGS) -c test.cpp

alloc.o: parse.cpp alloc.h
	$(CC) $(FLAGS) -c parse.cpp
clean:
	rm -rf *.o test
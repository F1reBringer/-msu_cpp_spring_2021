CC=g++
FLAGS=-std=c++17 -Wall -Werror -fsanitize=address
all: test

test: test.o
	$(CC) $(FLAGS) -o test test.o
	./test

test.o: test.cpp format.h
	$(CC) $(FLAGS) -c test.cpp

clean:
	rm -rf *.o test
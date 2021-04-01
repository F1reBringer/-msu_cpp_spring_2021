CC=g++
FLAGS=-std=c++17 -Wall -Werror -Wextra -Wno-unused-variable -fsanitize=address
all: test

test: alloc.o test.o
	$(CC) $(FLAGS) -o test alloc.o test.o
	./test

test.o: test.cpp alloc.h
	$(CC) $(FLAGS) -c test.cpp

alloc.o: alloc.cpp alloc.h
	$(CC) $(FLAGS) -c alloc.cpp
clean:
	rm -rf *.o test

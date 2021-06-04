CC=g++
# FLAGS=-std=c++17 -Wall -Wextra -Wno-unused-variable
FLAGS= -fsanitize=address
all: test

test: test.o
	$(CC) $(FLAGS) -o test test.o
	./test

test.o: test.cpp vector.h allocator.h iterator.h
	$(CC) $(FLAGS) -c test.cpp

clean:
	rm -rf *.o test

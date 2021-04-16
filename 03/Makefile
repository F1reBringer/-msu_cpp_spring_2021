CC=g++
FLAGS=-std=c++17 -Wall -Werror -Wextra -Wno-unused-variable -fsanitize=address
all: test

test: matrix.o test.o
	$(CC) $(FLAGS) -o test matrix.o test.o
	./test

test.o: test.cpp matrix.h
	$(CC) $(FLAGS) -c test.cpp

matrix.o: matrix.cpp matrix.h
	$(CC) $(FLAGS) -c matrix.cpp
clean:
	rm -rf *.o test

CC=g++
FLAGS=-std=c++17 -Wall -Werror -Wextra -Wno-unused-variable -fsanitize=address
all: test

test: pool.o test.o
	$(CC) $(FLAGS) -o test pool.o test.o
	./test

test.o: test.cpp pool.h
	$(CC) $(FLAGS) -c test.cpp

pool.o: pool.cpp pool.h
	$(CC) $(FLAGS) -c pool.cpp
clean:
	rm -rf *.o test
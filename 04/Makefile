CC=g++
FLAGS=-std=c++17 -Wall -Werror -Wextra -Wno-unused-variable -fsanitize=address
all: test

test: BigInt.o test.o
	$(CC) $(FLAGS) -o test BigInt.o test.o
	./test

test.o: test.cpp BigInt.h
	$(CC) $(FLAGS) -c test.cpp

BigInt.o: BigInt.cpp BigInt.h
	$(CC) $(FLAGS) -c BigInt.cpp
clean:
	rm -rf *.o test
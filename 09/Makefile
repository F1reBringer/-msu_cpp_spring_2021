CC=g++
FLAGS=-std=c++17 -Wall -Werror -Wextra -Wno-unused-variable -fsanitize=address
all: test

test: sort.o test.o
	$(CC) $(FLAGS) -o test sort.o test.o
	./test

test.o: test.cpp sort.h
	$(CC) $(FLAGS) -c test.cpp

sort.o: sort.cpp sort.h
	$(CC) $(FLAGS) -c sort.cpp
clean:
	rm -rf *.o test
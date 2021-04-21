CC=g++
FLAGS=-std=c++17 -Wall -Werror -Wextra -Wno-unused-variable -fsanitize=address
all: test

test: serializer.o deserializer.o test.o
	$(CC) $(FLAGS) -o test serializer.o deserializer.o test.o
	./test
test.o: test.cpp
	$(CC) $(FLAGS) -c test.cpp

serializer.o: serializer.cpp serializer.h
	$(CC) $(FLAGS) -c serializer.cpp
deserializer.o: deserializer.cpp deserializer.h serializer.h
	$(CC) $(FLAGS) -c deserializer.cpp
clean:
	rm -rf *.o test
CC=g++
CFLAGS=-c -g -O3 
SPLFLAG=-std=c++0x
all: execute

execute: main.o transpose.o multiply.o gaussElimination.o gaussSiedel.o
	$(CC) main.o transpose.o multiply.o gaussElimination.o gaussSiedel.o -o execute

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

transpose.o: transpose.cpp
	$(CC) $(CFLAGS) transpose.cpp

multiply.o: multiply.cpp
	$(CC) $(CFLAGS) multiply.cpp

gaussElimination.o: gaussElimination.cpp
	$(CC) $(SPLFLAG) $(CFLAGS) gaussElimination.cpp

gaussSiedel.o: gaussSiedel.cpp
	$(CC) $(SPLFLAG) $(CFLAGS) gaussSiedel.cpp

clean:
	rm *.o execute

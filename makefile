Lab03: main.o Timer.o InsertionSort.o
	g++ -g main.o Timer.o InsertionSort.o -o Lab03
main.o: main.cpp
	g++ -g -c main.cpp
Timer.o: Timer.cpp
	g++ -g -c Timer.cpp
InsertionSort.o: InsertionSort.cpp InsertionSort.h
	g++ -g -c InsertionSort.cpp

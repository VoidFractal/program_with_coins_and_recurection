monety: main.o Functions.o
	g++ main.o Functions.o -o monety

main.o: main.cpp
	g++ -c main.cpp

Functions.o: Functions.cpp Functions.h 
	g++ -c Functions.cpp

clean:
	rm *.o monety

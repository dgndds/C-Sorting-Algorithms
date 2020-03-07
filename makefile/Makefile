output: main.o sorting.o auxArrayFunctions.o
	g++ main.o sorting.o auxArrayFunctions.o -o hw1
main.o: main.cpp
	g++ -c main.cpp
sorting.o: sorting.cpp sorting.h
	g++ -c sorting.cpp sorting.h
auxArrayFunctions.o: auxArrayFunctions.cpp auxArrayFunctions.h
	g++ -c auxArrayFunctions.cpp  auxArrayFunctions.h
clean:
	rm *.o hw1

all: table

table: main.o distance.o isSubstring.o minimum.o
	g++ main.o distance.o isSubstring.o minimum.o -o table

main.o: main.cpp
	g++ -c main.cpp

distance.o: distance.cpp
	g++ -c distance.cpp

minimum.o: minimum.cpp
	g++ -c minimum.cpp

isSubstring.o: isSubstring.cpp
	g++ -c isSubstring.cpp



clean:
	rm *o table

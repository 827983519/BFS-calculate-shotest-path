all: assignment2.o Graph.o
	g++  assignment2.o Graph.o

assignment2.o: assignment2.cpp
	g++ -c assignment2.cpp

Graph.o: Graph.cpp
	g++ -c Graph.cpp


all: assignment2.o Graph.o
	g++  assignment2.o Graph.o

assignment2.o: assignment2.cpp
	g++ -c assignment2.cpp -std=c++11

Graph.o: Graph.cpp
	g++ -c Graph.cpp -std=c++11


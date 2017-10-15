CXX=g++

all: debug life

debug: debug.cpp
	$(CXX) -g debug.cpp -o debug

life: life.cpp life.h
	$(CXX) -c -g life.cpp 

game: life.cpp main.cpp life.h
	$(CXX) -g main.cpp life.cpp -o game

clean: 
	rm -f debug *.o game
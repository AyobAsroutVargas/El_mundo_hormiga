CXX = g++
CXXFLAGS = -std=c++14 -g -Wall

main: ant.h world.h finite_world.h infinite_world.h universe.h main.cpp ant.cpp world.cpp finite_world.cpp infinite_world.cpp universe.cpp
	g++ -g ant.cpp world.cpp finite_world.cpp infinite_world.cpp universe.cpp main.cpp -o main
clean:
	rm main
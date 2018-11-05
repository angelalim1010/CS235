CXXFLAGS=-std=c++14
main: main.o MazeSolver.o
	g++ -o main main.o MazeSolver.o
main.o: main.cpp MazeSolver.h
	g++ $(CXXFLAGS) -c main.cpp
MazeSolver.o: MazeSolver.cpp MazeSolver.h
	g++ $(CXXFLAGS) -c MazeSolver.cpp
clean:
	rm main main.o MazeSolver.o

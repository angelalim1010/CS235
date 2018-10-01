CXXFLAGS=-std=c++14
main: main.o Song.o PlayList.o
	g++ -o main main.o Song.o PlayList.o
main.o: main.cpp Song.h PlayList.h Linkedset.h SetInterface.h
	g++ $(CXXFLAGS) -c main.cpp
PlayList.o: Playlist.cpp LinkedSet.h Song.h PlayList.h
	g++ $(CXXFLAGS) -c PlayList.cpp
Song.o: Song.cpp Song.h
	g++ $(CXXFLAGS) -c Song.cpp
LinkedSet.o: Set.cpp LinkedSet.h SetInterface.h
	g++ $(CXXFLAGS) -c LinkedSet.cpp
clean:
	rm -f main.o PlayList.o Song.o Set.o

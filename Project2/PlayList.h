#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Set.h"
#include "Song.h"
using namespace std;
/*
Name: Angela Lim
Professor: Tiziana Ligorio
Project 2
*/
//class for Playlist
class PlayList{
	public:
		PlayList();
		PlayList(const Song& a_song);
		int getNumberOfSongs() const;
		bool isEmpty() const;
		bool addSong(const Song& new_song);
		bool removeSong(const Song& a_song);
		void clearPlayList();
		void displayPlayList() const;
	private:
    	Set<Song> playlist_;
};
//end class


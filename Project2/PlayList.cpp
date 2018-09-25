#include <iostream>
#include <string>
#include <vector>
#include "PlayList.h"
using namespace std;
/*
Name: Angela Lim
Professor: Tiziana Ligorio
Project 2: This file will create a playlist of songs
*/
//default playlist constructor 
PlayList::PlayList(){}
//add a song to the playlist
//use add function from set.h
PlayList::PlayList(const Song& a_song){
	playlist_.add(a_song);
}
//find how many songs are in the playlist
//use getCurrentSize()
int PlayList::getNumberOfSongs() const{
	return playlist_.getCurrentSize();
}
//check if the playlist is empty
//use isEmpty()
bool PlayList::isEmpty() const{
	return playlist_.isEmpty();
}
//check if you can add a song to the playlist
// use add()
bool PlayList::addSong(const Song& new_song){
	return playlist_.add(new_song);
}
//check if you can remove a song from the playlist
//use remove()
bool PlayList::removeSong(const Song& a_song){
	return playlist_.remove(a_song);
}
//remove all songs from playlist
//use clear()
void PlayList::clearPlayList(){
	playlist_.clear();
}
//use Set::Vector() to display all the songs 
void PlayList::displayPlayList() const{
	vector<Song> arr_song = playlist_.toVector();
	for(size_t i = 0; i < arr_song.size(); i++){
		cout << "* Title: " << arr_song.at(i).getTitle() << " * Author: " << arr_song.at(i).getAuthor() << " * Album: " << arr_song.at(i).getAlbum() << " *" << endl;
	}
	cout << "End of playlist" << endl;
}

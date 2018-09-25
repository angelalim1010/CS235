#include <iostream>
#include "Song.h"
using namespace std;
/*
Name: Angela Lim
Professor: Tiziana Ligorio
Project 2: This file gives us the song information
*/
// default constructor
Song::Song(){
	title_ = "";
	author_ = "";
	album_ = "";
}
//setting the variables of song
Song::Song(const string& title, const string& author, const string& album){

	title_ = title;
	author_ = author;
	album_ = album;
}
// sets the title of a song
void Song::setTitle(string title){
	title_ = title;
}
// sets the author of a song
void Song::setAuthor(string author){
	author_ = author;
}
// sets the album of a song
void Song::setAlbum(string album){
	album_ = album;
}
// return the title of the song
string Song::getTitle() const{
	return title_;
}
// return the author of the song
string Song::getAuthor() const{
	return author_;
}
// return the album of the song
string Song::getAlbum() const{
	return album_;
}
//check if two songs are the same by comparing the title, author and album
bool operator==(const Song& lhs, const Song& rhs){
	if((lhs.title_ == rhs.title_) && (lhs.author_ == rhs.author_) && (lhs.album_ == rhs.album_)){
		return true;
	}
	return false;
}
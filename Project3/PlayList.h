#pragma once
#include "LinkedSet.h"
#include "Song.h"
/*
Author: Angela Lim
Course: CSCI 235
Professor: Tiziana Ligorio
Project 3: To create a LinkedSet for a playlist that will store your songs

*/
class PlayList : public LinkedSet<Song>{
public:
  PlayList();                     //default constructor
  PlayList(const Song& a_song);   //parameterized constructor
  PlayList(const PlayList& a_play_list); // copy constructor
  ~PlayList(); // Destructor
  bool add(const Song& new_song) override;
  bool remove(const Song& a_song) override;
  // post: previous_ptr is null if target is not in PlayList or if target is the
  // first node, otherwise it points to the node preceding target
  // return: either a pointer to the node containing target
  // or the null pointer if the target is not in the PlayList.
  void loop();
  void unloop();
  void displayPlayList();
private:
  Node<Song>* tail_ptr_; // Pointer to last node
  Node<Song>* getPointerTo(const Song& target, Node<Song>*& previous_ptr) const;
  Node<Song>* getPointerToLastNode() const;
};

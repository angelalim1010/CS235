#include "PlayList.h"
#include "Song.h"
#include "LinkedSet.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Author: Angela Lim
Course: CSCI 235
Professor: Tiziana Ligorio
Project 3: To create a LinkedSet for a playlist that will store your songs

*/
//intializing the default constructor for tail_ptr_
PlayList::PlayList(){
  tail_ptr_ = new Node<Song>();
}

//adding the first song to the PlayList
//since we have one item both head_ptr_ and tail_ptr_ will point to the first song
PlayList::PlayList(const Song& a_song){
  //create a new node for a_song and have tail_ptr_ and head_ptr_ point to it
  head_ptr_ = new Node<Song>(a_song);
  tail_ptr_ = head_ptr_;
  item_count_++;
}
//copy constructor
PlayList::PlayList(const PlayList& a_play_list){
//if the copy playlist isn't empty, create a new node where it's going to get the first item and set the next item
  if ( !a_play_list.isEmpty() ) {
    Node<Song> *temp_node = new Node<Song>( a_play_list.head_ptr_->getItem(), a_play_list.head_ptr_->getNext() );
    head_ptr_ = temp_node;
    tail_ptr_ = head_ptr_;
    item_count_ ++;
//as long as the next node isn't nullptr we're going to keep traversing through the nodes
    while ( temp_node->getNext() != nullptr ) {
      temp_node = temp_node->getNext();
      //we need to connect the chain
      tail_ptr_->setNext(temp_node);
      tail_ptr_ = tail_ptr_->getNext();
      item_count_ ++;
      //we're looping back around
      if (item_count_ == 2) {
        head_ptr_->setNext(tail_ptr_);
      }
    }
  }
}
//destructor
PlayList::~PlayList(){
//we use unloop to break the loop/chain
 unloop();
//impliment the clear function from LinkedSet to delete the pointers
 Node<Song>*node_to_delete_ptr = head_ptr_;
 while (head_ptr_ ->getNext()!= nullptr) {
   head_ptr_ = head_ptr_->getNext();
   node_to_delete_ptr->setNext(nullptr);
   delete node_to_delete_ptr;
   node_to_delete_ptr = head_ptr_;
 }
 head_ptr_ = nullptr;
 delete head_ptr_;
}

//implimenting the member function
Node<Song>*PlayList::getPointerToLastNode() const{
//we will just return nullptr if head_ptr_ = nullptr
  if(head_ptr_ == nullptr){
    return nullptr;
  }
//create a new node and we will look for nullptr
//if the new pointer points to a nullptr next return true
//if not keep pointing to the next object
  Node<Song>* last_node = head_ptr_;
  bool found_null = false;
  while(!found_null){
    if(last_node->getNext() == nullptr)
      found_null = true;
      else
      last_node = last_node->getNext();
    }
  return last_node;
}
//implimenting the other member function
Node<Song>*PlayList::getPointerTo(const Song& target, Node<Song>*& previous_ptr) const{
  //unlike in LinkedSet which looks at the first node, we're looking for the previous one
  //therefore we need to look at the position of the node
  bool found = false;
  Node<Song>*cur_ptr = head_ptr_;
  int position = 0;
  while(!found && (cur_ptr != nullptr)){
    if (position <= 1){
      previous_ptr = head_ptr_;
    }
    else{
      previous_ptr = previous_ptr->getNext();
    }
    //this is the same as LinkedSet
    if(target == cur_ptr->getItem()){
      found = true;
    }
    else{
      cur_ptr = cur_ptr->getNext();
    }
    position++;
  }
  return cur_ptr;

}

//adding a new song to the playlist
bool PlayList::add(const Song& new_song) {
  //if new_song isn't in the playlist create a new node for song
  //set tail_ptr_ to the new pointer which is what will be next
  if (!contains(new_song)){
    Node<Song>*last = new Node<Song>(new_song);
    tail_ptr_->setNext(last);
    tail_ptr_ = tail_ptr_->getNext();
    item_count_ ++;
    return true;
  }
  return false;
}
//removing a song from the playlist using prev_ptr
bool PlayList::remove(const Song& a_song){
    //post: previous_ptr is null if target is not in PlayList or if target is the
    Node<Song>*prev_ptr = new Node<Song>();
    Node<Song>*node_to_delete_ptr = getPointerTo(a_song,prev_ptr);
    // first node, otherwise it points to the node preceding target
    bool canremoveitem = !isEmpty() && (node_to_delete_ptr != nullptr);
    // return: either a pointer to the node containing target
    if(canremoveitem){
      //If this is first node
      if (node_to_delete_ptr == head_ptr_) {
  			head_ptr_ = head_ptr_->getNext();
  		}
      //if it's the last node
      else if (node_to_delete_ptr == tail_ptr_) {
        tail_ptr_ = prev_ptr;
        prev_ptr->setNext(nullptr);
      }
      //if its in the middle
      else {
        prev_ptr->setNext( node_to_delete_ptr->getNext() );
      }
      // or the null pointer if the target is not in the PlayList.
      node_to_delete_ptr->setNext(nullptr);
  		delete node_to_delete_ptr;
  		node_to_delete_ptr = nullptr;
  		item_count_--;
    }
    return canremoveitem;
}

void PlayList::loop(){
  //traversing through all the songs
  tail_ptr_->setNext(head_ptr_);
}

void PlayList::unloop(){
  tail_ptr_->setNext(nullptr);
}

void PlayList::displayPlayList(){
  vector<Song>arr_song = toVector();
  for(int i = 0; i < getCurrentSize(); i++){
  cout << "* Title: " <<  arr_song[i].getTitle() << " * Author: " << arr_song[i].getAuthor() << " * Album: " << arr_song[i].getAlbum() << " * " << endl;
	}
	cout << "End of playlist\n" << endl;

}

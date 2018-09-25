#include "Set.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Name: Angela Lim
Professor: Tiziana Ligorio
Project 2: This file sets a template for a set of songs
*/
// default constructor
template<class ItemType>
Set<ItemType>::Set(){
	item_count_ = 0;
	max_items_ = DEFAULT_SET_SIZE;
}
//return the size of the set
template<class ItemType>
int Set<ItemType>::getCurrentSize() const{
	return item_count_;
}
//check if the Set is empty
template<class ItemType>
bool Set<ItemType>::isEmpty() const{
	return item_count_ == 0;
}
//return false if the entry is already in set
//return true if song was added
template<class ItemType>
bool Set<ItemType>::add(const ItemType& newEntry){
	if(getIndexOf(newEntry) != -1)
		return false;
	if(item_count_ < max_items_){
		items_[item_count_] = newEntry;
		item_count_++;
		return true;
	}
	return false;
}
//return true if song was removed
template<class ItemType>
bool Set<ItemType>::remove(const ItemType& anEntry){
	int located_index = getIndexOf(anEntry);
	bool remove_item = !isEmpty() && (located_index > -1);
	if (remove_item)
		{
			item_count_--;
			items_[located_index] = items_[item_count_];
		} 
	return remove_item;
}
//clear the set by setting the item_count to 0 
template<class ItemType>
void Set<ItemType>::clear(){
	item_count_ = 0;
}
//check the location of an element
//if it's > -1 then it is part of the set
template<class ItemType>
bool Set<ItemType>::contains(const ItemType& anEntry) const{
	return getIndexOf(anEntry) > -1;
}
//using a vector to contain all the elements of the set
template<class ItemType>
vector<ItemType> Set<ItemType>::toVector() const{
	vector<ItemType> bag_contents;
	for (int i = 0; i < item_count_; i++)
		bag_contents.push_back(items_[i]);

 return bag_contents;
}
template<class ItemType>
int Set<ItemType>::getIndexOf(const ItemType& target) const{
	for(int i = 0; i < item_count_; i++)
		if(items_[i] == target)
			return i;
	return -1;
}


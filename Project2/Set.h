#ifndef SET_H
#define SET_H
#include <iostream>
#include "SetInterface.h"
#include <vector>
using namespace std;
/*
Name: Angela Lim
Professor: Tiziana Ligorio
Project 2
*/
//This file will create the set interface that playlist will use

template<class ItemType>
class Set : public SetInterface<ItemType>{
    public:
      Set();
      int getCurrentSize() const;
      bool isEmpty() const;
      bool add(const ItemType& newEntry);
      bool remove(const ItemType& anEntry);
      void clear();
      bool contains(const ItemType& anEntry) const;
      std::vector<ItemType> toVector() const;
    private:
      static const int DEFAULT_SET_SIZE = 4; // for testing purposes we will keep the set small
      ItemType items_[DEFAULT_SET_SIZE]; // array of set items
      int item_count_;                  // current count of set items
      int max_items_;                   // max capacity of the set
      int getIndexOf(const ItemType& target) const;
};


#include "Set.cpp"
#endif 


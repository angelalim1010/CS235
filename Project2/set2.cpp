
class Set: public SetInterface{
public:
	int Set::getCurrentSize(){
		return item_count_;
	}

	bool Set::isEmpty(){
		if (item_count_ == 0){
			return true;
		}
		return false;
	}
	bool Set::add(const ItemType& newEntry){
		if (getIndexOf(newEntry) == -1){
			ItemType[item_count_] = newEntry;
			item_count_++;
			return true;
		}
		return false;
	}
	bool Set::remove(const ItemType& anEntry){
		/*
		for (int i=0; i < item_count_; i++){
			if (ItemType[i] == getIndexOf(anEntry)){
				for (int j = i; j < item_count_ - 1; j++){
					ItemType[j] = ItemType[j+1];
				}
				item_count_--;
				return true;
			}
		}
		return false;
	}
	*/
		}
	void Set::clear();
	bool Set::contains(const ItemType& anEntry){

	}
	vector<ItemType> toVector(){

	}
	
private:
  static const int DEFAULT_SET_SIZE = 4; // for testing purposes we will keep the set small
	ItemType items_[DEFAULT_SET_SIZE]; // array of set items
	int item_count_;                  // current count of set items
	int max_items_;                   // max capacity of the set
	int getIndexOf(const ItemType& target) const;
 
}


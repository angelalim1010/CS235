
#include <iostream>
//#include "Customer.h"
//#include "GeniusBar.h"
#include <string>
using namespace std;
class Customer{
    
public:
    Customer(){
    	name_ = "";
    	defective_device_ = "";
    	wait_time_ = 0;
    }  //default constructor
    Customer(string name, string device = "unknown", int wait_time = 0){   //parameterized constructor{
        name_ = name;
        defective_device_ = device;
        wait_time_ = wait_time;
    }

    //return: name_
    string getName(){
       return name_;
    }
    
    //return: defective_device_
    string getDevice(){
        return defective_device_;
    }
    
    //return: wait_time_
    int getWaitTime(){
        return wait_time_;
    }
    
    //post: wait_time_ = new_wait_time
    void updateWaitTime(int new_wait_time){
        wait_time_ = new_wait_time;
    }
    
private:
    string name_;
    string defective_device_;
    int wait_time_;
}; // end Customer


class GeniusBar
{
    
public:
	GeniusBar(){
    current_wait_time_ = 0;
    number_of_available_geniuses_ = 3;
    number_of_customers_ = 0;
} //default constructor
    
    //pre: number_of_customers_ < MAX_NUMBER_OF_CUSTOMERS
    //post: add new_customer to genius_bar_ and increment current_wait_time_ by WAIT_TIME_INCREMENT
    //return: true if number_of_customers_ < MAX_NUMBER_OF_CUSTOMERS, false otherwise
    bool addWaitingCustomer(Customer& new_customer){
    	
        
    //new_customer.updateWaitTime(current_wait_time_);
    if(number_of_customers_ < MAX_NUMBER_OF_CUSTOMERS){
    	current_wait_time_ += WAIT_TIME_INCREMENT;
        number_of_customers_++;
        new_customer.updateWaitTime(current_wait_time_);
        genius_bar_[number_of_customers_] = new_customer;
        return true;
    }
    return false;
    }
    
    //pre: (number_of_customers_ > 0) && (number_of_available_geniuses_ > 0)
    //post: decrement number_of_customers_ and number_of_available_geniuses_
    //return: true if (number_of_customers_ > 0) && (number_of_available_geniuses_ > 0), false otherwise
    bool assignGeniusToCustomer(){
         if((number_of_customers_ > 0) && (number_of_available_geniuses_ > 0)){
        number_of_customers_--;
        number_of_available_geniuses_--;
        return true;
    }
    return false;

    }
    
    //pre: number_of_available_geniuses_ < TOTAL_NUMBER_OF_GENIUSES
    //post: increment number_of_available_geniuses
    //return: true if number_of_available_geniuses_ < TOTAL_NUMBER_OF_GENIUSES, false otherwise
    bool releaseGenius(){
       if(number_of_available_geniuses_ < TOTAL_NUMBER_OF_GENIUSES){
        number_of_available_geniuses_++;
        return true;
    }
    return false;

    }
    
    //pre: number_of_customers_ > 0
    //post: increment the wait time of each customer on the genius_bar by WAIT_TIME_INCREMENT
    //return: true if number_of_customers_ > 0, false otherwise
    bool updateCustomersWaitTime(){
       if(number_of_customers_ > 0){
        for(int i = 0; i < number_of_customers_; i++){
       
            genius_bar_[i].updateWaitTime(WAIT_TIME_INCREMENT);
        }
        return true;
    }
    return false;
    }
    
    
private:
    static const int TOTAL_NUMBER_OF_GENIUSES = 3;
    static const int MAX_NUMBER_OF_CUSTOMERS = 5;
    static const int WAIT_TIME_INCREMENT = 5;
    int current_wait_time_;
    int number_of_available_geniuses_;
    int number_of_customers_;
    Customer genius_bar_[MAX_NUMBER_OF_CUSTOMERS];
    
    
}; //end GeniusBar

int main() {
    
    //initialize a GeniusBar
    GeniusBar genius_bar;
    
    //create some customers
    Customer customer1("Lina", "iPhone");
    cout << customer1.getName() << " has problems with " << customer1.getDevice() << endl;
    Customer customer2("Clay", "iPad");
    cout << customer2.getName() << " has problems with " << customer2.getDevice() << endl;
    Customer customer3("Rory", "iMac");
    cout << customer3.getName() << " has problems with " << customer3.getDevice() << endl;
    Customer customer4("Liam", "macBookPro");
    cout << customer4.getName() << " has problems with " << customer4.getDevice() << endl;
    Customer customer5("Adri", "iPhone");
    cout << customer5.getName() << " has problems with " << customer5.getDevice() << endl;
    Customer customer6("Sky", "macBookAir");
    cout << customer6.getName() << " has problems with " << customer6.getDevice() << endl;
    
    cout << endl << "add customers to the geinus bar \n";
    cout << genius_bar.addWaitingCustomer(customer1) << endl;  // true (1)
    cout << customer1.getName() << "'s wait time is now " << customer1.getWaitTime() << endl;
    cout << genius_bar.addWaitingCustomer(customer2) << endl;  // true (1)
    cout << customer2.getName() << "'s wait time is now " << customer2.getWaitTime() << endl;
    cout << genius_bar.addWaitingCustomer(customer3) << endl;  // true (1)
    cout << customer3.getName() << "'s wait time is now " << customer3.getWaitTime() << endl;
    cout << genius_bar.addWaitingCustomer(customer4) << endl;  // true (1)
    cout << customer4.getName() << "'s wait time is now " << customer4.getWaitTime() << endl;
    cout << genius_bar.addWaitingCustomer(customer5) << endl;  // true (1)
    cout << customer5.getName() << "'s wait time is now " << customer5.getWaitTime() << endl;
    cout << genius_bar.addWaitingCustomer(customer6) << endl;  // true (0)
    cout << customer6.getName() << "'s wait time is still " << customer6.getWaitTime() << " because there is no more space at the genius bar \n";
    cout << "Sorry Sky please come back later!\n\n";
    
    cout << endl << "assigning geniuses to assist customers:" << endl;
    cout << genius_bar.assignGeniusToCustomer() << endl;  // true (1)
    cout << genius_bar.assignGeniusToCustomer() << endl;  // true (1)
    cout << genius_bar.assignGeniusToCustomer() << endl;  // true (1)
    cout << genius_bar.assignGeniusToCustomer() << endl;  // true (0)
    cout << "Oops, no more available geniuses, the remaining customers must wait \n\n";
   
    
    cout << endl << "release some geniuses from helping customers and make them available again \n";
    cout << genius_bar.releaseGenius() << endl;  // true (1)
    cout << genius_bar.releaseGenius() << endl;  // true (1)
    cout << genius_bar.releaseGenius() << endl;  // true (1)
    cout << genius_bar.releaseGenius() << endl;  // true (0)
    cout << "no more geniuses to be released \n\n";
    
    cout << "Oops, it's lunch time, our geniuses are going on lunch break, better update the remaining customers' wait time \n";
    cout << genius_bar.updateCustomersWaitTime() << endl; // true (1)
    
   
    cout << endl << "Ok, our geniuses are back from lunch, assign more geniuses to help the remaining customers \n";
    cout << genius_bar.assignGeniusToCustomer() << endl;  // true (1)
    cout << genius_bar.assignGeniusToCustomer() << endl;  // true (1)
    cout << genius_bar.assignGeniusToCustomer() << endl;  // true (0)
    cout << "no more customers in the store, all done for today!!! \n\n";
    
    cout << "do we need to tell any remaining customers that they need to wait unitl tomorrow? \n";
    cout << genius_bar.updateCustomersWaitTime() << endl; // true (0)
    cout << "no we don't, good night!!! \n\n";
    return 0;
    
}

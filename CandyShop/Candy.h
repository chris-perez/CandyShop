//
//  Candy.h
//  CandyShopProject
//
//  Authors: Chris Perez, Noah Zheutlin, Kelly Sadwin, and Shelby Cohen
//
// Last-Modified-Date: 12/10/2014

#ifndef __CandyShopProject__Candy__
#define __CandyShopProject__Candy__

//#include <stdio.h>
#include "Queue.h"
#include <iostream>

class Candy{
private:
	string name;
	int quantity;
	int wantedOnShelf;
	Queue* waitList;

public:
	Candy();
	Candy(string name, int quantity, int wantedOnShelf);

	//returns the name of the candy
	string getName();

	//returns the quantity in the shop
    int getQuantity();

	//returns how much is wanted on the shelf
    int getWanted();

	//returns the list of people waiting for the candy
	Queue* getWaitlist();

	//sells candy to everyone on the waitlist
	void deliverToWaitlist();

	//sets the name
    void setName(string name);

	//sets the quantity in the store
    void setQuantity(int quantity);

	//sets the amount wanted on the shelf
    void setWanted(int wantedOnShelf);
    
	//adds to quantity
	void add(int quantity);

	//returns the number actually sold
	int sell(int quantity);
	
	//adds a name to the waitlist
	void addToWaitlist(string name);

	//removes the first person from waitlist
	string removeFromWaitList();

	//print the candy info
	void toPrint();

	//only prints out name of candy (for use with ArrayList mostly)
	friend ostream& operator<< (ostream &out, Candy &candy);
};
	


#endif /* defined(__CandyShopProject__Candy__) */

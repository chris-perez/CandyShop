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
	string getName();
    int getQuantity();
    int getWanted();
	Queue* getWaitlist();
	void deliverToWaitlist();
    void setName(string name);
    void setQuantity(int quantity);
    void setWanted(int wantedOnShelf);
    
	void add(int quantity);
	//returns the number actually sold
	int sell(int quantity);
	void addToWaitlist(string name);
	string removeFromWaitList();

	void toPrint();

	//only prints out name of candy (for use with ArrayList mostly)
	friend ostream& operator<< (ostream &out, Candy &candy);
};
	


#endif /* defined(__CandyShopProject__Candy__) */

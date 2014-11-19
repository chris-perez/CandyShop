//
//  Candy.h
//  CandyShopProject
//
//  Created by Noah on 11/10/14.
//  Copyright (c) 2014 Noah. All rights reserved.
//

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
	Queue waitList;

public:
	Candy();
	Candy(string name, int quantity, int wantedOnShelf);
	string getName();
    int getQuantity();
    int getWanted();
    void setName(string name);
    void setQuantity(int quantity);
    void setWanted(int wantedOnShelf);
    
	void add(int quantity);
	bool sell(int quantity);
	void addToWaitlist(string name);
	string removeFromWaitList();

	void toPrint();

	//only prints out name of candy (for use with ArrayList mostly)
	friend ostream& operator<< (ostream &out, Candy &candy);
};
	


#endif /* defined(__CandyShopProject__Candy__) */

//
//  CandyShop.h
//  CandyShopProject
//
//  Created by Noah on 11/10/14.
//  Copyright (c) 2014 Noah. All rights reserved.
//

#ifndef CandyShopProject_CandyShop_h
#define CandyShopProject_CandyShop_h

#include "Candy.h"
#include "ArrayList.h"

class CandyShop {

private:
	ArrayList candyList;

public:
	CandyShop(ArrayList candyList = ArrayList());
	
	void importShipment();

	void print();

	Candy* getCandy(string name); //inquire

	void save();

	void load();

	void addCandy(Candy* candy);

	//search for candy, decrease count or add to stock, place buyer on waitlist if necessary
	void sell(Candy* candy);

	void delivery();

	//change want value
	void modify();

	//print out sorted list
	void list();

	void help();

	void quit();

};
#endif

//
//  CandyShop.h
//  CandyShopProject
//
// Authors: Chris Perez, Noah Zheutlin, Kelly Sadwin, and Shelby Cohen
//
// Last-Modified-Date: 12/10/2014

#ifndef CandyShopProject_CandyShop_h
#define CandyShopProject_CandyShop_h

#include "Candy.h"
#include "ArrayList.h"

class CandyShop {

private:
	List* candyList;

public:
	CandyShop(List* candyList = new ArrayList());
	~CandyShop();

	//print list of candies in shop
	void print();

	//get candy by name
	Candy* getCandy(string name); //inquire

	//saves candy shop info to file
	void save();

	//retrieves candy shop info from file
	void load();

	//adds a candy to the shop
	void addCandy(Candy* candy);

	//search for candy, decrease count or add to stock, place buyer on waitlist if necessary
	void sell(Candy* candy);

	bool delivery();

	//orders the amount of candy needed to empty waitlist and have enough on shelf
	bool order();
    
	//returns any excess candy
    bool returnCandy();

};
#endif

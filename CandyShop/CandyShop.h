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

	void order();

	//change want value
	void modify();

	//print out sorted list
	void list();

	void help();
    
    void returnCandy();

	void quit();

};
#endif

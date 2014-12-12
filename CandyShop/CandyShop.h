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
	
	void importShipment();

	void print();

	Candy* getCandy(string name); //inquire

	void save();

	void load();

	void addCandy(Candy* candy);

	//search for candy, decrease count or add to stock, place buyer on waitlist if necessary
	void sell(Candy* candy);

	bool delivery();

	bool order();

	//change want value
	void modify();

	//print out sorted list
	void list();
    
    bool returnCandy();

	void help();

	void quit();

};
#endif

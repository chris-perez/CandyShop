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

class CandyShop {

private:


public:
	void importShipment();

	void print();

	//Candy getCandy(String name); //inquire

	void save();

	void load();

	//void addCandy(Candy candy);

	void sell();

	void delivery();

	void modify();

	void list();

	void help();

	void quit();

};
#endif

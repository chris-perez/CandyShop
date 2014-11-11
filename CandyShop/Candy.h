//
//  Candy.h
//  CandyShopProject
//
//  Created by Noah on 11/10/14.
//  Copyright (c) 2014 Noah. All rights reserved.
//

#ifndef __CandyShopProject__Candy__
#define __CandyShopProject__Candy__

#include <stdio.h>
#include <string>
#include <queue>

using namespace std;

class Candy{
private:
	string name;
	int quantity;
	int wantedOnShelf;
	queue<Candy> waitList;


public:
	Candy(string name, int quantity, int wantedOnShelf);
	string getName();
	void add(int quantity);
	void sell(int quantity);
	void addToWaitlist(string name);

};
	


#endif /* defined(__CandyShopProject__Candy__) */

//
//  Candy.cpp
//  CandyShopProject
//
//  Created by Noah on 11/10/14.
//  Copyright (c) 2014 Noah. All rights reserved.
//

#include "Candy.h"

Candy::Candy(string name, int quantity, int wantedOnShelf){
	this->name = name;
	this->quantity = quantity;
	this->wantedOnShelf = wantedOnShelf;
}

string Candy::getName(){
	return name;
}

void Candy::add(int quantity){
	this->quantity += quantity;
}

void Candy::sell(int quantity){
	this->quantity -= quantity;
}
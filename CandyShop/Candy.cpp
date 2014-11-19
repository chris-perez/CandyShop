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
	waitList = Queue();
}

Candy::Candy() {
	name = "None";
	quantity = 0;
	wantedOnShelf = 0;
	waitList = Queue();
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

void Candy::addToWaitlist(string personName) {
	waitList.addToEnd(personName);
}

string Candy::removeFromWaitList() {
	string name = waitList.getStart();
	waitList.removeStart();
	return name;
}

int Candy::getQuantity(){
    return quantity;
}

int Candy::getWanted(){
    return wantedOnShelf;
}

void Candy::setName(string name){
    this->name = name;
}

void Candy::setQuantity(int quantity){
    this->quantity = quantity;
}

void Candy::setWanted(int wantedOnShelf){
    this->wantedOnShelf = wantedOnShelf;
}

void Candy::toPrint() {
	cout << name << endl << "Current stock: " << quantity << endl << "Wanted on shelf: " << wantedOnShelf << endl << "Wait list:" << endl << waitList << endl;
}

ostream& operator<< (ostream &out, Candy &candy){
	out << candy.name <<": {" << endl << "\tCurrent stock: " << candy.quantity <<", "<< endl << "\tWanted on shelf: " << candy.wantedOnShelf <<", " << endl << "\tWait list:" << candy.waitList << endl<<"\t}\n";
	return out;
}
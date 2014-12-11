//
//  Candy.cpp
//  CandyShopProject
//
//  Authors: Chris Perez, Noah Zheutlin, Kelly Sadwin, and Shelby Cohen
//
//  Last-Modified-Date: 12/10/2014
//
//  Stores all data for each candy

#include "Candy.h"

Candy::Candy(string name, int quantity, int wantedOnShelf){
	this->name = name;
	this->quantity = quantity;
	this->wantedOnShelf = wantedOnShelf;
	waitList = new Queue();
}

Candy::Candy() {
	name = "None";
	quantity = 0;
	wantedOnShelf = 0;
	waitList = new Queue();
	//Queue has a deconstructor so Candy does not need one
}

string Candy::getName(){
	return name;
}

Queue* Candy::getWaitlist(){
	return waitList;
}

void Candy::deliverToWaitlist(){
	while (quantity > 0 && waitList->length() > 0) {
		cout << "Name: " << waitList->getStart() << " -- Candy: " <<name << endl;
		waitList->removeStart();
		quantity--;
	}
}

void Candy::add(int quantity){
	this->quantity += quantity;
}

int Candy::sell(int quantity){
	if (this->quantity - quantity >= 0) {
		this->quantity -= quantity;
		return quantity;
	}
	else{
		int numSold = this->quantity;
		this->quantity = 0;
		return numSold;
	}
}

void Candy::addToWaitlist(string personName) {
	waitList->addToEnd(personName);
}

string Candy::removeFromWaitList() {
	string name = waitList->getStart();
	waitList->removeStart();
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
	cout << name << endl << "\tCurrent stock : " << quantity << endl << "\tWanted on shelf : " << wantedOnShelf << endl << "\tWait list:" << waitList->toString() << endl;
}

ostream& operator<< (ostream &out, Candy &candy){
	out << candy.name << ":" << endl << "\tCurrent stock : " << candy.quantity << endl << "\tWanted on shelf : " << candy.wantedOnShelf << endl << "\tWait list : " << candy.waitList << endl << "\t\n";
	return out;
}
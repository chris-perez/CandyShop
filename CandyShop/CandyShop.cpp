
//
//  CandyShop.cpp
//  CandyShopProject
//

#include "CandyShop.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

CandyShop::CandyShop(ArrayList candyList) {
	this->candyList = candyList;
}

Candy* CandyShop::getCandy(string name){
	int idx = candyList.binarySearch(name);
	if (idx != -1) {
		return candyList.get(idx);
	}
	else {
		return nullptr;
	}
}

void CandyShop::addCandy(Candy* candy){
	candyList.insert(candy);
}

void addCandyToOrder(string filename, Candy* candy){
	ofstream outf;
	outf.open(filename);
	if (outf){
		outf << candy->getName() << ", " << candy->getWanted() + candy->getWaitlist().length() << endl;
		outf.close();
	}else {// Print an error and exit
		cerr << "Can't write to file" << endl;
	}
}

void CandyShop::delivery(){
	string filename = "";
	{//parseFile
		ifstream infile(filename);
		if (infile){
			while (infile){
				string strInput;
				getline(infile, strInput);
				//parseLine
				if (strInput.length() > 0){
					stringstream splitter(strInput);
					string name, quantity;
					getline(splitter, name, ',');
					getline(splitter, quantity, ',');
					cout << "name:" << name << "\tnumber:" << quantity << endl;
					Candy* candy = getCandy(name);
					candy->setQuantity(candy->getQuantity() + stoi(quantity));
					//some quantity goes to waitlist
					candy->deliverToWaitlist();
					//some goes on the shelf
				}
			}
		}else {
			cerr << "File not found." << endl;
		}
	}
}

void CandyShop::order(){
	string filename = "";
	for (int i = 0; i < candyList.length(); i++){
		if (candyList.get(i)->getQuantity() < candyList.get(i)->getWanted()){
			addCandyToOrder(filename, candyList.get(i));
		}
	}
}

void CandyShop::print() {
	candyList.printList();
}
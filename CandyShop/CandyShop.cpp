
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
	string filename = "delivery.txt";
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
	string filename = "delivery.txt";
	for (int i = 0; i < candyList.length(); i++){
		if (candyList.get(i)->getQuantity() < candyList.get(i)->getWanted()){
			addCandyToOrder(filename, candyList.get(i));
		}
	}
}

void CandyShop::print() {
	candyList.printList();
}

void CandyShop::save(){
	string filename = "save.txt";
	ofstream outf;
	outf.open(filename);
	if (outf){
		for (int i = 0; i < candyList.length(); i++){
			outf << candyList.get(i)->getName() << ", " << candyList.get(i)->getQuantity() << ", " << candyList.get(i)->getWanted();
			Queue* waitlist = new Queue(candyList.get(i)->getWaitlist());
			while (waitlist->length() > 1){
				outf << waitlist->getStart() << ", ";
				waitlist->removeStart();
			}
			outf << waitlist->getStart() << endl;
			waitlist->removeStart();
			
		}
		outf.close();
	}
	else {// Print an error and exit
		cerr << "Can't write to file" << endl;
	}
}

void CandyShop::load(){
	string filename = "save.txt";
	ifstream infile(filename);
	if (infile){
		while (infile){
			string strInput;
			getline(infile, strInput);
			if (strInput.length() > 0){
				stringstream splitter(strInput);
				string name, quantity, wanted, waitlistName;
				getline(splitter, name, ',');
				getline(splitter, quantity, ',');
				getline(splitter, wanted, ',');
				candyList.addToEnd(new Candy(name, stoi(quantity), stoi(wanted)));
				while (strInput.length() > 0){
					getline(splitter, waitlistName, ',');
					candyList.get(candyList.length()-1)->addToWaitlist(waitlistName);
				}
				cout << "name:" << name << "\tnumber:" << quantity << "\twords:" << wanted << endl;
			}
		}
	}
	else {
		cerr << "File not found." << endl;
	}
}
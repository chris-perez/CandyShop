//
//  CandyShop.cpp
//  CandyShopProject
//
// Authors: Chris Perez, Noah Zheutlin, Kelly Sadwin, and Shelby Cohen
//
// Last-Modified-Date: 12/10/2014
//
// Uses CandyShop's data to store individual candies

#include "CandyShop.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

CandyShop::CandyShop(ArrayList* candyList) {
	this->candyList = candyList;
}

CandyShop::~CandyShop() {
	delete candyList;
}

Candy* CandyShop::getCandy(string name){
	int idx = candyList->binarySearch(name);
	if (idx != -1) {
		return candyList->get(idx);
	}
	else {
		return nullptr;
	}
}

void CandyShop::addCandy(Candy* candy){
	candyList->insert(candy);
}

void addCandyToOrder(string filename, Candy* candy){
	ofstream outf;
	outf.open(filename);
	if (outf){
		outf << candy->getName() << ", " << candy->getWanted() + candy->getWaitlist()->length() - candy->getQuantity() << endl;
		outf.close();
	}else {// Print an error and exit
		cerr << "Can't write to file" << endl;
	}
}
void removeCandyFromOrder(string filename, Candy* candy){
    ofstream outf;
    outf.open(filename);
    if (outf){
        outf << candy->getName() << ", " << candy->getQuantity() - candy->getWanted() << endl;
        outf.close();
    }else {// Print an error and exit
        cerr << "Can't write to file" << endl;
    }
}

bool CandyShop::returnCandy(){
	bool wasCandyReturned = false;
    string filename = "returnInvoice.txt";
    for (int i = 0; i < candyList->length(); i++){
        if (candyList->get(i)->getQuantity() > candyList->get(i)->getWanted()){
            removeCandyFromOrder(filename, candyList->get(i));
            candyList->get(i)->setQuantity(candyList->get(i)->getWanted());
			cout << candyList->get(i)->getName() << " returned." << endl;
			wasCandyReturned = true;
        }
    }
	return wasCandyReturned;
}

bool CandyShop::delivery(){
	bool wasDelivery = false;
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
					cout << "name: " << name << " \tnumber:" << quantity << endl;
					Candy* candy = getCandy(name);
					candy->setQuantity(candy->getQuantity() + stoi(quantity));
					//some quantity goes to waitlist
					candy->deliverToWaitlist();
					//some goes on the shelf
					wasDelivery = true;
				}
			}
			ofstream ofs;
			ofs.open(filename, ofstream::trunc);
		}
	}
	return wasDelivery;
}

bool CandyShop::order(){
	bool wasThereAnOrder = false;
	string filename = "delivery.txt";
	string text = "";
	for (int i = 0; i < candyList->length(); i++){
		int needed = candyList->get(i)->getWanted() + candyList->get(i)->getWaitlist()->length();
		if (candyList->get(i)->getQuantity() < needed){
			text += candyList->get(i)->getName() + ", " + to_string(needed - candyList->get(i)->getQuantity()) + "\n";
			cout << needed - candyList->get(i)->getQuantity() << " of " << candyList->get(i)->getName() << ", ";
			wasThereAnOrder = true;
		}
	}
	ofstream outf;
	outf.open(filename);
	if (outf){
		outf << text << endl;
		outf.close();
	}
	else {// Print an error and exit
		cerr << "Can't write to file" << endl;
	}
	return wasThereAnOrder;
}

void CandyShop::print() {
	candyList->printList();
}

void CandyShop::save(){
	string filename = "save.txt";
	string text = "";
	for (int i = 0; i < candyList->length(); i++){
		text += candyList->get(i)->getName() + "," + to_string(candyList->get(i)->getQuantity()) + "," + to_string(candyList->get(i)->getWanted()) + ",";
		Node* current = candyList->get(i)->getWaitlist()->getStartNode();
		if (current != nullptr) {
			while (current->getNext() != nullptr){
				text += current->getItem() + ",";
				current = current->getNext();
			}
			text += current->getItem();
		}
		text += "\n";
	}
	ofstream outf;
	outf.open(filename);
	if (outf){
		outf << text;
	}
	else {// Print an error and exit
		cerr << "Can't save" << endl;
	}
	outf.close();
	
}

void CandyShop::load(){
	string filename = "save.txt";
	{
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
					candyList->insert(new Candy(name, stoi(quantity), stoi(wanted)));
					int thistime = 0;
					int lasttime = -1;
					while (lasttime != thistime){
						getline(splitter, waitlistName, ',');
						candyList->get(candyList->length() - 1)->addToWaitlist(waitlistName);
						lasttime = thistime;
						thistime = candyList->get(candyList->length() - 1)->getWaitlist()->length();
					}
					cout << "name: " << name << " \tnumber:" << quantity << " \twanted on shelf:" << wanted << endl;
				}
			}
		}
		else {
			cerr << "File not found." << endl;
		}
	}
	
}
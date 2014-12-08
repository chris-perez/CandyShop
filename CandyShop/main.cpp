//
//  main.cpp
//  CandyShopProject
//
//  Created by Noah on 11/10/14.
//  Copyright (c) 2014 Noah. All rights reserved.
//
//#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <sstream>


using namespace std;
#include <stdio.h>
#include "CandyShop.h"

int main(int argc, const char * argv[])
{
    parseFile("testFile.txt");
    printToFile("testOutput.txt");
    
	CandyShop* myShop = new CandyShop();
	bool running = true;
	string x = "";
	cout << "Enter H for a list of Commands: ";
	cin >> x;

	while (running)
	{
		if (x == "h" || x == "H")
		{
			cout << "Keys:" << endl << "I-inquire" << endl << "L-list" << endl << "A-add" << endl << "M-modify" << endl << "O-order" << endl << "D-delivery" << endl << "R-return" << endl << "S-sell" << endl << "Q-quit" << endl;
		}
		cout << "Enter a new command: ";
		cin >> x;
		//inquire
		if (x == "i" || x == "I")
		{
			cout << "Enter name of candy: ";
			cin >> x;
			Candy* inquireCandy = myShop->getCandy(x);
			if (inquireCandy != nullptr) {
				inquireCandy->toPrint();
			}
			else {
				cout << "Candy not found in store." << endl;
			}
			continue;
		}
		//list
		if (x == "l" || x == "L")
		{
			//THIS IS MAYBE ALPHABETIZED
			myShop->print();
			continue;
		}
		//add
		if (x == "a" || x == "A")
		{
			string name;
			cout << "Enter name of candy: ";
			cin >> name;
			Candy* inquireCandy = myShop->getCandy(name);
			if (inquireCandy != nullptr) {
				cout << "Candy already exists in store." << endl;
				inquireCandy->toPrint();
			}
			else {
				int wanted;
				cout << "How many of " << name << " would you like on shelf? Enter number: ";
				cin >> wanted;
				myShop->addCandy(new Candy(name, 0, wanted));
				cout << name << " added." << endl;
			}
			continue;
		}
		if (x == "m" || x == "M")
		{
			string name;
			int x;
			cout << "Enter name of candy: ";
			cin >> name;
			Candy* modifyCandy = myShop->getCandy(name);
			if (modifyCandy->getName() != "None") {
				cout << "there are currently: " << modifyCandy->getWanted() << " " << name << endl;
				cout << "how many would you like now?" << endl;
				cin >> x;
				modifyCandy->setWanted(x);
			}
			else {
				cout << "Candy not found in store." << endl;
			}
			continue;
		}
		if (x == "o" || x == "O")
		{
			myShop->order();
			cout << "order" << endl;
			continue;
		}
		if (x == "d" || x == "D")
		{
			cout << "delivery" << endl;
			continue;
		}
		if (x == "r" || x == "R")
		{
			cout << "return" << endl;
			continue;
		}
		//sell
		if (x == "s" || x == "S")
		{
			string name;
			cout << "What candy would you like to sell?" << endl;
			cin >> name;
			Candy* inquireCandy = myShop->getCandy(name);

			if (inquireCandy != nullptr){
				int quantity;
				cout << "Quantity?" << endl;
				cin >> quantity;
				if (inquireCandy->sell(quantity)){
				}
				else{
					//if out of stock
					string answer;
					cout << "The candy you asked for is out of stock." << endl;
					cout << "Would you like us to add you to the waitlist for this candy? (y/n)" << endl;
					cin >> answer;
					if (answer == "y"){
						cout << "What is your name?" << endl;
						cin >> name;
						inquireCandy->addToWaitlist(name);
						cout << "Thank you." << endl;
					}
					else{
						cout << "Sorry for the inconvenience." << endl;
					}
				}
			}
			else{
				cout << "Error: Candy not found." << endl;
			}
			continue;
		}
		if (x == "q" || x == "Q")
		{
			cout << "Goodbye!" << endl;
			running = false;
			continue;
		}
		return 0;
	}
}

void parseLine(string line){
    if (line.length() > 0){
        stringstream splitter (line);
        string name, number, words;
        getline(splitter, name, ',');
        getline(splitter, number, ',');
        getline(splitter, words, ',');
        cout << "name:" << name << "\tnumber:" << number << "\twords:"<< words << endl;
    }
}

void parseFile(string filename){
    ifstream infile(filename);
    if (infile){
        while (infile){
            string strInput;
            getline(infile, strInput);
            parseLine(strInput);
        }
    }
    else {
        cerr << "File not found." << endl;
    }
}

void printToFile(string filename){
    ofstream outf(filename);
    if (outf){
        outf << "This is line 1" << endl;
        outf << "This is line 2" << endl;
        outf.close();
    }
    else {// Print an error and exit
        cerr << "Can't write to file" << endl;
    }
    
}


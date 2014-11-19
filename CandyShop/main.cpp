//
//  main.cpp
//  CandyShopProject
//
//  Created by Noah on 11/10/14.
//  Copyright (c) 2014 Noah. All rights reserved.
//

#include <stdio.h>
#include "CandyShop.h"

int main(int argc, const char * argv[])
{
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
		}
		//list
		if (x == "l" || x == "L")
		{
			//THIS IS NOT ALPHABETIZED
			myShop->print();
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
		}
		if (x == "m" || x == "M")
		{
			cout << "modify" << endl;
		}
		if (x == "o" || x == "O")
		{
			cout << "order" << endl;
		}
		if (x == "d" || x == "D")
		{
			cout << "delivery" << endl;
		}
		if (x == "r" || x == "R")
		{
			cout << "return" << endl;
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
		}
		if (x == "q" || x == "Q")
		{
			cout << "Goodbye!" << endl;
			running = false;
		}
		return 0;
	}
}

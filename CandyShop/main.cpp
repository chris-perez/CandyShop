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
	CandyShop myShop = CandyShop();
	bool running = true;
	string x = "";
	cout << "Enter H for a list of Commands: ";
	cin >> x;
	while (running == true)
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
			Candy inquireCandy = myShop.getCandy(x);
			if (inquireCandy.getName() != "None") {
				inquireCandy.toPrint();
			}
			else {
				cout << "Candy not found in store." << endl;
			}
		}
		//list
		if (x == "l" || x == "L")
		{
			//THIS IS NOT ALPHABETIZED
			myShop.print();
		}
		//add
		if (x == "a" || x == "A")
		{
			cout << "Enter name of candy: ";
			cin >> x;
			Candy inquireCandy = myShop.getCandy(x);
			if (inquireCandy.getName() != "None") {
				cout << "Candy already exists in store." << endl;
				inquireCandy.toPrint();
			}
			else {
				int wanted;
				cout << "How many of " << x << " would you like on shelf? Enter number: ";
				cin >> wanted;
				myShop.addCandy(Candy(x, 0, wanted));
				cout << x << " added." << endl;
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
		if (x == "s" || x == "S")
		{
			cout << "sell" << endl;
		}
		if (x == "q" || x == "Q")
		{
			cout << "Goodbye!" << endl;
			running = false;
		}

	}
	return 0;
}

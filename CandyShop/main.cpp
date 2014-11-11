//
//  main.cpp
//  CandyShopProject
//
//  Created by Noah on 11/10/14.
//  Copyright (c) 2014 Noah. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[])
{
	bool running = true;
	string x = "";
	cout << "Enter H for a list of Commands: ";
	cin >> x;
	while (running == true)
	{
		if (x == "h")
		{
			cout << "Keys:" << endl << "I-inquire" << endl << "L-list" << endl << "A-add" << endl << "M-modify" << endl << "O-order" << endl << "D-delivery" << endl << "R-return" << endl << "S-sell" << endl << "Q-quit" << endl;
		}
		cout << "Enter a new command: ";
		cin >> x;
		if (x == "i" || x == "I")
		{
			cout << "inquire" << endl;
		}
		if (x == "l" || x == "L")
		{
			cout << "list" << endl;
		}
		if (x == "a" || x == "A")
		{
			cout << "add" << endl;
		}
		if (x == "m" || x == "M")
		{
			cout << "modify" << endl;
		}
		if (x == "O" || x == "O")
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
			cout << "quit" << endl;
		}

	}
	return 0;
}

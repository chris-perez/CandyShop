//
//  main.cpp
//  CandyShopProject
//
// Authors: Chris Perez, Noah Zheutlin, Kelly Sadwin, and Shelby Cohen
//
// Last-Modified-Date: 12/10/2014
//
// Allows user to type commands and focuses on file input and output
//#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#include <string>
using namespace std;
#include <stdio.h>
#include "CandyShop.h"

inline bool isNumeric(std::string input){
    return std::all_of(input.begin(), input.end(), ::isdigit);
}

int main(int argc, const char * argv[])
{   
	CandyShop* myShop = new CandyShop();
	bool running = true;
	myShop->load();
	string x = " ";
    cout << "Keys:" << endl << "I-inquire" << endl << "L-list" << endl << "A-add" << endl << "M-modify" << endl << "O-order" << endl << "D-delivery" << endl << "R-return" << endl << "S-sell" << endl << "Q-quit" << endl << "H-help"<<endl;


	while (running)
	{
        if(x != ""){
		cout << "Enter a new command: ";
        }
        //cin.ignore();
        getline(cin, x);
        //cin >> x;
		//inquire
		if (x == "i" || x == "I")
		{
			cout << "Enter name of candy: ";
            //cin.ignore();
            getline(cin, x);
            //cin >> x;
			Candy* inquireCandy = myShop->getCandy(x);
			if (inquireCandy != nullptr) {
				inquireCandy->toPrint();
			}
			else {
				cout << "Candy not found in store." << endl;
			}
		}
		//help
		else if (x == "h" || x == "H")
		{
			cout << "Keys:" << endl << "I-inquire" << endl << "L-list" << endl << "A-add" << endl << "M-modify" << endl << "O-order" << endl << "D-delivery" << endl << "R-return" << endl << "S-sell" << endl << "Q-quit" << endl;
		}
		//list
		else if (x == "l" || x == "L")
		{
			myShop->print();
		}
		//add
		else if (x == "a" || x == "A")
		{
			string name;
			cout << "Enter name of candy: ";
            //cin.ignore();
            getline(cin, name);
			//cin >> name;
			Candy* inquireCandy = myShop->getCandy(name);
			if (inquireCandy != nullptr) {
				cout << "Candy already exists in store." << endl;
				inquireCandy->toPrint();
			}
			else {
				string wanted;
                cout << "How many of " << name << " would you like on shelf? Enter number: ";
                //getline(cin, wanted);
                cin >> wanted;
                while(!isNumeric(wanted)){
                    cout << "Error: invalid input" << endl;
                    cout << "How many of " << name << " would you like on shelf? Enter number: ";
                    cin >> wanted;
                }
				myShop->addCandy(new Candy(name, 0, stoi(wanted)));
                cout << "The candy " << name << " has been added." << endl;
			}
        }
		
		else if (x == "m" || x == "M")
		{
			string name;
			int x;
			cout << "Enter name of candy: ";
            //cin.ignore();
            getline(cin, name);
			//cin >> name;
			Candy* modifyCandy = myShop->getCandy(name);
			if (modifyCandy->getName() != "None") {
				cout << "Current number wanted on shelf: " << modifyCandy->getWanted() << " " << name << endl << "How many would you like now?: ";
                cin >> x;
                cin.ignore();
                //getline(cin, x);
				modifyCandy->setWanted(x);
			}
			else {
				cout << "Candy not found in store." << endl;
			}
			continue;
		}
		else if (x == "o" || x == "O")
		{
			if (myShop->order()) {
				cout << "have been ordered" << endl;
			}
			else {
				cout << "No candy to order." << endl;
			}
		}
		else if (x == "d" || x == "D")
		{
			//read candy name in file, find it in list, update have values accordingly
			if (myShop->delivery()) {
				cout << "Your delivery succeeded." << endl;
			}
			else {
				cout << "No delivery available." << endl;
			}
		}
		else if (x == "r" || x == "R")
		{
			//go through candies linearly, compare want and have values, add a return order to file for excessive numbers of candies
			if (!myShop->returnCandy()) {
				cout << "No candy to return." << endl;
			}
		}
		//sell
		else if (x == "s" || x == "S")
		{
			string name;
			cout << "What candy would you like to sell?: ";
            //cin.ignore();
            getline(cin, name);
			//cin >> name;
			Candy* inquireCandy = myShop->getCandy(name);

			if (inquireCandy != nullptr){
				int quantity;
				cout << "Enter the quantity of "<< name << " that you would like to sell: ";
                cin.ignore();
                getline(cin, name);
				//cin >> quantity;
				int numSold = inquireCandy->sell(quantity);
				if (numSold == quantity){
					cout << "Enjoy your candy." << endl;
				}
				else{
					//if out of stock
					string answer;
					cout << "There is not enough candy in stock for this sale." << endl;
					cout << "Would you like us to add you to the waitlist for this candy? (y/n): ";
                    //cin.ignore();
                    getline(cin, answer);
					//cin >> answer;
					if (answer == "y" || answer == "Y"){
						cout << "Please enter your name: ";
                        cin.ignore();
                        getline(cin, name);
						//cin >> name;
						for (int i = 0; i < quantity - numSold; i++) {
							inquireCandy->addToWaitlist(name);
						}
						cout << "Thank you. You have " << numSold << " now." << endl;
					}else{
						cout << "Sorry for the inconvenience." << endl;
					}
				}
			}
			else{
				cout << "Error: Candy not found." << endl;
			}
		}
		else if (x == "q" || x == "Q")
		{
			cout << "Saving data..." << endl;
			myShop->save();
			cout << "Goodbye!" << endl;
			running = false;
		}
		else {
            if(x != ""){
                cout << "Error: invalid command" << endl;
            }
		}
	}
	return 0;
}




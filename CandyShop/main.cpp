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


using namespace std;
#include <stdio.h>
#include "CandyShop.h"

void parseLine(string line){
	if (line.length() > 0){
		stringstream splitter(line);
		string name, number, words;
		getline(splitter, name, ',');
		getline(splitter, number, ',');
		getline(splitter, words, ',');
		cout << "name:" << name << "\tnumber:" << number << "\twords:" << words << endl;
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
	}else {
		cerr << "File not found." << endl;
	}
}

void printToFile(string filename){
	ofstream outf;
	outf.open(filename);
	if (outf){
		//outf << "This is line 1" << endl;
		//outf << "This is line 2" << endl;
		outf.close();
	}else {
        // Print an error and exit
		cerr << "Can't write to file" << endl;
	}
}

int main(int argc, const char * argv[])
{
    //files get created in visual studio
    //need to have separate folder with files when using Xcode
    printToFile("testOutput.txt");
	parseFile("testOutput.txt");
    
	CandyShop* myShop = new CandyShop();
	bool running = true;
	myShop->load();
	string x = "";
	cout << "Keys:" << endl << "I-inquire" << endl << "L-list" << endl << "A-add" << endl << "M-modify" << endl << "O-order" << endl << "D-delivery" << endl << "R-return" << endl << "S-sell" << endl << "Q-quit" << endl << "H-help" << endl;


	while (running)
	{
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
		//help
		else if (x == "h" || x == "H")
		{
			cout << "Keys:" << endl << "I-inquire" << endl << "L-list" << endl << "A-add" << endl << "M-modify" << endl << "O-order" << endl << "D-delivery" << endl << "R-return" << endl << "S-sell" << endl << "Q-quit" << endl;
		}
		//list
		else if (x == "l" || x == "L")
		{
			//THIS IS ALPHABETIZED
			myShop->print();
		}
		//add
		else if (x == "a" || x == "A")
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
				cout << "The candy " << name << " has been added." << endl;
			}
		}
		else if (x == "m" || x == "M")
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
		else if (x == "o" || x == "O")
		{
			myShop->order();
            
			cout << " have been ordered" << endl;
		}
		else if (x == "d" || x == "D")
		{
			//read candy name in file, find it in list, update have values accordingly
			myShop->delivery();
			cout << "Your delivery succeeded" << endl;
		}
		else if (x == "r" || x == "R")
		{
			//go through candies linearly, compare want and have values, add a return order to file for excessive numbers of candies
            myShop->returnCandy();
            cout << "Candy has been returned" << endl;
		}
		//sell
		else if (x == "s" || x == "S")
		{
			string name;
			cout << "What candy would you like to sell? : ";
			cin >> name;
			Candy* inquireCandy = myShop->getCandy(name);

			if (inquireCandy != nullptr){
				int quantity;
				cout << "Enter the quantity of "<< name << " that you would like to sell: ";
				cin >> quantity;
				if (inquireCandy->sell(quantity)){
					cout << "Enjoy your candy." << endl;
				}
				else{
					//if out of stock
					string answer;
					cout << "The candy you asked for is out of stock." << endl;
					cout << "Would you like us to add you to the waitlist for this candy? (y/n)" << endl;
					cin >> answer;
					if (answer == "y" || answer == "Y"){
						cout << "What is your name?" << endl;
						cin >> name;
						inquireCandy->addToWaitlist(name);
						cout << "Thank you." << endl;
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
			myShop->save();
			cout << "Goodbye!" << endl;
			running = false;
		}
		else {
			cout << "Error: invalid command" << endl;
		}
	}
	return 0;
}




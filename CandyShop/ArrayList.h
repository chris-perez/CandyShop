//
//  ArrayList.h
//  List
//
// Authors: Chris Perez, Noah Zheutlin, Kelly Sadwin, and Shelby Cohen
//  Copyright (c) 2014 Toby Dragon. All rights reserved.
//

#ifndef __List__ArrayList__
#define __List__ArrayList__

#include <stdio.h>
#include "List.h"
using namespace std;

class ArrayList : public List {
private:
   //TODO: enter necessary data members here
	Data* arr;
	int capacity = 10;
	int numItems = 0;

    long ticks = 0;
    void doubleSize();

	int binarySearch(string toFind, int len, Data start);
	int searchForInsert(string toFind, int len, int currIdx);
    
public:
    ArrayList();
    ~ArrayList();
    int length();
    const Data getStart();
	Data get(int i);
    Data removeStart();
    const Data getEnd();
    Data removeEnd();
    void addToEnd(Data toAdd);
    void printList();
    
	int binarySearch(string toFind);
	bool insert(Data toAdd);

    int calcMemInUse();
    long getElapsedTime();
};

#endif /* defined(__List__ArrayList__) */

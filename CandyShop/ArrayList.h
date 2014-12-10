//
//  ArrayList.h
//
//  Authors: Chris Perez, Noah Zheutlin, Kelly Sadwin, and Shelby Cohen
//  Last-Modified-Date: 12/10/2014
//
// Contains an array with various methods for manipulating the array.


#ifndef __List__ArrayList__
#define __List__ArrayList__

#include <stdio.h>
#include "List.h"
using namespace std;

class ArrayList : public List {
private:
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
    
    //returns the index of the desired item, or -1 if not found
	int binarySearch(string toFind);
    //returns true or false to indicate whether or not it was successful
	bool insert(Data toAdd);

    int calcMemInUse();
    long getElapsedTime();
};

#endif /* defined(__List__ArrayList__) */

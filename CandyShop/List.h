//
//  List.h
//  List
//
//  Created by Toby Dragon on 10/9/14.
//  Copyright (c) 2014 Toby Dragon. All rights reserved.
//

#ifndef List_List_h
#define List_List_h

#include <string>
#include "Candy.h"

using namespace std;


#define Data Candy*

class List {
public:
    //default destructor, declared virtual to ensure that child destructors are called
    virtual ~List(){};
    
    //returns the number of items in the list
    virtual int length() = 0;
    
    //returns the item at the start of the list
    //(earliest item added)
    //const so that the item can't be changed
    virtual const Data getStart() = 0;
    
    //removes the item at the start of the list
    //returns the item removed
    virtual Data removeStart() = 0;
    
    //returns the item at the end of the list
    //(most recent item added)
    //const so that the item can't be changed
    virtual const Data getEnd() = 0;
    
    //removes the item at the end of the list
    //returns the item removed
    virtual Data removeEnd() = 0;
    
    //adds an item to the end of the list
    //param toAdd: the item to add
    virtual void addToEnd(Data toAdd) = 0;
    
    //prints the contents of the list to the screen
    virtual void printList() = 0;
    
	//returns the index of the desired item, or -1 if not found
	virtual int binarySearch(string toFind) = 0;

	//returns true or false to indicate whether or not it was successful
	virtual bool insert(Data toAdd) = 0;

	//gets the item associated with index i
	virtual Data get(int i) = 0;

    //returns the number of bytes currently used by this entire list object
    virtual int calcMemInUse() = 0;
    
    //returns the number of ticks this object has taken,
    //the total for all operations since the object was created
    virtual long getElapsedTime() = 0;
};
#endif

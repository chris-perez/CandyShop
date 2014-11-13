//
//  ArrayList.h
//  List
//
//  Created by Toby Dragon on 10/9/14.
//  Copyright (c) 2014 Toby Dragon. All rights reserved.
//

#ifndef __List__ArrayList__
#define __List__ArrayList__

#include <stdio.h>
#include "List.h"

class ArrayList : public List {
private:
   //TODO: enter necessary data members here
	Data* arr;
	int capacity = 10;
	int numItems = 0;

    long ticks = 0;
    void doubleSize();
    
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
    
    int calcMemInUse();
    long getElapsedTime();
};

#endif /* defined(__List__ArrayList__) */

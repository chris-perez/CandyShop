// Queue.h
// CandyShopProject
//
// Authors: Chris Perez, Noah Zheutlin, Kelly Sadwin, and Shelby Cohen
// Last-Modified-Date: 12/10/2014
//
// Used to store the waitlist of candies


#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"
#include <iostream>

class Queue {
private:
	Node* start;
	Node* end;
	int len;

public:
	Queue();
	~Queue();

	//O(1)
	int length();

	//O(1)
	const string getStart();

	Node* getStartNode();

	//O(c)
	string removeStart();

	//O(1)
	const string getEnd();

	//O(c)
	void addToEnd(string toAdd);

	string toString();

	friend ostream& operator<< (ostream &out, Queue &queue);
};

#endif
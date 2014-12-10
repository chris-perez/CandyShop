// Queue.h
// CandyShopProject
//
// Authors: Chris Perez, Noah Zheutlin, Kelly Sadwin, and Shelby Cohen
// Last-Modified-Date: 12/10/2014

#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"
#include <iostream>
//Isn't implementing List.h because some methods of List do not apply to queues (only adds to one end)
//and because it holds strings, not Data (Candy)

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

	//O(c)
	string removeStart();

	//O(1)
	const string getEnd();

	//O(c)
	void addToEnd(string toAdd);

	friend ostream& operator<< (ostream &out, Queue &queue);
};

#endif
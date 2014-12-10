// Node.h
// CandyShopProject
//
// Authors: Chris Perez, Noah Zheutlin, Kelly Sadwin, and Shelby Cohen
// Last-Modified-Date: 12/10/2014
//
// Used by the Queue class to access items


#ifndef NODE_H
#define NODE_H

#include <string>
using namespace std;

class Node {
private:
	string item;
	Node* next;

public:
	Node(string itemIn, Node* nextIn);

	string getItem();
	Node* getNext();
	void setNext(Node* nextIn);
	int calcMemInUse();
};

#endif
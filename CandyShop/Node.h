#ifndef NODE_H
#define NODE_H

#include "Candy.h"
#define Data string

class Node {
private:
	Data item;
	Node* next;

public:
	Node(Data itemIn, Node* nextIn);

	Data getItem();
	Node* getNext();
	void setNext(Node* nextIn);
	int calcMemInUse();
};

#endif
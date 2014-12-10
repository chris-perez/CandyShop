// Node.cpp
// CandyShopProject
//
// Authors: Chris Perez, Noah Zheutlin, Kelly Sadwin, and Shelby Cohen
// Last-Modified-Date: 12/10/2014


#include "Node.h"

Node::Node(string itemIn, Node* nextIn) {
	item = itemIn;
	next = nextIn;
}

string Node::getItem() {
	return item;
}
Node* Node::getNext() {
	return next;
}
void Node::setNext(Node* nextIn) {
	next = nextIn;
}

int Node::calcMemInUse() {
	return sizeof(item) + sizeof(next);
}
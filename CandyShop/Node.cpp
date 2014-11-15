#include "stdafx.h"
#include "Node.h"

Node::Node(string itemIn, Node* nextIn) {
	item = string(itemIn);
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
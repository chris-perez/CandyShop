#include "stdafx.h"
#include "Node.h"

Node::Node(Data itemIn, Node* nextIn) {
	item = Data(itemIn);
	next = nextIn;
}

Data Node::getItem() {
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
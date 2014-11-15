#include "stdafx.h"
#include "Queue.h"

Queue::Queue() {
	start = nullptr;
	end = nullptr;
	len = 0;
}

Queue::~Queue() {
	Node* tempptr = start;
	while (tempptr != nullptr) {
		tempptr = start->getNext();
		delete start;
		start = tempptr;
	}
}

//O(c)
void Queue::addToEnd(Data toAdd) {
	//creating first item in the list
	if (start == nullptr) {
		start = new Node(toAdd, nullptr);
		end = start;
	}
	//creating additional items in the list
	else {
		end->setNext(new Node(toAdd, nullptr));
		end = end->getNext();
	}
	len++;
}
//O(1)
int Queue::length() {
	return len;
}
//O(c)
const Data Queue::getStart() {
	return start->getItem();
}
//O(c)
Data Queue::removeStart() {
	//we need to hold onto the memory in start before we overwrite it so we can release it
	Node* tempPtr = start;
	start = start->getNext();
	Data toReturn = Data(tempPtr->getItem());
	delete tempPtr;
	tempPtr = nullptr;
	len--;
	return toReturn;
}
//O(1)
const Data Queue::getEnd() {
	return end->getItem();
}
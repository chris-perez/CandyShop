// Queue.cpp
// CandyShopProject
//
// Authors: Chris Perez, Noah Zheutlin, Kelly Sadwin, and Shelby Cohen
// Last-Modified-Date: 12/10/2014

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
void Queue::addToEnd(string toAdd) {
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
const string Queue::getStart() {
	return start->getItem();
}
//O(c)
string Queue::removeStart() {
	//we need to hold onto the memory in start before we overwrite it so we can release it
	Node* tempPtr = start;
	start = start->getNext();
	string toReturn = tempPtr->getItem();
	delete tempPtr;
	tempPtr = nullptr;
	len--;
	return toReturn;
}
//O(1)
const string Queue::getEnd() {
	return end->getItem();
}

ostream& operator<< (ostream &out, Queue &queue){
	// Since operator<< is a friend, we can access the data members of the class directly.
	Node* current = queue.start;
	out << "[ ";
	if (current != nullptr) {
		while (current->getNext() != nullptr) {
			//i will only increment after this line of code is executed
			out << current->getItem() << ", ";
			current = current->getNext();
		}
		out << current->getItem() << " ]" << endl;
	}
	else {
		out << "]" << endl;
	}
	return out;
}
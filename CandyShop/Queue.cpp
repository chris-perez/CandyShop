// Queue.cpp
// CandyShopProject
//
// Authors: Chris Perez, Noah Zheutlin, Kelly Sadwin, and Shelby Cohen
// Last-Modified-Date: 12/10/2014
//
// Used to store the waitlist of candies

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

string Queue::toString() {
	cout << "test Queue toString" << endl;
	string out = "[ ";
	Node* current = start;
	cout << "hello?" << endl;
	if (current != nullptr) {
		cout << "hello??" << endl;
		while (current->getNext() != nullptr) {
			cout << "hi ";
			out += current->getItem() + ", ";
			current = current->getNext();
		}
		cout << "Outside the while loop" << endl;
		out += current->getItem() + " ]\n";
	}
	else {
		out += "]";
	}
	return out;
}

ostream& operator<< (ostream &out, Queue &queue){
	// Since operator<< is a friend, we can access the data members of the class directly.
	cout << "Kelly is testing the Queue ostream operator" << endl;
	Node* current = queue.start;
	cout << "here i am" << endl;
	out << "[ ";
	if (current != nullptr) {
		cout << "Made it into the if statement" << endl;
		while (current->getNext() != nullptr) {
			cout << "Inside the while loop, ";
			out << current->getItem() << ", ";
			current = current->getNext();
		}
		cout << "Outside the while loop" << endl;
		out << current->getItem() << " ]" << endl;
	}
	else {
		out << "]" << endl;
	}
	return out;
}
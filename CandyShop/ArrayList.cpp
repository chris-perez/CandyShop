//
// ArrayList.cpp
//
// Authors: Chris Perez, Noah Zheutlin, Kelly Sadwin, and Shelby Cohen
// Last-Modified-Date: 12/10/2014
//
// Contains an array with various methods for manipulating the array.

#include "ArrayList.h"
#include <time.h>

// O(1)
ArrayList::ArrayList(){
	arr = new Data[capacity];
}

// O(1)
ArrayList::~ArrayList(){
	long startTime = clock();
	delete[] arr;
	ticks += clock() - startTime;
}

Data ArrayList::get(int i){
	return arr[i];
}

// O(1)
int ArrayList::length(){
	return numItems;
}

const Data ArrayList::getStart(){
	return arr[0];
}

// O(n)
Data ArrayList::removeStart(){
	long startTime = clock();

	Data temp = arr[0];
	for (int i = 0; i < capacity - 1; i++){
		arr[i] = arr[i + 1];
	}
	numItems--;

	ticks += clock() - startTime;
	return temp;
}

// O(1)
const Data ArrayList::getEnd(){
	return arr[numItems];
}

// O(1)
Data ArrayList::removeEnd(){
	long startTime = clock();

	Data temp = arr[numItems-1];
	arr[numItems - 1] = nullptr;
	numItems--;
	return temp;

	ticks += clock() - startTime;
}

// O(1)
void ArrayList::addToEnd(Data toAdd){
	long startTime = clock();

	if (numItems == capacity){
		Data* arr2 = new Data[capacity+1];
		for (int i = 0; i < capacity; i++){
			arr2[i] = arr[i];
		}
		arr = arr2;
		capacity++;
		arr[numItems] = toAdd;
		numItems++;
	}
	else{
		arr[numItems] = toAdd;
		numItems++;
	}

	ticks += clock() - startTime;
}


// O(n)
void ArrayList::printList(){
	if (numItems > 0){
		for (int i = 0; i < numItems; i++){
			cout << *arr[i] << endl;
		}
	}
	else{
		cout << "No items in list" << endl;
	}
}

int ArrayList::searchForInsert(string toFind, int len, int currIdx) {
	//base case for found
	if (arr[currIdx + len / 2]->getName() == toFind) {
		return -1;
	}
	//base case for not found
	if (len <= 1) {
		if (arr[currIdx + len / 2]->getName() > toFind) {
			return currIdx;
		}
		else {
			return currIdx + 1;
		}
	}
	//recursive cases
	if (arr[currIdx + len / 2]->getName() > toFind) {
		return searchForInsert(toFind, len / 2, currIdx);
	}
	else {
		return searchForInsert(toFind, len - (len / 2 + 1), currIdx + (len / 2 + 1));
	}
}

bool ArrayList::insert(Data toAdd){
	if (numItems == 0) {
		arr[0] = toAdd;
		numItems++;
		return true;
	}
	int idx = searchForInsert(toAdd->getName(), numItems, 0);
	if (idx != -1) {
		if (numItems == capacity) {
			doubleSize();
		}
		for (int i = numItems; i >= idx; i--) {
			arr[i] = arr[i - 1];
		}
		arr[idx] = toAdd;
		numItems++;
		return true;
	}
	else {
		//candy already exists in list
		return false;
	}
}

int ArrayList::binarySearch(string toFind, int len, Data start) {
	//base case for found
	if (arr[len/2]->getName() == toFind) {
		return len/2;
	}
	//base case for not found
	if (len <= 1) {
		return -1;
	}
	//recursive cases
	if (arr[len / 2]->getName() > toFind) {
		return binarySearch(toFind, len/2, start);
	}
	else {
		return binarySearch(toFind, len - (len / 2 + 1), start + len / 2 + 1);
	}
}

int ArrayList::binarySearch(string toFind) {
	if (numItems == 0) {
		return -1;
	}
	else {
		return binarySearch(toFind, numItems, arr[0]);
	}
}

// O(n)
int ArrayList::calcMemInUse(){
	long startTime = clock();

	int total = sizeof(capacity)+sizeof(numItems)+sizeof(ticks);
	for (int i = 0; i < capacity; i++){
		total += sizeof(arr[i]);
	}
	ticks += clock() - startTime;
	return total;
}

// O(1)
long ArrayList::getElapsedTime(){
	return ticks;
}

// O(n)
void ArrayList::doubleSize(){
	long startTime = clock();

	Data* arr2 = new Data[capacity * 2];
	for (int i = 0; i < capacity; i++){
		arr2[i] = arr[i];
	}
	arr = arr2;

	ticks += clock() - startTime;
}
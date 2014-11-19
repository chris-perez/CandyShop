//Author: Chris Perez
//Last-Modified-Date: 11/3/2014
//Contains an array with various methods for manipulating the array.

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
		cout << "{";
		for (int i = 0; i < numItems - 1; i++){
			cout << *arr[i] << ", ";
		}
		cout << *arr[numItems - 1] << "}" << endl;
	}
	else{
		cout << "{}" << endl;
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
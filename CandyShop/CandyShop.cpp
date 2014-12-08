
//
//  CandyShop.cpp
//  CandyShopProject
//

#include "CandyShop.h"

CandyShop::CandyShop(ArrayList candyList) {
	this->candyList = candyList;
}

Candy* CandyShop::getCandy(string name){
	int idx = candyList.binarySearch(name);
	if (idx != -1) {
		return candyList.get(idx);
	}
	else {
		return nullptr;
	}
}

void CandyShop::addCandy(Candy* candy){
	candyList.insert(candy);
}

void CandyShop::order(){

}

void CandyShop::print() {
	candyList.printList();
}

//
//  CandyShop.cpp
//  CandyShopProject
//

#include "CandyShop.h"

CandyShop::CandyShop(ArrayList candyList) {
	this->candyList = candyList;
}

Candy* CandyShop::getCandy(string name){
	for (int i = 0; i < candyList.length(); i++){
		if (candyList.get(i)->getName() == name){
			return candyList.get(i);
		}
	}
	return nullptr;
}

void CandyShop::addCandy(Candy* candy){
	candyList.addToEnd(candy);
}

void CandyShop::print() {
	candyList.printList();
}
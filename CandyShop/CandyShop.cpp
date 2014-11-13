//
//  CandyShop.cpp
//  CandyShopProject
//

#include "CandyShop.h"

Candy CandyShop::getCandy(string name){
	for (int i = 0; i < candyList.length(); i++){
		if (candyList.get(i).getName() == name){
			return candyList.get(i);
		}
	}
	return Data();
}

void CandyShop::addCandy(Candy candy){
	candyList.addToEnd(candy);
}
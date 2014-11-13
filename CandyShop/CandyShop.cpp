//
//  CandyShop.cpp
//  CandyShopProject
//

#include "CandyShop.h"

Candy* CandyShop::getCandy(string name){
	for (int i = 0; i < candyList.size; i++){
		if (candyList.at(i)->getName() == name){
			return candyList.at(i);
		}
	}
	return nullptr;
}

void CandyShop::addCandy(Candy* candy){

}
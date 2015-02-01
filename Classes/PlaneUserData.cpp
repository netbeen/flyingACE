/*
 * PlaneUserData.cpp
 *
 *  Created on: 2015年1月19日
 *      Author: netbeen
 */

#include "PlaneUserData.h"

#include "cocos2d.h"
PlaneUserData::PlaneUserData(int initHP):HP(initHP){
}

bool PlaneUserData::isAliveUnderAttack(int damage){
	this->HP -= damage;
	if(this->HP <= 0){
		return false;
	}else{
		return true;
	}
}

int PlaneUserData::getHP() const{
	return this->HP;
}

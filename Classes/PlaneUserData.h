/*
 * PlaneUserData.h
 *
 *  Created on: 2015年1月19日
 *      Author: netbeen
 */

#ifndef PLANEUSERDATA_H_
#define PLANEUSERDATA_H_

class PlaneUserData {
public:
	PlaneUserData(int initHP);
	bool isAliveUnderAttack(int damage);
	int getHP() const;
private:
	int HP;
};

#endif /* PLANEUSERDATA_H_ */

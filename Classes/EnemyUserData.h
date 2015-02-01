/*
 * EnemyUserData.h
 *
 *  Created on: 2015年1月18日
 *      Author: netbeen
 */

#ifndef ENEMYUSERDATA_H_
#define ENEMYUSERDATA_H_

class EnemyUserData {
public:
	EnemyUserData(int initHP);
	void setIsDeleting();
	bool getIsDeleting() const;
	bool isAliveUnderAttack(int damage);
	int getHP();
private:
	int HP;
	bool isDeleting;
};

#endif /* ENEMYUSERDATA_H_ */

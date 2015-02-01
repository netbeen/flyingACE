/*
 * EnemyBulletLayer.h
 *
 *  Created on: 2015年1月29日
 *      Author: netbeen
 */

#ifndef ENEMYBULLETLAYER_H_
#define ENEMYBULLETLAYER_H_

#include "cocos2d.h"



class EnemyBulletLayer : public cocos2d::Layer{
public:
	CREATE_FUNC(EnemyBulletLayer);
	void bossStartShooting();
	void bossStopShooting();
	virtual bool init() override;
private:
	cocos2d::Vector<cocos2d::Sprite*> allEnemyBullet;
	cocos2d::Size winSize;
	cocos2d::Animate* actionExplosion;

	EnemyBulletLayer();
	void addBossBulletSet(float useless);
	void bossBulletMoveFinished(Node* pSender);
	void update(float useless);
	void changeSceneCallBack(float useless);
};

#endif /* ENEMYBULLETLAYER_H_ */

/*
 * BulletLayer.h
 *
 *  Created on: 2015年1月16日
 *      Author: netbeen
 */

#ifndef BULLETLAYER_H_
#define BULLETLAYER_H_

#include "cocos2d.h"

class BulletLayer : public cocos2d::Layer{
public:
	cocos2d::Vector<cocos2d::Sprite*> allBullet;

	CREATE_FUNC(BulletLayer);
	void bulletMoveFinished(Node* pSender);
	void stopShooting();
	void setBulletLevelUP();
	void launchBigBomb();

private:
	int eachBulletDamage;
	std::vector<std::string> bulletTextureName;
	int nowBulletLevel;
	std::vector<cocos2d::SpriteBatchNode*> bulletBatchNodeVector;

	BulletLayer();
	~BulletLayer();
	virtual bool init() override;
	void startShooting();
	void addBullet(float useless);
};

#endif /* BULLETLAYER_H_ */

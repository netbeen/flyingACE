/*
 * UFOLayer.cpp
 *
 *  Created on: 2015年1月21日
 *      Author: netbeen
 */

#include "UFOLayer.h"

#include "ControlLayer.h"
#include "UFOUserData.h"
#include "BulletLayer.h"
#include "GameScene.h"

USING_NS_CC;

UFOLayer::UFOLayer() :
		winSize(Director::getInstance()->getWinSize()), sequenceBack(nullptr), sequenceFront(nullptr) {
}

bool UFOLayer::init() {
	std::string name1 = "bigBombGet.png";		// Kind 0
	std::string name2 = "bulletUpgrade.png";	// Kind 1
	giftTextureName.push_back(name1);
	giftTextureName.push_back(name2);

	giftFlyTime.push_back(UserDefault::getInstance()->getIntegerForKey("FlytimeOfGiftBigBomb"));
	giftFlyTime.push_back(UserDefault::getInstance()->getIntegerForKey("FlytimeOfGiftLevelUp"));

	this->scheduleUpdate();
	return true;
}

void UFOLayer::addGiftSprite() {
	float testProbability = CCRANDOM_0_1();
	int giftKinds;
	if(testProbability < 0.5) {
		giftKinds = 0;
	} else {
		giftKinds = 1;
	}
	Sprite* giftSprite = Sprite::createWithSpriteFrameName(giftTextureName[giftKinds].c_str());
	int randomX = CCRANDOM_0_1()*winSize.width;
	giftSprite->setPosition(randomX, winSize.height +giftSprite->getContentSize().height/2 );
	giftSprite->setUserData(new UFOUserData(giftKinds));
	this->addChild(giftSprite);
	allGift.pushBack(giftSprite);

	FiniteTimeAction* giftMove = MoveTo::create(giftFlyTime[giftKinds], Point(randomX, - giftSprite->getContentSize().height/2));
	FiniteTimeAction* giftRemove = CallFuncN::create(CC_CALLBACK_1(UFOLayer::giftMoveFinished, this));
	Action* giftAction = Sequence::create(giftMove, giftRemove, NULL);
	giftSprite->runAction(giftAction);
}

void UFOLayer::giftMoveFinished(Node* pSender) {
	Sprite* gift = (Sprite*) pSender;
	delete static_cast<UFOUserData*>(gift->getUserData());
	allGift.eraseObject(gift);
	this->removeChild(gift, true);
}

void UFOLayer::update(float useless) {
	for (Sprite* gift : this->allGift) {
		//判断我方飞机是否与gift碰撞
		if (gift->getBoundingBox().intersectsRect(static_cast<GameScene*>(this->getParent())->getPlaneLayer()->getMyPlane()->getBoundingBox())) {

			if (static_cast<UFOUserData*>(gift->getUserData())->getGiftKind() == 0) {
				static_cast<GameScene*>(this->getParent())->getControlLayer()->setLaunchButtonEnable();
			} else {
				static_cast<GameScene*>(this->getParent())->getBulletLayer()->setBulletLevelUP();
			}
			this->showAnnotation(gift);
			this->giftMoveFinished(gift);
		}
		//end判断我方飞机是否与gift碰撞
	}
}

void UFOLayer::showAnnotation(Sprite* gift) {
	Sprite* bulletLevelUp1;
	Sprite* bulletLevelUp2;
	if(static_cast<UFOUserData*>(gift->getUserData())->getGiftKind() == 0){
		bulletLevelUp1 = Sprite::createWithSpriteFrameName("getBigBomb1.png");
		bulletLevelUp2 = Sprite::createWithSpriteFrameName("getBigBomb2.png");
	}else{
		bulletLevelUp1 = Sprite::createWithSpriteFrameName("bulletLevelUp1.png");
		bulletLevelUp2 = Sprite::createWithSpriteFrameName("bulletLevelUp2.png");
	}
	sequenceFront = Sequence::create(FadeIn::create(0.5f), FadeOut::create(2.0f), NULL);
	sequenceBack = Sequence::create(FadeIn::create(1.0f), FadeOut::create(3.0f), NULL);
	bulletLevelUp1->setPosition(gift->getPosition());
	bulletLevelUp1->setScale(2.0f);
	bulletLevelUp1->setOpacity(0);
	bulletLevelUp2->setPosition(gift->getPosition());
	bulletLevelUp2->setScale(2.0f);
	bulletLevelUp2->setOpacity(0);
	this->addChild(bulletLevelUp1);
	this->addChild(bulletLevelUp2);
	bulletLevelUp1->runAction(sequenceFront);
	bulletLevelUp2->runAction(sequenceBack);
}

/*
 * BulletLayer.cpp
 *
 *  Created on: 2015年1月16日
 *      Author: netbeen
 */

#include "BulletLayer.h"

#include "PlaneLayer.h"
#include "BulletUserData.h"
#include "GameScene.h"

USING_NS_CC;

bool BulletLayer::init() {
	bulletTextureName.push_back("bullet1.png");
	bulletTextureName.push_back("bullet2.png");
	bulletTextureName.push_back("bullet3.png");

	bulletBatchNodeVector.push_back(SpriteBatchNode::createWithTexture(SpriteFrameCache::getInstance()->getSpriteFrameByName("bullet1.png")->getTexture()));
	bulletBatchNodeVector.push_back(SpriteBatchNode::createWithTexture(SpriteFrameCache::getInstance()->getSpriteFrameByName("bullet2.png")->getTexture()));
	bulletBatchNodeVector.push_back(SpriteBatchNode::createWithTexture(SpriteFrameCache::getInstance()->getSpriteFrameByName("bullet3.png")->getTexture()));
	bulletBatchNodeVector.push_back(SpriteBatchNode::createWithTexture(SpriteFrameCache::getInstance()->getSpriteFrameByName("bigBomb.png")->getTexture()));	//定义大招层

	this->addChild(bulletBatchNodeVector[0]);
	this->addChild(bulletBatchNodeVector[1]);
	this->addChild(bulletBatchNodeVector[2]);
	this->addChild(bulletBatchNodeVector[3]);	//大招层

	this->startShooting();
	return true;
}

void BulletLayer::addBullet(float useless) {
	Sprite* bullet = Sprite::createWithSpriteFrameName(bulletTextureName[nowBulletLevel]);
	Point planePosition = static_cast<GameScene*>(this->getParent())->getPlaneLayer()->getChildByName("PLANE")->getPosition();

	Point bulletPosition = Point(planePosition.x, planePosition.y + static_cast<GameScene*>(this->getParent())->getPlaneLayer()->getChildByName("PLANE")->getContentSize().height);

	bullet->setPosition(bulletPosition);
	bullet->setUserData(new BulletUserData(eachBulletDamage, nowBulletLevel));
	allBullet.pushBack(bullet);
	this->bulletBatchNodeVector[nowBulletLevel]->addChild(bullet);

	float bulletFlyLenth = Director::getInstance()->getWinSize().height - bulletPosition.y + (bullet->getContentSize().height / 2);
	float bulletFlySpeed = 1000 / 1;
	float bulletFltTime = bulletFlyLenth / bulletFlySpeed;

	FiniteTimeAction* bulletMove = MoveTo::create(bulletFltTime, Point(bulletPosition.x, Director::getInstance()->getWinSize().height + bullet->getContentSize().height / 2));
	FiniteTimeAction* bulletRemove = CallFuncN::create(CC_CALLBACK_1(BulletLayer::bulletMoveFinished, this));

	auto bulleAction = Sequence::create(bulletMove, bulletRemove, NULL);
	bullet->runAction(bulleAction);
}

void BulletLayer::bulletMoveFinished(Node* pSender) {
	Sprite* bullet = static_cast<Sprite*>(pSender);
	BulletUserData* bulletUserData = static_cast<BulletUserData*>(bullet->getUserData());
	int bulletLevel = bulletUserData->getBulletLevel();
	delete bulletUserData;
	allBullet.eraseObject(bullet);
	this->bulletBatchNodeVector[bulletLevel]->removeChild(bullet, true);
}

void BulletLayer::startShooting() {
	this->schedule(schedule_selector(BulletLayer::addBullet), UserDefault::getInstance()->getFloatForKey("intervalOfAddBullet"));
}

void BulletLayer::stopShooting() {
	this->unschedule(schedule_selector(BulletLayer::addBullet));
}

BulletLayer::BulletLayer() :
		eachBulletDamage(UserDefault::getInstance()->getIntegerForKey("damageOfInitBullet")), nowBulletLevel(0) {
}

BulletLayer::~BulletLayer() {
}

void BulletLayer::setBulletLevelUP() {
	if (nowBulletLevel < 2) {
		this->nowBulletLevel += 1;
		this->eachBulletDamage += UserDefault::getInstance()->getIntegerForKey("damageOfDeltaWhenLevelUp");
	}
}

void BulletLayer::launchBigBomb() {
	for(int i = 0; i < Director::getInstance()->getWinSize().width + Sprite::createWithSpriteFrameName("bigBomb.png")->getContentSize().width ; i += Sprite::createWithSpriteFrameName("bigBomb.png")->getContentSize().width){
		Sprite* bigBomb = Sprite::createWithSpriteFrameName("bigBomb.png");
		bigBomb->setPosition(i, - bigBomb->getContentSize().height /2);
		bigBomb->setUserData(new BulletUserData(UserDefault::getInstance()->getIntegerForKey("damageOfBigBomb"), 3));
		allBullet.pushBack(bigBomb);
		this->bulletBatchNodeVector[3]->addChild(bigBomb);

		float bulletFlyLenth = Director::getInstance()->getWinSize().height - bigBomb->getPositionY() + (bigBomb->getContentSize().height / 2);
		float bulletFlySpeed = 1000 / 1;
		float bulletFltTime = bulletFlyLenth / bulletFlySpeed;

		FiniteTimeAction* bulletMove = MoveTo::create(bulletFltTime, Point(bigBomb->getPositionX(), Director::getInstance()->getWinSize().height + bigBomb->getContentSize().height / 2));
		FiniteTimeAction* bulletRemove = CallFuncN::create(CC_CALLBACK_1(BulletLayer::bulletMoveFinished, this));

		auto bulleAction = Sequence::create(bulletMove, bulletRemove, NULL);
		bigBomb->runAction(bulleAction);
	}
}

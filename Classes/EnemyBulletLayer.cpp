/*
 * EnemyBulletLayer.cpp
 *
 *  Created on: 2015年1月29日
 *      Author: netbeen
 */

#include "EnemyBulletLayer.h"
#include "GameScene.h"
#include "ResultScene.h"

USING_NS_CC;

void EnemyBulletLayer::bossStartShooting() {
	this->schedule(schedule_selector(EnemyBulletLayer::addBossBulletSet), UserDefault::getInstance()->getFloatForKey("intervalOfAddEnemyBullet"));
	this->scheduleUpdate();
}

void EnemyBulletLayer::bossStopShooting() {
	this->unschedule(schedule_selector(EnemyBulletLayer::addBossBulletSet));
	this->unscheduleUpdate();
}

bool EnemyBulletLayer::init(){
	return true;
}

EnemyBulletLayer::EnemyBulletLayer() :actionExplosion(nullptr){
	winSize = Director::getInstance()->getWinSize();
}

void EnemyBulletLayer::addBossBulletSet(float useless) {
	Sprite* bulletSet = Sprite::createWithSpriteFrameName("enemyBulletSet.png");

	Point bossPosition = static_cast<GameScene*>(this->getParent())->getEnemyLayer()->getBossSprite()->getPosition();
	bulletSet->setPosition(bossPosition);
	allEnemyBullet.pushBack(bulletSet);
	this->addChild(bulletSet);

	FiniteTimeAction* bulletSetMove = MoveTo::create(2, Point(-winSize.width/2 + CCRANDOM_0_1()*winSize.width*2, -bulletSet->getContentSize().height/2));
	FiniteTimeAction* bulletSetRemove = CallFuncN::create(CC_CALLBACK_1(EnemyBulletLayer::bossBulletMoveFinished, this));
	Sequence* bulletSetSequence = Sequence::create(bulletSetMove, bulletSetRemove, NULL);
	bulletSet->runAction(bulletSetSequence);
}

void EnemyBulletLayer::bossBulletMoveFinished(Node* pSender) {
	Sprite* bullet = static_cast<Sprite*>(pSender);
	this->allEnemyBullet.eraseObject(bullet);
	this->removeChild(bullet);
}

void EnemyBulletLayer::update(float useless) {
	Animation* animationExplosion = AnimationCache::getInstance()->getAnimation("explosion");
		animationExplosion->setRestoreOriginalFrame(false);
		animationExplosion->setDelayPerUnit(0.5f / 9.0f);
		actionExplosion = Animate::create(animationExplosion);

	Sprite* myPlane = static_cast<GameScene*>(this->getParent())->getPlaneLayer()->getMyPlane();
	for (Sprite* bullet : this->allEnemyBullet) {
		if (bullet->getBoundingBox().intersectsRect(myPlane->getBoundingBox())) {

			if(static_cast<PlaneUserData*>(myPlane->getUserData())->isAliveUnderAttack(200) == false){
				//更新HP指示器
				static_cast<GameScene*>(this->getParent())->getControlLayer()->updateHPIndicator();
				static_cast<GameScene*>(this->getParent())->getBulletLayer()->stopShooting();
				myPlane->runAction(Sequence::create(actionExplosion, NULL));
				scheduleOnce(schedule_selector(EnemyBulletLayer::changeSceneCallBack), 1.0f);
				this->bossStopShooting();
				return;
			}else{
				//更新HP指示器
				static_cast<GameScene*>(this->getParent())->getControlLayer()->updateHPIndicator();
			}
			bossBulletMoveFinished(bullet);
		}
	}
}

void EnemyBulletLayer::changeSceneCallBack(float useless) {
	Scene* resultSceneWithAnimation = TransitionFade::create(2.0f, ResultScene::create(false, static_cast<GameScene*>(this->getParent())->getControlLayer()->getScore()));
	Director::getInstance()->replaceScene(resultSceneWithAnimation);
}

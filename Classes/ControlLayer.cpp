/*
 * ControlLayer.cpp
 *
 *  Created on: 2015年1月20日
 *      Author: netbeen
 */

#include "ControlLayer.h"

#include "GameScene.h"

USING_NS_CC;

ControlLayer::ControlLayer() :
		score(0), scoreLabel(nullptr), pauseButtonItem(nullptr),HPIndicator(nullptr),launchButton(nullptr),launchButtonItem(nullptr),pauseButton(nullptr) {
}

void ControlLayer::addScoreBy(int addScore) {
	this->score += addScore;
	this->updateScore();
	return;
}

bool ControlLayer::init() {
	auto listenerkeyPad = EventListenerKeyboard::create();
	listenerkeyPad->onKeyReleased = CC_CALLBACK_2(ControlLayer::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerkeyPad, this);

	scoreLabel = Label::createWithTTF("0", "fonts/MarkerFelt.ttf", 60);
	scoreLabel->setAnchorPoint(Point(1.0f, 1.0f));
	scoreLabel->setPosition(Director::getInstance()->getWinSize().width - 50, Director::getInstance()->getWinSize().height - 50);
	this->addChild(scoreLabel);

	pauseButtonItem = MenuItemSprite::create(Sprite::createWithSpriteFrameName("pauseButton.png"), Sprite::createWithSpriteFrameName("pauseButton.png"),CC_CALLBACK_1(ControlLayer::menuPauseCallback, this));
	pauseButton = Menu::create(pauseButtonItem, nullptr);
	pauseButton->setAnchorPoint(Point(0.0f, 1.0f));
	pauseButton->setPosition(75, Director::getInstance()->getWinSize().height - 75);
	this->addChild(pauseButton);

	Sprite* HPBottomSprite = Sprite::createWithSpriteFrameName("HPBottom.png");
	HPBottomSprite->setPosition(100, 100);
	this->addChild(HPBottomSprite);
	Sprite* HP = Sprite::createWithSpriteFrameName("HP.png");
	HPIndicator = ProgressTimer::create(HP);
	HPIndicator->setType(ProgressTimer::Type::RADIAL);
	HPIndicator->setPercentage(100);
	HPIndicator->setPosition(100, 100);
	addChild(HPIndicator, 0, 0);

	launchButtonItem = MenuItemSprite::create(Sprite::createWithSpriteFrameName("launchButton.png"), Sprite::createWithSpriteFrameName("launchButton.png"), Sprite::createWithSpriteFrameName("launchButtonUnable.png"), CC_CALLBACK_1(ControlLayer::menuLaunchCallback, this));
	launchButton = Menu::create(launchButtonItem, nullptr);
	launchButton->setPosition(100, 100);

	launchButtonItem->setEnabled(false);
	launchButton->setEnabled(false);

	this->addChild(launchButton);
	return true;
}

void ControlLayer::updateHPIndicator(){
	int HP = static_cast<PlaneUserData*>(static_cast<GameScene*>(this->getParent())->getPlaneLayer()->getMyPlane()->getUserData())->getHP();
	int initHP = static_cast<GameScene*>(this->getParent())->getPlaneLayer()->getInitHP();
	float HPOld = HPIndicator->getPercentage();
	float HPPercentage = static_cast<float>(HP) / static_cast<float>(initHP);
	ProgressFromTo* animation = ProgressFromTo::create(0.2, HPOld, HPPercentage * 100);
	HPIndicator->runAction(animation);
}

void ControlLayer::updateScore() {
	std::string strScore;
	std::strstream ss;
	ss << this->score;
	ss >> strScore;
	scoreLabel->setString(strScore.c_str());
	if(this->score % 1000 == 0){
		static_cast<GameScene*>(this->getParent())->getUFOLayer()->addGiftSprite();
	}
}

void ControlLayer::menuPauseCallback(Ref* pSender) {
	//如果游戏已在暂停中
	if (Director::getInstance()->isPaused()) {
		Director::getInstance()->resume();
		pauseButtonItem->setNormalImage(Sprite::createWithSpriteFrameName("pauseButton.png"));
		pauseButtonItem->setSelectedImage(Sprite::createWithSpriteFrameName("startButton.png"));
	} else {
	//如果游戏正在进行
		Director::getInstance()->pause();
		pauseButtonItem->setNormalImage(Sprite::createWithSpriteFrameName("startButton.png"));
		pauseButtonItem->setSelectedImage(Sprite::createWithSpriteFrameName("pauseButton.png"));
	}
}

void ControlLayer::menuLaunchCallback(Ref* pSender){
	launchButtonItem->setEnabled(false);
	launchButton->setEnabled(false);
	static_cast<GameScene*>(this->getParent())->getBulletLayer()->launchBigBomb();
}

void ControlLayer::setLaunchButtonEnable(){
	launchButtonItem->setEnabled(true);
	launchButton->setEnabled(true);
}

void ControlLayer::onKeyReleased(EventKeyboard::KeyCode keycode, Event* event){
	switch (keycode) {
		case EventKeyboard::KeyCode::KEY_BACK:
			Director::getInstance()->end();
			break;
		default:
			break;
	}
}

int ControlLayer::getScore(){
	return this->score;
}

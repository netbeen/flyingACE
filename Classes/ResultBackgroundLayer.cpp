/*
 * ResultBackgroundLayer.cpp
 *
 *  Created on: 2015年1月27日
 *      Author: netbeen
 */

#include "ResultBackgroundLayer.h"

USING_NS_CC;

bool ResultBackgroundLayer::init() {
	auto listenerkeyPad = EventListenerKeyboard::create();
	listenerkeyPad->onKeyReleased = CC_CALLBACK_2(ResultBackgroundLayer::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerkeyPad, this);

	auto background = Sprite::createWithSpriteFrameName("img_bg_welcome.jpg");
	background->setAnchorPoint(Point(0, 0));
	background->setScale(2);
	this->addChild(background);
	return true;
}

void ResultBackgroundLayer::setIsWin(bool isWin) {
	this->isWin = isWin;
}

void ResultBackgroundLayer::setScore(int score) {
	this->score = score;
}

void ResultBackgroundLayer::displayInfomation() {
	std::string strScore;
	std::strstream ss;
	ss << this->score;
	ss >> strScore;

	TTFConfig ttfConfig("fonts/MarkerFelt.ttf", 100);

	scoreLabel = Label::createWithTTF(ttfConfig, strScore.c_str(), TextHAlignment::CENTER);

	if (this->isWin == true) {
		winOrLose = Label::createWithTTF(ttfConfig, "WIN!!!", TextHAlignment::CENTER);
		winOrLose->enableShadow();
		winOrLose->setColor(Color3B(255, 201, 37));
		scoreLabel->setColor(Color3B(255, 201, 37));
	} else {
		winOrLose = Label::createWithTTF(ttfConfig, "LOSE", TextHAlignment::CENTER);
		winOrLose->enableShadow();
		winOrLose->setColor(Color3B(100, 100, 100));
		scoreLabel->setColor(Color3B(100, 100, 100));
	}

	winOrLose->setPosition(Director::getInstance()->getWinSize().width / 2, Director::getInstance()->getWinSize().height / 2 + 200);
	this->addChild(winOrLose);

	scoreLabel->setPosition(Director::getInstance()->getWinSize().width / 2, Director::getInstance()->getWinSize().height / 2);
	this->addChild(scoreLabel);

}

void ResultBackgroundLayer::onKeyReleased(EventKeyboard::KeyCode keycode, Event* event) {
	switch (keycode) {
	case EventKeyboard::KeyCode::KEY_BACK:
		Director::getInstance()->end();
		break;
	default:
		break;
	}
}

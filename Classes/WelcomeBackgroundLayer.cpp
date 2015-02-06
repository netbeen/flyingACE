/*
 * WelcomeBackgroundLayer.cpp
 *
 *  Created on: 2015年1月27日
 *      Author: netbeen
 */

#include "WelcomeBackgroundLayer.h"

USING_NS_CC;

bool WelcomeBackgroundLayer::init() {
	auto listenerkeyPad = EventListenerKeyboard::create();
	listenerkeyPad->onKeyReleased = CC_CALLBACK_2(WelcomeBackgroundLayer::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerkeyPad, this);

	Sprite* background = Sprite::createWithSpriteFrameName("img_bg_welcome.jpg");
	background->setAnchorPoint(Point(0, 0));
	background->setScale(2);
	this->addChild(background);

	Sprite* logo = Sprite::createWithSpriteFrameName("logo.png");
	logo->setAnchorPoint(Point(0.5, 0.5));
	logo->setPosition(Director::getInstance()->getWinSize().width / 2, 650);
	this->addChild(logo);

	return true;
}

void WelcomeBackgroundLayer::onKeyReleased(EventKeyboard::KeyCode keycode, Event* event) {
	switch (keycode) {
	case EventKeyboard::KeyCode::KEY_BACK:
		Director::getInstance()->end();
		break;
	default:
		break;
	}
}

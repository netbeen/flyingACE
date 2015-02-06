/*
 * SelectBackground.cpp
 *
 *  Created on: 2015年1月30日
 *      Author: netbeen
 */

#include "SelectBackgroundLayer.h"

USING_NS_CC;

bool SelectBackgroundLayer::init() {
	auto listenerkeyPad = EventListenerKeyboard::create();
	listenerkeyPad->onKeyReleased = CC_CALLBACK_2(SelectBackgroundLayer::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerkeyPad, this);

	Sprite* background = Sprite::createWithSpriteFrameName("selectSceneBackground.jpg");
	background->setScale(2.0f);
	background->setAnchorPoint(Point(0, 0));
	this->addChild(background);

	Sprite* blank1 = Sprite::createWithSpriteFrameName("img_bg_1.jpg");
	blank1->setScale(0.5);
	blank1->setAnchorPoint(Point(0, 0));
	blank1->setPosition(75, 700);
	this->addChild(blank1);

	Sprite* blank2 = Sprite::createWithSpriteFrameName("blank.png");
	blank2->setAnchorPoint(Point(0, 0));
	blank2->setPosition(275, 700);
	this->addChild(blank2);

	Sprite* blank3 = Sprite::createWithSpriteFrameName("blank.png");
	blank3->setAnchorPoint(Point(0, 0));
	blank3->setPosition(475, 700);
	this->addChild(blank3);

	Sprite* blank4 = Sprite::createWithSpriteFrameName("blank.png");
	blank4->setAnchorPoint(Point(0, 0));
	blank4->setPosition(75, 350);
	this->addChild(blank4);

	Sprite* blank5 = Sprite::createWithSpriteFrameName("blank.png");
	blank5->setAnchorPoint(Point(0, 0));
	blank5->setPosition(275, 350);
	this->addChild(blank5);

	Sprite* blank6 = Sprite::createWithSpriteFrameName("blank.png");
	blank6->setAnchorPoint(Point(0, 0));
	blank6->setPosition(475, 350);
	this->addChild(blank6);

	TTFConfig ttfConfig("fonts/SIMLI.TTF", 100);

	Label* titleLabel = Label::createWithTTF(ttfConfig, "选择关卡", TextHAlignment::CENTER);
	titleLabel->enableShadow();
	titleLabel->setColor(Color3B(255, 201, 37));
	titleLabel->setPosition(Director::getInstance()->getWinSize().width / 2, Director::getInstance()->getWinSize().height - 100);
	this->addChild(titleLabel);
	return true;
}

void SelectBackgroundLayer::onKeyReleased(EventKeyboard::KeyCode keycode, Event* event) {
	switch (keycode) {
	case EventKeyboard::KeyCode::KEY_BACK:
		Director::getInstance()->end();
		break;
	default:
		break;
	}
}

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
	//blank1->setAnchorPoint(Point(0, 0));
	blank1->setPosition(75 + 90, 700 + 160);
	this->addChild(blank1);

	Sprite* blank2 = Sprite::createWithSpriteFrameName("blank.png");
	blank2->setPosition(275 + 90, 700 + 160);
	this->addChild(blank2);
	Sprite* blank2_locked = Sprite::createWithSpriteFrameName("locked.png");
	blank2_locked->setPosition(275 + 90, 700 + 160);
	this->addChild(blank2_locked);

	Sprite* blank3 = Sprite::createWithSpriteFrameName("blank.png");
	blank3->setPosition(475 + 90, 700 + 160);
	this->addChild(blank3);
	Sprite* blank3_locked = Sprite::createWithSpriteFrameName("locked.png");
	blank3_locked->setPosition(475 + 90, 700 + 160);
	this->addChild(blank3_locked);

	Sprite* blank4 = Sprite::createWithSpriteFrameName("blank.png");
	blank4->setPosition(75 + 90, 350 + 160);
	this->addChild(blank4);
	Sprite* blank4_locked = Sprite::createWithSpriteFrameName("locked.png");
	blank4_locked->setPosition(75 + 90, 350 + 160);
	this->addChild(blank4_locked);

	Sprite* blank5 = Sprite::createWithSpriteFrameName("blank.png");
	blank5->setPosition(275 + 90, 350 + 160);
	this->addChild(blank5);
	Sprite* blank5_locked = Sprite::createWithSpriteFrameName("locked.png");
	blank5_locked->setPosition(275 + 90, 350 + 160);
	this->addChild(blank5_locked);

	Sprite* blank6 = Sprite::createWithSpriteFrameName("blank.png");
	blank6->setPosition(475 + 90, 350 + 160);
	this->addChild(blank6);
	Sprite* blank6_locked = Sprite::createWithSpriteFrameName("locked.png");
	blank6_locked->setPosition(475 + 90, 350 + 160);
	this->addChild(blank6_locked);

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

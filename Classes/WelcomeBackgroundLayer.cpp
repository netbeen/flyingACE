/*
 * WelcomeBackgroundLayer.cpp
 *
 *  Created on: 2015年1月27日
 *      Author: netbeen
 */

#include "WelcomeBackgroundLayer.h"

USING_NS_CC;

bool WelcomeBackgroundLayer::init(){
	Sprite* background = Sprite::createWithSpriteFrameName("img_bg_welcome.jpg");
	background->setAnchorPoint(Point(0,0));
	background->setScale(2);
	this->addChild(background);

	Sprite* logo = Sprite::createWithSpriteFrameName("logo.png");
	logo->setAnchorPoint(Point(0.5,0.5));
	logo->setPosition(Director::getInstance()->getWinSize().width/2, 650);
	this->addChild(logo);

	return true;
}

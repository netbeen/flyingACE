/*
 * WelcomeButtonLayer.cpp
 *
 *  Created on: 2015年1月25日
 *      Author: netbeen
 */

#include "WelcomeButtonLayer.h"

USING_NS_CC;

bool WelcomeButtonLayer::init() {
	MenuItemSprite* startGameButtonItemSprite = MenuItemSprite::create(Sprite::createWithSpriteFrameName("startGameButton.png"), Sprite::createWithSpriteFrameName("startGameButton.png"), CC_CALLBACK_1(WelcomeButtonLayer::startGameButtonCallback, this));
	Menu* startGameButton = Menu::create(startGameButtonItemSprite, nullptr);
	startGameButton->setAnchorPoint(Point(0.0f, 1.0f));
	startGameButton->setPosition(Director::getInstance()->getWinSize().width/2, 200);
	this->addChild(startGameButton);
	return true;
}

void WelcomeButtonLayer::startGameButtonCallback(Ref* pSender) {
	Scene* resultSceneWithAnimation = TransitionFade::create(2.0f, SelectScene::create());
	Director::getInstance()->replaceScene(resultSceneWithAnimation);
}

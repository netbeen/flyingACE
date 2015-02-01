/*
 * ResultButtonLayer.cpp
 *
 *  Created on: 2015年1月25日
 *      Author: netbeen
 */

#include "ResultButtonLayer.h"

USING_NS_CC;

bool ResultButtonLayer::init() {
	MenuItemSprite* restartGameButtonItemSprite = MenuItemSprite::create(Sprite::createWithSpriteFrameName("restartGameButton.png"), Sprite::createWithSpriteFrameName("restartGameButton.png"), CC_CALLBACK_1(ResultButtonLayer::restartGameButtonCallback, this));
	Menu* restartGameButton = Menu::create(restartGameButtonItemSprite, nullptr);
	restartGameButton->setPosition(Director::getInstance()->getWinSize().width/2,400);
	this->addChild(restartGameButton);

	MenuItemSprite* backToMenuButtonItemSprite = MenuItemSprite::create(Sprite::createWithSpriteFrameName("backToMenuButton.png"), Sprite::createWithSpriteFrameName("backToMenuButton.png"), CC_CALLBACK_1(ResultButtonLayer::backToMenuButtonCallback, this));
	Menu* backToMenuButton = Menu::create(backToMenuButtonItemSprite, nullptr);
	backToMenuButton->setPosition(Director::getInstance()->getWinSize().width/2,330);
	this->addChild(backToMenuButton);

	return true;
}

void ResultButtonLayer::restartGameButtonCallback(Ref* pSender){
	Scene* welcomeScene = TransitionFade::create(2.0f,GameScene::create());
	Director::getInstance()->replaceScene(welcomeScene);
}

void ResultButtonLayer::backToMenuButtonCallback(Ref* pSender){
	Scene* welcomeScene = TransitionFade::create(2.0f,WelcomeScene::create());
	Director::getInstance()->replaceScene(welcomeScene);
}

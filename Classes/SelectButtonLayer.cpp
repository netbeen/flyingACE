/*
 * SelectButtonLayer.cpp
 *
 *  Created on: 2015年1月30日
 *      Author: netbeen
 */

#include "SelectButtonLayer.h"

USING_NS_CC;

bool SelectButtonLayer::init() {
	MenuItemSprite* startGameButtonItemSprite = MenuItemSprite::create(Sprite::createWithSpriteFrameName("selectStartButton.png"), Sprite::createWithSpriteFrameName("selectStartButton.png"), CC_CALLBACK_1(SelectButtonLayer::startGameButtonCallback, this));
	Menu* startGameButton = Menu::create(startGameButtonItemSprite, nullptr);
	startGameButton->setPosition(Director::getInstance()->getWinSize().width/2,170);
	this->addChild(startGameButton);

	return true;
}

void SelectButtonLayer::startGameButtonCallback(Ref* pSender){
	Scene* resultSceneWithAnimation = TransitionFade::create(2.0f, GameScene::create());
	Director::getInstance()->replaceScene(resultSceneWithAnimation);
}

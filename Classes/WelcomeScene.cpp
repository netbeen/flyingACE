/*
 * WelcomeScene.cpp
 *
 *  Created on: 2015年1月25日
 *      Author: netbeen
 */

#include "WelcomeScene.h"

USING_NS_CC;

Scene* WelcomeScene::welcomeScene = nullptr;
WelcomeButtonLayer* WelcomeScene::welcomeButtonLayer = nullptr;
WelcomeBackgroundLayer* WelcomeScene::welcomeBackgroundLayer = nullptr;

Scene* WelcomeScene::create() {
	Scene* welcomeScene = Scene::create();

	welcomeBackgroundLayer = WelcomeBackgroundLayer::create();
	welcomeBackgroundLayer->setParent(welcomeScene);
	welcomeScene->addChild(welcomeBackgroundLayer);

	welcomeButtonLayer = WelcomeButtonLayer::create();
	welcomeButtonLayer->setParent(welcomeScene);
	welcomeScene->addChild(welcomeButtonLayer);

	return welcomeScene;
}


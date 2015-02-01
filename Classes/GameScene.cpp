/*
 * GameScene.cpp
 *
 *  Created on: 2015年1月25日
 *      Author: netbeen
 */

#include "GameScene.h"

#include <iostream>

USING_NS_CC;

Scene* GameScene::gameScene = nullptr;
GameBackgroundLayer* GameScene::gameBackgroundLayer = nullptr;
UFOLayer* GameScene::ufoLayer = nullptr;
BulletLayer* GameScene::bulletLayer = nullptr;
EnemyLayer* GameScene::enemyLayer = nullptr;
PlaneLayer* GameScene::planeLayer = nullptr;
ControlLayer* GameScene::controlLayer = nullptr;
EnemyBulletLayer* GameScene::enemyBulletLayer = nullptr;

Scene* GameScene::create() {
	gameScene = Scene::create();

	gameBackgroundLayer = GameBackgroundLayer::create();
	gameBackgroundLayer->setParent(gameScene);
	planeLayer = PlaneLayer::create();
	planeLayer->setParent(gameScene);
	ufoLayer = UFOLayer::create();
	ufoLayer->setParent(gameScene);
	bulletLayer = BulletLayer::create();
	bulletLayer->setParent(gameScene);
	enemyLayer = EnemyLayer::create();
	enemyLayer->setParent(gameScene);
	controlLayer = ControlLayer::create();
	controlLayer->setParent(gameScene);
	enemyBulletLayer = EnemyBulletLayer::create();
	enemyBulletLayer->setParent(gameScene);


	gameScene->addChild(gameBackgroundLayer);
	gameScene->addChild(bulletLayer);
	gameScene->addChild(enemyBulletLayer);
	gameScene->addChild(enemyLayer);
	gameScene->addChild(planeLayer);
	gameScene->addChild(ufoLayer);
	gameScene->addChild(controlLayer);

	return gameScene;
}

PlaneLayer* GameScene::getPlaneLayer(){
	return this->planeLayer;
}

GameBackgroundLayer* GameScene::getGameBackgroundLayer(){
	return this->gameBackgroundLayer;
}

UFOLayer* GameScene::getUFOLayer(){
	return this->ufoLayer;
}
BulletLayer* GameScene::getBulletLayer(){
	return this->bulletLayer;
}
EnemyLayer* GameScene::getEnemyLayer(){
	return this->enemyLayer;
}
ControlLayer* GameScene::getControlLayer(){
	return this->controlLayer;
}

EnemyBulletLayer* GameScene::getEnemyBulletLayer(){
	return this->enemyBulletLayer;
}

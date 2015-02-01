/*
 * GameScene.h
 *
 *  Created on: 2015年1月25日
 *      Author: netbeen
 */

#ifndef GAMESCENE_H_
#define GAMESCENE_H_

#include "cocos2d.h"
#include "GameBackgroundLayer.h"
#include "PlaneLayer.h"
#include "BulletLayer.h"
#include "EnemyLayer.h"
#include "ControlLayer.h"
#include "UFOLayer.h"
#include "EnemyBulletLayer.h"

class GameScene: public cocos2d::Scene {
public:
	static cocos2d::Scene* create();
	GameBackgroundLayer* getGameBackgroundLayer();
	UFOLayer* getUFOLayer();
	BulletLayer* getBulletLayer();
	EnemyLayer* getEnemyLayer();
	ControlLayer* getControlLayer();
	PlaneLayer* getPlaneLayer();
	EnemyBulletLayer* getEnemyBulletLayer();
private:
	static cocos2d::Scene* gameScene;
	static GameBackgroundLayer* gameBackgroundLayer;
	static UFOLayer* ufoLayer;
	static BulletLayer* bulletLayer;
	static EnemyLayer* enemyLayer;
	static PlaneLayer* planeLayer;
	static ControlLayer* controlLayer;
	static EnemyBulletLayer* enemyBulletLayer;

};

#endif /* GAMESCENE_H_ */

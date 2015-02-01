/*
 * SelectScene.h
 *
 *  Created on: 2015年1月30日
 *      Author: netbeen
 */

#ifndef SELECTSCENE_H_
#define SELECTSCENE_H_

#include "cocos2d.h"
#include "SelectBackgroundLayer.h"
#include "SelectButtonLayer.h"

class SelectScene : public cocos2d::Scene{
public:
	static Scene* create();
private:
	static Scene* selectScene;

};

#endif /* SELECTSCENE_H_ */

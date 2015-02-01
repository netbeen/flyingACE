/*
 * WelcomeButtonLayer.h
 *
 *  Created on: 2015年1月25日
 *      Author: netbeen
 */

#ifndef WELCOMEBUTTONLAYER_H_
#define WELCOMEBUTTONLAYER_H_

#include "cocos2d.h"
#include "GameScene.h"
#include "SelectScene.h"

class WelcomeButtonLayer : public cocos2d::Layer{
public:
	CREATE_FUNC(WelcomeButtonLayer);
private:
	void startGameButtonCallback(Ref* pSender);
	virtual bool init() override;
};

#endif /* WELCOMEBUTTONLAYER_H_ */

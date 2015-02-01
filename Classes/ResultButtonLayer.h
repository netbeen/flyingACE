/*
 * ResultButtonLayer.h
 *
 *  Created on: 2015年1月25日
 *      Author: netbeen
 */

#ifndef RESULTBUTTONLAYER_H_
#define RESULTBUTTONLAYER_H_

#include "cocos2d.h"
#include "GameScene.h"
#include "WelcomeScene.h"

class ResultButtonLayer : public cocos2d::Layer{
public:
	CREATE_FUNC(ResultButtonLayer);
private:
	void restartGameButtonCallback(Ref* pSender);
	void backToMenuButtonCallback(Ref* pSender);
	virtual bool init() override;
};

#endif /* RESULTBUTTONLAYER_H_ */

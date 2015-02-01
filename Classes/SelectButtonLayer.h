/*
 * SelectButtonLayer.h
 *
 *  Created on: 2015年1月30日
 *      Author: netbeen
 */

#ifndef SELECTBUTTONLAYER_H_
#define SELECTBUTTONLAYER_H_

#include "cocos2d.h"
#include "GameScene.h"

class SelectButtonLayer :public cocos2d::Layer{
public:
	CREATE_FUNC(SelectButtonLayer);
private:
	virtual bool init() override;
	void startGameButtonCallback(Ref* pSender);

};

#endif /* SELECTBUTTONLAYER_H_ */

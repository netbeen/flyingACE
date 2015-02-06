/*
 * WelcomeBackgroundLayer.h
 *
 *  Created on: 2015年1月27日
 *      Author: netbeen
 */

#ifndef WELCOMEBACKGROUNDLAYER_H_
#define WELCOMEBACKGROUNDLAYER_H_

#include "cocos2d.h"

class WelcomeBackgroundLayer : public cocos2d::Layer{
public:
	CREATE_FUNC(WelcomeBackgroundLayer);
private:
	virtual bool init() override;
	virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event) override;//对应back键
};

#endif /* WELCOMEBACKGROUNDLAYER_H_ */

/*
 * SelectBackground.h
 *
 *  Created on: 2015年1月30日
 *      Author: netbeen
 */

#ifndef SELECTBACKGROUNDLAYER_H_
#define SELECTBACKGROUNDLAYER_H_

#include "cocos2d.h"

class SelectBackgroundLayer : public cocos2d::Layer{
public:
	CREATE_FUNC(SelectBackgroundLayer);
private:
	virtual bool init() override;
	virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event) override;//对应back键
};

#endif /* SELECTBACKGROUNDLAYER_H_ */

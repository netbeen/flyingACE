/*
 * ControlLayer.h
 *
 *  Created on: 2015年1月20日
 *      Author: netbeen
 */

#ifndef CONTROLLAYER_H_
#define CONTROLLAYER_H_

#include <strstream>
#include "cocos2d.h"
#include "GameBackgroundLayer.h"
#include "PlaneLayer.h"
#include "PlaneUserData.h"
#include "UFOLayer.h"


class ControlLayer : public cocos2d::Layer{
public:
	CREATE_FUNC(ControlLayer);
	void addScoreBy(int addScore);
	void updateHPIndicator();
	void setLaunchButtonEnable();
	int getScore();
private:
	int score;
	cocos2d::Label* scoreLabel;
	cocos2d::MenuItemSprite* pauseButtonItem;
	cocos2d::MenuItemSprite* launchButtonItem;
	cocos2d::ProgressTimer* HPIndicator;
	cocos2d::Menu* pauseButton;
	cocos2d::Menu* launchButton;

	void updateScore();
	void menuPauseCallback(cocos2d::Ref* pSender);
	ControlLayer();
	virtual bool init() override;
	void menuLaunchCallback(cocos2d::Ref* pSender);
	virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event) override;//对应back键
};

#endif /* CONTROLLAYER_H_ */

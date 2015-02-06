/*
 * ResultBackgroundLayer.h
 *
 *  Created on: 2015年1月27日
 *      Author: netbeen
 */

#ifndef RESULTBACKGROUNDLAYER_H_
#define RESULTBACKGROUNDLAYER_H_

#include "cocos2d.h"
#include <strstream>

class ResultBackgroundLayer : public cocos2d::Layer{
public:
	CREATE_FUNC(ResultBackgroundLayer);
	void setIsWin(bool isWin);
	void setScore(int score);
	void displayInfomation();
private:
	bool isWin;
	int score;
	cocos2d::Label* winOrLose;
	cocos2d::Label* scoreLabel;

	virtual bool init() override;
	virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event) override;//对应back键
};

#endif /* RESULTBACKGROUNDLAYER_H_ */

/*
 * PlaneLayer.h
 *
 *  Created on: 2015年1月16日
 *      Author: netbeen
 */

#ifndef PLANELAYER_H_
#define PLANELAYER_H_

#include "cocos2d.h"
#include "PlaneUserData.h"

class PlaneLayer : public cocos2d::Layer{
public:
	CREATE_FUNC(PlaneLayer);
	cocos2d::Sprite* getMyPlane();
	int getInitHP() const;

private:
	const int initHP;
	PlaneLayer();
	const cocos2d::Size winSize;
	virtual bool init() override;
	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event) override;
    virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event) override;
    cocos2d::Sprite* myPlane;
};

#endif /* PLANELAYER_H_ */

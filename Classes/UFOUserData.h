/*
 * UFOUserData.h
 *
 *  Created on: 2015年1月23日
 *      Author: netbeen
 */

#ifndef UFOUSERDATA_H_
#define UFOUSERDATA_H_

class UFOUserData {
public:
	UFOUserData(int initGiftKind);
	int getGiftKind();
private:
	int giftKind;
};

#endif /* UFOUSERDATA_H_ */

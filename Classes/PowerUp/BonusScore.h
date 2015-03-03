

#ifndef BonusScore_H_
#define BonusScore_H_

#include "cocos2d.h"
#include "../Sprite/Item.h"

using namespace cocos2d;

class BonusScore: public Item {
public:
	BonusScore();
	virtual ~BonusScore();
	static BonusScore* createBonusScore();
};

#endif /* BonusScore_H_ */



#ifndef FireBallItem_H_
#define FireBallItem_H_
#include "cocos2d.h"
#include "../Sprite/Item.h"
using namespace cocos2d;
class FireBallItem: public Item {
public:
	FireBallItem();
	virtual ~FireBallItem();

	static FireBallItem* createFireBallItem();
};

#endif /* FireBallItem_H_ */

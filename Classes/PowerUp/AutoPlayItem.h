

#ifndef REVERSEITEM_H_
#define REVERSEITEM_H_

#include "cocos2d.h"
#include "../Sprite/Item.h"

using namespace cocos2d;
class AutoPlayItem: public Item {
public:
	AutoPlayItem();
	virtual ~AutoPlayItem();
	static AutoPlayItem* createAutoPlayItem();

};

#endif /* REVERSEITEM_H_ */

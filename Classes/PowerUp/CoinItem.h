
#ifndef CoinItem_H_
#define CoinItem_H_

#include "cocos2d.h"
#include "../Sprite/Item.h"
#define PTM_RATIO 32.0
using namespace cocos2d;

class CoinItem: public Item {
public:
	CoinItem();
	virtual ~CoinItem();
	static CoinItem* createCoinItem();

};

#endif /* CoinItem_H_ */

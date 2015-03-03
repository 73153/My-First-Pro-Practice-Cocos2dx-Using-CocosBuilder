
#include "../PowerUp/CoinItem.h"

CoinItem::CoinItem() {
	function = "CoinDetecttion";
    itemSprite=this;
}

CoinItem::~CoinItem() {
	
}

CoinItem* CoinItem::createCoinItem() {

	CoinItem* CoinItem = new class CoinItem();
	if (CoinItem
			&& CoinItem->initWithFile("coin.png")) {
//        CoinItem->setColor(ccc3(124,252,0));
		return CoinItem;
	}
	CC_SAFE_DELETE(CoinItem);
	return NULL;
}


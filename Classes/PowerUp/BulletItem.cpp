

#include "../PowerUp/BulletItem.h"

BulletItem::BulletItem() {
	function = "bullet";
    itemSprite=this;
}

BulletItem::~BulletItem() {
}

BulletItem* BulletItem::createBulletItem() {

	BulletItem* BulletItem = new class BulletItem();
    
	if (BulletItem && BulletItem->initWithFile("gun.png")) {
//        BulletItem->setColor(ccBLACK);
		return BulletItem;
	}
	CC_SAFE_DELETE(BulletItem);
	return NULL;
}

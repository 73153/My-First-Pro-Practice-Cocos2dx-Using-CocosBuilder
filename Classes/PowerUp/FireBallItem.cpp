

#include "../PowerUp/FireBallItem.h"

FireBallItem::FireBallItem() {
	function = "fireBall";
    itemSprite=this;

}

FireBallItem::~FireBallItem() {
	
}

FireBallItem* FireBallItem::createFireBallItem() {

	FireBallItem* FireBallItem = new class FireBallItem();
	if (FireBallItem
			&& FireBallItem->initWithFile("fire.png")) {
		return FireBallItem;
	}
	CC_SAFE_DELETE(FireBallItem);
	return NULL;

}

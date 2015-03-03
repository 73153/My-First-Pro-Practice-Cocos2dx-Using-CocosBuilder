 

#include "../PowerUp/MagnetItem.h"

MagnetItem::MagnetItem() {
	function = "magnet";
    itemSprite=this;

}

MagnetItem::~MagnetItem() {
}

MagnetItem* MagnetItem::createMagnetItem() {

	MagnetItem* MagnetItem = new class MagnetItem();
	if (MagnetItem
			&& MagnetItem->initWithFile("magnet.png")) {
//        MagnetItem->setColor(ccGREEN);
		return MagnetItem;
	}
	CC_SAFE_DELETE(MagnetItem);
	return NULL;
}

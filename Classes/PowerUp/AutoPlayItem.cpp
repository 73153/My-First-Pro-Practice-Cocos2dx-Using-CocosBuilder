

#include "../PowerUp/AutoPlayItem.h"

AutoPlayItem::AutoPlayItem() {
	function = "autoPlay";
    itemSprite=this;
}

AutoPlayItem::~AutoPlayItem() {
}

AutoPlayItem* AutoPlayItem::createAutoPlayItem() {

	AutoPlayItem* AutoPlayItem = new class AutoPlayItem();
	if (AutoPlayItem
			&& AutoPlayItem->initWithFile("autoplay.png")) {
		return AutoPlayItem;
	}
	CC_SAFE_DELETE(AutoPlayItem);
	return NULL;
}

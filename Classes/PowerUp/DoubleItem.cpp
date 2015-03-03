
#include "../PowerUp/DoubleItem.h"

DoubleItem::DoubleItem() {
	function = "double";
    itemSprite=this;
}

DoubleItem::~DoubleItem() {
	
}

DoubleItem* DoubleItem::createDoubleItem() {

	DoubleItem* doubleItem = new DoubleItem();
	if (doubleItem
			&& doubleItem->initWithFile("multiball.png")) {
//        doubleItem->setColor(ccGREEN);
		return doubleItem;
	}
	CC_SAFE_DELETE(doubleItem);
	return NULL;
}


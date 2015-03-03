
#include "../PowerUp/EnlargeItem.h"

EnlargeItem::EnlargeItem() {
	function = "enlarge";
    itemSprite=this;

}

EnlargeItem::~EnlargeItem() {
	
}

EnlargeItem* EnlargeItem::createEnlargeItem() {

	EnlargeItem* enlargeItem = new EnlargeItem();
	if (enlargeItem
			&& enlargeItem->initWithFile("enlargeItem.png")) {
//        enlargeItem->setColor(ccc3(124,252,0));
		return enlargeItem;
	}
	CC_SAFE_DELETE(enlargeItem);
	return NULL;
}


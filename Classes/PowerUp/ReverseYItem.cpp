

#include "../PowerUp/ReverseYItem.h"

ReverseYItem::ReverseYItem() {
	function = "reverseY";
    itemSprite=this;
}

ReverseYItem::~ReverseYItem() {
}


ReverseYItem* ReverseYItem::createReverseYItem() {

	ReverseYItem* reverseYItem = new class ReverseYItem();
    
	if (reverseYItem
			&& reverseYItem->initWithFile("reverseYItem.png")) {
		return reverseYItem;
	}
	CC_SAFE_DELETE(reverseYItem);
	return NULL;
}



#include "../PowerUp/ShortenItem.h"

ShortenItem::ShortenItem() {
	function = "shorten";
    itemSprite=this;
}

ShortenItem::~ShortenItem() {
}

ShortenItem* ShortenItem::createShortenItem() {

	ShortenItem* shortenItem = new class ShortenItem();
	if (shortenItem
			&& shortenItem->initWithFile("shortenItem.png")) {
//        shortenItem->setColor(ccRED);
		return shortenItem;
	}
	CC_SAFE_DELETE(shortenItem);
	return NULL;
}

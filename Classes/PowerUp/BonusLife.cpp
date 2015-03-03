 

#include "../PowerUp/BonusLife.h"

BonusLife::BonusLife() {
	function = "bonus";
    itemSprite=this;
}

BonusLife::~BonusLife() {
}

BonusLife* BonusLife::createBonusLife() {

	BonusLife* BonusLife = new class BonusLife();
	if (BonusLife
			&& BonusLife->initWithFile("bonus-life.png")) {
//        BonusLife->setColor(ccGREEN);
		return BonusLife;
	}
	CC_SAFE_DELETE(BonusLife);
	return NULL;
}

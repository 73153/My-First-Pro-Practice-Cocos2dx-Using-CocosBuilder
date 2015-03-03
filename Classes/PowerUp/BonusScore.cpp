
#include "../PowerUp/BonusScore.h"

BonusScore::BonusScore() {
	function = "BonusPoints";
    itemSprite=this;
}

BonusScore::~BonusScore() {
	
}

BonusScore* BonusScore::createBonusScore() {

	BonusScore* bonusScoreSpr = new class BonusScore();
	if (bonusScoreSpr
			&& bonusScoreSpr->initWithFile("bonuspoints.png")) {
//        bonusScoreSpr->setColor(ccYELLOW);
		return bonusScoreSpr;
	}
	CC_SAFE_DELETE(bonusScoreSpr);
	return NULL;
}


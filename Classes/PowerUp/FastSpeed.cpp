

#include "../PowerUp/FastSpeed.h"

FastSpeed::FastSpeed() {
	function = "fastSpeed";
    itemSprite=this;
}

FastSpeed::~FastSpeed() {
}

FastSpeed* FastSpeed::createFastSpeed() {

	FastSpeed* FastSpeed = new class FastSpeed();
	if (FastSpeed
			&& FastSpeed->initWithFile("speed-increase.png")) {
		return FastSpeed;
	}
	CC_SAFE_DELETE(FastSpeed);
	return NULL;
}

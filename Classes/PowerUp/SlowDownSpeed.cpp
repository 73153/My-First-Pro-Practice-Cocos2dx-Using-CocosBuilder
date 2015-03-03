

#include "../PowerUp/SlowDownSpeed.h"

SlowDownSpeed::SlowDownSpeed() {
	function = "slowBallSpeed";
    itemSprite=this;
}

SlowDownSpeed::~SlowDownSpeed() {
}

SlowDownSpeed* SlowDownSpeed::createSlowDownSpeed() {

	SlowDownSpeed* SlowDownSpeed = new class SlowDownSpeed();
	if (SlowDownSpeed
			&& SlowDownSpeed->initWithFile("decreaseSpeed.png")) {
		return SlowDownSpeed;
	}
	CC_SAFE_DELETE(SlowDownSpeed);
	return NULL;
}

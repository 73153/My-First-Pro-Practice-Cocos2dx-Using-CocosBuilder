
#ifndef SlowDownSpeed_H_
#define SlowDownSpeed_H_

#include "../Sprite/Item.h"

class SlowDownSpeed: public Item {
public:
	SlowDownSpeed();
	virtual ~SlowDownSpeed();
	static SlowDownSpeed* createSlowDownSpeed();

};

#endif /* SlowDownSpeed_H_ */

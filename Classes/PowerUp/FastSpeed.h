
#ifndef FastSpeed_H_
#define FastSpeed_H_

#include "../Sprite/Item.h"

class FastSpeed: public Item {
public:
	FastSpeed();
	virtual ~FastSpeed();
	static FastSpeed* createFastSpeed();

};

#endif /* FastSpeed_H_ */

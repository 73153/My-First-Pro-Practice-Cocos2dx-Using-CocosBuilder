

#ifndef MagnetItem_H_
#define MagnetItem_H_

#include "../Sprite/Item.h"

class MagnetItem: public Item {
public:
	MagnetItem();
	virtual ~MagnetItem();
	static MagnetItem* createMagnetItem();
};

#endif /* MagnetItem_H_ */

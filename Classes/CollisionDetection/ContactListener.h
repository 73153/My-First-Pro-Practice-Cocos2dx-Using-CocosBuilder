#ifndef __CONTACT_LISTENER_H__
#define __CONTACT_LISTENER_H__
#include "Box2D/Box2D.h"
#include <vector>
#include "../Ball/Ball.h"
#include "../PowerUp/Bullet.h"

struct ContactHolder
{
public:
	b2Fixture* fixtureA;
	b2Fixture* fixtureB;

	bool operator==(const ContactHolder& other) const
    {
        return (fixtureA == other.fixtureA) && (fixtureB == other.fixtureB);
    }
};

class ContactListener :	public b2ContactListener
{
public:
  
    CC_SYNTHESIZE(bool, isBullet, isBullet);
	ContactListener(void);
	~ContactListener(void);

	virtual void BeginContact( b2Contact* contact );
	virtual void EndContact( b2Contact* contact );

	std::vector<ContactHolder> contacts;
};
#endif

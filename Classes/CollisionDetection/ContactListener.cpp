#include "ContactListener.h"

ContactListener::ContactListener()
{
}
 
ContactListener::~ContactListener()
{
}


void ContactListener::BeginContact( b2Contact* contact )
{
	ContactHolder holder = ContactHolder();
    holder.fixtureA = contact->GetFixtureA();
	holder.fixtureB = contact->GetFixtureB();

//    //check if fixture A was a bullet
//    void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
//    //check if fixture B was a ball
//    void* anotherbodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
//    if ( bodyUserData )
//    {
//        if(static_cast<Bullet*>( bodyUserData )->getTag()==5 && static_cast<Ball*>( anotherbodyUserData )->getTag()==0)
//        {
//            //            static_cast<Bullet*>( bodyUserData )->removeBulletFromParent();
//            CCLog("called contatxxxxxxxxxxx");
//            
//        }
//        else
//        {
//            contacts.push_back(holder);
//            
//        }
//    }
    contacts.push_back(holder);

}

void ContactListener::EndContact( b2Contact* contact )
{
	ContactHolder holder = ContactHolder();
	holder.fixtureA = contact->GetFixtureA();
	holder.fixtureB = contact->GetFixtureB();
	std::vector<ContactHolder>::iterator pos;
	pos = std::find( contacts.begin(), contacts.end(), holder);
	if(pos != contacts.end() )
	{
		contacts.erase(pos);
	}
}


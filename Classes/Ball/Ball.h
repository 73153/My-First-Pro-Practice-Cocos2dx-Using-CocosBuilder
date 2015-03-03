

#ifndef BALL_H_
#define BALL_H_
#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include <cmath>
#define PTM_RATIO 32.0

using namespace cocos2d;

struct Velocity {
	float x;
	float y;
	float speed;

};

class Ball: public CCSprite {
public:
    //The traveling speed of the ball on the horizontal line.
    float velocityX;
    
    //The traveling speed of the ball on the vertical line.
    float velocityY;
    
    //The angle the ball is traveling in.
    float angle;
    
    //The angle in radians the ball is traveling in.
    float angleRad;
    
    //The speed the ball is traveling in ( pixels per update :P ).
    float speed;

    void bouncing(float pAngle);


	Ball();
	virtual ~Ball();
	static Ball* createBall(std::string ballTypeToCreate);
	void createBody(b2World &world);
	b2Body* getBody();
	float getWidth();
	float getHeight();
	float getRadius();
	Velocity getVelocity();
	Velocity setVelocity(Velocity v);
    void verticalBounce(float pAngle);
    void horizontalBounce(float pAngle);
    
    void UnInit(b2World *removeFromWorld);

	b2Body* getBallBody();
    b2Body* getFireBallBody();
    void setFireBallBody(b2Body* ballBody);
	void setBallBody(b2Body* ballBody);
	CCRect rect();
    
    int m_numContacts;
    
    //new implementation for contact state change
    void startContact() { m_numContacts++; }
    void endContact() { m_numContacts--; }

//	void frameAddOne();
	int getPriority();

	void frozenFrameAddOne();
	int getFrozenFrameLasted();
	void setFrozenFrameTo0();

	void skewFrameAddOne();
	int getSkewFrameLasted();
	void setSkewFrameLastedTo0();
    
    void setFrameLastedTo0();
    void frameAddOne();
    int getFrameLasted();
    
    
    enum ballType {
		simpleBall,fireball
	};
    ballType getBallState();
    void setBallState(ballType typeOfBall);
	ballType typeOfBall;

    CCSprite* getBallSprite();
    void setBallSpr(CCSprite *ballSpr);
    
    CCSprite* getFireBallSprite();
    void setFireBallSpr(CCSprite *firedBall);
    void update(b2Body *fireballBodyForMove,CCSprite *fireSpr);
    b2Body *ballBody;
    CCSprite *ballSpr;

private:

	Velocity velocity;
	CCTexture2D ballTexture;
    b2Body *fireBallBody;
    CCSprite *fireBallSpr;
	int frameLasted;
	int frozenFrameLasted;
	int skewFrameLasted;
	int priority;
};

#endif /* BALL_H_ */

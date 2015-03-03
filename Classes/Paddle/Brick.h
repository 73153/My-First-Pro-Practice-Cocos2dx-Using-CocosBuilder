#ifndef __Brick_H__
#define __Brick_H__
#include "Box2D/Box2D.h"
#include "cocos2d.h"

using namespace cocos2d;
class Brick: public cocos2d::CCSprite
{
public:
	Brick(void);
	~Brick(void);
    CC_SYNTHESIZE(int, m_score, Score);
    CC_SYNTHESIZE_READONLY(int, _life, Life);

	void Init(cocos2d::CCLayer* layer, b2World* world,CCSprite *spr,int brickLife);
	void UnInit();

	void Update();
	b2Body* brickBody;
    CCSprite* brickSprites;
    void setBrickSprite(CCSprite* brickSpr);
    CCSprite *getBrickSprite();
    void setColor(CCSprite *spr,int _life);
    b2BodyDef ballBodyDef;
    b2PolygonShape BrickShape;
    b2FixtureDef ballShapeDef;

private:
	
	b2World* m_world;
	cocos2d::CCLayer* m_layer;
};
#endif

#include "../Paddle/Brick.h"
#define PTM_RATIO 32

Brick::Brick(void)
{
	brickBody = NULL;
	brickSprites = NULL;
}


Brick::~Brick(void)
{
}

void Brick::Init(cocos2d::CCLayer* layer, b2World* world,CCSprite *spr,int brickLife)
{
	m_world = world;
	m_layer = layer;
    CCSprite *localbrickSprites = spr;
    int localbrickLife = brickLife;
    if(localbrickLife==1){
        localbrickSprites->setTag(7);
    }
    else if (localbrickLife==2){
        localbrickSprites->setTag(6);
    }
    else if(localbrickLife==3){
        localbrickSprites->setTag(9);
    }
    else{
        localbrickSprites->setTag(5);
    }

	ballBodyDef.type = b2_kinematicBody;
	ballBodyDef.position.Set((localbrickSprites->getPositionX()) / PTM_RATIO,(localbrickSprites->getPositionY() )/ PTM_RATIO);
	ballBodyDef.userData = localbrickSprites;
	brickBody = world->CreateBody( &ballBodyDef );

	BrickShape.SetAsBox( ( localbrickSprites->boundingBox().size.width / 2.0f ) / PTM_RATIO,
		( localbrickSprites->boundingBox().size.height / 2.0f ) / PTM_RATIO );

	ballShapeDef.shape = &BrickShape;
	ballShapeDef.density = 10.0f;
	ballShapeDef.friction = 0.0f;
	ballShapeDef.restitution = 0.1f;
	brickBody->CreateFixture( &ballShapeDef );
    
    brickSprites = localbrickSprites;
}

void Brick::setBrickSprite(cocos2d::CCSprite *brickSpr)
{
//    brickSprites = brickSpr;
}
CCSprite *Brick::getBrickSprite()
{
    return brickSprites;
}

void Brick::UnInit()
{
//	m_layer->removeChild( brickSprites, true );
    if(brickSprites==NULL)
        return;
    brickSprites->removeFromParentAndCleanup(true);
	m_world->DestroyBody(brickBody);
}

void Brick::setColor(CCSprite *spr,int life){
    _life = life;
    switch (_life) {
        case 1:
            //Orange
            //           spr->setColor(ccc3(236,87,44));
            //            spr->setColor(ccc3(210,105,30));
            //            spr->setColor(ccc3(246,142,40));
            break;
        case 2:
            //Red
            //            spr->setColor(ccc3(246,142,40));
            //            spr->setColor(ccc3(235,86,44));
            //              spr->setColor(ccc3(255,255,0));
            
            break;
        case 3:
            //Grey
            //            spr->setColor(ccc3(173 ,173 ,173));
//            spr->setColor(ccc3(172,172,172));
            //             spr->setColor(ccc3(105,105,105));
            
            break;
    }
}

void Brick::Update()
{
	if( brickBody != NULL && brickSprites != NULL )
	{
		brickSprites->setPosition(ccp(brickBody->GetPosition().x * PTM_RATIO,
                                    brickBody->GetPosition().y * PTM_RATIO));
		brickSprites->setRotation(-1 * CC_RADIANS_TO_DEGREES(brickBody->GetAngle()));
	}
}
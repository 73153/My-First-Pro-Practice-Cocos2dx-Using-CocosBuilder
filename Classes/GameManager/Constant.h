
#ifndef BreakingBricks_Cosntant_h
#define BreakingBricks_Cosntant_h


//static int redColorBricks[]  = {15,20,25,30,40,50,20,70,80,107,116,118,125,134,140};

static int maxBulletToFire[] = {0,50,60,70,80,100,150,200,50,60,70,80,100,150,200,50,60,70,80,100,150,200,50,60,70,80,100,150,200,50,60,70,80,100,150,200,50,60,70,80,100,150,200,50,60,70,80,100,150,200,50,60,70,80,100,150,200,50,60,70,80,100,150,200,50,60,70,80,100,150,200,50,60,70,80,100,150,200};

static float bulletSpeed[] = {1.4,1.5,1.6,1.7,1.7,1.8,1.9,1.4,1.5,1.6,1.7,1.7,1.8,1.9,1.4,1.5,1.6,1.7,1.7,1.8,1.9,1.4,1.5,1.6,1.7,1.7,1.8,1.9,1.4,1.5,1.6,1.7,1.7,1.8,1.9,1.4,1.5,1.6,1.7,1.7,1.8,1.9,1.4,1.5,1.6,1.7,1.7,1.8,1.9,1.4,1.5,1.6,1.7,1.7,1.8,1.9};

//static float bulletSpeedAndroid[] = {0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1,1,1,1,1};

static float shapeNotUsed[] = {0,1,2,3,4,5,6,7,15,16,17,18,19,20,21,22,23,24,25,26,27,28,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54};

//static string shapeSprString[] = {"",/*1*/"newshape1.png",/*2*/"newshape2.png",/*3*/"newshape3.png",/*4*/"newshape4.png",/*5*/"newshape5.png",/*6*/"newshape6.png",/*7*/"newshape7.png",/*8*/"newshape8.png",/*9*/"newshape9.png",/*10*/"newshape10.png",/*11*/"newshape11.png",/*12*/"newshape12.png",/*13*/"newshape13.png",/*14*/"newshape14.png",/*15*/"newshape15.png",/*16*/"newshape16.png",/*17*/"newshape17.png",/*18*/"newshape18.png",/*19*/"newshape19.png",/*20*/"newshape20.png",/*21*/"newshape21.png",/*22*/"newshape22.png",/*23*/"newshape23.png",/*24*/"newshape24.png",/*25*/"newshape25.png",/*26*/"newshape26.png",/*27*/"newshape27.png",/*28*/"newshape28.png",/*29*/"newshape29.png",/*30*/"newshape30.png",/*31*/"newshape31.png",/*32*/"newshape32.png",/*33*/"newshape33.png",/*34*/"newshape34.png",/*35*/"newshape35.png",/*36*/"newshape36.png",/*37*/"newshape37.png",/*38*/"newshape38.png",/*39*/"newshape39.png",/*40*/"newshape40.png",/*41*/"newshape41.png",/*42*/"newshape42.png",/*43*/"newshape43.png",/*44*/"newshape44.png",/*45*/"newshape45.png",/*46*/"newshape46.png",/*47*/"newshape47.png",/*48*/"newshape48.png",/*49*/"newshape49.png",/*50*/"newshape50.png",/*51*/"newshape51.png",/*52*/"newshape52.png",/*53*/"newshape53.png",/*54*/"newshape54.png",/*55*/"newshape55.png",/*56*/"newshape56.png"};

static int powerCreateDuration[] = {0,6,6,8,8,10,10,10,10,6,6,8,8,10,10,10,10,6,6,8,8,10,10,10,10,6,6,8,8,10,10,10,10,6,6,8,8,10,10,10,10,6,6,8,8,10,10,10,10,6,6,8,8,10,10,10,10,6,6,8,8,10,10,10,10,6,6,8,8,10,10,10,10,10,10};

static int coinArrivalTime[] = {0,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,15,20,20,20,24,24,15,15,20,20,20,24,24,15,15,20,20,20,24,24,15,15,20,20,20,24,24,15,15,20,20,20,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24};

static std::string ballType = "ball.png";
static std::string paddleName = "myPaddle.png";
static std::string longPaddleType = "myLongPaddle.png";
static std::string shortPaddleType = "myShortPaddle.png";


static std::string paddleNameNight = "myPaddleNight.png";
static std::string longPaddleTypeNight = "myLongPaddleNight.png";
static std::string shortPaddleTypeNight = "myShortPaddleNight.png";


static CCSize globleWinSize = CCDirector::sharedDirector()->getWinSize();



static void brickExplodeAtPos(CCPoint brickPos, CCLayer *brikLyr,std::string typeOfParticle,int controlMode)
{
    int localControlMode = controlMode;
    if(SettingLayer::getControlMode()==0)
        localControlMode=0;
    if(localControlMode==0)
    {
        CCParticleSun* explosion = CCParticleSun::createWithTotalParticles(300);
        explosion->setAutoRemoveOnFinish(true);
        explosion->setStartSize(10.0f);
        explosion->setSpeed(70.0f);
        explosion->setAnchorPoint(ccp(0.5f,0.5f));
        explosion->setPosition(brickPos);
        explosion->setDuration(0.5f);
        brikLyr->addChild(explosion,11);
    }
    else{
        CCParticleSystemQuad *explosion = CCParticleSystemQuad::create(typeOfParticle.c_str());
        explosion->setPosition(brickPos);
        explosion->setAutoRemoveOnFinish(true);
        brikLyr->addChild(explosion,10);
    }
}

static CCSprite *rightBulletAtPos(CCPoint myPaddleCurrent,CCLayer *brikLayer,std::string typeOfParticle,CCSize windowSize,int paddleLength,TargetPlatform detectedPlatform,int deviceResolution)
{
    CCSize winsiZe = windowSize;
    int paddleLengthInt = paddleLength;
    CCPoint myPaddleCurrentPos = myPaddleCurrent;
    CCLayer *brikLyer = brikLayer;
    std::string particleType =typeOfParticle;
    
    CCSprite *rightBulletSpr = CCSprite::create(particleType.c_str());
    
    switch (deviceResolution)
    {
        case 1:
            if (1 ==paddleLengthInt) {
                rightBulletSpr->setPosition(ccp(myPaddleCurrentPos.x+220, myPaddleCurrentPos.y+20));
            } else if (2 ==paddleLengthInt) {
                rightBulletSpr->setPosition(ccp(myPaddleCurrentPos.x+280, myPaddleCurrentPos.y+20));
            }
            else{
                rightBulletSpr->setPosition(ccp(myPaddleCurrentPos.x+170, myPaddleCurrentPos.y+20));
            }
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136)
            {
                if (1 == paddleLengthInt) {
                    rightBulletSpr->setPosition(ccp(((myPaddleCurrentPos.x+120)), myPaddleCurrentPos.y+20));
                } else if (2 == paddleLengthInt) {
                    rightBulletSpr->setPosition(ccp((myPaddleCurrentPos.x+154), myPaddleCurrentPos.y+20));
                }
                else{
                    rightBulletSpr->setPosition(ccp((myPaddleCurrentPos.x+94), myPaddleCurrentPos.y+20));
                }
            }
            else
            {
                if (1 == paddleLengthInt) {
                    rightBulletSpr->setPosition(ccp(((myPaddleCurrentPos.x+120)), myPaddleCurrentPos.y+20));
                } else if (2 == paddleLengthInt) {
                    rightBulletSpr->setPosition(ccp((myPaddleCurrentPos.x+154), myPaddleCurrentPos.y+20));
                }
                else{
                    rightBulletSpr->setPosition(ccp((myPaddleCurrentPos.x+94), myPaddleCurrentPos.y+20));
                }
            }
        }
            break;
        case 3:
            if (1 == paddleLengthInt) {
                rightBulletSpr->setPosition(ccp(((myPaddleCurrentPos.x+110)), myPaddleCurrentPos.y+20));
            } else if (2 == paddleLengthInt) {
                rightBulletSpr->setPosition(ccp((myPaddleCurrentPos.x+138), myPaddleCurrentPos.y+20));
            }
            else{
                rightBulletSpr->setPosition(ccp((myPaddleCurrentPos.x+84), myPaddleCurrentPos.y+20));
            }
            break;
        case 4:
            if (1 == paddleLengthInt) {
                rightBulletSpr->setPosition(ccp(((myPaddleCurrentPos.x+100)), myPaddleCurrentPos.y+20));
            } else if (2 == paddleLengthInt) {
                rightBulletSpr->setPosition(ccp((myPaddleCurrentPos.x+138), myPaddleCurrentPos.y+20));
            }
            else{
                rightBulletSpr->setPosition(ccp((myPaddleCurrentPos.x+84), myPaddleCurrentPos.y+20));
            }
            break;
        case 5:
            
            if (1 == paddleLengthInt) {
                rightBulletSpr->setPosition(ccp(myPaddleCurrentPos.x+112, myPaddleCurrentPos.y+20));
            } else if (2 == paddleLengthInt) {
                rightBulletSpr->setPosition(ccp(myPaddleCurrentPos.x+142, myPaddleCurrentPos.y+20));
            }
            else{
                rightBulletSpr->setPosition(ccp(myPaddleCurrentPos.x+90, myPaddleCurrentPos.y+20));
            }
            
            break;
        case 6:
            if (1 == paddleLengthInt) {
                rightBulletSpr->setPosition(ccp(myPaddleCurrentPos.x+235, myPaddleCurrentPos.y+20));
            } else if (2 == paddleLengthInt) {
                rightBulletSpr->setPosition(ccp(myPaddleCurrentPos.x+290, myPaddleCurrentPos.y+20));
            }
            else{
                rightBulletSpr->setPosition(ccp(myPaddleCurrentPos.x+190, myPaddleCurrentPos.y+20));
            }
            break;
            
        default:
            break;
    }
    brikLyer->addChild(rightBulletSpr);
    return rightBulletSpr;
}
static CCSprite *leftBulletAtPos(CCPoint myPaddleCurrent,CCLayer *brikLayer,std::string bulletStr,CCSize windowSize,int paddleLength,TargetPlatform detectedPlatform,int deviceResolution)
{
    CCSize winsiZe = windowSize;
    int paddleLengthInt = paddleLength;
    CCPoint myPaddleCurrentPos = myPaddleCurrent;
    CCLayer *brikLyer = brikLayer;
    std::string leftBulletStrType =bulletStr;
    
    CCSprite *leftBulletSpr = CCSprite::create(leftBulletStrType.c_str());
    switch (deviceResolution)
    {
        case 1:
            if (1 == paddleLengthInt) {
                leftBulletSpr->setPosition(ccp(myPaddleCurrentPos.x-220, myPaddleCurrentPos.y+20));
            } else if (2 == paddleLengthInt) {
                leftBulletSpr->setPosition(ccp(myPaddleCurrentPos.x-280, myPaddleCurrentPos.y+20));
            }
            else{
                leftBulletSpr->setPosition(ccp(myPaddleCurrentPos.x-170, myPaddleCurrentPos.y+20));
            }
            
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136)
            {
                if (1 == paddleLengthInt) {
                    leftBulletSpr->setPosition(ccp(((myPaddleCurrentPos.x-120)), myPaddleCurrentPos.y+20));
                } else if (2 == paddleLengthInt) {
                    leftBulletSpr->setPosition(ccp((myPaddleCurrentPos.x-154), myPaddleCurrentPos.y+20));
                }
                else{
                    leftBulletSpr->setPosition(ccp((myPaddleCurrentPos.x-94), myPaddleCurrentPos.y+20));
                }
            }
            else
            {
                
                if (1 == paddleLengthInt) {
                    leftBulletSpr->setPosition(ccp(((myPaddleCurrentPos.x-120)), myPaddleCurrentPos.y+20));
                } else if (2 == paddleLengthInt) {
                    leftBulletSpr->setPosition(ccp((myPaddleCurrentPos.x-154), myPaddleCurrentPos.y+20));
                }
                else{
                    leftBulletSpr->setPosition(ccp((myPaddleCurrentPos.x-94), myPaddleCurrentPos.y+20));
                }
                
            }
        }
            break;
        case 3:
            if (1 == paddleLengthInt) {
                leftBulletSpr->setPosition(ccp(((myPaddleCurrentPos.x-110)), myPaddleCurrentPos.y+20));
            } else if (2 == paddleLengthInt) {
                leftBulletSpr->setPosition(ccp((myPaddleCurrentPos.x-138), myPaddleCurrentPos.y+20));
            }
            else{
                leftBulletSpr->setPosition(ccp((myPaddleCurrentPos.x-84), myPaddleCurrentPos.y+20));
            }
            break;
        case 4:
            if (1 == paddleLengthInt) {
                leftBulletSpr->setPosition(ccp(((myPaddleCurrentPos.x-100)), myPaddleCurrentPos.y+20));
            } else if (2 == paddleLengthInt) {
                leftBulletSpr->setPosition(ccp((myPaddleCurrentPos.x-138), myPaddleCurrentPos.y+20));
            }
            else{
                leftBulletSpr->setPosition(ccp((myPaddleCurrentPos.x-84), myPaddleCurrentPos.y+20));
            }
            break;
        case 5:
            if (1 == paddleLengthInt) {
                leftBulletSpr->setPosition(ccp(myPaddleCurrentPos.x-115, myPaddleCurrentPos.y+20));
            } else if (2 == paddleLengthInt) {
                leftBulletSpr->setPosition(ccp(myPaddleCurrentPos.x-145, myPaddleCurrentPos.y+20));
            }
            else{
                leftBulletSpr->setPosition(ccp(myPaddleCurrentPos.x-90, myPaddleCurrentPos.y+20));
            }
            break;
        case 6:
            if (1 == paddleLengthInt) {
                leftBulletSpr->setPosition(ccp(myPaddleCurrentPos.x-235, myPaddleCurrentPos.y+20));
            } else if (2 == paddleLengthInt) {
                leftBulletSpr->setPosition(ccp(myPaddleCurrentPos.x-290, myPaddleCurrentPos.y+20));
            }
            else{
                leftBulletSpr->setPosition(ccp(myPaddleCurrentPos.x-190, myPaddleCurrentPos.y+20));
            }
            break;
            
        default:
            break;
    }
    
    brikLyer->addChild(leftBulletSpr);
    
    return leftBulletSpr;
}

static void saveToStdUserDefaults(cocos2d::CCString *arg, cocos2d::CCString *myString)
{
    CCLOG("arg %s and myString %s",arg->getCString(),myString->getCString());
    CCUserDefault * standardUserDefaults = CCUserDefault::sharedUserDefault();
    
    if (standardUserDefaults)
    {
        standardUserDefaults->setStringForKey(myString->getCString(), arg->getCString());
    }
}
static CCSprite *myPaddleImageArcadeMode(CCSprite*mypaddleSpr,bool isAddedGun, int paddleLenthState,bool nightOrDayModeToPlay)
{
    if(nightOrDayModeToPlay==true)
    {
        if (paddleLenthState == 0) {
            mypaddleSpr->setDisplayFrame(CCSpriteFrame::create("myShortPaddleNight.png",shortPaddleSprArcadeMode->getTextureRect()));
        }
        else if (paddleLenthState == 1) {
            mypaddleSpr->setDisplayFrame(CCSpriteFrame::create("myPaddleNight.png",normalPaddleSprArcadeMode->getTextureRect()));
        }
        else if(paddleLenthState == 2){
            mypaddleSpr->setDisplayFrame(CCSpriteFrame::create("myLongPaddleNight.png",longPaddleSprArcadeMode->getTextureRect()));
        }
    }
    else
    {
        if (paddleLenthState == 0) {
            CCSprite *spr = (CCSprite*)shortPaddleSpr;
            mypaddleSpr->setDisplayFrame(CCSpriteFrame::create("myShortPaddle.png",spr->getTextureRect()));
        }
        else if (paddleLenthState == 1) {
            CCSprite *spr = (CCSprite*)normalPaddleSpr;
            mypaddleSpr->setDisplayFrame(CCSpriteFrame::create("myPaddle.png",spr->getTextureRect()));
        }
        else if(paddleLenthState == 2){
            CCSprite *spr = (CCSprite*)longPaddleSpr;
            mypaddleSpr->setDisplayFrame(CCSpriteFrame::create("myLongPaddle.png",spr->getTextureRect()));
        }
    }
    
    return mypaddleSpr;
}

static CCSprite *myPaddleImage(CCSprite*mypaddleSpr,bool isAddedGun, int controlMode,bool modeToPlay)
{
    if( modeToPlay==true)
    {
        if(isAddedGun==true)
        {
            if (controlMode == 0) {
                CCSprite *spr = (CCSprite*)shortPaddleSpr;
                mypaddleSpr->setDisplayFrame(CCSpriteFrame::create("myShortBulletPaddleNight.png",spr->getTextureRect()));
            }
            else if (controlMode == 1) {
                CCSprite *spr = (CCSprite*)normalPaddleSpr;
                mypaddleSpr->setDisplayFrame(CCSpriteFrame::create("myBulletPaddleNight.png",spr->getTextureRect()));
            }
            else if(controlMode == 2){
                CCSprite *spr = (CCSprite*)longPaddleSpr;
                mypaddleSpr->setDisplayFrame(CCSpriteFrame::create("myLongBulletPaddleNight.png",spr->getTextureRect()));
            }
        }
        else
        {
            if (controlMode == 0) {
                CCSprite *spr = (CCSprite*)shortPaddleSpr;
                mypaddleSpr->setDisplayFrame(CCSpriteFrame::create("myShortPaddleNight.png",spr->getTextureRect()));
            }
            else if (controlMode == 1) {
                CCSprite *spr = (CCSprite*)normalPaddleSpr;
                mypaddleSpr->setDisplayFrame(CCSpriteFrame::create("myPaddleNight.png",spr->getTextureRect()));
            }
            else if(controlMode == 2){
                CCSprite *spr = (CCSprite*)longPaddleSpr;
                mypaddleSpr->setDisplayFrame(CCSpriteFrame::create("myLongPaddleNight.png",spr->getTextureRect()));
            }
        }
    }
    else
    {
        if(isAddedGun==true)
        {
            if (controlMode == 0) {
                CCSprite *spr = (CCSprite*)shortPaddleSpr;
                mypaddleSpr->setDisplayFrame(CCSpriteFrame::create("myShortBulletPaddle.png",spr->getTextureRect()));
            }
            else if (controlMode == 1) {
                CCSprite *spr = (CCSprite*)normalPaddleSpr;
                
                mypaddleSpr->setDisplayFrame(CCSpriteFrame::create("myBulletPaddle.png",spr->getTextureRect()));
            }
            else if(controlMode == 2){
                CCSprite *spr = (CCSprite*)longPaddleSpr;
                
                mypaddleSpr->setDisplayFrame(CCSpriteFrame::create("myLongBulletPaddle.png",spr->getTextureRect()));
            }
        }
        else
        {
            if (controlMode == 0) {
                CCSprite *spr = (CCSprite*)shortPaddleSpr;
                mypaddleSpr->setDisplayFrame(CCSpriteFrame::create("myShortPaddle.png",spr->getTextureRect()));
            }
            else if (controlMode == 1) {
                CCSprite *spr = (CCSprite*)normalPaddleSpr;
                mypaddleSpr->setDisplayFrame(CCSpriteFrame::create("myPaddle.png",spr->getTextureRect()));
            }
            else if(controlMode == 2){
                CCSprite *spr = (CCSprite*)longPaddleSpr;
                mypaddleSpr->setDisplayFrame(CCSpriteFrame::create("myLongPaddle.png",spr->getTextureRect()));
            }
        }
        
    }
    return mypaddleSpr;
}



//static CCSprite *myPaddleImageArcadeMode(CCSprite*mypaddleSpr,bool isAddedGun, int paddleLenthState,bool nightOrDayModeToPlay,int resolution)
//{
//    //    if(resolution==1 || resolution==6)
//    //    {
//    //        if(isAddedGun==true)
//    //        {
//    //            if (paddleLenthState == 0) {
//    //                mypaddleSpr->setTexture(CCTextureCache::sharedTextureCache()->addImage("myShortBulletPaddleNight.png"));
//    //            }
//    //            else if (paddleLenthState == 1) {
//    //                mypaddleSpr->setTexture(CCTextureCache::sharedTextureCache()->addImage("myBulletPaddleNight.png"));
//    //            }
//    //            else if(paddleLenthState == 2){
//    //                mypaddleSpr->setTexture(CCTextureCache::sharedTextureCache()->addImage("myLongBulletPaddleNight.png"));
//    //            }
//    //        }
//    //        else if ( isAddedGun==false)
//    //        {
//    if (paddleLenthState == 0) {
//        mypaddleSpr->setTexture(CCTextureCache::sharedTextureCache()->addImage("myShortPaddleNight.png"));
//
//    }
//    else if (paddleLenthState == 1) {
//        mypaddleSpr->setTexture(CCTextureCache::sharedTextureCache()->addImage("myPaddleNight.png"));
//
//    }
//    else if(paddleLenthState == 2){
//        mypaddleSpr->setTexture(CCTextureCache::sharedTextureCache()->addImage("myLongPaddleNight.png"));
//
//    }
//    //        }
//    //    }
//    //    else
//    //    {
//    //        if(isAddedGun==true)
//    //        {
//    //            if (paddleLenthState == 0) {
//    //                mypaddleSpr->setTexture(CCTextureCache::sharedTextureCache()->addImage("myShortBulletPaddleNight.png"));
//    //
//    //            }
//    //            else if (paddleLenthState == 1) {
//    //                mypaddleSpr->setTexture(CCTextureCache::sharedTextureCache()->addImage("myBulletPaddleNight.png"));
//    //            }
//    //            else if(paddleLenthState == 2){
//    //                mypaddleSpr->setTexture(CCTextureCache::sharedTextureCache()->addImage("myLongBulletPaddleNight.png"));
//    //
//    //            }
//    //        }
//    //        else if ( isAddedGun==false)
//    //        {
//    //            if (paddleLenthState == 0) {
//    //                mypaddleSpr->setTexture(CCTextureCache::sharedTextureCache()->addImage("myShortPaddleNight.png"));
//    //            }
//    //            else if (paddleLenthState == 1) {
//    //                mypaddleSpr->setTexture(CCTextureCache::sharedTextureCache()->addImage("myPaddleNight.png"));
//    //            }
//    //            else if(paddleLenthState == 2){
//    //                mypaddleSpr->setTexture(CCTextureCache::sharedTextureCache()->addImage("myLongPaddleNight.png"));
//    //            }
//    //        }
//    //    }
//    return mypaddleSpr;
//}
//
//static CCSprite *myPaddleImage(CCSprite*mypaddleSpr,bool isAddedGun, int controlMode,bool modeToPlay,int resolution)
//{
//    if( modeToPlay==true)
//    {
//
//        if(isAddedGun==true)
//        {
//            if (controlMode == 0) {
//                mypaddleSpr->setTexture(CCTextureCache::sharedTextureCache()->addImage("myShortBulletPaddleNight.png"));
//            }
//            else if (controlMode == 1) {
//                mypaddleSpr->setTexture(CCTextureCache::sharedTextureCache()->addImage("myBulletPaddleNight.png"));
//            }
//            else if(controlMode == 2){
//                mypaddleSpr->setTexture(CCTextureCache::sharedTextureCache()->addImage("myLongBulletPaddleNight.png"));
//            }
//        }
//        else if ( isAddedGun==false)
//        {
//            if (controlMode == 0) {
//                mypaddleSpr->setTexture(CCTextureCache::sharedTextureCache()->addImage("myShortPaddleNight.png"));
//
//            }
//            else if (controlMode == 1) {
//                mypaddleSpr->setTexture(CCTextureCache::sharedTextureCache()->addImage("myPaddleNight.png"));
//
//            }
//            else if(controlMode == 2){
//                mypaddleSpr->setTexture(CCTextureCache::sharedTextureCache()->addImage("myLongPaddleNight.png"));
//
//            }
//        }
//    }
//    else
//    {
//        if(isAddedGun==true)
//        {
//            if (controlMode == 0) {
//                mypaddleSpr->setTexture(CCTextureCache::sharedTextureCache()->addImage("myShortBulletPaddle.png"));
//            }
//            else if (controlMode == 1) {
//                mypaddleSpr->setTexture(CCTextureCache::sharedTextureCache()->addImage("myBulletPaddle.png"));
//
//            }
//            else if(controlMode == 2){
//                mypaddleSpr->setTexture(CCTextureCache::sharedTextureCache()->addImage("myLongBulletPaddle.png"));
//
//            }
//        }
//        else if ( isAddedGun==false)
//        {
//            if (controlMode == 0) {
//                mypaddleSpr->setTexture(CCTextureCache::sharedTextureCache()->addImage("myShortPaddle.png"));
//
//            }
//            else if (controlMode == 1) {
//                mypaddleSpr->setTexture(CCTextureCache::sharedTextureCache()->addImage("myPaddle.png"));
//            }
//            else if(controlMode == 2){
//                mypaddleSpr->setTexture(CCTextureCache::sharedTextureCache()->addImage("myLongPaddle.png"));
//
//            }
//        }
//
//    }
//    return mypaddleSpr;
//}

static CCString *retrieveFromStdUserDefaults(cocos2d::CCString *arg)
{
    CCUserDefault* standardUserDefaults= CCUserDefault::sharedUserDefault();
    CCString* val = NULL;
    
    if (standardUserDefaults)
    {
        val = CCString::create(CCUserDefault::sharedUserDefault()->getStringForKey(arg->getCString()));
    }
    return val;
}

static void changeAnimationLableContent(string lblContent,CCLabelTTF *labelChange,CCPoint paddlePos)
{
    
    CCLabelTTF *animateLbl = (CCLabelTTF*)labelChange;
    animateLbl->setOpacity(255);
    animateLbl->setColor(ccc3(236,86,44));
    animateLbl->setString(lblContent.c_str());
    animateLbl->setPosition(paddlePos);
    animateLbl->runAction(CCMoveTo::create(1.5f, ccp(paddlePos.x,300)));
    animateLbl->runAction(CCFadeTo::create(1.5f,0));
}
static void mileStoneCompletedDisplay(int currentLevel,CCLabelTTF *labelChangeMileStone)
{
    CCLabelTTF *animateLbl = (CCLabelTTF*)labelChangeMileStone;
    animateLbl->setVisible(true);
    animateLbl->setOpacity(255);
    labelChangeMileStone->setString("Great you have achieved MileStone");
   /* switch (currentLevel) {
        case 1:
            labelChangeMileStone->setString("Great you have achieved MileStone One");
            break;
        case 2:
            labelChangeMileStone->setString("Great you have achieved MileStone Two");
            break;
        case 3:
            labelChangeMileStone->setString("Great you have achieved MileStone Three");
            break;
        case 4:
            labelChangeMileStone->setString("Great you have achieved MileStone Four");
            break;
        case 5:
            labelChangeMileStone->setString("Great you have achieved MileStone Five");
            break;
        case 6:
            labelChangeMileStone->setString("Great you have achieved MileStone Six");
            break;
        case 7:
            labelChangeMileStone->setString("Great you have achieved MileStone Seven");
            break;
        case 8:
            labelChangeMileStone->setString("Great you have achieved MileStone Eight");
            break;
        case 9:
            labelChangeMileStone->setString("Great you have achieved MileStone Nine");
            break;
        case 10:
            labelChangeMileStone->setString("Great you have achieved MileStone Ten");
            break;
        case 11:
            labelChangeMileStone->setString("Great you have achieved MileStone Eleven");
            break;
        case 12:
            labelChangeMileStone->setString("Great you have achieved MileStone Twelve");
            break;
        case 13:
            labelChangeMileStone->setString("Great you have achieved MileStone Thirteen");
            break;
        case 14:
            labelChangeMileStone->setString("Great you have achieved MileStone Fourteen");
            break;
        case 15:
            labelChangeMileStone->setString("Great you have achieved MileStone Fifteen");
            break;
        case 16:
            labelChangeMileStone->setString("Great you have achieved MileStone Sixteen");
            break;
        case 17:
            labelChangeMileStone->setString("Great you have achieved MileStone Seventeen");
            break;
        case 18:
            labelChangeMileStone->setString("Great you have achieved MileStone Eighteen");
            break;
        case 19:
            labelChangeMileStone->setString("Great you have achieved MileStone Nineteen");
            break;
        case 20:
            labelChangeMileStone->setString("Great you have achieved MileStone Twenty");
            break;
        case 21:
            labelChangeMileStone->setString("Great you have achieved MileStone Twenty One");
        case 22:
            labelChangeMileStone->setString("Great you have achieved MileStone Twenty Two");
            break;
        case 23:
            labelChangeMileStone->setString("Great you have achieved MileStone Twenty Three");
        case 24:
            labelChangeMileStone->setString("Great you have achieved MileStone Twenty Four");
            break;
        case 25:
            labelChangeMileStone->setString("Great you have achieved MileStone Twenty Five");
        case 26:
            labelChangeMileStone->setString("Great you have achieved MileStone Twenty Six");
            break;
        case 27:
            labelChangeMileStone->setString("Great you have achieved MileStone Twenty Seven");
        case 28:
            labelChangeMileStone->setString("Great you have achieved MileStone Twenty Eight");
            break;
        case 29:
            labelChangeMileStone->setString("Great you have achieved MileStone Twenty Nine");
        case 30:
            labelChangeMileStone->setString("Great you have achieved MileStone Thirty");
            break;
        case 31:
            labelChangeMileStone->setString("Great you have achieved MileStone Thirty One");
        case 32:
            labelChangeMileStone->setString("Great you have achieved MileStone Thirty Two");
            break;
        case 33:
            labelChangeMileStone->setString("Great you have achieved MileStone Thirty Three");
            break;
            
        default:
            break;
    }*/
}


static void changeViewAndLabelContentAndColoronGameOver(int currentLevel,CCLabelTTF *labelChange,bool modeOfPlay)
{
    CCLabelTTF *animateLbl = (CCLabelTTF*)labelChange;
    animateLbl->setVisible(true);
    animateLbl->setOpacity(255);
    switch (arc4random()%26) {
        case 0:
            animateLbl->setString("Winners never quit, and quitters never win");
            break;
        case 1:
            animateLbl->setString("It's always too early to quit");
            break;
        case 2:
            animateLbl->setString("You have a winner’s attitude, let try one's more");
            break;
        case 3:
            animateLbl->setString("If you think you can do it, you can");
            break;
        case 4:
            animateLbl->setString("You have to make it happen");
            break;
        case 5:
            animateLbl->setString("Your attitude and work will suits at eack level");
            break;
        case 6:
            animateLbl->setString("It's Not Over yet!");
            break;
        case 7:
            animateLbl->setString("Belive in Yourself! Never Quit");
            break;
        case 8:
            animateLbl->setString("Failure Only Happens When you Give up trying");
            break;
        case 9:
            animateLbl->setString("Yo! Champ in the making!");
            break;
        case 10:
            animateLbl->setString("Always dream, Never give up!");
            break;
        case 11:
            animateLbl->setString("Only those who try will become Champ");
            break;
        case 12:
            animateLbl->setString("If you quit once it becomes habit, Never Quit");
            break;
        case 13:
            animateLbl->setString("I am not afraid...I was born to do this");
            break;
        case 14:
            animateLbl->setString("Your attention will put you at the top!");
            break;
        case 15:
            animateLbl->setString("Don't give up just because things are hard!");
            break;
        case 16:
            animateLbl->setString("You're Never a loser until you quit trying!");
            break;
        case 17:
            animateLbl->setString("Always remember your destiny is in your own hands!");
            break;
        case 18:
            animateLbl->setString("We have to keep our dreams alive!");
            break;
        case 19:
            animateLbl->setString("Our greatest weakness lies in giving up!");
            break;
        case 20:
            animateLbl->setString("To get succeed is always to try just one more time!");
            break;
        case 21:
            animateLbl->setString("To get succeed, We must first believe that we can");
            break;
        case 22:
            animateLbl->setString("Well done is better than well said");
            break;
        case 23:
            animateLbl->setString("The harder the conflict, the more glorious the triumph");
            break;
        case 24:
            animateLbl->setString("You just can't beat the person who never gives up");
            break;
        case 25:
            animateLbl->setString("Courage is the magic that turns dreams into reality");
            break;
        case 26:
            animateLbl->setString("Your victory is right around the corner. Never give up");
            break;
        case 27:
            animateLbl->setString("Never give up, have the passion. Don't be afraid");
            break;
        default:
            break;
    }
}

static void changeViewAndLabelContentAndColoronGameWon(int currentLevel,CCLabelTTF *animateLbl,bool modeOfPlay)
{
    animateLbl->setVisible(true);
    int levelTemp = currentLevel;
    
    if (levelTemp>8 && levelTemp<17){
        levelTemp=levelTemp-8;
    }
    
    if (levelTemp>=17 && levelTemp<25){
        levelTemp=levelTemp-16;
    }
    
    if (levelTemp>=25 && levelTemp<33){
        levelTemp=levelTemp-24;
    }
    
    if (levelTemp>=33 && levelTemp<41){
        levelTemp=levelTemp-32;
    }
    
    if (levelTemp>=41 && levelTemp<49){
        levelTemp=levelTemp-40;}
    
    if (levelTemp>=49 &&levelTemp<57){
        levelTemp=levelTemp-48;
    }
    
    switch (levelTemp) {
        case 1:
            switch (arc4random()%6) {
                case 0:
                    animateLbl->setString("Yippee!");
                    break;
                case 1:
                    animateLbl->setString("That's the way!");
                    break;
                case 2:
                    animateLbl->setString("Great Job!");
                    break;
                case 3:
                    animateLbl->setString("You Rock!");
                    break;
                case 4:
                    animateLbl->setString("Good one mate!");
                    break;
                case 5:
                    animateLbl->setString("Cheers!");
                    break;
                    
                default:
                    break;
            }
            
            break;
        case 2:
            switch (arc4random()%5) {
                case 0:
                    animateLbl->setString("Nice going! ");
                    break;
                case 1:
                    animateLbl->setString("Fantastic!");
                    break;
                case 2:
                    animateLbl->setString("Wonderful!");
                    break;
                case 3:
                    animateLbl->setString("You've got it!");
                    break;
                case 4:
                    animateLbl->setString("Bravo!");
                    break;
            }
            break;
        case 3:
            switch (arc4random()%6) {
                case 0:
                    animateLbl->setString("Hooray!");
                    break;
                case 1:
                    animateLbl->setString("Commendations!");
                    break;
                case 2:
                    animateLbl->setString("Impressive!");
                    break;
                case 3:
                    animateLbl->setString("Congrats!");
                    break;
                case 4:
                    animateLbl->setString("Spectacular Show!");
                    break;
                case 5:
                    animateLbl->setString("Amazing play!");
                    break;
                    
            }
            break;
        case 4:
            switch (arc4random()%6) {
                case 0:
                    animateLbl->setString("Hats off!");
                    break;
                case 1:
                    animateLbl->setString("You rule!");
                    break;
                case 2:animateLbl->setString("Way to go! ");
                    break;
                case 3:animateLbl->setString("Good show! ");
                    break;
                case 4:animateLbl->setString("Awesome!");
                    break;
                case 5: animateLbl->setString("Superb!");
                    break;
            }
            
            break;
        case 5:
            switch (arc4random()%6) {
                case 0:animateLbl->setString("Well deserved!");
                    break;
                case 1:animateLbl->setString("Excellent job!");
                    break;
                case 2:animateLbl->setString("Take a bow!");
                    break;
                case 3:animateLbl->setString("Stunning Show!");
                    break;
                case 4:animateLbl->setString("Remarkable Work!");
                    break;
                case 5:animateLbl->setString("Excellent Performance!");
                    
                    break;
            }
            break;
        case 6:
            switch (arc4random()%6) {
                case 0:animateLbl->setString("Bravo!");
                    
                    break;
                case 1:animateLbl->setString("Sensational!");
                    
                    break;
                case 2:animateLbl->setString("Breathtaking Feat!");
                    
                    break;
                case 3:animateLbl->setString("Glorious Show!");
                    
                    break;
                case 4:animateLbl->setString("Outstanding!");
                    
                    break;
                case 5: animateLbl->setString("You're Great!");
                    
                    break;
                    
            }
            break;
        case 7:
            switch (arc4random()%6) {
                case 0:animateLbl->setString("Marvellous Performance!");
                    
                    break;
                case 1:animateLbl->setString("You are a genius!");
                    
                    break;
                case 2: animateLbl->setString("Exceptional Feat!");
                    
                    break;
                case 3:animateLbl->setString("Magnificent!");
                    
                    break;
                case 4:animateLbl->setString("You're the best!");
                    
                    break;
                case 5:animateLbl->setString("Congratulations Champion!");
                    
                    break;
            }
            break;
        default:
            break;
    }
}


static void changePowerCounter(string powerCounter,CCLabelTTF *powerCountDownLabel,int modeOfPlay)
{
    CCLabelTTF *powerLabel = (CCLabelTTF*)powerCountDownLabel;
    powerLabel->setVisible(true);
    
    powerLabel->setOpacity(255);
    if(modeOfPlay==true){
        powerLabel->setColor(ccWHITE);
    }
    else{
        powerLabel->setColor(ccWHITE);
        
    }
    powerLabel->setFontSize(150);
    powerCountDownLabel->setString(powerCounter.c_str());
    powerLabel->runAction(CCFadeTo::create(1.0f,0));
}


static void changeCountingLableContent(string lblContent,CCLabelTTF *labelChange,CCPoint paddlePos)
{
    labelChange->setOpacity(255);
    //    animateLbl->setColor(ccc3(0,0,255));
    //    labelChange->setColor(ccc3(236,86,44));
    labelChange->setFontSize(300);
    if(lblContent=="GO")
        labelChange->setFontSize(200);
    
    labelChange->setString(lblContent.c_str());
    labelChange->setPosition(paddlePos);
    labelChange->runAction(CCFadeTo::create(1.0f,0));
}





#endif

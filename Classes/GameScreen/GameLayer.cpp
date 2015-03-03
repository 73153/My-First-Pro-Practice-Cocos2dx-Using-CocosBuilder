#include "../GameScreen/GameLayer.h"
#include "SimpleAudioEngine.h"
#include "../GameManager/GameManager.h"
#include "../GameManager/Constant.h"
#include "../Layers/MenuLayer.h"
#include "../Layers/MenuLayerLoader.h"
#include "../GameScreen/GameLayerLoader.h"
#include "../CCValue/CCValue.h"
#include "../GameScreen/StrokeTool.h"
#include "../GameManager/Constant.h"
#include "../SoundManager/SoundManager.h"
#include "HoldOnModel.h"
using namespace cocos2d;
using namespace CocosDenshion;
using namespace std;


Ball* GameLayer::ball;
Ball* GameLayer::fireBall;
Bullet* GameLayer::bulletFired;
MyPaddle* GameLayer::myPaddle;

GameLayer::GameLayer():mAnimationManager(NULL),_mouseJoint(NULL),world(NULL),hardBricks(NULL),m_Bricks(NULL),groundBody(NULL),bottomFixture(NULL),ballFixture(NULL),myPaddleFixture(NULL),itemList(NULL),ballList(NULL),m_pFireEmitter(NULL),navigationLayer(NULL),shapeSpr(NULL),backGroundSpr(NULL),animationLayerObj(NULL),isAddGun(false),isTouchedOnPlayerPaddle(false),paddleLayer(NULL),isPaddleCreatedNotFirstTime(false),gameIsPaused(false),gameIsEnded(false),isSlowDownSpeed(false),isAllBricksRemoved(false),isPlayerLifeZero(false),animationLable(NULL),shapeBackLayer(NULL),countingLable(NULL),isGameEnded(false),isDestroyedGameOverPaddle(false),isCallOnce(false),isgameover(false),isContingEnded(false),isAutoPlayModeActive(false),autostrip(NULL),isBallRecreated(false),isGameStarted(false),coinAnimateArray(NULL),globalPlayerLifeCountLabel(NULL),isTouchedOnPaddlefront(false),isMagnetEnabled(false),isCoinToGenerate(false),isballHitPaddleInMagnet(false),isBallRecreatedAndTouched(false),isReleaseBall(false),isBallDownToPaddlePos(false),kachcheLabel(NULL),isSpeedMax(false),powerCountLabel(NULL),isMultiBallCreated(false),isPaddleTimerEnable(false),stageSpr(NULL),scoreSpr(NULL),ballTopSpr(NULL),coinSpr(NULL),coinLabel(NULL),isInstructionLabelVisible(true),isNavigationLayerAllObjectGotInitialised(false),isBlackColorBackground(NULL),isPowerMultiBallVisible(false),kachcheLabelGameWon(NULL),instructionLabel(NULL),isMagnetRepeat(false),isMagnetAndMultiBallEnable(false)
{
    brickPoints=0;counterForPower=0;bulletCount=0;scoreLbl=0;stageLbl=0;playerLifeCount=3;gameStarterCounter=4;reverseCounting=10;autoPlayModeCounter=0;deviceResolutionSize=0;currentLevelPoint=0;
    coinCountDownStart=0;powerCounterInt=0;paddleCounter=0;brickBreakSound=0;powerCreationCurrentLevel=0;
    deviceResolutionInt=0;powerBonusLifeArr=NULL;isRepeatMultiBall=false;lastPowerInt=0;
    ball=NULL;myPaddleBody = NULL;mypaddleSpritFrame = NULL;multiBallCounterToDelete=0;
    
    isPowerFlagBulletSet=false,isPowerFlagMultiBallSet=false,isPowerFlagAutoPlaySet=false,isPowerFlagBonusPointsSet=false,isPowerFlagLargePaddleSet=false,isPowerFlagSlowBallSet=false,isPowerFlagMagnetSet=false,isPowerFlagReverseBallSet=false,isPowerFlagShortPaddleSet=false,isPowerFlagFastBallSet=false,isPowerFlagBonusLifeSet=false;isdeleteMultiBalls=false;isGameWonForNextLevel=false;isTimeToRemoveGun=false;
    
    isPowerFlagBulletSetCount=0,isPowerFlagMultiBallSetCount=0,isPowerFlagAutoPlaySetCount=0,isPowerFlagBonusPointsSetCount=0,isPowerFlagLargePaddleSetCount=0,isPowerFlagSlowBallSetCount=0,isPowerFlagMagnetSetCount=0,isPowerFlagReverseBallSetCount=0,isPowerFlagShortPaddleSetCount=0,isPowerFlagFastBallSetCount=0;
    leftBulletList.clear();rightBulletList.clear();itemList.clear();ballList.clear();
}

bool GameLayer::init() {
    if (!CCLayer::init()) {
        return false;
    }
    return true;
}

#pragma mark.....................MAIN   GAME   LOGIC................................
void GameLayer::updateAtEachSeconds(float delta) {
    
    TargetPlatform localdevice = detectedDevice;
    CCSize windowSize = winSize;
    MyPaddle *myPaddleLocalStorage = myPaddle;
    Ball *ballLocalStorage = ball;
    if(isballHitPaddleInMagnet==true || isBallRecreated==true)
        previousPosition = ballLocalStorage->ballSpr->getPosition();
    if (!gameIsPaused) {
        world->Step(delta, 10, 10);
        for (b2Body *b = world->GetBodyList(); b; b = b->GetNext()) {
            if (b->GetUserData() != NULL) {
                CCSprite *sprite = (CCSprite *) b->GetUserData();
                sprite->setPosition(ccp(b->GetPosition().x * PTM_RATIO,b->GetPosition().y * PTM_RATIO));
            }
        }
        float myPaddleYpos= myPaddleLocalStorage->getPositionY();
        float myPaddleXpos= myPaddleLocalStorage->getPositionX();
        
        if(windowSize.width >=1024){
            if(myPaddleLocalStorage->getLengthState() == 2)
            {
                if(myPaddleXpos>= 1235){
                    myPaddleLocalStorage->setPosition(ccp(1235,myPaddleYpos));
                }else if (myPaddleXpos <= 300)
                {
                    myPaddleLocalStorage->setPosition(ccp(300,myPaddleYpos));
                }
            }
            else if(myPaddleLocalStorage->getLengthState() == 1)
            {
                CCPoint paddleLastPos = myPaddleLocalStorage->getPosition();
                if(paddleLastPos.x >= 1295){
                    myPaddleLocalStorage->setPosition(ccp(1295, myPaddleYpos));
                }else if (paddleLastPos.x <= 240)
                {
                    myPaddleLocalStorage->setPosition(ccp(240,myPaddleYpos));
                }
            }
        }
        paddleLayer->setPosition(ccp(myPaddleXpos-300,myPaddleYpos-200));
        
        if(isballHitPaddleInMagnet==true|| isBallRecreated==true)
        {
            CCPoint currentPosition = ballLocalStorage->ballSpr->getPosition();
            float distanceX = previousPosition.x - currentPosition.x;
            float distanceY = previousPosition.y - currentPosition.y;
            float damping = ccpDistance(previousPosition, currentPosition);
            ballLocalStorage->ballBody->SetLinearDamping(damping);
            ballLocalStorage->ballBody->SetLinearVelocity(b2Vec2(distanceX, distanceY));
            
            switch (deviceResolutionInt)
            {
                case 1:{
                    ballLocalStorage->ballSpr->setPosition(ccp(myPaddleXpos,myPaddleYpos+50));
                }
                    break;
                case 2:{
                    if (CCDirector::sharedDirector()->getWinSize().height==1136)
                    {
                        ballLocalStorage->ballSpr->setPosition(ccp(myPaddleXpos,myPaddleYpos+25));
                    }
                    else
                    {
                        ballLocalStorage->ballSpr->setPosition(ccp(myPaddleXpos,myPaddleYpos+25));
                    }
                }
                    break;
                case 3:{
                    ballLocalStorage->ballSpr->setPosition(ccp(myPaddleXpos,myPaddleYpos+25));
                }
                    break;
                case 4:{
                    ballLocalStorage->ballSpr->setPosition(ccp(myPaddleXpos,myPaddleYpos+20));
                }
                    break;
                case 5:{
                    ballLocalStorage->ballSpr->setPosition(ccp(myPaddleXpos,myPaddleYpos+25));
                }
                    break;
                case 6:{
                    ballLocalStorage->ballSpr->setPosition(ccp(myPaddleXpos,myPaddleYpos+50));
                }
                    break;
                default:
                    break;
            }
            CCPoint updatedPoint = ballLocalStorage->ballSpr->getPosition();
            ballLocalStorage->ballBody->SetTransform(b2Vec2(updatedPoint.x,updatedPoint.y),0);
        }
        //=============== start of remove hit Bricks code ====================================
        std::vector<ContactHolder>::iterator pos;
        for( pos = m_contactListener->contacts.begin(); pos != m_contactListener->contacts.end(); pos++ )
        {
            b2Body* bodyA = pos->fixtureA->GetBody();
            b2Body* bodyB = pos->fixtureB->GetBody();
            isTouchedOnPaddlefront=false;
            if(bodyA != NULL && bodyB != NULL )
            {
                CCSprite* spriteA = (CCSprite*) bodyA->GetUserData();
                CCSprite* spriteB = (CCSprite*) bodyB->GetUserData();
                
                if( spriteA != NULL && spriteB != NULL )
                {
                    if(spriteA->getTag()==0 && spriteB->getTag()==0)
                    {
                        b2Vec2 bv;
                        bv = bodyB->GetLinearVelocity();
                        bv.x = bv.x+5;
                        bv.y = bv.y+10;
                        bodyB->SetLinearVelocity(bv);
                        
                        bv = bodyA->GetLinearVelocity();
                        bv.x = bv.x+5;
                        bv.y = bv.y+10;
                        bodyA->SetLinearVelocity(bv);
                        
                    }
                    if(spriteA->getTag()==29999 && spriteB->getTag()==0)
                    {
                        
                        if(isMagnetEnabled==true)
                        {
                            unschedule(schedule_selector(GameLayer::updateAtEachSeconds));
                            unschedule(schedule_selector(GameLayer::checkIfGameOver));
                            unschedule(schedule_selector(GameLayer::gameWonRestartConfirm));
                            
                            isMagnetEnabled=false;
                            removeAllBalls();
                            removeAllBalls();
                            CCCallFunc * callFunc = CCCallFunc::create( this, callfunc_selector( GameLayer::powerCounterScheduler) );
                            this->runAction( CCSequence::createWithTwoActions(CCDelayTime::create(0.01),callFunc));
                            return;
                        }
                    }
                    
                    //Black Color Brick
                    else if (spriteA->getTag() == 9 && spriteB->getTag() == 0){
                        dropDownPowerFromPosition(spriteA,localdevice);
                        addPoints(5);
                        spriteA->setTag(8);
                        if(isBlackColorBackground==true)
                            spriteA->setColor(ccc3(150,150,150));
                        else
                            spriteA->setColor(ccc3(105,105,105));
                    }
                    //Black Color Brick
                    else if (spriteA->getTag() == 8 && spriteB->getTag() == 0)
                    {
                        dropDownPowerFromPosition(spriteA,localdevice);
                        addPoints(5);
                        spriteA->setTag(33333);
                        if(isBlackColorBackground==true)
                            spriteA->setColor(ccc3(200,200,200));
                        else
                            spriteA->setColor(ccc3(30,30,30));
                    }
                    //Orange Color Brick
                    else if (spriteA->getTag() == 6 && spriteB->getTag() == 0){
                        dropDownPowerFromPosition(spriteA,localdevice);
                        addPoints(5);
                        spriteA->setTag(22222);
                        spriteA->setColor(ccc3(246,142,40));
                    }
                    
                    //Black Color Brick ============Final Break================
                    else if (spriteA->getTag() == 33333 && spriteB->getTag() == 0)
                    {
                        dropDownPowerFromPosition(spriteA,localdevice);
                        if(windowSize.width >=1024){
                            brickExplodeAtPos(spriteA->getPosition(), bricksLayer, "brickBlackParticle.plist",1);}else{
                                brickExplodeAtPos(spriteA->getPosition(), bricksLayer, "brickBlackParticleiPod.plist",1);
                            }
                        addPoints(15);
                        toRemove.push_back( bodyA);
                        SoundManager::sharedSoundManager()->stopSoundEffect(brickBreakSound);
                        brickBreakSound =SoundManager::sharedSoundManager()->playSoundEffect("Brick_Sound 6.wav", false);
                        
                    }
                    //Orange Color Brick ============Final Break================
                    else if (spriteA->getTag() == 22222 && spriteB->getTag() == 0){
                        dropDownPowerFromPosition(spriteA,localdevice);
                        if(windowSize.width >=1024){
                            brickExplodeAtPos(spriteA->getPosition(), bricksLayer, "brickOrangeParticle.plist",1);}else{
                                brickExplodeAtPos(spriteA->getPosition(), bricksLayer, "brickOrangeParticleiPod.plist",1);
                            }
                        addPoints(10);
                        toRemove.push_back( bodyA);
                        SoundManager::sharedSoundManager()->stopSoundEffect(brickBreakSound);
                        brickBreakSound =SoundManager::sharedSoundManager()->playSoundEffect("Brick_Sound 6.wav", false);
                        
                    }
                    
                    //Yellow Color Brick ============Final Break================
                    if(spriteA->getTag() == 7 && spriteB->getTag() == 0)
                    {
                        dropDownPowerFromPosition(spriteA,localdevice);
                        if(windowSize.width >=1024){
                            brickExplodeAtPos(spriteA->getPosition(), bricksLayer, "brickYellowParticle.plist",1);}else{
                                brickExplodeAtPos(spriteA->getPosition(), bricksLayer, "brickYellowParticleiPod.plist",1);
                            }
                        
                        addPoints(5);
                        toRemove.push_back( bodyA);
                        SoundManager::sharedSoundManager()->stopSoundEffect(brickBreakSound);
                        brickBreakSound =SoundManager::sharedSoundManager()->playSoundEffect("Brick_Sound 6.wav", false);
                    }
                }
            }
        }
        
        if(leftBulletList.size()>0 || rightBulletList.size()>0){
            isTimeToRemoveGun=true;
        }
        else{
            isTimeToRemoveGun=false;
        }
        
        int localcurrentLevel = currentLevel;
        removeBullet(windowSize,localdevice);
        avoidUnwantedSituation(localcurrentLevel);
        updateGunPosition(localdevice,localcurrentLevel);
    }
}


void GameLayer::dropDownPowerFromPosition(CCSprite *brickPos,TargetPlatform device)
{
    TargetPlatform localDeviceDeteted = device;
    CCSprite *localbrickPos =brickPos;
    if(isPowerToGenerate==true || isCoinToGenerate==true){
        powerCreationAndDropDown(localbrickPos->getPosition(),localDeviceDeteted);
    }
}

void GameLayer::addPoints(int point)
{
    int localPoints = point;
    currentLevelPoint +=localPoints;
    brickPoints += localPoints;
    GameManager::sharedGameManager()->AddPoints(localPoints);
    
    CCLabelTTF *lblPoints = (CCLabelTTF*)scoreLbl;
    lblPoints->setString(CCString::createWithFormat("%d",brickPoints)->getCString());
}
void GameLayer::addCoins(int number){
    GameManager::sharedGameManager()->saveCoinsCount(number);
    coinCounter +=number;
    coinLabel->setString(CCString::createWithFormat("%d",coinCounter)->getCString());
}

#pragma  mark   COCOSBUILDER INITITIALIZATION
void GameLayer::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    ObjCCalls::hideActivityIndicator();
    
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(GameLayer::onPausePressedFromAnimationLayer), "onPausePressedFromAnimationLayer", NULL);
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(GameLayer::onRestartGameLayer), "onRestartGameLayer", NULL);
    
    detectedDevice = CCApplication::sharedApplication()->getTargetPlatform();
    
    int volume = CCUserDefault::sharedUserDefault()->getIntegerForKey("FORGROUNDVOLUME");
    SoundManager::sharedSoundManager()->setEffectVolume(volume);
    
    deviceResolutionInt = GameManager::sharedGameManager()->get_devise_resolution();
    deviceResolutionForLocal=deviceResolutionInt;
    multiBallCount=CCUserDefault::sharedUserDefault()->getIntegerForKey("EXTRAMULTIBALLCOUNTER");
    bulletTimerCount=CCUserDefault::sharedUserDefault()->getIntegerForKey("BULLETTIMERCOUNTER");
    bonusPointsCount=CCUserDefault::sharedUserDefault()->getIntegerForKey("BONUSPOINTCOUNTER");
    bonusLifeCount=CCUserDefault::sharedUserDefault()->getIntegerForKey("BONUSLIFECOUNTER");
    largePaddleCount=CCUserDefault::sharedUserDefault()->getIntegerForKey("LARGEPADDLECOUNTER");
    autoPlayCount=CCUserDefault::sharedUserDefault()->getIntegerForKey("AUTOPLAYTIMERCOUNTER");
    brickPoints=CCUserDefault::sharedUserDefault()->getIntegerForKey("BREAKPOINTS");
    
    autoPlayTotalTimer = autoPlayCount+6;
    largepaddleTotalTimer = largePaddleCount+6;
    butlletTotalTimer =bulletTimerCount+6;
    brickPoints = bonusPointsCount+brickPoints;
    
    instructionLabel->setZOrder(100);
    instructionLabel->setVisible(true);
    powerBonusLifeArr = CCArray::create();
    powerBonusLifeArr->retain();
    
    initAllObjects();
}

void GameLayer::onPausePressedFromAnimationLayer()
{
    if(animationLayerObj->getgameIsPaused() ==true)
    {
        std::list<Item*>::iterator it;
        for( it = itemList.begin(); it != itemList.end(); it++ )
        {
            if( (*it) != NULL && itemList.size() != 0)
            {
                //                CCSprite *itemSpr =(CCSprite*)(*it)->getitemSprite();
                (*it)->pauseSchedulerAndActions();
            }
        }
    }
    else{
        std::list<Item*>::iterator it;
        for( it = itemList.begin(); it != itemList.end(); it++ )
        {
            if( (*it) != NULL && itemList.size() != 0)
            {
                //                CCSprite *itemSpr =(CCSprite*)(*it)->getitemSprite();
                (*it)->resumeSchedulerAndActions();
            }
        }
    }
}

void GameLayer::initAllObjects()
{
    CCLOG("on loaded called");
    CCArray *localUsers = get_Challenge_userslist();
    GameManager::sharedGameManager()->setchallenge_existing_usersArr(localUsers);
    winSize = CCDirector::sharedDirector()->getWinSize();
    GameManager::sharedGameManager()->initialize();
    int localdeviceResolutionInt = deviceResolutionInt;
    
    currentLevel =  CCUserDefault::sharedUserDefault()->getIntegerForKey("BREAKLEVEL");
    brickPoints=CCUserDefault::sharedUserDefault()->getIntegerForKey("BREAKPOINTS");
    coinCounter = CCUserDefault::sharedUserDefault()->getIntegerForKey("COINCOUNT");
    
    int playedLevel =currentLevel;
    if(playedLevel>56){
        playedLevel=1;
        currentLevel=1;
    }
    int localStageCounter =currentLevel;
    powerCreationCurrentLevel = playedLevel;
    int clickCounter =0;
    if(localStageCounter<=8){
        powerBonusLifeArr->addObject(CCString::createWithFormat("%d",randomNumberBetween(1, 8)));
        powerBonusLifeArr->addObject(CCString::createWithFormat("%d",randomNumberBetween(1, 8)));
        clickCounter=1;
    }
    if (localStageCounter>8 && localStageCounter<17){
        powerBonusLifeArr->addObject(CCString::createWithFormat("%d",randomNumberBetween(9, 16)));
        powerBonusLifeArr->addObject(CCString::createWithFormat("%d",randomNumberBetween(9, 16)));
        clickCounter=2;
    }
    
    if (localStageCounter>=17 && localStageCounter<25){
        powerBonusLifeArr->addObject(CCString::createWithFormat("%d",randomNumberBetween(17, 24)));
        powerBonusLifeArr->addObject(CCString::createWithFormat("%d",randomNumberBetween(17, 24)));
        clickCounter=3;
    }
    
    if (localStageCounter>=25 && localStageCounter<33){
        powerBonusLifeArr->addObject(CCString::createWithFormat("%d",randomNumberBetween(25, 32)));
        powerBonusLifeArr->addObject(CCString::createWithFormat("%d",randomNumberBetween(25, 32)));
        clickCounter=4;
    }
    
    if (localStageCounter>=33 && localStageCounter<41){
        powerBonusLifeArr->addObject(CCString::createWithFormat("%d",randomNumberBetween(33, 40)));
        powerBonusLifeArr->addObject(CCString::createWithFormat("%d",randomNumberBetween(33, 40)));
        clickCounter=5;
    }
    
    if (localStageCounter>=41 && localStageCounter<49){
        powerBonusLifeArr->addObject(CCString::createWithFormat("%d",randomNumberBetween(41, 48)));
        powerBonusLifeArr->addObject(CCString::createWithFormat("%d",randomNumberBetween(41, 48)));
        clickCounter=6;}
    
    if (localStageCounter>=49 &&localStageCounter<57){
        powerBonusLifeArr->addObject(CCString::createWithFormat("%d",randomNumberBetween(49, 56)));
        powerBonusLifeArr->addObject(CCString::createWithFormat("%d",randomNumberBetween(49, 56)));
        clickCounter=7;
    }
    
    CCLog("clickCounter %d",clickCounter);
    CCUserDefault::sharedUserDefault()->setIntegerForKey("CLICKCOUNTER",clickCounter);
    CCUserDefault::sharedUserDefault()->flush();
    
    AnimationLayer *localanimationLayerObj = animationLayerObj;
    localanimationLayerObj->getmultiBallTopPowerSpr()->setVisible(false);
    
    //-----------------------BackGround Theme Setting---------------------------------
    CCSprite *backBGSpr;
    CCLayerColor *localmenuLayer  = (CCLayerColor*)localanimationLayerObj->getmenuLayer();
    if(localStageCounter==1 || localStageCounter==9 || localStageCounter==17 || localStageCounter==25 || localStageCounter==33 || localStageCounter==41 || localStageCounter==49 || isInstructionLabelVisible==true){
        backBGSpr = (CCSprite*)this->getChildByTag(900);
        isBlackColorBackground=backGroundSetting(playedLevel, backGroundSpr, backBGSpr, shapeBackLayer,  localdeviceResolutionInt);
        if(isBlackColorBackground==true){
            localmenuLayer->setOpacity(10);
        }
        else{
            localmenuLayer->setOpacity(100);
        }
    }
    
    CCLabelTTF *localkachcheLabelGameWon = (CCLabelTTF*)localanimationLayerObj->getcontinueLabelNotUsed();
    CCLabelTTF *lableGameWon = (CCLabelTTF*)localanimationLayerObj->getkacheLabelGameWon();
    
    switch (localdeviceResolutionInt){
        case 1:{
            localanimationLayerObj->getKaccheGameOverLabel()->setFontSize(80);
            lableGameWon->setFontSize(80);
            localkachcheLabelGameWon->setFontSize(80);
            
        }
            break;
        case 2:{
            if (CCDirector::sharedDirector()->getWinSize().height==1136){
                localanimationLayerObj->getKaccheGameOverLabel()->setFontSize(40);
                lableGameWon->setFontSize(40);
                localkachcheLabelGameWon->setFontSize(40);
                instructionLabel->setFontSize(40);
            }
            else{
                localanimationLayerObj->getKaccheGameOverLabel()->setFontSize(40);
                lableGameWon->setFontSize(40);
                localkachcheLabelGameWon->setFontSize(40);
                instructionLabel->setFontSize(40);
                
            }
        }
            break;
        case 3:{
            localanimationLayerObj->getKaccheGameOverLabel()->setFontSize(40);
            lableGameWon->setFontSize(40);
            localkachcheLabelGameWon->setFontSize(40);
            instructionLabel->setFontSize(40);
            
        }
            break;
        case 4:{
            localanimationLayerObj->getKaccheGameOverLabel()->setFontSize(40);
            lableGameWon->setFontSize(40);
            localkachcheLabelGameWon->setFontSize(40);
            instructionLabel->setFontSize(40);
        }
            break;
        case 5:{
            localanimationLayerObj->getKaccheGameOverLabel()->setFontSize(40);
            lableGameWon->setFontSize(40);
            localkachcheLabelGameWon->setFontSize(40);
            instructionLabel->setFontSize(40);
            
        }
            break;
        case 6:{
            localanimationLayerObj->getKaccheGameOverLabel()->setFontSize(80);
            lableGameWon->setFontSize(80);
            localkachcheLabelGameWon->setFontSize(80);
            
        }
            break;
        default:
            break;
    }
    
    CCSize windowSize = winSize;
    coinTimer = coinArrivalTime[playedLevel];
    b2Vec2 gravity(0.0f, 0.0f);
    world = new b2World(gravity);
    navigationLayer->setZOrder(200);
    
    coinAnimateArray = CCArray::create();
    coinAnimateArray->retain();
    
    m_contactListener = new ContactListener();
    world->SetContactListener(m_contactListener);
    
    randomValueForPowerToAppear = powerCreateDuration[playedLevel];
    localanimationLayerObj->getpauseMenuItemButton()->setEnabled(false);
    localanimationLayerObj->getstageMenuItemButton()->setEnabled(false);
    
    navigationLayer->setColor(ccc3(213, 213, 213));
    localanimationLayerObj->getpauseAndPlayLayer()->setColor(ccc3(213, 213, 213));
    localanimationLayerObj->getstageLayer()->setColor(ccc3(213, 213, 213));
    
    bricksLayer = CCLayer::create();
    bricksLayer->setPosition(ccp(0, (windowSize.height/2)+300));
    this->addChild(bricksLayer);
    
    CCLayer *localbricksLayer = bricksLayer;
    
    buildBrickPaddle();
    
    //Navigation layer objects
    if(isNavigationLayerAllObjectGotInitialised==false)
        changeLableSizeAndPos(stageSpr,stageLbl,scoreSpr,scoreLbl,coinSpr,coinLabel,ballTopSpr,globalPlayerLifeCountLabel,localdeviceResolutionInt);
    
    isNavigationLayerAllObjectGotInitialised = true;
    
    stageLbl->setFontName("fonts/Zekton-Bold.ttf");
    scoreLbl->setFontName("fonts/Zekton-Bold.ttf");
    coinLabel->setFontName("fonts/Zekton-Bold.ttf");
    globalPlayerLifeCountLabel->setFontName("fonts/Zekton-Bold.ttf");
    
    if(coinCounter>9999)
        coinCounter=0;
    globalPlayerLifeCountLabel->setString(CCString::createWithFormat("%d",playerLifeCount)->getCString());
    coinLabel->setString(CCString::createWithFormat("%d",coinCounter)->getCString());
    
    autostrip = CCSprite::create("autostrip.png");
    autostrip->setPosition(ccp(windowSize.width/2, 10));
    localbricksLayer->addChild(autostrip);
    autostrip->setVisible(false);
    
    if((playedLevel>8 && playedLevel<17) ||(playedLevel>32 && playedLevel<41) ){
        shapeSpr = CCSprite::create(CCString::createWithFormat("newshape%d.png",playedLevel)->getCString());
        CCSprite* localSpr = shapeBackColorAndVisiblity(playedLevel,windowSize, shapeSpr,localdeviceResolutionInt);
        localbricksLayer->addChild(localSpr);
    }
    
    string brickOrange = "brickOrange.png";
    topLineSpr = CCSprite::create("topline.png");
    switch (deviceResolutionInt)
    {
        case 1:
            topLineSpr->setPosition(ccp(windowSize.width/2, windowSize.height-180));
            break;
        case 2: if (CCDirector::sharedDirector()->getWinSize().height==1136){
            topLineSpr->setPosition(ccp(windowSize.width/2, windowSize.height-98));
        }
        else{
            topLineSpr->setPosition(ccp(windowSize.width/2, windowSize.height-100));
        }
            break;
        case 3:
            topLineSpr->setPosition(ccp(windowSize.width/2, windowSize.height-98));
            break;
        case 4:
            topLineSpr->setPosition(ccp(windowSize.width/2, windowSize.height-98));
            break;
        case 5:
            topLineSpr->setPosition(ccp(windowSize.width/2, windowSize.height-110));
            break;
        case 6:
            topLineSpr->setPosition(ccp(windowSize.width/2, windowSize.height-195));
            break;
            
        default:
            break;
    }
    
    localbricksLayer->addChild(topLineSpr);
    topLineSpr->setVisible(false);
    
    animationLable = CCLabelTTF::create("", "fonts/ZektonRg-Regular.ttf", 60);
    localbricksLayer->addChild(animationLable);
    
    countingLable = CCLabelTTF::create("", "fonts/Zekton-Bold.ttf", 80);
    this->addChild(countingLable);
    countingLable->setZOrder(500);
    
    
    setKeypadEnabled(true);
    setTouchPriority(kCCMenuHandlerPriority + 1);
    setTouchEnabled(true);
    
    localanimationLayerObj->getmenuLayer()->setVisible(false);
    
    //Add the previous Points
    CCLabelTTF *lblPoints = (CCLabelTTF*)scoreLbl;
    lblPoints->setString(CCString::createWithFormat("%d",brickPoints)->getCString());
    
    //Add the previous Coins
    CCLabelTTF *coinsLabel = (CCLabelTTF*)coinLabel;
    coinsLabel->setString(CCString::createWithFormat("%d",coinCounter)->getCString());
    
    buildGround();
    
    if(isBlackColorBackground==true){
        normalPaddleSpr = CCSprite::create(paddleNameNight.c_str());
        longPaddleSpr = CCSprite::create(longPaddleTypeNight.c_str());
        shortPaddleSpr = CCSprite::create(shortPaddleTypeNight.c_str());
        buildMyPaddle(paddleNameNight);
    }
    else
    {
        normalPaddleSpr = CCSprite::create(paddleName.c_str());
        longPaddleSpr = CCSprite::create(longPaddleType.c_str());
        shortPaddleSpr = CCSprite::create(shortPaddleType.c_str());
        buildMyPaddle(paddleName);
    }
    localbricksLayer->addChild(normalPaddleSpr);
    normalPaddleSpr->setVisible(false);
    
    localbricksLayer->addChild(longPaddleSpr);
    longPaddleSpr->setVisible(false);
    
    localbricksLayer->addChild(shortPaddleSpr);
    shortPaddleSpr->setVisible(false);
    localbricksLayer->setContentSize(CCSizeMake(windowSize.width, windowSize.height+40));
    
    localbricksLayer=bricksLayer;
    buildBall("ball.png");
    restrictPaddleMovement();
    CCCallFunc * callFunc = CCCallFunc::create( this, callfunc_selector( GameLayer::brickFallDown) );
    bricksLayer->runAction( CCSequence::createWithTwoActions(CCMoveTo::create(2.3, ccp(0, 0)),callFunc));
    
    if(localdeviceResolutionInt==1 || localdeviceResolutionInt==6)
    {
        CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("CoinAnimationIpad.plist", "CoinAnimationIpad.png");
        for ( int i = 1; i < 8; i++ ){
            CCSpriteFrame*		pFrame = CCSpriteFrameCache::sharedSpriteFrameCache ( )->spriteFrameByName ( CCString::createWithFormat ( "coin%d.png", i )->getCString() );
            coinAnimateArray->addObject ( pFrame );
        }
    }
    else
    {
        CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("CoinAnimationIpod.plist", "CoinAnimationIpod.png");
        for ( int i = 1; i < 8; i++ ){
            CCSpriteFrame*		pFrame = CCSpriteFrameCache::sharedSpriteFrameCache ( )->spriteFrameByName ( CCString::createWithFormat ( "coin%d.png", i )->getCString() );
            coinAnimateArray->addObject ( pFrame );
        }
    }
    
    
}

SEL_CallFuncN GameLayer::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
    return NULL;
}

SEL_MenuHandler GameLayer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName){
    
    return NULL;
}

SEL_CCControlHandler GameLayer::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName){
    return NULL;
}

bool GameLayer::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "scoreLbl",CCLabelTTF*, this->scoreLbl);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "coinLabel",CCLabelTTF *, this->coinLabel);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "stageLbl",CCLabelTTF *, this->stageLbl);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "kachcheLabel",CCLabelTTF *, this->kachcheLabel);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "kachcheLabelGameWon",CCLabelTTF *, this->kachcheLabelGameWon);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "powerCountLabel",CCLabelTTF *, this->powerCountLabel);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "instructionLabel",CCLabelTTF *, this->instructionLabel);
    
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "navigationLayer",CCLayerColor *, this->navigationLayer);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "shapeBackLayer",CCLayerColor *, this->shapeBackLayer);
    
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "stageSpr",CCSprite *, this->stageSpr);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "scoreSpr",CCSprite *, this->scoreSpr);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "ballTopSpr",CCSprite *, this->ballTopSpr);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "coinSpr",CCSprite *, this->coinSpr);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "shapeSpr",CCSprite *, this->shapeSpr);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "backGround",CCSprite *, this->backGroundSpr);
    
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "animationLayerObj",AnimationLayer *, this->animationLayerObj);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "globalPlayerLifeCountLabel",CCLabelTTF *, this->globalPlayerLifeCountLabel);
    return false;
}

bool GameLayer::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    bool bRet = false;
    return bRet;
}

void GameLayer::brickFallDown()
{
    if(isBlackColorBackground==true)
        instructionLabel->setColor(ccc3(255,255,255));
    else
        instructionLabel->setColor(ccc3(0,0,0));
    
    this->startGame();
}

#pragma mark   BUILD     BALL,    PADDLE,   GROUND,    BALL,     BULLET,   BRICKS
void GameLayer::startGame()
{
    scoreLbl->setString(CCString::createWithFormat("%d",brickPoints)->getCString());
    
    kachcheLabelGameWon->setVisible(false);
    kachcheLabel->setVisible(false);
    kachcheLabelGameWon->setFontName("fonts/Zekton-Bold.ttf");
    kachcheLabel->setFontName("fonts/Zekton-Bold.ttf");
    isGameStarted=true;
    AnimationLayer *localanimationLayerObj = animationLayerObj;
    
    localanimationLayerObj->getpauseMenuItemButton()->setEnabled(true);
    localanimationLayerObj->getstageMenuItemButton()->setEnabled(true);
    
    schedule(schedule_selector(GameLayer::updateAtEachSeconds));
    schedule(schedule_selector(GameLayer::powerUpItems));
    schedule(schedule_selector(GameLayer::timerForPower),1);
    schedule(schedule_selector(GameLayer::enableCoinToDrop),2);
    schedule(schedule_selector(GameLayer::disablePaddleMovement),2);
    schedule(schedule_selector(GameLayer::checkIfGameOver));
    schedule(schedule_selector(GameLayer::gameWonRestartConfirm));
}

void GameLayer::buildGround() {
    // Create edges around the entire screen
    CCSize windowSize = winSize;
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0,0);
    groundBody = world->CreateBody(&groundBodyDef);
    
    groundBoxDef.shape = &groundBox;
    
    groundBox.Set(b2Vec2(0,0), b2Vec2(0, (windowSize.height/PTM_RATIO)-2));
    groundBody->CreateFixture(&groundBoxDef);
    
    //=============== Bottom to restict game over ====================================
    //       groundBox.Set(b2Vec2(0,0), b2Vec2(winSize.width/PTM_RATIO, 0));
    //       bottomFixture = groundBody->CreateFixture(&groundBoxDef);
    if(deviceResolutionInt==1 || deviceResolutionInt==6)
        groundBox.Set(b2Vec2(0, (windowSize.height/PTM_RATIO)-5), b2Vec2(windowSize.width/PTM_RATIO,
                                                                         (windowSize.height/PTM_RATIO)-5));
    else
        groundBox.Set(b2Vec2(0, (windowSize.height/PTM_RATIO)-3), b2Vec2(windowSize.width/PTM_RATIO,
                                                                         (windowSize.height/PTM_RATIO)-3));
    groundBody->CreateFixture(&groundBoxDef);
    
    groundBox.Set(b2Vec2(windowSize.width/PTM_RATIO, (windowSize.height/PTM_RATIO)-2),
                  b2Vec2(windowSize.width/PTM_RATIO, 0));
    groundBody->CreateFixture(&groundBoxDef);
}

void GameLayer::buildBullet(std::string bulletTypeStr)
{
    CCSize windowSize = winSize;
    CCLayer *brickLyr = bricksLayer;
    CCPoint mypaddlePos =myPaddle->getPosition();
    std::string bulletType = bulletTypeStr;
    int paddleLenghtState = myPaddle->getLengthState();
    b2World *worldLocalStorage = world;
    TargetPlatform detectPlatform = detectedDevice;
    int localdeviceResolutionInt=deviceResolutionInt;
    
    CCSprite *rightBulletSpr = rightBulletAtPos(mypaddlePos,brickLyr, bulletType.c_str(), windowSize,paddleLenghtState,detectPlatform,localdeviceResolutionInt);
    
    Bullet* rightBullet = new Bullet();
    rightBullet->Init(brickLyr, worldLocalStorage,rightBulletSpr,5);
    rightBulletList.push_back(rightBullet);
    
    CCSprite * leftBulletSpr = leftBulletAtPos(mypaddlePos,brickLyr, bulletType.c_str(), windowSize,paddleLenghtState,detectPlatform,localdeviceResolutionInt);
    
    Bullet* leftBullet= new Bullet();
    leftBullet->Init(this, worldLocalStorage,leftBulletSpr,5);
    leftBulletList.push_back(leftBullet);
}

void GameLayer::buildBall(std::string ballType) {
    Ball *ballocalStore = ball;
    ballocalStore = Ball::createBall("ball.png");
    ballocalStore->setTag(0);
    
    float mypaddleXPos = myPaddle->getPositionX();
    float mypaddleYPos = myPaddle->getPositionY();
    
    switch (deviceResolutionInt)
    {
        case 1:
            ballocalStore->setPosition(ccp(mypaddleXPos,mypaddleYPos+50));
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136)
            {
                ballocalStore->setPosition(ccp(mypaddleXPos,mypaddleYPos+25));
            }
            else
            {
                ballocalStore->setPosition(ccp(mypaddleXPos,mypaddleYPos+25));
            }
        }
            break;
        case 3:ballocalStore->setPosition(ccp(mypaddleXPos,mypaddleYPos+25));
            break;
        case 4:ballocalStore->setPosition(ccp(mypaddleXPos,mypaddleYPos+20));
            break;
        case 5:ballocalStore->setPosition(ccp(mypaddleXPos,mypaddleYPos+25));
            break;
        case 6:ballocalStore->setPosition(ccp(mypaddleXPos,mypaddleYPos+50));
            break;
        default:
            break;
    }
    this->addChild(ballocalStore,1);
    
    ballocalStore->setBallSpr(ballocalStore);
    //=============== ball body ====================================
    ballBodyDef.type = b2_dynamicBody;
    ballBodyDef.position.Set(ballocalStore->getPosition().x / PTM_RATIO,
                             ballocalStore->getPosition().y / PTM_RATIO);
    ballBodyDef.bullet = true;
    ballBodyDef.gravityScale = 0.0f;
    
    //=============== circle shape ====================================
    b2CircleShape circle;
    circle.m_radius = ballocalStore->getRadius() / PTM_RATIO;
    
    //================== ball shape ===============================
    b2FixtureDef ballFixtureDef;
    ballFixtureDef.shape = &circle;
    ballFixtureDef.density = 1.0f;
    ballFixtureDef.friction = 0.0f;
    ballFixtureDef.restitution = 1.0f;
    
    ballBodyDef.userData = ballocalStore;
    ballocalStore->setBallState(Ball::simpleBall);
    ballocalStore->setBallBody(world->CreateBody(&ballBodyDef));
    ballocalStore->ballBody->SetUserData(ballocalStore);
    ballocalStore->setBallSpr(ballocalStore);
    ballFixture =ballocalStore->ballBody->CreateFixture( &ballFixtureDef);
    
    if(isMultiBallCreated==true)
    {
        isMultiBallCreated=false;
        if(multiBallCount==2)
            isMultiBallCreated=true;
        if(multiBallCount==3)
            isMultiBallCreated=true;
        isBallRecreated=false;
        isTouchedOnPaddlefront=false;
        isBallRecreatedAndTouched=false;
        b2Vec2 v;
        int random = arc4random()%2;
        if(random==0)
            v = b2Vec2(30,30);
        else
            v = b2Vec2(-30,30);
        ballocalStore->ballBody->SetLinearVelocity(v);
    }
    else{
        isTouchedOnPaddlefront=true;
        ballocalStore->ballBody->SetActive(true);
        isBallRecreated=true;
        isBallRecreatedAndTouched=false;
    }
    
    ball = ballocalStore;
    ballList.push_back(ball);
}


void GameLayer::buildMyPaddle(std::string myPaddleName) {
    if (myPaddleFixture != NULL) {
        myPaddleBody->DestroyFixture(myPaddleFixture);
        myPaddleFixture=NULL;
    }
    
    if(isPaddleCreatedNotFirstTime==false){
        myPaddle = MyPaddle::createMyPaddle(myPaddleName.c_str());
        this->addChild(myPaddle);
        myPaddle->setTag(29999);
        
        CCSize windowSize = winSize;
        switch (deviceResolutionInt)
        {
            case 1:
                myPaddle->setPosition(ccp(windowSize.width / 2, myPaddle->getTextureRect().getMidY() + 120));
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136){
                    myPaddle->setPosition(ccp(windowSize.width / 2, myPaddle->getTextureRect().getMidY() + 105));
                    
                }
                else{
                    myPaddle->setPosition(ccp(windowSize.width / 2, myPaddle->getTextureRect().getMidY() + 90));
                }
            }
                break;
            case 3:
                myPaddle->setPosition(ccp(windowSize.width / 2, myPaddle->getTextureRect().getMidY() + 80));
                break;
            case 4:
                myPaddle->setPosition(ccp(windowSize.width / 2, myPaddle->getTextureRect().getMidY() + 70));
                break;
            case 5:
                myPaddle->setPosition(ccp(windowSize.width / 2, myPaddle->getTextureRect().getMidY() + 105));
                break;
            case 6:
                myPaddle->setPosition(ccp(windowSize.width / 2, myPaddle->getTextureRect().getMidY() + 120));
                break;
            default:
                break;
        }
        
        
        //my paddle body
        myPaddleBodyDef.type = b2_dynamicBody;
        myPaddleBodyDef.userData = myPaddle;
        myPaddleBodyDef.position.Set(myPaddle->getPosition().x / PTM_RATIO,
                                     myPaddle->getPosition().y / PTM_RATIO);
        
        myPaddleBody = (world->CreateBody(&myPaddleBodyDef));
        
        paddleLayer = CCLayer::create();
        paddleLayer->setPosition(myPaddle->getPosition());
        paddleLayer->setContentSize(CCSizeMake(myPaddle->getContentSize().width+450, myPaddle->getContentSize().height+500));
        bricksLayer->addChild(paddleLayer);
    }
    b2PolygonShape myPaddleShape;
    
    CCSprite *spr = myPaddleImage(myPaddle, isAddGun, myPaddle->getLengthState(),isBlackColorBackground);
    
    myPaddleShape.SetAsBox((spr->getContentSize().width)/ PTM_RATIO/2,
                           spr->getContentSize().height/ PTM_RATIO/2);
    //=============================my paddle fixture========================
    b2FixtureDef myPaddleFixtureDef;
    myPaddleFixtureDef.shape = &myPaddleShape;
    myPaddleFixtureDef.density = 10.0f;
    myPaddleFixtureDef.friction = 0.4f;
    myPaddleFixtureDef.restitution = 0.1f;
    myPaddleFixture = myPaddleBody->CreateFixture(&myPaddleFixtureDef);
    isPaddleCreatedNotFirstTime = true;
}

void GameLayer::buildBrickPaddle() {
    
    int localLevel = currentLevel;
    CCArray *piecesPosition=CCArray::create();
    piecesPosition->retain();
    
    CCArray *brickSprArrr = CCArray::create();
    brickSprArrr->retain();
    vector<CCSprite*> sortedSprArr;
    CCArray *originalColorBrick = CCArray::create();
    originalColorBrick->retain();
    CCLabelTTF *currentLbl = (CCLabelTTF*)stageLbl;
    currentLbl->setString(CCString::createWithFormat("%d",localLevel)->getCString());
    
    TargetPlatform device = detectedDevice;
    CCSize windowSize = winSize;
    
    CCLayer *locakBricksLayer = bricksLayer;
    
    string brickOrange = "brickOrange.png";
    string brickYellow = "brickYellow.png";
    CCSprite *brickYellowSpr = CCSprite::create(brickYellow.c_str());
    brickYellowSpr->setPosition(ccp(-100, -200));
    bricksLayer->addChild(brickYellowSpr);
    int localdeviceResolutionInt=deviceResolutionInt;
    
    
    if(!((localLevel>8 && localLevel<17) ||(localLevel>32 && localLevel<41)))
    {
        for (int i = 11; i <= maxHalfBrickScaled[localLevel]; i++) {
            CCSprite *brickSpr = CCSprite::create("brickGrey.png");
            CCSprite *brickNewPosSpr =  halfBrickPositionOnTheScreenDisplay(localLevel,device,windowSize,brickSpr,i,localdeviceResolutionInt);
            brickNewPosSpr->setScaleX(0.5);
            locakBricksLayer->addChild(brickNewPosSpr);
            brickSprArrr->addObject(brickNewPosSpr);
            sortedSprArr.push_back(brickNewPosSpr);
        }
    }
    
    for (int i = 11; i <= maxFullBrickOnScreen[localLevel]; i++) {
        CCSprite *brickSpr = CCSprite::create("brickGrey.png");
        CCSprite *brickNewPosSpr = brickPositionOnTheScreenDisplay(localLevel,device,windowSize,brickSpr,i,localdeviceResolutionInt);
        locakBricksLayer->addChild(brickNewPosSpr);
        brickSprArrr->addObject(brickNewPosSpr);
        sortedSprArr.push_back(brickNewPosSpr);
    }
    
    
    brickSprArrr =GameManager::sharedGameManager()->shuffle_array(brickSprArrr, brickSprArrr->count());
    
    for (int j = blackColorBricks[localLevel]; j > 0; j--)
    {
        CCSprite *blackBrick = (CCSprite*)brickSprArrr->lastObject();
        Brick* brick = new Brick();
        brick->Init(locakBricksLayer, world,blackBrick,3);
        brickSprArrr->removeLastObject();
        m_Bricks.push_back( brick );
    }
    brickSprArrr->removeAllObjects();
    vector<CCSprite*>::iterator originalSprArr;
    for (originalSprArr = sortedSprArr.begin(); originalSprArr != sortedSprArr.end(); originalSprArr++)
    {
        CCSprite *spr = (CCSprite*)(*originalSprArr);
        if (spr->getTag()==9) {
        }
        else{
            brickSprArrr->addObject(spr);
        }
    }
    
    CCObject *objIndexNext=NULL;
    int indexing =0;
    CCARRAY_FOREACH(brickSprArrr, objIndexNext)
    {
        CCSprite *brickColouring = (CCSprite*)objIndexNext;
        if(indexing%2==0){
            brickColouring->setDisplayFrame(CCSpriteFrame::create(brickOrange.c_str(),brickYellowSpr->getTextureRect()));
            Brick* brick = new Brick();
            brick->Init(locakBricksLayer, world,brickColouring,2);
            //            orangeBrick->setColor(ccc3(235,86,44));
            m_Bricks.push_back( brick );
        }else
        {
            brickColouring->setDisplayFrame(CCSpriteFrame::create(brickYellow.c_str(),brickYellowSpr->getTextureRect()));
            Brick* brick = new Brick();
            brick->Init(locakBricksLayer, world,brickColouring,1);
            //            yellowBrick->setColor(ccc3(246,142,40));
            m_Bricks.push_back(brick);
            
        }
        indexing++;
    }
    
    bricksLayer = locakBricksLayer;
    
    sortedSprArr.clear();
    CC_SAFE_RELEASE_NULL(originalColorBrick);
    CC_SAFE_RELEASE_NULL(piecesPosition);
    CC_SAFE_RELEASE_NULL(brickSprArrr);
    
}

void GameLayer::restrictPaddleMovement() {
    //===================restrict paddle's movement===============
    b2PrismaticJointDef jointDef;
    b2Vec2 worldAxis(1.0f, 0.0f);
    jointDef.collideConnected = true;
    jointDef.Initialize(myPaddleBody, groundBody,
                        myPaddleBody->GetWorldCenter(), worldAxis);
    world->CreateJoint(&jointDef);
    //    world->SetAllowSleeping( true );
    world->SetAutoClearForces(true);
    //    world->SetContinuousPhysics(true);
}

MyPaddle* GameLayer::getMyPaddle() {
    return myPaddle;
}

void GameLayer::gameWonRestartConfirm() {
    if (gameIsEnded==true) {
        int localcurrentLevel = currentLevel;
        
        AnimationLayer *localanimationLayerObj = animationLayerObj;
        if(isPlayerLifeZero==true && isgameover==true){
            int localbrickPoints =brickPoints;
            autostrip->setVisible(false);
            topLineSpr->setVisible(false);
            isGameStarted=false;
            unschedule(schedule_selector(GameLayer::gameWonRestartConfirm));
            unschedule(schedule_selector(GameLayer::checkIfGameOver));
            unschedule(schedule_selector(GameLayer::updateAtEachSeconds));
            unschedule(schedule_selector(GameLayer::powerUpItems));
            unschedule(schedule_selector(GameLayer::timerForPower));
            unschedule(schedule_selector(GameLayer::enableCoinToDrop));
            unschedule(schedule_selector(GameLayer::disablePaddleMovement));
            unschedule(schedule_selector(GameLayer::bulletCounterTrace));
            unschedule(schedule_selector(GameLayer::bulletTimer));
            
            CCLabelTTF *yourScore = (CCLabelTTF*)localanimationLayerObj->getscoreCountLbl();
            yourScore->setString("YOUR SCORE");
            CCLabelTTF *totalScore = (CCLabelTTF*)localanimationLayerObj->getscoreLabelNotUsed();
            totalScore->setString(CCString::createWithFormat("%d",localbrickPoints)->getCString());
            HoldOnModel::shareModel()->setChallengeGameHighestScore(localbrickPoints);
            localanimationLayerObj->getstageMenuItemButton()->setEnabled(false);
            localanimationLayerObj->getpauseMenuItemButton()->setEnabled(false);
            CCLabelTTF *localKaccheGameOverLabel = (CCLabelTTF*)localanimationLayerObj->getKaccheGameOverLabel();
            localanimationLayerObj->gameOverDown(NULL);
            changeViewAndLabelContentAndColoronGameOver(localcurrentLevel, localKaccheGameOverLabel, isBlackColorBackground);
            
            localanimationLayerObj->getmultiBallTopPowerSpr()->setVisible(false);
            
            CCScaleTo *myPaddleScale = CCScaleTo::create(2, 0);
            myPaddle->runAction(myPaddleScale);
        }
        else{
            if(isCallOnce==false)
            {
                list<Item *>::iterator it;
                for( it = itemList.begin(); it != itemList.end(); it++ ){
                    if (!itemList.empty() && itemList.size() > 0){
                        (*it)->removeFromParentAndCleanup(true);
                        it = itemList.erase(it);
                    }
                }
                if(bottomFixture!=NULL){
                    groundBody->DestroyFixture(bottomFixture);
                    bottomFixture=NULL;
                }
                unschedule(schedule_selector(GameLayer::timerForPower));
                unschedule(schedule_selector(GameLayer::enableCoinToDrop));
                
                gameEndedStartCounting();
                isCallOnce=true;
                isContingEnded=true;
                if(isAddGun==true){
                    unschedule(schedule_selector(GameLayer::bulletCounterTrace));
                    unschedule(schedule_selector(GameLayer::bulletTimer));
                }
                else if (isPaddleTimerEnable==true){
                    unschedule(schedule_selector(GameLayer::paddleTimer));
                }
                
            }
            
            if(isGameEnded==true){
                int localbrickPoints =brickPoints;
                list<Ball *>::iterator it;
                for( it = ballList.begin(); it != ballList.end(); it++ ){
                    if(topLineSpr->boundingBox().intersectsRect((*it)->boundingBox()))
                    {
                        CCLabelTTF *localkachcheLabelGameWon = (CCLabelTTF*)localanimationLayerObj->getcontinueLabelNotUsed();
                        localkachcheLabelGameWon->setVisible(true);
                        localkachcheLabelGameWon->setString("");
                        localkachcheLabelGameWon->setString(CCString::createWithFormat("Level %d Completed",localcurrentLevel)->getCString());
                        
                        CCLabelTTF *lableGameWon = (CCLabelTTF*)localanimationLayerObj->getkacheLabelGameWon();
                        changeViewAndLabelContentAndColoronGameWon(localcurrentLevel, lableGameWon, isBlackColorBackground);
                        
                        CCLabelTTF *yourScore = (CCLabelTTF*)localanimationLayerObj->getscoreCountLbl();
                        yourScore->setString("YOUR SCORE");
                        CCLabelTTF *totalScore = (CCLabelTTF*)localanimationLayerObj->getscoreLabelNotUsed();
                        totalScore->setString(CCString::createWithFormat("%d",localbrickPoints)->getCString());
                        
                        topLineSpr->setVisible(false);
                        powerCountLabel->setVisible(false);
                        countingLable->setVisible(false);
                        isGameStarted=false;
                        myPaddle->setVisible(false);
                        isDestroyedGameOverPaddle=true;
                        
                        CCUserDefault::sharedUserDefault()->setIntegerForKey("BREAKLEVEL", localcurrentLevel+1);
                        CCUserDefault::sharedUserDefault()->flush();
                        
                        localanimationLayerObj->getpauseMenuItemButton()->setEnabled(false);
                        localanimationLayerObj->getstageMenuItemButton()->setEnabled(false);
                        
                        localanimationLayerObj->gameWonDown(NULL);
                        isGameWonForNextLevel=true;
                        
                        CCCallFunc * gameWonCall = CCCallFunc::create( this, callfunc_selector( GameLayer::gameWon));
                        this ->runAction(CCSequence::createWithTwoActions(CCDelayTime::create(4.3),gameWonCall));
                        
                        SoundManager::sharedSoundManager()->playSoundEffect("Ball Hit On Stick 2 Final.wav", false);
                        SoundManager::sharedSoundManager()->playSoundEffect("Cheers 3 FInal.wav", false);
                        
                        GameManager::sharedGameManager()->save_LastPlayedLavel(localcurrentLevel+1, playerLifeCount, 3);
                        
                        removeAllBalls();
                        removeAllBalls();
                        
                        gameOver();
                        releaseLayerMemory();
                        
                        HoldOnModel::shareModel()->setChallengeGameHighestScore(localbrickPoints);
                        HoldOnModel::shareModel()->reportChallengeScore();
                        break;
                    }
                }
            }
        }
    }
}

void GameLayer::releaseLayerMemory()
{
    countingLable->removeFromParentAndCleanup(true);
    myPaddle->removeFromParentAndCleanup(true);
    ball->removeFromParentAndCleanup(true);
    bricksLayer->removeAllChildren();
    bricksLayer->removeFromParentAndCleanup(true);
    
    unschedule(schedule_selector(GameLayer::gameWonRestartConfirm));
    unschedule(schedule_selector(GameLayer::checkIfGameOver));
    unschedule(schedule_selector(GameLayer::updateAtEachSeconds));
    unschedule(schedule_selector(GameLayer::powerUpItems));
    unschedule(schedule_selector(GameLayer::timerForPower));
    unschedule(schedule_selector(GameLayer::enableCoinToDrop));
    unschedule(schedule_selector(GameLayer::disablePaddleMovement));
    unschedule(schedule_selector(GameLayer::bulletCounterTrace));
    unschedule(schedule_selector(GameLayer::bulletTimer));
    return;
}

void GameLayer::enableMagnet()
{
    removeAllBalls();
    ballList.clear();
    buildBall("ball.png");
    if(gameIsEnded==true){
        isMagnetAndMultiBallEnable=false;
    }
    //    if(isMagnetAndMultiBallEnable==true){
    //        isMagnetAndMultiBallEnable=false;
    //        buildBall("ball.png");
    //    }
    //    if(isballHitPaddleInMagnet==true && isMultiBallCreated==true){
    //        buildBall("ball.png");
    //        buildBall("ball.png");
    //    }
    
    isBallRecreatedAndTouched=false;
    isBallRecreated=false;
    isballHitPaddleInMagnet=false;
    isMagnetEnabled=false;
    isReleaseBall=true;
}

#pragma  mark   TOUCHES    METHODS
void GameLayer::ccTouchesBegan(CCSet *pTouches, CCEvent *event) {
    AnimationLayer *animationLayerLocalObj = animationLayerObj;
    if(isInstructionLabelVisible==true){isInstructionLabelVisible=false;
        instructionLabel->setVisible(false);}
    if(isGameStarted==false || animationLayerLocalObj->getisPausePressed()==true)
        return;
    
    if(isballHitPaddleInMagnet==true || isBallRecreatedAndTouched==true){
        removeAllBalls();
        enableMagnet();
    }
    
    CCTouch *myTouch = (CCTouch*) pTouches->anyObject();
    CCPoint location = myTouch->getLocationInView();
    location = CCDirector::sharedDirector()->convertToGL(location);
    if(GameManager::sharedGameManager()->isNodeAtPoint(animationLayerLocalObj->getpauseAndPlayLayer(), location)){
        animationLayerLocalObj->pauseAndResume(NULL);
        return;
    }
    if(GameManager::sharedGameManager()->isNodeAtPoint(animationLayerLocalObj->getstageLayer(), location)){
        animationLayerLocalObj->onStagePressed(NULL);
        return;
    }
    
    if(GameManager::sharedGameManager()->isNodeAtPoint(animationLayerLocalObj->getmultiBallTopPowerLayer(), location)){
        if( isGameStarted==false || gameIsEnded==true || isBallRecreated==true|| isBallDownToPaddlePos==true || isBallRecreatedAndTouched==true){
            
        }
        else{
            if(isPowerMultiBallVisible==true &&  animationLayerObj->getmultiBallTopPowerSpr()->isVisible()==true){
                animationLayerObj->getmultiBallTopPowerSpr()->setVisible(false);
                isMultiBallCreated=true;
                buildBall("ball.png");
                isMultiBallCreated=true;
                buildBall("ball.png");
                if(ballList.size()>1){
                    unschedule(schedule_selector(GameLayer::deleteMultiBalls));
                    isReleaseBall=true;
                }
                multiBallCounterToDelete=0;
                schedule(schedule_selector(GameLayer::deleteMultiBalls),1);
            }
        }
    }
    if(isReleaseBall==true){
        isReleaseBall=false;
        isBallDownToPaddlePos=false;
        b2Vec2 v;
        int random = arc4random()%2;
        if(random==0)
            v = b2Vec2(30,30);
        else
            v = b2Vec2(-30,30);
        ball->ballBody->ApplyForceToCenter(v);
        ball->ballBody->SetLinearVelocity(v);
    }
    
    if (_mouseJoint != NULL)
        return;
    
    b2Vec2 locationWorld = b2Vec2(location.x / PTM_RATIO ,location.y / PTM_RATIO);
    if(myPaddle==NULL)
        return;
    
    if (paddleLayer->boundingBox().containsPoint(location) || myPaddle->boundingBox().containsPoint(location)) {
        
        b2MouseJointDef md;
        md.bodyA = groundBody;
        md.bodyB = myPaddleBody;
        md.target = locationWorld;
        md.collideConnected = true;
        md.maxForce = 5000.0f* myPaddleBody->GetMass();
        if(_mouseJoint != NULL)
        {
            world->DestroyJoint(_mouseJoint);
            _mouseJoint = NULL;
        }
        _mouseJoint = (b2MouseJoint *) world->CreateJoint(&md);
        myPaddleBody->SetAwake(true);
    }
}

void GameLayer::ccTouchesMoved(CCSet *pTouches, CCEvent* event) {
    
    CCTouch* myTouch = (CCTouch*) pTouches->anyObject();
    CCPoint location = myTouch->getLocationInView();
    location = CCDirector::sharedDirector()->convertToGL(location);
    
    b2Vec2 locationWorld = b2Vec2(location.x / PTM_RATIO,
                                  location.y / PTM_RATIO);
    if (_mouseJoint==NULL)
        return;
    _mouseJoint->SetTarget(locationWorld);
    
}

void GameLayer::ccTouchesEnded(CCSet *pTouches, CCEvent* event) {
    if (_mouseJoint != NULL){
        world->DestroyJoint(_mouseJoint);
        _mouseJoint = NULL;
        isTouchedOnPlayerPaddle= false;
        if(isBallRecreated==true)
            isBallRecreatedAndTouched=true;
    }
}

void GameLayer::disablePaddleMovement()
{
    if(isTouchedOnPlayerPaddle == false){
        b2Vec2 v = b2Vec2(0, 0);
        myPaddleBody->SetLinearVelocity(v);
    }
}
void GameLayer::ccTouchesCancelled(CCSet *pTouches, CCEvent *pEvent)
{
    if (_mouseJoint != NULL){
        world->DestroyJoint(_mouseJoint);
        
        // Have the layer run the action and call this same method again
        CCDelayTime * delayAction = CCDelayTime::create(5);
        CCCallFunc * callFunc = CCCallFunc::create( this, callfunc_selector( GameLayer::disablePaddleMovement ));
        this -> runAction( CCSequence::createWithTwoActions( delayAction, callFunc ) );
        //            scheduleOnce(schedule_selector(GameLayer::disablePaddleMovement),2);
        _mouseJoint = NULL;
    }
}


#pragma  mark   ******************........POWER IMPLEMENTATION......*********************
void GameLayer::powerCreationAndDropDown(CCPoint localitemPos,TargetPlatform device) {
    CCPoint itemPos = localitemPos;
    if (!gameIsEnded && !gameIsPaused) {
        isPowerToGenerate = false;
        
        if(m_Bricks.size()<=35 && isPowerMultiBallVisible==false){
            isPowerMultiBallVisible=true;
            animationLayerObj->getmultiBallTopPowerSpr()->setVisible(true);
            CCActionInterval *action1 = CCFadeIn::create(5);
            CCActionInterval *action = CCFadeOut::create(1);
            animationLayerObj->getmultiBallTopPowerSpr()->runAction(CCRepeatForever::create(CCSequence::create(action1,CCDelayTime::create(1),action,CCDelayTime::create(0.3),NULL)));
        }
        
        
        if(isSpeedMax==true || isAutoPlayModeActive==true||  isPaddleTimerEnable==true||  isSlowDownSpeed==true|| isAddGun==true||isRepeatMultiBall==true){
            return;
        }
        
        
        int powerType = arc4random()%11;
        
        if(isCoinToGenerate==true){
            isCoinToGenerate=false;
            powerType=11;
        }
        
        if(lastPowerInt==powerType)
            powerType = arc4random()%11;
        if(lastPowerInt==powerType)
            powerType = arc4random()%11;
        //        //Dont delete
        int levelLocal = powerCreationCurrentLevel;
        if(levelLocal>=40 && powerType==10)
            powerType=8;
        if(levelLocal<=8 && powerType==9)
            powerType=3;
        
        if((lastPowerInt==7 && powerType==3)){
            isMagnetAndMultiBallEnable=true;
        }
        
        lastPowerInt= powerType;
        item=NULL;
        
        switch (powerType) {
            case 0:{
                if(isPowerFlagLargePaddleSet==false){
                    isPowerFlagLargePaddleSetCount++;
                    if(isPowerFlagLargePaddleSetCount==2)
                        isPowerFlagLargePaddleSet=true;
                    item = EnlargeItem::createEnlargeItem();
                }
            }
                break;
            case 1:{
                if(isPowerFlagShortPaddleSet==false){
                    isPowerFlagShortPaddleSetCount++;
                    if(isPowerFlagShortPaddleSetCount==2)
                        
                        isPowerFlagShortPaddleSet=true;
                    item = ShortenItem::createShortenItem();
                }
            }
                break;
            case 2:{
                if(isPowerFlagReverseBallSet==false){
                    isPowerFlagReverseBallSetCount++;
                    if(isPowerFlagReverseBallSetCount==2)
                        isPowerFlagReverseBallSet=true;
                    item = ReverseYItem::createReverseYItem();
                }
            }
                break;
            case 3:{
                if(isPowerFlagMultiBallSet==false){
                    isRepeatMultiBall=true;
                    isPowerFlagMultiBallSetCount++;
                    if(isPowerFlagMultiBallSetCount==2)
                        isPowerFlagMultiBallSet=true;
                    item = DoubleItem::createDoubleItem();
                }
            }
                break;
            case 4:{
                if(isPowerFlagAutoPlaySet==false){
                    isPowerFlagAutoPlaySetCount++;
                    if(isPowerFlagAutoPlaySetCount==2)
                        isPowerFlagAutoPlaySet=true;
                    item = AutoPlayItem::createAutoPlayItem();
                }
            }
                break;
            case 5:{
                if(isPowerFlagBonusPointsSet==false){
                    isPowerFlagBonusPointsSetCount++;
                    if(isPowerFlagBonusPointsSetCount==2)
                        isPowerFlagBonusPointsSet=true;
                    item = BonusScore::createBonusScore();
                }
            }
                break;
            case 6:{
                if(isPowerFlagBonusLifeSet==false){
                    isPowerFlagBonusLifeSet=true;
                    CCString *str1;
                    CCString *str2;
                    str1 = (CCString*)powerBonusLifeArr->objectAtIndex(0);
                    str2=(CCString*)powerBonusLifeArr->objectAtIndex(1);
                    if(levelLocal==str1->intValue() || levelLocal==str2->intValue())
                        item = BonusLife::createBonusLife();
                }
            }
                break;
            case 7:{
                if(isPowerFlagMagnetSet==false){
                    if(isMagnetRepeat==false)
                    {
                        isMagnetRepeat=true;
                        isPowerFlagMagnetSetCount++;
                        if(isPowerFlagMagnetSetCount==2)
                            isPowerFlagMagnetSet=true;
                        item = MagnetItem::createMagnetItem();
                    }
                }
            }
                break;
            case 8:{
                if(isPowerFlagBulletSet==false){
                    isPowerFlagBulletSetCount++;
                    if(isPowerFlagBulletSetCount==2)
                        isPowerFlagBulletSet=true;
                    item = BulletItem::createBulletItem();
                }
            }
                break;
            case 9:{
                if(isPowerFlagSlowBallSet==false){
                    isPowerFlagSlowBallSetCount++;
                    if(isPowerFlagSlowBallSetCount==2)
                        isPowerFlagSlowBallSet=true;
                    item = SlowDownSpeed::createSlowDownSpeed();
                }
            }
                break;
            case 10:{
                if(isPowerFlagFastBallSet==false){
                    isPowerFlagFastBallSetCount++;
                    if(isPowerFlagFastBallSetCount==2)
                        isPowerFlagFastBallSet=true;
                    item = FastSpeed::createFastSpeed();
                }
            }
                break;
            case 11:
                item = CoinItem::createCoinItem();
                break;
            default:
                break;
        }
        if(item==NULL)
            return;
        item->setPosition(localitemPos);
        bricksLayer->addChild(item);
        CCMoveTo* action2;
        if(powerType==11)
        {
            CCPoint itemPosToDrop1 = localitemPos;
            CCAnimation*	pAnimation = CCAnimation::createWithSpriteFrames (coinAnimateArray, 0.04f );
            CCAnimate *animate = CCAnimate::create ( pAnimation );
            item->runAction ( CCSequence::createWithTwoActions(animate, animate->reverse()));
            action2 = CCMoveTo::create(1.0f,ccp(itemPosToDrop1.x,myPaddle->getPositionY()-200));
        }
        else{
            CCPoint itemPosToDrop1 = localitemPos;
            action2 = CCMoveTo::create(4.f,ccp(itemPosToDrop1.x,myPaddle->getPositionY()-200));
        }
        
        item->runAction(action2);
        itemList.push_back(item);
    }
}

void GameLayer::powerUpItems()
{
    
    list<Item *> localitemList = itemList;
    std::list<Item*>::iterator it;
    for( it = localitemList.begin(); it != localitemList.end(); it++ )
    {
        if( (*it) != NULL && localitemList.size() != 0)
        {
            
            if (myPaddle->boundingBox().intersectsRect((*it)->boundingBox())) {
                
                string localfunction = (*it)->getFunction();

                if (!localitemList.empty() && localitemList.size() > 0){
                    (*it)->removeFromParentAndCleanup(true);
                    it = localitemList.erase(it);
                }
                addPoints(20);
                if(localfunction == "CoinDetecttion"){
                    addCoins(1);
                    SoundManager::sharedSoundManager()->playSoundEffect("Coin Pickup 2 Final.wav", false);
                    break;
                }
                else{
                    playPowerUpSound();
                }
                if (localfunction == "enlarge") {
                    if(isPaddleTimerEnable==true){paddleCounter=0;
                        unschedule(schedule_selector(GameLayer::paddleTimer));}
                    isPaddleTimerEnable=true;
                    enlargePaddle();
                    break;
                } if (localfunction == "autoPlay") {
                    autostrip->setVisible(true);
                    autoPlayGame();
                    if(isAutoPlayModeActive==true)
                    {
                        isAutoPlayModeActive=false; unschedule(schedule_selector(GameLayer::autoPlayTimer));}
                    isAutoPlayModeActive=true;
                    autoPlayModeCounter=0;
                    powerCounterInt=3;
                    schedule(schedule_selector(GameLayer::autoPlayTimer),1);
                    break;
                }  if (localfunction == "reverseY") {
                    reverseBallYVelocity();
                    break;
                }  if (localfunction == "double") {
                    if(ballList.size()>=2){
                        unschedule(schedule_selector(GameLayer::deleteMultiBalls));
                    }
                    multiBallCounterToDelete=0;
                    schedule(schedule_selector(GameLayer::deleteMultiBalls),1);
                    isRepeatMultiBall=false;
                    isMultiBallCreated=true;
                    if(multiBallCount==2){
                        buildBall("ball.png");
                        buildBall("ball.png");
                    }
                    if(multiBallCount==3){
                        buildBall("ball.png");
                        buildBall("ball.png");
                        buildBall("ball.png");
                    }
                    else {
                        buildBall("ball.png");
                    }
                    break;
                }  if (localfunction == "shorten") {
                    if(isPaddleTimerEnable==true){paddleCounter=0;
                        unschedule(schedule_selector(GameLayer::paddleTimer));}
                    isPaddleTimerEnable=true;
                    shortenPaddle();
                    break;
                }  if (localfunction == "bonus") {
                    bonusBallLife();
                    break;
                }  if (localfunction == "magnet") {
                    isMagnetEnabled=true;
                    isMagnetRepeat=false;
                    break;
                }
                if(localfunction=="slowBallSpeed"){
                    isSlowDownSpeed=true;
                    slowDownBallSpeed();
                    break;
                }
                if (localfunction == "bullet") {
                    if(leftBulletList.size()!=0 && rightBulletList.size()!=0){
                        bulletCount=0;
                        isAddGun =false;
                        unschedule(schedule_selector(GameLayer::bulletCounterTrace));
                        unschedule(schedule_selector(GameLayer::bulletTimer));
                    }
                    bulletCount=0;
                    isAddGun =true;
                    myPaddleImage(myPaddle, isAddGun,myPaddle->getLengthState(),isBlackColorBackground);
                    if(detectedDevice==kTargetAndroid)
                        schedule(schedule_selector(GameLayer::bulletCounterTrace),0.5f);
                    else
                        schedule(schedule_selector(GameLayer::bulletCounterTrace),0.3f);
                    schedule(schedule_selector(GameLayer::bulletTimer),1.0f);
                    break;
                }
                
                if (localfunction == "BonusPoints") {
                    addPoints(100);
                    break;
                }
                if(localfunction == "fastSpeed")
                {
                    if(isSpeedMax==true){
                        unschedule(schedule_selector(GameLayer::disableMaxSpeed));
                    }
                    isSpeedMax=true;
                    speedMaxCounter=0;
                    powerCounterInt=3;
                    schedule(schedule_selector(GameLayer::disableMaxSpeed),1);
                    break;
                }
                
            }
            
            else if((*it)->getPositionY() < myPaddle->getPositionY()-100) {
                if (!localitemList.empty() && localitemList.size() > 0)
                {
                    (*it)->removeFromParentAndCleanup(true);
                    it = localitemList.erase(it);
                }
            }
            //            if(animationLayerObj->getmenuLayer()->isVisible()==true || gameIsEnded==true)
            //            {
            //                if (!localitemList.empty() && localitemList.size() > 0)
            //                {
            //                    (*it)->removeFromParentAndCleanup(true);
            //                    it = localitemList.erase(it);
            //                }
            //            }
            
        }
    }
    itemList.swap(localitemList);
    
}

void GameLayer::enlargePaddle() {
    MyPaddle *myPaddleLocalStorage = myPaddle;
    if (myPaddleLocalStorage->getLengthState() == 0) {
        ;
        myPaddleLocalStorage->setLengthState(Paddle::normalPaddle);
        
    } else if (myPaddleLocalStorage->getLengthState() == 1) {
        ;
        myPaddleLocalStorage->setLengthState(Paddle::longPaddle);
    }
    buildMyPaddleWithNewPaddle(myPaddleLocalStorage);
    schedule(schedule_selector(GameLayer::paddleTimer),1);
}

void GameLayer::shortenPaddle() {
    
    MyPaddle *myPaddleLocalStorage = myPaddle;
    if (myPaddleLocalStorage->getLengthState() == 1) {
        ;
        myPaddleLocalStorage->setLengthState(Paddle::shortPaddle);
        
    } else if (myPaddleLocalStorage->getLengthState() == 2) {
        ;
        myPaddleLocalStorage->setLengthState(Paddle::normalPaddle);
    }
    buildMyPaddleWithNewPaddle(myPaddleLocalStorage);
    schedule(schedule_selector(GameLayer::paddleTimer),1);
}

void GameLayer::paddleTimer() {
    if(paddleCounter==largepaddleTotalTimer){
        unschedule(schedule_selector(GameLayer::paddleTimer));
        paddleCounter=0;
        isPaddleTimerEnable=false;
        myPaddle->setLengthState(Paddle::normalPaddle);
        if(isBlackColorBackground==true)
            buildMyPaddle("myPaddleNight.png");
        else
            buildMyPaddle(paddleName);
    }
    else{
        paddleCounter++;
    }
}

void GameLayer::freezeBall() {
    list<Ball *>::iterator it;
    for( it = ballList.begin(); it != ballList.end(); it++ )
    {
        if( (*it) != NULL){
            b2Vec2 bv = (*it)->ballBody->GetLinearVelocity();
            if(bv.x>30)
            {
                (*it)->ballBody->SetLinearVelocity(b2Vec2(10,0));
            }
            CCPoint ballPosition = (*it)->getPosition();
            
            float bs = bv.x * bv.x + bv.y * bv.y*1;
            if( bv.Length()>30)
                (*it)->ballBody->SetLinearDamping(1.0f);
            else
                (*it)->ballBody->SetLinearDamping(0.0f);
            if (bs > 2000) {
                b2Vec2 *bf = new b2Vec2(-bv.x * 10, -bv.y * 10);
                (*it)->ballBody->ApplyForceToCenter(*bf);
            }
            b2Vec2 gv = (*it)->ballBody->GetLinearVelocity();
            float gs = gv.x * gv.x + gv.y * gv.y*0.5;
            /*if (gs < 9000)*/
            if(gs<1000){
                b2Vec2 *gf = new b2Vec2(gv.x, gv.y);
                (*it)->ballBody->ApplyForceToCenter(*gf);
            }
            
            /*else if (bs > 12000)*/
            else if (bs > 2000){
                b2Vec2 *gf = new b2Vec2(-gv.x, -gv.y);
                
                (*it)->ballBody->ApplyForceToCenter(*gf);
            }
            
            if(bv.x==0.000000){
                bv.x = -sqrt(bs - bv.y * bv.y);
            }
            else if (bv.x<=-0.09234567){
                bv.x = -sqrt(bs - bv.y * bv.y);
            }
            else if (bv.y<=-0.09234567){
                bv.y = -sqrt(bs) / 2;
            }
            if (bv.y * bv.y < bs / 4) {
                if (bv.y < 0) {
                    bv.y = -sqrt(bs) / 2;
                } else {
                    bv.y = sqrt(bs) / 2;
                }
                
                if (bv.x < 0) {
                    bv.x = -sqrt(bs - bv.y * bv.y);
                } else {
                    bv.x = sqrt(bs - bv.y * bv.y);
                }
            }
            (*it)->ballBody->SetLinearVelocity(bv);
        }
    }
}

void GameLayer::bonusBallLife() {
    if(bonusLifeCount>0)
        playerLifeCount = playerLifeCount+bonusLifeCount;
    
    int lifeOfPlayer =playerLifeCount;
    lifeOfPlayer++;
    globalPlayerLifeCountLabel->setString(CCString::createWithFormat("%d",lifeOfPlayer)->getCString());
    playerLifeCount=lifeOfPlayer;
}

void GameLayer::slowDownBallSpeed() {
    CCCallFunc * callFunc = CCCallFunc::create( this, callfunc_selector( GameLayer::ballSetNormalSpeed));
    this->runAction( CCSequence::createWithTwoActions(CCDelayTime::create(6.2),callFunc));
}
void GameLayer::ballSetNormalSpeed(){
    isSlowDownSpeed=false;
}

void GameLayer::autoPlayTimer() {
    
    if(autoPlayModeCounter==autoPlayTotalTimer)
    {
        unschedule(schedule_selector(GameLayer::autoPlayTimer));
        isAutoPlayModeActive=false;
        autostrip->setVisible(false);
        if(bottomFixture!=NULL){
            groundBody->DestroyFixture(bottomFixture);
            bottomFixture=NULL;
        }
        autoPlayModeCounter=0;
        powerCounterInt=0;
        
    }
    else{
        autoPlayModeCounter++;
    }
}

void GameLayer::autoPlayGame() {
    if (isAutoPlayModeActive==true)
        return;
    //=============== Bottom to restict game over ====================================
    groundBox.Set(b2Vec2(0,0), b2Vec2(winSize.width/PTM_RATIO, 0));
    bottomFixture = groundBody->CreateFixture(&groundBoxDef);
}

void GameLayer::reverseBallYVelocity() {
    list<Ball *>::iterator it ;
    for( it = ballList.begin(); it != ballList.end(); it++ )
    {
        if( (*it) != NULL )
        {
            b2Vec2 v = (*it)->ballBody->GetLinearVelocity();
            v.y = -v.y;
            (*it)->ballBody->SetLinearVelocity(v);
        }
    }
}

void GameLayer::deleteMultiBalls()
{
    int localmultiBallCounterToDelete = multiBallCounterToDelete;
    localmultiBallCounterToDelete++;
    
    if(localmultiBallCounterToDelete>=15)
        isdeleteMultiBalls=true;
    else if(localmultiBallCounterToDelete==9){
        list<Ball *> localballList;
        localballList = ballList;
        if(localballList.size()>2){
            applyBlinkEffectOnBall(localballList.front());
            ballList.swap(localballList);
        }
    }
    
    else if (localmultiBallCounterToDelete==12){
        list<Ball *> localballList;
        localballList = ballList;
        if (localballList.size() > 1) {
            list<Ball *>::iterator it;
            for( it = localballList.begin(); it != localballList.end(); it--){
                if ((*it)!=NULL){
                    if(localballList.size()==1)
                        break;
                    else if(localballList.size()>2){
                        (*it)->UnInit(world);
                        it = localballList.erase(it);
                    }
                    else
                        applyBlinkEffectOnBall((*it));
                }
            }
            ballList.swap(localballList);
        }
    }
    
    multiBallCounterToDelete=localmultiBallCounterToDelete;
    if(isdeleteMultiBalls==true){
        unschedule(schedule_selector(GameLayer::deleteMultiBalls));
        removeAllBalls();
        removeAllBalls();
        removeAllBalls();
        isdeleteMultiBalls=false;
        multiBallCounterToDelete=0;
    }
}
void GameLayer::applyBlinkEffectOnBall(cocos2d::CCSprite *spr)
{
    if(spr==NULL)
        return;
    CCActionInterval *action1 = CCFadeIn::create(0.1);
    CCActionInterval *action = CCFadeOut::create(0.1);
    CCDelayTime *delay= CCDelayTime::create(0.1);
    CCSequence *Seq = CCSequence::create(action1,delay,action,delay,action1,delay,action,delay,action1,delay,action,delay,action1,delay,action,delay,action1,delay,action1,delay,action,delay,action1,NULL);
    spr->runAction(Seq);
    return;
}



void GameLayer::gameOver()
{
    if(isAddGun==true)
    {
        list<Bullet *>::iterator it;
        for( it = leftBulletList.begin(); it != leftBulletList.end(); it++)
        {
            if ((*it) != NULL){
                (*it)->setVisible(false);
                (*it)->removeBulletFromParent();
                it = leftBulletList.erase( it );
            }
        }
        
        list<Bullet *>::iterator rightBullet = rightBulletList.begin();
        for( rightBullet = rightBulletList.begin(); rightBullet != rightBulletList.end(); rightBullet++)
        {
            if ((*rightBullet) != NULL){
                (*rightBullet)->setVisible(false);
                (*rightBullet)->removeBulletFromParent();
                rightBullet = rightBulletList.erase( rightBullet );
            }
        }
    }
    
    removeGun();
    
    if(isAllBricksRemoved==true)
    {
        if (!m_Bricks.empty() && m_Bricks.size() > 0) {
            vector<Brick *>::iterator it;
            for( it = m_Bricks.begin(); it != m_Bricks.end(); it++)
            {
                if ((*it)!=NULL)
                {
                    (*it)->UnInit();
                    it = m_Bricks.erase(it);
                }
            }
        }
        m_Bricks.clear();
    }
    if(isPlayerLifeZero == true || isDestroyedGameOverPaddle==true)
    {
        removeAllBalls();
        int indexing = 1;
        if (!m_Bricks.empty() && m_Bricks.size() > 0) {
            vector<Brick *>::iterator it;
            for( it = m_Bricks.begin(); it != m_Bricks.end(); it++){
                if ((*it)!=NULL){
                    indexing++;
                    (*it)->UnInit();
                    it = m_Bricks.erase(it);
                }
            }
        }
        m_Bricks.clear();
        ballList.clear();
        gameIsPaused=true;
        gameIsEnded = true;
    }
    
    if (!itemList.empty() && itemList.size() > 0) {
        list<Item *>::iterator it;
        for( it = itemList.begin(); it != itemList.end(); it++) {
            if ((*it) != NULL){
                (*it)->removeFromParentAndCleanup(true);
                it = itemList.erase(it);
            }
        }
    }
}

#pragma mark  ****************REMOVE BULLET AND BRICK AND CHECK IF THE GAME OVER***********************************
void GameLayer::removeBullet(cocos2d::CCSize windoSize,TargetPlatform platform)
{
    if(isTimeToRemoveGun==true){
        CCSize windorSize = windoSize;
        TargetPlatform deviceDetected = platform;
        CCLayer *localbricksLayer = bricksLayer;
        CCSize windowSize = winSize;
        // REMOVE  BULLETS AND BRICK FROM THE POSTITIONS
        CCSprite *brickSpr;
        
        std::list<Bullet*>::iterator removeLeftPosbullet;
        for( removeLeftPosbullet = leftBulletList.begin(); removeLeftPosbullet != leftBulletList.end(); removeLeftPosbullet++ )
        {
            if( (*removeLeftPosbullet) != NULL)
            {
                std::vector<Brick*>::iterator BrickPos = m_Bricks.begin();
                while(BrickPos != m_Bricks.end())
                {
                    brickSpr =(*BrickPos)->brickSprites;
                    if(brickSpr->boundingBox().intersectsRect((*removeLeftPosbullet)->bullet_Sprite->boundingBox()))
                    {
                        addPoints(10);
                        
                        //Yellow Brick
                        if(brickSpr->getTag()==7){
                            if(windorSize.width >=1024){
                                brickExplodeAtPos(brickSpr->getPosition(), localbricksLayer, "brickYellowParticle.plist",1);}
                            else{
                                brickExplodeAtPos(brickSpr->getPosition(), localbricksLayer, "brickYellowParticleiPod.plist",1);}
                        }
                        //Orange Brick
                        if(brickSpr->getTag()==6 || brickSpr->getTag()==22222)
                        {
                            if(windorSize.width >=1024){
                                brickExplodeAtPos(brickSpr->getPosition(), localbricksLayer, "brickOrangeParticle.plist",1);}
                            else{
                                brickExplodeAtPos(brickSpr->getPosition(), localbricksLayer, "brickOrangeParticleiPod.plist",1);}
                        }
                        
                        //Black Brick
                        if(brickSpr->getTag()==8 || brickSpr->getTag()==9  || brickSpr->getTag()==33333) {
                            if(windorSize.width >=1024){
                                brickExplodeAtPos(brickSpr->getPosition(), localbricksLayer, "brickBlackParticle.plist",1);}
                            else{
                                brickExplodeAtPos(brickSpr->getPosition(), localbricksLayer, "brickBlackParticleiPod.plist",1);}
                        }
                        if(brickSpr==NULL)
                            break;
                        playBrickBrokenSound(deviceDetected,windorSize);
                        (*BrickPos)->UnInit();
                        BrickPos = m_Bricks.erase( BrickPos );
                        BrickPos = m_Bricks.end();
                        (*removeLeftPosbullet)->removeBulletFromParent();
                        removeLeftPosbullet=leftBulletList.erase(removeLeftPosbullet);
                        break;
                    }
                    else{
                        ++BrickPos;
                    }
                }
            }
        }
        
        std::list<Bullet*>::iterator removeRightPosBullet;
        for( removeRightPosBullet = rightBulletList.begin(); removeRightPosBullet != rightBulletList.end(); removeRightPosBullet++ )
        {
            if( (*removeRightPosBullet) != NULL)
            {
                std::vector<Brick*>::iterator BrickPos = m_Bricks.begin();
                while(BrickPos != m_Bricks.end())
                {
                    brickSpr =(*BrickPos)->brickSprites;
                    if(brickSpr->boundingBox().intersectsRect((*removeRightPosBullet)->bullet_Sprite->boundingBox()))
                    {
                        addPoints(10);
                        //Yellow Brick
                        if(brickSpr->getTag()==7){
                            if(windorSize.width >=1024){
                                brickExplodeAtPos(brickSpr->getPosition(), localbricksLayer, "brickYellowParticle.plist",1);}
                            else{
                                brickExplodeAtPos(brickSpr->getPosition(), localbricksLayer, "brickYellowParticleiPod.plist",1);}
                        }
                        //Orange Brick
                        if(brickSpr->getTag()==6 || brickSpr->getTag()==22222)
                        {
                            if(windorSize.width >=1024){
                                brickExplodeAtPos(brickSpr->getPosition(), localbricksLayer, "brickOrangeParticle.plist",1);}
                            else{
                                brickExplodeAtPos(brickSpr->getPosition(), localbricksLayer, "brickOrangeParticleiPod.plist",1);}
                        }
                        
                        //Black Brick
                        if(brickSpr->getTag()==8 || brickSpr->getTag()==9  || brickSpr->getTag()==33333) {
                            if(windorSize.width >=1024){
                                brickExplodeAtPos(brickSpr->getPosition(), localbricksLayer, "brickBlackParticle.plist",1);}
                            else{
                                brickExplodeAtPos(brickSpr->getPosition(), localbricksLayer, "brickBlackParticleiPod.plist",1);}
                        }
                        if(brickSpr==NULL)
                            break;
                        playBrickBrokenSound(deviceDetected,windorSize);
                        (*BrickPos)->UnInit();
                        BrickPos = m_Bricks.erase( BrickPos );
                        BrickPos = m_Bricks.end();
                        (*removeRightPosBullet)->removeBulletFromParent();
                        removeRightPosBullet= rightBulletList.erase(removeRightPosBullet);
                        break;
                    }
                    else{
                        ++BrickPos;
                    }
                }
            }
        }
        
        
        //Check if the bullet is not hitting any brick.
        std::list<Bullet*>::iterator leftBulletPos = leftBulletList.begin();
        while(leftBulletPos != leftBulletList.end())
        {
            if( (*leftBulletPos)->bullet_Sprite->getPositionY() >= windorSize.height-50){
                (*leftBulletPos)->setVisible(false);
                (*leftBulletPos)->removeBulletFromParent();
                leftBulletPos = leftBulletList.erase( leftBulletPos );
                break;
            }
            else{
                ++leftBulletPos;
            }
        }
        
        std::list<Bullet*>::iterator rightBulletPos = rightBulletList.begin();
        while(rightBulletPos != rightBulletList.end())
        {
            if( (*rightBulletPos)->bullet_Sprite->getPositionY() >= windorSize.height-50){
                (*rightBulletPos)->setVisible(false);
                (*rightBulletPos)->removeBulletFromParent();
                rightBulletPos = rightBulletList.erase(rightBulletPos);
                break;
            }
            else{
                ++rightBulletPos;
            }
        }
    }
    
    
    //REMOVE THE BRICKS ON BALL TOUCH
    std::vector<b2Body*>::iterator removePos;
    for( removePos = toRemove.begin(); removePos != toRemove.end(); removePos++ )
    {
        if( (*removePos) != NULL && toRemove.size() != 0)
        {
            std::vector<Brick*>::iterator brickPosForIntersect = m_Bricks.begin();
            while(brickPosForIntersect != m_Bricks.end()){
                if( (*brickPosForIntersect)->brickBody == (*removePos) )
                {
                    (*brickPosForIntersect)->UnInit();
                    brickPosForIntersect = m_Bricks.erase( brickPosForIntersect );
                    
                }
                else{
                    ++brickPosForIntersect;
                }
            }
        }
    }
}

void GameLayer::checkIfGameOver()
{
    //================ Game won condition check ======================
    if( m_Bricks.size() ==0 && isgameover==false){
        isgameover=true;
        isAllBricksRemoved=true;
        gameOver();
        gameIsEnded = true;
    }
    
    //    if (!gameIsEnded) {
    b2World *localworld = world;
    list<Ball *>::iterator it;
    for( it = ballList.begin(); it != ballList.end(); it++){
        if ((*it)!=NULL){
            if ((*it)->getPosition().y < -(*it)->getHeight() / 2) {
                (*it)->UnInit(localworld);
                it = ballList.erase(it);
            }
        }
    }
    
    if(isAutoPlayModeActive==true)
        return;
    if(isBallDownToPaddlePos==true)
        return;
    if(isdeleteMultiBalls==true)
        return;
    
    if(ballList.size()==0 ){
        gameOver();
        isballHitPaddleInMagnet=false;
        isMagnetEnabled=false;
        isBallRecreated=false;
        isBallRecreatedAndTouched=false;
        isBallDownToPaddlePos=true;
        if(isPaddleTimerEnable==true){
            isPaddleTimerEnable=false;
            unschedule(schedule_selector(GameLayer::paddleTimer));
        }
        if(isSpeedMax==true){
            speedMaxCounter=0;
            powerCounterInt=0;
            isSpeedMax=false;
            unschedule(schedule_selector(GameLayer::disableMaxSpeed));
        }
        if(isAutoPlayModeActive==true){
            unschedule(schedule_selector(GameLayer::autoPlayTimer));
            isAutoPlayModeActive=false;
            autostrip->setVisible(false);
            autoPlayModeCounter=0;
            if(bottomFixture!=NULL){
                groundBody->DestroyFixture(bottomFixture);
                bottomFixture=NULL;}
        }
        list<Item *>::iterator it;
        for( it = itemList.begin(); it != itemList.end(); it++ ){
            if (!itemList.empty() && itemList.size() > 0){
                (*it)->removeFromParentAndCleanup(true);
                it = itemList.erase(it);
            }
        }
        int localplayerLifeCount = playerLifeCount;
        localplayerLifeCount--;
        globalPlayerLifeCountLabel->setString(CCString::createWithFormat("%d",localplayerLifeCount)->getCString());
        
        if(localplayerLifeCount>=1){
            myPaddleBody->SetActive(false);
            CCScaleTo *myPaddleScale = CCScaleTo::create(1, 0);
            myPaddle->runAction(myPaddleScale);
            CCCallFunc * callFunc = CCCallFunc::create( this, callfunc_selector( GameLayer::decrementPlayerLife) );
            this->runAction( CCSequence::createWithTwoActions(CCDelayTime::create(1.2),callFunc));
        }
        else if(localplayerLifeCount==0){
            isgameover=true;
            gameIsEnded = true;
            isPlayerLifeZero = true;
            gameWonRestartConfirm();
            animationLayerObj->getmultiBallTopPowerSpr()->setVisible(false);
        }
        playerLifeCount=localplayerLifeCount;
        SoundManager::sharedSoundManager()->playSoundEffect("Boll Drop 2 Final.wav", false);
        if (myPaddle->getLengthState() == 0){
            myPaddle->setLengthState(Paddle::normalPaddle);
        }else if(myPaddle->getLengthState() == 2){
            myPaddle->setLengthState(Paddle::normalPaddle);
        }
    }
    //    }
}

#pragma mark *************** PLAYER LIFE ****************

void GameLayer::decrementPlayerLife()
{
    myPaddle->setScale(1);
    myPaddleBody->SetActive(true);
    buildMyPaddleWithNewPaddle(myPaddle);
    buildBall("ball.png");
    isBallDownToPaddlePos=false;
}


#pragma mark **********************TIMERS FOR THE PADDLE,  BULLET,  BALL***********************
void GameLayer::bulletCounterTrace() {
    string bulletSpr = "bullet.png";
    buildBullet(bulletSpr);
}

void GameLayer::bulletTimer()
{
    if(bulletCount>=butlletTotalTimer){
        removeGun();
    }
    else{
        bulletCount++;
    }
}

void GameLayer::avoidUnwantedSituation(int level) {
    int localLevel = level;
    int localdeviceResolutionInt = deviceResolutionForLocal;
    if(isballHitPaddleInMagnet==true)
        return;
    list<Ball *>::iterator it;
    if(isSlowDownSpeed==true){
        localLevel=1;
    }
    
    bool localisSpeedMax = isSpeedMax;
    
    if(localisSpeedMax==true){
        localLevel=localLevel+20;
        if(localLevel>=56)
            localLevel=56;
    }
    b2Vec2 bv,gv;
    float gs,bs;
    float32 speed;
    b2Body *localballBody;
    
    for( it = ballList.begin(); it != ballList.end(); it++ )
    {
        if( (*it) != NULL){
            localballBody=(*it)->ballBody;
            
            bv = localballBody->GetLinearVelocity();
            gv = localballBody->GetLinearVelocity();
            
            speed = bv.Length();
            
            if(localdeviceResolutionInt==1 || localdeviceResolutionInt==6){
                if(speed<20)
                    speed=20;
                if(localLevel>43)
                {
                    bs = bv.x * bv.x + bv.y * bv.y*randomValueBetween(1.5, 2);
                    gs = gv.x * gv.x + gv.y * gv.y*randomValueBetween(0.5, 1);
                }
                else
                {
                    bs = bv.x * bv.x + bv.y * bv.y*randomValueBetween(1.5, 2.5);
                    gs = gv.x * gv.x + gv.y * gv.y*randomValueBetween(0.5, 1.5);
                }
                
                if (bs > maxAverageSpeedIpad[localLevel]/1.4) {
                    b2Vec2 *bf = new b2Vec2(-bv.x * 20, -bv.y * 20);
                    localballBody->ApplyForceToCenter(*bf);
                }
                if(speed<maxSpeedIpad[localLevel]/1.4){
                    localballBody->SetLinearDamping(0.0f);
                    bs = bv.x * bv.x + bv.y * bv.y*15;
                }
                else if (speed>maxSpeedIpad[localLevel]/1.4){
                    localballBody->SetLinearDamping(1.0f);
                }
            }
            
            else{
                bs = bv.x * bv.x + bv.y * bv.y*1.5;
                gs = gv.x * gv.x + gv.y * gv.y*1.5;
                if (bs > maxAverageSpeedIpod[localLevel]/3) {
                    b2Vec2 *bf ;
                    bf = new b2Vec2(-bv.x * 10, -bv.y * 10);
                    localballBody->ApplyForceToCenter(*bf);
                }
                if(speed<maxSpeedIpod[localLevel]/3)
                {
                    localballBody->SetLinearDamping(0.0f);
                    if(localLevel<9)
                        bs = bv.x * bv.x + bv.y * bv.y*10;
                    else
                        bs = bv.x * bv.x + bv.y * bv.y*15;
                }
                else if (speed>maxSpeedIpod[localLevel]/3)
                {
                    localballBody->SetLinearDamping(1.0f);
                }
            }
            if(localdeviceResolutionInt==1 || localdeviceResolutionInt==6){
                if(bs<1200){
                    b2Vec2 *bf = new b2Vec2(bv.x * 15, bv.y * 15);
                    localballBody->ApplyForceToCenter(*bf);
                }
                if(gs<1200){
                    b2Vec2 *bf = new b2Vec2(bv.x * 15, bv.y * 15);
                    localballBody->ApplyForceToCenter(*bf);
                }
                
            }
            else{
                if(bs<900){
                    b2Vec2 *bf ;
                    if(localLevel<9)
                        bf = new b2Vec2(bv.x * 4, bv.y * 4);
                    else
                        bf = new b2Vec2(bv.x * 10, bv.y * 10);
                    localballBody->ApplyForceToCenter(*bf);
                }
                if(gs<900){
                    b2Vec2 *bf ;
                    if(localLevel<9)
                        bf = new b2Vec2(bv.x * 4, bv.y * 4);
                    else
                        bf = new b2Vec2(bv.x * 10, bv.y * 10);
                    localballBody->ApplyForceToCenter(*bf);
                }
            }
            
            if(bv.x==0 && bv.y==0){
                b2Vec2 v;
                int random = arc4random()%2;
                if(random==0)
                    v = b2Vec2(30,30);
                else
                    v = b2Vec2(-30,30);
                ball->ballBody->ApplyForceToCenter(v);
                ball->ballBody->SetLinearVelocity(v);
            }
            if(!(localdeviceResolutionInt==1 || localdeviceResolutionInt==6)){
                if(bv.x==0.000000){
                    bv.x = -sqrt(bs - bv.y * bv.y);
                }
                else if (bv.x<=-0.09234567){
                    bv.x = -sqrt(bs - bv.y * bv.y);
                }
                else if (bv.y<=-0.09234567){
                    bv.y = -sqrt(bs) / 2;
                }
            }else
            {
                if (bv.x<0){
                    bv.x = -sqrt(bs - bv.y * bv.y);
                }
                else if (bv.y<0){
                    bv.y = -sqrt(bs) / 2;
                }
            }
            
            if (bv.y * bv.y < bs / 4) {
                if (bv.y < 0) {
                    bv.y = -sqrt(bs) / 2;
                } else {
                    bv.y = sqrt(bs) / 2;
                }
                if (bv.x < 0) {
                    bv.x = -sqrt(bs - bv.y * bv.y);
                } else {
                    bv.x = sqrt(bs - bv.y * bv.y);
                }
            }
            localballBody->SetLinearVelocity(bv);
        }
    }
}

void GameLayer::timerForPower(){
    if(counterForPower == randomValueForPowerToAppear){
        counterForPower = 0;
        randomValueForPowerToAppear = powerCreateDuration[powerCreationCurrentLevel];
        isPowerToGenerate = true;
    }
    else{
        counterForPower++;
    }
}

void GameLayer::enableCoinToDrop()
{
    if(coinCountDownStart==coinTimer){
        coinCountDownStart=0;
        coinTimer = 5;
        isCoinToGenerate=true;
    }else{
        coinCountDownStart++;
    }
}

void GameLayer::disableMaxSpeed()
{
    if(speedMaxCounter==6){
        unschedule(schedule_selector(GameLayer::disableMaxSpeed));
        speedMaxCounter=0;
        powerCounterInt=0;
        isSpeedMax=false;
    }else{
        speedMaxCounter++;
    }
}
void GameLayer::updateGunPosition(TargetPlatform determinePlatform,int localLevel){
    //================Move left and right bullet from player paddle towards Bricks===========
    
    if(isTimeToRemoveGun==true){
        TargetPlatform localDeterminePlatform = determinePlatform;
        
        b2Vec2 myPaddlePos = myPaddleBody->GetPosition();
        if (localDeterminePlatform == kTargetIphone)
        {
            list<Bullet *>::iterator it;
            for( it = leftBulletList.begin(); it != leftBulletList.end(); it++ )
            {
                if( (*it) != NULL )
                {
                    b2Vec2 force = b2Vec2(0 ,0.45);
                    (*it)->getBulletBody()->ApplyLinearImpulse(force,myPaddlePos);
                }
            }
            
            list<Bullet *>::iterator iterating;
            for( iterating = rightBulletList.begin(); iterating != rightBulletList.end(); iterating++ )
            {
                if( (*iterating) != NULL ){
                    b2Vec2 force = b2Vec2(0 ,0.8);
                    (*iterating)->getBulletBody()->ApplyLinearImpulse(force,myPaddlePos);
                }
            }
        }
        else
        {
            list<Bullet *>::iterator it;
            for( it = leftBulletList.begin(); it != leftBulletList.end(); it++ )
            {
                if( (*it) != NULL )
                {
                    b2Vec2 force = b2Vec2(0 ,1.5);
                    (*it)->getBulletBody()->ApplyLinearImpulse(force, myPaddlePos);
                }
            }
            
            list<Bullet *>::iterator iterating;
            for( iterating = rightBulletList.begin(); iterating != rightBulletList.end(); iterating++ )
            {
                if( (*iterating) != NULL )
                {
                    b2Vec2 force = b2Vec2(0 ,1.5);
                    (*iterating)->getBulletBody()->ApplyLinearImpulse(force,myPaddlePos);
                }
            }
        }
    }
}

void GameLayer::gameWon(){
    removeAllBalls();
    
    counterForPower=0;bulletCount=0;gameStarterCounter=4;reverseCounting=10;autoPlayModeCounter=0;coinCountDownStart=0;powerCounterInt=0;paddleCounter=0;brickBreakSound=0;
    
    isPowerFlagBulletSet=false,isPowerFlagMultiBallSet=false,isPowerFlagAutoPlaySet=false,isPowerFlagBonusPointsSet=false,isPowerFlagLargePaddleSet=false,isPowerFlagSlowBallSet=false,isPowerFlagMagnetSet=false,isPowerFlagReverseBallSet=false,isPowerFlagShortPaddleSet=false,isPowerFlagFastBallSet=false;isPowerFlagBonusLifeSet=false,isSpeedMax=false,isAutoPlayModeActive=false,isPaddleTimerEnable=false,isSlowDownSpeed=false,isAddGun=false,isRepeatMultiBall=false,isMagnetRepeat=false;isGameWonForNextLevel=false;
    
    isPowerFlagBulletSetCount=0,isPowerFlagMultiBallSetCount=0,isPowerFlagAutoPlaySetCount=0,isPowerFlagBonusPointsSetCount=0,isPowerFlagLargePaddleSetCount=0,isPowerFlagSlowBallSetCount=0,isPowerFlagMagnetSetCount=0,isPowerFlagReverseBallSetCount=0,isPowerFlagShortPaddleSetCount=0,isPowerFlagFastBallSetCount=0;
    
    ball=NULL;myPaddleBody = NULL;mypaddleSpritFrame = NULL;
    leftBulletList.clear();rightBulletList.clear();itemList.clear();ballList.clear();itemList.clear();m_Bricks.clear();hardBricks.clear();
    mAnimationManager=NULL;_mouseJoint=NULL;groundBody=NULL;bottomFixture=NULL;ballFixture=NULL;
    myPaddleFixture=NULL;m_pFireEmitter=NULL;isAddGun=false;isTouchedOnPlayerPaddle=false;paddleLayer=NULL;isPaddleCreatedNotFirstTime=false; gameIsPaused=false;gameIsEnded=false;isSlowDownSpeed=false;isAllBricksRemoved=false;isPlayerLifeZero=false;animationLable=NULL;countingLable=NULL;isGameEnded=false;isDestroyedGameOverPaddle=false;isCallOnce=false;m_contactListener=NULL;world=NULL;isgameover=false;isContingEnded=false;isAutoPlayModeActive=false;autostrip=NULL;isBallRecreated=false;isGameStarted=false;isTouchedOnPaddlefront=false;isMagnetEnabled=false;isCoinToGenerate=false;isballHitPaddleInMagnet=false;isBallRecreatedAndTouched=false;isReleaseBall=false;isBallDownToPaddlePos=false;isMultiBallCreated=false;isPaddleTimerEnable=false;isPowerMultiBallVisible=false;isMagnetAndMultiBallEnable=false;isTimeToRemoveGun=false;
    CC_SAFE_RELEASE_NULL(coinAnimateArray);
    
    if(playerLifeCount<3)
        playerLifeCount=3;
    if(deviceResolutionInt==1 ||deviceResolutionInt==6)
        CCSpriteFrameCache::sharedSpriteFrameCache()->removeSpriteFramesFromFile("CoinAnimationIpad.plist");
    else
        CCSpriteFrameCache::sharedSpriteFrameCache()->removeSpriteFramesFromFile("CoinAnimationIpod.plist");
    
    initAllObjects();
}

void GameLayer::removeGun(){
    if(isAddGun==true){
        bulletCount=0;
        isAddGun = false;
        myPaddleImage(myPaddle, isAddGun,myPaddle->getLengthState(),isBlackColorBackground);
        unschedule(schedule_selector(GameLayer::bulletCounterTrace));
        unschedule(schedule_selector(GameLayer::bulletTimer));
    }
}
void GameLayer::gameEndedStartCounting()
{
    if(isGameEnded==false){
        //        //=============== Bottom to restict game over ====================================
        //        groundBox.Set(b2Vec2(0,0), b2Vec2(winSize.width/PTM_RATIO, 0));
        //        bottomFixture = groundBody->CreateFixture(&groundBoxDef);
        isGameEnded=true;
        isContingEnded=false;
        
        autostrip->setVisible(false);
        topLineSpr->setVisible(true);
    }
}

#pragma mark *************OnTransitionEnter*********************
GameLayer::~GameLayer()
{
}

void GameLayer::onExitTransitionDidStart()
{
    CCLayer::onExitTransitionDidStart();
}

void GameLayer::onEnterTransitionDidFinish() {
    CCLayer::onEnterTransitionDidFinish();
}

void GameLayer::createBallAtPaddlePos(cocos2d::CCPoint paddlePos)
{
    if (ballFixture != NULL) {
        myPaddleBody->DestroyFixture(myPaddleFixture);
        myPaddleFixture=NULL;
    }
    b2PolygonShape myPaddleShape;
    
    CCSprite *spr = myPaddleImage(myPaddle, isAddGun, myPaddle->getLengthState(),isBlackColorBackground);
    myPaddleShape.SetAsBox((spr->getContentSize().width)/ 2/PTM_RATIO,
                           spr->getContentSize().height/ 2/PTM_RATIO);
    //=============================my paddle fixture========================
    b2FixtureDef myPaddleFixtureDef;
    myPaddleFixtureDef.shape = &myPaddleShape;
    myPaddleFixtureDef.density = 1.0f;
    myPaddleFixtureDef.friction = 0.0f;
    myPaddleFixtureDef.restitution = 0.0f;
    myPaddleFixture = myPaddleBody->CreateFixture(&myPaddleFixtureDef);
    isPaddleCreatedNotFirstTime = true;
    
}
void GameLayer::buildMyPaddleWithNewPaddle(MyPaddle *myPaddleSpr)
{
    if (myPaddleSpr->getLengthState() == 2) {
        if(isBlackColorBackground==true)
            buildMyPaddle("myLongPaddleNight.png");
        else
            buildMyPaddle(longPaddleType);
    }
    else if (myPaddleSpr->getLengthState() == 0) {
        if(isBlackColorBackground==true)
            buildMyPaddle("myPaddleNight.png");
        else
            buildMyPaddle(paddleName);
    }
    else if (myPaddleSpr->getLengthState() == 1) {
        if(isBlackColorBackground==true)
            buildMyPaddle("myShortPaddleNight.png");
        else
            buildMyPaddle(shortPaddleType);
    }
}

#pragma mark animationManaget
void GameLayer::setAnimationManager(cocos2d::extension::CCBAnimationManager *animationManager)
{
    if (animationManager)
    {
        CC_SAFE_RELEASE_NULL(mAnimationManager);
        mAnimationManager = animationManager;
        CC_SAFE_RETAIN(animationManager);
    }
}
void GameLayer::powerCounterScheduler()
{
    buildBall("ball.png");
    schedule(schedule_selector(GameLayer::updateAtEachSeconds));
    schedule(schedule_selector(GameLayer::checkIfGameOver));
    schedule(schedule_selector(GameLayer::gameWonRestartConfirm));
    isballHitPaddleInMagnet=true;
}

void GameLayer::playBrickBrokenSound(TargetPlatform deviceDetectedIs,CCSize windorSize)
{
    CCSize windowSize = windorSize;
    SoundManager::sharedSoundManager()->stopSoundEffect(brickBreakSound);
    
    brickBreakSound =SoundManager::sharedSoundManager()->playSoundEffect("Brick_Sound 6.wav", false);
    
}

void GameLayer::playPowerUpSound()
{
    SoundManager::sharedSoundManager()->stopSoundEffect(brickBreakSound);
    
    switch (arc4random()%3) {
        case 0:
            SoundManager::sharedSoundManager()->playSoundEffect("Power Up 1.wav", false);
            break;
        case 1:
            SoundManager::sharedSoundManager()->playSoundEffect("Power Up 2.wav", false);
            break;
        case 2:
            SoundManager::sharedSoundManager()->playSoundEffect("Power Up 3.wav", false);
            break;
        default:
            break;
    }
    
}

void GameLayer::removeAllBalls()
{
    list<Ball *> localballList;
    localballList = ballList;
    
    if(isdeleteMultiBalls==true){
        if (localballList.size() > 1) {
            b2World *localworld = world;
            list<Ball *>::iterator it;
            for( it = localballList.begin(); it != localballList.end(); it++){
                if(localballList.size()==1)
                    break;
                if ((*it)!=NULL){
                    (*it)->UnInit(localworld);
                    it = localballList.erase(it);
                }
            }
        }
    }
    else
    {
        if (localballList.size() > 0) {
            b2World *localworld = world;
            list<Ball *>::iterator it;
            for( it = localballList.begin(); it != localballList.end(); it++){
                if ((*it)!=NULL){
                    (*it)->UnInit(localworld);
                    it = localballList.erase(it);
                }
            }
        }
    }
    ballList.swap(localballList);
    
}

float GameLayer::randomValueBetween(float low , float high){
    return rand() % (int)high + (int)low;
}


void GameLayer::gameWonAndOverLabelDisplay()
{
    if(m_Bricks.size()==0){
    }
    else{
        animationLayerObj->gameOverDown(NULL);
    }
}

int GameLayer::randomNumberBetween(int min, int max)
{
    return min + rand() % (max - min);
}
void GameLayer::onRestartGameLayer(){
    
    releaseLayerMemory();
    removeAllBalls();
    removeAllBalls();
    
    this->gameWon();
    
    animationLayerObj->getmenuLayer()->setVisible(false);
    animationLayerObj->setisPausePressed(false);
    isGameStarted=false;
    return;
}

void GameLayer::save_ChallengeCurrentUserScore(CCDictionary *user)
{
    GameManager::sharedGameManager()->getchallenge_existing_usersArr()->addObject(user);
    CCDictionary *root = CCDictionary::create();
    root->setObject(GameManager::sharedGameManager()->getchallenge_existing_usersArr(), "array");
    std::string writablePath_temp = CCFileUtils::sharedFileUtils()->getWritablePath();
    std::string fullPath = writablePath_temp + "ChallengeScoreList.plist";
    CCLOG("ScoreList fullPath %s",fullPath.c_str());
    if(root->writeToFile(fullPath.c_str()))
    {
    }
}
CCArray*  GameLayer::get_Challenge_userslist()
{
    CCArray *arr_users;
    std::string writablePath_temp = CCFileUtils::sharedFileUtils()->getWritablePath();
    std::string fullPath = writablePath_temp + "ChallengeScoreList.plist";
    if(CCFileUtils::sharedFileUtils()->isFileExist(fullPath))
    {
        CCDictionary *dict=CCDictionary::createWithContentsOfFile(fullPath.c_str());
        dict->retain();
        arr_users=(CCArray*)dict->objectForKey("array");
    }
    else
    {
        arr_users=CCArray::createWithContentsOfFileThreadSafe("ChallengeScoreList.plist");
        CCDictionary *root = CCDictionary::create();
        root->setObject(arr_users, "array");
        if(root->writeToFile(fullPath.c_str()))
        {
            //CCLog("see the plist file at %s", fullPath.c_str());
        }
        else
        {
            //CCLog("write plist file failed");
        }
        CCLog("external file path = %s", fullPath.c_str());
    }
    return arr_users;
}


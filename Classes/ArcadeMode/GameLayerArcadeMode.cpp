//
//  GameLayerArcadeMode.cpp
//  Bricks
//
//  Created by Victor on 12/22/14.
//
//

#include "../ArcadeMode/GameLayerArcadeMode.h"
#include "SimpleAudioEngine.h"
#include "../GameManager/GameManager.h"
#include "../Layers/MenuLayer.h"
#include "../Layers/MenuLayerLoader.h"
#include "../ArcadeMode/GameLayerArcadeModeLoader.h"
#include "../GameManager/Constant.h"
#include "../SoundManager/SoundManager.h"
#include "HoldOnModel.h"
using namespace cocos2d;
using namespace CocosDenshion;
using namespace std;

Ball* GameLayerArcadeMode::ballArcadeMode;
MyPaddle* GameLayerArcadeMode::myPaddleArcadeMode;

GameLayerArcadeMode::GameLayerArcadeMode():mAnimationManager(NULL),_mouseJoint(NULL),world(NULL),groundBody(NULL),bottomFixture(NULL),ballFixture(NULL),myPaddleFixture(NULL),m_pFireEmitter(NULL),navigationLayer(NULL),backGroundSpr(NULL),animationLayerArcadeModeObj(NULL),isAddGun(false),isTouchedOnPlayerPaddle(false),paddleLayer(NULL),isPaddleCreatedNotFirstTime(false),gameIsPaused(false),gameIsEnded(false),isSlowDownSpeed(false),isAllBricksRemoved(false),isPlayerLifeZero(false),animationLable(NULL),shapeBackLayer(NULL),countingLable(NULL),isGameEnded(false),isDestroyedGameOverPaddle(false),isCallOnce(false),isgameover(false),isContingEnded(false),isAutoPlayModeActive(false),autostrip(NULL),isBallRecreated(false),isGameStarted(false),globalPlayerLifeCountLabel(NULL),isTouchedOnPaddlefront(false),isMagnetEnabled(false),isballHitPaddleInMagnet(false),isBallRecreatedAndTouched(false),isReleaseBall(false),isBallDownToPaddlePos(false),kachcheLabel(NULL),isSpeedMax(false),powerCountLabel(NULL),isMultiBallCreated(false),isPaddleTimerEnable(false),stageSpr(NULL),scoreSpr(NULL),ballTopSpr(NULL),isInstructionLabelVisible(false),isBlackColorBackground(true),isPowerMultiBallVisible(false),kachcheLabelGameWon(NULL),instructionLabel(NULL),isUserPlayingGame(false),isAddNewBricks(true),isAddedBricksMoreThanOnce(false),isFourtyBrickOnScreen(false)
{
    brickPointsArcadeMode=0;counterForPower=0;scoreLbl=0;playerLifeCount=3;gameStarterCounter=4;reverseCounting=10;autoPlayModeCounter=0;deviceResolutionSize=0;brickLastPosY=0;
    powerCounterInt=0;paddleCounter=0;brickBreakSound=0;powerCreationcurrentLevelArcadeMode=0;isFullBundleRequired=false;lastPowerInt=0;isdeleteMultiBalls=false;isBallBreakFirstBrick=false;isFourtyBrickBelowHalfScreen=false;
    deviceResolutionInt=0;indexCurrentLevel=1;mileStoneCount=0;mileStoneCountForDisplay=0;
    ballArcadeMode=NULL;myPaddleBody = NULL;mypaddleSpritFrame = NULL;isMileStoneCountTwo=false;isMileStoneCountThree=false;isAddedOtherBricks=false;multiBallCount=0;
    itemList.clear();ballList.clear();addOtherBricks.clear();m_Bricks.clear();
}

bool GameLayerArcadeMode::init() {
    if (!CCLayer::init()) {
        return false;
    }
    return true;
}

#pragma mark.....................MAIN   GAME   LOGIC................................
void GameLayerArcadeMode::updateAtEachSeconds(float delta) {
    CCSize windowSize = winSize;
    MyPaddle *myPaddleLocalStorage = myPaddleArcadeMode;
    Ball *ballLocalStorage = ballArcadeMode;
    
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
                    int spriteATag = spriteA->getTag();
                    int spriteBTag =spriteB->getTag();
                    
                    if(spriteATag==29999 && (spriteBTag==9||spriteBTag==8||spriteBTag==6||spriteBTag==33333||spriteBTag==22222||spriteBTag==7)){
                        isgameover=true;
                        gameIsEnded = true;
                        gameOver();
                    }
                    if(spriteATag==0 && spriteBTag==0){
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
                    
                    if(spriteATag==29999 && spriteB->getTag()==0){
                        if(isMagnetEnabled==true){
                            unschedule(schedule_selector(GameLayerArcadeMode::updateAtEachSeconds));
                            unschedule(schedule_selector(GameLayerArcadeMode::checkIfGameOver));
                            unschedule(schedule_selector(GameLayerArcadeMode::gameWonRestartConfirm));
                            
                            isMagnetEnabled=false;
                            removeAllBalls();
                            removeAllBalls();
                            CCCallFunc * callFunc = CCCallFunc::create( this, callfunc_selector( GameLayerArcadeMode::powerCounterScheduler) );
                            this->runAction( CCSequence::createWithTwoActions(CCDelayTime::create(0.01),callFunc));
                            return;
                        }
                    }
                    //Black Color Brick
                    else if (spriteATag == 9 && spriteBTag == 0){
                        dropDownPowerFromPosition(spriteA);
                        addPoints(5);
                        spriteA->setTag(8);
                        
                        spriteA->setColor(ccc3(180,180,180));
                    }
                    //Black Color Brick
                    else if (spriteATag == 8 && spriteBTag == 0)
                    {
                        dropDownPowerFromPosition(spriteA);
                        addPoints(5);
                        spriteA->setTag(33333);
                        spriteA->setColor(ccc3(180,180,180));
                    }
                    //Orange Color Brick
                    else if (spriteATag == 6 && spriteBTag == 0){
                        dropDownPowerFromPosition(spriteA);
                        addPoints(5);
                        spriteA->setTag(22222);
                        spriteA->setColor(ccc3(180,180,180));
                    }
                    
                    //Black Color Brick ============Final Break================
                    else if (spriteATag == 33333 && spriteBTag == 0)
                    {
                        dropDownPowerFromPosition(spriteA);
                        if(windowSize.width >=1024){
                            brickExplodeAtPos(spriteA->getPosition(), bricksLayerArcadeMode, "brickBlackParticle.plist",1);}else{
                                brickExplodeAtPos(spriteA->getPosition(), bricksLayerArcadeMode, "brickBlackParticleiPod.plist",1);
                            }
                        addPoints(15);
                        toRemove.push_back( bodyA);
                        SoundManager::sharedSoundManager()->stopSoundEffect(brickBreakSound);
                        brickBreakSound =SoundManager::sharedSoundManager()->playSoundEffect("Brick_Sound 6.wav", false);
                    }
                    //Orange Color Brick ============Final Break================
                    else if (spriteATag == 22222 && spriteBTag == 0){
                        dropDownPowerFromPosition(spriteA);
                        if(windowSize.width >=1024){
                            brickExplodeAtPos(spriteA->getPosition(), bricksLayerArcadeMode, "brickBlackParticle.plist",1);}else{
                                brickExplodeAtPos(spriteA->getPosition(), bricksLayerArcadeMode, "brickBlackParticleiPod.plist",1);
                            }
                        
                        addPoints(10);
                        toRemove.push_back( bodyA);
                        SoundManager::sharedSoundManager()->stopSoundEffect(brickBreakSound);
                        brickBreakSound =SoundManager::sharedSoundManager()->playSoundEffect("Brick_Sound 6.wav", false);
                    }
                    
                    //Yellow Color Brick ============Final Break================
                    if(spriteATag == 7 && spriteBTag == 0)
                    {
                        dropDownPowerFromPosition(spriteA);
                        if(windowSize.width >=1024){
                            brickExplodeAtPos(spriteA->getPosition(), bricksLayerArcadeMode, "brickYellowParticle.plist",1);}else{
                                brickExplodeAtPos(spriteA->getPosition(), bricksLayerArcadeMode, "brickYellowParticleiPod.plist",1);
                            }
                        
                        addPoints(5);
                        toRemove.push_back( bodyA);
                        SoundManager::sharedSoundManager()->stopSoundEffect(brickBreakSound);
                        brickBreakSound =SoundManager::sharedSoundManager()->playSoundEffect("Brick_Sound 6.wav", false);
                    }
                }
            }
        }
        int localcurrentLevelArcadeMode = currentLevelArcadeMode;
        removeBullet();
        avoidUnwantedSituation(localcurrentLevelArcadeMode);
    }
}


void GameLayerArcadeMode::dropDownPowerFromPosition(CCSprite *brickPos)
{
    CCSprite *localbrickPos =brickPos;
    if(isPowerToGenerate==true){
        powerCreationAndDropDown(localbrickPos->getPosition());
    }
}

void GameLayerArcadeMode::addPoints(int point)
{
    int localPoints = point;
    brickPointsArcadeMode += localPoints;
    
    CCLabelTTF *lblPoints = (CCLabelTTF*)scoreLbl;
    lblPoints->setString(CCString::createWithFormat("%d",brickPointsArcadeMode)->getCString());
    int highestArcadePoints = CCUserDefault::sharedUserDefault()->getIntegerForKey("ARCADEPOINTS");
    if(brickPointsArcadeMode>highestArcadePoints){
        CCUserDefault::sharedUserDefault()->setIntegerForKey("ARCADEPOINTS",brickPointsArcadeMode);
        CCUserDefault::sharedUserDefault()->flush();
        HoldOnModel::shareModel()->setArcadeGameHighestScore(brickPointsArcadeMode);
    }
}


#pragma  mark   COCOSBUILDER INITITIALIZATION
void GameLayerArcadeMode::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    ObjCCalls::hideActivityIndicator();
    
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(GameLayerArcadeMode::onPausePressedFromAnimationLayerArcadeMode), "onPausePressedFromAnimationLayerArcadeMode", NULL);
    
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(GameLayerArcadeMode::onRestartButtonPressed), "onRestartButtonPressed", NULL);
    
    
    detectedDevice = CCApplication::sharedApplication()->getTargetPlatform();
    
    int volume = CCUserDefault::sharedUserDefault()->getIntegerForKey("FORGROUNDVOLUME");
    SoundManager::sharedSoundManager()->setEffectVolume(volume);
    isBlackColorBackground=true;
    deviceResolutionInt = GameManager::sharedGameManager()->get_devise_resolution();
    currentLevelArcadeMode=1;
    instructionLabel->setZOrder(100);
    instructionLabel->setVisible(true);
    initAllObjects();
    autoPlayTotalTimer = 6;
    largepaddleTotalTimer = 6;
    butlletTotalTimer =6;
}

void GameLayerArcadeMode::initAllObjects()
{
    CCLOG("on loaded called");
    winSize = CCDirector::sharedDirector()->getWinSize();
    GameManager::sharedGameManager()->initialize();
    
    //    std::vector<ContactHolder>::iterator pos;
    //    for( pos = m_contactListener->contacts.begin(); pos != m_contactListener->contacts.end(); pos++ )
    //    {
    //        b2Body* bodyA = pos->fixtureA->GetBody();
    //        b2Body* bodyB = pos->fixtureB->GetBody();
    //        if(bodyA!=NULL)
    //        world->DestroyBody(bodyA);
    //        if(bodyB!=NULL)
    //        world->DestroyBody(bodyB);
    //    }
    //
    //    for (b2Body *b = world->GetBodyList(); b; b = b->GetNext()) {
    //        if (b->GetUserData() != NULL) {
    //            CCSprite *sprite = (CCSprite *) b->GetUserData();
    //            if(sprite!=NULL)
    //            sprite->removeFromParentAndCleanup(true);
    //        }
    //    }
    CCSize windowSize = winSize;
    if(addOtherBricks.size() <= 0){
        isAddedOtherBricks=false;
        backGroundSpr=CCSprite::create("bg_3.png");
        backGroundSpr->setPosition(ccp(windowSize.width/2,windowSize.height/2));
        this->addChild(backGroundSpr);
    }
    else{
        isAddedOtherBricks=true;
        if(backGroundSpr!=NULL){
            backGroundSpr->removeFromParentAndCleanup(true);
            backGroundSpr=NULL;
        }
        //-----------------------BackGround Theme Setting---------------------------------
        switch (mileStoneCount) {
            case 1:{
                
                isBlackColorBackground=false;
                backGroundSpr=CCSprite::create("bg_5.png");
                backGroundSpr->setPosition(ccp(windowSize.width/2,windowSize.height/2));
                this->addChild(backGroundSpr);
            }
                break;
            case 2:{
                backGroundSpr=CCSprite::create("bg_6.png");
                backGroundSpr->setPosition(ccp(windowSize.width/2,windowSize.height/2));
                this->addChild(backGroundSpr);
                isBlackColorBackground=false;
            }
                break;
            case 3:{
                backGroundSpr=CCSprite::create("bg_7.png");
                backGroundSpr->setPosition(ccp(windowSize.width/2,windowSize.height/2));
                this->addChild(backGroundSpr);
                isBlackColorBackground=true;
            }
                break;
            case 4:{
                backGroundSpr=CCSprite::create("bg_1.png");
                backGroundSpr->setPosition(ccp(windowSize.width/2,windowSize.height/2));
                this->addChild(backGroundSpr);
                isBlackColorBackground=false;
            }
                break;
                
            case 5:{
                backGroundSpr=CCSprite::create("bg_4.png");
                backGroundSpr->setPosition(ccp(windowSize.width/2,windowSize.height/2));
                this->addChild(backGroundSpr);
                isBlackColorBackground=true;
            }
                
            case 6:{
                backGroundSpr=CCSprite::create("bg_3.png");
                backGroundSpr->setPosition(ccp(windowSize.width/2,windowSize.height/2));
                this->addChild(backGroundSpr);
                isBlackColorBackground=true;
            }
                break;
            case 7:{
                isBlackColorBackground=false;
                backGroundSpr=CCSprite::create("bg_5.png");
                backGroundSpr->setPosition(ccp(windowSize.width/2,windowSize.height/2));
                this->addChild(backGroundSpr);
            }
                break;
                
            default:
                break;
        }
    }
    
    bricksLayerArcadeMode = CCLayer::create();
    bricksLayerArcadeMode->setPosition(ccp(0, (windowSize.height/2)+300));
    this->addChild(bricksLayerArcadeMode);
    
    
    int localdeviceResolutionInt = deviceResolutionInt;
    int playedLevel;
    
    AnimationLayerArcadeMode *localanimationLayerArcadeModeObj = animationLayerArcadeModeObj;
    
    CCLabelTTF *localkachcheLabelGameWon = (CCLabelTTF*)localanimationLayerArcadeModeObj->continueLabelNotUsed;
    CCLabelTTF *lableGameWon = (CCLabelTTF*)localanimationLayerArcadeModeObj->kacheLabelGameWon;
    
    switch (localdeviceResolutionInt){
        case 1:{
            localanimationLayerArcadeModeObj->KaccheGameOverLabel->setFontSize(80);
            lableGameWon->setFontSize(80);
            localkachcheLabelGameWon->setFontSize(80);
            
        }
            break;
        case 2:{
            if (CCDirector::sharedDirector()->getWinSize().height==1136){
                localanimationLayerArcadeModeObj->KaccheGameOverLabel->setFontSize(40);
                lableGameWon->setFontSize(40);
                localkachcheLabelGameWon->setFontSize(40);
                instructionLabel->setFontSize(40);
            }
            else{
                localanimationLayerArcadeModeObj->KaccheGameOverLabel->setFontSize(60);
                lableGameWon->setFontSize(40);
                localkachcheLabelGameWon->setFontSize(40);
                instructionLabel->setFontSize(40);
                
            }
        }
            break;
        case 3:{
            localanimationLayerArcadeModeObj->KaccheGameOverLabel->setFontSize(40);
            lableGameWon->setFontSize(40);
            localkachcheLabelGameWon->setFontSize(40);
            instructionLabel->setFontSize(40);
        }
            break;
        case 4:{
            localanimationLayerArcadeModeObj->KaccheGameOverLabel->setFontSize(40);
            lableGameWon->setFontSize(40);
            localkachcheLabelGameWon->setFontSize(40);
            instructionLabel->setFontSize(40);
        }
            break;
        case 5:{
            localanimationLayerArcadeModeObj->KaccheGameOverLabel->setFontSize(40);
            lableGameWon->setFontSize(40);
            localkachcheLabelGameWon->setFontSize(40);
            instructionLabel->setFontSize(40);
        }
            break;
        case 6:{
            localanimationLayerArcadeModeObj->KaccheGameOverLabel->setFontSize(80);
            lableGameWon->setFontSize(80);
            localkachcheLabelGameWon->setFontSize(80);
            
        }
            break;
        default:
            break;
    }
    
    switch (localdeviceResolutionInt){
        case 1:{
            localanimationLayerArcadeModeObj->KaccheGameOverLabel->setFontSize(90);
        }
            break;
        case 2:{
            if (CCDirector::sharedDirector()->getWinSize().height==1136){
                scoreLbl->setFontSize(30);
                globalPlayerLifeCountLabel->setFontSize(30);
                localanimationLayerArcadeModeObj->KaccheGameOverLabel->setFontSize(40);
            }
            else{
                scoreLbl->setFontSize(30);
                globalPlayerLifeCountLabel->setFontSize(30);
                localanimationLayerArcadeModeObj->KaccheGameOverLabel->setFontSize(60);
            }
        }
            break;
        case 3:{
            scoreLbl->setFontSize(30);
            globalPlayerLifeCountLabel->setFontSize(30);
            localanimationLayerArcadeModeObj->KaccheGameOverLabel->setFontSize(40);
        }
            break;
        case 4:{
            scoreLbl->setFontSize(30);
            globalPlayerLifeCountLabel->setFontSize(30);
            localanimationLayerArcadeModeObj->KaccheGameOverLabel->setFontSize(40);
        }
            break;
        case 5:{
            backGroundSpr->setScale(1.4);
            scoreLbl->setFontSize(30);
            globalPlayerLifeCountLabel->setFontSize(30);
            localanimationLayerArcadeModeObj->KaccheGameOverLabel->setFontSize(40);
        }
            break;
        case 6:{
            localanimationLayerArcadeModeObj->KaccheGameOverLabel->setFontSize(90);
        }
            break;
        default:
            break;
    }
    
    switch (localdeviceResolutionInt)
    {
        case 1:
            lableGameWon->setFontSize(90);
            localkachcheLabelGameWon->setFontSize(90);
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136){
                lableGameWon->setFontSize(40);
                localkachcheLabelGameWon->setFontSize(40);
            }
            else{
                lableGameWon->setFontSize(60);
                localkachcheLabelGameWon->setFontSize(60);
            }
        }
            break;
        case 3:
            lableGameWon->setFontSize(40);
            localkachcheLabelGameWon->setFontSize(40);
            break;
        case 4:
            lableGameWon->setFontSize(40);
            localkachcheLabelGameWon->setFontSize(40);
            break;
        case 5:
            lableGameWon->setFontSize(40);
            localkachcheLabelGameWon->setFontSize(40);
            break;
        case 6:
            lableGameWon->setFontSize(90);
            localkachcheLabelGameWon->setFontSize(90);
            break;
            
        default:
            break;
    }
    
    
    b2Vec2 gravity(0.0f, 0.0f);
    world = new b2World(gravity);
    navigationLayer->setZOrder(200);
    
    m_contactListener = new ContactListener();
    world->SetContactListener(m_contactListener);
    
    randomValueForPowerToAppear = powerCreateDuration[playedLevel];
    localanimationLayerArcadeModeObj->pauseMenuItemButton->setEnabled(false);
    localanimationLayerArcadeModeObj->stageMenuItemButton->setEnabled(false);
    localanimationLayerArcadeModeObj->menuLayer->setVisible(false);
    
    buildBrickPaddle();
    
    scoreLbl->setFontName("fonts/Zekton-Bold.ttf");
    globalPlayerLifeCountLabel->setFontName("fonts/Zekton-Bold.ttf");
    
    globalPlayerLifeCountLabel->setString(CCString::createWithFormat("%d",playerLifeCount)->getCString());
    
    autostrip = CCSprite::create("autostrip.png");
    autostrip->setPosition(ccp(windowSize.width/2, 10));
    bricksLayerArcadeMode->addChild(autostrip);
    autostrip->setVisible(false);
    
    string brickOrange = "brickOrange.png";
    
    animationLable = CCLabelTTF::create("", "fonts/ZektonRg-Regular.ttf", 60);
    bricksLayerArcadeMode->addChild(animationLable);
    
    countingLable = CCLabelTTF::create("", "fonts/Zekton-Bold.ttf", 80);
    this->addChild(countingLable);
    countingLable->setZOrder(500);
    
    setKeypadEnabled(true);
    setTouchPriority(kCCMenuHandlerPriority + 1);
    setTouchEnabled(true);
    if(!(localanimationLayerArcadeModeObj->isMileStoneAcieved==true))
        localanimationLayerArcadeModeObj->menuLayer->setVisible(false);
    
    //Add the previous Points
    CCLabelTTF *lblPoints = (CCLabelTTF*)scoreLbl;
    lblPoints->setString(CCString::createWithFormat("%d",brickPointsArcadeMode)->getCString());
    buildGround();
    normalPaddleSprArcadeMode = CCSprite::create("myPaddleNight.png");
    bricksLayerArcadeMode->addChild(normalPaddleSprArcadeMode);
    normalPaddleSprArcadeMode->setVisible(false);
    longPaddleSprArcadeMode = CCSprite::create("myLongPaddleNight.png");
    bricksLayerArcadeMode->addChild(longPaddleSprArcadeMode);
    longPaddleSprArcadeMode->setVisible(false);
    shortPaddleSprArcadeMode = CCSprite::create("myShortPaddleNight.png");
    bricksLayerArcadeMode->addChild(shortPaddleSprArcadeMode);
    shortPaddleSprArcadeMode->setVisible(false);
    
    normalPaddleSpr = CCSprite::create("myPaddle.png");
    longPaddleSpr = CCSprite::create("myLongPaddle.png");
    shortPaddleSpr = CCSprite::create("myShortPaddle.png");
    
    bricksLayerArcadeMode->addChild(normalPaddleSpr);
    normalPaddleSpr->setVisible(false);
    
    bricksLayerArcadeMode->addChild(longPaddleSpr);
    longPaddleSpr->setVisible(false);
    
    bricksLayerArcadeMode->addChild(shortPaddleSpr);
    shortPaddleSpr->setVisible(false);
    
    if(isAddedOtherBricks==true){
        isPaddleCreatedNotFirstTime=false;
        buildMyPaddle("myPaddleNight.png");
        buildMyPaddleWithNewPaddle(myPaddleArcadeMode);
        myPaddleArcadeMode->setPosition(paddleLastPos);
        unschedule(schedule_selector(GameLayerArcadeMode::updateAtEachSeconds));
        unschedule(schedule_selector(GameLayerArcadeMode::powerUpItems));
        unschedule(schedule_selector(GameLayerArcadeMode::timerForPower));
        unschedule(schedule_selector(GameLayerArcadeMode::checkIfGameOver));
        unschedule(schedule_selector(GameLayerArcadeMode::moveElement));
    }
    else{
        buildMyPaddle("myPaddleNight.png");
        buildBall("ball.png");
    }
    
    gameOverStrip = CCSprite::create("autostrip.png");
    gameOverStrip->setPosition(ccp(windowSize.width/2, myPaddleArcadeMode->getPositionY()));
    bricksLayerArcadeMode->addChild(gameOverStrip);
    gameOverStrip->setVisible(false);
    
    restrictPaddleMovement();
    
    if(isAddedOtherBricks==false){
        CCCallFunc * callFunc = CCCallFunc::create( this, callfunc_selector( GameLayerArcadeMode::brickFallDown) );
        bricksLayerArcadeMode->runAction( CCSequence::createWithTwoActions(CCMoveTo::create(2, ccp(0, 0)),callFunc));
    }else{
        CCCallFunc * callFunc = CCCallFunc::create( this, callfunc_selector( GameLayerArcadeMode::brickFallDown) );
        bricksLayerArcadeMode->runAction( CCSequence::createWithTwoActions(CCMoveTo::create(0.7, ccp(0, 0)),callFunc));
    }
    
}

SEL_CallFuncN GameLayerArcadeMode::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
    return NULL;
}

SEL_MenuHandler GameLayerArcadeMode::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName){
    
    
    return NULL;
}

SEL_CCControlHandler GameLayerArcadeMode::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName){
    return NULL;
}

bool GameLayerArcadeMode::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "scoreLbl",CCLabelTTF*, this->scoreLbl);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "kachcheLabel",CCLabelTTF *, this->kachcheLabel);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "kachcheLabelGameWon",CCLabelTTF *, this->kachcheLabelGameWon);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "powerCountLabel",CCLabelTTF *, this->powerCountLabel);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "instructionLabel",CCLabelTTF *, this->instructionLabel);
    
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "navigationLayer",CCLayerColor *, this->navigationLayer);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "shapeBackLayer",CCLayerColor *, this->shapeBackLayer);
    
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "stageSpr",CCSprite *, this->stageSpr);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "scoreSpr",CCSprite *, this->scoreSpr);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "ballTopSpr",CCSprite *, this->ballTopSpr);
    
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "animationLayerArcadeModeObj",AnimationLayerArcadeMode *, this->animationLayerArcadeModeObj);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "globalPlayerLifeCountLabel",CCLabelTTF *, this->globalPlayerLifeCountLabel);
    return false;
}

bool GameLayerArcadeMode::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    bool bRet = false;
    return bRet;
}

void GameLayerArcadeMode::brickFallDown()
{
    this->resumeSchedulerAndActions();
    this->startGame();
}

#pragma mark   BUILD     BALL,    PADDLE,   GROUND,    BALL,  BRICKS
void GameLayerArcadeMode::startGame()
{
    kachcheLabelGameWon->setVisible(false);
    kachcheLabel->setVisible(false);
    kachcheLabelGameWon->setFontName("fonts/Zekton-Bold.ttf");
    kachcheLabel->setFontName("fonts/Zekton-Bold.ttf");
    isGameStarted=true;
    if(isAddedOtherBricks==false){
        instructionLabel->setZOrder(100);
        instructionLabel->setVisible(true);
        isInstructionLabelVisible=true;
    }
    AnimationLayerArcadeMode *localanimationLayerArcadeModeObj = animationLayerArcadeModeObj;
    localanimationLayerArcadeModeObj->pauseMenuItemButton->setEnabled(true);
    localanimationLayerArcadeModeObj->stageMenuItemButton->setEnabled(true);
    
    if(isAddedOtherBricks==true)
    {
        localanimationLayerArcadeModeObj->isPausePressed=false;
        isballHitPaddleInMagnet=false;
        isBallRecreatedAndTouched=false;
        isMultiBallCreated=true;
        this->buildBall("ball.png");
        ballArcadeMode->ballSpr->setPosition(ballLastPos);
        ballArcadeMode->setPosition(ballLastPos);
        schedule(schedule_selector(GameLayerArcadeMode::updateAtEachSeconds));
        schedule(schedule_selector(GameLayerArcadeMode::powerUpItems));
        schedule(schedule_selector(GameLayerArcadeMode::timerForPower),3);
        schedule(schedule_selector(GameLayerArcadeMode::checkIfGameOver));
        schedule(schedule_selector(GameLayerArcadeMode::moveElement),10);
    }
}

void GameLayerArcadeMode::buildGround() {
    
    // Create edges around the entire screen
    CCSize windowSize = winSize;
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0,0);
    groundBody = world->CreateBody(&groundBodyDef);
    groundBoxDef.shape = &groundBox;
    
    groundBox.Set(b2Vec2(0,0), b2Vec2(0, (windowSize.height/PTM_RATIO)-2));
    groundBody->CreateFixture(&groundBoxDef);
    
    //=============== Bottom to restict game over ====================================
    //    groundBox.Set(b2Vec2(0,0), b2Vec2(winSize.width/PTM_RATIO, 0));
    //    bottomFixture = groundBody->CreateFixture(&groundBoxDef);
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
void GameLayerArcadeMode::callMeToArrangeNextBricks(){
    buildBrickPaddle();
}


void GameLayerArcadeMode::buildBall(std::string ballType) {
    CCLOG("build Ball called");
    Ball *ballocalStore = ballArcadeMode;
    ballocalStore = Ball::createBall("ball.png");
    ballocalStore->setTag(0);
    MyPaddle *localmyPaddleArcadeMode = myPaddleArcadeMode;
    
    float mypaddleXPos = localmyPaddleArcadeMode->getPositionX();
    float mypaddleYPos = localmyPaddleArcadeMode->getPositionY();
    
    switch (deviceResolutionInt)
    {
        case 1:
            ballocalStore->setPosition(ccp(mypaddleXPos,mypaddleYPos+50));
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136){
                ballocalStore->setPosition(ccp(mypaddleXPos,mypaddleYPos+25));
            }
            else{
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
    //    ballBodyDef.bullet = true;
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
        if(isAddedOtherBricks==true)
            multiBallCount=0;
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
            v = b2Vec2(20,20);
        else
            v = b2Vec2(-20,20);
        
        ballocalStore->ballBody->ApplyForceToCenter(v);
        ballocalStore->ballBody->SetLinearVelocity(v);
    }
    else{
        isTouchedOnPaddlefront=true;
        ballocalStore->ballBody->SetActive(true);
        isBallRecreated=true;
        isBallRecreatedAndTouched=false;
    }
    ballArcadeMode = ballocalStore;
    ballList.push_back(ballArcadeMode);
    
}

void GameLayerArcadeMode::buildMyPaddle(std::string myPaddleName) {
    if (myPaddleFixture != NULL) {
        myPaddleBody->DestroyFixture(myPaddleFixture);
        myPaddleFixture=NULL;
    }
    
    if(isPaddleCreatedNotFirstTime==false){
        myPaddleArcadeMode = MyPaddle::createMyPaddle(myPaddleName.c_str());
        this->addChild(myPaddleArcadeMode);
        myPaddleArcadeMode->setTag(29999);
        
        CCSize windowSize = winSize;
        switch (deviceResolutionInt)
        {
            case 1:
                myPaddleArcadeMode->setPosition(ccp(windowSize.width / 2, myPaddleArcadeMode->getTextureRect().getMidY() + 120));
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136){
                    myPaddleArcadeMode->setPosition(ccp(windowSize.width / 2, myPaddleArcadeMode->getTextureRect().getMidY() + 105));
                    
                }
                else{
                    myPaddleArcadeMode->setPosition(ccp(windowSize.width / 2, myPaddleArcadeMode->getTextureRect().getMidY() + 90));
                }
            }
                break;
            case 3:
                myPaddleArcadeMode->setPosition(ccp(windowSize.width / 2, myPaddleArcadeMode->getTextureRect().getMidY() + 80));
                break;
            case 4:
                myPaddleArcadeMode->setPosition(ccp(windowSize.width / 2, myPaddleArcadeMode->getTextureRect().getMidY() + 70));
                break;
            case 5:
                myPaddleArcadeMode->setPosition(ccp(windowSize.width / 2, myPaddleArcadeMode->getTextureRect().getMidY() + 105));
                break;
            case 6:
                myPaddleArcadeMode->setPosition(ccp(windowSize.width / 2, myPaddleArcadeMode->getTextureRect().getMidY() + 120));
                break;
            default:
                break;
        }
        
        //my paddle body
        myPaddleBodyDef.type = b2_dynamicBody;
        myPaddleBodyDef.userData = myPaddleArcadeMode;
        myPaddleBodyDef.position.Set(myPaddleArcadeMode->getPosition().x / PTM_RATIO,
                                     myPaddleArcadeMode->getPosition().y / PTM_RATIO);
        
        myPaddleBody = (world->CreateBody(&myPaddleBodyDef));
        
        paddleLayer = CCLayer::create();
        paddleLayer->setPosition(myPaddleArcadeMode->getPosition());
        paddleLayer->setContentSize(CCSizeMake(myPaddleArcadeMode->getContentSize().width+450, myPaddleArcadeMode->getContentSize().height+500));
        bricksLayerArcadeMode->addChild(paddleLayer);
    }
    b2PolygonShape myPaddleShape;
    
    int paddleLenght=myPaddleArcadeMode->getLengthState();
    CCSprite *spr = myPaddleImageArcadeMode(myPaddleArcadeMode, isAddGun, paddleLenght, isBlackColorBackground);
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
void GameLayerArcadeMode::buildBrickPaddle() {
    int localLevel=currentLevelArcadeMode;
    
    if(localLevel==14){
        unschedule(schedule_selector(GameLayerArcadeMode::updateAtEachSeconds));
        unschedule(schedule_selector(GameLayerArcadeMode::powerUpItems));
        unschedule(schedule_selector(GameLayerArcadeMode::timerForPower));
        unschedule(schedule_selector(GameLayerArcadeMode::checkIfGameOver));
        unschedule(schedule_selector(GameLayerArcadeMode::moveElement));
        
        ballLastPos = ballArcadeMode->ballSpr->getPosition();
        paddleLastPos = myPaddleArcadeMode->getPosition();
        
        int localLevel=currentLevelArcadeMode;
        localLevel=1;
        int localmileStoneCount = mileStoneCount;
        currentLevelArcadeMode=localLevel;
        powerCreationcurrentLevelArcadeMode=localLevel;
        
        autostrip->setVisible(false);
        isGameStarted=false;
        
        list<Ball *>::iterator it;
        for( it = ballList.begin(); it != ballList.end(); it++){
            if ((*it)!=NULL){
                (*it)->UnInit(world);
                it = ballList.erase(it);
            }
        }
        for( it = ballList.begin(); it != ballList.end(); it++){
            if ((*it)!=NULL){
                (*it)->UnInit(world);
                it = ballList.erase(it);
            }
        }
        
        myPaddleArcadeMode->removeFromParentAndCleanup(true);
        if (!itemList.empty() && itemList.size() > 0) {
            list<Item *>::iterator it;
            for( it = itemList.begin(); it != itemList.end(); it++) {
                if ((*it) != NULL){
                    (*it)->pauseSchedulerAndActions();
                }
            }
        }
        myPaddleFixture=NULL;myPaddleBody=NULL;bottomFixture=NULL;
        m_Bricks.clear();ballList.clear();
        itemList.clear();
        if(playerLifeCount<=0)
            playerLifeCount=1;
        countingLable->removeFromParentAndCleanup(true);
        bricksLayerArcadeMode->removeAllChildren();
        isAddGun=false,isTouchedOnPlayerPaddle=false,isPaddleCreatedNotFirstTime=false,gameIsPaused=false,gameIsEnded=false,isSlowDownSpeed=false,isAllBricksRemoved=false,isPlayerLifeZero=false,isGameEnded=false,isDestroyedGameOverPaddle=false,isCallOnce=false,isgameover=false,isContingEnded=false,isAutoPlayModeActive=false,isBallRecreated=false,isGameStarted=false,isTouchedOnPaddlefront=false,isMagnetEnabled=false,isballHitPaddleInMagnet=false,isBallRecreatedAndTouched=false,isReleaseBall=false,isBallDownToPaddlePos=false,isSpeedMax=false,isMultiBallCreated=false,isPaddleTimerEnable=false,isInstructionLabelVisible=false,isBlackColorBackground=true,isPowerMultiBallVisible=false,isUserPlayingGame=false,isAddNewBricks=true,isAddedBricksMoreThanOnce=false,isFourtyBrickOnScreen=false,isBallBreakFirstBrick=false;
        counterForPower=0;gameStarterCounter=4;reverseCounting=10;autoPlayModeCounter=0;deviceResolutionSize=0;brickLastPosY=0;
        powerCounterInt=0;paddleCounter=0;brickBreakSound=0;isFullBundleRequired=false;lastPowerInt=0;isdeleteMultiBalls=false;isFourtyBrickBelowHalfScreen=false;
        indexCurrentLevel=1;
        ballArcadeMode=NULL;myPaddleBody = NULL;mypaddleSpritFrame = NULL;isMileStoneCountTwo=false;isMileStoneCountThree=false;isAddedOtherBricks=false;multiBallCount=0;
        itemList.clear();ballList.clear();m_Bricks.clear();
        
        
        isSpeedMax=false; isAutoPlayModeActive=false;  isPaddleTimerEnable=false;  isSlowDownSpeed=false; isAddGun=false;isFourtyBrickBelowHalfScreen=false;isMileStoneCountTwo=false;isMileStoneCountThree=false;
        
        isFourtyBrickOnScreen=false;
        CCLOG("mileStoneCount %d",localmileStoneCount);
        if(localmileStoneCount==5)
            localmileStoneCount=0;
        mileStoneCount=localmileStoneCount;multiBallCounterToDelete=0;multiBallCount=0;
        counterForPower=0;
        
        detectedDevice = CCApplication::sharedApplication()->getTargetPlatform();
        deviceResolutionInt = GameManager::sharedGameManager()->get_devise_resolution();
        currentLevelArcadeMode=1;
        
        autoPlayTotalTimer = 6;
        largepaddleTotalTimer = 6;
        butlletTotalTimer =6;
        
        AnimationLayerArcadeMode *localanimationLayerArcadeModeObj = animationLayerArcadeModeObj;
        int localbrickPointsArcadeMode =brickPointsArcadeMode;
        localLevel=1;
        currentLevelArcadeMode=localLevel;
        powerCreationcurrentLevelArcadeMode=localLevel;
        mileStoneCountForDisplay++;
        CCLabelTTF *yourScore = (CCLabelTTF*)localanimationLayerArcadeModeObj->scoreCountLbl;
        yourScore->setString(CCString::createWithFormat("%d",mileStoneCountForDisplay)->getCString());
        CCLabelTTF *totalScore = (CCLabelTTF*)localanimationLayerArcadeModeObj->scoreLabelNotUsed;
        totalScore->setString(CCString::createWithFormat("%d",localbrickPointsArcadeMode)->getCString());
        CCLabelTTF *localKaccheGameOverLabel = (CCLabelTTF*)localanimationLayerArcadeModeObj->sroreLabelNotUsed;
        localanimationLayerArcadeModeObj->mileStoneCompleted(NULL);
        mileStoneCompletedDisplay(mileStoneCountForDisplay, localKaccheGameOverLabel);
        CCCallFunc * gameWonCall = CCCallFunc::create( this, callfunc_selector( GameLayerArcadeMode::gameWon));
        this ->runAction(CCSequence::createWithTwoActions(CCDelayTime::create(2),gameWonCall));
        
        return;
    }
    
    
    b2World *localWorld = world;
    CCSprite *brickYellowSpr = CCSprite::create("brickYellow.png");
    int localdeviceResolutionInt=deviceResolutionInt;
    CCLayer *localbricksLayerArcadeMode = bricksLayerArcadeMode;
    
    int indexing =0;
    CCArray *piecesPosition=CCArray::create();
    piecesPosition->retain();
    
    CCArray *brickSprArrr = CCArray::create();
    brickSprArrr->retain();
    CCArray *sortedSprArr  = CCArray::create();
    sortedSprArr->retain();
    CCArray *originalColorBrick = CCArray::create();
    originalColorBrick->retain();
    indexing=0;
    vector<CCPoint>::iterator it;
    for( it = addOtherBricks.begin(); it != addOtherBricks.end(); it++){
        Brick* brick;
        if(indexing%2==0){
            CCSprite *brickSpr = CCSprite::create("brickYellow.png");
            brickSpr->setPosition((*it));
            localbricksLayerArcadeMode->addChild(brickSpr);
            brick = new Brick();
            brick->Init(localbricksLayerArcadeMode, localWorld,brickSpr,1);
            m_Bricks.push_back( brick );
        }else
        {
            CCSprite *brickSpr = CCSprite::create("brickOrange.png");
            brickSpr->setPosition((*it));
            localbricksLayerArcadeMode->addChild(brickSpr);
            brick = new Brick();
            brick->Init(localbricksLayerArcadeMode, localWorld,brickSpr,1);
            m_Bricks.push_back( brick );
        }
        indexing++;
    }
    
    mileStoneCount++;
    int localmileStoneCount = arc4random()%5;
    if(localmileStoneCount==lastPlayedMileStoneCount){
        switch (localmileStoneCount) {
            case 0:
                localmileStoneCount=1;
                break;
            case 1:
                localmileStoneCount=2;
                break;
            case 2:
                localmileStoneCount=3;
                break;
            case 3:
                localmileStoneCount=4;
                break;
            case 4:
                localmileStoneCount=5;
                break;
            case 5:
                localmileStoneCount=3;
                break;
            default:
                break;
        }
    }
    lastPlayedMileStoneCount = localmileStoneCount;
    
    if(localmileStoneCount==1)
    {
        for (int i = 11; i <= 220; i++) {
            CCSprite *brickSpr = CCSprite::create("brickGrey.png");
            CCSprite *brickNewPosSpr = brickPositionOnTheScreenDisplayArcadeMode(1,brickSpr,i,localdeviceResolutionInt);
            localbricksLayerArcadeMode->addChild(brickNewPosSpr);
            brickSprArrr->addObject(brickNewPosSpr);
            sortedSprArr->addObject(brickNewPosSpr);
        }
    }
    else if(localmileStoneCount==2)
    {
        isMileStoneCountTwo=true;
        for (int i = 11; i <= 200; i++) {
            CCSprite *brickSpr = CCSprite::create("brickGrey.png");
            CCSprite *brickNewPosSpr = brickPositionOnTheScreenDisplayArcadeMode(10,brickSpr,i,localdeviceResolutionInt);
            localbricksLayerArcadeMode->addChild(brickNewPosSpr);
            brickSprArrr->addObject(brickNewPosSpr);
            sortedSprArr->addObject(brickNewPosSpr);
        }
    }
    else if(localmileStoneCount==3)
    {
        isMileStoneCountThree=true;
        for (int i = 11; i <= 220; i++) {
            CCSprite *brickSpr = CCSprite::create("brickGrey.png");
            CCSprite *brickNewPosSpr = brickPositionOnTheScreenDisplayArcadeMode(11111,brickSpr,i,localdeviceResolutionInt);
            localbricksLayerArcadeMode->addChild(brickNewPosSpr);
            brickSprArrr->addObject(brickNewPosSpr);
            sortedSprArr->addObject(brickNewPosSpr);
        }
    }
    else  if(localmileStoneCount==4){
        for (int i = 11; i <= 170; i++) {
            CCSprite *brickSpr = CCSprite::create("brickGrey.png");
            CCSprite *brickNewPosSpr = brickPositionOnTheScreenDisplayArcadeMode(111,brickSpr,i,localdeviceResolutionInt);
            localbricksLayerArcadeMode->addChild(brickNewPosSpr);
            brickSprArrr->addObject(brickNewPosSpr);
            sortedSprArr->addObject(brickNewPosSpr);
        }
    }else {
        for (int i = 11; i <= 220; i++) {
            CCSprite *brickSpr = CCSprite::create("brickGrey.png");
            CCSprite *brickNewPosSpr = brickPositionOnTheScreenDisplayArcadeMode(1,brickSpr,i,localdeviceResolutionInt);
            localbricksLayerArcadeMode->addChild(brickNewPosSpr);
            brickSprArrr->addObject(brickNewPosSpr);
            sortedSprArr->addObject(brickNewPosSpr);
        }
    }
    brickSprArrr =GameManager::sharedGameManager()->shuffle_array(brickSprArrr, brickSprArrr->count());
    
    //Hard Bricks
    for (int j = 20; j > 0; j--) {
        CCSprite *blackBrick = (CCSprite*)brickSprArrr->lastObject();
        Brick* brick = new Brick();
        brick->Init(localbricksLayerArcadeMode, localWorld,blackBrick,2);
        brickSprArrr->removeLastObject();
        m_Bricks.push_back( brick );
    }
    brickSprArrr->removeAllObjects();
    
    CCObject *objIndexNext2=NULL;
    CCARRAY_FOREACH(sortedSprArr, objIndexNext2)
    {
        CCSprite *brickColouring = (CCSprite*)objIndexNext2;
        if(brickColouring->getTag()==6){
        }
        else{
            brickSprArrr->addObject(brickColouring);
        }
    }
    
    CCObject *objIndexNext1=NULL;
    indexing =0;
    CCARRAY_FOREACH(brickSprArrr, objIndexNext1)
    {
        CCSprite *brickColouring = (CCSprite*)objIndexNext1;
        Brick* brick;
        if(indexing%2==0){
            brickColouring->setDisplayFrame(CCSpriteFrame::create("brickYellow.png",brickYellowSpr->getTextureRect()));
            brick = new Brick();
            brick->Init(localbricksLayerArcadeMode, localWorld,brickColouring,1);
        }else
        {
            brickColouring->setDisplayFrame(CCSpriteFrame::create("brickOrange.png",brickYellowSpr->getTextureRect()));
            brick = new Brick();
            brick->Init(localbricksLayerArcadeMode, localWorld,brickColouring,1);
            
        }
        m_Bricks.push_back(brick);
        indexing++;
    }
    
    world = localWorld;
    bricksLayerArcadeMode=localbricksLayerArcadeMode;
    CC_SAFE_RELEASE_NULL(sortedSprArr);
    CC_SAFE_RELEASE_NULL(originalColorBrick);
    CC_SAFE_RELEASE_NULL(piecesPosition);
    CC_SAFE_RELEASE_NULL(brickSprArrr);
    
    
    //    localLevel++;
    if(localLevel>49)
        localLevel=49;
    powerCreationcurrentLevelArcadeMode=localLevel;
    
    isAddNewBricks=false;
}

void GameLayerArcadeMode::restrictPaddleMovement() {
    //===================restrict paddle's movement===============
    b2PrismaticJointDef jointDef;
    b2Vec2 worldAxis(1.0f, 0.0f);
    jointDef.collideConnected = true;
    jointDef.Initialize(myPaddleBody, groundBody,
                        myPaddleBody->GetWorldCenter(), worldAxis);
    world->CreateJoint(&jointDef);
    world->SetAutoClearForces(true);
    
    
    //===================restrict paddle's movement===============
    b2PrismaticJointDef jointDef1;
    b2Vec2 worldAxis1(1.0f, 0.0f);
    jointDef1.collideConnected = true;
    jointDef1.Initialize(myPaddleBody, groundBody,
                         myPaddleBody->GetWorldCenter(), worldAxis);
    world->CreateJoint(&jointDef);
    world->SetAutoClearForces(true);
}

MyPaddle* GameLayerArcadeMode::getMyPaddle() {
    return myPaddleArcadeMode;
}

void GameLayerArcadeMode::gameWonRestartConfirm() {
    int localcurrentLevelArcadeMode = currentLevelArcadeMode;
    
    AnimationLayerArcadeMode *localanimationLayerArcadeModeObj = animationLayerArcadeModeObj;
    if(isPlayerLifeZero==true && isgameover==true){
        int localbrickPointsArcadeMode =brickPointsArcadeMode;
        autostrip->setVisible(false);
        isGameStarted=false;
        unschedule(schedule_selector(GameLayerArcadeMode::updateAtEachSeconds));
        unschedule(schedule_selector(GameLayerArcadeMode::powerUpItems));
        unschedule(schedule_selector(GameLayerArcadeMode::timerForPower));
        unschedule(schedule_selector(GameLayerArcadeMode::checkIfGameOver));
        unschedule(schedule_selector(GameLayerArcadeMode::moveElement));
        
        CCLabelTTF *yourScore = (CCLabelTTF*)localanimationLayerArcadeModeObj->scoreCountLbl;
        yourScore->setString("YOUR SCORE");
        CCLabelTTF *totalScore = (CCLabelTTF*)localanimationLayerArcadeModeObj->scoreLabelNotUsed;
        totalScore->setString(CCString::createWithFormat("%d",localbrickPointsArcadeMode)->getCString());
        
        CCLabelTTF *localKaccheGameOverLabel = (CCLabelTTF*)localanimationLayerArcadeModeObj->KaccheGameOverLabel;
        localanimationLayerArcadeModeObj->gameOverDown(NULL);
        changeViewAndLabelContentAndColoronGameOver(localcurrentLevelArcadeMode, localKaccheGameOverLabel, isBlackColorBackground);
        
        CCScaleTo *myPaddleScale = CCScaleTo::create(2, 0);
        myPaddleArcadeMode->runAction(myPaddleScale);
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
            gameEndedStartCounting();
            isCallOnce=true;
            isContingEnded=true;
            if (isPaddleTimerEnable==true){
                unschedule(schedule_selector(GameLayerArcadeMode::paddleTimer));
            }
        }
    }
    
}

void GameLayerArcadeMode::enableMagnet(){
    removeAllBalls();
    ballList.clear();
    buildBall("ball.png");
    
    isBallRecreatedAndTouched=false;
    isBallRecreated=false;
    isballHitPaddleInMagnet=false;
    isMagnetEnabled=false;
    isReleaseBall=true;
}
void GameLayerArcadeMode::onRestartButtonPressed()
{
    unschedule(schedule_selector(GameLayerArcadeMode::updateAtEachSeconds));
    unschedule(schedule_selector(GameLayerArcadeMode::powerUpItems));
    unschedule(schedule_selector(GameLayerArcadeMode::timerForPower));
    unschedule(schedule_selector(GameLayerArcadeMode::checkIfGameOver));
    unschedule(schedule_selector(GameLayerArcadeMode::moveElement));
    
    ballLastPos = ballArcadeMode->ballSpr->getPosition();
    paddleLastPos = myPaddleArcadeMode->getPosition();
    
    int localLevel=currentLevelArcadeMode;
    localLevel=1;
    int localmileStoneCount = mileStoneCount;
    currentLevelArcadeMode=localLevel;
    powerCreationcurrentLevelArcadeMode=localLevel;
    
    autostrip->setVisible(false);
    isGameStarted=false;
    
    list<Ball *>::iterator it;
    for( it = ballList.begin(); it != ballList.end(); it++){
        if ((*it)!=NULL){
            (*it)->UnInit(world);
            it = ballList.erase(it);
        }
    }
    for( it = ballList.begin(); it != ballList.end(); it++){
        if ((*it)!=NULL){
            (*it)->UnInit(world);
            it = ballList.erase(it);
        }
    }
    
    myPaddleArcadeMode->removeFromParentAndCleanup(true);
    if (!itemList.empty() && itemList.size() > 0) {
        list<Item *>::iterator it;
        for( it = itemList.begin(); it != itemList.end(); it++) {
            if ((*it) != NULL){
                (*it)->pauseSchedulerAndActions();
            }
        }
    }
    myPaddleFixture=NULL;myPaddleBody=NULL;bottomFixture=NULL;
    m_Bricks.clear();ballList.clear();
    itemList.clear();
    //    if(backGroundSpr!=NULL)
    //    backGroundSpr->removeFromParentAndCleanup(true);
    countingLable->removeFromParentAndCleanup(true);
    bricksLayerArcadeMode->removeAllChildren();
    //    backGroundSpr=NULL;
    isAddGun=false,isTouchedOnPlayerPaddle=false,isPaddleCreatedNotFirstTime=false,gameIsPaused=false,gameIsEnded=false,isSlowDownSpeed=false,isAllBricksRemoved=false,isPlayerLifeZero=false,isGameEnded=false,isDestroyedGameOverPaddle=false,isCallOnce=false,isgameover=false,isContingEnded=false,isAutoPlayModeActive=false,isBallRecreated=false,isGameStarted=false,isTouchedOnPaddlefront=false,isMagnetEnabled=false,isballHitPaddleInMagnet=false,isBallRecreatedAndTouched=false,isReleaseBall=false,isBallDownToPaddlePos=false,isSpeedMax=false,isMultiBallCreated=false,isPaddleTimerEnable=false,isInstructionLabelVisible=false,isBlackColorBackground=true,isPowerMultiBallVisible=false,isUserPlayingGame=false,isAddNewBricks=true,isAddedBricksMoreThanOnce=false,isFourtyBrickOnScreen=false,isBallBreakFirstBrick=false;
    counterForPower=0;playerLifeCount=3;gameStarterCounter=4;reverseCounting=10;autoPlayModeCounter=0;deviceResolutionSize=0;brickLastPosY=0;mileStoneCount=0;
    powerCounterInt=0;paddleCounter=0;brickBreakSound=0;isFullBundleRequired=false;lastPowerInt=0;isdeleteMultiBalls=false;isFourtyBrickBelowHalfScreen=false;brickPointsArcadeMode=0;
    indexCurrentLevel=1;mileStoneCountForDisplay=0;
    ballArcadeMode=NULL;myPaddleBody = NULL;mypaddleSpritFrame = NULL;isMileStoneCountThree=false;isAddedOtherBricks=false;multiBallCount=0;
    itemList.clear();ballList.clear();addOtherBricks.clear();m_Bricks.clear();
    
    isSpeedMax=false; isAutoPlayModeActive=false;  isPaddleTimerEnable=false;  isSlowDownSpeed=false; isAddGun=false;isFourtyBrickBelowHalfScreen=false;isMileStoneCountTwo=false;
    
    isFourtyBrickOnScreen=false;
    CCLOG("mileStoneCount %d",localmileStoneCount);
    if(localmileStoneCount==4)
        localmileStoneCount=0;
    mileStoneCount=localmileStoneCount;multiBallCounterToDelete=0;multiBallCount=0;
    counterForPower=0;
    
    detectedDevice = CCApplication::sharedApplication()->getTargetPlatform();
    deviceResolutionInt = GameManager::sharedGameManager()->get_devise_resolution();
    currentLevelArcadeMode=1;
    
    autoPlayTotalTimer = 6;
    largepaddleTotalTimer = 6;
    butlletTotalTimer =6;
    
    animationLayerArcadeModeObj->menuLayer->setVisible(false);
    CCCallFunc * gameWonCall = CCCallFunc::create( this, callfunc_selector( GameLayerArcadeMode::gameWon));
    this ->runAction(CCSequence::createWithTwoActions(CCDelayTime::create(0.5),gameWonCall));
    return;
    
}

void GameLayerArcadeMode::onPausePressedFromAnimationLayerArcadeMode()
{
    if(animationLayerArcadeModeObj->getgameIsPaused() ==true)
    {
        std::list<Item*>::iterator it;
        for( it = itemList.begin(); it != itemList.end(); it++ )
        {
            if(itemList.size() != 0)
            {
                (*it)->pauseSchedulerAndActions();
            }
        }
    }
    else{
        std::list<Item*>::iterator it;
        for( it = itemList.begin(); it != itemList.end(); it++ )
        {
            if(  itemList.size() != 0)
            {
                //                CCSprite *itemSpr =(CCSprite*)(*it)->itemSprite;
                (*it)->resumeSchedulerAndActions();
            }
        }
    }
}


#pragma  mark   TOUCHES    METHODS
void GameLayerArcadeMode::ccTouchesBegan(CCSet *pTouches, CCEvent *event) {
    
    if(isInstructionLabelVisible==true){
        isInstructionLabelVisible=false;
        instructionLabel->setVisible(false);
        schedule(schedule_selector(GameLayerArcadeMode::updateAtEachSeconds));
        schedule(schedule_selector(GameLayerArcadeMode::powerUpItems));
        schedule(schedule_selector(GameLayerArcadeMode::timerForPower),3);
        schedule(schedule_selector(GameLayerArcadeMode::checkIfGameOver));
    }
    
    AnimationLayerArcadeMode *animationLayerLocalObj = animationLayerArcadeModeObj;
    
    if(isGameStarted==false || animationLayerLocalObj->isPausePressed==true)
        return;
    
    if(isballHitPaddleInMagnet==true || isBallRecreatedAndTouched==true){
        removeAllBalls();
        enableMagnet();
    }
    
    CCTouch *myTouch = (CCTouch*) pTouches->anyObject();
    CCPoint location = myTouch->getLocationInView();
    location = CCDirector::sharedDirector()->convertToGL(location);
    if(GameManager::sharedGameManager()->isNodeAtPoint(animationLayerLocalObj->pauseAndPlayLayer, location)){
        animationLayerLocalObj->pauseAndResume(NULL);
        return;
    }
    if(GameManager::sharedGameManager()->isNodeAtPoint(animationLayerLocalObj->stageLayer, location)){
        animationLayerLocalObj->onStagePressed(NULL);
        return;
    }
    
    if(isReleaseBall==true){
        if (isBallBreakFirstBrick==false) {
            isBallBreakFirstBrick=true;
            this->moveElement(0);
            schedule(schedule_selector(GameLayerArcadeMode::moveElement),10);
        }
        isReleaseBall=false;
        isBallDownToPaddlePos=false;
        b2Vec2 v;
        int random = arc4random()%2;
        if(random==0)
            v = b2Vec2(20,20);
        else
            v = b2Vec2(-20,20);
        
        ballArcadeMode->ballBody->ApplyForceToCenter(v);
        ballArcadeMode->ballBody->SetLinearVelocity(v);
    }
    
    if (_mouseJoint != NULL)
        return;
    
    b2Vec2 locationWorld = b2Vec2(location.x / PTM_RATIO ,location.y / PTM_RATIO);
    if(myPaddleArcadeMode==NULL)
        return;
    
    if (paddleLayer->boundingBox().containsPoint(location) || myPaddleArcadeMode->boundingBox().containsPoint(location)) {
        isUserPlayingGame=true;
        b2MouseJointDef md;
        md.bodyA = groundBody;
        md.bodyB = myPaddleBody;
        md.target = locationWorld;
        md.collideConnected = true;
        md.maxForce = 40000.0f* 40000.0f*myPaddleBody->GetMass();
        if(_mouseJoint != NULL)
        {
            world->DestroyJoint(_mouseJoint);
            _mouseJoint = NULL;
        }
        _mouseJoint = (b2MouseJoint *) world->CreateJoint(&md);
        myPaddleBody->SetAwake(true);
    }
}
void GameLayerArcadeMode::moveElement(float delta){
    if(isAddNewBricks==true)
        return;
    bool localisMileStoneCountTwo = isMileStoneCountTwo;
    bool localisMileStoneCountThree = isMileStoneCountThree;
    
    float brickYPos;
    int deviceDetected = deviceResolutionInt;
    b2Vec2 v;
    vector<Brick *>::iterator it;
    bool localisFourtyBrickOnScreen = isFourtyBrickOnScreen;
    
    for( it = m_Bricks.begin(); it != m_Bricks.end(); it++){
        if ((*it)!=NULL){
            brickYPos =(*it)->brickSprites->getPosition().y;
            if(localisFourtyBrickOnScreen==true)
                if(brickYPos>600)
                    isFourtyBrickBelowHalfScreen=true;
            
            if((deviceDetected==1||deviceDetected==6)&& brickYPos <= 200){
                isgameover=true;
                gameIsEnded = true;
            }
            else{
                if(brickYPos <= 160){
                    isgameover=true;
                    gameIsEnded = true;
                }
            }
            if(isgameover==true && gameIsEnded==true){
                gameOver();
                break;
            }
            else{
                brickYPos =(*it)->getPosition().y;
                if(deviceDetected==1 || deviceDetected==6){
                    if(localisFourtyBrickOnScreen==true){
                        if(isFourtyBrickBelowHalfScreen==true)
                            if(localisMileStoneCountTwo==false)
                                v = b2Vec2(0, brickYPos-1);
                    }
                    else{
                        if(localisMileStoneCountThree==true)
                            v = b2Vec2(0, brickYPos-0.45);
                        else if(localisMileStoneCountTwo==true)
                            v = b2Vec2(0, brickYPos-0.14);
                        else
                            v = b2Vec2(0, brickYPos-0.26);
                    }
                    
                }
                else{
                    if(localisFourtyBrickOnScreen==true){
                        if(isFourtyBrickBelowHalfScreen==true)
                            if(localisMileStoneCountTwo==false)
                                v = b2Vec2(0, brickYPos-0.6);
                    }
                    else{
                        if(localisMileStoneCountThree==true)
                            v = b2Vec2(0, brickYPos-0.38);
                        else if(localisMileStoneCountTwo==true)
                            v = b2Vec2(0, brickYPos-0.1);
                        else
                            v = b2Vec2(0, brickYPos-0.2);
                    }
                }
                
                (*it)->brickBody->SetLinearVelocity(v);
            }
        }
    }
}

void GameLayerArcadeMode::callOnceToReScheduleMoveElement(){
    //    schedule(schedule_selector(GameLayerArcadeMode::moveElement),2);
    //    schedule(schedule_selector(GameLayerArcadeMode::callMeToArrangeNextBricks),15);
    //    this->callMeToArrangeNextBricks();
    
}

void GameLayerArcadeMode::ccTouchesMoved(CCSet *pTouches, CCEvent* event) {
    
    CCTouch* myTouch = (CCTouch*) pTouches->anyObject();
    CCPoint location = myTouch->getLocationInView();
    location = CCDirector::sharedDirector()->convertToGL(location);
    
    b2Vec2 locationWorld = b2Vec2(location.x / PTM_RATIO,location.y / PTM_RATIO);
    if (_mouseJoint==NULL)
        return;
    _mouseJoint->SetTarget(locationWorld);
    
}

void GameLayerArcadeMode::ccTouchesEnded(CCSet *pTouches, CCEvent* event) {
    isUserPlayingGame=false;
    if (_mouseJoint != NULL){
        world->DestroyJoint(_mouseJoint);
        _mouseJoint = NULL;
        isTouchedOnPlayerPaddle= false;
        if(isBallRecreated==true)
            isBallRecreatedAndTouched=true;
    }
}

void GameLayerArcadeMode::disablePaddleMovement()
{
    if(isTouchedOnPlayerPaddle == false){
        b2Vec2 v = b2Vec2(0, 0);
        myPaddleBody->SetLinearVelocity(v);
    }
}

void GameLayerArcadeMode::ccTouchesCancelled(CCSet *pTouches, CCEvent *pEvent)
{
    if (_mouseJoint != NULL){
        world->DestroyJoint(_mouseJoint);
        
        // Have the layer run the action and call this same method again
        CCDelayTime * delayAction = CCDelayTime::create(5);
        CCCallFunc * callFunc = CCCallFunc::create( this, callfunc_selector( GameLayerArcadeMode::disablePaddleMovement ));
        this -> runAction( CCSequence::createWithTwoActions( delayAction, callFunc ) );
        _mouseJoint = NULL;
    }
}

#pragma  mark   ******************........POWER IMPLEMENTATION......*********************
void GameLayerArcadeMode::powerCreationAndDropDown(CCPoint itemPos) {
    if (!gameIsEnded && !gameIsPaused) {
        isPowerToGenerate = false;
        if(isSpeedMax==true || isAutoPlayModeActive==true||  isPaddleTimerEnable==true||  isSlowDownSpeed==true|| isAddGun==true){
            return;
        }
        
        int powerType = arc4random()%9;
        if(lastPowerInt==powerType)
            powerType = arc4random()%9;
        
        if(playerLifeCount==9){
            if(powerType==5)
                return;
        }
        lastPowerInt=powerType;
        
        int localpowerCreationcurrentLevelArcadeMode = powerCreationcurrentLevelArcadeMode;
        if(localpowerCreationcurrentLevelArcadeMode>9)
            powerType = arc4random()%9;
        else if (localpowerCreationcurrentLevelArcadeMode<7)
            if(powerType==7)
                return;
        item=NULL;
        switch (powerType) {
            case 0:
                item = EnlargeItem::createEnlargeItem();
                break;
            case 1:
                item = ShortenItem::createShortenItem();
                break;
            case 2:
                item = ReverseYItem::createReverseYItem();
                break;
            case 3:
                item = AutoPlayItem::createAutoPlayItem();
                break;
            case 4:
                item = BonusScore::createBonusScore();
                break;
            case 5:
                item = BonusLife::createBonusLife();
                break;
            case 6:
                item = MagnetItem::createMagnetItem();
                break;
            case 7:
                item = SlowDownSpeed::createSlowDownSpeed();
                break;
            case 8:
                item = DoubleItem::createDoubleItem();
                break;
                
            default:
                break;
        }
        if(item==NULL)
            return;
        item->setPosition(itemPos);
        bricksLayerArcadeMode->addChild(item);
        CCMoveTo* action2 = CCMoveTo::create(4.f,ccp(itemPos.x,myPaddleArcadeMode->getPositionY()-200));
        
        item->runAction(action2);
        itemList.push_back(item);
    }
}

void GameLayerArcadeMode::powerUpItems()
{
    list<Item *> localitemList = itemList;
    
    std::list<Item*>::iterator it;
    for( it = localitemList.begin(); it != localitemList.end(); it++ )
    {
        if( (*it) != NULL && localitemList.size() != 0)
        {
            
            if (myPaddleArcadeMode->boundingBox().intersectsRect((*it)->boundingBox())) {
                
                string localfunction = (*it)->getFunction();

                if (!localitemList.empty() && localitemList.size() > 0){
                    (*it)->removeFromParentAndCleanup(true);
                    it = localitemList.erase(it);
                }
                addPoints(20);
                playPowerUpSound();
                if (localfunction == "enlarge") {
                    if(isPaddleTimerEnable==true){paddleCounter=0;
                        unschedule(schedule_selector(GameLayerArcadeMode::paddleTimer));}
                    isPaddleTimerEnable=true;
                    enlargePaddle();
                    break;
                } if (localfunction == "autoPlay") {
                    autostrip->setVisible(true);
                    autoPlayGame();
                    if(isAutoPlayModeActive==true)
                    {
                        isAutoPlayModeActive=false;
                        unschedule(schedule_selector(GameLayerArcadeMode::autoPlayTimer));}
                    
                    isAutoPlayModeActive=true;
                    autoPlayModeCounter=0;
                    powerCounterInt=3;
                    schedule(schedule_selector(GameLayerArcadeMode::autoPlayTimer),1);
                    break;
                }
                if (localfunction == "reverseY") {
                    reverseBallYVelocity();
                    break;
                }
                if (localfunction == "double") {
                    
                    if(ballList.size()>=2){
                        unschedule(schedule_selector(GameLayerArcadeMode::deleteMultiBalls));
                    }
                    multiBallCounterToDelete=0;
                    schedule(schedule_selector(GameLayerArcadeMode::deleteMultiBalls),1);
                    
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
                        unschedule(schedule_selector(GameLayerArcadeMode::paddleTimer));}
                    isPaddleTimerEnable=true;
                    shortenPaddle();
                    break;
                }  if (localfunction == "bonus") {
                    bonusBallLife();
                    break;
                }  if (localfunction == "magnet") {
                    isMagnetEnabled=true;
                    break;
                }
                if(localfunction=="slowBallSpeed"){
                    isSlowDownSpeed=true;
                    slowDownBallSpeed();
                    break;
                }
                
                if (localfunction == "BonusPoints") {
                    addPoints(100);
                    break;
                }
                if(localfunction == "fastSpeed")
                {
                    if(isSpeedMax==true){
                        unschedule(schedule_selector(GameLayerArcadeMode::disableMaxSpeed));
                    }
                    isSpeedMax=true;
                    speedMaxCounter=0;
                    powerCounterInt=3;
                    schedule(schedule_selector(GameLayerArcadeMode::disableMaxSpeed),1);
                    break;
                }
                
            }
            
            else if((*it)->getPositionY() < myPaddleArcadeMode->getPositionY()-100) {
                if (!localitemList.empty() && localitemList.size() > 0)
                {
                    (*it)->removeFromParentAndCleanup(true);
                    it = localitemList.erase(it);
                }
            }
            //            if(animationLayerArcadeModeObj->menuLayer->isVisible()==true || gameIsEnded==true)
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

void GameLayerArcadeMode::enlargePaddle() {
    MyPaddle *myPaddleLocalStorage = myPaddleArcadeMode;
    if (myPaddleLocalStorage->getLengthState() == 0) {
        ;
        myPaddleLocalStorage->setLengthState(Paddle::normalPaddle);
        
    } else if (myPaddleLocalStorage->getLengthState() == 1) {
        ;
        myPaddleLocalStorage->setLengthState(Paddle::longPaddle);
    }
    buildMyPaddleWithNewPaddle(myPaddleLocalStorage);
    schedule(schedule_selector(GameLayerArcadeMode::paddleTimer),1);
}

void GameLayerArcadeMode::shortenPaddle() {
    
    MyPaddle *myPaddleLocalStorage = myPaddleArcadeMode;
    if (myPaddleLocalStorage->getLengthState() == 1) {
        ;
        myPaddleLocalStorage->setLengthState(Paddle::shortPaddle);
        
    } else if (myPaddleLocalStorage->getLengthState() == 2) {
        ;
        myPaddleLocalStorage->setLengthState(Paddle::normalPaddle);
    }
    buildMyPaddleWithNewPaddle(myPaddleLocalStorage);
    schedule(schedule_selector(GameLayerArcadeMode::paddleTimer),1);
}

void GameLayerArcadeMode::paddleTimer() {
    if(paddleCounter==largepaddleTotalTimer){
        unschedule(schedule_selector(GameLayerArcadeMode::paddleTimer));
        paddleCounter=0;
        isPaddleTimerEnable=false;
        myPaddleArcadeMode->setLengthState(Paddle::normalPaddle);
        buildMyPaddle("myPaddleNight.png");
    }
    else{
        paddleCounter++;
    }
}


void GameLayerArcadeMode::bonusBallLife() {
    int lifeOfPlayer =playerLifeCount;
    lifeOfPlayer++;
    if(lifeOfPlayer>=9){
        lifeOfPlayer=9;
    }
    globalPlayerLifeCountLabel->setString(CCString::createWithFormat("%d",lifeOfPlayer)->getCString());
    playerLifeCount=lifeOfPlayer;
}

void GameLayerArcadeMode::slowDownBallSpeed() {
    CCCallFunc * callFunc = CCCallFunc::create( this, callfunc_selector( GameLayerArcadeMode::ballSetNormalSpeed));
    this->runAction( CCSequence::createWithTwoActions(CCDelayTime::create(6.2),callFunc));
}
void GameLayerArcadeMode::ballSetNormalSpeed(){
    isSlowDownSpeed=false;
}

void GameLayerArcadeMode::autoPlayTimer() {
    
    if(autoPlayModeCounter==autoPlayTotalTimer){
        unschedule(schedule_selector(GameLayerArcadeMode::autoPlayTimer));
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

void GameLayerArcadeMode::autoPlayGame() {
    if (isAutoPlayModeActive==true)
        return;
    //=============== Bottom to restict game over ====================================
    groundBox.Set(b2Vec2(0,0), b2Vec2(winSize.width/PTM_RATIO, 0));
    bottomFixture = groundBody->CreateFixture(&groundBoxDef);
}

void GameLayerArcadeMode::reverseBallYVelocity() {
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

void GameLayerArcadeMode::gameOver()
{
    if(isgameover==true && gameIsEnded==true){
        AnimationLayerArcadeMode *localanimationLayerArcadeModeObj = animationLayerArcadeModeObj;
        int localbrickPointsArcadeMode =brickPointsArcadeMode;
        
        unschedule(schedule_selector(GameLayerArcadeMode::updateAtEachSeconds));
        unschedule(schedule_selector(GameLayerArcadeMode::powerUpItems));
        unschedule(schedule_selector(GameLayerArcadeMode::timerForPower));
        unschedule(schedule_selector(GameLayerArcadeMode::checkIfGameOver));
        unschedule(schedule_selector(GameLayerArcadeMode::moveElement));
        
        CCLabelTTF *yourScore = (CCLabelTTF*)localanimationLayerArcadeModeObj->scoreCountLbl;
        yourScore->setString("YOUR SCORE");
        CCLabelTTF *totalScore = (CCLabelTTF*)localanimationLayerArcadeModeObj->scoreLabelNotUsed;
        totalScore->setString(CCString::createWithFormat("%d",localbrickPointsArcadeMode)->getCString());
        localanimationLayerArcadeModeObj->stageMenuItemButton->setEnabled(false);
        localanimationLayerArcadeModeObj->pauseMenuItemButton->setEnabled(false);
        CCLabelTTF *localKaccheGameOverLabel = (CCLabelTTF*)localanimationLayerArcadeModeObj->KaccheGameOverLabel;
        localanimationLayerArcadeModeObj->gameOverDown(NULL);
        changeViewAndLabelContentAndColoronGameOver(currentLevelArcadeMode, localKaccheGameOverLabel, isBlackColorBackground);
        
        CCScaleTo *myPaddleScale = CCScaleTo::create(2,  0);
        myPaddleArcadeMode->runAction(myPaddleScale);
        return;
    }
    
    removeGun();
    
    if(isPlayerLifeZero == true || isDestroyedGameOverPaddle==true){
        removeAllBalls();
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
    
    itemList.clear();
}

#pragma mark  ****************REMOVE BRICK AND CHECK IF THE GAME OVER***********************************
void GameLayerArcadeMode::removeBullet()
{
    if(isAddNewBricks==true)
        return;
    
    //REMOVE THE BRICKS ON BALL TOUCH
    std::vector<b2Body*>::iterator removePos;
    for( removePos = toRemove.begin(); removePos != toRemove.end(); removePos++ )
    {
        if( (*removePos) != NULL && toRemove.size() != 0)
        {
            std::vector<Brick*>::iterator BrickPos = m_Bricks.begin();
            while(BrickPos != m_Bricks.end()){
                if( (*BrickPos)->brickBody == (*removePos) ){
                    (*BrickPos)->UnInit();
                    BrickPos = m_Bricks.erase( BrickPos );
                }
                else{
                    ++BrickPos;
                }
            }
        }
    }
}

void GameLayerArcadeMode::checkIfGameOver()
{
    if(isAddNewBricks==false){
        if(isFourtyBrickOnScreen==false){
            if(m_Bricks.size()<30)
                isFourtyBrickOnScreen=true;
        }
        else if(isFourtyBrickOnScreen==true){
            if(m_Bricks.size()<25){
                isAddedOtherBricks=false;
                addOtherBricks.clear();
                vector<Brick *>::iterator it;
                for( it = m_Bricks.begin(); it != m_Bricks.end(); it++){
                    if ((*it)!=NULL){
                        addOtherBricks.push_back((*it)->brickSprites->getPosition());
                    }
                }
                
                currentLevelArcadeMode=14;
                buildBrickPaddle();
                return;
                
            }
        }
    }
    if (gameIsEnded==true)
        gameWonRestartConfirm();
    else{
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
        
        if(ballList.size()==0 && !gameIsEnded){
            gameOver();
            isballHitPaddleInMagnet=false;
            isMagnetEnabled=false;
            isBallRecreated=false;
            isBallRecreatedAndTouched=false;
            isBallDownToPaddlePos=true;
            if(isPaddleTimerEnable==true){
                isPaddleTimerEnable=false;
                unschedule(schedule_selector(GameLayerArcadeMode::paddleTimer));
            }
            if(isSpeedMax==true){
                speedMaxCounter=0;
                powerCounterInt=0;
                isSpeedMax=false;
                unschedule(schedule_selector(GameLayerArcadeMode::disableMaxSpeed));
            }
            if(isAutoPlayModeActive==true){
                unschedule(schedule_selector(GameLayerArcadeMode::autoPlayTimer));
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
            int localBonusLifeCount =bonusLifeCount;
            localplayerLifeCount--;
            globalPlayerLifeCountLabel->setString(CCString::createWithFormat("%d",localplayerLifeCount)->getCString());
            if(localBonusLifeCount>0){
                localBonusLifeCount--;
                bonusLifeCount=localBonusLifeCount;
            }
            if(localplayerLifeCount>=1){
                myPaddleBody->SetActive(false);
                CCScaleTo *myPaddleScale = CCScaleTo::create(1, 0);
                myPaddleArcadeMode->runAction(myPaddleScale);
                CCCallFunc * callFunc = CCCallFunc::create( this, callfunc_selector( GameLayerArcadeMode::decrementPlayerLife) );
                this->runAction( CCSequence::createWithTwoActions(CCDelayTime::create(1.2),callFunc));
            }
            else if(localplayerLifeCount==0){
                globalPlayerLifeCountLabel->setString(CCString::createWithFormat("%d",localplayerLifeCount)->getCString());
                
                isgameover=true;
                gameIsEnded = true;
                isPlayerLifeZero = true;
                gameWonRestartConfirm();
            }
            playerLifeCount=localplayerLifeCount;
            SoundManager::sharedSoundManager()->playSoundEffect("Boll Drop 2 Final.wav", false);
            if (myPaddleArcadeMode->getLengthState() == 0){
                myPaddleArcadeMode->setLengthState(Paddle::normalPaddle);
            }else if(myPaddleArcadeMode->getLengthState() == 2){
                myPaddleArcadeMode->setLengthState(Paddle::normalPaddle);
            }
        }
    }
}

void GameLayerArcadeMode::deleteMultiBalls()
{
    int localmultiBallCounterToDelete = multiBallCounterToDelete;
    localmultiBallCounterToDelete++;
    if(localmultiBallCounterToDelete>=15)
        isdeleteMultiBalls=true;
    else if (localmultiBallCounterToDelete==13){
        list<Ball *> localballList=ballList;
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
        }
        ballList.swap(localballList);
    }
    
    multiBallCounterToDelete=localmultiBallCounterToDelete;
    if(isdeleteMultiBalls==true){
        unschedule(schedule_selector(GameLayerArcadeMode::deleteMultiBalls));
        removeAllBalls();
        removeAllBalls();
        removeAllBalls();
        isdeleteMultiBalls=false;
        multiBallCounterToDelete=0;
    }
}
void GameLayerArcadeMode::applyBlinkEffectOnBall(cocos2d::CCSprite *spr)
{
    if(spr==NULL)
        return;
    CCActionInterval *action1 = CCFadeIn::create(0.1);
    CCActionInterval *action = CCFadeOut::create(0.1);
    CCDelayTime *delay= CCDelayTime::create(0.1);
    CCSequence *Seq = CCSequence::create(action1,delay,action,delay,action1,delay,action,action1,delay,action,delay,action1,NULL);
    spr->runAction(Seq);
    return;
}



#pragma mark *************** PLAYER LIFE ****************

void GameLayerArcadeMode::decrementPlayerLife()
{
    myPaddleArcadeMode->setScale(1);
    myPaddleBody->SetActive(true);
    buildMyPaddleWithNewPaddle(myPaddleArcadeMode);
    buildBall("ball.png");
    isBallDownToPaddlePos=false;
}


#pragma mark **********************TIMERS FOR THE PADDLE,  BALL***********************
void GameLayerArcadeMode::avoidUnwantedSituation(int level) {
    
    if(isAddNewBricks==true)
        return;
    if(isballHitPaddleInMagnet==true)
        return;
    
    int localLevel = level;
    int localdeviceResolutionInt = deviceResolutionInt;
    list<Ball *>::iterator it;
    if(isSlowDownSpeed==true){
        localLevel=1;
    }
    
    bool localisSpeedMax = isSpeedMax;
    if(localisSpeedMax==true){
        localLevel=localLevel+10;
        if(localLevel>=30)
            localLevel=30;
    }
    b2Vec2 bv,gv;
    float gs,bs;
    float32 speed;
    b2Body *localballBody;
    for( it = ballList.begin(); it != ballList.end(); it++ )
    {
        localballBody=(*it)->ballBody;
        if( (*it) != NULL){
            bv = localballBody->GetLinearVelocity();
            gv = localballBody->GetLinearVelocity();
            
            speed = bv.Length();
            if(localdeviceResolutionInt==1 || localdeviceResolutionInt==6){
                
                if(speed<20)
                    speed=20;
                
                bs = bv.x * bv.x + bv.y * bv.y*randomValueBetween(1.5, 2.5);
                gs = gv.x * gv.x + gv.y * gv.y*randomValueBetween(0.5, 1.5);
                if (bs > maxBallBSArcadeMode[localLevel]/1.4) {
                    b2Vec2 *bf = new b2Vec2(-bv.x * 20, -bv.y * 20);
                    localballBody->ApplyForceToCenter(*bf);
                }
                if(speed<maxBallSpeedArcadeMode[localLevel]/1.4){
                    localballBody->SetLinearDamping(0.0f);
                    bs = bv.x * bv.x + bv.y * bv.y*15;
                }
                else if (speed>maxBallSpeedArcadeMode[localLevel]/1.4){
                    localballBody->SetLinearDamping(1.0f);
                }
            }
            else{
                bs = bv.x * bv.x + bv.y * bv.y*1.5;
                gs = gv.x * gv.x + gv.y * gv.y*1.5;
                
                if (bs > maxBallBSArcadeMode[localLevel]/3) {
                    b2Vec2 *bf = new b2Vec2(-bv.x * 10, -bv.y * 10);
                    localballBody->ApplyForceToCenter(*bf);
                }
                if(speed<maxBallSpeedArcadeMode[localLevel]/3)
                {
                    localballBody->SetLinearDamping(0.0f);
                    bs = bv.x * bv.x + bv.y * bv.y*10;
                }
                else if (speed>maxBallSpeedArcadeMode[localLevel]/3)
                {
                    localballBody->SetLinearDamping(1.0f);
                }
            }
            if(localdeviceResolutionInt==1 || localdeviceResolutionInt==6){
                if(bs<1200){
                    b2Vec2 *bf = new b2Vec2(bv.x * 10, bv.y * 10);
                    localballBody->ApplyForceToCenter(*bf);
                }
                if(gs<1200){
                    b2Vec2 *bf = new b2Vec2(bv.x * 10, bv.y * 10);
                    localballBody->ApplyForceToCenter(*bf);
                }
            }
            else{
                if(bs<600){
                    b2Vec2 *bf ;
                    if(localLevel<8)
                        bf = new b2Vec2(bv.x * 3, bv.y * 3);
                    else
                        bf = new b2Vec2(bv.x * 5, bv.y * 5);
                    
                    localballBody->ApplyForceToCenter(*bf);
                }
                if(gs<600){
                    b2Vec2 *bf;
                    if(localLevel<8)
                        bf = new b2Vec2(bv.x * 3, bv.y * 3);
                    else
                        bf = new b2Vec2(bv.x * 5, bv.y * 5);
                    localballBody->ApplyForceToCenter(*bf);
                }
            }
            if(bv.x==0 && bv.y==0){
                b2Vec2 v = b2Vec2(40, 40);
                ballArcadeMode->ballBody->ApplyForceToCenter(v);
                ballArcadeMode->ballBody->SetLinearVelocity(v);
            }
            
            if (bv.x<0){
                bv.x = -sqrt(bs - bv.y * bv.y);
            }
            else if (bv.y<0){
                bv.y = -sqrt(bs) / 2;
            }
            //            }
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
    localballBody=NULL;
}

void GameLayerArcadeMode::timerForPower(){
    int localcounterForPower = counterForPower;
    if(localcounterForPower == randomValueForPowerToAppear){
        localcounterForPower = 0;
        randomValueForPowerToAppear = 4;
        isPowerToGenerate = true;
    }
    else{
        localcounterForPower++;
    }
    counterForPower=localcounterForPower;
}

void GameLayerArcadeMode::disableMaxSpeed()
{
    if(speedMaxCounter==6){
        unschedule(schedule_selector(GameLayerArcadeMode::disableMaxSpeed));
        speedMaxCounter=0;
        powerCounterInt=0;
        isSpeedMax=false;
    }else{
        speedMaxCounter++;
    }
}

void GameLayerArcadeMode::gameWon(){
    this->pauseSchedulerAndActions();
    initAllObjects();
    if(animationLayerArcadeModeObj->getgameIsPaused()==true)
        animationLayerArcadeModeObj->pauseAndResume(NULL);
}

void GameLayerArcadeMode::removeGun(){
    if(isAddGun==true){
        isAddGun = false;
        int paddleLenght=myPaddleArcadeMode->getLengthState();
        myPaddleImageArcadeMode(myPaddleArcadeMode, isAddGun,paddleLenght, 0 );
    }
}
void GameLayerArcadeMode::gameEndedStartCounting()
{
    if(isGameEnded==false){
        //=============== Bottom to restict game over ====================================
        groundBox.Set(b2Vec2(0,0), b2Vec2(winSize.width/PTM_RATIO, 0));
        bottomFixture = groundBody->CreateFixture(&groundBoxDef);
        isGameEnded=true;
        isContingEnded=false;
        autostrip->setVisible(false);
    }
}

#pragma mark *************OnTransitionEnter*********************
GameLayerArcadeMode::~GameLayerArcadeMode()
{
}

void GameLayerArcadeMode::onExitTransitionDidStart()
{
    CCLayer::onExitTransitionDidStart();
}

void GameLayerArcadeMode::onEnterTransitionDidFinish() {
    CCLayer::onEnterTransitionDidFinish();
}

void GameLayerArcadeMode::createBallAtPaddlePos(cocos2d::CCPoint paddlePos)
{
    if (ballFixture != NULL) {
        myPaddleBody->DestroyFixture(myPaddleFixture);
        myPaddleFixture=NULL;
    }
    b2PolygonShape myPaddleShape;
    
    int paddleLenght=myPaddleArcadeMode->getLengthState();
    
    CCSprite *spr = myPaddleImageArcadeMode(myPaddleArcadeMode, 0,paddleLenght, 0 );
    
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
void GameLayerArcadeMode::buildMyPaddleWithNewPaddle(MyPaddle *myPaddleSpr)
{
    if(isBlackColorBackground==true)
    {
        if (myPaddleSpr->getLengthState() == 2) {
            buildMyPaddle("myLongPaddleNight.png");
        }
        else if (myPaddleSpr->getLengthState() == 0) {
            buildMyPaddle("myPaddleNight.png");
        }
        else if (myPaddleSpr->getLengthState() == 1) {
            buildMyPaddle("myShortPaddleNight.png");
        }
    }
    else
    {
        if (myPaddleSpr->getLengthState() == 2) {
            buildMyPaddle("myLongPaddle.png");
        }
        else if (myPaddleSpr->getLengthState() == 0) {
            buildMyPaddle("myPaddle.png");
        }
        else if (myPaddleSpr->getLengthState() == 1) {
            buildMyPaddle("myShortPaddle.png");
        }
    }
    
}

//=============== returns a number between low and (high - 1)====================
float GameLayerArcadeMode::randomValueBetween(float low , float high){
    return rand() % (int)high + (int)low;
}


#pragma mark animationManaget
void GameLayerArcadeMode::setAnimationManager(cocos2d::extension::CCBAnimationManager *animationManager)
{
    if (animationManager)
    {
        CC_SAFE_RELEASE_NULL(mAnimationManager);
        mAnimationManager = animationManager;
        CC_SAFE_RETAIN(animationManager);
    }
}
void GameLayerArcadeMode::powerCounterScheduler()
{
    buildBall("ball.png");
    schedule(schedule_selector(GameLayerArcadeMode::updateAtEachSeconds));
    schedule(schedule_selector(GameLayerArcadeMode::checkIfGameOver));
    isballHitPaddleInMagnet=true;
}

void GameLayerArcadeMode::playBrickBrokenSound(TargetPlatform deviceDetectedIs,CCSize windorSize)
{
    CCSize windowSize = windorSize;
    SoundManager::sharedSoundManager()->stopSoundEffect(brickBreakSound);
    brickBreakSound =SoundManager::sharedSoundManager()->playSoundEffect("Brick_Sound 6.wav", false);
}

void GameLayerArcadeMode::playPowerUpSound()
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


void GameLayerArcadeMode::removeAllBalls()
{
    list<Ball *> localballList=ballList;
    
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


void GameLayerArcadeMode::gameWonAndOverLabelDisplay()
{
    if(m_Bricks.size()==0){
    }
    else{
        animationLayerArcadeModeObj->gameOverDown(NULL);
    }
}





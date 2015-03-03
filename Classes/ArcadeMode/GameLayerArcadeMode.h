

//
//  GameLayerArcadeMode.h
//  Bricks
//
//  Created by Victor on 12/22/14.
//
//

#ifndef GameLayerArcadeMode_H_
#define GameLayerArcadeMode_H_

#define MAX_ITEM 3
#include "Box2D/Box2D.h"
#include "../Paddle/MyPaddle.h"
#include "../Ball/Ball.h"
#include "../Layers/SettingLayer.h"
#include "../PowerUp/EnlargeItem.h"
#include "../CollisionDetection/ContactListener.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "../PowerUp/AutoPlayItem.h"
#include "../PowerUp/ReverseYItem.h"
#include "../PowerUp/DoubleItem.h"
#include "../PowerUp/MagnetItem.h"
#include "../Sprite/Item.h"
#include "../PowerUp/FireBallItem.h"
#include "../PowerUp/ShortenItem.h"
#include "../PowerUp/BonusLife.h"
#include "../PowerUp/SlowDownSpeed.h"
#include <list>
#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include"../Paddle/Brick.h"
#include "../PowerUp/BonusScore.h"
#include "../Layers/SettingLayer.h"
#include "../PowerUp/FastSpeed.h"
#include "../Layers/LeaderBoardLayer.h"
#include  "../OBJCall/ImagePicker.h"
#include "../OBJCall/ObjCCalls.h"
#include "../OBJCall/CCMask.h"
#include "../ArcadeMode/AnimationLayerArcadeMode.h"
#include "../ArcadeMode/AnimationLayerLoaderArcadeMode.h"
#include "../ArcadeMode/BrickPosArcadeMode.h"
#include "../ArcadeMode/BriPosSetArcadeMode.h"

#define PTM_RATIO 32.0

using namespace cocos2d;
//static float maxBallSpeedArcadeMode[] = {
//    /*1*/ 0,32,35,35,40,40,48,50,52/*8*/,
//    /*2*/ 55,55,60,65,70,70,75,75,
//    /*3*/ 78,78,80,80,80,84,84,84,
//    /*4*/ 88,88,90,90,90,90,90,95,
//    /*5*/ 95,95,95,95,95,95,95,95,
//    /*6*/ 95,95,95,95,95,95,95,95,
//    /*7*/ 95,95,95,95,95,95,95,95,
//    /*8*/ 95,95,95,95,95,95,95,95,
//    /*9*/ 95,95,95,95,95,95,95,95
//
//};
//
//static float maxBallBSArcadeMode[] = {
//    /*1*/ 0,3200,3500,3500,4000,4000,4800,5000,5200,
//    /*2*/ 5500,5500,5500,5500,7000,7000,7500,7500,
//    /*3*/ 7800,7800,8000,8000,8000,8500,8500,8500,
//    /*4*/ 9200,9200,9200,9200,9200,9200,9200,9200,
//    /*5*/ 10000,10000,10000,10000,10000,10000,10000,10000,
//    /*6*/ 11000,11000,11000,11000,11000,11000,11000,11000,
//    /*7*/ 11000,11000,11000,11000,11000,11000,11000,11000,
//    /*8*/ 11000,11000,11000,11000,11000,11000,11000,11000,
//    /*9*/ 11000,11000,11000,11000,11000,11000,11000,11000,
//    /*10*/ 11000,11000,11000,11000,11000,11000,11000,11000
//
//};


//static float maxBallSpeedArcadeModeIpad[] = {
//    /*1*/ 0,70,70,70,70,70,70,70,70/*8*/,
//    80,80,80,80,90,90,90,90,
//    90,90,90,90,90,90,90,90,
//    90,90,90,90,90,90,90,90,
//    90,90,90,90,90,90,90,90,
//    90,90,90,90,90,90,90,90,
//    90,90,90,90,90,90,90,90,
//    90,90,90,90,90,90,90,90,
//    90,90,90,90,90,90,90,90,
//    90,90,90,90,90,90,90,90,
//    90,90,90,90,90,90,90,90,
//    90,90,90,90,90,90,90,90,
//
//};
//
//static float maxBallBSArcadeModeIpad[] = {
//    /*1*/ 0,7000,7000,7000,7000,7000,7000,7000,7000,
//    8000,8000,8000,8000,9000,9000,9000,9000,
//    9000,9000,9000,9000,9000,9000,9000,9000,
//    9000,9000,9000,9000,9000,9000,9000,9000,
//    9000,9000,9000,9000,9000,9000,9000,9000,
//    9000,9000,9000,9000,9000,9000,9000,9000,
//    9000,9000,9000,9000,9000,9000,9000,9000,
//    9000,9000,9000,9000,9000,9000,9000,9000,
//    9000,9000,9000,9000,9000,9000,9000,9000,
//    9000,9000,9000,9000,9000,9000,9000,9000,
//    9000,9000,9000,9000,9000,9000,9000,9000,
//    9000,9000,9000,9000,9000,9000,9000,9000,
//
//};


static float maxBallSpeedArcadeMode[] = {
    /*1*/ 0,45,45,45,45,45,45,45,45,
    45,45,45,45,45,45,45,45,
    45,45,45,45,45,45,45,45,
    45,45,45,45,45,45,45,45,
    45,45,45,45,45,45,45,45,
    45,45,45,45,45,45,45,45,
    45,45,45,45,45,45,45,45,
    45,45,45,45,45,45,45,45,
    45,45,45,45,45,45,45,45,
    45,45,45,45,45,45,45,45,
    45,45,45,45,45,45,45,45,
    45,45,45,45,45,45,45,45
};

static float maxBallBSArcadeMode[] = {
    /*1*/ 0,4500,4500,4500,4500,4500,4500,4500,4500,
    4500,4500,4500,4500,4500,4500,4500,4500,
    4500,4500,4500,4500,4500,4500,4500,4500,
    4500,4500,4500,4500,4500,4500,4500,4500,
    4500,4500,4500,4500,4500,4500,4500,4500,
    4500,4500,4500,4500,4500,4500,4500,4500,
    4500,4500,4500,4500,4500,4500,4500,4500,
    4500,4500,4500,4500,4500,4500,4500,4500,
    4500,4500,4500,4500,4500,4500,4500,4500,
    4500,4500,4500,4500,4500,4500,4500,4500,
    4500,4500,4500,4500,4500,4500,4500,4500,
    4500,4500,4500,4500,4500,4500,4500,4500
    
};


static CCSprite *longPaddleSprArcadeMode;
static CCSprite *shortPaddleSprArcadeMode;
static CCSprite *normalPaddleSprArcadeMode;
static CCLayer *bricksLayerArcadeMode;

//static float maxSpeed[] = {0,35,35,40,40,55,55,60,60};
//static float maxBS[] = {0,3000,3000,4000,4000,5000,5000,55000,5500,7000};
class GameLayerArcadeMode: public cocos2d::CCLayer
,public cocos2d::extension::CCBSelectorResolver
,public cocos2d::extension::CCBMemberVariableAssigner
,public cocos2d::extension::CCNodeLoaderListener
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(GameLayerArcadeMode, create);
    
    GameLayerArcadeMode();
    ~GameLayerArcadeMode();
    
    //CCB methods...
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
    virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
    virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName);
    
    virtual bool init();
    virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
    virtual void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);
    virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);
    virtual void  ccTouchesCancelled(CCSet *pTouches, CCEvent *pEvent);
    
    bool isFullBundleRequired;
    b2Body *myPaddleBody;
private:
    LeaderBoardLayer *lederBoardObj;
    TargetPlatform detectedDevice;
    int deviceResolutionSize;
    Item* item;
    CCSpriteFrame* mypaddleSpritFrame;
    CCSize winSize;
    CCLabelTTF *scoreLbl; CCLabelTTF *stageLbl;CCLabelTTF *animationLable;CCLabelTTF *countingLable;
    CCLabelTTF *scores;CCLabelTTF *globalPlayerLifeCountLabel;
    CCLabelTTF *powerCountLabel;CCLabelTTF *kachcheLabel; CCLabelTTF *kachcheLabelGameWon;
    CCRenderTexture* stroke;CCLabelTTF *instructionLabel;
    bool isInstructionLabelVisible;bool isAddNewBricks;
    
    MyPaddle* getMyPaddle();
    std::vector<Brick*> m_Bricks;
    std::vector<CCPoint> addOtherBricks;
    list<Item *> itemList;
    list<Ball *> ballList;
    
    CCPoint ballLastPos;
    CCPoint paddleLastPos;
    float randomValueForPowerToAppear;
    int playerLifeCount;int brickPointsArcadeMode;int lastPowerInt;
    int counterForPower;int autoPlayModeCounter;int gameStarterCounter;int reverseCounting;
    int speedMaxCounter;int powerCounterInt;int paddleCounter;
    int brickBreakSound;int currentLevelArcadeModePoint;int powerCreationcurrentLevelArcadeMode; int deviceResolutionInt; int currentLevelArcadeMode; int indexCurrentLevel;int multiBallCounterToDelete;
    int multiBallCount,autoPlayCount,bonusPointsCount,bonusLifeCount,largePaddleCount,mileStoneCount,lastPlayedMileStoneCount,mileStoneCountForDisplay,lastLevelBrickCountForArrangement;
    
    CCLayer *paddleLayer;CCLayerColor *navigationLayer;CCLayerColor *shapeBackLayer;
    
    bool isPaddleCreatedNotFirstTime;bool isPlayerLifeZero;bool isAllBricksRemoved;bool gameIsPaused;bool gameIsEnded;bool isAutoPlayMode;bool isPowerToGenerate;bool isAddGun;bool isTouchedOnPlayerPaddle;bool isGameEnded;bool isSlowDownSpeed;bool isDestroyedGameOverPaddle;bool isCallOnce;bool isgameover;bool isContingEnded;bool isAutoPlayModeActive,isAddedBricksMoreThanOnce;
    bool isBallRecreated;bool isGameStarted;bool isTouchedOnPaddlefront;bool isMagnetEnabled;
    bool isballHitPaddleInMagnet;bool isBallRecreatedAndTouched;bool isReleaseBall;bool isBallDownToPaddlePos;bool isSpeedMax;bool isMultiBallCreated;bool isPaddleTimerEnable;bool isNavigationLayerAllObjectGotInitialised;bool isUserPlayingGame;bool isdeleteMultiBalls;bool isCallMoveEleMent,isFourtyBrickOnScreen,isFourtyBrickBelowHalfScreen,isMileStoneCountTwo,isMileStoneCountThree;
    bool isBlackColorBackground;bool isPowerMultiBallVisible,isBallBreakFirstBrick,isAddedOtherBricks;
    
    
    cocos2d::extension::CCBAnimationManager *mAnimationManager;
    AnimationLayerArcadeMode *animationLayerArcadeModeObj;
    CCParticleSystem*    m_pFireEmitter;
    ContactListener* m_contactListener;
    
    CCSprite* scoresLabel; CCSprite *shapeSpr;CCSprite *backGroundSpr;CCSprite *autostrip;CCSprite *stageSpr;CCSprite *scoreSpr;CCSprite *ballTopSpr;CCSprite *gameOverStrip;
    CCPoint previousPosition;
    std::vector<b2Body*> toRemove;
    
    static Ball *ballArcadeMode;
    static MyPaddle *myPaddleArcadeMode;

    b2World *world;
    b2Body *groundBody;
    b2Fixture *bottomFixture;
    b2Fixture *ballFixture;
    b2Fixture *myPaddleFixture;
    b2MouseJoint *_mouseJoint;
    b2EdgeShape groundBox;
    b2FixtureDef groundBoxDef;
    b2BodyDef myPaddleBodyDef;
    b2BodyDef ballBodyDef;
    b2Vec2 velocityBeforeFrozen;
    void moveElement(float delta);
    float brickLastPosY;
    
    void playPowerUpSound();
    void playBrickBrokenSound(TargetPlatform device,CCSize windowSize);
    void powerCounterScheduler();
    void disableMaxSpeed();
    void gameWonAndOverLabelDisplay();
    void buildMyPaddleWithNewPaddle(MyPaddle *paddle);
    void createBallAtPaddlePos(CCPoint paddlePos);
    void decrementPlayerLife();
    void initAllObjects();
    void onEnterTransitionDidFinish();
    void onExitTransitionDidStart();
    void brickFallDown();
    void gameWon();
    void removeGun();
    void startGame();
    void addPoints(int tag);
    void dropDownPowerFromPosition(CCSprite *brickPos);
    void moveBrickDownToOriginalPos();
    void autoPlayCounter(string counter);
    void enlargePaddle();
    void paddleTimer();
    void avoidUnwantedSituation(int level);
    void autoPlayGame();
    void reverseBallYVelocity();
    void shortenPaddle();
    void bonusBallLife();
    void slowDownBallSpeed();
    void autoPlayTimer();
    void buildBall(std::string ballType);
    void buildMyPaddle(std::string paddleName);
    void buildBrickPaddle();
    void buildGround();
    void restrictPaddleMovement();
    void gameOver();
    void powerUpItems();
    void removeBullet();
    void timerForPower();
    void checkIfGameOver();
    void powerCreationAndDropDown(CCPoint itemPos);
    void gameWonRestartConfirm();
    void updateAtEachSeconds(float delta);
    void setAnimationManager(CCBAnimationManager *pAnimationManager);
    void disablePaddleMovement();
    void gameEndedStartCounting();
    void ballSetNormalSpeed();
    void enableMagnet();
    void removeAllBalls();
    void callMeToArrangeNextBricks();
    void onPausePressedFromAnimationLayerArcadeMode();
    void onRestartButtonPressed();
    void deleteMultiBalls();
    void applyBlinkEffectOnBall(CCSprite *spr);
    void callOnceToReScheduleMoveElement();
    float randomValueBetween(float low , float high);

};

#endif /* GameLayerArcadeMode_H_ */

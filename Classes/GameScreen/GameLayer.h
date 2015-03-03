
#ifndef GAMELAYER_H_
#define GAMELAYER_H_

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
#include "../PowerUp/BulletItem.h"
#include "../PowerUp/DoubleItem.h"
#include "../PowerUp/MagnetItem.h"
#include "../Sprite/Item.h"
#include "../PowerUp/FireBallItem.h"
#include "../PowerUp/ShortenItem.h"
#include "../PowerUp/BonusLife.h"
#include "../PowerUp/CoinItem.h"
#include "../PowerUp/SlowDownSpeed.h"
#include <list>
#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include"../Paddle/Brick.h"
#include "../PowerUp/Bullet.h"
#include "../PowerUp/BonusScore.h"
#include "../Layers/AnimationLayerLoader.h"
#include "../Layers/AnimationLayer.h"
#include "../Layers/SettingLayer.h"
#include "../PowerUp/FastSpeed.h"
#include "../GameManager/BrickPosition.h"
#include "../GameManager/BrickPosSetting.h"
#include "../GameManager/GameScreenConstant.h"
#include "../Layers/LeaderBoardLayer.h"
#include "../OBJCall/ObjCCalls.h"

#define PTM_RATIO 32.0

using namespace cocos2d;
static int butlletTotalTimer;
static int autoPlayTotalTimer;
static int largepaddleTotalTimer;

//static float maxSpeedIpad[] = {
//    /*1*/ 0,41,42,43,44,45,46,47,48/*8*/,
//    /*2*/ 41,42,43,44,45,46,47,48/*16*/,
//    /*3*/ 49,50,51,52,53,54,55,56/*24*/,
//    /*4*/ 57,58,59,60,60,61,62,63/*32*/,
//    /*5*/ 64,65,66,67,68,69,70,71/*40*/,
//    /*6*/ 72,73,74,75,76,77,78,79/*48*/,
//    /*7*/ 80,80,80,80,80,80,80,80/*56*/,
//    /*8*/ 95,95,95,95,95,95,95/*64*/,
//    /*8*/ 95,95,95,95,95,95,95/*72*/,
//    /*8*/ 95,95,95,95,95,95,95
//};
//
//static float maxAverageSpeedIpad[] = {
//    /*1*/ 0,4100,4200,4300,4400,4500,4600,4700,4800/*8*/,
//    /*2*/ 4100,4200,4300,4400,4500,4600,4700,4800/*16*/,
//    /*3*/ 4900,5000,5100,5200,5300,5400,5500,5600/*24*/,
//    /*4*/ 5700,5800,5900,6000,6000,6100,6200,6300/*32*/,
//    /*5*/ 6400,6500,6600,6700,6800,6900,7000,7100/*40*/,
//    /*6*/ 7200,7300,7400,7500,7600,7700,7800,7900/*48*/,
//    /*7*/ 8000,8000,8000,8000,8000,8000,8000,8000/*56*/,
//    /*8*/ 9500,9500,9500,9500,9500,9500,9500/*64*/,
//    /*8*/ 9500,9500,9500,9500,9500,9500,9500/*72*/,
//    /*8*/ 9500,9500,9500,9500,9500,9500,9500
//};

static float maxSpeedIpad[] = {
    /*1*/ 0,40,40,40,40,40,40,40,40,
    55,55,55,55,60,60,60,60,
    65,65,65,65,65,65,65,65,
    65,65,65,65,65,65,65,65,
    65,65,65,65,65,65,65,65,
    65,65,65,65,65,65,65,65,
    65,65,65,65,65,65,65,65,
    65,65,65,65,65,65,65,65,
    65,65,65,65,65,65,65,65,
    65,65,65,65,65,65,65,65,
    65,65,65,65,65,65,65,65,
    65,65,65,65,65,65,65,65
    
};

static float maxAverageSpeedIpad[] = {
    /*1*/ 0,4000,4000,4000,4000,4000,4000,4000,4000,
    5500,5500,5500,5500,6000,6000,6000,6000,
    6500,6500,6500,6500,6500,6500,6500,6500,
    6500,6500,6500,6500,6500,6500,6500,6500,
    6500,6500,6500,6500,6500,6500,6500,6500,
    6500,6500,6500,6500,6500,6500,6500,6500,
    6500,6500,6500,6500,6500,6500,6500,6500,
    6500,6500,6500,6500,6500,6500,6500,6500,
    6500,6500,6500,6500,6500,6500,6500,6500,
    6500,6500,6500,6500,6500,6500,6500,6500,
    6500,6500,6500,6500,6500,6500,6500,6500,
    6500,6500,6500,6500,6500,6500,6500,6500
};



static float maxSpeedIpod[] = {
    /*1*/ 0,25,26,27,28,29,30,39,40/*8*/,
    /*2*/ 41,42,43,44,45,46,47,48/*16*/,
    /*3*/ 49,50,51,52,53,54,55,56/*24*/,
    /*4*/ 57,58,59,60,60,61,62,63/*32*/,
    /*5*/ 64,65,66,67,68,69,70,71/*40*/,
    /*6*/ 72,73,74,75,76,77,78,79/*48*/,
    /*7*/ 79,79,79,79,80,80,80,80/*56*/,
    /*8*/ 95,95,95,95,95,95,95/*64*/,
    /*8*/ 95,95,95,95,95,95,95/*72*/,
    /*8*/ 95,95,95,95,95,95,95
};

static float maxAverageSpeedIpod[] = {
    /*1*/ 0,2500,2600,2700,2800,2900,3000,3900,4000/*8*/,
    /*2*/ 4100,4200,4300,4400,4500,4600,4700,4800/*16*/,
    /*3*/ 4900,5000,5100,5200,5300,5400,5500,5600/*24*/,
    /*4*/ 5700,5800,5900,6000,6000,6100,6200,6300/*32*/,
    /*5*/ 6400,6500,6600,6700,6800,6900,7000,7100/*40*/,
    /*6*/ 7200,7300,7400,7500,7600,7700,7800,7900/*48*/,
    /*7*/ 7900,7900,7900,7900,8000,8000,8000,8000/*56*/,
    /*8*/ 9500,9500,9500,9500,9500,9500,9500/*64*/,
    /*8*/ 9500,9500,9500,9500,9500,9500,9500/*72*/,
    /*8*/ 9500,9500,9500,9500,9500,9500,9500
};


static CCSprite *longPaddleSpr;
static CCSprite *shortPaddleSpr;
static CCSprite *normalPaddleSpr;
static CCLayer *bricksLayer;
static  int currentLevel;
class GameLayer: public cocos2d::CCLayer
,public cocos2d::extension::CCBSelectorResolver
,public cocos2d::extension::CCBMemberVariableAssigner
,public cocos2d::extension::CCNodeLoaderListener

{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(GameLayer, create);
    
    GameLayer();
    ~GameLayer();
    
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
    
    b2Body *myPaddleBody;
private:
    LeaderBoardLayer *lederBoardObj;
    TargetPlatform detectedDevice;
    int deviceResolutionSize;
    Item* item;
    CCSpriteFrame* mypaddleSpritFrame;
    CCSize winSize;
    CCLabelTTF *scoreLbl; CCLabelTTF *stageLbl;CCLabelTTF *animationLable;CCLabelTTF *countingLable;
    CCLabelTTF *scores;CCLabelTTF *globalPlayerLifeCountLabel;CCLabelTTF *coinLabel;
    CCLabelTTF *powerCountLabel;CCLabelTTF *kachcheLabel; CCLabelTTF *kachcheLabelGameWon;
    CCRenderTexture* stroke;CCLabelTTF *instructionLabel;
    bool isInstructionLabelVisible;
    
    MyPaddle* getMyPaddle();
    std::vector<Brick*> m_Bricks;
    std::vector<Brick*> hardBricks;
    std::vector<Brick*> blackBricks;
    std::vector<b2Body*> itemToDelete;
    list<Item *> itemList;
    list<Ball *> ballList;
    list<Bullet *> leftBulletList;
    list<Bullet *> rightBulletList;
    
    CCArray *coinAnimateArray;
    int randomValueForPowerToAppear;
    int bulletCount;int playerLifeCount;int brickPoints;
    int counterForPower;int autoPlayModeCounter;int gameStarterCounter;int reverseCounting;int coinTimer;
    int coinCountDownStart;int coinCounter;int speedMaxCounter;int powerCounterInt;int paddleCounter;
    int brickBreakSound;int currentLevelPoint;int powerCreationCurrentLevel; int deviceResolutionInt;
    int bulletTimerCount,multiBallCount,autoPlayCount,bonusPointsCount,bonusLifeCount,largePaddleCount;int multiBallCounterToDelete;
    
    CCLayer *paddleLayer;CCLayerColor *navigationLayer;CCLayerColor *shapeBackLayer;
    
    bool skewDirectionIsRight;bool isPaddleCreatedNotFirstTime;bool isPlayerLifeZero;bool isAllBricksRemoved;bool gameIsPaused;bool gameIsEnded;bool isAutoPlayMode;bool isPowerToGenerate;bool isAddGun;bool isTouchedOnPlayerPaddle;bool isGameEnded;bool isSlowDownSpeed;bool isDestroyedGameOverPaddle;bool isCallOnce;bool isgameover;bool isContingEnded;bool isAutoPlayModeActive;
    bool isBallRecreated;bool isGameStarted;bool isTouchedOnPaddlefront;bool isMagnetEnabled;
    bool isCoinToGenerate;bool isballHitPaddleInMagnet;bool isBallRecreatedAndTouched;bool isReleaseBall;bool isBallDownToPaddlePos;bool isSpeedMax;bool isMultiBallCreated;bool isPaddleTimerEnable;bool isNavigationLayerAllObjectGotInitialised;bool isdeleteMultiBalls;
    bool isBlackColorBackground;bool isPowerMultiBallVisible;bool isGameWonForNextLevel;bool isTimeToRemoveGun;
    
    bool isPowerFlagBulletSet,isPowerFlagMultiBallSet,isPowerFlagAutoPlaySet,isPowerFlagBonusLifeSet,isPowerFlagBonusPointsSet,isPowerFlagLargePaddleSet,isPowerFlagSlowBallSet,isPowerFlagMagnetSet,isPowerFlagReverseBallSet,isPowerFlagShortPaddleSet,isPowerFlagFastBallSet,isMagnetAndMultiBallEnable;
    
    int isPowerFlagBulletSetCount,isPowerFlagMultiBallSetCount,isPowerFlagAutoPlaySetCount,isPowerFlagBonusPointsSetCount,isPowerFlagLargePaddleSetCount,isPowerFlagSlowBallSetCount,isPowerFlagMagnetSetCount,isPowerFlagReverseBallSetCount,isPowerFlagShortPaddleSetCount,isPowerFlagFastBallSetCount,isRepeatMultiBall,isMagnetRepeat;
    
    int lastPowerInt, deviceResolutionForLocal;
    cocos2d::extension::CCBAnimationManager *mAnimationManager;
    AnimationLayer *animationLayerObj;
    CCParticleSystem*    m_pFireEmitter;
    ContactListener* m_contactListener;
    
    CCArray *powerBonusLifeArr;
    CCSprite* scoresLabel; CCSprite *shapeSpr;CCSprite *backGroundSpr;CCSprite *autostrip;CCSprite *topLineSpr;CCSprite *stageSpr;CCSprite *scoreSpr;CCSprite *ballTopSpr;CCSprite *coinSpr;
    CCPoint previousPosition;
    std::vector<b2Body*> toRemove;
    std::vector<b2Body*> bulletToRemove;
    
    static Ball *ball;
    static Ball *fireBall;
    static Bullet *bulletFired;
    static MyPaddle *myPaddle;
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
    void updateGunPosition(TargetPlatform platform,int level);
    void addPoints(int tag);
    void dropDownPowerFromPosition(CCSprite *brickPos,TargetPlatform device);
    void moveBrickDownToOriginalPos();
    void autoPlayCounter(string counter);
    void enlargePaddle();
    void paddleTimer();
    void bulletCounterTrace();
    void bulletTimer();
    void avoidUnwantedSituation(int level);
    void autoPlayGame();
    void reverseBallYVelocity();
    void freezeBall();
    void shortenPaddle();
    void bonusBallLife();
    void slowDownBallSpeed();
    void autoPlayTimer();
    void buildBall(std::string ballType);
    void buildMyPaddle(std::string paddleName);
    void buildBrickPaddle();
    void buildGround();
    void buildBullet(std::string bulletType);
    void restrictPaddleMovement();
    void gameOver();
    void powerUpItems();
    void removeBullet(CCSize windoSize,TargetPlatform platform);
    void timerForPower();
    void checkIfGameOver();
    void powerCreationAndDropDown(CCPoint itemPos,TargetPlatform device);
    void gameWonRestartConfirm();
    void updateAtEachSeconds(float delta);
    void setAnimationManager(CCBAnimationManager *pAnimationManager);
    void disablePaddleMovement();
    void gameEndedStartCounting();
    void ballSetNormalSpeed();
    void enableMagnet();
    void enableCoinToDrop();
    void addCoins(int number);
    void releaseLayerMemory();
    void removeAllBalls();
    void onPausePressedFromAnimationLayer();
    void save_ChallengeCurrentUserScore(CCDictionary *user);
    void deleteMultiBalls();
    void applyBlinkEffectOnBall(CCSprite *spr);
    void onRestartGameLayer();
    int randomNumberBetween(int min, int max);
    
    CCArray*  get_Challenge_userslist();
    
    float randomValueBetween(float low , float high);
    //    void removeAllBalls();
};

#endif /* GAMELAYER_H_ */

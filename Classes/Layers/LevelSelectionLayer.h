

#ifndef __LevelSelectionLayer_SCENE_H__
#define __LevelSelectionLayer_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "../CCGestureRecognizer/CCSwipeGestureRecognizer.h"
using namespace cocos2d;
USING_NS_CC;
USING_NS_CC_EXT;

class LevelSelectionLayer : public cocos2d::CCLayer
, public cocos2d::extension::CCBSelectorResolver
, public cocos2d::extension::CCBMemberVariableAssigner
, public cocos2d::extension::CCNodeLoaderListener

{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(LevelSelectionLayer, create);
    //CCB methods...
    virtual void onEnter();
    virtual void onExit();
    
    //CCB methods...
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
    virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
    virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName);
    
    virtual bool init();
    CCSwipeGestureRecognizer * swipe;
    CCLabelTTF *lableLevel1;
    CCLabelTTF *lableLevel2;
    CCLabelTTF *lableLevel3;
    CCLabelTTF *lableLevel4;
    CCLabelTTF *lableLevel5;
    CCLabelTTF *lableLevel6;
    CCLabelTTF *lableLevel7;
    CCLabelTTF *swipeIndicationLabel;
    CCSprite *backgroundImage;
    
    LevelSelectionLayer();
    virtual ~LevelSelectionLayer();
    
    virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);
    virtual void  ccTouchesCancelled(CCSet *pTouches, CCEvent *pEvent);
    
    void menuItemClicked(CCObject *sender,int level);
    void onBackClicked(CCObject *sender);
    void onHomeClicked(CCObject *sender);

    CCLayerColor *navigationLayerTop;
    CCLayerColor *navigationHomeLayer;
    CCLayerColor *navigationBackLayer;
    CCLabelTTF *wondersNameLbl;
    CCMenu *menuLevels;
    CCLayerColor *levelLayer1,*levelLayer2,*levelLayer3,*levelLayer4,*levelLayer5,*levelLayer6,*levelLayer7,
    *levelLayer8;
    CCLabelTTF *level1,*level2,*level3,*level4,*level5,*level6,*level7,*level8;
    
    CCSprite *playRePlaySprFirst,*playRePlaySprSecond,*playRePlaySprThird,*playRePlaySprFourth,*playRePlaySprFifth,*playRePlaySprSixth,*playRePlaySprSeventh,*playRePlaySprEighth;

    CCArray *getIsLevelClearArr;
    
    int currentStageToComplete;
    int lastPlayedlevel;
    bool isAnyLevelCleared, isConnectToInternet;
    int inAppCounter;
    bool checkInAppWithbool;
    
    bool inAppEffielTower;
    bool inAppStatueOfLiberty;
    bool inAppTowerOfPisa;
    bool inAppBigBen;
    bool inAppColosseum;
    bool inAppOperaHouse;
    bool inAppEasterStone;
    bool inAppUnlockAllMonuments;
    bool isInAppPurchased;
    void goToLevel(int levelClicked,int bgActivityIndiactor);
    void onDidSwipe(cocos2d::CCObject * pSender);
    
    void reflectChangesInUi();
    
    int getIsLevelCleared(int currentLevelNumber);
    int getStarCountAccordingToLevel(int currentLevelNumber);
 
    int getisInAppPurchased(int currentLevelNumber);
    CCSize winSize;
    // game loop that animates the globe
    void                                update(float dt);
    
};

#endif // __LevelSelectionLayer_SCENE_H__

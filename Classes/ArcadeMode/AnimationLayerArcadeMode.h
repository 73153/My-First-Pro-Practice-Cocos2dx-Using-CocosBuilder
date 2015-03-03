

#ifndef AnimationLayerArcadeMode_H_
#define AnimationLayerArcadeMode_H_

#include "cocos2d.h"
#include "cocos-ext.h"
#include <iostream>


using namespace cocos2d;
USING_NS_CC;
USING_NS_CC_EXT;
class AnimationLayerArcadeMode:  public cocos2d::CCNode
, public cocos2d::extension::CCBSelectorResolver
, public cocos2d::extension::CCBMemberVariableAssigner
, public cocos2d::extension::CCNodeLoaderListener

{
public:
    
    
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(AnimationLayerArcadeMode, create);
    //CCB methods...
    virtual void onEnter();
    AnimationLayerArcadeMode();
    virtual ~AnimationLayerArcadeMode();
    //CCB methods...
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
    virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
    virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName);
    
    CCLayerColor *  menuLayer;
     CCLayerColor *  pauseAndPlayLayer;
     CCLayerColor *  stageLayer;
    CCLabelTTF* KaccheGameOverLabel;
    
     CCMenuItemImage *pauseMenuItemButton;
    CCMenuItemImage*stageMenuItemButton;
     CCMenu * pauseMenuButton;
    CCMenu* stageMenuButton;
    
     CCMenuItemImage * menuBtn;
     CCMenuItemImage * restartBtn;
     CCMenuItemImage *resumeBtn;
     bool   isPausePressed;
    bool isPlayAgain,isMileStoneAcieved;
    CCLabelTTF* scoreCountLbl,*continuePlayLbl;
    CCLabelTTF* kacheLabelGameWon;
    CCLabelTTF* gameOverLabelNotUsed;
    CCLabelTTF*restartAnotherLabelNotUsed;
    CCLabelTTF*continueLabelNotUsed;
    CCLabelTTF* resumeLabelNotUsed;
    int tempLevelForPositionTaking;
    
    cocos2d::extension::CCBAnimationManager *mAnimationManager;

    void pauseAndResume(cocos2d::CCObject * pSender);
     void restart(cocos2d::CCObject * pSender);
     void menuPressed(cocos2d::CCObject * pSender);
    void playAgainPressed(cocos2d::CCObject * pSender);
    void playAgainUp(cocos2d::CCObject * pSender);
    void gameWonDown(cocos2d::CCObject * pSender);
    void goToNextLevel(cocos2d::CCObject * pSender);
    void removeUnusedData();
    void keyBackClicked();
    void resumeGame();
    void onInAppPurchaseClicked(cocos2d::CCObject * pSender);
    void gameOverDown(cocos2d::CCObject * pSender);
    void backButtonPressed();
    void mileStoneCompleted(cocos2d::CCObject * pSender);
    void mileStoneCompletedResume(cocos2d::CCObject * pSender);
    virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
    CCSize winSize;
    CC_SYNTHESIZE(bool , gameIsPaused, gameIsPaused);
    void onStagePressed(cocos2d::CCObject * pSender);
    CCLabelTTF* restartLabelNotUsed;
    CCLabelTTF* menuLabelNotUsed;
    CCLabelTTF* scoreLabelNotUsed;
    CCLabelTTF *sroreLabelNotUsed;
    
};



#endif /* AnimationLayerArcadeMode_H_ */

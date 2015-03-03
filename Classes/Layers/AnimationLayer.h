

#ifndef AnimationLayer_H_
#define AnimationLayer_H_

#include "cocos2d.h"
#include "cocos-ext.h"
#include <iostream>


using namespace cocos2d;
USING_NS_CC;
USING_NS_CC_EXT;
class AnimationLayer:  public cocos2d::CCNode
, public cocos2d::extension::CCBSelectorResolver
, public cocos2d::extension::CCBMemberVariableAssigner
, public cocos2d::extension::CCNodeLoaderListener

{
public:
    
    
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(AnimationLayer, create);
    //CCB methods...
    virtual void onEnter();
    AnimationLayer();
    virtual ~AnimationLayer();
    //CCB methods...
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
    virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
    virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName);
    
   
   
    CC_SYNTHESIZE( CCLayerColor * , menuLayer, menuLayer);
    CC_SYNTHESIZE( CCLayerColor * , pauseAndPlayLayer, pauseAndPlayLayer);
    CC_SYNTHESIZE( CCLayerColor * , stageLayer, stageLayer);
    CC_SYNTHESIZE(CCLayerColor*, multiBallTopPowerLayer, multiBallTopPowerLayer);
    CC_SYNTHESIZE(CCSprite*, multiBallTopPowerSpr, multiBallTopPowerSpr);
    CC_SYNTHESIZE(CCLabelTTF*, KaccheGameOverLabel, KaccheGameOverLabel);
    
    CC_SYNTHESIZE( CCMenuItemImage * , pauseMenuItemButton, pauseMenuItemButton);
    CC_SYNTHESIZE(CCMenuItemImage*, stageMenuItemButton, stageMenuItemButton);
    CC_SYNTHESIZE( CCMenu * , pauseMenuButton, pauseMenuButton);
    CC_SYNTHESIZE(CCMenu*, stageMenuButton, stageMenuButton);
    
    CC_SYNTHESIZE( CCMenuItemImage * , menuBtn, menuBtn);
    CC_SYNTHESIZE( CCMenuItemImage * , restartBtn, restartBtn);
    CC_SYNTHESIZE( CCMenuItemImage * , resumeBtn, resumeBtn);
    CC_SYNTHESIZE( bool  , isPausePressed, isPausePressed);
    CC_SYNTHESIZE(bool, isPlayAgain, isPlayAgain);
    CC_SYNTHESIZE(CCLabelTTF*, scoreCountLbl, scoreCountLbl);
    CC_SYNTHESIZE(CCLabelTTF*, kacheLabelGameWon, kacheLabelGameWon);
    CC_SYNTHESIZE(CCLabelTTF*, gameOverLabelNotUsed, gameOverLabelNotUsed);
    CC_SYNTHESIZE(CCLabelTTF*,restartAnotherLabelNotUsed,restartAnotherLabelNotUsed);
    CC_SYNTHESIZE(CCLabelTTF*,continueLabelNotUsed,continueLabelNotUsed);
    CC_SYNTHESIZE(    CCLabelTTF* , scoreLabelNotUsed, scoreLabelNotUsed);
    CCLabelTTF* resumeLabelNotUsed;
    

//private:
    cocos2d::extension::CCBAnimationManager *mAnimationManager;
    //    CC_SYNTHESIZE(CCMenu* , pauseButton, pauseButton);

    //    void	setDelegate ( AnimationLayerDelegate* pDelegate );
    //    AnimationLayerDelegate *animationDelegte;
    

    void pauseAndResume(cocos2d::CCObject * pSender);
     void restart(cocos2d::CCObject * pSender);
     void menuPressed(cocos2d::CCObject * pSender);
    void playAgainPressed(cocos2d::CCObject * pSender);
    void playAgainUp(cocos2d::CCObject * pSender);
    void gameWonDown(cocos2d::CCObject * pSender);
    void goToNextLevel(cocos2d::CCObject * pSender);
    void playLableAnimation(cocos2d::CCObject * pSender);
    void removeUnusedData();
    void keyBackClicked();
    void newUserAuthentication(cocos2d::CCObject * pSender);
    void resumeGame();
    void onInAppPurchaseClicked(cocos2d::CCObject * pSender);
    void gameOverDown(cocos2d::CCObject * pSender);
    void backButtonPressed();
    virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
    CCSize winSize;
    CC_SYNTHESIZE(bool , gameIsPaused, gameIsPaused);

    void onStagePressed(cocos2d::CCObject * pSender);
    CCLabelTTF* restartLabelNotUsed;
    CCLabelTTF* menuLabelNotUsed;
    CCLabelTTF *sroreLabelNotUsed;
    
};

//class AnimationLayerDelegate{
//    public :
//    virtual void        removeAllChildern(void)=0;
//    virtual void        pauseTheGame(void)=0;
//    virtual void        resumeTheGame(void)=0;
//};

#endif /* AnimationLayer_H_ */

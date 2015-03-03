

#ifndef MENULAYER_H_
#define MENULAYER_H_

#include <string>
#include "cocos2d.h"
#include "cocos-ext.h"

using namespace cocos2d;
class MenuLayer:public  cocos2d::CCLayer
, public cocos2d::extension::CCBSelectorResolver
, public cocos2d::extension::CCBMemberVariableAssigner
, public cocos2d::extension::CCNodeLoaderListener
{
    
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(MenuLayer, create);
    //CCB methods...
    MenuLayer();
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
    virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
    virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName);
    
    CCMenuItemImage *arcadeMenuItemSpr;
    CCMenuItemImage *challengeMenuItemSpr;
    CCLayerColor *moreLayer;
    CCLayerColor *storeLayer;
    CCLayerColor *settingLayer;
    cocos2d::extension::CCBAnimationManager *mAnimationManager;
    virtual bool init();
    CCMenuItemImage *moreBtn;
    CCMenuItemImage *settingBtn;
    CCLabelTTF *settingLbl;
    CCLabelTTF *moreLbl;
    CCLabelTTF *storeLabelDisplay;
    CCSprite *backWoodenBG;
    void removeUnusedData();
    void menuQuit(CCObject *pSender);
    void menuStart(CCObject *pSender);
    void menuHelpClicked(CCObject *pSender);
    void menuMoreClicked(CCObject *pSender);
    void menuSetting(CCObject *pSender);
    int getIsLevelCleared(int currentLevelNumber);
    CCArray *getIsLevelClearArr;
    
    void callSubmitScore();
    
    void menuArcdeModeStart(CCObject *sender);
    static void getHighScoreFromFile();
    static void getControlModeFromFile();
    void playAnimation(CCNode* sender);
    virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
private:
    void initBackground();
    void initMenu();
    void actionCallback();
    static bool haveSavedFile();
};

#endif /* MENULAYER_H_ */



#ifndef SETTINGLAYER_H_
#define SETTINGLAYER_H_

#include "cocos2d.h"
#include "CCControlSlider.h"
#include "MenuLayer.h"
#include "cocos2d.h"
#include "cocos-ext.h"
#include <string.h>
#include "cocos-ext.h"
#include  "../OBJCall/ImagePicker.h"
#include "../OBJCall/ObjCCalls.h"
#include "../OBJCall/CCMask.h"
using namespace cocos2d;
using namespace cocos2d::extension;

//class SettingLayerDelegate;

class SettingLayer:public cocos2d::CCLayer
,public cocos2d::extension::CCBSelectorResolver
,public cocos2d::extension::CCBMemberVariableAssigner
,public cocos2d::extension::CCNodeLoaderListener
{
public:
    
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(SettingLayer, create);
    //CCB methods...
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
    virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
    virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName);
    
    virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
    
    CC_SYNTHESIZE(bool, isSettingBtnClicked, isSettingBtnClicked);
    SettingLayer();
    virtual ~SettingLayer();
    enum ControlType {
        Night, Day
    };
    static int getControlMode();
    static void setControlMode(ControlType mode);
    static ControlType controlMode;
    
    CCLabelTTF *moreAppLabelNotUsed;CCLabelTTF *feedBackLabelNotUsed;CCLabelTTF *supportLabelNotUsed;
    CCLabelTTF *howItWorkLabelNotUsed;CCLabelTTF *soundLabelNotUsed;CCLabelTTF *followUsLabelNotUsed;
    CCLabelTTF *settingMainLabel;CCLabelTTF *rateUsLabelNotUsed;
    
    //    CC_SYNTHESIZE(CCLabelTTF *,grvityControlLbl,grvityControlLbl);
    CC_SYNTHESIZE(CCMenuItemImage*, settingBtn, settingBtn);
    
    CC_SYNTHESIZE(CCLayerColor*, settingBtnLayer, settingBtnLayer);
    CCLayer *soundLayer;CCLayer *aboutLayer;CCLayer *helpLayer;CCLayer *feedbackLayer;
    CCLayer *shareLayer;
    CCLayer*onOffWhiteLayer;CCLayer *rateUsLayer;
    CCMenuItemImage *offMenuItemButton;CCMenuItemImage *onMenuItemButton;CCMenuItemImage *twitterBtn;
    CCMenuItemImage *faceBookBtn;CCMenuItemImage *moreAppsBtn;
    
    void onFaceBookClicked(CCObject *sender);
    void onTwitterClicked(CCObject *sender);
    void showAboutLayer(CCObject *sender);
    void showHelpLayer(CCObject *sender);
    void showFeedBackLayer(CCObject *sender);
    void showShareLayer(CCObject *sender);
    void onMoreAppsClicked(CCObject *sender);
    void soundOnOff(CCObject *sender);
    bool isSoundOn;
    
private:
    cocos2d::extension::CCBAnimationManager *mAnimationManager;
    bool init();
    void settingBtnClicked(CCObject* pSender);
    
};

//class SettingLayerDelegate
//{
//    public :
//    virtual void        removeAllChildern(void)=0;
//    virtual void        pauseTheGame(void)=0;
//    virtual void        resumeTheGame(void)=0;
//};

#endif /* SETTINGLAYER_H_ */

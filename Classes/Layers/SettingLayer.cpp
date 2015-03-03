

#include "../Layers/SettingLayer.h"
#include "../Layers/MenuLayer.h"
#include "../Layers/MenuLayerLoader.h"
#include "../GameManager/GameManager.h"
#include "../Layers/HelpLayer.h"
#include "../Layers/HelpLayerLoader.h"
#include "SimpleAudioEngine.h"
#include "../ArcadeMode/GameLayerArcadeMode.h"
#include "../ArcadeMode/GameLayerArcadeModeLoader.h"
using namespace CocosDenshion;
using namespace cocos2d;
using namespace cocos2d::extension;

SettingLayer::ControlType SettingLayer::controlMode;

SettingLayer::SettingLayer():settingBtnLayer(NULL),settingBtn(NULL),soundLayer(NULL),isSettingBtnClicked(false),isSoundOn(false),aboutLayer(NULL),helpLayer(NULL),feedbackLayer(NULL),shareLayer(NULL),onMenuItemButton(NULL),offMenuItemButton(NULL),twitterBtn(NULL),faceBookBtn(NULL),moreAppLabelNotUsed(NULL),feedBackLabelNotUsed(NULL),supportLabelNotUsed(NULL),howItWorkLabelNotUsed(NULL),soundLabelNotUsed(NULL),followUsLabelNotUsed(NULL),moreAppsBtn(NULL),settingMainLabel(NULL),rateUsLabelNotUsed(NULL),rateUsLayer(NULL)
{
    
}

SettingLayer::~SettingLayer() {
    
}


bool SettingLayer::init() {
    if (!CCLayer::init())
        return false;
    setKeypadEnabled(true);
    setTouchPriority(kCCMenuHandlerPriority + 1);
    setTouchEnabled(true);
    
    return true;
}

int SettingLayer::getControlMode() {
    return controlMode;
}

void SettingLayer::setControlMode(SettingLayer::ControlType mode) {
    controlMode = mode;
}



void SettingLayer::ccTouchesBegan(CCSet *pTouches, CCEvent *event) {
    CCTouch *myTouch = (CCTouch*) pTouches->anyObject();
    CCPoint location = myTouch->getLocationInView();
    location = CCDirector::sharedDirector()->convertToGL(location);
    
    if(GameManager::sharedGameManager()->isNodeAtPoint(settingBtnLayer, location)){
        settingBtnClicked(NULL);
    }
    else if(GameManager::sharedGameManager()->isNodeAtPoint(soundLayer, location)){
        if(isSoundOn==false){
            soundOnOff(NULL);
        }
        else{
            soundOnOff(NULL);
        }
    }
    else if(GameManager::sharedGameManager()->isNodeAtPoint(aboutLayer, location)){
  
        GameManager::sharedGameManager()->remove_unused_data();
        
        CCScene *menuSetting_scene=GameManager::sharedGameManager()->get_scene("HelpLayer.ccbi", "HelpLayer",HelpLayerLoader::loader(), CCScene::create(),false,false);
        CCDirector::sharedDirector()->replaceScene(CCTransitionTurnOffTiles::create(0.2,menuSetting_scene));
        
    }
//    else if(GameManager::sharedGameManager()->isNodeAtPoint(helpLayer, location)){
//        
//    }
    else if(GameManager::sharedGameManager()->isNodeAtPoint(feedbackLayer, location)){
        
        ObjCCalls::openFeedBackForm();
    }
    else if(GameManager::sharedGameManager()->isNodeAtPoint(shareLayer, location)){

            ObjCCalls::onShareClicked();
    }
    else if(GameManager::sharedGameManager()->isNodeAtPoint(rateUsLayer, location)){
        ObjCCalls::onRateUsClicked();
    }
}

void SettingLayer::showAboutLayer(cocos2d::CCObject * pSender){
    mAnimationManager = dynamic_cast<CCBAnimationManager *>( this->getUserObject());
    if (mAnimationManager)
    {
        mAnimationManager->runAnimationsForSequenceNamed("onAboutShow");
    }
}
void SettingLayer::showHelpLayer(CCObject *sender)
{
    mAnimationManager = dynamic_cast<CCBAnimationManager *>( this->getUserObject());
    if (mAnimationManager)
    {
        mAnimationManager->runAnimationsForSequenceNamed("onHelpShow");
    }
}
void SettingLayer::showFeedBackLayer(CCObject *sender){
    mAnimationManager = dynamic_cast<CCBAnimationManager *>( this->getUserObject());
    if (mAnimationManager)
    {
        mAnimationManager->runAnimationsForSequenceNamed("onFeedBackShow");
    }
}
void SettingLayer::showShareLayer(CCObject *sender){
    mAnimationManager = dynamic_cast<CCBAnimationManager *>( this->getUserObject());
    if (mAnimationManager)
    {
        mAnimationManager->runAnimationsForSequenceNamed("onAboutShow");
    }
}


#pragma  mark   COCOSBUILDER INITITIALIZATION
void SettingLayer::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    CCLOG("on loaded called");
    ObjCCalls::hideActivityIndicator();

    this->setZOrder(300);
    Resource ipad_HD = resources_ipad;
    
//    settingMainLabel->setFontName("Zekton-Bold.ttf");
    
    int volume = CCUserDefault::sharedUserDefault()->getIntegerForKey("FORGROUNDVOLUME");
    if(volume==0){
        offMenuItemButton->setVisible(true);
        onMenuItemButton->setVisible(false);
    }
    else{
        offMenuItemButton->setVisible(false);
        onMenuItemButton->setVisible(true);
    }
    
    float moreAppLabelNotUsedPosY = moreAppLabelNotUsed->getPositionY();
    switch (GameManager::sharedGameManager()->get_devise_resolution())
    {
        case 1:
            
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136){
                soundLabelNotUsed->setFontSize(30);
                moreAppLabelNotUsed->setFontSize(40);
                moreAppLabelNotUsed->setPositionY(moreAppLabelNotUsedPosY-15);
                feedBackLabelNotUsed->setFontSize(30);
                supportLabelNotUsed->setFontSize(30);
                howItWorkLabelNotUsed->setFontSize(30);
                followUsLabelNotUsed->setFontSize(30);
                moreAppsBtn->setScale(0.74);
                settingMainLabel->setFontSize(50);
                rateUsLabelNotUsed->setFontSize(30);
                
            }
            else
            {
                soundLabelNotUsed->setFontSize(30);
                moreAppLabelNotUsed->setFontSize(40);
                moreAppLabelNotUsed->setPositionY(moreAppLabelNotUsedPosY-15);
                feedBackLabelNotUsed->setFontSize(30);
                supportLabelNotUsed->setFontSize(30);
                howItWorkLabelNotUsed->setFontSize(30);
                followUsLabelNotUsed->setFontSize(30);
                rateUsLabelNotUsed->setFontSize(30);
                moreAppsBtn->setScale(0.74);
                settingMainLabel->setFontSize(50);
            }
        }
            break;
        case 3:{  soundLabelNotUsed->setFontSize(30);
            moreAppLabelNotUsed->setFontSize(40);
            moreAppLabelNotUsed->setPositionY(moreAppLabelNotUsedPosY-15);
            feedBackLabelNotUsed->setFontSize(30);
            supportLabelNotUsed->setFontSize(30);
            howItWorkLabelNotUsed->setFontSize(30);
            followUsLabelNotUsed->setFontSize(30);
            rateUsLabelNotUsed->setFontSize(30);
            moreAppsBtn->setScale(0.74);
            settingMainLabel->setFontSize(50);
            
        }
            
            break;
        case 4:{  soundLabelNotUsed->setFontSize(30);
            moreAppLabelNotUsed->setFontSize(40);
            moreAppLabelNotUsed->setPositionY(moreAppLabelNotUsedPosY-15);
            feedBackLabelNotUsed->setFontSize(30);
            supportLabelNotUsed->setFontSize(30);
            howItWorkLabelNotUsed->setFontSize(30);
            followUsLabelNotUsed->setFontSize(30);
            rateUsLabelNotUsed->setFontSize(30);
            moreAppsBtn->setScale(0.74);
            settingMainLabel->setFontSize(50);
            
        }
            
            break;
        case 5:{  soundLabelNotUsed->setFontSize(30);
            moreAppLabelNotUsed->setFontSize(40);
            moreAppLabelNotUsed->setPositionY(moreAppLabelNotUsedPosY-15);
            feedBackLabelNotUsed->setFontSize(30);
            supportLabelNotUsed->setFontSize(30);
            howItWorkLabelNotUsed->setFontSize(30);
            followUsLabelNotUsed->setFontSize(30);
            rateUsLabelNotUsed->setFontSize(30);
            moreAppsBtn->setScale(0.74);
            settingMainLabel->setFontSize(50);
        }
            
            break;
        case 6:{
            moreAppsBtn->setScale(0.74);}
            break;
            
        default:
            break;
    }
    
}

SEL_CallFuncN SettingLayer::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
    return NULL;
}

SEL_MenuHandler SettingLayer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "settingBtnClicked", SettingLayer::settingBtnClicked);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onMoreAppsClicked",SettingLayer::onMoreAppsClicked);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "soundOnOff",SettingLayer::soundOnOff);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onFaceBookClicked",SettingLayer::onFaceBookClicked);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onTwitterClicked",SettingLayer::onTwitterClicked);
    
    return NULL;
}

void SettingLayer::onMoreAppsClicked(cocos2d::CCObject *sender){
    ObjCCalls::presentAppsCue();
}

SEL_CCControlHandler SettingLayer::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}

bool SettingLayer::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    //
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "settingBtnLayer",CCLayerColor *, this->settingBtnLayer);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "soundLayer",CCLayer *, this->soundLayer);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "aboutLayer",CCLayer *, this->aboutLayer);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "helpLayer",CCLayer *, this->helpLayer);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "feedbackLayer",CCLayer *, this->feedbackLayer);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "shareLayer",CCLayer *, this->shareLayer);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "rateUsLayer",CCLayer *, this->rateUsLayer);

    
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "offMenuItemButton", CCMenuItemImage*, offMenuItemButton);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "onMenuItemButton", CCMenuItemImage*, onMenuItemButton);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "twitterBtn", CCMenuItemImage*, twitterBtn);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "faceBookBtn", CCMenuItemImage*, faceBookBtn);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "moreAppsBtn", CCMenuItemImage*, moreAppsBtn);
    
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "moreAppLabelNotUsed", CCLabelTTF*, moreAppLabelNotUsed);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "feedBackLabelNotUsed", CCLabelTTF*, feedBackLabelNotUsed);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "supportLabelNotUsed", CCLabelTTF*, supportLabelNotUsed);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "howItWorkLabelNotUsed", CCLabelTTF*, howItWorkLabelNotUsed);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "followUsLabelNotUsed", CCLabelTTF*, followUsLabelNotUsed);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "soundLabelNotUsed", CCLabelTTF*, soundLabelNotUsed);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "settingMainLabel", CCLabelTTF*, settingMainLabel);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "rateUsLabelNotUsed", CCLabelTTF*, rateUsLabelNotUsed);
    

    return false;
}
void SettingLayer::onFaceBookClicked(cocos2d::CCObject *sender)
{
    ObjCCalls::onFacebookClick();
}
void SettingLayer::onTwitterClicked(cocos2d::CCObject *sender)
{
    ObjCCalls::onTwitterClick();
}
void SettingLayer::soundOnOff(CCObject *sender)
{
    if( isSoundOn==false)
    {
        isSoundOn=true;
        CCUserDefault::sharedUserDefault()->setIntegerForKey("FORGROUNDVOLUME",isSoundOn);
        offMenuItemButton->setVisible(false);
        onMenuItemButton->setVisible(true);
        SoundManager::sharedSoundManager()->setEffectVolume(1);
    }
    else {
        isSoundOn=false;
        CCUserDefault::sharedUserDefault()->setIntegerForKey("FORGROUNDVOLUME",isSoundOn);
        offMenuItemButton->setVisible(true);
        onMenuItemButton->setVisible(false);
        SoundManager::sharedSoundManager()->setEffectVolume(0);
    }
    CCUserDefault::sharedUserDefault()->flush();
}

void SettingLayer::settingBtnClicked(cocos2d::CCObject *pSender)
{
    ObjCCalls::showActivityIndictor();
    GameManager::sharedGameManager()->remove_unused_data();
    
    CCScene *menuSetting_scene=GameManager::sharedGameManager()->get_scene("MenuLayer.ccbi", "MenuLayer", MenuLayerLoader::loader(), CCScene::create(),false,false);
    CCDirector::sharedDirector()->replaceScene(CCTransitionTurnOffTiles::create(0.2,menuSetting_scene));
    
}



bool SettingLayer::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    bool bRet = false;
    return bRet;
}







#include "../Layers/MonumentSelectionLayer.h"
#include "../ObjCCalls/HelloWorldScene.h"
// iOS Includes
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "../OBJCall/ObjCCalls.h"
#endif
// Android Includes
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "../JNICalls/InterfaceJNI.h"
#endif
#include "cocos-ext.h"
#include "SimpleAudioEngine.h"
#include "ObjCCalls.h"

MonumentSelectionLayer::MonumentSelectionLayer():rightImageSpr(NULL),leftImageSpr(NULL),mainImageSpr(NULL),backgroundLayer(NULL),isSetVisiblity(true),isFirstTimeLeftMenuClicked(true),navHomeLayer(NULL),navigationLayer(NULL),isVisiblePlayButton(true),homeButtonMenuItem(NULL),twitterMenuItem(NULL),facebookMenuItem(NULL),shareMenuItem(NULL),faceBookIconImageSpr(NULL),twitterIconImageSpr(NULL),fbTwShareMenu(NULL) {
    
    //    CCUserDefault::sharedUserDefault()->setIntegerForKey("CLICKCOUNTER", clickCounter);
    //    CCUserDefault::sharedUserDefault()->flush();
}

MonumentSelectionLayer::~MonumentSelectionLayer() {
}


void MonumentSelectionLayer::mainImageClicked(CCObject *sender)
{
    return;
}
void MonumentSelectionLayer::leftMenuItemClicked(CCObject *sender)
{
    //    if(isSetVisiblity==false)
    //        return;
    //    if(isFirstTimeLeftMenuClicked==true){
    //        isFirstTimeLeftMenuClicked=false;
    //        clickCounter=8;}
    //    clickCounter--;
    //    if(clickCounter<1)
    //    {
    //        clickCounter=7;
    //    }
    //
    //    schedule(schedule_selector(MonumentSelectionLayer::enableMainImageScale),0.85);
    //
    //    CCLOG("left menu clickCounter %d",clickCounter);
    //    isSetVisiblity=false;
    //    CCMenuItemImage *leftImage = (CCMenuItemImage*)leftImageSpr;
    //    CCMenuItemImage *rightImage = (CCMenuItemImage*)rightImageSpr;
    //    CCMenuItemImage *mainImage = (CCMenuItemImage*)mainImageSpr;
    //    CCLayerColor *backLayer = (CCLayerColor*)backgroundLayer;
    //    CCPoint mainImageLastPos = mainImage->getPosition();
    //    mainImage->setPosition(leftImage->getPosition());
    //    mainImage->setScale(0.2);
    //
    //    CCUserDefault::sharedUserDefault()->setIntegerForKey("CLICKCOUNTER", clickCounter);
    //    CCUserDefault::sharedUserDefault()->flush();
    //
    //    CCMoveTo *moveMainImage = CCMoveTo::create(0.2, mainImageLastPos);
    //    mainImage->runAction(moveMainImage);
    //
    //    CCScaleTo *scaleMainImage = CCScaleTo::create(0.5, 1);
    //    mainImage->runAction(CCSequence::createWithTwoActions(CCDelayTime::create(0.2), scaleMainImage));
    //
    //    if (clickCounter==1)
    //    {
    //        leftImageSpr->setNormalSpriteFrame(CCSpriteFrame::create("mon-sm-7.png",leftSpr->getTextureRect()));
    //        mainImageSpr->setNormalSpriteFrame(CCSpriteFrame::create("mon-1.png",mainSpr->getTextureRect()));
    //
    //        rightImageSpr->setNormalSpriteFrame(CCSpriteFrame::create("mon-sm-2.png",rightSpr->getTextureRect()));
    //    }
    //    if (clickCounter==2)
    //    {
    //        leftImage->setNormalSpriteFrame(CCSpriteFrame::create("mon-sm-1.png",leftSpr->getTextureRect()));
    //
    //        mainImage->setNormalSpriteFrame(CCSpriteFrame::create("mon-2.png",mainSpr->getTextureRect()));
    //
    //        rightImage->setNormalSpriteFrame(CCSpriteFrame::create("mon-sm-3.png",rightSpr->getTextureRect()));
    //    }
    //    if(clickCounter==3)
    //    {
    //        leftImage->setNormalSpriteFrame(CCSpriteFrame::create("mon-sm-2.png",leftSpr->getTextureRect()));
    //        mainImage->setNormalSpriteFrame(CCSpriteFrame::create("mon-3.png",mainSpr->getTextureRect()));
    //
    //        rightImage->setNormalSpriteFrame(CCSpriteFrame::create("mon-sm-4.png",rightSpr->getTextureRect()));
    //    }
    //    if (clickCounter==4)
    //    {
    //        leftImage->setNormalSpriteFrame(CCSpriteFrame::create("mon-sm-3.png",leftSpr->getTextureRect()));
    //        mainImage->setNormalSpriteFrame(CCSpriteFrame::create("mon-4.png",mainSpr->getTextureRect()));
    //
    //        rightImage->setNormalSpriteFrame(CCSpriteFrame::create("mon-sm-5.png",rightSpr->getTextureRect()));
    //    }
    //    if(clickCounter==5)
    //    {
    //        leftImage->setNormalSpriteFrame(CCSpriteFrame::create("mon-sm-4.png",leftSpr->getTextureRect()));
    //        mainImage->setNormalSpriteFrame(CCSpriteFrame::create("mon-5.png",mainSpr->getTextureRect()));
    //
    //        rightImage->setNormalSpriteFrame(CCSpriteFrame::create("mon-sm-6.png",rightSpr->getTextureRect()));
    //    }
    //    if (clickCounter==6)
    //    {
    //        leftImage->setNormalSpriteFrame(CCSpriteFrame::create("mon-sm-5.png",leftSpr->getTextureRect()));
    //        mainImage->setNormalSpriteFrame(CCSpriteFrame::create("mon-6.png",mainSpr->getTextureRect()));
    //
    //        rightImage->setNormalSpriteFrame(CCSpriteFrame::create("mon-sm-7.png",rightSpr->getTextureRect()));
    //
    //    } if(clickCounter==7)
    //    {
    //        leftImage->setNormalSpriteFrame(CCSpriteFrame::create("mon-sm-6.png",leftSpr->getTextureRect()));
    //        mainImage->setNormalSpriteFrame(CCSpriteFrame::create("mon-7.png",mainSpr->getTextureRect()));
    //
    //        rightImage->setNormalSpriteFrame(CCSpriteFrame::create("mon-sm-1.png",rightSpr->getTextureRect()));
    //    }
    //
    
}
void MonumentSelectionLayer::rightMenuItemClicked(CCObject *sender)
{
    //    if(isSetVisiblity==false)
    //        return;
    //    clickCounter++;
    //    if(isFirstTimeLeftMenuClicked==true)
    //        isFirstTimeLeftMenuClicked=false;
    //    if(clickCounter>7)
    //    {
    //        clickCounter=1;
    //    }
    //    schedule(schedule_selector(MonumentSelectionLayer::enableMainImageScale),0.85);
    //
    //    CCLOG("right menu clickCounter %d",clickCounter);
    //    isSetVisiblity=false;
    //    CCMenuItemImage *leftImage = (CCMenuItemImage*)leftImageSpr;
    //    CCMenuItemImage *rightImage = (CCMenuItemImage*)rightImageSpr;
    //    CCMenuItemImage *mainImage = (CCMenuItemImage*)mainImageSpr;
    //    CCLayerColor *backLayer = (CCLayerColor*)backgroundLayer;
    //    CCPoint mainImageLastPos = mainImage->getPosition();
    //    mainImage->setPosition(rightImage->getPosition());
    //    mainImage->setScale(0.2);
    //
    //    CCUserDefault::sharedUserDefault()->setIntegerForKey("CLICKCOUNTER", clickCounter);
    //    CCUserDefault::sharedUserDefault()->flush();
    //
    //    CCMoveTo *moveMainImage = CCMoveTo::create(0.2, mainImageLastPos);
    //    mainImage->runAction(moveMainImage);
    //
    //    CCScaleTo *scaleMainImage = CCScaleTo::create(0.5, 1);
    //    mainImage->runAction(CCSequence::createWithTwoActions(CCDelayTime::create(0.2), scaleMainImage));
    //
    //    if (clickCounter==1)
    //    {
    //        leftImageSpr->setNormalSpriteFrame(CCSpriteFrame::create("mon-sm-7.png",leftSpr->getTextureRect()));
    //        mainImageSpr->setNormalSpriteFrame(CCSpriteFrame::create("mon-1.png",mainSpr->getTextureRect()));
    //
    //        rightImageSpr->setNormalSpriteFrame(CCSpriteFrame::create("mon-sm-2.png",rightSpr->getTextureRect()));
    //    }
    //    if (clickCounter==2)
    //    {
    //        leftImage->setNormalSpriteFrame(CCSpriteFrame::create("mon-sm-1.png",leftSpr->getTextureRect()));
    //
    //        mainImage->setNormalSpriteFrame(CCSpriteFrame::create("mon-2.png",mainSpr->getTextureRect()));
    //
    //        rightImage->setNormalSpriteFrame(CCSpriteFrame::create("mon-sm-3.png",rightSpr->getTextureRect()));
    //    }
    //    if(clickCounter==3)
    //    {
    //        leftImage->setNormalSpriteFrame(CCSpriteFrame::create("mon-sm-2.png",leftSpr->getTextureRect()));
    //        mainImage->setNormalSpriteFrame(CCSpriteFrame::create("mon-3.png",mainSpr->getTextureRect()));
    //
    //        rightImage->setNormalSpriteFrame(CCSpriteFrame::create("mon-sm-4.png",rightSpr->getTextureRect()));
    //    }
    //    if (clickCounter==4)
    //    {
    //        leftImage->setNormalSpriteFrame(CCSpriteFrame::create("mon-sm-3.png",leftSpr->getTextureRect()));
    //        mainImage->setNormalSpriteFrame(CCSpriteFrame::create("mon-4.png",mainSpr->getTextureRect()));
    //
    //        rightImage->setNormalSpriteFrame(CCSpriteFrame::create("mon-sm-5.png",rightSpr->getTextureRect()));
    //    }
    //    if(clickCounter==5)
    //    {
    //        leftImage->setNormalSpriteFrame(CCSpriteFrame::create("mon-sm-4.png",leftSpr->getTextureRect()));
    //        mainImage->setNormalSpriteFrame(CCSpriteFrame::create("mon-5.png",mainSpr->getTextureRect()));
    //
    //        rightImage->setNormalSpriteFrame(CCSpriteFrame::create("mon-sm-6.png",rightSpr->getTextureRect()));
    //    }
    //    if (clickCounter==6)
    //    {
    //        leftImage->setNormalSpriteFrame(CCSpriteFrame::create("mon-sm-5.png",leftSpr->getTextureRect()));
    //        mainImage->setNormalSpriteFrame(CCSpriteFrame::create("mon-6.png",mainSpr->getTextureRect()));
    //
    //        rightImage->setNormalSpriteFrame(CCSpriteFrame::create("mon-sm-7.png",rightSpr->getTextureRect()));
    //
    //    } if(clickCounter==7)
    //    {
    //        leftImage->setNormalSpriteFrame(CCSpriteFrame::create("mon-sm-6.png",leftSpr->getTextureRect()));
    //        mainImage->setNormalSpriteFrame(CCSpriteFrame::create("mon-7.png",mainSpr->getTextureRect()));
    //
    //        rightImage->setNormalSpriteFrame(CCSpriteFrame::create("mon-sm-1.png",rightSpr->getTextureRect()));
    //    }
}

void MonumentSelectionLayer::enableMainImageScale(cocos2d::CCMenuItemImage *mainImage)
{
    
    int stage = CCUserDefault::sharedUserDefault()->getIntegerForKey("CLICKCOUNTER");
    if(stage==8 && isFirstTimeLeftMenuClicked==true)
    {
        isFirstTimeLeftMenuClicked=false;
        playButton->setVisible(false);
        faceBookIconImageSpr->setVisible(true);
        twitterIconImageSpr->setVisible(true);
        shareMenuItem->setVisible(true);

        
    }
    if (stage<=7 &&playButton->isVisible()==false)
    {
        isFirstTimeLeftMenuClicked=true;
        playButton->setVisible(true);
        faceBookIconImageSpr->setVisible(false);
        twitterIconImageSpr->setVisible(false);
        shareMenuItem->setVisible(false);

    }
}

bool MonumentSelectionLayer::tryIsInternetConnection()
{
    CCLog("HelloWorld: tryIsInternetConnection");
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    return InterfaceJNI::isInternetConnected();
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    return ObjCCalls::tryIsInternetConnection();
#endif
}


bool MonumentSelectionLayer::init() {

    
    clevelLayer = CLevelSelectLayer::create();
    clevelLayer->setPosition(CCPointZero);
    this->addChild(clevelLayer,20);
    
    
    if (!CCLayer::init())
        return false;
    
    setKeypadEnabled(true);
    this->setTouchEnabled(true);
    setTouchPriority(kCCMenuHandlerPriority + 1);
    setTouchMode (kCCTouchesOneByOne);
    
    schedule(schedule_selector(MonumentSelectionLayer::enableMainImageScale));
    //    schedule(schedule_selector(MonumentSelectionLayer::applyEffectOnButton),2);
    
    return true;
}

void MonumentSelectionLayer::onEnter() {
    CCLayer::onEnter();
    this->setTouchEnabled(true);
    homeButtonMenuItem->setZOrder(100);
}
void MonumentSelectionLayer::onExit()
{
    CCLayer::onExit();
}
void MonumentSelectionLayer::applyEffectOnButton()
{
    //    CCMenuItemImage *playbtn = (CCMenuItemImage*)playButton;
    
    if(isVisiblePlayButton==true)
    {
        isVisiblePlayButton=false;
        playButton->setVisible(false);
        faceBookIconImageSpr->setVisible(true);
        twitterIconImageSpr->setVisible(true);
        shareMenuItem->setVisible(true);

    }
    else
    {
        isVisiblePlayButton=true;
        playButton->setVisible(true);
        faceBookIconImageSpr->setVisible(false);
        twitterIconImageSpr->setVisible(false);
        shareMenuItem->setVisible(false);
    }
}

void MonumentSelectionLayer::initFaceBookAndTwitterButton() {

    faceBookIconImageSpr = CCMenuItemImage::create("FB_btn.png", "FB_btn.png",                       this,menu_selector(MonumentSelectionLayer::faceBookButtonPressed));
    faceBookIconImageSpr->setScaleY(0.9);
    twitterIconImageSpr = CCMenuItemImage::create("twi_btn.png", "twi_btn.png",this,menu_selector(MonumentSelectionLayer::twitterButtonPressed));
    twitterIconImageSpr->setScaleY(0.9);
       shareMenuItem = CCMenuItemImage::create("shar_btn.png", "shar_btn.png",
                                               this,menu_selector(MonumentSelectionLayer::onShareButtonClicked));
    
    shareMenuItem->setScaleY(0.9);

    //    faceBookIconImageSpr->setVisible(false);
    //    twitterIconImageSpr->setVisible(false);
    
    TargetPlatform device = CCApplication::sharedApplication()->getTargetPlatform();
    CCSize size = CCDirector::sharedDirector()->getWinSize();
  
    CCMenu* faceBookAndTwitterIcon = CCMenu::create(faceBookIconImageSpr,shareMenuItem,twitterIconImageSpr, NULL);
    faceBookAndTwitterIcon->setContentSize(CCSizeMake(size.width,40));
    faceBookAndTwitterIcon->setPosition(ccp(0, 40));
        faceBookIconImageSpr->setVisible(false);
    
    switch (GameManager::sharedGameManager()->get_devise_resolution())
    {
        case 1:{
            faceBookIconImageSpr->setPosition(ccp(254,250));
            twitterIconImageSpr->setPosition(ccp(768,250));
            shareMenuItem->setPosition(ccp(1280,250));
        }
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136){
                faceBookIconImageSpr->setScaleX(0.9);
                twitterIconImageSpr->setScaleX(0.9);
                shareMenuItem->setScaleX(0.9);
                faceBookIconImageSpr->setPosition(ccp(105,160));
                twitterIconImageSpr->setPosition(ccp(320,160));
                shareMenuItem->setPosition(ccp(533,160));
          
            }
            else{
                faceBookIconImageSpr->setPosition(ccp(254/2,110));
                twitterIconImageSpr->setPosition(ccp(768/2,110));
                shareMenuItem->setPosition(ccp(1280/2,110));
            }
        }
            break;
        case 3:{
        
            faceBookIconImageSpr->setScaleX(0.9);
            twitterIconImageSpr->setScaleX(0.9);
            shareMenuItem->setScaleX(0.9);
            faceBookIconImageSpr->setPosition(ccp(105,115));
            twitterIconImageSpr->setPosition(ccp(320,115));
            shareMenuItem->setPosition(ccp(533,115));
        }
            break;
        case 4:{
            faceBookIconImageSpr->setScaleX(0.9);
            twitterIconImageSpr->setScaleX(0.9);
            shareMenuItem->setScaleX(0.9);
            faceBookIconImageSpr->setPosition(ccp(105,160));
            twitterIconImageSpr->setPosition(ccp(320,160));
            shareMenuItem->setPosition(ccp(533,160));
        }
            break;
        case 5:{
            faceBookIconImageSpr->setScaleX(1.2);
            twitterIconImageSpr->setScaleX(1.2);
            shareMenuItem->setScaleX(1.2);
            faceBookIconImageSpr->setPosition(ccp(105,160));
            twitterIconImageSpr->setPosition(ccp(380,160));
            shareMenuItem->setPosition(ccp(593,160));
        }
            break;
        case 6:{
            faceBookIconImageSpr->setScaleX(0.85);
            twitterIconImageSpr->setScaleX(0.85);
            shareMenuItem->setScaleX(0.85);
            faceBookIconImageSpr->setPosition(ccp(224,270));
            twitterIconImageSpr->setPosition(ccp(680,270));
            shareMenuItem->setPosition(ccp(1040,270));
        }
            
            break;
            
        default:
            break;
    }
    
    this->addChild(faceBookAndTwitterIcon, 100);
    
        faceBookIconImageSpr->setVisible(false);
        twitterIconImageSpr->setVisible(false);
    shareMenuItem->setVisible(false);
}

void MonumentSelectionLayer::initPlayButton() {
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    //Pause Button
    playButton = CCMenuItemImage::create("playButton.png", "playButton.png",this,menu_selector(MonumentSelectionLayer::playButtonPressed));
    
    playButton->setPosition(ccp(0, 0));
    CCMenu* backButton = CCMenu::create(playButton, NULL);
    
    backButton->setPosition(ccp(size.width/2,size.height/2));
    
    this->addChild(backButton, 100);
    
    CCActionInterval *action1 = CCFadeIn::create(1);
    CCActionInterval *action = CCFadeOut::create(1);
    playButton->runAction(CCRepeatForever::create(CCSequence::create(action1,CCDelayTime::create(1),action,CCDelayTime::create(0.5),NULL)));
}

void MonumentSelectionLayer::onHomePressed(CCObject *sender) {
    ObjCCalls::showActivityIndictor();
    
    clevelLayer->removeAllChildrenWithCleanup(true);
    GameManager::sharedGameManager()->remove_unused_data();
    CCScene *help_scene=GameManager::sharedGameManager()->get_scene("MenuLayer.ccbi", "MenuLayer", MenuLayerLoader::loader(), CCScene::create(),false,false);
   	CCDirector::sharedDirector()->replaceScene(CCTransitionTurnOffTiles::create(0.2f,help_scene));
}
void MonumentSelectionLayer::faceBookButtonPressed()
{
    CCLog("HelloWorld: try to send a tweet");
    ObjCCalls::onFacebookClick();
}

void MonumentSelectionLayer::twitterButtonPressed()
{
    CCLog("HelloWorld: try to send a tweet");
    ObjCCalls::onTwitterClick();
    
}
void MonumentSelectionLayer::onShareButtonClicked()
{
    CCLog("HelloWorld: try to Share");
    ObjCCalls::onShareClickedFromMonuments();
}
void MonumentSelectionLayer::playButtonPressed() {
    ObjCCalls::showActivityIndictor();
    
    clevelLayer->removeAllChildrenWithCleanup(true);
    GameManager::sharedGameManager()->remove_unused_data();
    
    CCScene *help_scene=GameManager::sharedGameManager()->get_scene("LevelSelectionLayer.ccbi", "LevelSelectionLayer", LevelSelectionLayerLoader::loader(), CCScene::create(),false,false);
   	CCDirector::sharedDirector()->replaceScene(CCTransitionTurnOffTiles::create(0.2,help_scene));
}

void MonumentSelectionLayer::initHighScore() {
    CCSize size = CCDirector::sharedDirector()->getWinSize();
}
#pragma  mark   COCOSBUILDER INITITIALIZATION
void MonumentSelectionLayer::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    CCLOG("on loaded called");
    ObjCCalls::hideActivityIndicator();
    navHomeLayer->setZOrder(30);
    this->initFaceBookAndTwitterButton();
    this->initPlayButton();
//    CCLog("fbTwShareMenu pos X %f and posY %f",fbTwShareMenu->getPositionX(),fbTwShareMenu->getPositionY());
//    CCLog("twitterIconImageSpr pos X %f and posY %f",twitterIconImageSpr->getPositionX(),twitterIconImageSpr->getPositionY());
//    CCLog("faceBookIconImageSpr pos X %f and posY %f",faceBookIconImageSpr->getPositionX(),faceBookIconImageSpr->getPositionY());
//    CCLog("shareMenuItem pos X %f and posY %f",shareMenuItem->getPositionX(),shareMenuItem->getPositionY());

}

SEL_CallFuncN MonumentSelectionLayer::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
    return NULL;
}

SEL_MenuHandler MonumentSelectionLayer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onHomePressed", MonumentSelectionLayer::onHomePressed);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "playButtonPressed", MonumentSelectionLayer::playButtonPressed);
    
//    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "faceBookButtonPressed", MonumentSelectionLayer::faceBookButtonPressed);
//    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "twitterButtonPressed", MonumentSelectionLayer::twitterButtonPressed);
//    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onShareButtonClicked", MonumentSelectionLayer::onShareButtonClicked);

    return NULL;
}

cocos2d::extension::SEL_CCControlHandler MonumentSelectionLayer::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}

bool MonumentSelectionLayer::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{

    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "backgroundLayer", CCLayerColor*, backgroundLayer);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "navHomeLayer", CCLayerColor*, navHomeLayer);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "navigationLayer", CCLayerColor*, navigationLayer);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "homeButtonMenuItem", CCMenuItemImage*, homeButtonMenuItem);
    
//    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "twitterMenuItem", CCMenuItemImage*, twitterMenuItem);
//    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "facebookMenuItem", CCMenuItemImage*, facebookMenuItem);
//    
//    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "fbTwShareMenu", CCMenu*, fbTwShareMenu);

    return false;
}

bool MonumentSelectionLayer::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    bool bRet = false;
    return bRet;
}

void MonumentSelectionLayer::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
    CCTouch *myTouch = (CCTouch*) pTouches->anyObject();
    CCPoint location = myTouch->getLocationInView();
    location = CCDirector::sharedDirector()->convertToGL(location);
    if(GameManager::sharedGameManager()->isNodeAtPoint(navHomeLayer,location)){
        onHomePressed(NULL);
    }
}



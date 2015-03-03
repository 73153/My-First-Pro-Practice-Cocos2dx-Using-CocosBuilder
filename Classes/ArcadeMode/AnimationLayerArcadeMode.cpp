

#include "../ArcadeMode/AnimationLayerArcadeMode.h"
#include "../ArcadeMode/GameLayerArcadeMode.h"
#include "../ArcadeMode/GameLayerArcadeModeLoader.h"
#include "HoldOnModel.h"
#include "../Layers/MenuLayer.h"
#include "../Layers/MenuLayerLoader.h"
#include "../GameManager/GameManager.h"
#include "../Layers/MenuLayer.h"
#include "../Layers/MenuLayerLoader.h"
#include "../Layers/SettingLayer.h"
#include "../Layers/SettingLayerLoader.h"
#include "../OBJCall/ObjCCalls.h"

//#include "../SQliteManager/ItemDAO.h"

AnimationLayerArcadeMode::AnimationLayerArcadeMode():menuLayer(NULL),isPlayAgain(false),menuBtn(NULL),restartBtn(NULL),resumeBtn(NULL),isPausePressed(false),gameIsPaused(NULL),pauseAndPlayLayer(NULL),pauseMenuItemButton(NULL),scoreCountLbl(NULL),restartLabelNotUsed(NULL),gameOverLabelNotUsed(NULL),menuLabelNotUsed(NULL),restartAnotherLabelNotUsed(NULL),resumeLabelNotUsed(NULL),continueLabelNotUsed(NULL),scoreLabelNotUsed(NULL),stageLayer(NULL),KaccheGameOverLabel(NULL),sroreLabelNotUsed(NULL),stageMenuItemButton(NULL),pauseMenuButton(NULL),stageMenuButton(NULL),kacheLabelGameWon(NULL),continuePlayLbl(NULL),isMileStoneAcieved(false){
    tempLevelForPositionTaking=1;
}

AnimationLayerArcadeMode::~AnimationLayerArcadeMode() {
    
}

void AnimationLayerArcadeMode::onEnter() {
    CCNode::onEnter();
    //    pauseAndPlayLayer->setZOrder(500);
    pauseAndPlayLayer->setVisible(true);
}

void AnimationLayerArcadeMode::keyBackClicked() {
    ObjCCalls::showActivityIndictor();
    
    removeUnusedData();
    GameManager::sharedGameManager()->getcurrent_layer()->removeAllChildrenWithCleanup(true);
    
    GameManager::sharedGameManager()->remove_unused_data();
    
    CCScene *help_scene=GameManager::sharedGameManager()->get_scene("MenuLayer.ccbi", "MenuLayer", MenuLayerLoader::loader(), CCScene::create(),false,false);
   	CCDirector::sharedDirector()->replaceScene(CCTransitionTurnOffTiles::create(0.2,help_scene));
}

void AnimationLayerArcadeMode::backButtonPressed() {
    ObjCCalls::showActivityIndictor();
    removeUnusedData();
    GameManager::sharedGameManager()->getcurrent_layer()->removeAllChildrenWithCleanup(true);
    
    GameManager::sharedGameManager()->remove_unused_data();
    CCScene *help_scene=GameManager::sharedGameManager()->get_scene("MenuLayer.ccbi", "MenuLayer", MenuLayerLoader::loader(), CCScene::create(),false,false);
   	CCDirector::sharedDirector()->replaceScene(CCTransitionTurnOffTiles::create(0.2,help_scene));
}
void AnimationLayerArcadeMode::onInAppPurchaseClicked(cocos2d::CCObject *pSender)
{
    //    removeUnusedData();
    //    GameManager::sharedGameManager()->getcurrent_layer()->removeAllChildrenWithCleanup(true);
    //
    //    GameManager::sharedGameManager()->remove_unused_data();
    //    TargetPlatform deviceDetect = CCApplication::sharedApplication()->getTargetPlatform();
    //    if(deviceDetect==kTargetIpad || deviceDetect==kTargetIphone){
    //        CCScene *highScore_scene=GameManager::sharedGameManager()->get_scene("InAppPurchaseLayer.ccbi", "InAppPurchaseLayer",InAppPurchaseLayerLoader::loader(), CCScene::create(),false,false);
    //        CCDirector::sharedDirector()->replaceScene(CCTransitionTurnOffTiles::create(0.2,highScore_scene));
    //    }
    //    else{
    //        CCScene *highScore_scene=GameManager::sharedGameManager()->get_scene("InAppPurchaseLayer_Android.ccbi", "InAppPurchaseLayer",InAppPurchaseLayerLoader::loader(), CCScene::create(),false,false);
    //        CCDirector::sharedDirector()->replaceScene(CCTransitionTurnOffTiles::create(0.2,highScore_scene));
    //    }
}

#pragma  mark   COCOSBUILDER INITITIALIZATION
void AnimationLayerArcadeMode::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    ObjCCalls::hideActivityIndicator();
    isPlayAgain = false;
    menuLayer->setVisible(false);
    pauseMenuItemButton->setZOrder(1000);
    this->setZOrder(300);
    pauseAndPlayLayer->setVisible(true);
    
    
    //    CCLabelTTF *localrestartLabelNotUsed = (CCLabelTTF*)restartLabelNotUsed;
    //    CCLabelTTF *localgameOverLabelNotUsed = (CCLabelTTF*)gameOverLabelNotUsed;
    //    CCLabelTTF *localmenuLabelNotUsed = (CCLabelTTF*)menuLabelNotUsed;
    //    CCLabelTTF *localrestartAnotherLabelNotUsed = (CCLabelTTF*)restartAnotherLabelNotUsed;
    //    CCLabelTTF *localcontinueLabelNotUsed = (CCLabelTTF*)continueLabelNotUsed;
    //    CCLabelTTF *localresumeLabelNotUsed = (CCLabelTTF*)resumeLabelNotUsed;
    restartLabelNotUsed->setFontName("fonts/ZektonRg-Regular.ttf");
    gameOverLabelNotUsed->setFontName("fonts/Zekton-Bold.ttf");
    menuLabelNotUsed->setFontName("fonts/ZektonRg-Regular.ttf");
    restartAnotherLabelNotUsed->setFontName("fonts/ZektonRg-Regular.ttf");
    resumeLabelNotUsed->setFontName("fonts/ZektonRg-Regular.ttf");
    sroreLabelNotUsed->setFontName("fonts/ZektonRg-Regular.ttf");
    continueLabelNotUsed->setFontName("fonts/ZektonRg-Regular.ttf");
    KaccheGameOverLabel->setFontName("fonts/Zekton-Bold.ttf");
    kacheLabelGameWon->setFontName("fonts/Zekton-Bold.ttf");
    scoreCountLbl->setFontName("fonts/Zekton-Bold.ttf");
    scoreLabelNotUsed->setFontName("fonts/Zekton-Bold.ttf");
    
    
    switch (GameManager::sharedGameManager()->get_devise_resolution())
    {
        case 1:
            break;
        case 2:
            if (CCDirector::sharedDirector()->getWinSize().height==1136){
                restartLabelNotUsed->setFontSize(35);
                gameOverLabelNotUsed->setFontSize(70);
                menuLabelNotUsed->setFontSize(35);
                restartAnotherLabelNotUsed->setFontSize(35);
                resumeLabelNotUsed->setFontSize(35);
                continueLabelNotUsed->setFontSize(35);
                sroreLabelNotUsed->setFontSize(35);
                scoreCountLbl->setFontSize(40);
                continuePlayLbl->setFontSize(40);
                scoreLabelNotUsed->setFontSize(35);
            }
            else
            {
                restartLabelNotUsed->setFontSize(35);
                gameOverLabelNotUsed->setFontSize(70);
                menuLabelNotUsed->setFontSize(35);
                restartAnotherLabelNotUsed->setFontSize(35);
                resumeLabelNotUsed->setFontSize(35);
                continueLabelNotUsed->setFontSize(35);
                sroreLabelNotUsed->setFontSize(35);
                scoreCountLbl->setFontSize(40);
                continuePlayLbl->setFontSize(40);
                scoreLabelNotUsed->setFontSize(35);
            }
            break;
        case 3:{
            restartLabelNotUsed->setFontSize(35);
            gameOverLabelNotUsed->setFontSize(70);
            menuLabelNotUsed->setFontSize(35);
            restartAnotherLabelNotUsed->setFontSize(35);
            resumeLabelNotUsed->setFontSize(35);
            continueLabelNotUsed->setFontSize(35);
            sroreLabelNotUsed->setFontSize(35);
            scoreCountLbl->setFontSize(40);
            continuePlayLbl->setFontSize(40);
            scoreLabelNotUsed->setFontSize(35);
            
        }
            break;
        case 4:{
            restartLabelNotUsed->setFontSize(35);
            gameOverLabelNotUsed->setFontSize(70);
            menuLabelNotUsed->setFontSize(35);
            restartAnotherLabelNotUsed->setFontSize(35);
            resumeLabelNotUsed->setFontSize(35);
            continueLabelNotUsed->setFontSize(35);
            sroreLabelNotUsed->setFontSize(35);
            continuePlayLbl->setFontSize(40);
            scoreLabelNotUsed->setFontSize(35);
        }
            break;
        case 5:{
            restartLabelNotUsed->setFontSize(35);
            gameOverLabelNotUsed->setFontSize(70);
            menuLabelNotUsed->setFontSize(35);
            restartAnotherLabelNotUsed->setFontSize(35);
            resumeLabelNotUsed->setFontSize(35);
            continueLabelNotUsed->setFontSize(35);
            sroreLabelNotUsed->setFontSize(35);
            scoreCountLbl->setFontSize(40);
            continuePlayLbl->setFontSize(40);
            scoreLabelNotUsed->setFontSize(35);
        }
            break;
        case 6:
            break;
        default:
            break;
    }
    restartLabelNotUsed->setString("RESTART");
    restartAnotherLabelNotUsed->setString("RESTART");
    menuLabelNotUsed->setString("HOME");
    sroreLabelNotUsed->setString("STORE");
    CCLOG("on loaded called");
    
}

SEL_CallFuncN AnimationLayerArcadeMode::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
    return NULL;
}

SEL_MenuHandler AnimationLayerArcadeMode::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "restartPressed", AnimationLayerArcadeMode::restart);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "menuPressed", AnimationLayerArcadeMode::menuPressed);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "pauseAndResume", AnimationLayerArcadeMode::pauseAndResume);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "goToNextLevel", AnimationLayerArcadeMode::goToNextLevel);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onStagePressed", AnimationLayerArcadeMode::onStagePressed);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onInAppPurchaseClicked", AnimationLayerArcadeMode::onInAppPurchaseClicked);
    
    return NULL;
}

SEL_CCControlHandler AnimationLayerArcadeMode::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    
    return NULL;
}

bool AnimationLayerArcadeMode::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "menuLayer",CCLayerColor *, this->menuLayer);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "pauseAndPlayLayer",CCLayerColor *, this->pauseAndPlayLayer);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "stageLayer",CCLayerColor *, this->stageLayer);
    
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "menuBtn",CCMenuItemImage *, this->menuBtn);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "restartBtn",CCMenuItemImage *, this->restartBtn);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "resumeBtn",CCMenuItemImage *, this->resumeBtn);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "pauseMenuItemButton",CCMenuItemImage *, this->pauseMenuItemButton);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "stageMenuItemButton",CCMenuItemImage *, this->stageMenuItemButton);
    
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "ScoreCountLbl",CCLabelTTF *, this->scoreCountLbl);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "restartLabelNotUsed",CCLabelTTF *, this->restartLabelNotUsed);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "gameOverLabelNotUsed",CCLabelTTF *, this->gameOverLabelNotUsed);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "restartAnotherLabelNotUsed",CCLabelTTF *, this->restartAnotherLabelNotUsed);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "sroreLabelNotUsed",CCLabelTTF *, this->sroreLabelNotUsed);
    
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "KaccheGameOverLabel",CCLabelTTF *, this->KaccheGameOverLabel);
    
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "resumeLabelNotUsed",CCLabelTTF *, this->resumeLabelNotUsed);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "continueLabelNotUsed",CCLabelTTF *, this->continueLabelNotUsed);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "scoreLabelNotUsed",CCLabelTTF *, this->scoreLabelNotUsed);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "menuLabelNotUsed",CCLabelTTF *, this->menuLabelNotUsed);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "kacheLabelGameWon",CCLabelTTF *, this->kacheLabelGameWon);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "continuePlayLbl",CCLabelTTF *, this->continuePlayLbl);
    
    
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "pauseMenuButton", CCMenu*, pauseMenuButton);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "stageMenuButton", CCMenu*, stageMenuButton);
    
    return false;
}

bool AnimationLayerArcadeMode::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    bool bRet = false;
    return bRet;
}

void AnimationLayerArcadeMode::pauseAndResume(cocos2d::CCObject * pSender)
{
    if(isMileStoneAcieved==true){
        isMileStoneAcieved=false;
        this->menuLayer->setZOrder(-1);
        this->menuLayer->setVisible(false);
        menuLayer->setColor(ccBLACK);
        pauseAndPlayLayer->setZOrder(100);
        stageLayer->setZOrder(100);
        menuLayer->setOpacity(200);
        pauseMenuItemButton->setEnabled(true);
        stageMenuItemButton->setEnabled(true);
        mAnimationManager = dynamic_cast<CCBAnimationManager *>( this->getUserObject());
        if (mAnimationManager){
            mAnimationManager->runAnimationsForSequenceNamed("mileStoneCompletedResume");
        }
        return;
    }
    
    //    animationDelegte->removeAllChildern();
    if(isPlayAgain==true){
        this->menuLayer->setZOrder(-1);
        this->menuLayer->setVisible(false);
        isPlayAgain=false;
        mAnimationManager = dynamic_cast<CCBAnimationManager *>( this->getUserObject());
        if (mAnimationManager){
            mAnimationManager->runAnimationsForSequenceNamed("playAgainUp");
        }
        CCSequence *seq=CCSequence::createWithTwoActions(CCDelayTime::create(0.5),CCCallFunc::create(this, callfunc_selector(AnimationLayer::resumeGame)));
        this->runAction(seq);
        
        return;
    }
    
    
    if (gameIsPaused==false) {
        this->setZOrder(300);
        gameIsPaused=true;
        CCNotificationCenter::sharedNotificationCenter()->postNotification("onPausePressedFromAnimationLayerArcadeMode");
        
        pauseMenuItemButton->setZOrder(700);
        isPausePressed = true;
        menuLayer->setVisible(true);
        menuLayer->setZOrder(600);
        pauseMenuItemButton->setEnabled(false);
        stageMenuItemButton->setEnabled(false);
        mAnimationManager = dynamic_cast<CCBAnimationManager *>( this->getUserObject());
        if (mAnimationManager){
            mAnimationManager->runAnimationsForSequenceNamed("pausePressed");
        }
        
        this->getParent()->pauseSchedulerAndActions();
        return;
    }
    else
    {
        gameIsPaused = false;
        CCNotificationCenter::sharedNotificationCenter()->postNotification("onPausePressedFromAnimationLayerArcadeMode");
        isPausePressed=false;
        pauseMenuItemButton->setEnabled(true);
        stageMenuItemButton->setEnabled(true);
        mAnimationManager = dynamic_cast<CCBAnimationManager *>( this->getUserObject());
        if (mAnimationManager){
            mAnimationManager->runAnimationsForSequenceNamed("resumePressed");
        }
        
        CCSequence *seq=CCSequence::createWithTwoActions(CCDelayTime::create(0.5),CCCallFunc::create(this, callfunc_selector(AnimationLayer::resumeGame)));
        this->runAction(seq);
        return;
    }
}

void AnimationLayerArcadeMode::restart(cocos2d::CCObject * pSender) {
    
    CCNotificationCenter::sharedNotificationCenter()->postNotification("onRestartButtonPressed");

//    ObjCCalls::showActivityIndictor();
//    
//    removeUnusedData();
//    GameManager::sharedGameManager()->remove_unused_data();
//    CCScene *help_scene=GameManager::sharedGameManager()->get_scene("GameLayerArcadeMode.ccbi", "GameLayerArcadeMode",GameLayerArcadeModeLoader::loader(), CCScene::create(),false,false);
//   	CCDirector::sharedDirector()->replaceScene(CCTransitionTurnOffTiles::create(0.5,help_scene));
    
}

void AnimationLayerArcadeMode::menuPressed(cocos2d::CCObject * pSender)
{
    ObjCCalls::showActivityIndictor();
    HoldOnModel::shareModel()->reportArcadeScore();
    removeUnusedData();
    GameManager::sharedGameManager()->remove_unused_data();
    
    CCScene *help_scene=GameManager::sharedGameManager()->get_scene("MenuLayer.ccbi", "MenuLayer", MenuLayerLoader::loader(), CCScene::create(),false,false);
   	CCDirector::sharedDirector()->replaceScene(CCTransitionTurnOffTiles::create(0.2,help_scene));
}



void AnimationLayerArcadeMode::gameOverDown(cocos2d::CCObject * pSender)
{
    this->setZOrder(300);
    
    menuLayer->setVisible(true);
    menuLayer->setZOrder(600);
    mAnimationManager = dynamic_cast<CCBAnimationManager *>( this->getUserObject());
    if (mAnimationManager){
        mAnimationManager->runAnimationsForSequenceNamed("gameOverDown");
    }
    this->getParent()->pauseSchedulerAndActions();
}

void AnimationLayerArcadeMode::gameWonDown(cocos2d::CCObject * pSender)
{
    menuLayer->setVisible(true);
    setZOrder(300);
    menuLayer->setZOrder(600);
    
    mAnimationManager = dynamic_cast<CCBAnimationManager *>( this->getUserObject());
    if (mAnimationManager){
        mAnimationManager->runAnimationsForSequenceNamed("gameWonDown");
    }
    
    this->getParent()->pauseSchedulerAndActions();
}

void AnimationLayerArcadeMode::goToNextLevel(cocos2d::CCObject *pSender)
{
    
}

void AnimationLayerArcadeMode::resumeGame()
{
    pauseMenuItemButton->setEnabled(true);
    this->menuLayer->setZOrder(-1);
    this->menuLayer->setVisible(false);
    this->getParent()->resumeSchedulerAndActions();
}

void AnimationLayerArcadeMode::playAgainUp(cocos2d::CCObject * pSender)
{
    this->menuLayer->setZOrder(-1);
    this->menuLayer->setVisible(false);
    this->getParent()->resumeSchedulerAndActions();
    
}
void AnimationLayerArcadeMode::onStagePressed(cocos2d::CCObject * pSender)
{
    ObjCCalls::showActivityIndictor();
    removeUnusedData();
    GameManager::sharedGameManager()->removeDataOnClick();
    //    int localLevel =tempLevelForPositionTaking;
    //    localLevel++;
    //   if((localLevel>8 && localLevel<17))
    //   {
    //       localLevel=17;
    //   }
    //    if( (localLevel>32 && localLevel<41))
    //    {
    //        localLevel=41;
    //    }
    //
    //    GameManager::sharedGameManager()->gotoScene(localLevel);
    //    tempLevelForPositionTaking =localLevel;
    GameManager::sharedGameManager()->getcurrent_layer()->removeAllChildrenWithCleanup(true);
    
    GameManager::sharedGameManager()->remove_unused_data();
    CCScene *home_scene=GameManager::sharedGameManager()->get_scene("MenuLayer.ccbi", "MenuLayer", MenuLayerLoader::loader(), CCScene::create(),false,false);
    CCDirector::sharedDirector()->replaceScene(CCTransitionTurnOffTiles::create(0.2, home_scene));
}

bool AnimationLayerArcadeMode::ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
    CCPoint point =touch->getLocationInView();
    point = CCDirector::sharedDirector()->convertToGL(point);
    
    //    else if (GameManager::sharedGameManager()->isNodeAtPoint(restartBtn, point)) {
    //        this->restart();
    //    }
    return true;
}

void AnimationLayerArcadeMode::mileStoneCompleted(cocos2d::CCObject * pSender)
{
    this->setZOrder(300);
    pauseMenuItemButton->setZOrder(700);
    isMileStoneAcieved=true;
    menuLayer->setOpacity(255);
    menuLayer->setVisible(true);
    menuLayer->setZOrder(1000);
    menuLayer->setColor(ccBLACK);
    pauseMenuItemButton->setEnabled(false);
    stageMenuItemButton->setEnabled(false);
    
    mAnimationManager = dynamic_cast<CCBAnimationManager *>( this->getUserObject());
    if (mAnimationManager){
        mAnimationManager->runAnimationsForSequenceNamed("mileStoneCompleted");
    }
}

void AnimationLayerArcadeMode::mileStoneCompletedResume(cocos2d::CCObject * pSender)
{
    pauseMenuItemButton->setEnabled(true);
    stageMenuItemButton->setEnabled(true);
    isMileStoneAcieved=false;
    mAnimationManager = dynamic_cast<CCBAnimationManager *>( this->getUserObject());
    if (mAnimationManager){
        mAnimationManager->runAnimationsForSequenceNamed("mileStoneCompletedResume");
    }
}

void AnimationLayerArcadeMode::removeUnusedData(){
      CCNotificationCenter::sharedNotificationCenter()->removeObserver(this->getParent(),"onRestartButtonPressed");
    CCNotificationCenter::sharedNotificationCenter()->removeObserver(this->getParent(), "onPausePressedFromAnimationLayerArcadeMode");
    CCNotificationCenter::sharedNotificationCenter()->removeObserver(this->getParent(), "mileStoneResume");
    
    CCLayerColor *localmenuLayer =menuLayer;
    CCLayerColor *localpauseAndPlayLayer =pauseAndPlayLayer;
    localmenuLayer->removeAllChildren();
    localpauseAndPlayLayer->removeAllChildren();
    //    CC_SAFE_RELEASE_NULL(menuLayer);
    //    CC_SAFE_RELEASE_NULL(pauseAndPlayLayer);
}






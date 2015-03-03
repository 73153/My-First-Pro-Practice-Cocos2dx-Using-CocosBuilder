

#include "../Layers/AnimationLayer.h"
#include "../Layers/MenuLayer.h"
#include "../Layers/MenuLayerLoader.h"
#include "../GameManager/GameManager.h"
#include "../Layers/LevelSelectionLayer.h"
#include "../Layers/LevelSelectionLayerLoader.h"
#include "../Layers/InAppPurchaseLayer.h"
#include "../Layers/InAppPurchaseLayerLoader.h"
#include "../OBJCall/ObjCCalls.h"

//#include "../SQliteManager/ItemDAO.h"



AnimationLayer::AnimationLayer():menuLayer(NULL),isPlayAgain(false),menuBtn(NULL),restartBtn(NULL),resumeBtn(NULL),isPausePressed(NULL),gameIsPaused(NULL),pauseAndPlayLayer(NULL),pauseMenuItemButton(NULL),scoreCountLbl(NULL),restartLabelNotUsed(NULL),gameOverLabelNotUsed(NULL),menuLabelNotUsed(NULL),restartAnotherLabelNotUsed(NULL),resumeLabelNotUsed(NULL),continueLabelNotUsed(NULL),scoreLabelNotUsed(NULL),stageLayer(NULL),multiBallTopPowerLayer(NULL),multiBallTopPowerSpr(NULL),KaccheGameOverLabel(NULL),sroreLabelNotUsed(NULL),stageMenuItemButton(NULL),pauseMenuButton(NULL),stageMenuButton(NULL),kacheLabelGameWon(NULL){
}

AnimationLayer::~AnimationLayer() {
    
}

void AnimationLayer::onEnter() {
    CCNode::onEnter();
    //    pauseAndPlayLayer->setZOrder(500);
    pauseAndPlayLayer->setVisible(true);
    
}

void AnimationLayer::keyBackClicked() {
    
    int localStageCounter = CCUserDefault::sharedUserDefault()->getIntegerForKey("CLICKCOUNTER");
    
    if(localStageCounter==2 || localStageCounter==3 ||localStageCounter==4||localStageCounter==6)
        ObjCCalls::showWhiteActivityIndictor();
    
    else
        ObjCCalls::showActivityIndictor();
    
    removeUnusedData();
    GameManager::sharedGameManager()->getcurrent_layer()->removeAllChildrenWithCleanup(true);
    
    GameManager::sharedGameManager()->remove_unused_data();
    
    CCScene *help_scene=GameManager::sharedGameManager()->get_scene("MenuLayer.ccbi", "MenuLayer", MenuLayerLoader::loader(), CCScene::create(),false,false);
   	CCDirector::sharedDirector()->replaceScene(CCTransitionTurnOffTiles::create(0.2,help_scene));
}

void AnimationLayer::backButtonPressed() {
    
    int localStageCounter = CCUserDefault::sharedUserDefault()->getIntegerForKey("CLICKCOUNTER");
    
    if(localStageCounter==2 || localStageCounter==3 ||localStageCounter==4||localStageCounter==6)
        ObjCCalls::showWhiteActivityIndictor();
    
    else
        ObjCCalls::showActivityIndictor();
    
    removeUnusedData();
    GameManager::sharedGameManager()->getcurrent_layer()->removeAllChildrenWithCleanup(true);
    
    GameManager::sharedGameManager()->remove_unused_data();
    CCScene *help_scene=GameManager::sharedGameManager()->get_scene("MenuLayer.ccbi", "MenuLayer", MenuLayerLoader::loader(), CCScene::create(),false,false);
   	CCDirector::sharedDirector()->replaceScene(CCTransitionTurnOffTiles::create(0.2,help_scene));
}

void AnimationLayer::onInAppPurchaseClicked(cocos2d::CCObject *pSender)
{
    int localStageCounter = CCUserDefault::sharedUserDefault()->getIntegerForKey("CLICKCOUNTER");
    
    if(localStageCounter==2 || localStageCounter==3 ||localStageCounter==4||localStageCounter==6)
        ObjCCalls::showWhiteActivityIndictor();
    else
        ObjCCalls::showActivityIndictor();
    
    removeUnusedData();
    GameManager::sharedGameManager()->getcurrent_layer()->removeAllChildrenWithCleanup(true);
    
    GameManager::sharedGameManager()->remove_unused_data();
    
    CCScene *highScore_scene=GameManager::sharedGameManager()->get_scene("InAppPurchaseLayer.ccbi", "InAppPurchaseLayer",InAppPurchaseLayerLoader::loader(), CCScene::create(),false,false);
    CCDirector::sharedDirector()->replaceScene(CCTransitionTurnOffTiles::create(0.2,highScore_scene));
}


#pragma  mark   COCOSBUILDER INITITIALIZATION
void AnimationLayer::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    ObjCCalls::hideActivityIndicator();
    isPlayAgain = false;
    menuLayer->setVisible(false);
    pauseMenuItemButton->setZOrder(1000);
    this->setZOrder(300);
    
    
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
    //    scoreLabelNotUsed->setFontName("fonts/ZektonRg-Regular.ttf");
    //    TargetPlatform device = CCApplication::sharedApplication()->getTargetPlatform();
    //    CCSize windowSize = CCDirector::sharedDirector()->getWinSize();
    //
    //    float restartLabelNotUsedPosX = restartLabelNotUsed->getPositionX();
    //    float menuLabelNotUsedPosX = menuLabelNotUsed->getPositionX();
    //    float restartAnotherLabelNotUsedPosX = restartAnotherLabelNotUsed->getPositionX();
    //    float resumeLabelNotUsedPosX = resumeLabelNotUsed->getPositionX();
    //    float continueLabelNotUsedPosX = continueLabelNotUsed->getPositionX();
    
    switch (GameManager::sharedGameManager()->get_devise_resolution())
    {
        case 1:
            break;
        case 2:
            if (CCDirector::sharedDirector()->getWinSize().height==1136)
            {
                restartLabelNotUsed->setFontSize(35);
                gameOverLabelNotUsed->setFontSize(70);
                menuLabelNotUsed->setFontSize(35);
                restartAnotherLabelNotUsed->setFontSize(35);
                resumeLabelNotUsed->setFontSize(35);
                continueLabelNotUsed->setFontSize(35);
                sroreLabelNotUsed->setFontSize(35);
                scoreCountLbl->setFontSize(28);
                scoreLabelNotUsed->setFontSize(40);
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
                scoreCountLbl->setFontSize(28);
                scoreLabelNotUsed->setFontSize(40);
                
            }
            break;
        case 3:
        {
            restartLabelNotUsed->setFontSize(35);
            gameOverLabelNotUsed->setFontSize(70);
            menuLabelNotUsed->setFontSize(35);
            restartAnotherLabelNotUsed->setFontSize(35);
            resumeLabelNotUsed->setFontSize(35);
            continueLabelNotUsed->setFontSize(35);
            sroreLabelNotUsed->setFontSize(35);
            scoreCountLbl->setFontSize(28);
            scoreLabelNotUsed->setFontSize(40);
        }
            break;
        case 4:
        {
            restartLabelNotUsed->setFontSize(35);
            gameOverLabelNotUsed->setFontSize(70);
            menuLabelNotUsed->setFontSize(35);
            restartAnotherLabelNotUsed->setFontSize(35);
            resumeLabelNotUsed->setFontSize(35);
            continueLabelNotUsed->setFontSize(35);
            sroreLabelNotUsed->setFontSize(35);
            scoreCountLbl->setFontSize(28);
            scoreLabelNotUsed->setFontSize(40);
            
        }
            break;
        case 5:
        {
            restartLabelNotUsed->setFontSize(35);
            gameOverLabelNotUsed->setFontSize(70);
            menuLabelNotUsed->setFontSize(35);
            restartAnotherLabelNotUsed->setFontSize(35);
            resumeLabelNotUsed->setFontSize(35);
            continueLabelNotUsed->setFontSize(35);
            sroreLabelNotUsed->setFontSize(35);
            scoreCountLbl->setFontSize(28);
            scoreLabelNotUsed->setFontSize(40);
        }
            break;
        case 6:
        {
            
        }
            break;
        default:
            break;
    }
    restartLabelNotUsed->setString("RESTART");
    restartAnotherLabelNotUsed->setString("RESTART");
    menuLabelNotUsed->setString("LEVELS");
    sroreLabelNotUsed->setString("STORE");
    
}

SEL_CallFuncN AnimationLayer::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
    return NULL;
}

SEL_MenuHandler AnimationLayer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "restartPressed", AnimationLayer::restart);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "menuPressed", AnimationLayer::menuPressed);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "playAgainPressed", AnimationLayer::playAgainPressed);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "pauseAndResume", AnimationLayer::pauseAndResume);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "goToNextLevel", AnimationLayer::goToNextLevel);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onStagePressed", AnimationLayer::onStagePressed);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onInAppPurchaseClicked", AnimationLayer::onInAppPurchaseClicked);
    
    return NULL;
}

SEL_CCControlHandler AnimationLayer::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    
    return NULL;
}

bool AnimationLayer::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
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
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "multiBallTopPowerLayer", CCLayerColor*, multiBallTopPowerLayer);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "multiBallTopPowerSpr", CCSprite*, multiBallTopPowerSpr);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "pauseMenuButton", CCMenu*, pauseMenuButton);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "stageMenuButton", CCMenu*, stageMenuButton);
    
    return false;
}

bool AnimationLayer::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    bool bRet = false;
    return bRet;
}

void AnimationLayer::playLableAnimation(cocos2d::CCObject * pSender)
{
    mAnimationManager = dynamic_cast<CCBAnimationManager *>( this->getUserObject());
    if (mAnimationManager)
    {
        mAnimationManager->runAnimationsForSequenceNamed("lableAnimation");
    }
}

void AnimationLayer::pauseAndResume(cocos2d::CCObject * pSender)
{
    //    animationDelegte->removeAllChildern();
    if(isPlayAgain==true)
    {
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
        gameIsPaused = true;
        
        CCNotificationCenter::sharedNotificationCenter()->postNotification("onPausePressedFromAnimationLayer");
        
        pauseMenuItemButton->setZOrder(700);
        isPausePressed = true;
        menuLayer->setVisible(true);
        menuLayer->setZOrder(600);
        pauseMenuItemButton->setEnabled(false);
        mAnimationManager = dynamic_cast<CCBAnimationManager *>( this->getUserObject());
        if (mAnimationManager)
        {
            mAnimationManager->runAnimationsForSequenceNamed("pausePressed");
        }
        
        this->getParent()->pauseSchedulerAndActions();
    }
    else
    {
        gameIsPaused = false;
        CCNotificationCenter::sharedNotificationCenter()->postNotification("onPausePressedFromAnimationLayer");
        
        isPausePressed=false;
        pauseMenuItemButton->setEnabled(true);
        mAnimationManager = dynamic_cast<CCBAnimationManager *>( this->getUserObject());
        if (mAnimationManager){
            mAnimationManager->runAnimationsForSequenceNamed("resumePressed");
        }
        
        CCSequence *seq=CCSequence::createWithTwoActions(CCDelayTime::create(0.5),CCCallFunc::create(this, callfunc_selector(AnimationLayer::resumeGame)));
        this->runAction(seq);
    }
}

void AnimationLayer::restart(cocos2d::CCObject * pSender) {
    CCNotificationCenter::sharedNotificationCenter()->postNotification("onRestartGameLayer");
    return;
//    removeUnusedData();
//    GameManager::sharedGameManager()->removeDataOnClick();
//    int level =  CCUserDefault::sharedUserDefault()->getIntegerForKey("BREAKLEVEL");
//    GameManager::sharedGameManager()->gotoScene(level);
    //
    //        ItemDAO::sharedItemDAO()->insertDataBySentence("name,detail,rare,price,count,clear", "'New items','Details',0,0,0,0");
    //        CCLOG("=============================================");
    //        CCLOG("insertDataBySentence");
}


void AnimationLayer::newUserAuthentication(cocos2d::CCObject *pSender)
{
    mAnimationManager = dynamic_cast<CCBAnimationManager *>( this->getUserObject());
    if (mAnimationManager){
        mAnimationManager->runAnimationsForSequenceNamed("newUserAuthentication");
    }
    menuLayer->setVisible(true);
}
void AnimationLayer::menuPressed(cocos2d::CCObject * pSender)
{
    ObjCCalls::showWhiteActivityIndictor();
    removeUnusedData();
    GameManager::sharedGameManager()->removeDataOnClick();
    
    GameManager::sharedGameManager()->getcurrent_layer()->removeAllChildrenWithCleanup(true);
    
    GameManager::sharedGameManager()->remove_unused_data();
    
    CCScene *home_scene=GameManager::sharedGameManager()->get_scene("LevelSelectionLayer.ccbi", "LevelSelectionLayer", LevelSelectionLayerLoader::loader(), CCScene::create(),false,false);
    CCDirector::sharedDirector()->replaceScene(CCTransitionTurnOffTiles::create(0.2, home_scene));
}

void AnimationLayer::playAgainPressed(cocos2d::CCObject * pSender)
{
    if(isPlayAgain==false)
    {
        this->setZOrder(300);
        
        pauseMenuItemButton->setZOrder(700);
        isPlayAgain = true;
        pauseMenuItemButton->setEnabled(true);
        menuLayer->setVisible(true);
        menuLayer->setZOrder(600);
        this->getParent()->pauseSchedulerAndActions();
        mAnimationManager = dynamic_cast<CCBAnimationManager *>( this->getUserObject());
        if (mAnimationManager)
        {
            mAnimationManager->runAnimationsForSequenceNamed("playAgainDown");
        }
    }
}

void AnimationLayer::gameOverDown(cocos2d::CCObject * pSender)
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

void AnimationLayer::gameWonDown(cocos2d::CCObject * pSender)
{
    menuLayer->setVisible(true);
    setZOrder(300);
    menuLayer->setZOrder(600);
    
    mAnimationManager = dynamic_cast<CCBAnimationManager *>( this->getUserObject());
    if (mAnimationManager){
        mAnimationManager->runAnimationsForSequenceNamed("gameWonDown");
    }
}

void AnimationLayer::goToNextLevel(cocos2d::CCObject *pSender)
{
    removeUnusedData();
    GameManager::sharedGameManager()->removeDataOnClick();
    int level =  CCUserDefault::sharedUserDefault()->getIntegerForKey("BREAKLEVEL");
    GameManager::sharedGameManager()->gotoScene(level+1);
}

void AnimationLayer::resumeGame()
{
    this->menuLayer->setZOrder(-1);
    this->menuLayer->setVisible(false);
    this->getParent()->resumeSchedulerAndActions();
    
    stageLayer->setZOrder(100);
    menuLayer->setOpacity(200);
    pauseMenuItemButton->setEnabled(true);
    
}

void AnimationLayer::playAgainUp(cocos2d::CCObject * pSender)
{
    this->menuLayer->setZOrder(-1);
    this->menuLayer->setVisible(false);
    this->getParent()->resumeSchedulerAndActions();
    
}
void AnimationLayer::onStagePressed(cocos2d::CCObject * pSender)
{
    int localStageCounter = CCUserDefault::sharedUserDefault()->getIntegerForKey("CLICKCOUNTER");
    
    if(localStageCounter==2 || localStageCounter==3 ||localStageCounter==4||localStageCounter==6)
        ObjCCalls::showWhiteActivityIndictor();
    
    else
        ObjCCalls::showActivityIndictor();
    
    removeUnusedData();
    GameManager::sharedGameManager()->removeDataOnClick();
    GameManager::sharedGameManager()->getcurrent_layer()->removeAllChildrenWithCleanup(true);
    
    GameManager::sharedGameManager()->remove_unused_data();
    CCScene *home_scene=GameManager::sharedGameManager()->get_scene("LevelSelectionLayer.ccbi", "LevelSelectionLayer", LevelSelectionLayerLoader::loader(), CCScene::create(),false,false);
    CCDirector::sharedDirector()->replaceScene(CCTransitionTurnOffTiles::create(0.2, home_scene));
}

bool AnimationLayer::ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
    CCPoint point =touch->getLocationInView();
    point = CCDirector::sharedDirector()->convertToGL(point);
    
    //    else if (GameManager::sharedGameManager()->isNodeAtPoint(resumeBtn, point)) {
    //        this->playAgainPressed();
    //    }
    //    else if (GameManager::sharedGameManager()->isNodeAtPoint(restartBtn, point)) {
    //        this->restart();
    //    }
    return true;
}


void AnimationLayer::removeUnusedData(){
    CCNotificationCenter::sharedNotificationCenter()->removeObserver(this->getParent(), "onPausePressedFromAnimationLayer");
    CCNotificationCenter::sharedNotificationCenter()->removeObserver(this->getParent(),"onRestartGameLayer");
    CCLayerColor *localmenuLayer =menuLayer;
    CCLayerColor *localpauseAndPlayLayer =pauseAndPlayLayer;
    localmenuLayer->removeAllChildrenWithCleanup(true);
    localpauseAndPlayLayer->removeAllChildrenWithCleanup(true);
    multiBallTopPowerLayer->removeAllChildrenWithCleanup(true);
    CCLayer *localparentLayer = (CCLayer*)this->getParent();
    localparentLayer->removeAllChildrenWithCleanup(true);
    //    CC_SAFE_RELEASE_NULL(menuLayer);
    //    CC_SAFE_RELEASE_NULL(pauseAndPlayLayer);
}



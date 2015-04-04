
#include "../Layers/MenuLayer.h"
#include "../GameManager/GameManager.h"

using namespace cocos2d;
MenuLayer::MenuLayer():moreBtn(NULL),settingBtn(NULL),settingLbl(NULL),moreLbl(NULL),storeLabelDisplay(NULL),moreLayer(NULL),storeLayer(NULL),settingLayer(NULL),backWoodenBG(NULL),arcadeMenuItemSpr(NULL),challengeMenuItemSpr(NULL),getIsLevelClearArr(NULL){
    
}

void MenuLayer::initBackground() {
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    
    //Background
    CCSprite* menuLayerBackground = CCSprite::create("Background.png");
    
    menuLayerBackground->setPosition(ccp(size.width / 2, size.height / 2));
    this->addChild(menuLayerBackground, 0);
}

void MenuLayer::initMenu() {
    
}

bool MenuLayer::init() {
    if (!CCLayer::init()) {
        return false;
    }
    setTouchEnabled(true);
    setKeypadEnabled(true);
    setTouchPriority(kCCMenuHandlerPriority + 1);
    CCSize winsize = CCDirector::sharedDirector()->getWinSize();
    
    
    this->getHighScoreFromFile();
    this->getControlModeFromFile();
    return true;
}

void MenuLayer::menuQuit(CCObject* pSender) {
    CCDirector::sharedDirector()->end();
}

void MenuLayer::menuStart(CCObject* pSender) {
    
//    GameManager::sharedGameManager()->remove_unused_data();
//    CCScene *highScore_scene=GameManager::sharedGameManager()->get_scene("MonumentSelectionLayer.ccbi", "MonumentSelectionLayer",MonumentSelectionLayerLoader::loader(), CCScene::create(),false,false);
//   	CCDirector::sharedDirector()->replaceScene(CCTransitionTurnOffTiles::create(0.1,highScore_scene));
}

int MenuLayer::getIsLevelCleared(int currentLevelNumber)
{
    CCDictionary *dict=(CCDictionary*)getIsLevelClearArr->objectAtIndex(currentLevelNumber);
    int status_id=atoi(dict->valueForKey("isLevelCleared")->getCString());
    CCLog("currentLevelNumber %d and isLevelCleared %d",currentLevelNumber,status_id);
    return status_id;
}
void MenuLayer::menuArcdeModeStart(cocos2d::CCObject *sender){
    
    GameManager::sharedGameManager()->remove_unused_data();
  
    CCScene *menuSetting_scene=GameManager::sharedGameManager()->get_scene("MainScene.ccbi", "MainScene",MainSceneLoader::loader(), CCScene::create(),false,false);
    CCDirector::sharedDirector()->replaceScene(CCTransitionTurnOffTiles::create(0.1,menuSetting_scene));
}

void MenuLayer::menuHelpClicked(CCObject *pSender) {
    
//    GameManager::sharedGameManager()->remove_unused_data();
//    CCScene *help_scene=GameManager::sharedGameManager()->get_scene("LeaderBoardLayer.ccbi", "LeaderBoardLayer", LeaderBoardLayerLoader::loader(), CCScene::create(),false,false);
//    CCDirector::sharedDirector()->replaceScene(CCTransitionTurnOffTiles::create(0.2,help_scene));
    
}

void MenuLayer::menuMoreClicked(CCObject *pSender) {
    
//    GameManager::sharedGameManager()->remove_unused_data();
//    CCScene *highScore_scene=GameManager::sharedGameManager()->get_scene("InAppPurchaseLayer.ccbi", "InAppPurchaseLayer",InAppPurchaseLayerLoader::loader(), CCScene::create(),false,false);
//    CCDirector::sharedDirector()->replaceScene(CCTransitionTurnOffTiles::create(0.2,highScore_scene));
}

void MenuLayer::menuSetting(CCObject *pSender) {
    
//    GameManager::sharedGameManager()->remove_unused_data();
//    
//    CCScene *menuSetting_scene=GameManager::sharedGameManager()->get_scene("SettingLayer.ccbi", "SettingLayer", SettingLayerLoader::loader(), CCScene::create(),false,false);
//    CCDirector::sharedDirector()->replaceScene(CCTransitionTurnOffTiles::create(0.2,menuSetting_scene));
}
#pragma  mark   TOUCHES    METHODS


bool MenuLayer::haveSavedFile() {
    if (!CCUserDefault::sharedUserDefault()->getBoolForKey("haveSavedFileXml"))
    {
        CCUserDefault::sharedUserDefault()->setBoolForKey("haveSavedFileXml",
                                                          true);
        CCUserDefault::sharedUserDefault()->setIntegerForKey("HighScore", 0);
        
        CCUserDefault::sharedUserDefault()->setIntegerForKey("Sensitivity",
                                                             200);
        CCUserDefault::sharedUserDefault()->flush();
        return false;
    } else {
        return true;
    }
}

void MenuLayer::getHighScoreFromFile() {
    if (haveSavedFile())
    {
    }
}

void MenuLayer::getControlModeFromFile() {
//    ;
//    if (haveSavedFile()) {
//        string cm = CCUserDefault::sharedUserDefault()->getStringForKey("ControlMode", "DAY");
//        if (cm == "DAY") {
//            SettingLayer::setControlMode(SettingLayer::Day);
//        }  if (cm == "NIGHT") {
//            SettingLayer::setControlMode(SettingLayer::Night);
//        }
//    }
}


void MenuLayer::ccTouchesBegan(CCSet *pTouches, CCEvent *event) {
//    CCTouch *myTouch = (CCTouch*) pTouches->anyObject();
//    CCPoint location = myTouch->getLocationInView();
//    location = CCDirector::sharedDirector()->convertToGL(location);
//    if(GameManager::sharedGameManager()->isNodeAtPoint(moreLayer, location)){
//        this->menuHelpClicked(NULL);
//        return;
//    }
//    if(GameManager::sharedGameManager()->isNodeAtPoint(settingLayer, location)){
//        this->menuSetting(NULL);
//        return;
//    }
//    if(GameManager::sharedGameManager()->isNodeAtPoint(storeLayer, location)){
//        this->menuMoreClicked(NULL);
//        return;
//    }
}

#pragma  mark   COCOSBUILDER INITITIALIZATION
void MenuLayer::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    
    getIsLevelClearArr = CCArray::create();
    getIsLevelClearArr->retain();
    
    CCLOG("on loaded called");
    //    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    //    TargetPlatform device = CCApplication::sharedApplication()->getTargetPlatform();
    storeLabelDisplay->setFontName("fonts/Zekton-Bold.ttf");
    moreLbl->setFontName("fonts/Zekton-Bold.ttf");
    settingLbl->setFontName("fonts/Zekton-Bold.ttf");
    //    float moreLblPosX = moreLbl->getPositionX();
    //    float settingLblPosX = settingLbl->getPositionX();
    //    float moreBtnPosX = moreBtn->getPositionX();
    //    float settingBtnPosX = settingBtn->getPositionX();
    switch (GameManager::sharedGameManager()->get_devise_resolution())
    {
        case 1:
            moreLbl->setFontSize(70);
            settingLbl->setFontSize(70);
            storeLabelDisplay->setFontSize(70);
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136){
                moreLbl->setFontSize(40);
                settingLbl->setFontSize(40);
                storeLabelDisplay->setFontSize(40);
                challengeMenuItemSpr->setScale(0.8);
                arcadeMenuItemSpr->setScale(0.8);
                backWoodenBG->setScaleX(0.75);
                
            }
            else{
                moreLbl->setFontSize(40);
                settingLbl->setFontSize(40);
                storeLabelDisplay->setFontSize(40);
                challengeMenuItemSpr->setScale(0.8);
                arcadeMenuItemSpr->setScale(0.8);
                backWoodenBG->setScaleX(1);
            }
        }
            break;
        case 3:{
            moreLbl->setFontSize(40);
            settingLbl->setFontSize(40);
            storeLabelDisplay->setFontSize(40);
            challengeMenuItemSpr->setScale(0.8);
            arcadeMenuItemSpr->setScale(0.8);
            backWoodenBG->setScaleX(0.8);
            
        }
            break;
        case 4:{
            moreLbl->setFontSize(40);
            settingLbl->setFontSize(40);
            storeLabelDisplay->setFontSize(40);
            challengeMenuItemSpr->setScale(0.8);
            arcadeMenuItemSpr->setScale(0.8);
            backWoodenBG->setScaleX(0.8);
            
        }
            
            break;
        case 5:
            moreLbl->setFontSize(40);
            settingLbl->setFontSize(40);
            storeLabelDisplay->setFontSize(40);
            backWoodenBG->setScaleY(1.3);
            challengeMenuItemSpr->setScale(0.8);
            arcadeMenuItemSpr->setScale(0.8);
            
            break;
        case 6:
            challengeMenuItemSpr->setScale(0.8);
            arcadeMenuItemSpr->setScale(0.8);
            moreLbl->setFontSize(70);
            settingLbl->setFontSize(70);
            storeLabelDisplay->setFontSize(70);
            backWoodenBG->setScaleX(0.75);
            break;
            
        default:
            break;
    }
    
    //    CCCallFunc * callFunc = CCCallFunc::create( this, callfunc_selector( MenuLayer::callSubmitScore) );
    //    this->runAction( CCSequence::createWithTwoActions(CCDelayTime::create(3),callFunc));
    
}
void MenuLayer::callSubmitScore()
{
    //    HoldOnModel::shareModel()->reportArcadeScore();
    //    HoldOnModel::shareModel()->reportChallengeScore();
}
void MenuLayer::playAnimation(CCNode* sender)
{
    //    mAnimationManager = dynamic_cast<CCBAnimationManager *>( this->getUserObject());
    //    if (mAnimationManager){
    //        mAnimationManager->runAnimationsForSequenceNamed("gameOverDown");
    //    }
    //    this->getParent()->pauseSchedulerAndActions();
}

SEL_CallFuncN MenuLayer::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CALLFUNC_GLUE(this, "callSubmitScore", MenuLayer::callSubmitScore);
    
    return NULL;
}

SEL_MenuHandler MenuLayer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "menuStart", MenuLayer::menuStart);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "menuHelpClicked", MenuLayer::menuHelpClicked);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "menuMoreClicked", MenuLayer::menuMoreClicked);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "menuSetting", MenuLayer::menuSetting);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "menuArcdeModeStart", MenuLayer::menuArcdeModeStart);
    
    
    return NULL;
}

SEL_CCControlHandler MenuLayer::onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName)
{
    
    return NULL;
}

bool MenuLayer::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "settingLbl",CCLabelTTF *, this->settingLbl);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "moreLbl",CCLabelTTF *, this->moreLbl);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "storeLabelDisplay",CCLabelTTF *, this->storeLabelDisplay);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "moreBtn",CCMenuItemImage *, this->moreBtn);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "settingBtn",CCMenuItemImage *, this->settingBtn);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "moreLayer",CCLayerColor *, this->moreLayer);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "storeLayer",CCLayerColor *, this->storeLayer);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "settingLayer",CCLayerColor *, this->settingLayer);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "backWoodenBG", CCSprite*, backWoodenBG);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "arcadeMenuItemSpr", CCMenuItemImage*, arcadeMenuItemSpr);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "challengeMenuItemSpr", CCMenuItemImage*, challengeMenuItemSpr);
    return false;
}

bool MenuLayer::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    bool bRet = false;
    return bRet;
}

void MenuLayer::removeUnusedData()
{
    
}


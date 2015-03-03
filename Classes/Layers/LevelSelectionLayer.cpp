//
//  LevelSelectionLayerScene.cpp

//
#include "../Layers/LevelSelectionLayer.h"
#include "SimpleAudioEngine.h"
#include "../GameManager/GameManager.h"
#include "../Layers/MenuLayer.h"
#include "../Layers/MenuLayerLoader.h"
#include "../Layers/MonumentSelectionLayer.h"
#include "../Layers/MonumentSelectionLayerLoader.h"
#include "../GameScreen/StrokeTool.h"

using namespace cocos2d;
using namespace CocosDenshion;


LevelSelectionLayer::LevelSelectionLayer():navigationLayerTop(NULL),currentStageToComplete(1),lastPlayedlevel(1),wondersNameLbl(NULL),backgroundImage(NULL),navigationHomeLayer(NULL),navigationBackLayer(NULL),getIsLevelClearArr(NULL),isAnyLevelCleared(false),menuLevels(NULL),levelLayer1(NULL),levelLayer2(NULL),levelLayer3(NULL),levelLayer4(NULL),levelLayer5(NULL),levelLayer6(NULL),levelLayer7(NULL),levelLayer8(NULL),inAppCounter(0),isConnectToInternet(true),
playRePlaySprFirst(NULL),playRePlaySprSecond(NULL),playRePlaySprThird(NULL),playRePlaySprFourth(NULL),playRePlaySprFifth(NULL),playRePlaySprSixth(NULL),playRePlaySprSeventh(NULL),playRePlaySprEighth(NULL),checkInAppWithbool(NULL),swipeIndicationLabel(NULL),
level1(NULL),level2(NULL),level3(NULL),level4(NULL),level5(NULL),level6(NULL),level7(NULL),level8(NULL){
}

LevelSelectionLayer::~LevelSelectionLayer() {
    
}

void LevelSelectionLayer::onEnter() {
    CCLayer::onEnter();
    this->setTouchEnabled(true);
}

void LevelSelectionLayer::onExit() {
    CCLayer::onExit();
    CC_SAFE_RELEASE_NULL(navigationLayerTop);
}
#pragma  mark   COCOSBUILDER INITITIALIZATION
void LevelSelectionLayer::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    CCLOG("on loaded called");
    ObjCCalls::hideActivityIndicator();
    this->setTouchEnabled(true);
    
    getIsLevelClearArr = CCArray::create();
    getIsLevelClearArr->retain();
    
    this->retain();
    int resolution = GameManager::sharedGameManager()->get_devise_resolution();
    
    swipe = CCSwipeGestureRecognizer::create();
    swipe->setTarget(this,callfuncO_selector(LevelSelectionLayer::onDidSwipe));
    swipe->setDirection(kSwipeGestureRecognizerDirectionRight | kSwipeGestureRecognizerDirectionLeft|kSwipeGestureRecognizerDirectionUp|kSwipeGestureRecognizerDirectionDown);
    swipe->setCancelsTouchesInView(true);
    this->addChild(swipe);
    
    CCNotificationCenter::sharedNotificationCenter()->removeObserver(this, "MonumentPurchaseFinishedNotification");
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(LevelSelectionLayer::reflectChangesInUi), "MonumentPurchaseFinishedNotification", NULL);
    
    if(resolution==1 || resolution==6){
        wondersNameLbl->setFontSize(65);
    }
    else{
        swipeIndicationLabel->setFontSize(15);
        wondersNameLbl->setFontSize(30);}
    currentStageToComplete = CCUserDefault::sharedUserDefault()->getIntegerForKey("CLICKCOUNTER");
    if(currentStageToComplete==0){
        CCUserDefault::sharedUserDefault()->setIntegerForKey("CLICKCOUNTER",1);
        CCUserDefault::sharedUserDefault()->flush();
        currentStageToComplete = CCUserDefault::sharedUserDefault()->getIntegerForKey("CLICKCOUNTER");
    }
    
    lastPlayedlevel = CCUserDefault::sharedUserDefault()->getIntegerForKey("LASTPLAYEDLEVEL");
    
    int localcurrentStageToComplete = currentStageToComplete;
    getIsLevelClearArr = GameManager::sharedGameManager()->getstarStoreElements();
    
    if(localcurrentStageToComplete>10 || localcurrentStageToComplete==0)
        localcurrentStageToComplete=1;
    //============CheckBlack Background present or not=============
    bool isblackBg;
    if(localcurrentStageToComplete==2 || localcurrentStageToComplete==3 ||localcurrentStageToComplete==4||localcurrentStageToComplete==6)
        isblackBg=true;
    else
        isblackBg=false;
    
    if(localcurrentStageToComplete==0 || localcurrentStageToComplete==1)
    {
        for (int i=1; i<9; i++) {
            
            CCLayerColor *layer = (CCLayerColor*)this->getChildByTag(i+200);
            layer->setOpacity(200);
            layer->setColor(ccc3(221,221,221));
            
            CCLabelTTF *label = (CCLabelTTF*)this->getChildByTag(i+250);
            if(resolution==1|| resolution==6){
                label->setFontSize(60);
            }
            else{
                label->setFontSize(35);}
            
            label->setString(CCString::createWithFormat("%d",i)->getCString());
            
        }
        
    }
    
    if(localcurrentStageToComplete==2)
    {
        for (int i=9; i<17; i++) {
            
            CCLayerColor *layer = (CCLayerColor*)this->getChildByTag(i+192);
            layer->setOpacity(200);
            layer->setColor(ccc3(221,221,221));
            
            CCLabelTTF *label = (CCLabelTTF*)this->getChildByTag(i+242);
            if(resolution==1|| resolution==6){
                label->setFontSize(60);
            }
            else{
                label->setFontSize(35);}
            
            label->setString(CCString::createWithFormat("%d",i)->getCString());
            
            //            localStarcount = getStarCountAccordingToLevel(i);
        }
        
    }
    if(localcurrentStageToComplete==3)
    {
        for (int i=17; i<25; i++) {
            
            CCLayerColor *layer = (CCLayerColor*)this->getChildByTag(i+184);
            
            layer->setOpacity(200);
            layer->setColor(ccc3(221,221,221));
            
            CCLabelTTF *label = (CCLabelTTF*)this->getChildByTag(i+234);
            if(resolution==1|| resolution==6){
                label->setFontSize(60);
            }
            else{
                label->setFontSize(35);}
            
            label->setString(CCString::createWithFormat("%d",i)->getCString());
            //            localStarcount = getStarCountAccordingToLevel(i);
            
            
        }
    }
    
    if(localcurrentStageToComplete==4)
    {
        for (int i=25; i<33; i++) {
            CCLabelTTF *label = (CCLabelTTF*)this->getChildByTag(i+226);
            if(resolution==1|| resolution==6){
                label->setFontSize(60);
            }
            else{
                label->setFontSize(35);}
            
            label->setString(CCString::createWithFormat("%d",i)->getCString());
            CCLayerColor *layer = (CCLayerColor*)this->getChildByTag(i+176);
            
            layer->setOpacity(200);
            layer->setColor(ccc3(221,221,221));
            
            
            //            localStarcount = getStarCountAccordingToLevel(i);
            
        }
        
    }
    if(localcurrentStageToComplete==5)
    {
        for (int i=33; i<41; i++) {
            CCLabelTTF *label = (CCLabelTTF*)this->getChildByTag(i+218);
            if(resolution==1|| resolution==6){
                label->setFontSize(60);
            }
            else{
                label->setFontSize(35);}
            
            label->setString(CCString::createWithFormat("%d",i)->getCString());
            
            CCLayerColor *layer = (CCLayerColor*)this->getChildByTag(i+168);
            
            layer->setOpacity(200);
            layer->setColor(ccc3(221,221,221));
            
            //            localStarcount = getStarCountAccordingToLevel(i);
            
        }
    }
    if(localcurrentStageToComplete==6)
    {
        for (int i=41; i<49; i++) {
            
            CCLayerColor *layer = (CCLayerColor*)this->getChildByTag(i+160);
            
            layer->setOpacity(200);
            layer->setColor(ccc3(221,221,221));
            
            CCLabelTTF *label = (CCLabelTTF*)this->getChildByTag(i+210);
            if(resolution==1|| resolution==6){
                label->setFontSize(60);
            }
            else{
                label->setFontSize(35);}
            
            label->setString(CCString::createWithFormat("%d",i)->getCString());
            
        }
        
    }
    if(localcurrentStageToComplete==7)
    {
        for (int i=49; i<57; i++) {
            
            CCLabelTTF *label = (CCLabelTTF*)this->getChildByTag(i+202);
            if(resolution==1|| resolution==6){
                label->setFontSize(60);
            }
            else{
                label->setFontSize(35);}
            
            label->setString(CCString::createWithFormat("%d",i)->getCString());
            
            CCLayerColor *layer = (CCLayerColor*)this->getChildByTag(i+152);
            
            layer->setOpacity(200);
            layer->setColor(ccc3(221,221,221));
            
            //            localStarcount = getStarCountAccordingToLevel(i);
        }
        
    }
    
    reflectChangesInUi();
}

void LevelSelectionLayer::onDidSwipe(cocos2d::CCObject * pSender)
{
    CCSwipe * swipe = (CCSwipe*)pSender;
    if (swipe->direction==kSwipeGestureRecognizerDirectionRight)
    {
        int localcurrentStageToComplete = currentStageToComplete;
        if(localcurrentStageToComplete==0)
            localcurrentStageToComplete=1;
        localcurrentStageToComplete=localcurrentStageToComplete-1;
        currentStageToComplete=localcurrentStageToComplete;
        
        if(localcurrentStageToComplete==0)
            return;
        CCUserDefault::sharedUserDefault()->setIntegerForKey("CLICKCOUNTER",localcurrentStageToComplete);
        CCUserDefault::sharedUserDefault()->flush();
        reflectChangesInUi();
        return;
        
    }
    else if (swipe->direction==kSwipeGestureRecognizerDirectionLeft)
    {
        int localcurrentStageToComplete = currentStageToComplete;
        if(localcurrentStageToComplete==0)
            localcurrentStageToComplete=1;
        localcurrentStageToComplete=localcurrentStageToComplete+1;
        currentStageToComplete=localcurrentStageToComplete;
        if(localcurrentStageToComplete==9)
            return;
        CCUserDefault::sharedUserDefault()->setIntegerForKey("CLICKCOUNTER",localcurrentStageToComplete);
        CCUserDefault::sharedUserDefault()->flush();
        
        reflectChangesInUi();
        return;
    }
    else if (swipe->direction==kSwipeGestureRecognizerDirectionUp)
    {
        
    }
    else  if (swipe->direction==kSwipeGestureRecognizerDirectionDown)
    {
        
    }
}


void LevelSelectionLayer::reflectChangesInUi()
{
    isAnyLevelCleared=false;
    
    bool inAppEffielTower = CCUserDefault::sharedUserDefault()->getBoolForKey("com.r3app.bricksbreaker.unlock_eiffel_tower");
    bool inAppStatueOfLiberty = CCUserDefault::sharedUserDefault()->getBoolForKey("com.r3app.bricksbreaker.unlock_statue_of_liberty");
    bool inAppTowerOfPisa = CCUserDefault::sharedUserDefault()->getBoolForKey("com.r3app.bricksbreaker.unlock_leaning_tower");
    bool inAppBigBen = CCUserDefault::sharedUserDefault()->getBoolForKey("com.r3app.bricksbreaker.unlock_big_ban");
    bool inAppColosseum = CCUserDefault::sharedUserDefault()->getBoolForKey("com.r3app.bricksbreaker.unlock_colosseum");
    bool inAppOperaHouse = CCUserDefault::sharedUserDefault()->getBoolForKey("com.r3app.bricksbreaker.unlock_sydney_opera_house");
    bool inAppEasterStone = CCUserDefault::sharedUserDefault()->getBoolForKey("com.r3app.bricksbreaker.unlock_easter_island_stone");
    bool inAppUnlockAllMonuments = CCUserDefault::sharedUserDefault()->getBoolForKey("com.r3app.bricksbreaker.unlockAllMonuments");
    
    
    getIsLevelClearArr = GameManager::sharedGameManager()->getstarStoreElements();
    int  localcurrentStageToComplete = CCUserDefault::sharedUserDefault()->getIntegerForKey("CLICKCOUNTER");
    lastPlayedlevel = CCUserDefault::sharedUserDefault()->getIntegerForKey("LASTPLAYEDLEVEL");
    
    int levelClearCount =0;
    int idxForStageClear;
    if(inAppUnlockAllMonuments==true){
        
        for (int i=1; i<=56; i++) {
            levelClearCount = getIsLevelCleared(i);
            if(levelClearCount==3)
            {
            }
            else if(levelClearCount==2)
            {
                
            }
            else{
                GameManager::sharedGameManager()->save_LastPlayedLavel(i, 0, 2);
            }
        }
    }
    else{
        if(localcurrentStageToComplete==0 || localcurrentStageToComplete==1){
            if(inAppEffielTower==true){
                
                for (int i=1; i<=8; i++) {
                    levelClearCount = getIsLevelCleared(i);
                    if(levelClearCount==3){
                        
                    }
                    else if(levelClearCount==2){
                        
                    }
                    else{
                        GameManager::sharedGameManager()->save_LastPlayedLavel(i, 0, 2);
                    }
                }
            }
            else
            {
                idxForStageClear=0;
                for (int i=1; i<=8; i++) {
                    levelClearCount = getIsLevelCleared(i);
                    if(levelClearCount==3)
                    {
                        idxForStageClear++;
                        if(idxForStageClear==8){
                            CCUserDefault::sharedUserDefault()->setBoolForKey("com.r3app.bricksbreaker.unlock_eiffel_tower",true);
                            CCUserDefault::sharedUserDefault()->flush();
                        }
                        
                    }
                }
            }
        }
        if(localcurrentStageToComplete==2){
            if(inAppStatueOfLiberty==true){
                for (int i=9; i<=16; i++) {
                    levelClearCount = getIsLevelCleared(i);
                    
                    if(levelClearCount==3){
                        
                    }
                    else if(levelClearCount==2)
                    {
                        
                    }
                    else{
                        GameManager::sharedGameManager()->save_LastPlayedLavel(i, 0, 2);
                    }
                }
            }
            else{
                idxForStageClear=0;
                for (int i=9; i<=16; i++) {
                    levelClearCount = getIsLevelCleared(i);
                    
                    if(levelClearCount==3)
                    {
                        idxForStageClear++;
                        if(idxForStageClear==8){
                            CCUserDefault::sharedUserDefault()->setBoolForKey("com.r3app.bricksbreaker.unlock_statue_of_liberty",true);
                            CCUserDefault::sharedUserDefault()->flush();
                        }
                    }
                }
            }
            
        }
        
        if(localcurrentStageToComplete==3){
            if(inAppTowerOfPisa==true){
                for (int i=17; i<=24; i++) {
                    levelClearCount = getIsLevelCleared(i);
                    if(levelClearCount==3)
                    {
                        
                    }
                    else if(levelClearCount==2)
                    {
                        
                    }
                    else{
                        GameManager::sharedGameManager()->save_LastPlayedLavel(i, 0, 2);
                    }
                }
            }
            else
            {
                idxForStageClear=0;
                for (int i=17; i<=24; i++) {
                    levelClearCount = getIsLevelCleared(i);
                    if(levelClearCount==3)
                    {
                        idxForStageClear++;
                        if(idxForStageClear==8){
                            CCUserDefault::sharedUserDefault()->setBoolForKey("com.r3app.bricksbreaker.unlock_leaning_tower",true);
                            CCUserDefault::sharedUserDefault()->flush();
                        }
                    }
                }
            }
            
        }
        if(localcurrentStageToComplete==4){
            if(inAppBigBen==true){
                for (int i=25; i<=32; i++) {
                    levelClearCount = getIsLevelCleared(i);
                    if(levelClearCount==3)
                    {
                        
                    }
                    else if(levelClearCount==2)
                    {
                        
                    }
                    else{
                        GameManager::sharedGameManager()->save_LastPlayedLavel(i, 0, 2);
                    }
                }
            }
            else
            {
                idxForStageClear=0;
                for (int i=25; i<=32; i++) {
                    levelClearCount = getIsLevelCleared(i);
                    if(levelClearCount==3)
                    {
                        idxForStageClear++;
                        if(idxForStageClear==8){
                            CCUserDefault::sharedUserDefault()->setBoolForKey("com.r3app.bricksbreaker.unlock_big_ban",true);
                            CCUserDefault::sharedUserDefault()->flush();
                        }
                    }
                }
            }
        }
        if(localcurrentStageToComplete==5){
            if(inAppColosseum==true){
                for (int i=33; i<=40; i++) {
                    levelClearCount = getIsLevelCleared(i);
                    
                    if(levelClearCount==3)
                    {
                        
                    }
                    else if(levelClearCount==2)
                    {
                        
                    }
                    else{
                        GameManager::sharedGameManager()->save_LastPlayedLavel(i, 0,2);
                    }
                }
            }
            else
            {
                idxForStageClear=0;
                for (int i=33; i<=40; i++) {
                    levelClearCount = getIsLevelCleared(i);
                    
                    if(levelClearCount==3)
                    {
                        idxForStageClear++;
                        if(idxForStageClear==8){
                            CCUserDefault::sharedUserDefault()->setBoolForKey("com.r3app.bricksbreaker.unlock_colosseum",true);
                            CCUserDefault::sharedUserDefault()->flush();
                        }
                    }
                }
            }
        }
        if(localcurrentStageToComplete==6){
            if(inAppOperaHouse==true){
                for (int i=41; i<=48; i++) {
                    levelClearCount = getIsLevelCleared(i);
                    if(levelClearCount==3)
                    {
                        
                    }
                    else if(levelClearCount==2)
                    {
                        
                    }
                    else{
                        GameManager::sharedGameManager()->save_LastPlayedLavel(i, 0, 2);
                    }
                }
            }
            else
            {
                idxForStageClear=0;
                for (int i=41; i<=48; i++) {
                    levelClearCount = getIsLevelCleared(i);
                    if(levelClearCount==3)
                    {
                        idxForStageClear++;
                        if(idxForStageClear==8){
                            CCUserDefault::sharedUserDefault()->setBoolForKey("com.r3app.bricksbreaker.unlock_sydney_opera_house",true);
                            CCUserDefault::sharedUserDefault()->flush();
                        }
                    }
                }
            }
        }
        if(localcurrentStageToComplete==7){
            if(inAppEasterStone==true){
                for (int i=49; i<=56; i++) {
                    levelClearCount = getIsLevelCleared(i);
                    if(levelClearCount==3)
                    {
                        
                    }
                    else if(levelClearCount==2)
                    {
                        
                    }
                    else{
                        GameManager::sharedGameManager()->save_LastPlayedLavel(i, 0,2);
                    }
                }
            }
            else
            {
                idxForStageClear=0;
                for (int i=49; i<=56; i++) {
                    levelClearCount = getIsLevelCleared(i);
                    if(levelClearCount==3)
                    {
                        idxForStageClear++;
                        if(idxForStageClear==8){
                            CCUserDefault::sharedUserDefault()->setBoolForKey("com.r3app.bricksbreaker.unlock_easter_island_stone",true);
                            CCUserDefault::sharedUserDefault()->flush();
                        }
                    }
                }
            }
        }
    }
    
    switch (localcurrentStageToComplete) {
        case 1:
            wondersNameLbl->setString("EIFFEL TOWER");
            backgroundImage->setDisplayFrame(CCSpriteFrame::create("mon-1.png",backgroundImage->getTextureRect()));
            break;
        case 2:
            backgroundImage->setDisplayFrame(CCSpriteFrame::create("mon-2.png",backgroundImage->getTextureRect()));
            wondersNameLbl->setString("STATUE OF LIBERTY");
            break;
        case 3:
            
            backgroundImage->setDisplayFrame(CCSpriteFrame::create("mon-3.png",backgroundImage->getTextureRect()));
            wondersNameLbl->setString("TOWER OF PISA");
            break;
        case 4:
            
            backgroundImage->setDisplayFrame(CCSpriteFrame::create("mon-4.png",backgroundImage->getTextureRect()));
            wondersNameLbl->setString("BIG BEN");
            break;
        case 5:
            backgroundImage->setDisplayFrame(CCSpriteFrame::create("mon-5.png",backgroundImage->getTextureRect()));
            wondersNameLbl->setString("COLOSSEUM");
            
            break;
        case 6:
            
            backgroundImage->setDisplayFrame(CCSpriteFrame::create("mon-6.png",backgroundImage->getTextureRect()));
            wondersNameLbl->setString("OPERA HOUSE");
            break;
        case 7:
            
            backgroundImage->setDisplayFrame(CCSpriteFrame::create("mon-7.png",backgroundImage->getTextureRect()));
            wondersNameLbl->setString("EASTER STONE");
            
            break;
            
        default:
            break;
    }
    
    getIsLevelClearArr = GameManager::sharedGameManager()->getstarStoreElements();
    
    int locallastPlayedlevel= lastPlayedlevel;
    
    CCSize windowSize  = CCDirector::sharedDirector()->getWinSize();
    if(windowSize.height==1334)
        backgroundImage->setScaleY(1.4);
    
    if(localcurrentStageToComplete>10 || localcurrentStageToComplete==0)
        localcurrentStageToComplete=1;
    //============CheckBlack Background present or not=============
    bool isblackBg;
    if(localcurrentStageToComplete==2 || localcurrentStageToComplete==3 ||localcurrentStageToComplete==4||localcurrentStageToComplete==6)
        isblackBg=true;
    else
        isblackBg=false;
    
    
    
    if(localcurrentStageToComplete==1)
    {
        for (int i=1; i<9; i++) {
            int checkingCount = getIsLevelCleared(i);
            switch (i) {
                case 1:
                    level1->setString("1");
                    break;
                case 2:
                    level2->setString("2");
                    break;
                case 3:
                    level3->setString("3");
                    break;
                case 4:
                    level4->setString("4");
                    break;
                case 5:
                    level5->setString("5");
                    break;
                case 6:
                    level6->setString("6");
                    break;
                case 7:
                    level7->setString("7");
                    break;
                case 8:
                    level8->setString("8");
                    break;
                default:
                    break;
            }
            
            switch (checkingCount) {
                case 3:{
                    isAnyLevelCleared=true;
                    if(i==locallastPlayedlevel){
                        {
                            if(i==1){
                                playRePlaySprFirst->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==2){
                                playRePlaySprSecond->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==3){
                                playRePlaySprThird->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==4){
                                playRePlaySprFourth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==5){
                                playRePlaySprFifth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==6){
                                playRePlaySprSixth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==7){
                                playRePlaySprSeventh->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==8){
                                playRePlaySprEighth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                        }
                    }
                    else{
                        if(i==1){
                            playRePlaySprFirst->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==2){
                            playRePlaySprSecond->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==3){
                            playRePlaySprThird->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==4){
                            playRePlaySprFourth->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==5){
                            playRePlaySprFifth->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==6){
                            playRePlaySprSixth->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==7){
                            playRePlaySprSeventh->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==8){
                            playRePlaySprEighth->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        
                    }
                }
                    break;
                case 2:{
                    isAnyLevelCleared=true;
                    if(i==1){
                        playRePlaySprFirst->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==2){
                        playRePlaySprSecond->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==3){
                        playRePlaySprThird->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==4){
                        playRePlaySprFourth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==5){
                        playRePlaySprFifth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==6){
                        playRePlaySprSixth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==7){
                        playRePlaySprSeventh->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==8){
                        playRePlaySprEighth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                }
                    break;
                case 0:{
                    
                    if(i==1){
                        playRePlaySprFirst->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==2){
                        playRePlaySprSecond->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==3){
                        playRePlaySprThird->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==4){
                        playRePlaySprFourth->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==5){
                        playRePlaySprFifth->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==6){
                        playRePlaySprSixth->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==7){
                        playRePlaySprSeventh->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==8){
                        playRePlaySprEighth->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                }
                    break;
                default:
                    break;
            }
        }
        
    }
    if(localcurrentStageToComplete==2)
    {
        for (int i=9; i<17; i++) {
            int checkingCount = getIsLevelCleared(i);
            
            switch (i) {
                case 9:
                    level1->setString("9");
                    break;
                case 10:
                    level2->setString("10");
                    break;
                case 11:
                    level3->setString("11");
                    break;
                case 12:
                    level4->setString("12");
                    break;
                case 13:
                    level5->setString("13");
                    break;
                case 14:
                    level6->setString("14");
                    break;
                case 15:
                    level7->setString("15");
                    break;
                case 16:
                    level8->setString("16");
                    break;
                default:
                    break;
            }
            switch (checkingCount) {
                case 3:{
                    isAnyLevelCleared=true;
                    
                    if(i==locallastPlayedlevel){
                        {
                            if(i==9){
                                playRePlaySprFirst->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==10){
                                playRePlaySprSecond->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==11){
                                playRePlaySprThird->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==12){
                                playRePlaySprFourth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==13){
                                playRePlaySprFifth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==14){
                                playRePlaySprSixth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==15){
                                playRePlaySprSeventh->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==16){
                                playRePlaySprEighth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                        }
                    }
                    else{
                        if(i==9){
                            playRePlaySprFirst->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==10){
                            playRePlaySprSecond->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==11){
                            playRePlaySprThird->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==12){
                            playRePlaySprFourth->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==13){
                            playRePlaySprFifth->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==14){
                            playRePlaySprSixth->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==15){
                            playRePlaySprSeventh->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==16){
                            playRePlaySprEighth->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        
                    }
                }
                    break;
                case 2:{
                    isAnyLevelCleared=true;
                    
                    if(i==9){
                        playRePlaySprFirst->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==10){
                        playRePlaySprSecond->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==11){
                        playRePlaySprThird->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==12){
                        playRePlaySprFourth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==13){
                        playRePlaySprFifth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==14){
                        playRePlaySprSixth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==15){
                        playRePlaySprSeventh->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==16){
                        playRePlaySprEighth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                }
                    break;
                case 0:{
                    
                    if(i==9){
                        playRePlaySprFirst->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==10){
                        playRePlaySprSecond->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==11){
                        playRePlaySprThird->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==12){
                        playRePlaySprFourth->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==13){
                        playRePlaySprFifth->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==14){
                        playRePlaySprSixth->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==15){
                        playRePlaySprSeventh->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==16){
                        playRePlaySprEighth->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                }
                    break;
                    
                default:
                    break;
            }
        }
    }
    if(localcurrentStageToComplete==3)
    {
        for (int i=17; i<25; i++) {
            switch (i) {
                case 17:
                    level1->setString("17");
                    break;
                case 18:
                    level2->setString("18");
                    break;
                case 19:
                    level3->setString("19");
                    break;
                case 20:
                    level4->setString("20");
                    break;
                case 21:
                    level5->setString("21");
                    break;
                case 22:
                    level6->setString("22");
                    break;
                case 23:
                    level7->setString("23");
                    break;
                case 24:
                    level8->setString("24");
                    break;
                default:
                    break;
            }
            
            int checkingCount = getIsLevelCleared(i);
            switch (checkingCount) {
                case 3:{
                    isAnyLevelCleared=true;
                    
                    if(i==locallastPlayedlevel){
                        {
                            if(i==17){
                                playRePlaySprFirst->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==18){
                                playRePlaySprSecond->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==19){
                                playRePlaySprThird->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==20){
                                playRePlaySprFourth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==21){
                                playRePlaySprFifth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==22){
                                playRePlaySprSixth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==23){
                                playRePlaySprSeventh->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==24){
                                playRePlaySprEighth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                        }
                    }
                    else{
                        if(i==17){
                            playRePlaySprFirst->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==18){
                            playRePlaySprSecond->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==19){
                            playRePlaySprThird->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==20){
                            playRePlaySprFourth->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==21){
                            playRePlaySprFifth->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==22){
                            playRePlaySprSixth->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==23){
                            playRePlaySprSeventh->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==24){
                            playRePlaySprEighth->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        
                    }
                }
                    break;
                case 2:{
                    isAnyLevelCleared=true;
                    
                    if(i==17){
                        playRePlaySprFirst->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==18){
                        playRePlaySprSecond->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==19){
                        playRePlaySprThird->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==20){
                        playRePlaySprFourth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==21){
                        playRePlaySprFifth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==22){
                        playRePlaySprSixth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==23){
                        playRePlaySprSeventh->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==24){
                        playRePlaySprEighth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                }
                    break;
                case 0:{
                    
                    if(i==17){
                        playRePlaySprFirst->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==18){
                        playRePlaySprSecond->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==19){
                        playRePlaySprThird->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==20){
                        playRePlaySprFourth->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==21){
                        playRePlaySprFifth->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==22){
                        playRePlaySprSixth->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==23){
                        playRePlaySprSeventh->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==24){
                        playRePlaySprEighth->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                }
                    break;
                    
                default:
                    break;
            }
        }
        
    }
    if(localcurrentStageToComplete==4)
    {
        for (int i=25; i<33; i++) {
            switch (i) {
                case 25:
                    level1->setString("25");
                    break;
                case 26:
                    level2->setString("26");
                    break;
                case 27:
                    level3->setString("27");
                    break;
                case 28:
                    level4->setString("28");
                    break;
                case 29:
                    level5->setString("29");
                    break;
                case 30:
                    level6->setString("30");
                    break;
                case 31:
                    level7->setString("31");
                    break;
                case 32:
                    level8->setString("32");
                    break;
                default:
                    break;
            }
            
            
            int checkingCount = getIsLevelCleared(i);
            switch (checkingCount) {
                case 3:{
                    isAnyLevelCleared=true;
                    
                    
                    if(i==locallastPlayedlevel){
                        {
                            if(i==25){
                                playRePlaySprFirst->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==26){
                                playRePlaySprSecond->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==27){
                                playRePlaySprThird->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==28){
                                playRePlaySprFourth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==29){
                                playRePlaySprFifth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==30){
                                playRePlaySprSixth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==31){
                                playRePlaySprSeventh->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==32){
                                playRePlaySprEighth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                        }
                    }
                    else{
                        if(i==25){
                            playRePlaySprFirst->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==26){
                            playRePlaySprSecond->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==27){
                            playRePlaySprThird->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==28){
                            playRePlaySprFourth->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==29){
                            playRePlaySprFifth->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==30){
                            playRePlaySprSixth->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==31){
                            playRePlaySprSeventh->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==32){
                            playRePlaySprEighth->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        
                    }
                }
                    break;
                case 2:{
                    isAnyLevelCleared=true;
                    
                    if(i==25){
                        playRePlaySprFirst->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==26){
                        playRePlaySprSecond->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==27){
                        playRePlaySprThird->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==28){
                        playRePlaySprFourth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==29){
                        playRePlaySprFifth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==30){
                        playRePlaySprSixth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==31){
                        playRePlaySprSeventh->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==32){
                        playRePlaySprEighth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                }
                    break;
                case 0:{
                    
                    if(i==25){
                        playRePlaySprFirst->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==26){
                        playRePlaySprSecond->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==27){
                        playRePlaySprThird->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==28){
                        playRePlaySprFourth->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==29){
                        playRePlaySprFifth->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==30){
                        playRePlaySprSixth->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==31){
                        playRePlaySprSeventh->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==32){
                        playRePlaySprEighth->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                }
                    break;
                    
                default:
                    break;
            }
        }
        
    }
    if(localcurrentStageToComplete==5)
    {
        for (int i=33; i<41; i++) {
            
            switch (i) {
                case 33:
                    level1->setString("33");
                    break;
                case 34:
                    level2->setString("34");
                    break;
                case 35:
                    level3->setString("35");
                    break;
                case 36:
                    level4->setString("36");
                    break;
                case 37:
                    level5->setString("37");
                    break;
                case 38:
                    level6->setString("38");
                    break;
                case 39:
                    level7->setString("39");
                    break;
                case 40:
                    level8->setString("40");
                    break;
                default:
                    break;
            }
            
            int checkingCount = getIsLevelCleared(i);
            switch (checkingCount) {
                case 3:{
                    isAnyLevelCleared=true;
                    
                    if(i==locallastPlayedlevel){
                        {
                            if(i==33){
                                playRePlaySprFirst->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==34){
                                playRePlaySprSecond->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==35){
                                playRePlaySprThird->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==36){
                                playRePlaySprFourth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==37){
                                playRePlaySprFifth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==38){
                                playRePlaySprSixth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==39){
                                playRePlaySprSeventh->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==40){
                                playRePlaySprEighth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                        }
                    }
                    else{
                        if(i==33){
                            playRePlaySprFirst->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==34){
                            playRePlaySprSecond->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==35){
                            playRePlaySprThird->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==36){
                            playRePlaySprFourth->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==37){
                            playRePlaySprFifth->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==38){
                            playRePlaySprSixth->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==39){
                            playRePlaySprSeventh->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==40){
                            playRePlaySprEighth->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        
                    }
                }
                    break;
                case 2:{
                    isAnyLevelCleared=true;
                    
                    if(i==33){
                        playRePlaySprFirst->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==34){
                        playRePlaySprSecond->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==35){
                        playRePlaySprThird->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==36){
                        playRePlaySprFourth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==37){
                        playRePlaySprFifth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==38){
                        playRePlaySprSixth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==39){
                        playRePlaySprSeventh->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==40){
                        playRePlaySprEighth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                }
                    break;
                case 0:{
                    
                    if(i==33){
                        playRePlaySprFirst->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==34){
                        playRePlaySprSecond->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==35){
                        playRePlaySprThird->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==36){
                        playRePlaySprFourth->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==37){
                        playRePlaySprFifth->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==38){
                        playRePlaySprSixth->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==39){
                        playRePlaySprSeventh->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==40){
                        playRePlaySprEighth->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                }
                    break;
                    
                default:
                    break;
            }
        }
    }
    if(localcurrentStageToComplete==6)
    {
        for (int i=41; i<49; i++) {
            
            switch (i) {
                case 41:
                    level1->setString("41");
                    break;
                case 42:
                    level2->setString("42");
                    break;
                case 43:
                    level3->setString("43");
                    break;
                case 44:
                    level4->setString("44");
                    break;
                case 45:
                    level5->setString("45");
                    break;
                case 46:
                    level6->setString("46");
                    break;
                case 47:
                    level7->setString("47");
                    break;
                case 48:
                    level8->setString("48");
                    break;
                default:
                    break;
            }
            int checkingCount = getIsLevelCleared(i);
            switch (checkingCount) {
                case 3:{
                    isAnyLevelCleared=true;
                    if(i==locallastPlayedlevel){
                        {
                            if(i==41){
                                playRePlaySprFirst->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==42){
                                playRePlaySprSecond->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==43){
                                playRePlaySprThird->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==44){
                                playRePlaySprFourth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==45){
                                playRePlaySprFifth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==46){
                                playRePlaySprSixth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==47){
                                playRePlaySprSeventh->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==48){
                                playRePlaySprEighth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                        }
                    }
                    else{
                        if(i==41){
                            playRePlaySprFirst->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==42){
                            playRePlaySprSecond->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==43){
                            playRePlaySprThird->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==44){
                            playRePlaySprFourth->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==45){
                            playRePlaySprFifth->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==46){
                            playRePlaySprSixth->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==47){
                            playRePlaySprSeventh->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==48){
                            playRePlaySprEighth->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                    }
                }
                    break;
                case 2:{
                    isAnyLevelCleared=true;
                    
                    if(i==41){
                        playRePlaySprFirst->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==42){
                        playRePlaySprSecond->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==43){
                        playRePlaySprThird->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==44){
                        playRePlaySprFourth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==45){
                        playRePlaySprFifth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==46){
                        playRePlaySprSixth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==47){
                        playRePlaySprSeventh->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==48){
                        playRePlaySprEighth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                }
                    break;
                case 0:{
                    
                    if(i==41){
                        playRePlaySprFirst->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==42){
                        playRePlaySprSecond->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==43){
                        playRePlaySprThird->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==44){
                        playRePlaySprFourth->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==45){
                        playRePlaySprFifth->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==46){
                        playRePlaySprSixth->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==47){
                        playRePlaySprSeventh->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==48){
                        playRePlaySprEighth->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                }
                    break;
                    
                default:
                    break;
            }
        }
        
    }
    if(localcurrentStageToComplete==7)
    {
        for (int i=49; i<57; i++) {
            switch (i) {
                case 49:
                    level1->setString("49");
                    break;
                case 50:
                    level2->setString("50");
                    break;
                case 51:
                    level3->setString("51");
                    break;
                case 52:
                    level4->setString("52");
                    break;
                case 53:
                    level5->setString("53");
                    break;
                case 54:
                    level6->setString("54");
                    break;
                case 55:
                    level7->setString("55");
                    break;
                case 56:
                    level8->setString("56");
                    break;
                default:
                    break;
            }
            
            
            int checkingCount = getIsLevelCleared(i);
            switch (checkingCount) {
                case 3:{
                    isAnyLevelCleared=true;
                    
                    if(i==locallastPlayedlevel){
                        {
                            if(i==49){
                                playRePlaySprFirst->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==50){
                                playRePlaySprSecond->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==51){
                                playRePlaySprThird->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==52){
                                playRePlaySprFourth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==53){
                                playRePlaySprFifth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==54){
                                playRePlaySprSixth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==55){
                                playRePlaySprSeventh->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                            if(i==56){
                                playRePlaySprEighth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                            }
                        }
                    }
                    else{
                        if(i==49){
                            playRePlaySprFirst->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==50){
                            playRePlaySprSecond->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==51){
                            playRePlaySprThird->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==52){
                            playRePlaySprFourth->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==53){
                            playRePlaySprFifth->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==54){
                            playRePlaySprSixth->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==55){
                            playRePlaySprSeventh->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        if(i==56){
                            playRePlaySprEighth->setTexture(CCTextureCache::sharedTextureCache()->addImage("replay-screen3.png"));
                        }
                        
                    }
                }
                    break;
                case 2:{
                    isAnyLevelCleared=true;
                    
                    if(i==49){
                        playRePlaySprFirst->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==50){
                        playRePlaySprSecond->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==51){
                        playRePlaySprThird->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==52){
                        playRePlaySprFourth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==53){
                        playRePlaySprFifth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==54){
                        playRePlaySprSixth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==55){
                        playRePlaySprSeventh->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                    if(i==56){
                        playRePlaySprEighth->setTexture(CCTextureCache::sharedTextureCache()->addImage("playBtn.png"));
                    }
                }
                    break;
                case 0:{
                    
                    if(i==49){
                        playRePlaySprFirst->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==50){
                        playRePlaySprSecond->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==51){
                        playRePlaySprThird->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==52){
                        playRePlaySprFourth->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==53){
                        playRePlaySprFifth->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==54){
                        playRePlaySprSixth->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==55){
                        playRePlaySprSeventh->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                    if(i==56){
                        playRePlaySprEighth->setTexture(CCTextureCache::sharedTextureCache()->addImage("lock.png"));
                    }
                }
                    break;
                    
                    
                default:
                    break;
            }
        }
    }
}

SEL_CallFuncN LevelSelectionLayer::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
    return NULL;
}

SEL_MenuHandler LevelSelectionLayer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onBackClicked", LevelSelectionLayer::onBackClicked);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "menuItemClicked", LevelSelectionLayer::menuItemClicked);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onHomeClicked", LevelSelectionLayer::onHomeClicked);
    
    
    return NULL;
}

SEL_CCControlHandler LevelSelectionLayer::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}

bool LevelSelectionLayer::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "backgroundImage",CCSprite *, this->backgroundImage);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "navigationLayerTop",CCLayerColor *, this->navigationLayerTop);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "navigationHomeLayer",CCLayerColor *, this->navigationHomeLayer);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "navigationBackLayer",CCLayerColor *, this->navigationBackLayer);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "wondersNameLbl",CCLabelTTF *, this->wondersNameLbl);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "menuLevels",CCMenu *, this->menuLevels);
    
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "levelLayer1",CCLayerColor *, this->levelLayer1);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "levelLayer2",CCLayerColor *, this->levelLayer2);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "levelLayer3",CCLayerColor *, this->levelLayer3);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "levelLayer4",CCLayerColor *, this->levelLayer4);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "levelLayer5",CCLayerColor *, this->levelLayer5);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "levelLayer6",CCLayerColor *, this->levelLayer6);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "levelLayer7",CCLayerColor *, this->levelLayer7);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "levelLayer8",CCLayerColor *, this->levelLayer8);
    
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "playRePlaySprFirst",CCSprite *, this->playRePlaySprFirst);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "playRePlaySprSecond",CCSprite *, this->playRePlaySprSecond);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "playRePlaySprThird",CCSprite *, this->playRePlaySprThird);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "playRePlaySprFourth",CCSprite *, this->playRePlaySprFourth);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "playRePlaySprFifth",CCSprite *, this->playRePlaySprFifth);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "playRePlaySprSixth",CCSprite *, this->playRePlaySprSixth);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "playRePlaySprSeventh",CCSprite *, this->playRePlaySprSeventh);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "playRePlaySprEighth",CCSprite *, this->playRePlaySprEighth);
    
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level1",CCLabelTTF *, this->level1);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level2",CCLabelTTF *, this->level2);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level3",CCLabelTTF *, this->level3);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level4",CCLabelTTF *, this->level4);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level5",CCLabelTTF *, this->level5);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level6",CCLabelTTF *, this->level6);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level7",CCLabelTTF *, this->level7);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level8",CCLabelTTF *, this->level8);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "swipeIndicationLabel",CCLabelTTF *, this->swipeIndicationLabel);
    return false;
}

bool LevelSelectionLayer::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    bool bRet = false;
    return bRet;
}

bool LevelSelectionLayer::init() {
    
    return true;
}

void LevelSelectionLayer::onBackClicked(cocos2d::CCObject *sender)
{
    ObjCCalls::showActivityIndictor();
    swipe->setCancelsTouchesInView(false);
    GameManager::sharedGameManager()->remove_unused_data();
    
    CCScene *highScore_scene=GameManager::sharedGameManager()->get_scene("MonumentSelectionLayer.ccbi", "MonumentSelectionLayer",MonumentSelectionLayerLoader::loader(), CCScene::create(),false,false);
    CCDirector::sharedDirector()->replaceScene(CCTransitionFlipX::create(0.2,highScore_scene));
    //    CCScene *highScore_scene=GameManager::sharedGameManager()->get_scene("MenuLayer.ccbi", "MenuLayer",MenuLayerLoader::loader(), CCScene::create(),false,false);
    //   	CCDirector::sharedDirector()->replaceScene(CCTransitionRotoZoom::create(0.3,highScore_scene));
}

void LevelSelectionLayer::onHomeClicked(cocos2d::CCObject *sender)
{
    ObjCCalls::showActivityIndictor();
    swipe->setCancelsTouchesInView(false);
    GameManager::sharedGameManager()->remove_unused_data();
    CCScene *help_scene=GameManager::sharedGameManager()->get_scene("MenuLayer.ccbi", "MenuLayer", MenuLayerLoader::loader(), CCScene::create(),false,false);
    CCDirector::sharedDirector()->replaceScene(CCTransitionTurnOffTiles::create(0.2,help_scene));
}

void LevelSelectionLayer::menuItemClicked(cocos2d::CCObject *sender,int level)
{
    isConnectToInternet = ObjCCalls::tryIsInternetConnection();
    
    CCMenuItemImage *menuItemSpr = (CCMenuItemImage*)sender;
    int menuTag;
    if(level>0 && menuItemSpr==NULL)
        menuTag=level;
    else
        menuTag = menuItemSpr->getTag();
    
    int localcurrentStageToComplete = currentStageToComplete;
    isInAppPurchased=false;
    if(localcurrentStageToComplete==2){
        menuTag = menuTag+8;
    }
    if(localcurrentStageToComplete==3){
        menuTag = menuTag+16;
    }
    if(localcurrentStageToComplete==4){
        menuTag = menuTag+24;
    }
    if(localcurrentStageToComplete==5){
        menuTag = menuTag+32;
    }
    if(localcurrentStageToComplete==6){
        menuTag = menuTag+40;
    }
    if(localcurrentStageToComplete==7){
        menuTag = menuTag+48;
    }
    int lcocalLevelCleared =getIsLevelCleared(menuTag);
    if(lcocalLevelCleared==2 || lcocalLevelCleared==3){
        goToLevel(menuTag,localcurrentStageToComplete);
    }
    else{
        if(isConnectToInternet ==false){
            ObjCCalls::openToastAlert();
        }else{
            ObjCCalls::openAlert(isAnyLevelCleared,wondersNameLbl);
        }
    }
}



void LevelSelectionLayer::goToLevel(int levelClicked, int bgActivityIndiactor)
{
    swipe->setCancelsTouchesInView(false);
    int locallevelClicked = levelClicked;
    int localbgActivityIndiactor= bgActivityIndiactor;
    CCUserDefault::sharedUserDefault()->setIntegerForKey("BREAKLEVEL",levelClicked);
    CCUserDefault::sharedUserDefault()->flush();
    
    GameManager::sharedGameManager()->remove_unused_data();
    if(localbgActivityIndiactor==2 || localbgActivityIndiactor==3 ||localbgActivityIndiactor==4||localbgActivityIndiactor==6)
        ObjCCalls::showWhiteActivityIndictor();
    
    else
        ObjCCalls::showActivityIndictor();
    
    GameManager::sharedGameManager()->gotoScene(locallevelClicked);
}

void LevelSelectionLayer::update(float dt) {
}

void LevelSelectionLayer::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
    CCTouch *myTouch = (CCTouch*) pTouches->anyObject();
    CCPoint location = myTouch->getLocationInView();
    location = CCDirector::sharedDirector()->convertToGL(location);
    if(GameManager::sharedGameManager()->isNodeAtPoint(navigationBackLayer, location)){
        onBackClicked(NULL);
    }
    else if(GameManager::sharedGameManager()->isNodeAtPoint(navigationHomeLayer, location)){
        onHomeClicked(NULL);
    }
    else if(GameManager::sharedGameManager()->isNodeAtPoint(levelLayer1, location)){
        menuItemClicked(NULL, 1);
    }
    else if(GameManager::sharedGameManager()->isNodeAtPoint(levelLayer2, location)){
        menuItemClicked(NULL, 2);
    }
    else if(GameManager::sharedGameManager()->isNodeAtPoint(levelLayer3, location)){
        menuItemClicked(NULL, 3);
    }
    else if(GameManager::sharedGameManager()->isNodeAtPoint(levelLayer4, location)){
        menuItemClicked(NULL, 4);
    }
    else if(GameManager::sharedGameManager()->isNodeAtPoint(levelLayer5, location)){
        menuItemClicked(NULL, 5);
    }
    else if(GameManager::sharedGameManager()->isNodeAtPoint(levelLayer6, location)){
        menuItemClicked(NULL, 6);
    }
    else if(GameManager::sharedGameManager()->isNodeAtPoint(levelLayer7, location)){
        menuItemClicked(NULL, 7);
    }
    else if(GameManager::sharedGameManager()->isNodeAtPoint(levelLayer8, location)){
        menuItemClicked(NULL, 8);
    }
    
}

void LevelSelectionLayer::ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent){
    CCTouch *myTouch = (CCTouch*) pTouches->anyObject();
    CCPoint location = myTouch->getLocationInView();
    
    location = CCDirector::sharedDirector()->convertToGL(location);
}

void LevelSelectionLayer::ccTouchesEnded(cocos2d::CCSet *pTouches, cocos2d::    CCEvent *pEvent){
    CCTouch *myTouch = (CCTouch*) pTouches->anyObject();
    CCPoint location = myTouch->getLocationInView();
    location = CCDirector::sharedDirector()->convertToGL(location);
}

void LevelSelectionLayer::ccTouchesCancelled(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent){
    CCTouch *myTouch = (CCTouch*) pTouches->anyObject();
    CCPoint location = myTouch->getLocationInView();
    location = CCDirector::sharedDirector()->convertToGL(location);
    
}

int LevelSelectionLayer::getIsLevelCleared(int currentLevelNumber)
{
    CCDictionary *dict=(CCDictionary*)getIsLevelClearArr->objectAtIndex(currentLevelNumber);
    int status_id=atoi(dict->valueForKey("isLevelCleared")->getCString());
    return status_id;
}

int LevelSelectionLayer::getStarCountAccordingToLevel(int currentLevelNumber)
{
    CCDictionary *dict=(CCDictionary*)getIsLevelClearArr->objectAtIndex(currentLevelNumber);
    int status_id=atoi(dict->valueForKey("starCount")->getCString());
    return status_id;
}

int LevelSelectionLayer::getisInAppPurchased(int currentLevelNumber)
{
    CCDictionary *dict=(CCDictionary*)getIsLevelClearArr->objectAtIndex(currentLevelNumber);
    int status_id=atoi(dict->valueForKey("isInAppPurchased")->getCString());
    return status_id;
}



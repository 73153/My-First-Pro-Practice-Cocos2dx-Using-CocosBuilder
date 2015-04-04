

#include "../Layers/MainScene.h"
#include "../GameManager/GameManager.h"
#include "../Layers/MenuLayer.h"
#include "../Layers/MenuLayerLoader.h"
using namespace cocos2d;
using namespace cocos2d::extension;


MainScene::MainScene()
//menuHomeLayer(NULL),topFiveLabel(NULL),leaderBoardLabel(NULL),trophySpr(NULL),sideBarArcadeSpr(NULL),sideBarChallengeSpr(NULL),arcadeLabel(NULL),challengeLabel(NULL),backLayer(NULL),sideBarArcadeMenuItemSpr(NULL),sideBarChallengeMenuItemSpr(NULL),noScoreLabel(NULL),highestScoreLabelNotUsed(NULL),highestScoreLabel(NULL)
//    resolutionInt=0;
{
}

MainScene::~MainScene() {
    
}


bool MainScene::init() {
    
    return true;
}

//CCArray*  MainScene::get_Challenge_userlist()
//{
//    CCArray *arr_users;
//    std::string writablePath_temp = CCFileUtils::sharedFileUtils()->getWritablePath();
//    std::string fullPath = writablePath_temp + "ChallengeScoreList.plist";
//    if(CCFileUtils::sharedFileUtils()->isFileExist(fullPath))
//    {
//        CCDictionary *dict=CCDictionary::createWithContentsOfFile(fullPath.c_str());
//        dict->retain();
//        arr_users=(CCArray*)dict->objectForKey("array");
//    }
//    else
//    {
//        arr_users=CCArray::createWithContentsOfFileThreadSafe("ChallengeScoreList.plist");
//        CCDictionary *root = CCDictionary::create();
//        root->setObject(arr_users, "array");
//        if(root->writeToFile(fullPath.c_str()))
//        {
//            //CCLog("see the plist file at %s", fullPath.c_str());
//        }
//        else
//        {
//            //CCLog("write plist file failed");
//        }
//        //CCLog("external file path = %s", fullPath.c_str());
//    }
//    return arr_users;
//}
//void MainScene::save_Challenge_user(CCDictionary *user)
//{
//    GameManager::sharedGameManager()->getchallenge_existing_usersArr()->addObject(user);
//    
//    CCArray *localUsersList =GameManager::sharedGameManager()->getchallenge_existing_usersArr();
//    CCDictionary *root = CCDictionary::create();
//    int usersCount = localUsersList->count();
//    for (int i=0; i<=usersCount-5; i++) {
//        localUsersList->removeObjectAtIndex(i);
//    }
//    root->setObject(GameManager::sharedGameManager()->getchallenge_existing_usersArr(), "array");
//    std::string writablePath_temp = CCFileUtils::sharedFileUtils()->getWritablePath();
//    std::string fullPath = writablePath_temp + "ChallengeScoreList.plist";
//    CCLOG("ScoreList fullPath %s",fullPath.c_str());
//    if(root->writeToFile(fullPath.c_str()))
//    {
//        
//    }
//}
//
//CCArray*  MainScene::get_Arcade_userlist()
//{
//    CCArray *arr_users;
//    std::string writablePath_temp = CCFileUtils::sharedFileUtils()->getWritablePath();
//    std::string fullPath = writablePath_temp + "ArcadeScoreList.plist";
//    if(CCFileUtils::sharedFileUtils()->isFileExist(fullPath))
//    {
//        CCDictionary *dict=CCDictionary::createWithContentsOfFile(fullPath.c_str());
//        dict->retain();
//        arr_users=(CCArray*)dict->objectForKey("array");
//    }
//    else
//    {
//        arr_users=CCArray::createWithContentsOfFileThreadSafe("ArcadeScoreList.plist");
//        CCDictionary *root = CCDictionary::create();
//        root->setObject(arr_users, "array");
//        if(root->writeToFile(fullPath.c_str()))
//        {
//            //CCLog("see the plist file at %s", fullPath.c_str());
//        }
//        else
//        {
//            //CCLog("write plist file failed");
//        }
//        //CCLog("external file path = %s", fullPath.c_str());
//    }
//    return arr_users;
//}
//void MainScene::save_Arcade_user(CCDictionary *user)
//{
//    GameManager::sharedGameManager()->getarcade_existing_usersArr()->addObject(user);
//    
//    CCArray *localUsersList =GameManager::sharedGameManager()->getarcade_existing_usersArr();
//    CCDictionary *root = CCDictionary::create();
//    int usersCount = localUsersList->count();
//    for (int i=0; i<=usersCount-5; i++) {
//        localUsersList->removeObjectAtIndex(i);
//    }
//    root->setObject(GameManager::sharedGameManager()->getarcade_existing_usersArr(), "array");
//    std::string writablePath_temp = CCFileUtils::sharedFileUtils()->getWritablePath();
//    std::string fullPath = writablePath_temp + "ArcadeScoreList.plist";
//    CCLOG("Arcade fullPath %s",fullPath.c_str());
//    if(root->writeToFile(fullPath.c_str()))
//    {
//        
//    }
//}
//
//
//bool static sortIndexDescending(int a,int b)
//{
//    int k=a;
//    int l= b;
//    return k<l;
//}


//void MainScene::setDelegate(MainSceneDelegate* pDelegate)
//{
//	settingDelegte = pDelegate;
//}

#pragma  mark   COCOSBUILDER INITITIALIZATION
void MainScene::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    
    this->setTouchEnabled(true);
//    CCArray *localChallengeUsersList = CCArray::create();
//    localChallengeUsersList->retain();
//    localChallengeUsersList =get_Challenge_userlist();
//    int usersCount = localChallengeUsersList->count();
//    CCLOG("usersCount %d",usersCount);
//    
//    for (int i=usersCount; i>=6; i--) {
//        CCLOG("i %d",i);
//        localChallengeUsersList->removeLastObject();
//    }
//    GameManager::sharedGameManager()->saveChallengeScoreHighestSortedUsersList(localChallengeUsersList);
//    
//    CCArray *localArcadeUsersList = CCArray::create();
//    localArcadeUsersList->retain();
//    localArcadeUsersList =get_Arcade_userlist();
//    int arcadeUsersCount = localArcadeUsersList->count();
//    CCLOG("usersCount %d",arcadeUsersCount);
//    
//    for (int i=arcadeUsersCount; i>=6; i--) {
//        CCLOG("i %d",i);
//        localArcadeUsersList->removeLastObject();
//    }
//    GameManager::sharedGameManager()->saveArcadeScoreHighestSortedUsersList(localArcadeUsersList);
//    
//    sideBarChallengeMenuItemSpr->setColor(ccc3(121, 121,121 ));
//    sideBarArcadeMenuItemSpr->setColor(ccc3(200, 200, 200));
//    
//    CCArray *localchallenge_existing_usersArr = CCArray::create();
//    localchallenge_existing_usersArr->retain();
//    localchallenge_existing_usersArr=this->get_Challenge_userlist();
//    
//    localchallenge_existing_usersArr = GameManager::sharedGameManager()->sortArray(localchallenge_existing_usersArr);
//    GameManager::sharedGameManager()->setchallenge_existing_usersArr(localchallenge_existing_usersArr);
//    
//    
//    CCArray *local_Arcade_existing_usersArr = CCArray::create();
//    local_Arcade_existing_usersArr->retain();
//    local_Arcade_existing_usersArr=this->get_Arcade_userlist();

//    resolutionInt=GameManager::sharedGameManager()->get_devise_resolution();
//    
//    switch (resolutionInt)
//    {
//        case 1:{
//            leaderBoardLabel->setFontSize(85);
//            topFiveLabel->setFontSize(85);
//        }
//            break;
//        case 2:
//        {
//            if (CCDirector::sharedDirector()->getWinSize().height==1136){
//                leaderBoardLabel->setFontSize(40);
//                topFiveLabel->setFontSize(40);
//                arcadeLabel->setFontSize(35);
//                challengeLabel->setFontSize(35);
//                highestScoreLabelNotUsed->setFontSize(50);
//                highestScoreLabel->setFontSize(60);
//                noScoreLabel->setFontSize(50);
//                
//            }
//            else{
//                leaderBoardLabel->setFontSize(40);
//                topFiveLabel->setFontSize(40);
//                arcadeLabel->setFontSize(35);
//                challengeLabel->setFontSize(35);
//                highestScoreLabelNotUsed->setFontSize(50);
//                highestScoreLabel->setFontSize(60);
//                noScoreLabel->setFontSize(50);
//                
//            }
//        }
//            break;
//        case 3:{
//            leaderBoardLabel->setFontSize(40);
//            topFiveLabel->setFontSize(40);
//            arcadeLabel->setFontSize(35);
//            challengeLabel->setFontSize(35);
//            highestScoreLabelNotUsed->setFontSize(50);
//            highestScoreLabel->setFontSize(60);
//            noScoreLabel->setFontSize(50);
//            
//            
//        }
//            break;
//        case 4:{
//            
//            leaderBoardLabel->setFontSize(40);
//            topFiveLabel->setFontSize(40);
//            arcadeLabel->setFontSize(35);
//            challengeLabel->setFontSize(35);
//            highestScoreLabelNotUsed->setFontSize(50);
//            highestScoreLabel->setFontSize(60);
//            noScoreLabel->setFontSize(50);
//        }
//            
//            break;
//        case 5:
//        {
//            
//            leaderBoardLabel->setFontSize(40);
//            topFiveLabel->setFontSize(40);
//            arcadeLabel->setFontSize(35);
//            challengeLabel->setFontSize(35);
//            highestScoreLabelNotUsed->setFontSize(50);
//            highestScoreLabel->setFontSize(60);
//            noScoreLabel->setFontSize(50);
//            
//            break;
//        case 6:
//            {
//                leaderBoardLabel->setFontSize(85);
//                topFiveLabel->setFontSize(85);
//            }
//            break;
//            
//        default:
//            break;
//        }
//            winSize=CCDirector::sharedDirector()->getWinSize();
//            
//            //    NightSensitivityControlSlider->setVisible(true);
//    }
//    //
//    //    local_Arcade_existing_usersArr = GameManager::sharedGameManager()->sortArray(local_Arcade_existing_usersArr);
//    //    GameManager::sharedGameManager()->setarcade_existing_usersArr(local_Arcade_existing_usersArr);
//    
//    updateChallngeModeScore();

   
}

//void MainScene::updateChallngeModeScore()
//{
//    sideBarArcadeMenuItemSpr->setColor(ccc3(200, 200, 200));
//    sideBarChallengeMenuItemSpr->setColor(ccc3(121, 121, 121));
//    
//    int highestScore =  CCUserDefault::sharedUserDefault()->getIntegerForKey("BREAKPOINTS");
//    
//    if(highestScore<=0){
//        noScoreLabel->setVisible(true);
//        highestScoreLabelNotUsed->setVisible(false);
//        highestScoreLabel->setVisible(false);
//    }
//    else{
//        noScoreLabel->setVisible(false);
//        highestScoreLabelNotUsed->setVisible(true);
//        highestScoreLabel->setVisible(true);
//    }
//    highestScoreLabel->setString(CCString::createWithFormat("%d",highestScore)->getCString());
//}
//
//void MainScene::updateArcadeModeScore()
//{
//    sideBarArcadeMenuItemSpr->setColor(ccc3(121, 121, 121));
//    sideBarChallengeMenuItemSpr->setColor(ccc3(200, 200, 200));
//
//    int highestScore =  CCUserDefault::sharedUserDefault()->getIntegerForKey("ARCADEPOINTS");
//    
//    if(highestScore<=0){
//        noScoreLabel->setVisible(true);
//        highestScoreLabelNotUsed->setVisible(false);
//        highestScoreLabel->setVisible(false);
//    }
//    else{
//        noScoreLabel->setVisible(false);
//        highestScoreLabelNotUsed->setVisible(true);
//        highestScoreLabel->setVisible(true);
//    }
//    highestScoreLabel->setString(CCString::createWithFormat("%d",highestScore)->getCString());
//}

SEL_CallFuncN MainScene::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
//    CCB_SELECTORRESOLVER_CALLFUNC_GLUE(this, "updateChallngeModeScore", MainScene::updateChallngeModeScore);
//    CCB_SELECTORRESOLVER_CALLFUNC_GLUE(this, "updateArcadeModeScore", MainScene::updateArcadeModeScore);
    
    return NULL;
}

SEL_MenuHandler MainScene::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
//    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onHomeClicked", MainScene::onHomeClicked);
//    
//    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onsideBarChallengeMenuItemClicked", MainScene::onsideBarChallengeMenuItemClicked);
//    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onsideBarArcadeMenuItemCicked", MainScene::onsideBarArcadeMenuItemCicked);
    //    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onBackGroundSoundClicked", MainScene::onBackGroundSoundClicked);
    
    return NULL;
}


SEL_CCControlHandler MainScene::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}

bool MainScene::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    bool bRet = false;
    return bRet;
}
bool MainScene::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
//    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "menuHomeLayer",CCLayerColor *, this->menuHomeLayer);
//    
//    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "topFiveLabel",CCLabelTTF *, this->topFiveLabel);
//    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "leaderBoardLabel",CCLabelTTF *, this->leaderBoardLabel);
//    
//    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "arcadeLabel",CCLabelTTF *, this->arcadeLabel);
//    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "challengeLabel",CCLabelTTF *, this->challengeLabel);
//    
//    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "highestScoreLabel",CCLabelTTF *, this->highestScoreLabel);
//    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "highestScoreLabelNotUsed",CCLabelTTF *, this->highestScoreLabelNotUsed);
//    
//    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "trophySpr",CCSprite *, this->trophySpr);
//    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "sideBarArcadeSpr",CCSprite *, this->sideBarArcadeSpr);
//    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "sideBarChallengeSpr",CCSprite *, this->sideBarChallengeSpr);
//    
//    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "sideBarArcadeMenuItemSpr", CCMenuItemImage*, sideBarArcadeMenuItemSpr);
//    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "sideBarChallengeMenuItemSpr", CCMenuItemImage*, sideBarChallengeMenuItemSpr);
//    
//    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "noScoreLabel", CCLabelTTF*, noScoreLabel);
//    
//    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "backLayer", CCLayerColor*, backLayer);

    
    
    return false;
}
//
//void MainScene::onHomeClicked(cocos2d::CCObject *pSender)
//{
//    GameManager::sharedGameManager()->remove_unused_data();
//    CCScene *highScore_scene=GameManager::sharedGameManager()->get_scene("MenuLayer.ccbi", "MenuLayer",MenuLayerLoader::loader(), CCScene::create(),false,false);
//    CCDirector::sharedDirector()->replaceScene(CCTransitionTurnOffTiles::create(0.1,highScore_scene));
//}
//void MainScene::on_user_clicked(cocos2d::CCObject * pSender)
//{
//    if (is_info_showing==true)return;
//    CCTableViewCell *cell = (CCTableViewCell*)(((CCMenuItemSprite*)pSender)->getParent()->getParent());
//    //CCLog("%d",cell->getIdx());
//    GameManager::sharedGameManager()->getchallenge_existing_usersArr()->removeObjectAtIndex(cell->getIdx());
//    CCDictionary *root = CCDictionary::create();
//    root->setObject(GameManager::sharedGameManager()->getchallenge_existing_usersArr(), "array");
//    std::string writablePath_temp = CCFileUtils::sharedFileUtils()->getWritablePath();
//    std::string fullPath = writablePath_temp + "ChallengeScoreList.plist";
//    if(root->writeToFile(fullPath.c_str()))
//    {
//
//    }
//    //    tableView->reloadData();
//}


//void MainScene::onsideBarArcadeMenuItemCicked(cocos2d::CCObject *sender)
//{
////    mAnimationManager = dynamic_cast<CCBAnimationManager *>( this->getUserObject());
////    if (mAnimationManager)
////    {
////        mAnimationManager->runAnimationsForSequenceNamed("arcadeModeScore");
////    }
//    sideBarArcadeMenuItemSpr->setColor(ccc3(121, 121, 121));
//    sideBarChallengeMenuItemSpr->setColor(ccc3(200, 200, 200));
//    
//    int highestScore =  CCUserDefault::sharedUserDefault()->getIntegerForKey("ARCADEPOINTS");
//
//    if(highestScore<=0){
//        noScoreLabel->setVisible(true);
//        highestScoreLabelNotUsed->setVisible(false);
//        highestScoreLabel->setVisible(false);
//
//    }
//    else{
//        noScoreLabel->setVisible(false);
//        highestScoreLabelNotUsed->setVisible(true);
//        highestScoreLabel->setVisible(true);
//
//    }
//    highestScoreLabel->setString(CCString::createWithFormat("%d",highestScore)->getCString());
//    updateArcadeModeScore();
//}
//
//void MainScene::onsideBarChallengeMenuItemClicked(cocos2d::CCObject *sender)
//{
////    mAnimationManager = dynamic_cast<CCBAnimationManager *>( this->getUserObject());
////    if (mAnimationManager)
////    {
////        mAnimationManager->runAnimationsForSequenceNamed("challengeModeScore");
////    }
//    sideBarChallengeMenuItemSpr->setColor(ccc3(121, 121, 121));
//    sideBarArcadeMenuItemSpr->setColor(ccc3(200, 200, 200));
//    
//    int highestScore =  CCUserDefault::sharedUserDefault()->getIntegerForKey("BREAKPOINTS");
//    
//    if(highestScore<=0){
//        noScoreLabel->setVisible(true);
//        highestScoreLabelNotUsed->setVisible(false);
//        highestScoreLabel->setVisible(false);
//
//    }
//    else{
//        noScoreLabel->setVisible(false);
//        highestScoreLabelNotUsed->setVisible(true);
//        highestScoreLabel->setVisible(true);
//
//    }
//    highestScoreLabel->setString(CCString::createWithFormat("%d",highestScore)->getCString());
//    updateChallngeModeScore();
//}
//
void MainScene::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent)
{
    CCTouch *myTouch = (CCTouch*) pTouches->anyObject();
    CCPoint location = myTouch->getLocationInView();
    location = CCDirector::sharedDirector()->convertToGL(location);
//    if(GameManager::sharedGameManager()->isNodeAtPoint(menuHomeLayer, location)){
//        onHomeClicked(NULL);
//        return;
//    }
}





#include "../GameManager/GameManager.h"


using namespace std;
using namespace cocos2d;

//All static variables need to be defined in the .cpp file
//I've added this following line to fix the problem
GameManager* GameManager::m_mySingleton = NULL;
GameManager::GameManager():current_scene(0),current_layer(NULL),isSettingAndAnimationLayerAdded(false),starStoreElements(NULL),highestPlayedLevel(2),challenge_existing_usersArr(NULL),arcade_existing_usersArr(NULL),isAuthenticatedUser(false)
{
    
}
GameManager* GameManager::sharedGameManager()
{
    //If the singleton has no instance yet, create one
    if(NULL == m_mySingleton)
    {
        //Create an instance to the singleton
        m_mySingleton = new GameManager();
    }
    //Return the singleton object
    return m_mySingleton;
}
void GameManager::initialize()
{
    starStoreElements = CCArray::create();
    starStoreElements->retain();
    
    this->points=CCUserDefault::sharedUserDefault()->getIntegerForKey("BREAKPOINTS");
    this->coinCountNumber = CCUserDefault::sharedUserDefault()->getIntegerForKey("COINCOUNT");
    if(coinCountNumber>99999)
        coinCountNumber=0;
    this->level=CCUserDefault::sharedUserDefault()->getIntegerForKey("BREAKLEVEL");
    this->highestPlayedLevel = CCUserDefault::sharedUserDefault()->getIntegerForKey("LASTPLAYEDLEVEL");
    this->numberOfUsers = CCUserDefault::sharedUserDefault()->getIntegerForKey("NUMBEROFPLAYER");
    if (level == 0 ){
        if(level==0){
            level=1;
            coinCountNumber=0;
        }
        saveCoinsCount(0);
        coinCountNumber=0;
        level=1;
        highestPlayedLevel=1;
        //        level=55;
        //        highestPlayedLevel=56;
        numberOfUsers=0;
        CCUserDefault::sharedUserDefault()->setIntegerForKey("ARCADEPOINTS",0);
        CCUserDefault::sharedUserDefault()->setIntegerForKey("BREAKPOINTS",0);
        CCUserDefault::sharedUserDefault()->setIntegerForKey("LASTPLAYEDLEVEL",highestPlayedLevel);
        CCUserDefault::sharedUserDefault()->setIntegerForKey("COINCOUNT", coinCountNumber);
        CCUserDefault::sharedUserDefault()->setIntegerForKey("BREAKLEVEL", level);
        CCUserDefault::sharedUserDefault()->setIntegerForKey("NUMBEROFPLAYER", numberOfUsers);
        CCUserDefault::sharedUserDefault()->setIntegerForKey("FORGROUNDVOLUME",1);
        CCUserDefault::sharedUserDefault()->flush();
    }
    CCLOG("level %d",level);
    CCLOG("highestPlayedLevel %d",highestPlayedLevel);
    
    this->getStarsCount_list();
}

bool static sortIndexAsc(CCObject *a, CCObject *b)
{
    CCDictionary *firstObject = static_cast< CCDictionary *>(a);
    CCDictionary *secondObject = static_cast< CCDictionary *>(b);
    int k=firstObject->valueForKey("user_score")->intValue();
    int l=secondObject->valueForKey("user_score")->intValue();
    return k>l;
}
CCArray *GameManager::sortArray(CCArray *array)
{
    std::sort(array->data->arr,
              array->data->arr + array->data->num,
              sortIndexAsc);
    return array;
}

CCScene* GameManager::get_scene_at(int nIndex)
{
    this->setcurrent_scene(nIndex);
    switch(1)
    {
        case 1:{
            SoundManager::sharedSoundManager()->loadSondEffect(1);
            current_scene=nIndex;
            CCLog("index:%d",nIndex);
            //            CCSize winSize = CCDirector::sharedDirector()->getWinSize();
            //            TargetPlatform platform = CCApplication::sharedApplication()->getTargetPlatform();
            
            return  get_scene("Level1.ccbi","GameLayer",GameLayerLoader::loader(), CCScene::create(),false,false);
        }
        case 2:{
            current_scene=nIndex;
            return  get_scene("Level46.ccbi","GameLayer",GameLayerLoader::loader(), CCScene::create(),false,false);
            CCLog("index:%d",nIndex);
            
        }
        case 3:{
            current_scene=nIndex;
            return  get_scene("Level3.ccbi","GameLayer",GameLayerLoader::loader(), CCScene::create(),false,false);
            CCLog("index:%d",nIndex);
            
        }
        case 4:{
            current_scene=nIndex;
            return  get_scene("Level4.ccbi","GameLayer",GameLayerLoader::loader(), CCScene::create(),false,false);
            CCLog("index:%d",nIndex);
        }
        case 5:{
            current_scene=nIndex;
            return  get_scene("Level5.ccbi","GameLayer",GameLayerLoader::loader(), CCScene::create(),false,false);
            CCLog("index:%d",nIndex);
        }
        case 6: {
            current_scene=nIndex;
            return  get_scene("Level6.ccbi","GameLayer",GameLayerLoader::loader(), CCScene::create(),false,false);
            CCLog("index:%d",nIndex);
        }
        case 7:{
            current_scene=nIndex;
            return  get_scene("Level7.ccbi","GameLayer",GameLayerLoader::loader(), CCScene::create(),false,false);
            CCLog("index:%d",nIndex);
        }
            
        default:{
            
        }
    }
    return NULL;
}

void GameManager::saveChallengeScoreHighestSortedUsersList(CCArray *sortedUsersArray)
{
    CCDictionary *root = CCDictionary::create();
    root->setObject(sortedUsersArray, "array");
    std::string writablePath_temp = CCFileUtils::sharedFileUtils()->getWritablePath();
    std::string fullPath = writablePath_temp + "ChallengeScoreList.plist";
    CCLOG("ScoreList fullPath %s",fullPath.c_str());
    if(root->writeToFile(fullPath.c_str()))
    {
    }
}

void GameManager::saveArcadeScoreHighestSortedUsersList(CCArray *sortedUsersArray)
{
    CCDictionary *root = CCDictionary::create();
    root->setObject(sortedUsersArray, "array");
    std::string writablePath_temp = CCFileUtils::sharedFileUtils()->getWritablePath();
    std::string fullPath = writablePath_temp + "ArcadeScoreList.plist";
    CCLOG("ArcadeScoreList fullPath %s",fullPath.c_str());
    if(root->writeToFile(fullPath.c_str()))
    {
    }
}

void GameManager::read_data()
{
    challenge_existing_usersArr = CCArray::create();
    challenge_existing_usersArr->retain();
    
    arcade_existing_usersArr = CCArray::create();
    arcade_existing_usersArr->retain();
    //    std::string writablePath_temp = CCFileUtils::sharedFileUtils()->getWritablePath();
    //    std::string fullPath = writablePath_temp + "textPosition.plist";
    //    if (CCFileUtils::sharedFileUtils()->isFileExist(fullPath))
    //    {
    //        CCDictionary *dict=CCDictionary::createWithContentsOfFile(fullPath.c_str());
    //        dict->retain();
    //        // starStoreElements=CCArray::create();
    //    }
    //    else
    //    {
    //        CCDictionary *root = CCDictionary::create();
    //        if(root->writeToFile(fullPath.c_str()))
    //        {
    //            CCLog("see the plist file at %s", fullPath.c_str());
    //        }
    //        else
    //        {
    //            CCLog("write plist file failed");
    //        }
    //        CCLog("external file path = %s", fullPath.c_str());
    //    }
}

#pragma mark -
#pragma mark Scene manager
#pragma mark -
CCScene* GameManager::get_scene(const char *pCCBFilename,const char *pCCNodename,CCNodeLoader *pCCNodeLoader,CCObject *objowner,bool hasfooter,bool hasheader)
{
    CCNode *layer = NULL;
    CCLOG("pCCBFilename %s",pCCBFilename);
    map<string, CCNodeLoader*> loader_map;
    loader_map.insert(make_pair(pCCNodename, pCCNodeLoader));
    CCString *str_clsname = CCString::createWithFormat("%s",pCCNodename);
    CCString *str2 = CCString::createWithFormat("%s","GameLayer");
    CCString *str3 = CCString::createWithFormat("%s","GameLayerArcadeMode");
    
    
    if(str_clsname->isEqual(str2)){
        loader_map.insert(make_pair("AnimationLayer", AnimationLayerLoader::loader()));
        loader_map.insert(make_pair("SettingLayer", SettingLayerLoader::loader()));
    }
    else if(str_clsname->isEqual(str3)){
        loader_map.insert(make_pair("AnimationLayerArcadeMode",AnimationLayerLoaderArcadeMode::loader()));
        loader_map.insert(make_pair("SettingLayer", SettingLayerLoader::loader()));
    }
    layer = loadCCBFile(pCCBFilename, loader_map);
    isSettingAndAnimationLayerAdded=false;
    
    current_layer=(CCNode*)layer;
    /* Read a ccbi file. */
    CCScene * scene = CCScene::create();
    if(layer != NULL)
    {
          scene->addChild(layer);
      
        if(str_clsname->isEqual(str2)){
            animationLayerObj=(AnimationLayer*)layer->getChildByTag(12345);
            //            settingLayerObj=(SettingLayer*)layer->getChildByTag(6789);
            isSettingAndAnimationLayerAdded=true;
        }
        else if (str_clsname->isEqual(str3))
        {
            if(str_clsname->isEqual(str2)){
                animationLayerArcadeModeObj=(AnimationLayerArcadeMode*)layer->getChildByTag(12345);
                //            settingLayerObj=(SettingLayer*)layer->getChildByTag(6789);
                isSettingAndAnimationLayerAdded=true;
            }
        }
    }
    return scene;
}
bool GameManager::gotoNextScene()
{
    int kscene=this->getcurrent_scene().getValue();
    remove_unused_data();
    
    CCScene *splash_scene=this->get_scene_at(kscene);
    //push transition...
    //    if (kscene==11||kscene==18||kscene==19)
    //        CCDirector::sharedDirector()->replaceScene(CCTransitionSlideInR::create(0.2f, splash_scene));
    //    else
    //        CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(0.2f, splash_scene, false));
    return true;
}
bool GameManager::gotoPreviousScene()
{
    int kscene=this->getcurrent_scene().getValue();
    remove_unused_data();
    
    CCScene *splash_scene=this->get_scene_at(--kscene);
    
    //    if (kscene==10||kscene==18||kscene==17)
    //        CCDirector::sharedDirector()->replaceScene(CCTransitionSlideInL::create(0.2f, splash_scene));
    //    else
    //    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(0.2f, splash_scene, true));
    //
    
    return false;
}

void GameManager::save_ChallengeCurrentUserScore(CCDictionary *user)
{
    //    if(challenge_existing_usersArr->count() > 0)
    //    challenge_existing_usersArr->replaceObjectAtIndex(0,user);
    CCDictionary *root = CCDictionary::create();
    root->setObject(challenge_existing_usersArr, "array");
    std::string writablePath_temp = CCFileUtils::sharedFileUtils()->getWritablePath();
    std::string fullPath = writablePath_temp + "ChallengeScoreList.plist";
    CCLOG("ScoreList fullPath %s",fullPath.c_str());
    if(root->writeToFile(fullPath.c_str()))
    {
    }
}



CCArray*  GameManager::get_Challenge_userslist()
{
    CCArray *arr_users;
    std::string writablePath_temp = CCFileUtils::sharedFileUtils()->getWritablePath();
    std::string fullPath = writablePath_temp + "ChallengeScoreList.plist";
    if(CCFileUtils::sharedFileUtils()->isFileExist(fullPath))
    {
        CCDictionary *dict=CCDictionary::createWithContentsOfFile(fullPath.c_str());
        dict->retain();
        arr_users=(CCArray*)dict->objectForKey("array");
    }
    else
    {
        arr_users=CCArray::createWithContentsOfFileThreadSafe("ChallengeScoreList.plist");
        CCDictionary *root = CCDictionary::create();
        root->setObject(arr_users, "array");
        if(root->writeToFile(fullPath.c_str()))
        {
            //CCLog("see the plist file at %s", fullPath.c_str());
        }
        else
        {
            //CCLog("write plist file failed");
        }
        CCLog("external file path = %s", fullPath.c_str());
    }
    return arr_users;
}
void GameManager::save_ArcadeCurrentUserScore(CCDictionary *user)
{
    CCDictionary *root = CCDictionary::create();
    root->setObject(arcade_existing_usersArr, "array");
    std::string writablePath_temp = CCFileUtils::sharedFileUtils()->getWritablePath();
    std::string fullPath = writablePath_temp + "ArcadeScoreList.plist";
    CCLOG("ArcadeScoreList fullPath %s",fullPath.c_str());
    if(root->writeToFile(fullPath.c_str()))
    {
    }
}

CCArray*  GameManager::get_Arcade_userslist()
{
    CCArray *arr_users;
    std::string writablePath_temp = CCFileUtils::sharedFileUtils()->getWritablePath();
    std::string fullPath = writablePath_temp + "ArcadeScoreList.plist";
    if(CCFileUtils::sharedFileUtils()->isFileExist(fullPath))
    {
        CCDictionary *dict=CCDictionary::createWithContentsOfFile(fullPath.c_str());
        dict->retain();
        arr_users=(CCArray*)dict->objectForKey("array");
    }
    else
    {
        arr_users=CCArray::createWithContentsOfFileThreadSafe("ArcadeScoreList.plist");
        CCDictionary *root = CCDictionary::create();
        root->setObject(arr_users, "array");
        if(root->writeToFile(fullPath.c_str()))
        {
            //CCLog("see the plist file at %s", fullPath.c_str());
        }
        else
        {
            //CCLog("write plist file failed");
        }
        CCLog("external file path = %s", fullPath.c_str());
    }
    return arr_users;
}


bool GameManager::gotoScene(CCInteger index_scene)
{
    //    ObjCCalls::showActivityIndictor();
    
    int kscene=index_scene.getValue();
    CCLog("Go to scene %d",kscene);
    
    remove_unused_data();
    
    //    SoundManager::sharedSoundManager()->loadSondEffect(kscene);
    CCLog("Sound Loaded");
    CCScene *splash_scene=this->get_scene_at(kscene);
    CCLog("Get Scene");
    CCDirector::sharedDirector()->replaceScene(CCTransitionFlipX::create(0.2f, splash_scene));
    
    return true;
}

#pragma mark ********************STAR IMPLEMENTATION**********************
CCArray*  GameManager::getStarsCount_list()
{
    std::string writablePath_temp = CCFileUtils::sharedFileUtils()->getWritablePath();
    std::string fullPath = writablePath_temp + "text.plist";
    if (CCFileUtils::sharedFileUtils()->isFileExist(fullPath))
    {
        CCDictionary *dict=CCDictionary::createWithContentsOfFile(fullPath.c_str());
        dict->retain();
        CCLOG("%d",dict->allKeys()->count());
        starStoreElements=(CCArray*)dict->objectForKey("array");
        CCLOG("%d",starStoreElements->count());
    }
    else
    {
        starStoreElements=CCArray::createWithContentsOfFileThreadSafe("Published-iOS/StarsCount.plist");
        CCDictionary *root = CCDictionary::create();
        root->setObject(starStoreElements, "array");
        if(root->writeToFile(fullPath.c_str()))
        {
            CCLog("see the plist file at %s", fullPath.c_str());
        }
        else
        {
            CCLog("write plist file failed");
        }
        
        CCLog("external file path = %s", fullPath.c_str());
    }
    CCLog("external file path = %s", fullPath.c_str());
    return starStoreElements;
}

int GameManager::save_LastPlayedLavel(int curretLevelValue,int starCount,int isLevelCleared)
{
    int localcurretLevelValue = curretLevelValue;
    int localStarCount = starCount;
    int localisLevelCleared = isLevelCleared;
    if(localisLevelCleared==3)
    {
        CCLOG("highestPlayedLevel %d",highestPlayedLevel);
        if(curretLevelValue>=highestPlayedLevel){
            CCLOG("lastLevel %d",localcurretLevelValue);
            CCUserDefault::sharedUserDefault()->setIntegerForKey("LASTPLAYEDLEVEL",localcurretLevelValue);
            CCUserDefault::sharedUserDefault()->flush();
        }
        
        if(localStarCount>0){
            localcurretLevelValue = curretLevelValue-1;
            CCDictionary *element=(CCDictionary*)starStoreElements->objectAtIndex(localcurretLevelValue);
            element->setObject(CCString::createWithFormat("%d",localStarCount), "starCount");
            CCLog("localStarCount %d",localStarCount);
            CCLog("localcurretLevelValue %d",localcurretLevelValue);
            starStoreElements->replaceObjectAtIndex(localcurretLevelValue, element);
            
            element->setObject(CCString::createWithFormat("%d",localisLevelCleared), "isLevelCleared");
            starStoreElements->replaceObjectAtIndex(localcurretLevelValue, element);
        }
    }
    
    localcurretLevelValue=curretLevelValue;
    CCLOG("localcurretLevelValue %d",localcurretLevelValue);
    
    CCDictionary *elementNew=(CCDictionary*)starStoreElements->objectAtIndex(localcurretLevelValue);
    elementNew->setObject(CCString::createWithFormat("%d",localcurretLevelValue), "currentLevel");
    elementNew->setObject(CCString::createWithFormat("%d",localisLevelCleared), "isLevelCleared");
    starStoreElements->replaceObjectAtIndex(localcurretLevelValue, elementNew);
    
    CCDictionary *root = CCDictionary::create();
    root->setObject(starStoreElements, "array");
    std::string writablePath_temp = CCFileUtils::sharedFileUtils()->getWritablePath();
    std::string fullPath = writablePath_temp + "text.plist";
    if(root->writeToFile(fullPath.c_str()))
        CCLog("see the plist file at %s", fullPath.c_str());
    else
        CCLog("write plist file failed");
    return curretLevelValue;
}

int GameManager::getcurrentLevel(int currentLevelNumber)
{
    CCDictionary *dict=(CCDictionary*)starStoreElements->objectAtIndex(currentLevelNumber);
    int status_id=atoi(dict->valueForKey("currentLevel")->getCString());
    return status_id;
}


int GameManager::getIsLevelCleared(int currentLevelNumber)
{
    CCDictionary *dict=(CCDictionary*)starStoreElements->objectAtIndex(currentLevelNumber);
    int status_id=atoi(dict->valueForKey("isLevelCleared")->getCString());
    return status_id;
}

int GameManager::getisInAppPurchased(int currentLevelNumber)
{
    CCDictionary *dict=(CCDictionary*)starStoreElements->objectAtIndex(currentLevelNumber);
    int status_id=atoi(dict->valueForKey("isInAppPurchased")->getCString());
    return status_id;
}

int GameManager::getStarCountAccordingToLevel(int currentLevelNumber)
{
    CCDictionary *dict=(CCDictionary*)starStoreElements->objectAtIndex(currentLevelNumber);
    int status_id=atoi(dict->valueForKey("starCount")->getCString());
    return status_id;
}

#pragma mark -
#pragma mark utilities methods
#pragma mark -
bool GameManager::isNodeAtPoint(cocos2d::CCNode* node, cocos2d::CCPoint& touchLocation)
{
    CCPoint nodePoint = node->convertToNodeSpace(touchLocation);
    CCRect rect = CCRectMake(0, 0, node->getContentSize().width, node->getContentSize().height);
    return rect.containsPoint(nodePoint);
}
int GameManager::get_devise_resolution()
{
    return resolution_type;
}
void GameManager::set_devise_resolution(int resolution)
{
    resolution_type=resolution;
}
CCArray* GameManager::shuffle_array(CCArray *pArray, unsigned int nLen)
{
    int i;
    for( i = nLen - 1; i >= 0; i-- )
    {
        unsigned int j = rand() % (i+1);
        CCObject *tempobj = pArray->objectAtIndex(i);
        pArray->exchangeObject(tempobj, pArray->objectAtIndex(j));
    }
    return pArray;
}
bool GameManager::isTouchOnArea(CCPoint touch ,CCPoint center,float width,float height)
{
    if (CCRectMake(center.x-width/2, center.y-height/2, width, height).containsPoint(touch))
    {
        return true;
    }
    return false;
}

bool GameManager::isTouchOnAreaFromGimp(CCPoint touch ,CCPoint center,float width,float height)
{
    CCSize screenSize = CCDirector::sharedDirector()->getWinSize();
    if(CCRectMake(center.x, screenSize.height - center.y - height, width, height).containsPoint(touch))
        return true;
    else
        return false;
    
}

void GameManager::setLastPlayedLevel(int lastLevel){
    
}

int GameManager::getLastPlayedLevel()
{
    return CCUserDefault::sharedUserDefault()->getIntegerForKey("LASTPLAYEDLEVEL");
}

void GameManager::removeDataOnClick()
{
    if(isSettingAndAnimationLayerAdded==true)
    {
        this->animationLayerObj->stopAllActions();
        this->animationLayerObj->unscheduleAllSelectors();
        animationLayerObj->removeAllChildrenWithCleanup(true);
        //        this->settingLayerObj->stopAllActions();
        //        this->settingLayerObj->unscheduleAllSelectors();
        //        settingLayerObj->removeAllChildrenWithCleanup(true);
    }
}

void GameManager::remove_unused_data()
{
    SoundManager::sharedSoundManager()->stopAllEffect();
    SoundManager::sharedSoundManager()->unLoadSoundEffect(1);
    //    SoundManager::sharedSoundManager()->stopNarrator();
    //    SoundManager::sharedSoundManager()->stopBackgroundSound();
    CCLayer *layer=(CCLayer*)this->current_layer;
    
    if(layer==NULL)
        return;
    
    layer->setTouchEnabled(false);
    layer->stopAllActions();
    layer->unscheduleAllSelectors();
    layer->removeAllChildrenWithCleanup(true);
    layer = NULL;
    CCTextureCache::sharedTextureCache()->dumpCachedTextureInfo();
    CCAnimationCache::purgeSharedAnimationCache();
    CCTextureCache::sharedTextureCache()->removeUnusedTextures();
    CCSpriteFrameCache::sharedSpriteFrameCache()->removeUnusedSpriteFrames();
    CCDirector::sharedDirector()->purgeCachedData();}

#pragma mark -
#pragma mark StoreElement
#pragma mark -
void GameManager::saveMutedFX(bool mute)
{
    this->mutedFX = mute;
    CCUserDefault::sharedUserDefault()->setBoolForKey("mutedFX", mute);
    CCUserDefault::sharedUserDefault()->flush();
}
void GameManager::saveMutedNarrator(bool mute)
{
    this->mutedNarrator = mute;
    CCUserDefault::sharedUserDefault()->setBoolForKey("mutedNarrator", mute);
    CCUserDefault::sharedUserDefault()->flush();
}
void GameManager::saveCoinsCount(int coinNumber)
{
    coinCountNumber+=coinNumber;
    if (coinCountNumber >= 99999){
        coinCountNumber = 99999;
    }
    CCUserDefault::sharedUserDefault()->setIntegerForKey("COINCOUNT",coinCountNumber);
    CCUserDefault::sharedUserDefault()->flush();
}
void GameManager::AddPoints(int morePoints)
{
    points += morePoints;
    if (points >= 99999)
    {
        points = 99999;
    }
    CCUserDefault::sharedUserDefault()->setIntegerForKey("BREAKPOINTS",points);
    CCUserDefault::sharedUserDefault()->flush();
}

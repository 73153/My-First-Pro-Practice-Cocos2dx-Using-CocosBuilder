#include "../AppDelegate/AppDelegate.h"

#include "cocos2d.h"
#include "../Layers/MenuLayer.h"
#include "SimpleAudioEngine.h"
#include "../AppDelegate/AppMacros.h"
#include "../Layers/MenuLayerLoader.h"
#include "../GameManager/GameManager.h"

float AppDelegate::SCREEN_WIDTH         = 640;
float AppDelegate::SCREEN_HEIGHT        = 960;
float AppDelegate::SCREEN_SCALE_FACTOR  = 1.0f;
USING_NS_CC;
using namespace CocosDenshion;

AppDelegate::AppDelegate()
{
    
}


AppDelegate::~AppDelegate()
{
    CocosDenshion::SimpleAudioEngine::end();
}

bool AppDelegate::applicationDidFinishLaunching()
{
    
    CCSize frameSize = CCDirector::sharedDirector()->getWinSize();
    CCLOG("Window Size %f and %f",frameSize.width,frameSize.height);
    // initialize director
    pDirector = CCDirector::sharedDirector();
    pEGLView = CCEGLView::sharedOpenGLView();
    pDirector->setOpenGLView(pEGLView);
    pDirector->setProjection(kCCDirectorProjection2D);
    CCTexture2D::setDefaultAlphaPixelFormat(kCCTexture2DPixelFormat_RGBA8888);
    GameManager::sharedGameManager()->initialize();
    GameManager::sharedGameManager()->read_data();
    
//    pDirector->setDisplayStats(true);
    // set FPS. the default value is 1.0/60 if you don't call this
    this->setPathForResources();
    pDirector->setAnimationInterval(1 / 60);
    
    CCScene *home_scene=GameManager::sharedGameManager()->get_scene("MenuLayer.ccbi", "MenuLayer", MenuLayerLoader::loader(), CCScene::create(),false,false);
    //CCScene *home_scene=GameManager::sharedGameManager()->get_scene_at(13);
    CCDirector::sharedDirector()->runWithScene(home_scene);
    
    return true;
}
void AppDelegate::setPathForResources()
{
    
    //IMPORTANT LINE!!!
    CCSize frameSize = CCDirector::sharedDirector()->getWinSize();
    // Set the design resolution
    float scale_factor;
    vector<std::string> searchPaths;
    vector<std::string> resDirOrders;
    TargetPlatform platform = CCApplication::sharedApplication()->getTargetPlatform();
    
    pDirector->setProjection(kCCDirectorProjection2D);
    pDirector->setDepthTest(true);
    searchPaths.push_back("Published-iOS");
    
    searchPaths.push_back("Sound");
    resDirOrders.push_back("Sound");
    
    searchPaths.push_back("ParticleUsed");
    resDirOrders.push_back("ParticleUsed");
    
    if(frameSize.height >=resources_ipadhd.size.height)
    {
        searchPaths.push_back("resources-ipadhd");
        resDirOrders.push_back("resources-ipadhd");
        
        searchPaths.push_back("GameLayer/resources-ipadhd");
        resDirOrders.push_back("GameLayer/resources-ipadhd");
        
        searchPaths.push_back("LeaderBoardLayer/resources-ipadhd");
        resDirOrders.push_back("LeaderBoardLayer/resources-ipadhd");
        
        searchPaths.push_back("MenuLayer/resources-ipadhd");
        resDirOrders.push_back("MenuLayer/resources-ipadhd");
        
        searchPaths.push_back("PauseLayer/resources-ipadhd");
        resDirOrders.push_back("PauseLayer/resources-ipadhd");
        
        searchPaths.push_back("MonumentSelectionLayer/resources-ipadhd");
        resDirOrders.push_back("MonumentSelectionLayer/resources-ipadhd");
        
        searchPaths.push_back("SettingLayer/resources-ipadhd");
        resDirOrders.push_back("SettingLayer/resources-ipadhd");
        
        searchPaths.push_back("Background/resources-ipadhd");
        resDirOrders.push_back("Background/resources-ipadhd");
        
        searchPaths.push_back("MonumentSelection/resources-ipadhd");
        resDirOrders.push_back("MonumentSelection/resources-ipadhd");
        
        searchPaths.push_back("LevelSelectionlayer/resources-ipadhd");
        resDirOrders.push_back("LevelSelectionlayer/resources-ipadhd");
        
        searchPaths.push_back("ShapeSelect/resources-ipadhd");
        resDirOrders.push_back("ShapeSelect/resources-ipadhd");
        
        searchPaths.push_back("MonumentSelection/resources-ipadhd");
        resDirOrders.push_back("MonumentSelection/resources-ipadhd");
        
        searchPaths.push_back("InAppPurChaseLayer/resources-ipadhd");
        resDirOrders.push_back("InAppPurChaseLayer/resources-ipadhd");
        
        searchPaths.push_back("NightModeImages/resources-ipadhd");
        resDirOrders.push_back("NightModeImages/resources-ipadhd");
        
        
    }
    else
    {
        searchPaths.push_back("resources-ipad");
        resDirOrders.push_back("resources-ipad");
        
        searchPaths.push_back("GameLayer/resources-ipad");
        resDirOrders.push_back("GameLayer/resources-ipad");
        
        searchPaths.push_back("LeaderBoardLayer/resources-ipad");
        resDirOrders.push_back("LeaderBoardLayer/resources-ipad");
        
        searchPaths.push_back("MenuLayer/resources-ipad");
        resDirOrders.push_back("MenuLayer/resources-ipad");
        
        searchPaths.push_back("PauseLayer/resources-ipad");
        resDirOrders.push_back("PauseLayer/resources-ipad");
        
        searchPaths.push_back("MonumentSelectionLayer/resources-ipad");
        resDirOrders.push_back("MonumentSelectionLayer/resources-ipad");
        
        searchPaths.push_back("SettingLayer/resources-ipad");
        resDirOrders.push_back("SettingLayer/resources-ipad");
        
        searchPaths.push_back("Background/resources-ipad");
        resDirOrders.push_back("Background/resources-ipad");
        
        searchPaths.push_back("MonumentSelection/resources-ipad");
        resDirOrders.push_back("MonumentSelection/resources-ipad");
        
        searchPaths.push_back("LevelSelectionlayer/resources-ipad");
        resDirOrders.push_back("LevelSelectionlayer/resources-ipad");
        
        searchPaths.push_back("ShapeSelect/resources-ipad");
        resDirOrders.push_back("ShapeSelect/resources-ipad");
        
        searchPaths.push_back("MonumentSelection/resources-ipad");
        resDirOrders.push_back("MonumentSelection/resources-ipad");
        
        searchPaths.push_back("InAppPurChaseLayer/resources-ipad");
        resDirOrders.push_back("InAppPurChaseLayer/resources-ipad");
        
        searchPaths.push_back("NightModeImages/resources-ipad");
        resDirOrders.push_back("NightModeImages/resources-ipad");
    }
    
    if (platform == kTargetIpad || platform ==kTargetIphone)
    {
        if(frameSize.height >=resources_ipadhd.size.height)
        {
            if(frameSize.height==2208)
            {
                CCLOG("frameSize.height %f",frameSize.height);
                GameManager::sharedGameManager()->set_devise_resolution(6);
                
            }
            else{
                CCLOG("frameSize.height %f",frameSize.height);
                GameManager::sharedGameManager()->set_devise_resolution(1);
            }
            scale_factor=MIN(resources_ipadhd.size.height/frameSize.height, resources_ipadhd.size.width/frameSize.width);
            pDirector->setContentScaleFactor(scale_factor);
            
        }
        else if (frameSize.height == resources_iphoneSix.size.height)
        {
            CCLog("iphone Six");
            GameManager::sharedGameManager()->set_devise_resolution(5);
            scale_factor=MIN(resources_iphoneSix.size.height/frameSize.height, resources_iphoneSix.size.width/frameSize.width);
            pDirector->setContentScaleFactor(scale_factor);
        }
        else if (frameSize.height == resources_iphoneSixPlus.size.height)
        {
            CCLog("iphone Six Plus");
            GameManager::sharedGameManager()->set_devise_resolution(6);
            scale_factor=MIN(resources_iphoneSixPlus.size.height/frameSize.height, resources_iphoneSixPlus.size.width/frameSize.width);
            
            pDirector->setContentScaleFactor(scale_factor);
        }
        else if (frameSize.height >= resources_ipad.size.height)
        {
                CCLog("normal ipad");
                GameManager::sharedGameManager()->set_devise_resolution(2);
                scale_factor=MIN((resources_ipad.size.height/frameSize.height), (resources_ipad.size.width/frameSize.width));
                pDirector->setContentScaleFactor(scale_factor);
        }
        else if (frameSize.height >= resources_iphonehd.size.width)
        {
            GameManager::sharedGameManager()->set_devise_resolution(3);
            CCLog("retina ipod");
            if (frameSize.height>=1136)
            {
                scale_factor=MIN(resources_iphonehd.size.height/frameSize.height, resources_iphonehd.size.width/frameSize.width);
                CCLOG("ipod 5th");
            }
            else
            {
                CCLOG("ipod 4th");
                scale_factor=MIN(resources_iphonehd.size.height/frameSize.height, resources_iphonehd.size.width/frameSize.width);
            }
            pDirector->setContentScaleFactor(scale_factor);
        }
        else
        {
            GameManager::sharedGameManager()->set_devise_resolution(4);
            CCLog("normal ipod");
            
            scale_factor=MIN(resources_iphone.size.height/frameSize.height, resources_iphone.size.width/frameSize.width);
            pDirector->setContentScaleFactor(scale_factor);
        }
        pEGLView->setDesignResolutionSize(frameSize.width, frameSize.height, kResolutionShowAll);
    }
    else if (platform == kTargetAndroid )
    {
        CCSize designSize = CCSizeMake(1024, 768);
        if(frameSize.height >= resources_ipad.size.height)
        {
            CCLog("retina ipad");
            
            GameManager::sharedGameManager()->set_devise_resolution(1);
            scale_factor=MIN(resources_ipad.size.height/frameSize.height, resources_ipad.size.width/frameSize.width);
            pDirector->setContentScaleFactor(scale_factor);
            pEGLView->setDesignResolutionSize(frameSize.width, frameSize.height, kResolutionExactFit);
        }
        else if (frameSize.height >= resources_ipad.size.height)
        {
            CCLog("normal ipad");
            //searchPath.push_back(resources_ipad.directory);
            
            GameManager::sharedGameManager()->set_devise_resolution(2);
            scale_factor=MIN(resources_ipad.size.height/designSize.height, resources_ipad.size.width/designSize.width);
            pDirector->setContentScaleFactor(scale_factor);
        }
        //if the frame's height is larger than the height of small resource size, select medium resource.
        else if(frameSize.height >= resources_iphonehd.size.height)
        {
            CCLog("retina ipod");
            
            if (frameSize.width>=1136){
                scale_factor=MIN(resources_iphonehd.size.height/frameSize.height, resources_iphonehd.size.width/frameSize.width);
            }
            else{
                scale_factor=MIN(resources_ipad.size.height/frameSize.height, resources_ipad.size.width/frameSize.width);
            }
            
            GameManager::sharedGameManager()->set_devise_resolution(3);
            pDirector->setContentScaleFactor(scale_factor);
        }
        else if (frameSize.height == resources_iphoneSix.size.height)
        {
            CCLog("iphone Six");
            GameManager::sharedGameManager()->set_devise_resolution(5);
            scale_factor=MIN(resources_iphoneSix.size.height/frameSize.height, resources_iphoneSix.size.width/frameSize.width);
            pDirector->setContentScaleFactor(scale_factor);
        }
        else if (frameSize.height == resources_iphoneSixPlus.size.height)
        {
            CCLog("iphone Six Plus");
            pDirector->setContentScaleFactor(scale_factor);
        }
        
        // if the frame's height is smaller than the height of medium resource size, select small resource.
        else
        {
            CCLog("normal ipod");
            //scale_factor=MIN(resources_ipadhd.size.height/frameSize.height, resources_ipadhd.size.width/frameSize.width);
            //scale_factor=MIN(resources_Medium.size.height/frameSize.height,resources_Medium.size.height/frameSize.width);
            scale_factor=MIN(resources_ipad.size.height/frameSize.height, resources_ipad.size.width/frameSize.width);
            GameManager::sharedGameManager()->set_devise_resolution(4);
            pDirector->setContentScaleFactor(scale_factor);
        }
        pEGLView->setDesignResolutionSize(frameSize.width, frameSize.height, kResolutionExactFit);
        //        CCSize designSize = CCSizeMake(1024, 768);
        //        if(frameSize.height >= resources_ipad.size.height){
        //
        //            CCLOG("frameSize.height %f",frameSize.height);
        //            CCLOG("resources_ipad.size.height %f",resources_ipad.size.height);
        //            CCLog("retina ipad");
        //            GameManager::sharedGameManager()->set_devise_resolution(1);
        //            scale_factor=MIN(resources_ipad.size.height/frameSize.height, resources_ipad.size.width/frameSize.width);
        //            pDirector->setContentScaleFactor(scale_factor);
        //            pEGLView->setDesignResolutionSize(frameSize.width, frameSize.height, kResolutionShowAll);
        //        }
        //        else if (frameSize.height >= resources_ipad.size.height){
        //            CCLOG("frameSize.height %f",frameSize.height);
        //            CCLOG("resources_ipad.size.height %f",resources_ipad.size.height);
        //            CCLog("normal ipad");
        //            GameManager::sharedGameManager()->set_devise_resolution(2);
        //            scale_factor=MIN(resources_ipad.size.height/designSize.height, resources_ipad.size.width/designSize.width);
        //            pDirector->setContentScaleFactor(scale_factor);
        //            pEGLView->setDesignResolutionSize(frameSize.width, frameSize.height, kResolutionShowAll);
        //        }
        //
        //        //if the frame's height is larger than the height of small resource size, select medium resource.
        //        else if(frameSize.height >= resources_iphonehd.size.height){
        //            CCLOG("frameSize.height %f",frameSize.height);
        //            CCLOG("resources_iphonehd.size.height %f",resources_iphonehd.size.height);
        //            CCLog("retina ipod");
        //            if (frameSize.height>=1136)
        //            {
        //                scale_factor=MIN(resources_ipad.size.height/frameSize.height, resources_ipad.size.width/frameSize.width);
        //            }
        //            else
        //            {
        //                scale_factor=MIN(resources_ipad.size.height/frameSize.height, resources_ipad.size.width/frameSize.width);
        //            }
        //            GameManager::sharedGameManager()->set_devise_resolution(3);
        //            pDirector->setContentScaleFactor(scale_factor);
        //            pEGLView->setDesignResolutionSize(frameSize.width, frameSize.height, kResolutionShowAll);
        //        }
        //        // if the frame's height is smaller than the height of medium resource size, select small resource.
        //        else{
        //            CCLOG("frameSize.height %f",frameSize.height);
        //            CCLOG("resources_ipad.size.height %f",resources_ipad.size.height);
        //            CCLog("normal ipod");
        //
        //            scale_factor=MIN(resources_ipad.size.height/frameSize.height, resources_ipad.size.width/frameSize.width);
        //            GameManager::sharedGameManager()->set_devise_resolution(4);
        //            pDirector->setContentScaleFactor(scale_factor);
        //            pEGLView->setDesignResolutionSize(frameSize.width, frameSize.height, kResolutionShowAll);
        //        }
    }
    CCLOG("Window height %f",frameSize.height);
    CCLOG("Window Width %f",frameSize.width);
    CCLOG("GameManager::sharedGameManager()->get_devise_resolution() %d",GameManager::sharedGameManager()->get_devise_resolution() );
    CCFileUtils::sharedFileUtils()->setSearchResolutionsOrder(resDirOrders);
    // set searching path
    CCFileUtils::sharedFileUtils()->setSearchPaths(searchPaths);
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    //    CCDirector::sharedDirector()->pause();
    CCDirector::sharedDirector()->stopAnimation();
    // if you use SimpleAudioEngine, it must be pause
    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    //    CCDirector::sharedDirector()->resume();
    CCDirector::sharedDirector()->startAnimation();
    // if you use SimpleAudioEngine, it must resume here
    SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}

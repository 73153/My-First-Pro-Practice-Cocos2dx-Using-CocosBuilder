//PrintMessage.h
#ifndef __PRINTMESSAGE_H__
#define __PRINTMESSAGE_H__

#include <stddef.h>

#include "cocos2d.h"
#define isiOS8OrGreater [[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0 ? YES : NO
#define isiPad UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad

#define kAppUrl @"itms-apps://itunes.apple.com/app/id941007837"
#define kWebUrl @"https://itunes.apple.com/app/id941007837?mt=8"

#define kShareString [NSString stringWithFormat:@"Take a look at Bricks breaker! \n %@",kWebUrl]

#define kItunesAppID @"APPID"

using namespace cocos2d;

class ObjCCalls
{
public:
    static void gameCenterLogin();
    static void get_user_image();
    static void openImage();
    static CCSprite* image();
    static void remove_ads();
    static void full_screen_banner(bool should_show);
    static void full_screen_banner_revmob(bool should_show);
    
    static void trySendATweet(const char *score);
    static void trySendAnEMail(const char *score, bool usingInternalApp);
    static void tryPostOnFB(const char *score);
    static bool tryIsInternetConnection();
    static void openMoreApps();
    static void loadMoreAppsData();
    static void openFeedBackForm();
    static void purchaseEffielTower();
     static void purchaseStatueueOfLiberty();
     static void purchaseTowerOfPisa();
    static void purchaseBigBen();
    static void purchaseColosseum();
    static void purchaseOperaHouse();
    static void purchaseEasterStone();
    static void restoreInAppPurchase();
    static void showActivityIndictor();
    static void hideActivityIndicator();
    static void onFacebookClick();
    static void onTwitterClick();
    static void unlockAllMonuments();
    static void purchaseFiveHundredCoins();
    static void onShareClicked();
    static void startAppsCue();
    static void presentAppsCue();
    static void onShareClickedFromMonuments();
    static void onRateUsClicked();
    static void openAlert(bool isAnyLevelCleared,CCLabelTTF *monumentName);
    static void openToastAlert();
    static void alertForCoinsBuy();
    static void openToastAlertForGameCenter();
    static void showWhiteActivityIndictor();
    
    static std::string getCurrentTime();
    static std::string getTodayDate();
    
};

#endif//__PRINTMESSAGE_H__
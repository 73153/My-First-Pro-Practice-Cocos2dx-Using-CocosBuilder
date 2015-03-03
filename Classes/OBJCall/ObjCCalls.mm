#include "../OBJCall/ObjCCalls.h"
#import "../OBJCall/ImagePickerIOS.h"
#import "../cocos2dx/platform/ios/EAGLView.h" 
#import "../ObjCCalls/MailSender.h"
#import "../cocos2dx/platform/ios/EAGLView.h"
#import "../ObjCCalls/TweetSender.h"
#import "../ObjCCalls/Facebook.h"
#import "../ObjCCalls/MailSender.h"
#import "../ObjCCalls/Reachability.h"
#include "GameKitHelper.h"
#include "../InApp/InAppController.h"
//#import "ABGameKitHelper.h"
#import "../MoreAppAndSupport/MoreApps/MoreAppsViewController.h"
#import "../MoreAppAndSupport/Feedback/FeedbackViewController.h"
#import "../MoreAppAndSupport/Feedback/SVProgressHUD/SVProgressHUD.h"
#import "../KAWebViewController/KAWebViewController.h"
#import "../MoreAppAndSupport/AppsCueSDK/AppsCue.h"
#import "UIView+Toast.h"

ImagePickerIOS *sharedPicker = nil;
void ObjCCalls::openImage()
{
    if (sharedPicker == nil)
    {
        sharedPicker = [[ImagePickerIOS alloc] init];
        [sharedPicker retain];
    }
    if(CCApplication::sharedApplication()->getTargetPlatform()==kTargetIpad)
    [sharedPicker takePicture];
    else
    [sharedPicker takePhoto];
}
CCSprite* ObjCCalls::image()
{
    CCImage *imf =new CCImage();
    NSData *imgData = UIImagePNGRepresentation([sharedPicker getImage]);
    NSUInteger len = [imgData length];
    Byte *byteData = (Byte*)malloc(len);
    memcpy(byteData, [imgData bytes], len);
    imf->initWithImageData(byteData,imgData.length);
    imf->autorelease();
    CCTexture2D* pTexture = new CCTexture2D();
    pTexture->initWithImage(imf);
    pTexture->autorelease();
    CCSprite *sprit = CCSprite::createWithTexture(pTexture);
    return sprit;
}
void ObjCCalls::presentAppsCue()
{
     [[ImagePickerIOS sharedObject] displayParentalGatesForMoreApps];
}

void ObjCCalls::alertForCoinsBuy()
{
    [[ImagePickerIOS sharedObject] displayParentalGatesForalertForCoinsBuy];
}

void ObjCCalls::openAlert(bool isAnyLevelCleared,CCLabelTTF *monumentName)
{
    [[ImagePickerIOS sharedObject] openAlert:isAnyLevelCleared monumentName:[NSString stringWithCString:monumentName->getString() encoding:NSUTF8StringEncoding]];
}
void ObjCCalls::startAppsCue()
{
    [[AppsCue sharedInstance]startWithApiKey:@"0dbcce285e96e25f0150bd4def5b80fazskP"];
}
void ObjCCalls::gameCenterLogin()
{
    [[GameKitHelper sharedGameKitHelper] authenticateLocalUser];
    //2. Call class once to authenticate user
//    [ABGameKitHelper sharedHelper];
}
void ObjCCalls::showActivityIndictor()
{    
    [NSThread detachNewThreadSelector:@selector(show) toTarget:[SVProgressHUD class] withObject:nil];
    //[SVProgressHUD show];
}

void ObjCCalls::showWhiteActivityIndictor()
{
    [NSThread detachNewThreadSelector:@selector(showWhiteColorIndicator) toTarget:[SVProgressHUD class] withObject:nil];

}
void ObjCCalls::openToastAlert()
{
    UIViewController *topController = [UIApplication sharedApplication].keyWindow.rootViewController;
    while (topController.presentedViewController)
    {
        topController = topController.presentedViewController;
    }
    [topController.view makeToast:@"Please check your internet connection" duration:2 position:@"bottom" title:nil];
}

void ObjCCalls::openToastAlertForGameCenter()
{
    UIViewController *topController = [UIApplication sharedApplication].keyWindow.rootViewController;
    while (topController.presentedViewController)
    {
        topController = topController.presentedViewController;
    }
    [topController.view makeToast:@"Please sign in Game Center to see your highest score" duration:5 position:@"bottom" title:nil];
    
}
void ObjCCalls::hideActivityIndicator()
{       
    [SVProgressHUD dismiss];
}

void ObjCCalls::onFacebookClick()
{
    [[ImagePickerIOS sharedObject] displayParentalGatesForFB];
 }

void ObjCCalls::onTwitterClick()
{
    [[ImagePickerIOS sharedObject] displayParentalGatesForTwitter];
}

void ObjCCalls::get_user_image()
{
}
void ObjCCalls::full_screen_banner(bool should_show)
{
}
void ObjCCalls::full_screen_banner_revmob(bool should_show)
{

}

void ObjCCalls::trySendATweet(const char *score)
{
    [TweetSender trySendATweet:score];
}

void ObjCCalls::trySendAnEMail(const char *score, bool usingInternalApp)
{
    MailSender *mailSender = [MailSender alloc];
    if (usingInternalApp) {
        [mailSender sendMailUsingInAppMailer:score];
    }
    else{
        [mailSender sendMailUsingExternalApp:score];
    }
}

void ObjCCalls::loadMoreAppsData() {
    MoreAppsViewController *moreapp = [[MoreAppsViewController alloc]init];
    [moreapp loadAppData];
}

std::string ObjCCalls::getCurrentTime()
{
    NSDate *localDate = [NSDate date];
    NSDateFormatter *dateFormatter = [[[NSDateFormatter alloc]init]autorelease];
    dateFormatter.dateFormat = @"MM/dd/yy";
    
    
    NSDateFormatter *timeFormatter = [[[NSDateFormatter alloc]init]autorelease];
    timeFormatter.dateFormat = @"HH:mm:ss";
    
    NSString *todays1 = [dateFormatter stringFromDate: localDate];

    NSLog(@"%@ todays1",todays1);

    
    NSString *todaysDate = [timeFormatter stringFromDate: localDate];
    NSLog(@"%@ todaysDate",todaysDate);
    
    CCUserDefault::sharedUserDefault()->setStringForKey("TODAYDATE", [todaysDate UTF8String]);
    CCUserDefault::sharedUserDefault()->flush();
    
    std::string todaysTime =  [todaysDate UTF8String];
    CCLOG("todaysDateAndTime %s",todaysTime.c_str());
    
    std::string todayDate =  [todays1 UTF8String];
    CCLOG("todaysDateAndTime %s",todayDate.c_str());

    std::string todayDateAndTime =  todaysTime+" "+todayDate;

    CCLOG("todayDateAndTime %s",todayDateAndTime.c_str());
    return todaysTime;
}

std::string ObjCCalls::getTodayDate()
{
    NSDate *localDate = [NSDate date];
    NSDateFormatter *dateFormatter = [[[NSDateFormatter alloc]init]autorelease];
    dateFormatter.dateFormat = @"MM/dd/yy";
    
    
    NSDateFormatter *timeFormatter = [[[NSDateFormatter alloc]init]autorelease];
    timeFormatter.dateFormat = @"HH:mm:ss";
    
    NSString *todays1 = [dateFormatter stringFromDate: localDate];
    
    NSLog(@"%@ todays1",todays1);
    
    
    NSString *todaysDate = [timeFormatter stringFromDate: localDate];
    NSLog(@"%@ todaysDate",todaysDate);
    
    CCUserDefault::sharedUserDefault()->setStringForKey("TODAYDATE", [todaysDate UTF8String]);
    CCUserDefault::sharedUserDefault()->flush();
    
    std::string todaysTime =  [todaysDate UTF8String];
    CCLOG("todaysDateAndTime %s",todaysTime.c_str());
    
    std::string todayDate =  [todays1 UTF8String];
    CCLOG("todaysDateAndTime %s",todayDate.c_str());
    
    std::string todayDateAndTime =  todaysTime+" "+todayDate;
    
    CCLOG("todayDateAndTime %s",todayDateAndTime.c_str());
    return todayDate;
}

void ObjCCalls::openMoreApps()
{
    [MoreAppsViewController present];
//    [[ImagePickerIOS sharedObject] displayParentalGatesForMoreApps];
}
void ObjCCalls::purchaseEffielTower()
{
    [[ImagePickerIOS sharedObject] displayParentalGatesForpurchaseEffielTower];
}

void ObjCCalls::unlockAllMonuments()
{
    [[ImagePickerIOS sharedObject] displayParentalGatesForunlockAllMonuments];
}

void ObjCCalls::purchaseStatueueOfLiberty()
{
    [[ImagePickerIOS sharedObject] displayParentalGatesForpurchaseStatueueOfLiberty];
}

void ObjCCalls::purchaseTowerOfPisa()
{
    [[ImagePickerIOS sharedObject] displayParentalGatesForpurchaseTowerOfPisa];
}

void ObjCCalls::purchaseBigBen()
{
    [[ImagePickerIOS sharedObject] displayParentalGatesForpurchaseBigBen];
}

void ObjCCalls::purchaseColosseum()
{
    [[ImagePickerIOS sharedObject] displayParentalGatesForpurchaseColosseum];
}
void ObjCCalls::purchaseOperaHouse()
{
    [[ImagePickerIOS sharedObject] displayParentalGatesForpurchaseOperaHouse];

}
void ObjCCalls::purchaseEasterStone()
{
    [[ImagePickerIOS sharedObject] displayParentalGatesForpurchaseEasterStone];

  
}
void ObjCCalls::restoreInAppPurchase()
{
    [[ImagePickerIOS sharedObject] displayParentalGatesForrestoreInAppPurchase];

}

void ObjCCalls::onShareClicked()
{
    [[ImagePickerIOS sharedObject] displayParentalGatesForShare];

}
void ObjCCalls::onRateUsClicked()
{
    [[ImagePickerIOS sharedObject] displayParentalGatesForRateUs];
    
}
void ObjCCalls::onShareClickedFromMonuments()
{
    [[ImagePickerIOS sharedObject] displayParentalGatesForShare];
}

void ObjCCalls::purchaseFiveHundredCoins()
{
    [[ImagePickerIOS sharedObject] displayParentalGatesForpurchaseFiveHundredCoins];
}

void ObjCCalls::openFeedBackForm() {
    [[ImagePickerIOS sharedObject] displayParentalGatesForFeedBackForm];
}

void ObjCCalls::tryPostOnFB(const char *score)
{
    [Facebook tryToPostOnFacebook:score];
}

bool ObjCCalls::tryIsInternetConnection()
{
    if (![[Reachability reachabilityForInternetConnection] isReachable]) {
        return FALSE;
    }
    return TRUE;
}


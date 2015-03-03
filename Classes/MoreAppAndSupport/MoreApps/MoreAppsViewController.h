//
//  MoreAppsViewController.h
//  MoreAppsDemo
//
//  Created by Henryp on 7/18/14.
//  Copyright (c) 2014 r3app. All rights reserved.
//

#define MyAppID 920041144
#define kServerURL @"http://appdatafog.com/appadmin/services/show-more-apps.php?type=ios"

BOOL isiPadOrIphone6Plus();

static NSString *kAppID           = @"app_id";
static NSString *kiPadImageUrl    = @"ipadbaseImg";
static NSString *kiPhoneImageUrl  = @"ipodbaseImg";
static NSString *kStoreUrl        = @"url";
static NSString *kUrlSchema       = @"urlschema";

static NSString *kiPadTitleImgs   = @"ipadTitleImg";
static NSString *kiPodTitleImgs   = @"ipodTitleImg";

#import <UIKit/UIKit.h>
#import <StoreKit/StoreKit.h>
#import "iCarousel.h"
#import "JBAsyncImageView.h"
#import "UIView+Utility.h"

@interface MoreAppsViewController : UIViewController<iCarouselDataSource,iCarouselDelegate,NSURLConnectionDelegate,SKStoreProductViewControllerDelegate,iCarouselDelegate>
{
    IBOutlet UILabel *lblTitle;
    IBOutlet UIImageView *imgViewBg;
    IBOutlet iCarousel *carouselView;
    IBOutlet UIPageControl *pageControl;
    NSURLConnection *UrlConnection;
    IBOutlet UIView *containerView;
}
@property (nonatomic, strong)SKStoreProductViewController *productViewController;
@property (nonatomic, strong) NSMutableData *appData;
@property (nonatomic, strong) NSMutableArray *arrApps;

+(UIViewController*) topViewController;
+ (void)present;
-(void)loadAppData ;

@end

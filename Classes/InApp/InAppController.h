#import <UIKit/UIKit.h>
#import "IAPHelper.h"
#import <CoreLocation/CoreLocation.h>
#define kInAppProductIdentifierEffileTower @"com.r3app.bricksbreaker.unlock_eiffel_tower"
#define kInAppProductIdentifierStatueOfLiberty @"com.r3app.bricksbreaker.unlock_statue_of_liberty"
#define kInAppProductIdentifierTowerOfPisa @"com.r3app.bricksbreaker.unlock_leaning_tower"
#define kInAppProductIdentifierBigBen @"com.r3app.bricksbreaker.unlock_big_ban"
#define kInAppProductIdentifierColosseum @"com.r3app.bricksbreaker.unlock_colosseum"
#define kInAppProductIdentifierOperaHouse @"com.r3app.bricksbreaker.unlock_sydney_opera_house"
#define kInAppProductIdentifierEasterStone @"com.r3app.bricksbreaker.unlock_easter_island_stone"
#define kInAppProductIdentifierUnlockAllMonumrents @"com.r3app.bricksbreaker.unlockAllMonuments"
#define kInAppProductIdentifierFiveHundredCoins @"com.r3app.bricksbreaker.coins_pack_250"


@class RootViewController;

@interface InAppController : NSObject < IAPTransactionDelegate>
{
    UIWindow *window;
    RootViewController    *viewController;
    UIActivityIndicatorView *activityIndicator;
    // Declare one as an instance variable
}
-(void)purchaseEffielTower;
-(void)purchaseStatueueOfLiberty;
-(void)purchaseTowerOfPisa;
-(void)purchaseBigBen;
-(void)purchaseColosseum;
-(void)purchaseOperaHouse;
-(void)purchaseEasterStone;
-(void)unlockAllMonuments;
- (void)restoreProduct;
-(void)purchaseFiveHundredCoins;
@property (assign, nonatomic) IAPHelper *iapHelper;
//@property (nonatomic, strong)RevMobFullscreen *fullscreen;
//@property (nonatomic, strong)RevMobBannerView *banner;
//@property (nonatomic, strong)RevMobBanner *bannerWindow;
//@property (nonatomic, strong)RevMobAdLink *link;
@property(nonatomic,strong)UIWindow *window;
@property(nonatomic,strong)RootViewController    *viewController;
@end


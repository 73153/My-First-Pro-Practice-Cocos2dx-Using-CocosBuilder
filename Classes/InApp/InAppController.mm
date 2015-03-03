#import "InAppController.h"
#import "cocos2d.h"
#import "RootViewController.h"
#import "SVProgressHUD.h"

@implementation InAppController
@synthesize viewController;
@synthesize window;
#pragma mark -
#pragma mark Application lifecycle
//cocos2d application instance
USING_NS_CC;
#pragma mark -
#pragma mark In App Purchase
#pragma mark -
-(void)purchaseEffielTower
{
    [SVProgressHUD show];
    NSSet *set = [[[NSSet alloc]initWithObjects:kInAppProductIdentifierEffileTower, nil] retain];
	_iapHelper = [[IAPHelper alloc]initWithProductIdentifiers:set];
	_iapHelper.delegate = self;
	[_iapHelper requestProducts];
    NSLog(@"Method purchaseEffielTower called");
}
-(void)purchaseStatueueOfLiberty{
    [SVProgressHUD showWhiteColorIndicator];
    NSSet *set = [[[NSSet alloc]initWithObjects:kInAppProductIdentifierStatueOfLiberty, nil] retain];
    _iapHelper = [[IAPHelper alloc]initWithProductIdentifiers:set];
    _iapHelper.delegate = self;
    [_iapHelper requestProducts];
    NSLog(@"Method kInAppProductIdentifierStatueOfLiberty called");
}
-(void)purchaseTowerOfPisa{
    
    [SVProgressHUD showWhiteColorIndicator];
    NSSet *set = [[[NSSet alloc]initWithObjects:kInAppProductIdentifierTowerOfPisa, nil] retain];
    _iapHelper = [[IAPHelper alloc]initWithProductIdentifiers:set];
    _iapHelper.delegate = self;
    [_iapHelper requestProducts];
    NSLog(@"Method kInAppProductIdentifierTowerOfPisa called");
}
-(void)purchaseBigBen{
    [SVProgressHUD showWhiteColorIndicator];

    NSSet *set = [[[NSSet alloc]initWithObjects:kInAppProductIdentifierBigBen, nil] retain];
    _iapHelper = [[IAPHelper alloc]initWithProductIdentifiers:set];
    _iapHelper.delegate = self;
    [_iapHelper requestProducts];
    NSLog(@"Method kInAppProductIdentifierBigBen called");
}
-(void)purchaseColosseum{
    [SVProgressHUD show];
    NSSet *set = [[[NSSet alloc]initWithObjects:kInAppProductIdentifierColosseum, nil] retain];
    _iapHelper = [[IAPHelper alloc]initWithProductIdentifiers:set];
    _iapHelper.delegate = self;
    [_iapHelper requestProducts];
    NSLog(@"Method kInAppProductIdentifierColosseum called");
}
-(void)purchaseOperaHouse{
    [SVProgressHUD showWhiteColorIndicator];
    NSSet *set = [[[NSSet alloc]initWithObjects:kInAppProductIdentifierOperaHouse, nil] retain];
    _iapHelper = [[IAPHelper alloc]initWithProductIdentifiers:set];
    _iapHelper.delegate = self;
    [_iapHelper requestProducts];
    NSLog(@"Method kInAppProductIdentifierOperaHouse called");
}
-(void)purchaseEasterStone{
    [SVProgressHUD show];
    NSSet *set = [[[NSSet alloc]initWithObjects:kInAppProductIdentifierEasterStone, nil] retain];
    _iapHelper = [[IAPHelper alloc]initWithProductIdentifiers:set];
    _iapHelper.delegate = self;
    [_iapHelper requestProducts];
    NSLog(@"Method kInAppProductIdentifierEasterStone called");
}
-(void)purchaseFiveHundredCoins
{
    [SVProgressHUD show];
    NSSet *set = [[[NSSet alloc]initWithObjects:kInAppProductIdentifierFiveHundredCoins, nil] retain];
    _iapHelper = [[IAPHelper alloc]initWithProductIdentifiers:set];
    _iapHelper.delegate = self;
    [_iapHelper requestProducts];
    NSLog(@"Method purchaseFiveHundredCoins called");
}

- (void)restoreProduct{
    NSLog(@"Method restoreProduct called");
    [SVProgressHUD showWithMaskType:SVProgressHUDMaskTypeGradient];
    NSSet *set = [[[NSSet alloc]initWithObjects:kInAppProductIdentifierEffileTower,kInAppProductIdentifierStatueOfLiberty,kInAppProductIdentifierTowerOfPisa,kInAppProductIdentifierBigBen,kInAppProductIdentifierColosseum,kInAppProductIdentifierOperaHouse,kInAppProductIdentifierEasterStone,kInAppProductIdentifierUnlockAllMonumrents, nil] retain];
    [[IAPHelper sharedHelper]setProductIdentifiers:set];
    [[IAPHelper sharedHelper] setDelegate:self];
    [[IAPHelper sharedHelper] restorePurchased];
}

- (void)finishedProductLoading
{
	[_iapHelper buyProduct:[_iapHelper.products objectAtIndex:0]];
}

- (void)noProductToRestore {
    [SVProgressHUD dismiss];
        [[[UIAlertView alloc] initWithTitle:@"" message:@"No product purchased" delegate:self cancelButtonTitle:nil otherButtonTitles:@"Ok", nil] show];
}

-(void)restoreCompletedWithTransactions:(NSArray *)transactions {
    [SVProgressHUD dismiss];
    [transactions enumerateObjectsUsingBlock:^(SKPaymentTransaction *obj, NSUInteger idx, BOOL *stop) {
        CCString *str = CCString::createWithFormat("%s",[obj.payment.productIdentifier UTF8String]);
        CCLOG("str %s",str->getCString());
        CCUserDefault::sharedUserDefault()->setBoolForKey(str->getCString(), true);
        CCUserDefault::sharedUserDefault()->flush();
        
    }];
    CCNotificationCenter::sharedNotificationCenter()->postNotification("MonumentPurchaseFinishedNotification");

    [[[UIAlertView alloc]initWithTitle:@"" message:[NSString stringWithFormat:@"Restore completed"] delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil]show];
    
    
}

-(void)finishdProductPurchased:(NSString*)transaction
{
    NSLog(@"***** purchased finish %@ ",transaction);
    [SVProgressHUD dismiss];
	[self finishedProductPurchase:transaction];
    if([transaction isEqualToString:kInAppProductIdentifierFiveHundredCoins]){
    CCNotificationCenter::sharedNotificationCenter()->postNotification("CoinsPurchaseFinishedNotification");
    }
    else{
        CCNotificationCenter::sharedNotificationCenter()->postNotification("MonumentPurchaseFinishedNotification");
    }
}

-(void)failedProductPurchased:(SKPaymentTransaction*)transaction
{
    [SVProgressHUD dismiss];
    [[[UIAlertView alloc] initWithTitle:@"Failure" message:[transaction.error localizedDescription] delegate:self cancelButtonTitle:nil otherButtonTitles:@"Ok", nil] show];
}

-(void)unlockAllMonuments{
    [SVProgressHUD show];
    NSSet *set = [[[NSSet alloc]initWithObjects:kInAppProductIdentifierUnlockAllMonumrents, nil] retain];
    _iapHelper = [[IAPHelper alloc]initWithProductIdentifiers:set];
    _iapHelper.delegate = self;
    [_iapHelper requestProducts];
    NSLog(@"Method kInAppProductIdentifierUnlockAllMonumrents called");
}

- (void)restoreProductFailed {
    [SVProgressHUD dismiss];
}


- (void)finishedProductPurchase:(NSString*)transaction
{
    CCString *str = CCString::createWithFormat("%s",[transaction UTF8String]);
    CCLOG("str %s",str->getCString());
    CCUserDefault::sharedUserDefault()->setBoolForKey(str->getCString(), true);
    CCUserDefault::sharedUserDefault()->flush();
    
    if([transaction isEqualToString:kInAppProductIdentifierUnlockAllMonumrents])
    {
        CCUserDefault::sharedUserDefault()->setBoolForKey([kInAppProductIdentifierEffileTower UTF8String], true);
        CCUserDefault::sharedUserDefault()->setBoolForKey([kInAppProductIdentifierStatueOfLiberty UTF8String], true);
        CCUserDefault::sharedUserDefault()->setBoolForKey([kInAppProductIdentifierTowerOfPisa UTF8String], true);

        CCUserDefault::sharedUserDefault()->setBoolForKey([kInAppProductIdentifierBigBen UTF8String], true);

        CCUserDefault::sharedUserDefault()->setBoolForKey([kInAppProductIdentifierColosseum UTF8String], true);

        CCUserDefault::sharedUserDefault()->setBoolForKey([kInAppProductIdentifierOperaHouse UTF8String], true);

        CCUserDefault::sharedUserDefault()->setBoolForKey([kInAppProductIdentifierEasterStone UTF8String], true);

        CCUserDefault::sharedUserDefault()->flush();
    }
    [[NSUserDefaults standardUserDefaults] setBool:TRUE forKey:transaction];
    [[NSUserDefaults standardUserDefaults] synchronize];
}
@end
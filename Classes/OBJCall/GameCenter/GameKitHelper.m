//
//  GameKitHelper.m
//  HoldOnDemo
//
//  Created by ken on 14/7/4.
//
//

#import "GameKitHelper.h"
#include "HoldOnConfig.h"

//#import "HoldOnModel.h"

@implementation GameKitHelper

@synthesize gameCenterAvailable;

//静态初始化 对外接口
static GameKitHelper *sharedHelper = nil;
static UIViewController* currentModalViewController = nil;
+ (GameKitHelper *) sharedGameKitHelper {
    if (!sharedHelper) {
        sharedHelper = [[GameKitHelper alloc] init];
    }
    return sharedHelper;
}

//用于验证
- (BOOL)isGameCenterAvailable {
    // check for presence of GKLocalPlayer API
    Class gcClass = (NSClassFromString(@"GKLocalPlayer"));
    // check if the device is running iOS 4.1 or later
    NSString *reqSysVer =@"4.1";
    NSString *currSysVer = [[UIDevice currentDevice] systemVersion];
    BOOL osVersionSupported = ([currSysVer compare:reqSysVer
                                           options:NSNumericSearch] != NSOrderedAscending);
    return (gcClass && osVersionSupported);
}

- (id)init {
    if ((self = [super init])) {
        gameCenterAvailable = [self isGameCenterAvailable];
        if (gameCenterAvailable) {
            NSNotificationCenter *nc =
            [NSNotificationCenter defaultCenter];
            [nc addObserver:self
                   selector:@selector(authenticationChanged)
                       name:GKPlayerAuthenticationDidChangeNotificationName
                     object:nil];
        }
    }
    return self;
}

//后台回调登陆验证
- (void)authenticationChanged {
    if ([GKLocalPlayer localPlayer].isAuthenticated &&!userAuthenticated) {
        NSLog(@"Authentication changed: player authenticated.");
        userAuthenticated = TRUE;
    } else if (![GKLocalPlayer localPlayer].isAuthenticated && userAuthenticated) {
        NSLog(@"Authentication changed: player not authenticated");
        userAuthenticated = FALSE;
    }
}

- (void)authenticateLocalUser {
    if (!gameCenterAvailable) return;
    NSLog(@"Authenticating local user...");
    if ([GKLocalPlayer localPlayer].authenticated == NO) {
        [[GKLocalPlayer localPlayer] authenticateWithCompletionHandler:nil];
    } else {
        NSLog(@"Already authenticated!");
    }
}

- (void)reportChallengeScore:(uint32_t)score{
    GKScore *scoreReporter = [[GKScore alloc] initWithCategory:KLeaderBoardIdMonumentChallenge];
    scoreReporter.value = score;
    
    [scoreReporter reportScoreWithCompletionHandler:^(NSError *error) {
        if (error != nil){
            NSLog(@"上传分数出错.");
        }else {
            NSLog(@"上传分数成功");
        }
    }];
}

-(void) whetherChallengeHighestScores:(uint32_t)score{
    _isNewRecordChallenge = YES;
    NSLog(@"Highest %d",score);
    GKLeaderboard *leaderboardRequest = [[GKLeaderboard alloc] init];
    if (leaderboardRequest != nil){
        leaderboardRequest.playerScope = GKLeaderboardPlayerScopeGlobal;
        leaderboardRequest.timeScope = GKLeaderboardTimeScopeAllTime;
        leaderboardRequest.range = NSMakeRange(1,100);
        leaderboardRequest.category = KLeaderBoardIdMonumentChallenge;
        [leaderboardRequest loadScoresWithCompletionHandler: ^(NSArray *scores, NSError *error) {
            if (error != nil){
            }
            if (scores != nil){
                NSLog(@"下载成功.... scores = %@", scores);
                for (GKScore *obj in leaderboardRequest.scores) {
                    if (obj.value >= score) {
                        _isNewRecordChallenge = NO;
                        NSLog(@"value = %lld, score = %d", obj.value, score);
                        break;
                    }
                }
            }
        }];
    }
}


- (void)reportArcadeScore:(uint32_t)score{
    GKScore *scoreReporter = [[GKScore alloc] initWithCategory:KLeaderBoardIdArcade];
    scoreReporter.value = score;
    
    [scoreReporter reportScoreWithCompletionHandler:^(NSError *error) {
        if (error != nil){
            NSLog(@"上传分数出错.");
        }else {
            NSLog(@"上传分数成功");
        }
    }];
}

-(void) whetherArcadeHighestScores:(uint32_t)score{
    _isNewRecordArcade = YES;
    NSLog(@"Highest %d",score);
    GKLeaderboard *leaderboardRequest = [[GKLeaderboard alloc] init];
    if (leaderboardRequest != nil){
        leaderboardRequest.playerScope = GKLeaderboardPlayerScopeGlobal;
        leaderboardRequest.timeScope = GKLeaderboardTimeScopeAllTime;
        leaderboardRequest.range = NSMakeRange(1,100);
        leaderboardRequest.category = KLeaderBoardIdArcade;
        [leaderboardRequest loadScoresWithCompletionHandler: ^(NSArray *scores, NSError *error) {
            if (error != nil){
            }
            if (scores != nil){
                NSLog(@"下载成功.... scores = %@", scores);
                for (GKScore *obj in leaderboardRequest.scores) {
                    if (obj.value >= score) {
                        _isNewRecordArcade = NO;
                        NSLog(@"value = %lld, score = %d", obj.value, score);
                        break;
                    }
                }
            }
        }];
    }
}

//显示排行榜
- (void) showLeaderboard{
    NSLog(@"=%hhd",gameCenterAvailable);
    if (!gameCenterAvailable) return;
    GKLeaderboardViewController *leaderboardController = [[GKLeaderboardViewController alloc] init];
    if (leaderboardController != nil) {
        leaderboardController.leaderboardDelegate = self;
        UIWindow *window = [[UIApplication sharedApplication] keyWindow];
        currentModalViewController = [[UIViewController alloc] init];
        [window addSubview:currentModalViewController.view];
        [currentModalViewController presentModalViewController:leaderboardController animated:YES ];
    }
}
- (void)share
{
    NSLog(@"Share button pressed");
    NSString *text = [NSString stringWithFormat:@"Take a look at Bricks breaker! \n"];
    NSURL *url = [NSURL URLWithString:@"https://itunes.apple.com/app/id941007837?mt=8"];
    NSArray *objectsToShare = @[text, url];
    
    UIActivityViewController *controller = [[UIActivityViewController alloc]
                                            initWithActivityItems:objectsToShare
                                            applicationActivities:nil];
    
    controller.excludedActivityTypes = @[UIActivityTypeAssignToContact];
    
    [[[self class] topViewController] presentViewController:controller animated:TRUE completion:nil];
    
}

+(UIViewController*) topViewController
{
    UIViewController *topController = [UIApplication sharedApplication].keyWindow.rootViewController;
    while (topController.presentedViewController)
    {
        topController = topController.presentedViewController;
    }
    return topController;
}

//关闭排行榜回调
- (void)leaderboardViewControllerDidFinish:(GKLeaderboardViewController *)viewController{
    
//     if (viewController!=nil)
//    {
//        NSString *text = [NSString stringWithFormat:@"Take a look at Bricks breaker! \n"];
//        NSURL *url = [NSURL URLWithString:@"https://itunes.apple.com/app/id941007837?mt=8"];
//        NSArray *objectsToShare = @[text, url];
//        
//        UIActivityViewController *controller = [[UIActivityViewController alloc]
//                                                initWithActivityItems:objectsToShare
//                                                applicationActivities:nil];
//        
//        controller.excludedActivityTypes = @[UIActivityTypeAssignToContact];
//        
//        [[[self class] topViewController] presentViewController:controller animated:TRUE completion:nil];
//    }
    if(currentModalViewController !=nil){
        [currentModalViewController dismissModalViewControllerAnimated:NO];
        [currentModalViewController release];
        [currentModalViewController.view removeFromSuperview];
        currentModalViewController = nil;
    }
   
}

// The achievement view has finished
- (void)achievementViewControllerDidFinish:(GKAchievementViewController *)viewController{
    
}
@end

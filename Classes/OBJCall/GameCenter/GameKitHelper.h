//
//  GameKitHelper.h
//  HoldOnDemo
//
//  Created by ken on 14/7/4.
//
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <GameKit/GameKit.h>
@interface GameKitHelper : NSObject <GKLeaderboardViewControllerDelegate, GKAchievementViewControllerDelegate, GKMatchmakerViewControllerDelegate, GKMatchDelegate>{
    BOOL gameCenterAvailable;
    BOOL userAuthenticated;
}

@property (assign, readonly) BOOL gameCenterAvailable;

+ (GameKitHelper *)sharedGameKitHelper;
- (void)share;
- (void) authenticateLocalUser;
- (void) showLeaderboard;
- (void) reportChallengeScore:(uint32_t)score;    //上传得分
- (void) whetherChallengeHighestScores:(uint32_t)score;

- (void) reportArcadeScore:(uint32_t)score;    //上传得分
- (void) whetherArcadeHighestScores:(uint32_t)score;      //是否为最高得分
- (void) leaderboardViewControllerDidFinish:(GKLeaderboardViewController *)viewController;

@property (assign) BOOL isNewRecordArcade;
@property (assign) BOOL isNewRecordChallenge;


@end

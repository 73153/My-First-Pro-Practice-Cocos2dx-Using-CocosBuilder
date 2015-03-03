//
//  HoldOnModel.cpp
//  HoldOnDemo
//
//  Created by apple on 14/7/4.
//
//

#include "HoldOnModel.h"
#include "HoldOnConfig.h"
#include "SimpleAudioEngine.h"

#import "KENDataManager.h"
#import "GameKitHelper.h"
#import "RootViewController.h"
#import "ObjCCalls.h"
#import "Reachability.h"

static HoldOnModel* s_ShareModel = NULL;

HoldOnModel* HoldOnModel::shareModel(){
    if (!s_ShareModel) {
        s_ShareModel = new HoldOnModel();
    }
    
    return s_ShareModel;
}
HoldOnModel::HoldOnModel()
: arcadeGameScore(0),challengeGameScore(0)

{
    
};

HoldOnModel::~HoldOnModel(){
    
}

void HoldOnModel::initData(){
    //初始数据
    
    
    if ([KENDataManager getDataByKey:KArcadeBestScore] == nil) {
        [KENDataManager setDataByKey:[NSNumber numberWithInt:0] forkey:KArcadeBestScore];
    }
    
    if ([KENDataManager getDataByKey:KChallengeBestScore] == nil) {
        [KENDataManager setDataByKey:[NSNumber numberWithInt:0] forkey:KChallengeBestScore];
    }
    //初始友盟统计
    //    [MobClick setCrashReportEnabled:NO]; // 如果不需要捕捉异常，注释掉此行
    //    [MobClick setLogEnabled:YES];  // 打开友盟sdk调试，注意Release发布时需要注释掉此行,减少io消耗
    //    [MobClick setAppVersion:XcodeAppVersion]; //参数为NSString * 类型,自定义app版本信息，如果不设置，默认从CFBundleVersion里取
    
    //    if (IsPad) {
    //        [MobClick startWithAppkey:@"53bcd08356240bf086045566"];
    //    } else {0    //        [MobClick startWithAppkey:@"53bcd00d56240b0c1b01f0c4"];
    //    }
    
    //初始全屏广告
    //    [SysDelegate.viewController initFullMogo];
}



void HoldOnModel::checkCurrentNetStatus(){
    Reachability *reach = [Reachability reachabilityWithHostName:@"www.baidu.com"];
    switch ([reach currentReachabilityStatus]) {
        case ReachableViaWiFi:{
        }
            break;
        case ReachableViaWWAN:{
        }
            break;
        case NotReachable:
        default:{
        }
            break;
    }
}

void HoldOnModel::showGameCenterLoader(){
    //显示排行榜
    [[GameKitHelper sharedGameKitHelper] showLeaderboard];
}

void HoldOnModel::reportArcadeScore(){
    
    isConnectToInternet = ObjCCalls::tryIsInternetConnection();
    
    if(isConnectToInternet==true)
    {
        int bestScore = [[KENDataManager getDataByKey:KArcadeBestScore] intValue];
        CCLOG("arcadeGameScore %d",arcadeGameScore);
        if (arcadeGameScore > bestScore) {
            bestScore = arcadeGameScore;
            [KENDataManager setDataByKey:[NSNumber numberWithInt:arcadeGameScore] forkey:KArcadeBestScore];
            
            [[GameKitHelper sharedGameKitHelper] whetherArcadeHighestScores:arcadeGameScore];
        } else {
            [[GameKitHelper sharedGameKitHelper] setIsNewRecordArcade:NO];
        }
        
        [[GameKitHelper sharedGameKitHelper] reportArcadeScore:bestScore];
    }
    
}

void HoldOnModel::setArcadeGameHighestScore(int score)
{
    arcadeGameScore=score;
}

void HoldOnModel::reportChallengeScore(){
    
    isConnectToInternet = ObjCCalls::tryIsInternetConnection();
    if(isConnectToInternet==true){
        int bestScore = [[KENDataManager getDataByKey:KChallengeBestScore] intValue];
        CCLOG("KChallengeBestScore %d",challengeGameScore);
        if (challengeGameScore > bestScore) {
            bestScore = challengeGameScore;
            [KENDataManager setDataByKey:[NSNumber numberWithInt:challengeGameScore] forkey:KChallengeBestScore];
            
            [[GameKitHelper sharedGameKitHelper] whetherChallengeHighestScores:challengeGameScore];
        } else {
            [[GameKitHelper sharedGameKitHelper] setIsNewRecordChallenge:NO];
        }
        [[GameKitHelper sharedGameKitHelper] reportChallengeScore:bestScore];
    }
    
}

void HoldOnModel::setChallengeGameHighestScore(int score){
    challengeGameScore=score;
}


bool HoldOnModel::getIsNewRecordArcade(){
    return [[GameKitHelper sharedGameKitHelper] isNewRecordArcade];
}
bool HoldOnModel::getIsNewRecordChallenge(){
    return [[GameKitHelper sharedGameKitHelper] isNewRecordChallenge];
}
bool HoldOnModel::isPad(){
    return IsPad;
}

bool HoldOnModel::isLanguageEnglish(){
    NSUserDefaults* defs = [NSUserDefaults standardUserDefaults];
    NSArray* languages = [defs objectForKey:@"AppleLanguages"];
    NSString* preferredLang = [languages objectAtIndex:0];
    if ([preferredLang compare:@"zh-Hans"] == NSOrderedSame) {
        return false;
    } else {
        return true;
    }
}

#pragma mark - music
void HoldOnModel::stopBackgroundMusic(){
    CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
}

void HoldOnModel::stopEffect(unsigned int nSoundId){
    CocosDenshion::SimpleAudioEngine::sharedEngine()->stopEffect(nSoundId);
}

#pragma mark - score
void HoldOnModel::resetLevelScore(){
    arcadeGameScore = 0;
    challengeGameScore=0;
}


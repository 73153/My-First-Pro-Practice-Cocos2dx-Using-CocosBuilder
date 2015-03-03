//
//  HoldOnModel.h
//  HoldOnDemo
//
//  Created by ken on 14/7/4.
//
//

#ifndef  _HOLDONMODEL_H_
#define  _HOLDONMODEL_H_

#include "cocos2d.h"

class  HoldOnModel
{
public:
    HoldOnModel();
    virtual ~HoldOnModel();
    
    static HoldOnModel* shareModel(void);
    
public:
    void checkCurrentNetStatus();
    
    void reportArcadeScore();
    void reportChallengeScore();
    void showGameCenterLoader();
    
    void initData();
    bool isLanguageEnglish();
    bool isPad();
    
    //music         参考：http://www.2cto.com/kf/201306/217740.html
    void stopEffect(unsigned int nSoundId);
    void stopBackgroundMusic();
    
    void resetLevelScore();
    uint32_t getArcadegameScore(){return arcadeGameScore;}
    void setArcadeGameHighestScore(int score);
    
    uint32_t getChallengegameScore(){return challengeGameScore;}
    void setChallengeGameHighestScore(int score);
    
    bool getIsNewRecordArcade();
    bool getIsNewRecordChallenge();
    bool isConnectToInternet;
    
private:
    uint32_t arcadeGameScore;
    uint32_t challengeGameScore;
    
};

#endif // _HOLDONMODEL_H_

#ifndef __Noah360univarsal__GameManager__
#define __Noah360univarsal__GameManager__
#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "../Layers/AnimationLayer.h"
#include "../Layers/AnimationLayerLoader.h"
#include  "../GameManager/common_function.h"
#include "../SoundManager/SoundManager.h"
#include "../GameScreen/GameLayer.h"
#include "../GameScreen/GameLayerLoader.h"
#include "../Shapes/ShapeLayer.h"
#include "../Shapes/ShapeLayerLoader.h"
#include "../Layers/SettingLayer.h"
#include "../Layers/SettingLayerLoader.h"
#include "../Layers/MonumentSelectionLayer.h"
#include "../ArcadeMode/AnimationLayerLoaderArcadeMode.h"
#include "../ArcadeMode/AnimationLayerArcadeMode.h"
#include "../ArcadeMode/GameLayerArcadeMode.h"


USING_NS_CC;
USING_NS_CC_EXT;

#define EnglishLang "english"
#define SpanishLang "spanish"
#define SavedAppVersionCode "SavedAppVersion"
#define AppVersionCode "0.0.32"
#define elementStatusUnbought 1
#define elementStatusBoughtUnselected 2
#define elementStatusBoughtSelected 3
#define InkyAchievmentID 12
#define GuitarStarsAchievmentID 25
#define ForceFieldAchievmentID 11
#define GroupIDArks 1
#define GroupIDLoadingAnimals 2
#define GroupIDFishes 3
#define ExclusiveGroupIDArks 1
#define ExclusiveGroupIDStarSounds 2
#define screen_height  CCDirector::sharedDirector()->getWinSize().height
#define screen_width   CCDirector::sharedDirector()->getWinSize().width

typedef enum
{
    green,
    red,
    cloud
} branchType;
typedef enum
{
    TalktoUs,
    Feedback,
    share_mail
}emailType;

 static int resolution_type;
class GameManager
{
private:
    //Constructor
    GameManager();
    //Instance of the singleton
    static GameManager* m_mySingleton;
public:
    
    void initialize();
    void removeDataOnClick();
     CC_SYNTHESIZE(AnimationLayer *,animationLayerObj,animationLayerObj);
     CC_SYNTHESIZE(SettingLayer *,settingLayerObj,settingLayerObj);
      CC_SYNTHESIZE(AnimationLayerArcadeMode *,animationLayerArcadeModeObj,animationLayerArcadeModeObj);
//     CC_SYNTHESIZE(MonumentSelectionLayer *,monumentLayerObj,monumentLayerObj);
    //Get instance of singleton
    static GameManager* sharedGameManager();
    
    CC_SYNTHESIZE(CCInteger, current_scene,current_scene);
    CC_SYNTHESIZE(CCNode*, current_layer, current_layer);
    
    CCScene* get_scene(const char *pCCBFilename,const char *pCCNodename,CCNodeLoader *pCCNodeLoader,CCObject *objowner,bool hasfooter,bool hasheader);
    CCScene* get_scene_at(int nIndex);
    bool gotoNextScene();
    bool gotoPreviousScene();
    bool gotoScene(CCInteger index_scene);
    bool isSettingAndAnimationLayerAdded;
    
    void saveChallengeScoreHighestSortedUsersList(CCArray *arr);
    void saveArcadeScoreHighestSortedUsersList(CCArray *sortedUsersArray);

    //memory management...
    void remove_unused_data();
    
    bool isNodeAtPoint(cocos2d::CCNode* node, cocos2d::CCPoint& touchLocation);
    bool isTouchOnArea(CCPoint touch ,CCPoint center,float width,float height);
    bool isTouchOnAreaFromGimp(CCPoint touch ,CCPoint center,float width,float height);
    int get_devise_resolution();
    void set_devise_resolution(int resolution);
   
    CCArray* shuffle_array(CCArray *pArray, unsigned int nLen);
    
    void read_data();
    
    void setLastPlayedLevel(int level);
    int getLastPlayedLevel();
    
    void AddPoints(int morePoints);
    void saveMutedFX(bool mute);
    void saveMutedNarrator(bool mute);
    
    
    void save_ChallengeCurrentUserScore(CCDictionary *user);
    void save_ArcadeCurrentUserScore(CCDictionary *user);
    CCArray*  get_Challenge_userslist();
    CCArray*  get_Arcade_userslist();
    
    void saveCoinsCount(int coinNumber);
     CC_SYNTHESIZE(int, coinCountNumber, coinCountNumber);
    CC_SYNTHESIZE(int, points, points);
    CC_SYNTHESIZE(int, level, level);
    CC_SYNTHESIZE(int, numberOfUsers, numberOfUsers);
    CC_SYNTHESIZE(int, highestPlayedLevel, highestPlayedLevel);

    CC_SYNTHESIZE(bool, mutedFX, mutedFX);
    CC_SYNTHESIZE(bool, social, social);
    CC_SYNTHESIZE(bool, mutedNarrator, mutedNarrator);
    CC_SYNTHESIZE(bool , isAuthenticatedUser, isAuthenticatedUser);
    
    CC_SYNTHESIZE(CCArray *, challenge_existing_usersArr, challenge_existing_usersArr);
    CC_SYNTHESIZE(CCArray *, arcade_existing_usersArr, arcade_existing_usersArr);

    
    //Star implementaion
    CC_SYNTHESIZE(CCArray*, starStoreElements, starStoreElements);
    CCArray* sortArray(CCArray *aArray);
    CCArray*  getStarsCount_list();
    int save_LastPlayedLavel(int index,int starCount,int isLevelCleared);
    
    int getStarCountAccordingToLevel(int index);
    int getcurrentLevel(int currentLevel);
    int getIsLevelCleared(int currentLevelNumber);
    int getisInAppPurchased(int currentLevelNumber);
    
};
#endif /* defined(__Noah360univarsal__GameManager__) */

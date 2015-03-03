

#ifndef LeaderBoardLayer_H_
#define LeaderBoardLayer_H_

#include "cocos2d.h"
#include "cocos-ext.h"

using namespace cocos2d;
using namespace cocos2d::extension;


class LeaderBoardLayer:public cocos2d::CCLayer
,public cocos2d::extension::CCBSelectorResolver
,public cocos2d::extension::CCBMemberVariableAssigner
,public cocos2d::extension::CCNodeLoaderListener

{
public:
    
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(LeaderBoardLayer, create);
    //CCB methods...
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
    virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
    virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName);
    
    virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
    
	LeaderBoardLayer();
	 ~LeaderBoardLayer();
 
    cocos2d::extension::CCBAnimationManager *mAnimationManager;
    CCMenuItemImage *playIconMenuSpr;
    CC_SYNTHESIZE(CCLayerColor*, menuHomeLayer, menuHomeLayer);
    void onHomeClicked(CCObject* pSender);

    CCLabelTTF *leaderBoardLabel;
    CCLabelTTF *topFiveLabel;
      virtual bool init();
    //information screen
    bool is_info_showing;
    int resolutionInt;
    //select user from text field...
//    void on_user_clicked(cocos2d::CCObject * pSender);
    CCString *str_new_user;
    CCSprite *str_new_user_profile;
    CCSize winSize;
    
    CCArray* get_Challenge_userlist();
    void save_Challenge_user(CCDictionary *user);
    
    CCArray* get_Arcade_userlist();
    void save_Arcade_user(CCDictionary *user);
    CCSprite *trophySpr,*sideBarArcadeSpr,*sideBarChallengeSpr;
    
    CCLabelTTF *arcadeLabel,*challengeLabel;
    
    CCLabelTTF *highestScoreLabel,*highestScoreLabelNotUsed;
    CCMenuItemImage *sideBarArcadeMenuItemSpr,*sideBarChallengeMenuItemSpr;
    
    CCLayerColor *backLayer;
    
    void onsideBarArcadeMenuItemCicked(CCObject *sender);
    void onsideBarChallengeMenuItemClicked(CCObject *sender);
    void updateChallngeModeScore();
    void updateArcadeModeScore();
    
    CCLabelTTF *noScoreLabel;


};




#endif /* LeaderBoardLayer_H_ */



#ifndef MonumentSelectionLayer_H_
#define MonumentSelectionLayer_H_

#include "cocos2d.h"
#include "cocos-ext.h"
#include "../Layers/MenuLayer.h"
#include "../GameManager/GameManager.h"
#include "../CCPageControl/SelectLevel.h"
#include "../Layers/LevelSelectionLayer.h"
#include "../Layers/LevelSelectionLayerLoader.h"
#include "../Layers/MenuLayerLoader.h"

using namespace cocos2d;

class MonumentSelectionLayer: public cocos2d::CCLayer
,public cocos2d::extension::CCBSelectorResolver
,public cocos2d::extension::CCBMemberVariableAssigner
,public cocos2d::extension::CCNodeLoaderListener


 {
public:
	MonumentSelectionLayer();
	virtual ~MonumentSelectionLayer();
     CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(MonumentSelectionLayer, create);
     //CCB methods...
     virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
     virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
     virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
     virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
     virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
     virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName);
     cocos2d::extension::CCBAnimationManager *mAnimationManager;
     
     virtual void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
     
     virtual void onEnter();
     virtual void onExit();
     
     void playButtonPressed();
     void faceBookButtonPressed();
     void twitterButtonPressed();
     CCMenuItemImage *rightImageSpr;
     CCMenuItemImage *leftImageSpr;
     CCMenuItemImage *mainImageSpr;
     CCMenuItemImage *playButton;
     CCMenuItemImage *faceBookIconImageSpr;
     CCMenuItemImage *twitterIconImageSpr;
     CCMenuItemImage *homeButtonMenuItem;
     CCLabelTTF *followUsLbl;
     CCLayerColor *backgroundLayer;
     CCLayerColor *navHomeLayer;
     CCLayerColor *navigationLayer;
     CCSprite *mainSpr;
     CCSprite *leftSpr;
     CCSprite *rightSpr;
     CCMenu *fbTwShareMenu;
     
     CCMenuItemImage *twitterMenuItem,*facebookMenuItem,*shareMenuItem;
     
     bool tryIsInternetConnection();
     
     bool isSetVisiblity;
     bool isVisiblePlayButton;
     bool isFirstTimeLeftMenuClicked;
     void enableMainImageScale(CCMenuItemImage *mainImage);
     int clickCounter;
     void mainImageClicked(CCObject *sender);
     void leftMenuItemClicked(CCObject *sender);
     void rightMenuItemClicked(CCObject *sender);
     void applyEffectOnButton();
private:
     CLevelSelectLayer* clevelLayer;

	void initFaceBookAndTwitterButton();
	bool init();
	void onHomePressed(CCObject *sender);
	void initPlayButton();
	void initHighScore();
     void onShareButtonClicked();
};



#endif /* MonumentSelectionLayer_H_ */

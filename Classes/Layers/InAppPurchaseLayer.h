

#ifndef InAppPurchaseLayer_H_
#define InAppPurchaseLayer_H_

#include "cocos2d.h"
#include "cocos-ext.h"

using namespace cocos2d;
using namespace cocos2d::extension;


class InAppPurchaseLayer:public cocos2d::CCLayer
,public cocos2d::extension::CCBSelectorResolver
,public cocos2d::extension::CCBMemberVariableAssigner
,public cocos2d::extension::CCNodeLoaderListener

{
public:
    
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(InAppPurchaseLayer, create);
    //CCB methods...
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
    virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
    virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName);
    
    virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
    
     CC_SYNTHESIZE(cocos2d::extension::CCBAnimationManager *,mAnimationManager,mAnimationManager);
	InAppPurchaseLayer();
	 ~InAppPurchaseLayer();
    
    bool isRestorePurchased;
    
    int dollerLabel1Int,dollerLabel2Int,dollerLabel3Int,dollerLabel4Int,dollerLabel5Int,dollerLabel6Int;
    int bulletTimerCount,multiBallCount,autoPlayCount,bonusPointsCount,bonusLifeCount,largePaddleCounter;
    
    CCMenuItemImage *coinMenuSpr1,*coinMenuSpr2,*coinMenuSpr3,*coinMenuSpr4,*coinMenuSpr5,
    *coinMenuSpr6;
    
    int counter;
    void updateInterval();
    void updateScalingForFBAndCoin(CCMenuItemImage *coinSpr,CCMenuItemImage *faceBookSpr);
    CCLabelTTF *DayLabelNotUsed,*NightLabelNotUsed,*controlModeLabelNotUsed,*soundLabelNotUsed,*largePaddleLabel,*bonusPointLabel,*bonusLifeLabel,*autoPlayLabel,*multiBallLabel,*bulletLabel,*storeMainLbl;
    
    CCLabelTTF *dollerLabel1,*dollerLabel2,*dollerLabel3,*dollerLabel4,*dollerLabel5,*dollerLabel6,*totalCoinsCollected,*totalCoinsLabelNotUsed,*bulletLabelNotUsed,*multiBallLabelNotUsed,*autoPlayLabelNotUsed,*bonusLifeLabelNotUsed,*bonusPointLabelNotUsed,*laregPaddleLabelNotUsed;
    
    CCLabelTTF *coinsPackLabelUnused,*buyLabel,*powerUpsLabel,*unlockAllMonLabel;
    CCLabelTTF *buyLabelNotUsed1,*buyLabelNotUsed2,*buyLabelNotUsed3,*buyLabelNotUsed4,*buyLabelNotUsed5,*buyLabelNotUsed6,*buyLabelNotUsed7;
    CCLabelTTF *restoreLabelNotUsed,*unlockAllLabelNotUsed,*effielTowerLabelNotUsed,*statueOfLibertyLabelNotUsed,*towerOfPisaLabelNotUsed,*bigBenLabelNotUsed,*colosseumLabelNotUsed,*operaHouseLabelNotUsed,*easterStoneLabelNotUsed;
    
    
    CCMenuItemImage *buyMenuItem,*buyBtn1,*buyBtn2,*buyBtn3,*buyBtn4,*buyBtn5,*buyBtn6,*buyBtn7,*restoreMenuItemSpr,*unlockAllMenuItemSpr;
    
     CCLayerColor *bulletCoinLayer,*multiBallCoinLayer,*autoPlayCoinLayer,*bonusLifeCoinLayer,*bonusPointCoinLayer,*unlockAllMonumentsMainLayer,*laregPaddleLayer;
    
    CCLayerColor *effielLayer,*statueLayer,*towerLayer,*bigLayer,*colosseumLayer,*operaLayer,*easterLayer;
    CCLayerColor *buyLayer1,*buyLayer2,*buyLayer3,*buyLayer4,*buyLayer5,*buyLayer6,*buyLayer7,*coinLayer1,*coinLayer2,*coinLayer3,*coinLayer4,*coinLayer5,*coinLayer6;
    
    
    CCLayerColor *powerUpsMenuLayer,*unlockAllMonMenuLayer;
    CCLayerColor *menuBackLayer;
    void onBackClicked(CCObject* pSender);
    void onCoinPurchaseClicked(CCObject* pSender,int tag);
    void onUnlockAllMonumentsClicked(CCObject* pSender);
    void onBuyButtonClicked(CCObject* pSender,int tag);
    CCLayerColor *segmentControlLayer;
    CCLayerColor *powerUpsMainLayer;
    bool isCoinRequireUpdate;
    bool isPowerLayerVisible;
    bool isMonumentPurchased;
    bool isConnectToInternet;
    float buyLabelNotUsed1PosX;
    float buyLabelNotUsed2PosX;
    float buyLabelNotUsed3PosX;
    float buyLabelNotUsed4PosX;
    float buyLabelNotUsed5PosX;
    float buyLabelNotUsed6PosX;
    float buyLabelNotUsed7PosX;
    
private:
	bool init();
    
    void onBuyFiveHundredCoinsClicked(CCObject *sender);
    void onPowerUpsClicked(CCObject *sender);
    void onUnlockAllClicked(CCObject *sender);
    void onRestoreAllClicked(CCObject *sender);
    void CoinsPurchaseFinished();
    void MonumentPurchaseFinished();
    void updateUIAfterPurchase();
    void unLockReflectToAllMonuments();
    int volumeBackGroundCounter;
    int soundForGroundCounter;
    bool isForGroundHighVolume;
    bool isBackGroundHighVolume;

    
};

#endif /* InAppPurchaseLayer_H_ */

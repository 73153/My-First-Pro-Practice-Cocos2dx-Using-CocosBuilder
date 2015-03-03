

#ifndef HelpLayer_H_
#define HelpLayer_H_

#include "cocos2d.h"
#include "cocos-ext.h"

using namespace cocos2d;
using namespace cocos2d::extension;


class HelpLayer:public cocos2d::CCLayer
,public cocos2d::extension::CCBSelectorResolver
,public cocos2d::extension::CCBMemberVariableAssigner
,public cocos2d::extension::CCNodeLoaderListener, public cocos2d::extension::CCTableViewDataSource, public cocos2d::extension::CCTableViewDelegate

{
public:
    
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(HelpLayer, create);
    //CCB methods...
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual bool onAssignCCBMemberVariable(cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
    virtual void onNodeLoaded(cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader);
    virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName);
    
    virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
    
//    CC_SYNTHESIZE(bool, isSettingBtnClicked, isSettingBtnClicked);
	HelpLayer();
	 ~HelpLayer();
    bool isdetailBackLayer1Hidden,isdetailBackLayer2Hidden,isdetailBackLayer3Hidden,isdetailBackLayer4Hidden,isdetailBackLayer5Hidden,isdetailBackLayer6Hidden,isdetailBackLayer7Hidden,isdetailBackLayer8Hidden,isdetailBackLayer9Hidden,isdetailBackLayer10Hidden;
    CCLayerColor *detailBackLayer1,*detailBackLayer2,*detailBackLayer3,*detailBackLayer4,*detailBackLayer5,*detailBackLayer6,*detailBackLayer7,*detailBackLayer8,*detailBackLayer9,
    *detailBackLayer10;
    
    CCLayerColor *powerInformationLayer;
    CCLayerColor *menuBackButtonLayer;
    
    CCLabelTTF *shortPaddleLbl,*reverseBallLbl,*magnetLbl,*slowBallLbl,*largePaddleLbl,*bonusPointLbl,
    *bonusLifeLbl,*autoPlayLbl,*multiBallLbl,*bulletLbl,*powerMainLabel;

    cocos2d::extension::CCBAnimationManager *mAnimationManager;
    
    CCMenuItemImage *playIconMenuSpr;
    CCLayerColor *menuHomeLayer;
    void onDetailShowPressed(CCObject* pSender);
    void onHomeClicked(CCObject* pSender);
    void onFacebookClicked(CCObject* pSender);
    void onCoinPurchaseClicked(CCObject* pSender);
    void onPowerInfoPressed(CCObject* pSender);
    void onBackButtonClicked(CCObject *pSender);
    //    void	setDelegate ( HelpLayerDelegate* pDelegate );
//    HelpLayerDelegate *settingDelegte;
    CCLabelTTF *DayLabelNotUsed;
    CCLabelTTF *NightLabelNotUsed;
    CCLabelTTF *controlModeLabelNotUsed;
    CCLabelTTF *soundLabelNotUsed;
    
//	CC_SYNTHESIZE(CCMenu*, controlModeNight,controlModeNight);
//	CC_SYNTHESIZE(CCMenu* ,controlModeDay,controlModeDay);
//	CC_SYNTHESIZE(CCMenu*, controlModeTouch,controlModeTouch);
////    CC_SYNTHESIZE(CCLabelTTF *,grvityControlLbl,grvityControlLbl);
//    CC_SYNTHESIZE(CCMenuItemImage*, settingBtn, settingBtn);
//    
//    CC_SYNTHESIZE(CCLayerColor*, settingBtnLayer, settingBtnLayer);
//    CC_SYNTHESIZE(CCLayerColor*, settingScreenlayer, settingScreenlayer);
    
    
    // table view delegates....
    
    CCTableView* tableView;
    virtual void scrollViewDidScroll(cocos2d::extension::CCScrollView* view) {};
    virtual void scrollViewDidZoom(cocos2d::extension::CCScrollView* view) {}
    virtual void tableCellTouched(cocos2d::extension::CCTableView* table, cocos2d::extension::CCTableViewCell* cell);
    virtual cocos2d::CCSize cellSizeForTable(cocos2d::extension::CCTableView *table);
    virtual cocos2d::extension::CCTableViewCell* tableCellAtIndex(cocos2d::extension::CCTableView *table, unsigned int idx);
    virtual unsigned int numberOfCellsInTableView(cocos2d::extension::CCTableView *table);
    
    int resolutionInt;
    
  
    
private:
	bool init();
    cocos2d::CCArray* m_pRecipes;
    void nextScene(int nIndex, int nStep=0);
    int m_iTouchIndex;
    int volumeBackGroundCounter;
    int soundForGroundCounter;
    bool isForGroundHighVolume;
    bool isBackGroundHighVolume;
//
//    
//	static int sensitivity;
//	static ControlType controlMode;
//	
//    void settingBtnClicked(CCObject* pSender);
//	 bool ccTouchBegan(CCTouch * pTouch, CCEvent * pEvent);
    
};

//class HelpLayerDelegate
//{
//    public :
//    virtual void        removeAllChildern(void)=0;
//    virtual void        pauseTheGame(void)=0;
//    virtual void        resumeTheGame(void)=0;
//};

#endif /* HelpLayer_H_ */

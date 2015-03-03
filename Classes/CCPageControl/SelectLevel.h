

#ifndef __AA__SelectLevel__
#define __AA__SelectLevel__

#include <iostream>
#include "../CCPageControl/CCNewScrollView.h"
#include "cocos2d.h"
#include "../CCPageControl/CCPageControl.h"
#include "../AppDelegate/AppMacros.h"
using namespace cocos2d;
class CLevelSelectLayer
: public cocos2d::CCLayer
, public CCNewScrollViewDelegate{
public:
    CCCGameScrollView* m_ScrollView;
    cocos2d::CCArray* dataArr;
    CCLabelTTF *monumentLabel;
    CCLabelTTF *monumentStageLabel;
    CCLayer *playeButtonlayer;
    cocos2d::CCArray* spriteArray;
    virtual bool init();
    ~CLevelSelectLayer();
    void onEnter();
    void onExit();
    void scalePage();
    CCSize winsize;
    CC_SYNTHESIZE(int, currentPage, currentPage);
    bool m_bTouchedMenu;
    bool isPageGotChanged;
    int lastScrolledPageCount;
    CREATE_FUNC(CLevelSelectLayer);
    CCSize windowSize;
    TargetPlatform detectedDevice;
    
    virtual void scrollViewDidScroll( cocos2d::extension::CCScrollView* view );
    
    virtual void scrollViewDidZoom( cocos2d::extension::CCScrollView* view );
    
    virtual bool scrollViewInitPage( cocos2d::CCNode* pPage,int nPage );
    
    virtual void scrollViewClick( const cocos2d::CCPoint& oOffset,const cocos2d::CCPoint & oPoint ,cocos2d::CCNode * pPage,int nPage );
    CCMenu* playButton;
    virtual void scrollViewScrollEnd( cocos2d::CCNode * pPage,int nPage );
    virtual void scrollViewPageChangedOrNot(bool isPageChanged);

    void levelSelectButtonPressed(CCObject *sender);
    virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    CC_SYNTHESIZE(CCPageControl*, pageControl, pageControl);
    virtual void setThePageControlToCurrentPage(int page);
    
    
    
private:
    
};
#endif /* defined(__AA__SelectLevel__) */

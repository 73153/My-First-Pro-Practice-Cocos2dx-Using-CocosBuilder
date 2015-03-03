

#include "../CCPageControl/CCNewScrollView.h"

#include "../GameManager/GameManager.h"

USING_NS_CC;
USING_NS_CC_EXT;

CCCGameScrollView::CCCGameScrollView()
:m_fAdjustSpeed(ADJUST_ANIM_VELOCITY)
, m_nPrePage(0)
{
    
}

CCCGameScrollView::~CCCGameScrollView()
{
    removeAllChildrenWithCleanup(true);
}

bool CCCGameScrollView::init()
{
    if (!CCScrollView::init())
    {
        return false;
    }
    //    CCMenuItemFont *okMenuItem = CCMenuItemFont::create("OK", this, menu_selector(CCCGameScrollView::okMenuItemCallback));
    //    okMenuItem->setFontSizeObj(50);
    //    okMenuItem->setPosition(ccp(200, 200));
    //    CCMenu *m_pMenu = CCMenu::create(okMenuItem, NULL);
    //    m_pMenu->setPosition(CCPointZero);
    //    this->addChild(m_pMenu);
    this->setTouchEnabled(true);
    return true;
}
void CCCGameScrollView::okMenuItemCallback(cocos2d::CCObject *pSender)
{
    //    this->removeFromParentAndCleanup(false);
}

bool CCCGameScrollView::ccTouchBegan( CCTouch *pTouch, CCEvent *pEvent )
{
    m_BeginOffset = getContentOffset();
    return CCScrollView::ccTouchBegan(pTouch, pEvent);
}

void CCCGameScrollView::ccTouchMoved( CCTouch *pTouch, CCEvent *pEvent )
{
    CCScrollView::ccTouchMoved(pTouch, pEvent);
}

void CCCGameScrollView::ccTouchEnded( CCTouch *pTouch, CCEvent *pEvent )
{
    CCPoint touchPoint = pTouch->getLocationInView();
    touchPoint = CCDirector::sharedDirector()->convertToGL( touchPoint );
    
    CCScrollView::ccTouchEnded(pTouch, pEvent);
    
    CCPoint m_EndOffset=getContentOffset();
    
    if (m_BeginOffset.equals(m_EndOffset))
    {
        int nPage = abs(m_EndOffset.x / (int)m_CellSize.width);
        CCNewScrollViewDelegate* pDele=(CCNewScrollViewDelegate*)m_pDelegate;
        pDele->scrollViewClick(m_EndOffset,touchPoint,m_pContainer->getChildByTag(nPage),nPage);
        return ;
    }
    
    adjustScrollView(m_BeginOffset,m_EndOffset);
}

void CCCGameScrollView::ccTouchCancelled( CCTouch *pTouch, CCEvent *pEvent )
{
    CCScrollView::ccTouchCancelled(pTouch, pEvent);
    
    CCPoint m_EndOffset=getContentOffset();
    adjustScrollView(m_BeginOffset,m_EndOffset);
}

void CCCGameScrollView::adjustScrollView( const cocos2d::CCPoint& oBegin,const cocos2d::CCPoint & oEnd)
{
    int nPage = abs(oBegin.x / (int)m_CellSize.width);
    
    int nAdjustPage = 0;
    
    int nDis = oEnd.x-oBegin.x;
    if (nDis<-getViewSize().width/5)
    {
        nAdjustPage=nPage+1;
        CCNewScrollViewDelegate* pDele=(CCNewScrollViewDelegate*)m_pDelegate;
        pDele->scrollViewPageChangedOrNot(true);
    }
    else if (nDis>getViewSize().width/5)
    {
        nAdjustPage=nPage-1;
        CCNewScrollViewDelegate* pDele=(CCNewScrollViewDelegate*)m_pDelegate;
        pDele->scrollViewPageChangedOrNot(true);
    }
    else
    {
        nAdjustPage=nPage;
    }
    
    nAdjustPage=MIN(nAdjustPage,m_nPageCount-1);
    nAdjustPage=MAX(nAdjustPage,0);
    
    scrollToPage(nAdjustPage);
}

void CCCGameScrollView::scrollToPage( int nPage )
{
    unscheduleAllSelectors();
    
    CCNewScrollViewDelegate* pDele=(CCNewScrollViewDelegate*)m_pDelegate;
    pDele->scrollViewScrollEnd(m_pContainer->getChildByTag(nPage),nPage);
    
    CCPoint oOffset=getContentOffset();
    CCPoint adjustPos=ccp(-m_CellSize.width*nPage,0);
    
    float adjustAnimDelay=ccpDistance(adjustPos,oOffset)/m_fAdjustSpeed;
    
    setContentOffsetInDuration(adjustPos, adjustAnimDelay);
    
    if (nPage!=m_nPrePage)
    {
        schedule(schedule_selector(CCCGameScrollView::onScrollEnd),adjustAnimDelay,0,0.0f);
        m_nPrePage=nPage;
    }
}

void CCCGameScrollView::onScrollEnd(float fDelay)
{
    int nPage=getCurPage();
    CCNewScrollViewDelegate* pDele=(CCNewScrollViewDelegate*)m_pDelegate;
    pDele->scrollViewScrollEnd(m_pContainer->getChildByTag(nPage),nPage);
}

void CCCGameScrollView::scrollToNextPage()
{
    int nCurPage=getCurPage();
    if (nCurPage>=m_nPageCount-1)
    {
        return ;
    }
    scrollToPage(nCurPage+1);
}

void CCCGameScrollView::scrollToPrePage()
{
    int nCurPage=getCurPage();
    if (nCurPage<=0)
    {
        return ;
    }
    scrollToPage(nCurPage-1);
}

bool CCCGameScrollView::createContainer(CCNewScrollViewDelegate* pDele, int nCount,const cocos2d::CCSize oSize )
{
    m_nPageCount=nCount;
    m_CellSize=oSize;
    setDelegate(pDele);
    
    CCLayer* pContainer=CCLayer::create();
    pContainer->setAnchorPoint(CCPointZero);
    pContainer->setPosition(CCPointZero);
    
    CCSize winSize=CCDirector::sharedDirector()->getWinSize();
    pContainer->setContentSize(CCSizeMake((oSize.width*nCount),oSize.height));
    
    
    for (int i=0;i<nCount;++i)
    {
        CCNode* pNode=CCNode::create();
        
        switch (GameManager::sharedGameManager()->get_devise_resolution())
        {
            case 1:
            {
                pNode->setScale(1, 0.937);
                pNode->setPosition(ccp(winSize.width/2+i*oSize.width,(winSize.height/2)-70));
            }
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136){
                    pNode->setScale(0.76, 0.815);
                    pNode->setPosition(ccp(((winSize.width)/2+(i*oSize.width))+4,(winSize.height/2)-9));
                }
                else{
                    pNode->setScale(1, 0.95);
                    pNode->setPosition(ccp(((winSize.width/2+(i*winSize.width))),(winSize.height/2)-40));
                }
            }
                break;
            case 3:
            {
               pNode->setScale(0.83, 0.895);
                pNode->setPosition(ccp(((winSize.width/2+(i*winSize.width))),(winSize.height/2)-76));
            }
                break;
            case 4:
            {
                pNode->setScale(0.8, 0.8);
                pNode->setPosition(ccp(((winSize.width/2+(i*winSize.width))),(winSize.height/2)));
            }
                break;
            case 5:
            {
                pNode->setScale(1, 1.16);
                pNode->setPosition(ccp(((winSize.width)/2+(i*oSize.width))+9,(winSize.height/2)-12));
            }
                break;
            case 6:
            {
                pNode->setScale(0.79, 0.87);
                pNode->setPosition(ccp(((winSize.width)/2+(i*oSize.width))+30,(winSize.height/2)-38));
            }
                break;
            default:
                break;
        }
        pDele->scrollViewInitPage(pNode,i);
        pNode->setTag(i);
        pContainer->addChild(pNode);
    }
    setContainer(pContainer);
    int currentStageNumber =  CCUserDefault::sharedUserDefault()->getIntegerForKey("CLICKCOUNTER");
    if(currentStageNumber<=10 && currentStageNumber>=0){
        currentStageNumber=currentStageNumber-1;
        if(currentStageNumber<0)
            currentStageNumber=0;
        CCNewScrollViewDelegate* pDele=(CCNewScrollViewDelegate*)m_pDelegate;
        pDele->setThePageControlToCurrentPage(currentStageNumber);
        CCPoint adjustPos=ccp(-m_CellSize.width*currentStageNumber,0);
        setContentOffsetInDuration(adjustPos, 0);
    }
    CCLOG("currentStageNumber %d",currentStageNumber);
    return true;
}

int CCCGameScrollView::getCurPage()
{
    return abs(getContentOffset().x / (int)m_CellSize.width);
}
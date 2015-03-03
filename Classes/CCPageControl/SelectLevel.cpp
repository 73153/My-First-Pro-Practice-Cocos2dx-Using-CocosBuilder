

#include "../CCPageControl/SelectLevel.h"
#include "cocos2d.h"
#include "../Layers/LevelSelectionLayer.h"
#include "../Layers/LevelSelectionLayerLoader.h"
#include "../GameManager/GameManager.h"
USING_NS_CC;
USING_NS_CC_EXT;
#define LevelCount  8
#define BAGROW 4
#define BAGCOL 3

CLevelSelectLayer:: ~CLevelSelectLayer(){
    
    removeAllChildrenWithCleanup(true);
    dataArr->release();
    spriteArray->release();
}
bool CLevelSelectLayer::init()
{
    if (!CCLayer::init())
    {
        return false;
    }
    detectedDevice = CCApplication::sharedApplication()->getTargetPlatform();
    
    windowSize = CCDirector::sharedDirector()->getWinSize();
    CCSize localWinSize = windowSize;
    
    isPageGotChanged=false;
    dataArr = CCArray::create(CCString::create("mon-1.png"),CCString::create("mon-2.png"),CCString::create("mon-3.png"),CCString::create("mon-4.png"),CCString::create("mon-5.png"),CCString::create("mon-6.png"),CCString::create("mon-7.png"),CCString::create("cs_bg.png"),NULL);
    dataArr->retain();
    
    
    spriteArray = CCArray::create();
    spriteArray->retain();
    
    monumentLabel =CCLabelTTF::create("EIFFEL TOWER","fonts/Zekton-Bold.ttf", 40);
    monumentStageLabel = CCLabelTTF::create("1","fonts/Zekton-Bold.ttf", 40);
    
    CCLabelTTF *editMonuentlabel = (CCLabelTTF*)monumentLabel;
    CCLabelTTF *editmonumentStageLabel =(CCLabelTTF*)monumentStageLabel;
    editMonuentlabel->setOpacity(150);
    editmonumentStageLabel->setOpacity(150);
    int stageCount =   CCUserDefault::sharedUserDefault()->getIntegerForKey("CLICKCOUNTER");
    
    if(stageCount==1 || stageCount==0){
        //        editMonuentlabel->setColor(ccBLACK);
        editMonuentlabel->setString("EIFFEL TOWER");
        editmonumentStageLabel->setVisible(true);
        editmonumentStageLabel->setString("1");
    }
    else if(stageCount==2){
        //        editMonuentlabel->setColor(ccWHITE);
        editMonuentlabel->setString("STATUE OF LIBERTY");
        editmonumentStageLabel->setVisible(true);
        editmonumentStageLabel->setString("2");}
    else if(stageCount==3){
        //        editMonuentlabel->setColor(ccWHITE);
        editMonuentlabel->setString("TOWER OF PISA");
        editmonumentStageLabel->setVisible(true);
        editmonumentStageLabel->setString("3");}
    else if(stageCount==4){
        //        editMonuentlabel->setColor(ccWHITE);
        editMonuentlabel->setString("BIG BEN");
        editmonumentStageLabel->setVisible(true);
        editmonumentStageLabel->setString("4");}
    else if(stageCount==5){
        //        editMonuentlabel->setColor(ccBLACK);
        editMonuentlabel->setString("COLOSSEUM");
        editmonumentStageLabel->setVisible(true);
        editmonumentStageLabel->setString("5");}
    else if(stageCount==6){
        //        editMonuentlabel->setColor(ccWHITE);
        editMonuentlabel->setString("OPERA HOUSE");
        editmonumentStageLabel->setVisible(true);
        editmonumentStageLabel->setString("6");}
    else if(stageCount==7){
        //        editMonuentlabel->setColor(ccWHITE);
        editMonuentlabel->setString("EASTER STONE");
        editmonumentStageLabel->setVisible(true);
        editmonumentStageLabel->setString("7");}
    else{
        editmonumentStageLabel->setVisible(false);
    }
    
    switch (GameManager::sharedGameManager()->get_devise_resolution())
    {
        case 1:
            editmonumentStageLabel->setPosition(ccp(localWinSize.width-100,localWinSize.height-62));
            editMonuentlabel->setPosition(ccp(localWinSize.width/2,localWinSize.height-62));
            editMonuentlabel->setFontSize(65);
            editmonumentStageLabel->setFontSize(90);
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136){
                editMonuentlabel->setFontSize(30);
                editmonumentStageLabel->setFontSize(50);
                editmonumentStageLabel->setPosition(ccp(localWinSize.width-80,localWinSize.height-35));
                editMonuentlabel->setPosition(ccp(localWinSize.width/2,localWinSize.height-35));
            }
            else{
                editMonuentlabel->setFontSize(30);
                editmonumentStageLabel->setFontSize(50);
                editmonumentStageLabel->setPosition(ccp(localWinSize.width-100,localWinSize.height-35));
                editMonuentlabel->setPosition(ccp(localWinSize.width/2,localWinSize.height-35));
            }
        }
            break;
        case 3:{
            editMonuentlabel->setFontSize(30);
            editmonumentStageLabel->setFontSize(50);
            editmonumentStageLabel->setPosition(ccp(localWinSize.width-100,localWinSize.height-35));
            editMonuentlabel->setPosition(ccp(localWinSize.width/2,localWinSize.height-35));
        }
            
            break;
        case 4:{
            editMonuentlabel->setFontSize(30);
            editmonumentStageLabel->setFontSize(50);
            editmonumentStageLabel->setPosition(ccp(localWinSize.width-100,localWinSize.height-35));
            editMonuentlabel->setPosition(ccp(localWinSize.width/2,localWinSize.height-35));
        }
            break;
        case 5:{
            editMonuentlabel->setFontSize(30);
            editmonumentStageLabel->setFontSize(50);
            editmonumentStageLabel->setPosition(ccp(localWinSize.width-100,localWinSize.height-35));
            editMonuentlabel->setPosition(ccp(localWinSize.width/2,localWinSize.height-35));
        }
            break;
        case 6:
            editMonuentlabel->setPosition(ccp(localWinSize.width/2,localWinSize.height-62));
            editMonuentlabel->setFontSize(55);
            editmonumentStageLabel->setPosition(ccp(localWinSize.width-100,localWinSize.height-62));
            editmonumentStageLabel->setFontSize(80);
            break;
            
        default:
            break;
    }
    
    editMonuentlabel->setColor(ccc3(0, 0, 0));
    editmonumentStageLabel->setColor(ccc3(0, 0, 0));
    this->addChild(monumentLabel,500);
    this->addChild(monumentStageLabel,500);
    
    // CCScrollView
    m_ScrollView = CCCGameScrollView::create();
    
    m_ScrollView->createContainer(
                                  this,
                                  LevelCount,
                                  localWinSize);
    m_ScrollView->setPosition(ccp(0,0));
    m_ScrollView->setContentOffset(CCPointZero);
    m_ScrollView->setViewSize(CCDirector::sharedDirector()->getVisibleSize());
    m_ScrollView->setDirection(kCCScrollViewDirectionHorizontal);  //
    
    this->addChild(m_ScrollView);
    
    return true;
}


bool CLevelSelectLayer::scrollViewInitPage( cocos2d::CCNode* pPage,int nPage )
{
    CCString* helpstr = (CCString*)dataArr->objectAtIndex(nPage);
    

    CCSprite *sprite = CCSprite::create(helpstr->getCString());
    //    sprite->setScale(0.5);
    spriteArray->addObject(sprite);
    pPage->addChild(sprite);
    //    CCScaleTo *zoom = CCScaleTo::create(1, 1);
    //    sprite->runAction(zoom);
    
    //    CCScaleTo *playButtonZoom = CCScaleTo::create(0.5, 1);
    //    playButton->runAction(playButtonZoom);
    //
    
    pageControl = CCPageControl::create();
    pageControl->setNumberOfPages(nPage+1);
    pageControl->setCurrentPage(nPage);
    pageControl->setHidesForSinglePage(false);
    Resource ipad_HD = resources_ipad;
    CCSize localWinSize= windowSize;
    switch (GameManager::sharedGameManager()->get_devise_resolution())
    {
        case 1:{
            pageControl->setPosition(ccp(520,50));
        }
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136){
                sprite->setPositionY(40);
                pageControl->setPosition(ccp(200,50));
            }
            else{
                pageControl->setPosition(ccp(490/2,50/2));
            }
        }
            break;
        case 3:{
            sprite->setPositionY(40);
            pageControl->setPosition(ccp(210,30));
        }
            
            break;
        case 4:{
            pageControl->setPosition(ccp(160,50));
            sprite->setPositionY(40);
        }
            
            break;
        case 5:{
            pageControl->setPosition(ccp(230,50));
        }
            
            break;
        case 6:{
            sprite->setPositionY(50);
            pageControl->setPosition(ccp(450,50));
        }
            break;
            
        default:
            break;
    }
    this->addChild(pageControl,10);
    
    CCLayerColor *pageControlBackLayer = CCLayerColor::create();
    pageControlBackLayer->setColor(ccBLACK);
    pageControlBackLayer->setOpacity(30);
    switch (GameManager::sharedGameManager()->get_devise_resolution())
    {
        case 1:
            pageControlBackLayer->setContentSize(CCSizeMake(localWinSize.width, 150));
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136){
                pageControlBackLayer->setContentSize(CCSizeMake(localWinSize.width, 130));
            }
            else{
                pageControlBackLayer->setContentSize(CCSizeMake(localWinSize.width, 75));
            }
        }
            break;
        case 3:
            pageControlBackLayer->setContentSize(CCSizeMake(localWinSize.width, 75));
            break;
        case 4:
            pageControlBackLayer->setContentSize(CCSizeMake(localWinSize.width, 75));
            break;
        case 5:
            pageControlBackLayer->setContentSize(CCSizeMake(localWinSize.width, 130));
            break;
        case 6:
            pageControlBackLayer->setContentSize(CCSizeMake(localWinSize.width, 150));
            break;
        default:
            break;
    }
    
    pageControlBackLayer->setPosition(CCPointZero);
    this->addChild(pageControlBackLayer,pageControl->getZOrder()-1);
    
    
    return true;
}

void CLevelSelectLayer::scrollViewPageChangedOrNot(bool isPageChanged)
{
    isPageGotChanged = isPageChanged;
}


void CLevelSelectLayer::scrollViewScrollEnd( cocos2d::CCNode * pPage,int nPage )
{
    if(isPageGotChanged==false)
        return;
    scalePage();
    CCLabelTTF *editMonuentlabel = (CCLabelTTF*)monumentLabel;
    CCLabelTTF *editmonumentStageLabel =(CCLabelTTF*)monumentStageLabel;
    if(nPage==0){
        //        editMonuentlabel->setColor(ccBLACK);
        editMonuentlabel->setString("EIFFEL TOWER");
        editmonumentStageLabel->setVisible(true);
        editmonumentStageLabel->setString("1");}
    else if(nPage==1){
        //        editMonuentlabel->setColor(ccWHITE);
        editMonuentlabel->setString("STATUE OF LIBERTY");
        editmonumentStageLabel->setVisible(true);
        editmonumentStageLabel->setString("2");}
    else if(nPage==2){
        //        editMonuentlabel->setColor(ccWHITE);
        editMonuentlabel->setString("TOWER OF PISA");
        editmonumentStageLabel->setVisible(true);
        editmonumentStageLabel->setString("3");}
    else if(nPage==3){
        //        editMonuentlabel->setColor(ccWHITE);
        editMonuentlabel->setString("BIG BEN");
        editmonumentStageLabel->setVisible(true);
        editmonumentStageLabel->setString("4");}
    else if(nPage==4){
        //        editMonuentlabel->setColor(ccBLACK);
        editMonuentlabel->setString("COLOSSEUM");
        editmonumentStageLabel->setVisible(true);
        editmonumentStageLabel->setString("5");}
    else if(nPage==5){
        //        editMonuentlabel->setColor(ccWHITE);
        editMonuentlabel->setString("OPERA HOUSE");
        editmonumentStageLabel->setVisible(true);
        editmonumentStageLabel->setString("6");}
    else if(nPage==6){
        //        editMonuentlabel->setColor(ccWHITE);
        editMonuentlabel->setString("EASTER STONE");
        editmonumentStageLabel->setVisible(true);
        editmonumentStageLabel->setString("7");}
    else if(nPage==7){
        //        editMonuentlabel->setColor(ccBLACK);
        editMonuentlabel->setString("TO BE CONTINUED......");
        editmonumentStageLabel->setVisible(false);}
    
    isPageGotChanged=false;
    pageControl->setCurrentPage(nPage);
   
    CCUserDefault::sharedUserDefault()->setIntegerForKey("CLICKCOUNTER", nPage+1);
    CCUserDefault::sharedUserDefault()->flush();
    
}

void CLevelSelectLayer::scrollViewClick( const cocos2d::CCPoint& oOffset,const cocos2d::CCPoint & oPoint ,cocos2d::CCNode * pPage,int nPage )
{
    currentPage=nPage;
    
    //    playButton->setScale(0);
    //Current Page Zoom
}

void CLevelSelectLayer::setThePageControlToCurrentPage(int pageCurrent)
{
    pageControl->setCurrentPage(pageCurrent);
}



void CLevelSelectLayer:: scrollViewDidScroll( cocos2d::extension::CCScrollView* view ){
    //    playButton->setScale(0);
    for (int i=0; i<LevelCount; i++) {
        CCSprite *sprite = (CCSprite*)spriteArray->objectAtIndex(i);
        sprite->setScale(1);
    }
}

void CLevelSelectLayer:: scrollViewDidZoom( cocos2d::extension::CCScrollView* view ){
    
    
}

void CLevelSelectLayer::levelSelectButtonPressed(CCObject *sender) {
    ObjCCalls::showActivityIndictor();

    GameManager::sharedGameManager()->remove_unused_data();
    
    CCScene *help_scene=GameManager::sharedGameManager()->get_scene("LevelSelectionLayer.ccbi", "LevelSelectionLayer", LevelSelectionLayerLoader::loader(), CCScene::create(),false,false);
   	CCDirector::sharedDirector()->replaceScene(CCTransitionTurnOffTiles::create(0.2,help_scene));
}

bool CLevelSelectLayer::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    CCPoint touchLocation   = pTouch->getLocation();                      // Get the touch position
    touchLocation           = this->convertToNodeSpace(touchLocation);
    //    if(GameManager::sharedGameManager()->isNodeAtPoint(playeButtonlayer, touchLocation))
    //    {
    //        levelSelectButtonPressed(NULL);
    //    }
    CCRect rec = m_ScrollView->boundingBox();
    if (rec.containsPoint(pTouch->getLocationInView())){
        m_bTouchedMenu = m_ScrollView->ccTouchBegan(pTouch, pEvent);
    }
    
    
    return true;
}

void CLevelSelectLayer::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    if (m_bTouchedMenu) {
        if ( m_ScrollView->boundingBox().containsPoint(pTouch->getLocationInView()))
            m_ScrollView->ccTouchMoved(pTouch, pEvent);
        
    }
    
}

void CLevelSelectLayer::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    if ( m_bTouchedMenu) {
        if ( m_ScrollView->boundingBox().containsPoint(pTouch->getLocationInView()))
            m_ScrollView->ccTouchEnded(pTouch, pEvent);
        
        m_bTouchedMenu = false;
    }
}

void CLevelSelectLayer::ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    
    if (m_bTouchedMenu) {
        if ( m_ScrollView->boundingBox().containsPoint(pTouch->getLocationInView()))
            m_ScrollView->ccTouchEnded(pTouch, pEvent);
        m_bTouchedMenu = false;
    }
}
void CLevelSelectLayer::onEnter()
{
    CCLayer::onEnter();
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,  - 128, true);
    
}

void CLevelSelectLayer::onExit()
{
    CCLayer::onExit();
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
    
}

void CLevelSelectLayer::scalePage()
{
    
    
}

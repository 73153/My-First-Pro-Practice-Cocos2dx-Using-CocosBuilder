

#include "../Layers/HelpLayer.h"
#include "../GameManager/GameManager.h"
#include "../Layers/MenuLayer.h"
#include "../Layers/MenuLayerLoader.h"
#include "SimpleAudioEngine.h"
#include "../Layers/SettingLayer.h"
#include "../Layers/SettingLayerLoader.h"
#include "../OBJCall/ObjCCalls.h"
#include "../Layers/CustomTableViewCell.h"
using namespace cocos2d;
using namespace cocos2d::extension;
using namespace CocosDenshion;
using namespace cocos2d;
using namespace cocos2d::extension;


HelpLayer::HelpLayer():menuHomeLayer(NULL),detailBackLayer1(NULL),detailBackLayer2(NULL),detailBackLayer3(NULL),detailBackLayer4(NULL),detailBackLayer5(NULL),detailBackLayer6(NULL),detailBackLayer7(NULL),detailBackLayer8(NULL),detailBackLayer9(NULL),detailBackLayer10(NULL),isdetailBackLayer1Hidden(false),isdetailBackLayer2Hidden(NULL),isdetailBackLayer3Hidden(NULL),isdetailBackLayer4Hidden(NULL),isdetailBackLayer5Hidden(NULL),isdetailBackLayer6Hidden(NULL),isdetailBackLayer7Hidden(NULL),isdetailBackLayer8Hidden(NULL),isdetailBackLayer9Hidden(NULL),isdetailBackLayer10Hidden(NULL),menuBackButtonLayer(NULL),powerMainLabel(NULL),
playIconMenuSpr(NULL),powerInformationLayer(NULL) {
}

HelpLayer::~HelpLayer() {
    
}


bool HelpLayer::init() {
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    
    m_pRecipes = CCArray::createWithContentsOfFile("helpLayer.plist");
    m_pRecipes->retain();
    resolutionInt=GameManager::sharedGameManager()->get_devise_resolution();
    switch (resolutionInt)
    {
        case 1:{
            tableView = CCTableView::create(this, CCSizeMake(visibleSize.width, visibleSize.height-145));
            
        }
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136)
            {
                tableView = CCTableView::create(this, CCSizeMake(visibleSize.width, visibleSize.height-70));
                
            }
            else
            {
                tableView = CCTableView::create(this, CCSizeMake(visibleSize.width, visibleSize.height-70));
                
            }
        }
            break;
        case 3:{
            tableView = CCTableView::create(this, CCSizeMake(visibleSize.width, visibleSize.height-70));
            
        }
            break;
        case 4:{
            tableView = CCTableView::create(this, CCSizeMake(visibleSize.width, visibleSize.height-70));
            
        }
            
            break;
        case 5:
        {
            tableView = CCTableView::create(this, CCSizeMake(visibleSize.width, visibleSize.height-70));
            
        }
            break;
        case 6:
        {
            tableView = CCTableView::create(this, CCSizeMake(visibleSize.width, visibleSize.height-150));
            
        }
            break;
            
        default:
            break;
    }
    tableView->setDirection(kCCScrollViewDirectionVertical);
    tableView->setVerticalFillOrder(kCCTableViewFillTopDown);
    tableView->setPosition(origin);
    tableView->setDelegate(this);
    this->addChild(tableView,100);
    tableView->reloadData();
    this->setTouchEnabled(true);
    
    return true;
}

void HelpLayer::tableCellTouched(CCTableView* table, CCTableViewCell* cell)
{
    return;
    //    CCDictionary* pRecipe = (CCDictionary*)m_pRecipes->objectAtIndex(cell->getIdx());
    //    CCString* pNo   = (CCString*)pRecipe->objectForKey("recipe");
    //    CCString* pStep = (CCString*)pRecipe->objectForKey("step");
    //    int iStep = pStep==NULL?0:pStep->intValue();
    //    this->nextScene(pNo->intValue(), iStep);
}

CCSize HelpLayer::cellSizeForTable(CCTableView *table)
{
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    float height = visibleSize.height/9.6;
    return CCSizeMake(visibleSize.width, height);
}

/*
 CCTableViewCell* HelpLayer::tableCellAtIndex(CCTableView *table, unsigned int idx)
 {
 CCDictionary* pRecipe = (CCDictionary*)m_pRecipes->objectAtIndex(idx);
 CCString* pName = (CCString*)pRecipe->objectForKey("powerName");
 CCString* powerSprName   = (CCString*)pRecipe->objectForKey("powerSprName");
 CCString* powerDetail = (CCString*)pRecipe->objectForKey("powerDetail");
 CCString * nameString = CCString :: createWithFormat ("leaderboard_listbar.png");
 CCString* string;
 CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
 if (pName!=NULL) {
 string = CCString::createWithFormat("%s", pName->getCString());
 }
 CCTableViewCell *cell = table->dequeueCell();
 if (!cell) {
 cell = new CCTableViewCell();
 cell->autorelease();
 CCLabelTTF *label = CCLabelTTF::create(string->getCString(), "ZektonRg-Regular.ttf", 20, CCSizeMake(visibleSize.width, visibleSize.height/5), kCCTextAlignmentLeft);
 label->setPosition(CCPointZero);
 label->setAnchorPoint(CCPointZero);
 label->setColor(ccBLACK);
 label->setTag(123+idx);
 cell->addChild(label);
 
 CCSprite *sprite = CCSprite::create("leaderboard_listbar.png");
 sprite->setColor(ccc3(226, 226, 226));
 sprite->setPosition(ccp(visibleSize.width/2,90));
 sprite-> setTag(1234);
 cell-> addChild (sprite);
 
 CCSprite *powerSprite = CCSprite::create(powerSprName->getCString());
 powerSprite->setPosition(ccp(20,50));
 powerSprite-> setTag(1234567+idx);
 cell-> addChild (powerSprite);
 
 }
 else{
 
 //Power Main Label
 CCLabelTTF *label = (CCLabelTTF*)cell->getChildByTag(123);
 label->setString(string->getCString());
 CCTexture2D * aTexture = CCTextureCache :: sharedTextureCache () -> addImage
 (nameString -> getCString ());
 
 //Back List bar
 CCSprite * pSprite = (CCSprite *) cell-> getChildByTag (1234);
 pSprite->setColor(ccc3(226, 226, 226));
 pSprite->setPosition(ccp(visibleSize.width/2,90));
 pSprite-> setTexture (aTexture);
 
 //Power Sprite
 CCTexture2D * aPowerTexture = CCTextureCache :: sharedTextureCache () -> addImage
 (powerSprName -> getCString ());
 CCSprite * pPowerSprite = (CCSprite *) cell-> getChildByTag (1234567+idx);
 pPowerSprite->setPosition(ccp(20,50));
 pPowerSprite-> setTexture (aPowerTexture);
 }
 return cell;
 }
 */

CCTableViewCell* HelpLayer::tableCellAtIndex(CCTableView *table, unsigned int idx)
{
    CCDictionary* pRecipe = (CCDictionary*)m_pRecipes->objectAtIndex(idx);
    CCString* pName = (CCString*)pRecipe->objectForKey("powerName");
    CCString* powerSprName   = (CCString*)pRecipe->objectForKey("powerSprName");
    CCString* powerDetail = (CCString*)pRecipe->objectForKey("powerDetail");
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    CCTableViewCell *cell = table->dequeueCell();
    if (!cell) {
        cell = new CCTableViewCell();
        //cell->autorelease();
    }
    
    switch (resolutionInt)
    {
        case 1:{
            CCSprite *sprite = CCSprite::create("leaderboard_listbar.png");
            sprite->setColor(ccc3(226, 226, 226));
            sprite->setPosition(ccp(visibleSize.width/2,95));
            cell-> addChild (sprite);
            
            CCLabelTTF *label = CCLabelTTF::create(pName->getCString(), "Zekton-Bold.ttf",40);
            label->setPosition(ccp(215,75));
            label->setAnchorPoint(CCPointZero);
            label->setColor(ccBLACK);
            cell->addChild(label);
            
            CCLabelTTF *powerDetaillabel = CCLabelTTF::create(powerDetail->getCString(), "ZektonRg-Regular.ttf",30,CCSizeMake(visibleSize.width/2, cell->getContentSize().height),kCCTextAlignmentLeft);
            powerDetaillabel->setAnchorPoint(CCPointZero);
            if(idx==7)
                powerDetaillabel->setPosition(ccp((visibleSize.width/2)-30,60));
            else
                powerDetaillabel->setPosition(ccp((visibleSize.width/2)-30,70));
            powerDetaillabel->setColor(ccBLACK);
            cell->addChild(powerDetaillabel);
            
            CCSprite *powerSprite = CCSprite::create(powerSprName->getCString());
            powerSprite->setPosition(ccp(90,90));
            cell-> addChild (powerSprite);
            
        }
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136)
            {
                CCSprite *sprite = CCSprite::create("leaderboard_listbar.png");
                sprite->setColor(ccc3(226, 226, 226));
                sprite->setPosition(ccp(visibleSize.width/2,60));
                cell-> addChild (sprite);
                
                CCLabelTTF *label = CCLabelTTF::create(pName->getCString(), "Zekton-Bold.ttf",25,CCSizeMake(150, cell->getContentSize().height),kCCTextAlignmentLeft);
                if(idx==5 || idx==9)
                    label->setPosition(ccp(100,15));
                else if(idx==1 ||idx==2|| idx==4||idx==6|| idx==8)
                    label->setPosition(ccp(100,20));
                else
                    label->setPosition(ccp(100,40));
                label->setAnchorPoint(CCPointZero);
                label->setColor(ccBLACK);
                cell->addChild(label);
                
                CCLabelTTF *powerDetaillabel = CCLabelTTF::create(powerDetail->getCString(), "ZektonRg-Regular.ttf",23,CCSizeMake(visibleSize.width/2+35, cell->getContentSize().height),kCCTextAlignmentLeft);
                powerDetaillabel->setAnchorPoint(CCPointZero);
                if(idx==7){
                    powerDetaillabel->setFontSize(20);
                    powerDetaillabel->setPosition(ccp((visibleSize.width/2)-35,15));
                }
                else
                    powerDetaillabel->setPosition(ccp((visibleSize.width/2)-35,28));
                
                powerDetaillabel->setColor(ccBLACK);
                cell->addChild(powerDetaillabel);
                
                CCSprite *powerSprite = CCSprite::create(powerSprName->getCString());
                powerSprite->setPosition(ccp(50,60));
                cell-> addChild (powerSprite);
                
            }
            else
            {
                CCSprite *sprite = CCSprite::create("leaderboard_listbar.png");
                sprite->setColor(ccc3(226, 226, 226));
                sprite->setPosition(ccp(visibleSize.width/2,60));
                cell-> addChild (sprite);
                
                CCLabelTTF *label = CCLabelTTF::create(pName->getCString(), "Zekton-Bold.ttf",19);
                label->setPosition(ccp(100,45));
                label->setAnchorPoint(CCPointZero);
                label->setColor(ccBLACK);
                cell->addChild(label);
                
                CCLabelTTF *powerDetaillabel = CCLabelTTF::create(powerDetail->getCString(), "ZektonRg-Regular.ttf",23,CCSizeMake(visibleSize.width/2+35, cell->getContentSize().height),kCCTextAlignmentLeft);
                powerDetaillabel->setAnchorPoint(CCPointZero);
                if(idx==7){
                    powerDetaillabel->setFontSize(20);
                    powerDetaillabel->setPosition(ccp((visibleSize.width/2)-35,15));
                }
                else
                    powerDetaillabel->setPosition(ccp((visibleSize.width/2)-35,28));
                
                powerDetaillabel->setColor(ccBLACK);
                cell->addChild(powerDetaillabel);
                
                CCSprite *powerSprite = CCSprite::create(powerSprName->getCString());
                powerSprite->setPosition(ccp(50,60));
                cell-> addChild (powerSprite);
                
            }
        }
            break;
        case 3:{
            CCSprite *sprite = CCSprite::create("leaderboard_listbar.png");
            sprite->setColor(ccc3(226, 226, 226));
            sprite->setPosition(ccp(visibleSize.width/2,60));
            cell-> addChild (sprite);
            
            CCLabelTTF *label = CCLabelTTF::create(pName->getCString(), "Zekton-Bold.ttf",19);
            label->setPosition(ccp(100,45));
            label->setAnchorPoint(CCPointZero);
            label->setColor(ccBLACK);
            cell->addChild(label);
            
            CCLabelTTF *powerDetaillabel = CCLabelTTF::create(powerDetail->getCString(), "ZektonRg-Regular.ttf",23,CCSizeMake(visibleSize.width/2+35, cell->getContentSize().height),kCCTextAlignmentLeft);
            powerDetaillabel->setAnchorPoint(CCPointZero);
            if(idx==7){
                powerDetaillabel->setFontSize(20);
                powerDetaillabel->setPosition(ccp((visibleSize.width/2)-35,15));
            }
            else
                powerDetaillabel->setPosition(ccp((visibleSize.width/2)-35,28));
            
            powerDetaillabel->setColor(ccBLACK);
            cell->addChild(powerDetaillabel);
            
            CCSprite *powerSprite = CCSprite::create(powerSprName->getCString());
            powerSprite->setPosition(ccp(50,60));
            cell-> addChild (powerSprite);
            
        }
            break;
        case 4:{
            CCSprite *sprite = CCSprite::create("leaderboard_listbar.png");
            sprite->setColor(ccc3(226, 226, 226));
            sprite->setPosition(ccp(visibleSize.width/2,60));
            cell-> addChild (sprite);
            
            CCLabelTTF *label = CCLabelTTF::create(pName->getCString(), "Zekton-Bold.ttf",19);
            label->setPosition(ccp(100,45));
            label->setAnchorPoint(CCPointZero);
            label->setColor(ccBLACK);
            cell->addChild(label);
            
            CCLabelTTF *powerDetaillabel = CCLabelTTF::create(powerDetail->getCString(), "ZektonRg-Regular.ttf",23,CCSizeMake(visibleSize.width/2+35, cell->getContentSize().height),kCCTextAlignmentLeft);
            powerDetaillabel->setAnchorPoint(CCPointZero);
            if(idx==7){
                powerDetaillabel->setFontSize(20);
                powerDetaillabel->setPosition(ccp((visibleSize.width/2)-35,15));
            }
            else
                powerDetaillabel->setPosition(ccp((visibleSize.width/2)-35,28));
            
            powerDetaillabel->setColor(ccBLACK);
            cell->addChild(powerDetaillabel);
            
            CCSprite *powerSprite = CCSprite::create(powerSprName->getCString());
            powerSprite->setPosition(ccp(50,60));
            cell-> addChild (powerSprite);
        }
            
            break;
        case 5:
        {
            CCSprite *sprite = CCSprite::create("leaderboard_listbar.png");
            sprite->setColor(ccc3(226, 226, 226));
            sprite->setPosition(ccp(visibleSize.width/2,60));
            cell-> addChild (sprite);
            
            CCLabelTTF *label = CCLabelTTF::create(pName->getCString(), "Zekton-Bold.ttf",19);
            label->setPosition(ccp(100,45));
            label->setAnchorPoint(CCPointZero);
            label->setColor(ccBLACK);
            cell->addChild(label);
            
            CCLabelTTF *powerDetaillabel = CCLabelTTF::create(powerDetail->getCString(), "ZektonRg-Regular.ttf",23,CCSizeMake(visibleSize.width/2+35, cell->getContentSize().height),kCCTextAlignmentLeft);
            powerDetaillabel->setAnchorPoint(CCPointZero);
            if(idx==7){
                powerDetaillabel->setFontSize(20);
                powerDetaillabel->setPosition(ccp((visibleSize.width/2)-35,15));
            }
            else
                powerDetaillabel->setPosition(ccp((visibleSize.width/2)-35,28));
            
            powerDetaillabel->setColor(ccBLACK);
            cell->addChild(powerDetaillabel);
            
            CCSprite *powerSprite = CCSprite::create(powerSprName->getCString());
            powerSprite->setPosition(ccp(50,60));
            cell-> addChild (powerSprite);
        }
            break;
        case 6:
        {
            CCSprite *sprite = CCSprite::create("leaderboard_listbar.png");
            sprite->setColor(ccc3(226, 226, 226));
            sprite->setPosition(ccp(visibleSize.width/2,90));
            cell-> addChild (sprite);
            
            CCLabelTTF *label = CCLabelTTF::create(pName->getCString(), "Zekton-Bold.ttf",35);
            label->setPosition(ccp(205,75));
            label->setAnchorPoint(CCPointZero);
            label->setColor(ccBLACK);
            cell->addChild(label);
            
            CCLabelTTF *powerDetaillabel = CCLabelTTF::create(powerDetail->getCString(), "ZektonRg-Regular.ttf",30,CCSizeMake(visibleSize.width/2, cell->getContentSize().height),kCCTextAlignmentLeft);
            powerDetaillabel->setAnchorPoint(CCPointZero);
            if(idx==7)
                powerDetaillabel->setPosition(ccp((visibleSize.width/2)-20,30));
            else
                powerDetaillabel->setPosition(ccp((visibleSize.width/2)-20,70));
            powerDetaillabel->setColor(ccBLACK);
            cell->addChild(powerDetaillabel);
            
            CCSprite *powerSprite = CCSprite::create(powerSprName->getCString());
            powerSprite->setPosition(ccp(90,90));
            cell-> addChild (powerSprite);
        }
            break;
            
        default:
            break;
    }
    
    
    
    
    /*
     //Power Main Label
     CCLabelTTF *label = (CCLabelTTF*)cell->getChildByTag(123);
     label->setString(string->getCString());
     CCTexture2D * aTexture = CCTextureCache :: sharedTextureCache () -> addImage
     (nameString -> getCString ());
     
     //Back List bar
     CCSprite * pSprite = (CCSprite *) cell-> getChildByTag (1234);
     pSprite->setColor(ccc3(226, 226, 226));
     pSprite->setPosition(ccp(visibleSize.width/2,90));
     pSprite-> setTexture (aTexture);
     
     //Power Sprite
     CCTexture2D * aPowerTexture = CCTextureCache :: sharedTextureCache () -> addImage
     (powerSprName -> getCString ());
     CCSprite * pPowerSprite = (CCSprite *) cell-> getChildByTag (1234567+idx);
     pPowerSprite->setPosition(ccp(20,50));
     pPowerSprite-> setTexture (aPowerTexture);
     */
    
    return cell;
}


unsigned int HelpLayer::numberOfCellsInTableView(CCTableView *table)
{
    return m_pRecipes->count();
}

void HelpLayer::nextScene(int nIndex, int iStep)
{
}

//void HelpLayer::setDelegate(HelpLayerDelegate* pDelegate)
//{
//	settingDelegte = pDelegate;
//}

#pragma  mark   COCOSBUILDER INITITIALIZATION
void HelpLayer::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    ObjCCalls::hideActivityIndicator();
    
    CCLabelTTF *localpowerMainLabel = (CCLabelTTF*)powerMainLabel;
    
    int resoluTion = GameManager::sharedGameManager()->get_devise_resolution();
    
    //    Resource ipad_HD = resources_ipad;
    if(resoluTion==1 || resoluTion==6){
    }
    if(resoluTion==2){
        localpowerMainLabel->setFontSize(35);
    }
    if(resoluTion==3)
    {
        localpowerMainLabel->setFontSize(35);
    }
    if(resoluTion==4){
        localpowerMainLabel->setFontSize(25);
    }
    
    if(resoluTion==5)
    {
        localpowerMainLabel->setFontSize(35);
    }
    
    
    //    NightSensitivityControlSlider->setVisible(true);
    
}

SEL_CallFuncN HelpLayer::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
    return NULL;
}

SEL_MenuHandler HelpLayer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onHomeClicked", HelpLayer::onHomeClicked);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onFacebookClicked", HelpLayer::onFacebookClicked);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onCoinPurchaseClicked", HelpLayer::onCoinPurchaseClicked);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onDetailShowPressed", HelpLayer::onDetailShowPressed);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onPowerInfoPressed", HelpLayer::onPowerInfoPressed);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onBackButtonClicked", HelpLayer::onBackButtonClicked);
    
    
    //    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "settingBtnClicked", HelpLayer::settingBtnClicked);
    //    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onForGroundSoundClicked", HelpLayer::onForGroundSoundClicked);
    //    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onBackGroundSoundClicked", HelpLayer::onBackGroundSoundClicked);
    
    return NULL;
}
void HelpLayer::onPowerInfoPressed(cocos2d::CCObject *pSender)
{
    
}

SEL_CCControlHandler HelpLayer::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}

bool HelpLayer::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    bool bRet = false;
    return bRet;
}
bool HelpLayer::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "menuHomeLayer",CCLayerColor *, this->menuHomeLayer);
    
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "powerMainLabel", CCLabelTTF*, powerMainLabel);
    
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "menuBackButtonLayer", CCLayerColor*, menuBackButtonLayer);
    
    
    return false;
}

void HelpLayer::onHomeClicked(cocos2d::CCObject *pSender)
{
    ObjCCalls::showActivityIndictor();
    GameManager::sharedGameManager()->remove_unused_data();
    CCScene *highScore_scene=GameManager::sharedGameManager()->get_scene("MenuLayer.ccbi", "MenuLayer",MenuLayerLoader::loader(), CCScene::create(),false,false);
   	CCDirector::sharedDirector()->replaceScene(CCTransitionTurnOffTiles::create(0.2,highScore_scene));
}
void HelpLayer::onFacebookClicked(cocos2d::CCObject *pSender)
{
    
}
void HelpLayer::onCoinPurchaseClicked(cocos2d::CCObject *pSender)
{
    
}

void HelpLayer::onDetailShowPressed(CCObject* pSender)
{
    CCMenuItemImage *menuItemPressed = (CCMenuItemImage*)pSender;
    
    if(menuItemPressed->getTag()==10)
    {
        CCPoint detailBackLayer1Pos = detailBackLayer1->getPosition();
        if(isdetailBackLayer1Hidden==false){
            CCMoveTo *move = CCMoveTo::create(0.5, CCPoint(detailBackLayer1Pos.x+1000, detailBackLayer1Pos.y));
            detailBackLayer1->runAction(move);
            isdetailBackLayer1Hidden=true;
        }
        else{
            CCMoveTo *move = CCMoveTo::create(0.5, CCPoint(detailBackLayer1Pos.x-1000, detailBackLayer1Pos.y));
            detailBackLayer1->runAction(move);
            isdetailBackLayer1Hidden=false;
        }
    }
    if(menuItemPressed->getTag()==11)
    {
        CCPoint detailBackLayer1Pos = detailBackLayer2->getPosition();
        if(isdetailBackLayer2Hidden==false){
            CCMoveTo *move = CCMoveTo::create(0.5, CCPoint(detailBackLayer1Pos.x+1000, detailBackLayer1Pos.y));
            detailBackLayer2->runAction(move);
            isdetailBackLayer2Hidden=true;
        }
        else{
            CCMoveTo *move = CCMoveTo::create(0.5, CCPoint(detailBackLayer1Pos.x-1000, detailBackLayer1Pos.y));
            detailBackLayer2->runAction(move);
            isdetailBackLayer2Hidden=false;
        }
    }
    if(menuItemPressed->getTag()==12)
    {
        CCPoint detailBackLayer1Pos = detailBackLayer3->getPosition();
        if(isdetailBackLayer3Hidden==false){
            CCMoveTo *move = CCMoveTo::create(0.5, CCPoint(detailBackLayer1Pos.x+1000, detailBackLayer1Pos.y));
            detailBackLayer3->runAction(move);
            isdetailBackLayer3Hidden=true;
        }
        else{
            CCMoveTo *move = CCMoveTo::create(0.5, CCPoint(detailBackLayer1Pos.x-1000, detailBackLayer1Pos.y));
            detailBackLayer3->runAction(move);
            isdetailBackLayer3Hidden=false;
        }
    }
    if(menuItemPressed->getTag()==13)
    {
        CCPoint detailBackLayer1Pos = detailBackLayer4->getPosition();
        if(isdetailBackLayer4Hidden==false){
            CCMoveTo *move = CCMoveTo::create(0.5, CCPoint(detailBackLayer1Pos.x+1000, detailBackLayer1Pos.y));
            detailBackLayer4->runAction(move);
            isdetailBackLayer4Hidden=true;
        }
        else{
            CCMoveTo *move = CCMoveTo::create(0.5, CCPoint(detailBackLayer1Pos.x-1000, detailBackLayer1Pos.y));
            detailBackLayer4->runAction(move);
            isdetailBackLayer4Hidden=false;
        }
    }
    if(menuItemPressed->getTag()==14)
    {
        CCPoint detailBackLayer1Pos = detailBackLayer5->getPosition();
        if(isdetailBackLayer5Hidden==false){
            CCMoveTo *move = CCMoveTo::create(0.5, CCPoint(detailBackLayer1Pos.x+1000, detailBackLayer1Pos.y));
            detailBackLayer5->runAction(move);
            isdetailBackLayer5Hidden=true;
        }
        else{
            CCMoveTo *move = CCMoveTo::create(0.5, CCPoint(detailBackLayer1Pos.x-1000, detailBackLayer1Pos.y));
            detailBackLayer5->runAction(move);
            isdetailBackLayer5Hidden=false;
        }
    }
    if(menuItemPressed->getTag()==15)
    {
        CCPoint detailBackLayer1Pos = detailBackLayer6->getPosition();
        if(isdetailBackLayer6Hidden==false){
            CCMoveTo *move = CCMoveTo::create(0.5, CCPoint(detailBackLayer1Pos.x+1000, detailBackLayer1Pos.y));
            detailBackLayer6->runAction(move);
            isdetailBackLayer6Hidden=true;
        }
        else{
            CCMoveTo *move = CCMoveTo::create(0.5, CCPoint(detailBackLayer1Pos.x-1000, detailBackLayer1Pos.y));
            detailBackLayer6->runAction(move);
            isdetailBackLayer6Hidden=false;
        }
    }
    if(menuItemPressed->getTag()==16)
    {
        CCPoint detailBackLayer1Pos = detailBackLayer7->getPosition();
        if(isdetailBackLayer7Hidden==false){
            CCMoveTo *move = CCMoveTo::create(0.5, CCPoint(detailBackLayer1Pos.x+1000, detailBackLayer1Pos.y));
            detailBackLayer7->runAction(move);
            isdetailBackLayer7Hidden=true;
        }
        else{
            CCMoveTo *move = CCMoveTo::create(0.5, CCPoint(detailBackLayer1Pos.x-1000, detailBackLayer1Pos.y));
            detailBackLayer7->runAction(move);
            isdetailBackLayer7Hidden=false;
        }
    }
    if(menuItemPressed->getTag()==17)
    {
        CCPoint detailBackLayer1Pos = detailBackLayer8->getPosition();
        if(isdetailBackLayer8Hidden==false){
            CCMoveTo *move = CCMoveTo::create(0.5, CCPoint(detailBackLayer1Pos.x+1000, detailBackLayer1Pos.y));
            detailBackLayer8->runAction(move);
            isdetailBackLayer8Hidden=true;
        }
        else{
            CCMoveTo *move = CCMoveTo::create(0.5, CCPoint(detailBackLayer1Pos.x-1000, detailBackLayer1Pos.y));
            detailBackLayer8->runAction(move);
            isdetailBackLayer8Hidden=false;
        }
    }
    if(menuItemPressed->getTag()==18)
    {
        CCPoint detailBackLayer1Pos = detailBackLayer9->getPosition();
        if(isdetailBackLayer9Hidden==false){
            CCMoveTo *move = CCMoveTo::create(0.5, CCPoint(detailBackLayer1Pos.x+1000, detailBackLayer1Pos.y));
            detailBackLayer9->runAction(move);
            isdetailBackLayer9Hidden=true;
        }
        else{
            CCMoveTo *move = CCMoveTo::create(0.5, CCPoint(detailBackLayer1Pos.x-1000, detailBackLayer1Pos.y));
            detailBackLayer9->runAction(move);
            isdetailBackLayer9Hidden=false;
        }
    }
    
    if(menuItemPressed->getTag()==19)
    {
        CCPoint detailBackLayer1Pos = detailBackLayer10->getPosition();
        if(isdetailBackLayer10Hidden==false){
            CCMoveTo *move = CCMoveTo::create(0.5, CCPoint(detailBackLayer1Pos.x+1000, detailBackLayer1Pos.y));
            detailBackLayer10->runAction(move);
            isdetailBackLayer10Hidden=true;
        }
        else{
            CCMoveTo *move = CCMoveTo::create(0.5, CCPoint(detailBackLayer1Pos.x-1000, detailBackLayer1Pos.y));
            detailBackLayer10->runAction(move);
            isdetailBackLayer10Hidden=false;
        }
    }
    
    
}
void HelpLayer::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent)
{
    
    CCTouch *myTouch = (CCTouch*) pTouches->anyObject();
    CCPoint location = myTouch->getLocationInView();
    location = CCDirector::sharedDirector()->convertToGL(location);
    if(GameManager::sharedGameManager()->isNodeAtPoint(menuHomeLayer, location))
    {
        onHomeClicked(NULL);
    }
    else if(GameManager::sharedGameManager()->isNodeAtPoint(menuBackButtonLayer, location)){
        onBackButtonClicked(NULL);
    }
    
}
void HelpLayer::onBackButtonClicked(cocos2d::CCObject *pSender)
{
    ObjCCalls::showActivityIndictor();
    GameManager::sharedGameManager()->remove_unused_data();
    CCScene *highScore_scene=GameManager::sharedGameManager()->get_scene("SettingLayer.ccbi", "SettingLayer",SettingLayerLoader::loader(), CCScene::create(),false,false);
   	CCDirector::sharedDirector()->replaceScene(CCTransitionTurnOffTiles::create(0.2,highScore_scene));
}



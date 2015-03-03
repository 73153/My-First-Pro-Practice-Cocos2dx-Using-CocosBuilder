

#include "../Layers/InAppPurchaseLayer.h"
#include "../GameManager/GameManager.h"
#include "../Layers/MenuLayer.h"
#include "../Layers/MenuLayerLoader.h"
#include "../Layers/LevelSelectionLayer.h"
#include "../Layers/LevelSelectionLayerLoader.h"
// iOS Includes
#include "../OBJCall/ObjCCalls.h"

#include "cocos-ext.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
using namespace cocos2d;
using namespace cocos2d::extension;


InAppPurchaseLayer::InAppPurchaseLayer():menuBackLayer(NULL),largePaddleLabel(NULL),bonusPointLabel(NULL),bonusLifeLabel(NULL),autoPlayLabel(NULL),multiBallLabel(NULL),bulletLabel(NULL),dollerLabel1(NULL),dollerLabel2(NULL),dollerLabel3(NULL),dollerLabel4(NULL),dollerLabel5(NULL),dollerLabel6(NULL),bulletLabelNotUsed(NULL),multiBallLabelNotUsed(NULL),autoPlayLabelNotUsed(NULL),
bonusLifeLabelNotUsed(NULL),bonusPointLabelNotUsed(NULL),laregPaddleLabelNotUsed(NULL),totalCoinsCollected(NULL),storeMainLbl(NULL),coinMenuSpr1(NULL),coinMenuSpr2(NULL),coinMenuSpr3(NULL),coinMenuSpr4(NULL),coinMenuSpr5(NULL),coinMenuSpr6(NULL),totalCoinsLabelNotUsed(NULL),coinsPackLabelUnused(NULL),buyLabel(NULL),powerUpsLabel(NULL),unlockAllMonLabel(NULL),powerUpsMenuLayer(NULL),unlockAllMonMenuLayer(NULL),buyMenuItem(NULL),unlockAllMonumentsMainLayer(NULL),powerUpsMainLayer(NULL),segmentControlLayer(NULL),buyBtn1(NULL),buyBtn2(NULL),buyBtn3(NULL),buyBtn4(NULL),buyBtn5(NULL),buyBtn6(NULL),buyBtn7(NULL),buyLabelNotUsed1(NULL),buyLabelNotUsed2(NULL),buyLabelNotUsed3(NULL),buyLabelNotUsed4(NULL),buyLabelNotUsed5(NULL),buyLabelNotUsed6(NULL),buyLabelNotUsed7(NULL),restoreLabelNotUsed(NULL),unlockAllLabelNotUsed(NULL),effielTowerLabelNotUsed(NULL),statueOfLibertyLabelNotUsed(NULL),towerOfPisaLabelNotUsed(NULL),bigBenLabelNotUsed(NULL),colosseumLabelNotUsed(NULL),operaHouseLabelNotUsed(NULL),easterStoneLabelNotUsed(NULL),isCoinRequireUpdate(false),restoreMenuItemSpr(NULL),unlockAllMenuItemSpr(NULL),bulletCoinLayer(NULL),multiBallCoinLayer(NULL),autoPlayCoinLayer(NULL),bonusLifeCoinLayer(NULL),bonusPointCoinLayer(NULL),laregPaddleLayer(NULL),effielLayer(NULL),statueLayer(NULL),towerLayer(NULL),bigLayer(NULL),colosseumLayer(NULL),operaLayer(NULL),easterLayer(NULL),isPowerLayerVisible(NULL),isMonumentPurchased(false),buyLayer1(NULL),buyLayer2(NULL),buyLayer3(NULL),buyLayer4(NULL),buyLayer5(NULL),buyLayer6(NULL),buyLayer7(NULL),coinLayer1(NULL),coinLayer2(NULL),coinLayer3(NULL),coinLayer4(NULL),coinLayer5(NULL),coinLayer6(NULL),isRestorePurchased(false),isConnectToInternet(true){
}

InAppPurchaseLayer::~InAppPurchaseLayer() {
    //    CC_SAFE_RELEASE_NULL(mAnimationManager);
    //    CC_SAFE_RELEASE_NULL(controlModeSelector);
    //    CC_SAFE_RELEASE_NULL(controlModeTouch);
    //    CC_SAFE_RELEASE_NULL(controlModeDay);
    //    CC_SAFE_RELEASE_NULL(settingBtn);
    //    CC_SAFE_RELEASE_NULL(slider);
    //    CC_SAFE_RELEASE_NULL(grvityControlLbl);
    //    CC_SAFE_RELEASE_NULL(volumeForGroundOrangeSpr1);
    //    CC_SAFE_RELEASE_NULL(volumeForGroundOrangeSpr2);
    //    CC_SAFE_RELEASE_NULL(volumeForGroundOrangeSpr3);
    //    CC_SAFE_RELEASE_NULL(soundForGroundOrangeSpr1);
    //    CC_SAFE_RELEASE_NULL(soundForGroundOrangeSpr2);
    //    CC_SAFE_RELEASE_NULL(soundForGroundOrangeSpr3);
    //    CC_SAFE_RELEASE_NULL(NightSensitivityControlSlider);
    //    CC_SAFE_RELEASE_NULL(settingBtnLayer);
    //    CC_SAFE_RELEASE_NULL(settingScreenlayer);
}


bool InAppPurchaseLayer::init() {
    
    bulletTimerCount=0;
    multiBallCount=0;
    autoPlayCount=0;
    bonusLifeCount=0;
    bonusPointsCount=0;
    largePaddleCounter=0;
    dollerLabel1Int=0;
    dollerLabel2Int=0;
    dollerLabel3Int=0;
    dollerLabel4Int=0;
    dollerLabel5Int=0;
    dollerLabel6Int=0;
    counter=0;
    
    setKeypadEnabled(true);
    setTouchPriority(kCCMenuHandlerPriority + 1);
    setTouchEnabled(true);
    return true;
}

//void InAppPurchaseLayer::setDelegate(InAppPurchaseLayerDelegate* pDelegate)
//{
//	settingDelegte = pDelegate;
//}



#pragma  mark   COCOSBUILDER INITITIALIZATION
void InAppPurchaseLayer::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    ObjCCalls::hideActivityIndicator();
    
    this->retain();
    
    menuBackLayer->setZOrder(10);
    CCNotificationCenter::sharedNotificationCenter()->removeObserver(this, "MonumentPurchaseFinishedNotification");
    CCNotificationCenter::sharedNotificationCenter()->removeObserver(this, "CoinsPurchaseFinishedNotification");
    
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(InAppPurchaseLayer::CoinsPurchaseFinished), "CoinsPurchaseFinishedNotification", NULL);
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(InAppPurchaseLayer::MonumentPurchaseFinished), "MonumentPurchaseFinishedNotification", NULL);
    
    
    int totalCoins = CCUserDefault::sharedUserDefault()->getIntegerForKey("COINCOUNT");
    totalCoinsCollected->setString(CCString::createWithFormat("%d",totalCoins)->getCString());
    CCLOG("totalCoins %d",totalCoins);
    
    powerUpsMenuLayer->setColor(ccc3(200,200,200));
    
    unlockAllMonMenuLayer->setColor(ccc3(100,100,100));
    powerUpsLabel->setColor(ccBLACK);
    
    buyMenuItem->setColor(ccc3(170, 170, 170));
    
    buyBtn1->setColor(ccc3(170, 170, 170));
    buyBtn2->setColor(ccc3(170, 170, 170));
    buyBtn3->setColor(ccc3(170, 170, 170));
    buyBtn4->setColor(ccc3(170, 170, 170));
    buyBtn5->setColor(ccc3(170, 170, 170));
    buyBtn6->setColor(ccc3(170, 170, 170));
    buyBtn7->setColor(ccc3(170, 170, 170));
    
    buyBtn1->setVisible(false);
    buyBtn2->setVisible(false);
    buyBtn3->setVisible(false);
    buyBtn4->setVisible(false);
    buyBtn5->setVisible(false);
    buyBtn6->setVisible(false);
    buyBtn7->setVisible(false);
    
    
    unlockAllMonLabel->setColor(ccWHITE);
    dollerLabel1Int=CCUserDefault::sharedUserDefault()->getIntegerForKey("DOLLERLABEL1");
    dollerLabel2Int=CCUserDefault::sharedUserDefault()->getIntegerForKey("DOLLERLABEL2");
    dollerLabel3Int=CCUserDefault::sharedUserDefault()->getIntegerForKey("DOLLERLABEL3");
    dollerLabel4Int=CCUserDefault::sharedUserDefault()->getIntegerForKey("DOLLERLABEL4");
    dollerLabel5Int=CCUserDefault::sharedUserDefault()->getIntegerForKey("DOLLERLABEL5");
    dollerLabel6Int=CCUserDefault::sharedUserDefault()->getIntegerForKey("DOLLERLABEL6");
    
    bulletTimerCount=CCUserDefault::sharedUserDefault()->getIntegerForKey("BULLETTIMERCOUNTER");
    multiBallCount=CCUserDefault::sharedUserDefault()->getIntegerForKey("EXTRAMULTIBALLCOUNTER");
    autoPlayCount=CCUserDefault::sharedUserDefault()->getIntegerForKey("AUTOPLAYTIMERCOUNTER");
    bonusPointsCount=CCUserDefault::sharedUserDefault()->getIntegerForKey("BONUSPOINTCOUNTER");
    bonusLifeCount=CCUserDefault::sharedUserDefault()->getIntegerForKey("BONUSLIFECOUNTER");
    largePaddleCounter=CCUserDefault::sharedUserDefault()->getIntegerForKey("LARGEPADDLECOUNTER");
    
    if(bulletTimerCount==0)
        bulletTimerCount=6;
    if(multiBallCount==0)
        multiBallCount=1;
    if(autoPlayCount==0)
        autoPlayCount=6;
    if(bonusPointsCount==0)
        bonusPointsCount=100;
    if(largePaddleCounter==0)
        largePaddleCounter=6;
    if(bonusLifeCount==0)
        bonusLifeCount=1;
    
    bulletLabel->setString(CCString::createWithFormat("%d Seconds",bulletTimerCount)->getCString());
    multiBallLabel->setString(CCString::createWithFormat("%d Ball Extra",multiBallCount)->getCString());
    autoPlayLabel->setString(CCString::createWithFormat("%d Seconds",autoPlayCount)->getCString());
    bonusLifeLabel->setString(CCString::createWithFormat("%d Life Bonus",bonusLifeCount)->getCString());
    bonusPointLabel->setString(CCString::createWithFormat("%d Bonus",bonusPointsCount)->getCString());
    largePaddleLabel->setString(CCString::createWithFormat("%d Seconds",largePaddleCounter)->getCString());
    if(dollerLabel1Int==0)
        dollerLabel1Int=100;
    if(dollerLabel2Int==0)
        dollerLabel2Int=160;
    if(dollerLabel3Int==0)
        dollerLabel3Int=40;
    if(dollerLabel4Int==0)
        dollerLabel4Int=80;
    if(dollerLabel5Int==0)
        dollerLabel5Int=100;
    if(dollerLabel6Int==0)
        dollerLabel6Int=160;
    
    dollerLabel1->setString(CCString::createWithFormat("%d Coins",dollerLabel1Int)->getCString());
    dollerLabel2->setString(CCString::createWithFormat("%d Coins",dollerLabel2Int)->getCString());
    dollerLabel3->setString(CCString::createWithFormat("%d Coins",dollerLabel3Int)->getCString());
    dollerLabel4->setString(CCString::createWithFormat("%d Coins",dollerLabel4Int)->getCString());
    dollerLabel5->setString(CCString::createWithFormat("%d Coins",dollerLabel5Int)->getCString());
    dollerLabel6->setString(CCString::createWithFormat("%d Coins",dollerLabel6Int)->getCString());
    
    if(isRestorePurchased==true){
        restoreMenuItemSpr->setEnabled(false);
        restoreMenuItemSpr->setOpacity(100);
    }
    else{
        restoreMenuItemSpr->setEnabled(true);
    }
    
    
    if(bulletTimerCount>9)
        dollerLabel1->setString("Limit exceeds");
    if(multiBallCount>2)
        dollerLabel2->setString("Limit exceeds");
    if(autoPlayCount>9)
        dollerLabel3->setString("Limit exceeds");
    if(bonusLifeCount>6)
        dollerLabel4->setString("Limit exceeds");
    if(largePaddleCounter>9)
        dollerLabel6->setString("Limit exceeds");
    
    CCPoint menuBackLayerPos = menuBackLayer->getPosition();
    CCPoint largePaddleLabelPos  =largePaddleLabel->getPosition();
    CCPoint bonusPointLabelPos =bonusPointLabel->getPosition();
    CCPoint bonusLifeLabelPos =bonusLifeLabel->getPosition();
    CCPoint autoPlayLabelPos =autoPlayLabel->getPosition();
    CCPoint multiBallLabelPos =multiBallLabel->getPosition();
    CCPoint bulletLabelPos =bulletLabel->getPosition();
    
    CCPoint dollerLabel1Pos =dollerLabel1->getPosition();
    CCPoint dollerLabel2Pos =dollerLabel2->getPosition();
    CCPoint dollerLabel3Pos =dollerLabel3->getPosition();
    CCPoint dollerLabel4Pos =dollerLabel4->getPosition();
    CCPoint dollerLabel5Pos =dollerLabel5->getPosition();
    CCPoint dollerLabel6Pos =dollerLabel6->getPosition();
    
    
    CCPoint bulletLabelNotUsedPos =bulletLabelNotUsed->getPosition();
    CCPoint autoPlayLabelNotUsedPos =autoPlayLabelNotUsed->getPosition();
    CCPoint bonusLifeLabelNotUsedPos =bonusLifeLabelNotUsed->getPosition();
    CCPoint  bonusPointLabelNotUsedPos =bonusPointLabelNotUsed->getPosition();
    CCPoint laregPaddleLabelNotUsedPos =laregPaddleLabelNotUsed->getPosition();
    CCPoint multiBallLabelNotUsedPos =multiBallLabelNotUsed->getPosition();
    CCPoint totalCoinsLabelNotUsedPos = totalCoinsLabelNotUsed->getPosition();
    
    CCLabelTTF *locallargePaddleLabel = locallargePaddleLabel;
    
    buyLabelNotUsed1PosX= buyLabelNotUsed1->getPositionX();
    buyLabelNotUsed2PosX= buyLabelNotUsed2->getPositionX();
    buyLabelNotUsed3PosX= buyLabelNotUsed3->getPositionX();
    buyLabelNotUsed4PosX= buyLabelNotUsed4->getPositionX();
    buyLabelNotUsed5PosX= buyLabelNotUsed5->getPositionX();
    buyLabelNotUsed6PosX= buyLabelNotUsed6->getPositionX();
    buyLabelNotUsed7PosX= buyLabelNotUsed7->getPositionX();
    switch (GameManager::sharedGameManager()->get_devise_resolution())
    {
        case 1:{
            
        }
            
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136)
            {
                buyLabelNotUsed1->setPositionX(buyLabelNotUsed1PosX+10);
                buyLabelNotUsed2->setPositionX(buyLabelNotUsed2PosX+10);
                buyLabelNotUsed3->setPositionX(buyLabelNotUsed3PosX+10);
                buyLabelNotUsed4->setPositionX(buyLabelNotUsed4PosX+10);
                buyLabelNotUsed5->setPositionX(buyLabelNotUsed5PosX+10);
                buyLabelNotUsed6->setPositionX(buyLabelNotUsed6PosX+10);
                buyLabelNotUsed7->setPositionX(buyLabelNotUsed7PosX+10);
                
                powerUpsMenuLayer->setScaleX(1.1);
                unlockAllMonMenuLayer->setScaleX(1.1);
                unlockAllMenuItemSpr->setScaleX(0.9);
                restoreMenuItemSpr->setScaleX(0.9);
                buyLabel->setFontSize(25);
                float powerUpsLabelPosX = powerUpsLabel->getPositionX();
                float unlockAllMonLabelPosX = unlockAllMonLabel->getPositionX();
                float powerUpsMenuLayerPosX = powerUpsMenuLayer->getPositionX();
                float unlockAllMonMenuLayerPosX = unlockAllMonMenuLayer->getPositionX();
                unlockAllMonMenuLayer->setPositionX(unlockAllMonMenuLayerPosX-10);
                powerUpsMenuLayer->setPositionX(powerUpsMenuLayerPosX-40);
                powerUpsLabel->setPositionX(powerUpsLabelPosX-20);
                unlockAllMonLabel->setPositionX(unlockAllMonLabelPosX-10);
                powerUpsLabel->setFontSize(25);
                unlockAllMonLabel->setFontSize(23);
                
                CCPoint unlockAllPos = unlockAllLabelNotUsed->getPosition();
                CCPoint restorePos = restoreLabelNotUsed->getPosition();
                
                unlockAllLabelNotUsed->setPosition(ccp(unlockAllPos.x-15,unlockAllPos.y-5));
                restoreLabelNotUsed->setPosition(ccp(restorePos.x-15,restorePos.y-5));
                
                dollerLabel1->setFontSize(25);
                dollerLabel2->setFontSize(25);
                dollerLabel3->setFontSize(25);
                dollerLabel4->setFontSize(25);
                dollerLabel5->setFontSize(25);
                dollerLabel6->setFontSize(25);
                storeMainLbl->setFontSize(50);
                
                largePaddleLabel->setFontSize(20);
                bonusPointLabel->setFontSize(20);
                bonusLifeLabel->setFontSize(20);
                autoPlayLabel->setFontSize(20);
                multiBallLabel->setFontSize(20);
                bulletLabel->setFontSize(20);
                
                totalCoinsCollected->setFontSize(45);
                totalCoinsLabelNotUsed->setFontSize(40);
                
                bulletLabelNotUsed->setFontSize(25);
                autoPlayLabelNotUsed->setFontSize(25);
                bonusLifeLabelNotUsed->setFontSize(25);
                bonusPointLabelNotUsed->setFontSize(25);
                laregPaddleLabelNotUsed->setFontSize(25);
                multiBallLabelNotUsed->setFontSize(25);
                
                buyLabelNotUsed1->setFontSize(30);
                buyLabelNotUsed2->setFontSize(30);
                buyLabelNotUsed3->setFontSize(30);
                buyLabelNotUsed4->setFontSize(30);
                buyLabelNotUsed5->setFontSize(30);
                buyLabelNotUsed6->setFontSize(30);
                buyLabelNotUsed7->setFontSize(30);
                
                restoreLabelNotUsed->setFontSize(30);
                unlockAllLabelNotUsed->setFontSize(30);
                effielTowerLabelNotUsed->setFontSize(25);
                bigBenLabelNotUsed->setFontSize(25);
                statueOfLibertyLabelNotUsed->setFontSize(25);
                towerOfPisaLabelNotUsed->setFontSize(25);
                colosseumLabelNotUsed->setFontSize(25);
                operaHouseLabelNotUsed->setFontSize(25);
                easterStoneLabelNotUsed->setFontSize(25);
                coinsPackLabelUnused->setFontSize(45);
            }
            else
            {
                buyLabelNotUsed1->setPositionX(buyLabelNotUsed1PosX+10);
                buyLabelNotUsed2->setPositionX(buyLabelNotUsed2PosX+10);
                buyLabelNotUsed3->setPositionX(buyLabelNotUsed3PosX+10);
                buyLabelNotUsed4->setPositionX(buyLabelNotUsed4PosX+10);
                buyLabelNotUsed5->setPositionX(buyLabelNotUsed5PosX+10);
                buyLabelNotUsed6->setPositionX(buyLabelNotUsed6PosX+10);
                buyLabelNotUsed7->setPositionX(buyLabelNotUsed7PosX+10);
                powerUpsMenuLayer->setScaleX(1.2);
                unlockAllMonMenuLayer->setScaleX(1.2);
                
                unlockAllMenuItemSpr->setScaleX(0.9);
                restoreMenuItemSpr->setScaleX(0.9);
                buyLabel->setFontSize(25);
                float powerUpsLabelPosX = powerUpsLabel->getPositionX();
                float unlockAllMonLabelPosX = unlockAllMonLabel->getPositionX();
                float powerUpsMenuLayerPosX = powerUpsMenuLayer->getPositionX();
                float unlockAllMonMenuLayerPosX = unlockAllMonMenuLayer->getPositionX();
                unlockAllMonMenuLayer->setPositionX(unlockAllMonMenuLayerPosX-10);
                powerUpsMenuLayer->setPositionX(powerUpsMenuLayerPosX-40);
                powerUpsLabel->setPositionX(powerUpsLabelPosX-20);
                unlockAllMonLabel->setPositionX(unlockAllMonLabelPosX-10);
                powerUpsLabel->setFontSize(25);
                unlockAllMonLabel->setFontSize(23);
                
                dollerLabel1->setFontSize(25);
                dollerLabel2->setFontSize(25);
                dollerLabel3->setFontSize(25);
                dollerLabel4->setFontSize(25);
                dollerLabel5->setFontSize(25);
                dollerLabel6->setFontSize(25);
                storeMainLbl->setFontSize(50);
                
                largePaddleLabel->setFontSize(20);
                bonusPointLabel->setFontSize(20);
                bonusLifeLabel->setFontSize(20);
                autoPlayLabel->setFontSize(20);
                multiBallLabel->setFontSize(20);
                bulletLabel->setFontSize(20);
                
                totalCoinsCollected->setFontSize(45);
                totalCoinsLabelNotUsed->setFontSize(40);
                
                bulletLabelNotUsed->setFontSize(25);
                autoPlayLabelNotUsed->setFontSize(25);
                bonusLifeLabelNotUsed->setFontSize(25);
                bonusPointLabelNotUsed->setFontSize(25);
                laregPaddleLabelNotUsed->setFontSize(25);
                multiBallLabelNotUsed->setFontSize(25);
                
                buyLabelNotUsed1->setFontSize(25);
                buyLabelNotUsed2->setFontSize(25);
                buyLabelNotUsed3->setFontSize(25);
                buyLabelNotUsed4->setFontSize(25);
                buyLabelNotUsed5->setFontSize(25);
                buyLabelNotUsed6->setFontSize(25);
                buyLabelNotUsed7->setFontSize(25);
                
                restoreLabelNotUsed->setFontSize(25);
                unlockAllLabelNotUsed->setFontSize(25);
                effielTowerLabelNotUsed->setFontSize(25);
                bigBenLabelNotUsed->setFontSize(25);
                statueOfLibertyLabelNotUsed->setFontSize(25);
                towerOfPisaLabelNotUsed->setFontSize(25);
                colosseumLabelNotUsed->setFontSize(25);
                operaHouseLabelNotUsed->setFontSize(25);
                easterStoneLabelNotUsed->setFontSize(25);
                coinsPackLabelUnused->setFontSize(45);
                
            }
        }
            break;
        case 3:{
            
            powerUpsMenuLayer->setScaleX(1.2);
            unlockAllMonMenuLayer->setScaleX(1.2);
            
            buyLabelNotUsed1->setPositionX(buyLabelNotUsed1PosX+10);
            buyLabelNotUsed2->setPositionX(buyLabelNotUsed2PosX+10);
            buyLabelNotUsed3->setPositionX(buyLabelNotUsed3PosX+10);
            buyLabelNotUsed4->setPositionX(buyLabelNotUsed4PosX+10);
            buyLabelNotUsed5->setPositionX(buyLabelNotUsed5PosX+10);
            buyLabelNotUsed6->setPositionX(buyLabelNotUsed6PosX+10);
            buyLabelNotUsed7->setPositionX(buyLabelNotUsed7PosX+10);
            
            unlockAllMenuItemSpr->setScaleX(0.9);
            restoreMenuItemSpr->setScaleX(0.9);
            buyLabel->setFontSize(25);
            float powerUpsLabelPosX = powerUpsLabel->getPositionX();
            float unlockAllMonLabelPosX = unlockAllMonLabel->getPositionX();
            float powerUpsMenuLayerPosX = powerUpsMenuLayer->getPositionX();
            float unlockAllMonMenuLayerPosX = unlockAllMonMenuLayer->getPositionX();
            unlockAllMonMenuLayer->setPositionX(unlockAllMonMenuLayerPosX-10);
            powerUpsMenuLayer->setPositionX(powerUpsMenuLayerPosX-40);
            powerUpsLabel->setPositionX(powerUpsLabelPosX-20);
            unlockAllMonLabel->setPositionX(unlockAllMonLabelPosX-10);
            powerUpsLabel->setFontSize(25);
            unlockAllMonLabel->setFontSize(23);
            
            dollerLabel1->setFontSize(25);
            dollerLabel2->setFontSize(25);
            dollerLabel3->setFontSize(25);
            dollerLabel4->setFontSize(25);
            dollerLabel5->setFontSize(25);
            dollerLabel6->setFontSize(25);
            storeMainLbl->setFontSize(50);
            
            largePaddleLabel->setFontSize(20);
            bonusPointLabel->setFontSize(20);
            bonusLifeLabel->setFontSize(20);
            autoPlayLabel->setFontSize(20);
            multiBallLabel->setFontSize(20);
            bulletLabel->setFontSize(20);
            
            totalCoinsCollected->setFontSize(45);
            totalCoinsLabelNotUsed->setFontSize(40);
            
            bulletLabelNotUsed->setFontSize(25);
            autoPlayLabelNotUsed->setFontSize(25);
            bonusLifeLabelNotUsed->setFontSize(25);
            bonusPointLabelNotUsed->setFontSize(25);
            laregPaddleLabelNotUsed->setFontSize(25);
            multiBallLabelNotUsed->setFontSize(25);
            
            buyLabelNotUsed1->setFontSize(25);
            buyLabelNotUsed2->setFontSize(25);
            buyLabelNotUsed3->setFontSize(25);
            buyLabelNotUsed4->setFontSize(25);
            buyLabelNotUsed5->setFontSize(25);
            buyLabelNotUsed6->setFontSize(25);
            buyLabelNotUsed7->setFontSize(25);
            
            restoreLabelNotUsed->setFontSize(25);
            unlockAllLabelNotUsed->setFontSize(25);
            effielTowerLabelNotUsed->setFontSize(25);
            bigBenLabelNotUsed->setFontSize(25);
            statueOfLibertyLabelNotUsed->setFontSize(25);
            towerOfPisaLabelNotUsed->setFontSize(25);
            colosseumLabelNotUsed->setFontSize(25);
            operaHouseLabelNotUsed->setFontSize(25);
            easterStoneLabelNotUsed->setFontSize(25);
            coinsPackLabelUnused->setFontSize(45);
            
        }
            break;
        case 4:{
            powerUpsMenuLayer->setScaleX(1.2);
            unlockAllMonMenuLayer->setScaleX(1.2);
            buyLabelNotUsed1->setPositionX(buyLabelNotUsed1PosX+10);
            buyLabelNotUsed2->setPositionX(buyLabelNotUsed2PosX+10);
            buyLabelNotUsed3->setPositionX(buyLabelNotUsed3PosX+10);
            buyLabelNotUsed4->setPositionX(buyLabelNotUsed4PosX+10);
            buyLabelNotUsed5->setPositionX(buyLabelNotUsed5PosX+10);
            buyLabelNotUsed6->setPositionX(buyLabelNotUsed6PosX+10);
            buyLabelNotUsed7->setPositionX(buyLabelNotUsed7PosX+10);
            
            
            unlockAllMenuItemSpr->setScaleX(0.9);
            restoreMenuItemSpr->setScaleX(0.9);
            buyLabel->setFontSize(25);
            float powerUpsLabelPosX = powerUpsLabel->getPositionX();
            float unlockAllMonLabelPosX = unlockAllMonLabel->getPositionX();
            float powerUpsMenuLayerPosX = powerUpsMenuLayer->getPositionX();
            float unlockAllMonMenuLayerPosX = unlockAllMonMenuLayer->getPositionX();
            unlockAllMonMenuLayer->setPositionX(unlockAllMonMenuLayerPosX-10);
            powerUpsMenuLayer->setPositionX(powerUpsMenuLayerPosX-40);
            powerUpsLabel->setPositionX(powerUpsLabelPosX-20);
            unlockAllMonLabel->setPositionX(unlockAllMonLabelPosX-10);
            powerUpsLabel->setFontSize(25);
            unlockAllMonLabel->setFontSize(23);
            
            dollerLabel1->setFontSize(25);
            dollerLabel2->setFontSize(25);
            dollerLabel3->setFontSize(25);
            dollerLabel4->setFontSize(25);
            dollerLabel5->setFontSize(25);
            dollerLabel6->setFontSize(25);
            storeMainLbl->setFontSize(50);
            
            largePaddleLabel->setFontSize(20);
            bonusPointLabel->setFontSize(20);
            bonusLifeLabel->setFontSize(20);
            autoPlayLabel->setFontSize(20);
            multiBallLabel->setFontSize(20);
            bulletLabel->setFontSize(20);
            
            totalCoinsCollected->setFontSize(45);
            totalCoinsLabelNotUsed->setFontSize(40);
            
            bulletLabelNotUsed->setFontSize(25);
            autoPlayLabelNotUsed->setFontSize(25);
            bonusLifeLabelNotUsed->setFontSize(25);
            bonusPointLabelNotUsed->setFontSize(25);
            laregPaddleLabelNotUsed->setFontSize(25);
            multiBallLabelNotUsed->setFontSize(25);
            
            buyLabelNotUsed1->setFontSize(25);
            buyLabelNotUsed2->setFontSize(25);
            buyLabelNotUsed3->setFontSize(25);
            buyLabelNotUsed4->setFontSize(25);
            buyLabelNotUsed5->setFontSize(25);
            buyLabelNotUsed6->setFontSize(25);
            buyLabelNotUsed7->setFontSize(25);
            
            restoreLabelNotUsed->setFontSize(25);
            unlockAllLabelNotUsed->setFontSize(25);
            effielTowerLabelNotUsed->setFontSize(25);
            bigBenLabelNotUsed->setFontSize(25);
            statueOfLibertyLabelNotUsed->setFontSize(25);
            towerOfPisaLabelNotUsed->setFontSize(25);
            colosseumLabelNotUsed->setFontSize(25);
            operaHouseLabelNotUsed->setFontSize(25);
            easterStoneLabelNotUsed->setFontSize(25);
            coinsPackLabelUnused->setFontSize(45);
            
        }
            break;
        case 5:{
            powerUpsMenuLayer->setScaleX(1.2);
            unlockAllMonMenuLayer->setScaleX(1.2);
            
            buyLabelNotUsed1->setPositionX(buyLabelNotUsed1PosX+10);
            buyLabelNotUsed2->setPositionX(buyLabelNotUsed2PosX+10);
            buyLabelNotUsed3->setPositionX(buyLabelNotUsed3PosX+10);
            buyLabelNotUsed4->setPositionX(buyLabelNotUsed4PosX+10);
            buyLabelNotUsed5->setPositionX(buyLabelNotUsed5PosX+10);
            buyLabelNotUsed6->setPositionX(buyLabelNotUsed6PosX+10);
            buyLabelNotUsed7->setPositionX(buyLabelNotUsed7PosX+10);
            
            
            unlockAllMenuItemSpr->setScaleX(0.9);
            restoreMenuItemSpr->setScaleX(0.9);
            buyLabel->setFontSize(25);
            float powerUpsLabelPosX = powerUpsLabel->getPositionX();
            float unlockAllMonLabelPosX = unlockAllMonLabel->getPositionX();
            float powerUpsMenuLayerPosX = powerUpsMenuLayer->getPositionX();
            float unlockAllMonMenuLayerPosX = unlockAllMonMenuLayer->getPositionX();
            unlockAllMonMenuLayer->setPositionX(unlockAllMonMenuLayerPosX-10);
            powerUpsMenuLayer->setPositionX(powerUpsMenuLayerPosX-40);
            powerUpsLabel->setPositionX(powerUpsLabelPosX-20);
            unlockAllMonLabel->setPositionX(unlockAllMonLabelPosX-10);
            powerUpsLabel->setFontSize(25);
            unlockAllMonLabel->setFontSize(23);
            
            dollerLabel1->setFontSize(25);
            dollerLabel2->setFontSize(25);
            dollerLabel3->setFontSize(25);
            dollerLabel4->setFontSize(25);
            dollerLabel5->setFontSize(25);
            dollerLabel6->setFontSize(25);
            storeMainLbl->setFontSize(50);
            
            largePaddleLabel->setFontSize(20);
            bonusPointLabel->setFontSize(20);
            bonusLifeLabel->setFontSize(20);
            autoPlayLabel->setFontSize(20);
            multiBallLabel->setFontSize(20);
            bulletLabel->setFontSize(20);
            
            totalCoinsCollected->setFontSize(45);
            totalCoinsLabelNotUsed->setFontSize(40);
            
            bulletLabelNotUsed->setFontSize(25);
            autoPlayLabelNotUsed->setFontSize(25);
            bonusLifeLabelNotUsed->setFontSize(25);
            bonusPointLabelNotUsed->setFontSize(25);
            laregPaddleLabelNotUsed->setFontSize(25);
            multiBallLabelNotUsed->setFontSize(25);
            
            buyLabelNotUsed1->setFontSize(25);
            buyLabelNotUsed2->setFontSize(25);
            buyLabelNotUsed3->setFontSize(25);
            buyLabelNotUsed4->setFontSize(25);
            buyLabelNotUsed5->setFontSize(25);
            buyLabelNotUsed6->setFontSize(25);
            buyLabelNotUsed7->setFontSize(25);
            
            restoreLabelNotUsed->setFontSize(25);
            unlockAllLabelNotUsed->setFontSize(25);
            effielTowerLabelNotUsed->setFontSize(25);
            bigBenLabelNotUsed->setFontSize(25);
            statueOfLibertyLabelNotUsed->setFontSize(25);
            towerOfPisaLabelNotUsed->setFontSize(25);
            colosseumLabelNotUsed->setFontSize(25);
            operaHouseLabelNotUsed->setFontSize(25);
            easterStoneLabelNotUsed->setFontSize(25);
            coinsPackLabelUnused->setFontSize(45);
        }
            break;
        case 6:{
            unlockAllMenuItemSpr->setScaleX(0.9);
            restoreMenuItemSpr->setScaleX(0.9);
        }
            break;
            
        default:
            break;
    }
    schedule(schedule_selector(InAppPurchaseLayer::updateInterval), 2);
    
    
    updateUIAfterPurchase();
    
    
    
}

void InAppPurchaseLayer::updateUIAfterPurchase()
{
    this->setTouchEnabled(true);
    bool inAppUnlockAllMonuments = CCUserDefault::sharedUserDefault()->getBoolForKey("com.r3app.bricksbreaker.unlockAllMonuments");
    if(inAppUnlockAllMonuments==true){
        powerUpsLabel->setOpacity(100);
        unlockAllMonLabel->setOpacity(100);
        restoreMenuItemSpr->setEnabled(false);
        unlockAllMenuItemSpr->setEnabled(false);
        unlockAllMenuItemSpr->setColor(ccc3(255,69,0));
        unlockAllMenuItemSpr->setOpacity(100);
        restoreMenuItemSpr->setColor(ccc3(255,69,0));
        restoreMenuItemSpr->setOpacity(100);
    }
    else{
        
        unlockAllMenuItemSpr->setColor(ccc3(170, 170, 170));
        restoreMenuItemSpr->setColor(ccc3(170, 170, 170));
    }
    unLockReflectToAllMonuments();
}
void InAppPurchaseLayer::unLockReflectToAllMonuments(){
    
    bool inAppEffielTower = CCUserDefault::sharedUserDefault()->getBoolForKey("com.r3app.bricksbreaker.unlock_eiffel_tower");
    bool inAppStatueOfLiberty = CCUserDefault::sharedUserDefault()->getBoolForKey("com.r3app.bricksbreaker.unlock_statue_of_liberty");
    bool inAppTowerOfPisa = CCUserDefault::sharedUserDefault()->getBoolForKey("com.r3app.bricksbreaker.unlock_leaning_tower");
    bool inAppBigBen = CCUserDefault::sharedUserDefault()->getBoolForKey("com.r3app.bricksbreaker.unlock_big_ban");
    bool inAppColosseum = CCUserDefault::sharedUserDefault()->getBoolForKey("com.r3app.bricksbreaker.unlock_colosseum");
    bool inAppOperaHouse = CCUserDefault::sharedUserDefault()->getBoolForKey("com.r3app.bricksbreaker.unlock_sydney_opera_house");
    bool inAppEasterStone = CCUserDefault::sharedUserDefault()->getBoolForKey("com.r3app.bricksbreaker.unlock_easter_island_stone");
    int deviceResolution = GameManager::sharedGameManager()->get_devise_resolution();
    
    if(inAppEffielTower==true)
    {
        buyBtn1->setVisible(true);
        
        buyBtn1->setColor(ccc3(170,170,170));
        buyBtn1->setOpacity(100);
        buyBtn1->setEnabled(false);
        if(deviceResolution==1|| deviceResolution==6){
            buyLabelNotUsed1->setFontSize(35);
            buyLabelNotUsed1->setPositionX(buyLabelNotUsed3PosX-15);}
        else{
            buyLabelNotUsed1->setFontSize(20);
            buyLabelNotUsed1->setPositionX(buyLabelNotUsed1PosX-20);
        }
        buyLabelNotUsed1->setString("Purchased");
        
    }else{
        if(deviceResolution==1||deviceResolution==6)
            buyLabelNotUsed1->setPositionX(buyLabelNotUsed1PosX+30);
    }
    if(inAppStatueOfLiberty==true)
    {
        buyBtn2->setVisible(true);
        
        buyBtn2->setColor(ccc3(170,170,170));
        buyBtn2->setOpacity(100);
        buyBtn2->setEnabled(false);
        buyLabelNotUsed2->setString("Purchased");
        if(deviceResolution==1|| deviceResolution==6){
            buyLabelNotUsed2->setFontSize(35);
            buyLabelNotUsed2->setPositionX(buyLabelNotUsed2PosX-15);
        }
        else{
            buyLabelNotUsed2->setFontSize(20);
            buyLabelNotUsed2->setPositionX(buyLabelNotUsed2PosX-20);}
        
    }
    else{
        if(deviceResolution==1||deviceResolution==6)
            buyLabelNotUsed2->setPositionX(buyLabelNotUsed1PosX+30);
    }
    if(inAppTowerOfPisa==true)
    {
        buyBtn3->setVisible(true);
        
        buyBtn3->setColor(ccc3(170,170,170));
        buyBtn3->setOpacity(100);
        buyBtn3->setEnabled(false);
        buyLabelNotUsed3->setString("Purchased");
        if(deviceResolution==1|| deviceResolution==6){
            buyLabelNotUsed3->setFontSize(35);
            buyLabelNotUsed3->setPositionX(buyLabelNotUsed3PosX-15);}
        else{
            buyLabelNotUsed3->setFontSize(20);
            buyLabelNotUsed3->setPositionX(buyLabelNotUsed3PosX-20);}
        
    }
    else{
        if(deviceResolution==1||deviceResolution==6)
            buyLabelNotUsed3->setPositionX(buyLabelNotUsed1PosX+30);
    }
    if(inAppBigBen==true)
    {
        buyBtn4->setVisible(true);
        
        buyBtn4->setColor(ccc3(170,170,170));
        buyBtn4->setOpacity(100);
        buyBtn4->setEnabled(false);
        buyLabelNotUsed4->setString("Purchased");
        if(deviceResolution==1|| deviceResolution==6){
            buyLabelNotUsed4->setFontSize(35);
            buyLabelNotUsed4->setPositionX(buyLabelNotUsed3PosX-15);}
        else{
            buyLabelNotUsed4->setFontSize(20);
            buyLabelNotUsed4->setPositionX(buyLabelNotUsed4PosX-20);}
        
    }
    else{
        if(deviceResolution==1||deviceResolution==6)
            buyLabelNotUsed4->setPositionX(buyLabelNotUsed1PosX+30);
    }
    if(inAppColosseum==true)
    {
        buyBtn5->setVisible(true);
        
        buyBtn5->setColor(ccc3(170,170,170));
        buyBtn5->setOpacity(100);
        buyBtn5->setEnabled(false);
        buyLabelNotUsed5->setString("Purchased");
        if(deviceResolution==1|| deviceResolution==6){
            buyLabelNotUsed5->setFontSize(35);
            buyLabelNotUsed5->setPositionX(buyLabelNotUsed3PosX-15);}
        else{
            buyLabelNotUsed5->setFontSize(20);
            buyLabelNotUsed5->setPositionX(buyLabelNotUsed5PosX-20);}
        
    }
    else{
        if(deviceResolution==1||deviceResolution==6)
            buyLabelNotUsed5->setPositionX(buyLabelNotUsed1PosX+30);
    }
    if(inAppOperaHouse==true)
    {
        buyBtn6->setVisible(true);
        
        buyBtn6->setColor(ccc3(170,170,170));
        buyBtn6->setOpacity(100);
        buyBtn6->setEnabled(false);
        buyLabelNotUsed6->setString("Purchased");
        if(deviceResolution==1|| deviceResolution==6){
            buyLabelNotUsed6->setFontSize(35);
            buyLabelNotUsed6->setPositionX(buyLabelNotUsed3PosX-15);}
        else{
            buyLabelNotUsed6->setFontSize(20);
            buyLabelNotUsed6->setPositionX(buyLabelNotUsed6PosX-20);}
        
    }
    else{
        if(deviceResolution==1||deviceResolution==6)
            buyLabelNotUsed6->setPositionX(buyLabelNotUsed1PosX+30);
    }
    if(inAppEasterStone==true)
    {
        buyBtn7->setVisible(true);
        buyBtn7->setColor(ccc3(170,170,170));
        buyBtn7->setEnabled(false);
        buyBtn7->setOpacity(100);
        buyLabelNotUsed7->setString("Purchased");
        if(deviceResolution==1|| deviceResolution==6){
            buyLabelNotUsed7->setFontSize(35);
            buyLabelNotUsed7->setPositionX(buyLabelNotUsed3PosX-15);}
        else{
            buyLabelNotUsed7->setFontSize(20);
            buyLabelNotUsed7->setPositionX(buyLabelNotUsed7PosX-20);}
        
    }
    else{
        if(deviceResolution==1||deviceResolution==6)
            buyLabelNotUsed7->setPositionX(buyLabelNotUsed1PosX+20);
    }
}

void InAppPurchaseLayer::onBuyFiveHundredCoinsClicked(cocos2d::CCObject *sender)
{
    isConnectToInternet = ObjCCalls::tryIsInternetConnection();
    if(isConnectToInternet ==false)
    {
        ObjCCalls::openToastAlert();
        return;
    }
    isCoinRequireUpdate=true;
    ObjCCalls::purchaseFiveHundredCoins();
}

void InAppPurchaseLayer::updateInterval(){
}

void InAppPurchaseLayer::updateScalingForFBAndCoin(CCMenuItemImage *coinSpr,CCMenuItemImage *faceBookSpr){
    CCMenuItemImage *localcoinMenuSpr1 = (CCMenuItemImage*)coinSpr;
    
    CCActionInterval *scale = CCScaleTo::create(0.2, 1.3);
    CCActionInterval *scaleBack = CCScaleTo::create(0.5, 1);
    CCActionInterval *repeatForEver = CCRepeatForever::create(CCSequence::createWithTwoActions(scale,scaleBack));
    localcoinMenuSpr1->runAction(repeatForEver);
}

SEL_CallFuncN InAppPurchaseLayer::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
    return NULL;
}

SEL_MenuHandler InAppPurchaseLayer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onBackClicked", InAppPurchaseLayer::onBackClicked);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onCoinPurchaseClicked", InAppPurchaseLayer::onCoinPurchaseClicked);
    
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onBuyFiveHundredCoinsClicked", InAppPurchaseLayer::onBuyFiveHundredCoinsClicked);
    
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onBuyButtonClicked", InAppPurchaseLayer::onBuyButtonClicked);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onUnlockAllClicked", InAppPurchaseLayer::onUnlockAllClicked);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onRestoreAllClicked", InAppPurchaseLayer::onRestoreAllClicked);
    
    
    //    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "settingBtnClicked", InAppPurchaseLayer::settingBtnClicked);
    //    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onForGroundSoundClicked", InAppPurchaseLayer::onForGroundSoundClicked);
    //    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onBackGroundSoundClicked", InAppPurchaseLayer::onBackGroundSoundClicked);
    
    return NULL;
}

SEL_CCControlHandler InAppPurchaseLayer::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}

bool InAppPurchaseLayer::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    bool bRet = false;
    return bRet;
}
bool InAppPurchaseLayer::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "menuBackLayer",CCLayerColor *, this->menuBackLayer);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "bulletCoinLayer",CCLayerColor *, this->bulletCoinLayer);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "multiBallCoinLayer",CCLayerColor *, this->multiBallCoinLayer);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "autoPlayCoinLayer",CCLayerColor *, this->autoPlayCoinLayer);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "bonusLifeCoinLayer",CCLayerColor *, this->bonusLifeCoinLayer);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "bonusPointCoinLayer",CCLayerColor *, this->bonusPointCoinLayer);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "unlockAllMonumentsMainLayer",CCLayerColor *, this->unlockAllMonumentsMainLayer);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "laregPaddleLayer",CCLayerColor *, this->laregPaddleLayer);
    
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "effielLayer",CCLayerColor *, this->effielLayer);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "statueLayer",CCLayerColor *, this->statueLayer);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "towerLayer",CCLayerColor *, this->towerLayer);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "bigLayer",CCLayerColor *, this->bigLayer);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "colosseumLayer",CCLayerColor *, this->colosseumLayer);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "operaLayer",CCLayerColor *, this->operaLayer);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "easterLayer",CCLayerColor *, this->easterLayer);
    
    
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "totalCoinsCollected",CCLabelTTF *, this->totalCoinsCollected);
    
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "largePaddleLabel",CCLabelTTF *, this->largePaddleLabel);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "bonusPointLabel",CCLabelTTF *, this->bonusPointLabel);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "bonusLifeLabel",CCLabelTTF *, this->bonusLifeLabel);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "autoPlayLabel",CCLabelTTF *, this->autoPlayLabel);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "multiBallLabel",CCLabelTTF *, this->multiBallLabel);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "bulletLabel",CCLabelTTF *, this->bulletLabel);
    
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "dollerLabel1",CCLabelTTF *, this->dollerLabel1);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "dollerLabel2",CCLabelTTF *, this->dollerLabel2);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "dollerLabel3",CCLabelTTF *, this->dollerLabel3);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "dollerLabel4",CCLabelTTF *, this->dollerLabel4);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "dollerLabel5",CCLabelTTF *, this->dollerLabel5);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "dollerLabel6",CCLabelTTF *, this->dollerLabel6);
    
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "buyLabelNotUsed1",CCLabelTTF *, this->buyLabelNotUsed1);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "buyLabelNotUsed2",CCLabelTTF *, this->buyLabelNotUsed2);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "buyLabelNotUsed3",CCLabelTTF *, this->buyLabelNotUsed3);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "buyLabelNotUsed4",CCLabelTTF *, this->buyLabelNotUsed4);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "buyLabelNotUsed5",CCLabelTTF *, this->buyLabelNotUsed5);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "buyLabelNotUsed6",CCLabelTTF *, this->buyLabelNotUsed6);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "buyLabelNotUsed7",CCLabelTTF *, this->buyLabelNotUsed7);
    
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "bulletLabelNotUsed",CCLabelTTF *, this->bulletLabelNotUsed);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "multiBallLabelNotUsed",CCLabelTTF *, this->multiBallLabelNotUsed);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "autoPlayLabelNotUsed",CCLabelTTF *, this->autoPlayLabelNotUsed);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "bonusLifeLabelNotUsed",CCLabelTTF *, this->bonusLifeLabelNotUsed);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "bonusPointLabelNotUsed",CCLabelTTF *, this->bonusPointLabelNotUsed);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "laregPaddleLabelNotUsed",CCLabelTTF *, this->laregPaddleLabelNotUsed);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "storeMainLbl",CCLabelTTF *, this->storeMainLbl);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "totalCoinsLabelNotUsed",CCLabelTTF *, this->totalCoinsLabelNotUsed);
    
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "coinMenuSpr1",CCMenuItemImage *, this->coinMenuSpr1);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "coinMenuSpr2",CCMenuItemImage *, this->coinMenuSpr2);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "coinMenuSpr3",CCMenuItemImage *, this->coinMenuSpr3);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "coinMenuSpr4",CCMenuItemImage *, this->coinMenuSpr4);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "coinMenuSpr5",CCMenuItemImage *, this->coinMenuSpr5);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "coinMenuSpr6",CCMenuItemImage *, this->coinMenuSpr6);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "restoreMenuItemSpr",CCMenuItemImage *, this->restoreMenuItemSpr);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "unlockAllMenuItemSpr",CCMenuItemImage *, this->unlockAllMenuItemSpr);
    
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "buyLabel",CCLabelTTF *, this->buyLabel);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "unlockAllMonLabel",CCLabelTTF *, this->unlockAllMonLabel);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "coinsPackLabelUnused",CCLabelTTF *, this->coinsPackLabelUnused);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "powerUpsLabel",CCLabelTTF *, this->powerUpsLabel);
    
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "restoreLabelNotUsed",CCLabelTTF *, this->restoreLabelNotUsed);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "unlockAllLabelNotUsed",CCLabelTTF *, this->unlockAllLabelNotUsed);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "effielTowerLabelNotUsed",CCLabelTTF *, this->effielTowerLabelNotUsed);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "statueOfLibertyLabelNotUsed",CCLabelTTF *, this->statueOfLibertyLabelNotUsed);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "towerOfPisaLabelNotUsed",CCLabelTTF *, this->towerOfPisaLabelNotUsed);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "bigBenLabelNotUsed",CCLabelTTF *, this->bigBenLabelNotUsed);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "colosseumLabelNotUsed",CCLabelTTF *, this->colosseumLabelNotUsed);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "operaHouseLabelNotUsed",CCLabelTTF *, this->operaHouseLabelNotUsed);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "easterStoneLabelNotUsed",CCLabelTTF *, this->easterStoneLabelNotUsed);
    
    
    
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "unlockAllMonMenuLayer",CCLayerColor *, this->unlockAllMonMenuLayer);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "powerUpsMenuLayer",CCLayerColor *, this->powerUpsMenuLayer);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "buyMenuItem",CCMenuItemImage *, this->buyMenuItem);
    
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "buyBtn1",CCMenuItemImage *, this->buyBtn1);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "buyBtn2",CCMenuItemImage *, this->buyBtn2);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "buyBtn3",CCMenuItemImage *, this->buyBtn3);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "buyBtn4",CCMenuItemImage *, this->buyBtn4);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "buyBtn5",CCMenuItemImage *, this->buyBtn5);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "buyBtn6",CCMenuItemImage *, this->buyBtn6);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "buyBtn7",CCMenuItemImage *, this->buyBtn7);
    
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "powerUpsMainLayer",CCLayerColor *, this->powerUpsMainLayer);
    
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "segmentControlLayer", CCLayerColor*, segmentControlLayer);
    
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "buyLayer1", CCLayerColor*, buyLayer1);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "buyLayer2", CCLayerColor*, buyLayer2);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "buyLayer3", CCLayerColor*, buyLayer3);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "buyLayer4", CCLayerColor*, buyLayer4);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "buyLayer5", CCLayerColor*, buyLayer5);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "buyLayer6", CCLayerColor*, buyLayer6);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "buyLayer7", CCLayerColor*, buyLayer7);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "coinLayer1", CCLayerColor*, coinLayer1);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "coinLayer2", CCLayerColor*, coinLayer2);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "coinLayer3", CCLayerColor*, coinLayer3);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "coinLayer4", CCLayerColor*, coinLayer4);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "coinLayer5", CCLayerColor*, coinLayer5);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "coinLayer6", CCLayerColor*, coinLayer6);
    
    return false;
}

void InAppPurchaseLayer::CoinsPurchaseFinished()
{
    isConnectToInternet = ObjCCalls::tryIsInternetConnection();
    if(isConnectToInternet ==false)
    {
        ObjCCalls::openToastAlert();
        return;
    }
    if(isCoinRequireUpdate==true){
        isCoinRequireUpdate=false;
        int totalCoins = CCUserDefault::sharedUserDefault()->getIntegerForKey("COINCOUNT");
        totalCoins  = totalCoins+500;
        totalCoinsCollected->setString(CCString::createWithFormat("%d",totalCoins)->getCString());
        CCUserDefault::sharedUserDefault()->setIntegerForKey("COINCOUNT",totalCoins);
        CCUserDefault::sharedUserDefault()->flush();
        CCLOG("PurchaseFinished called");
        
    }
}
void InAppPurchaseLayer::MonumentPurchaseFinished()
{
    if(isMonumentPurchased==true || isRestorePurchased==true){
        isMonumentPurchased=false;
        updateUIAfterPurchase();
    }
}


void InAppPurchaseLayer::onBackClicked(cocos2d::CCObject *pSender){
    ObjCCalls::showActivityIndictor();
    GameManager::sharedGameManager()->remove_unused_data();
    CCScene *highScore_scene=GameManager::sharedGameManager()->get_scene("MenuLayer.ccbi", "MenuLayer",MenuLayerLoader::loader(), CCScene::create(),false,false);
   	CCDirector::sharedDirector()->replaceScene(CCTransitionTurnOffTiles::create(0.1,highScore_scene));
}

void InAppPurchaseLayer::onUnlockAllClicked(cocos2d::CCObject *sender)
{
    isConnectToInternet = ObjCCalls::tryIsInternetConnection();
    if(isConnectToInternet ==false)
    {
        ObjCCalls::openToastAlert();
        return;
    }
    isMonumentPurchased=true;
    ObjCCalls::unlockAllMonuments();
}

void InAppPurchaseLayer::onRestoreAllClicked(cocos2d::CCObject *sender)
{
    isConnectToInternet = ObjCCalls::tryIsInternetConnection();
    if(isConnectToInternet ==false)
    {
        ObjCCalls::openToastAlert();
        return;
    }
    isRestorePurchased=true;
    ObjCCalls::restoreInAppPurchase();
}

void InAppPurchaseLayer::onUnlockAllMonumentsClicked(cocos2d::CCObject *pSender)
{
    isPowerLayerVisible=false;
    powerUpsLabel->setColor(ccBLACK);
    unlockAllMonLabel->setColor(ccWHITE);
    powerUpsMenuLayer->setColor(ccc3(200, 200, 200));
    unlockAllMonMenuLayer->setColor(ccc3(100,100,100));
    powerUpsMainLayer->setVisible(false);
    unlockAllMonumentsMainLayer->setVisible(true);
}
void InAppPurchaseLayer::onPowerUpsClicked(cocos2d::CCObject *sender)
{
    isPowerLayerVisible=true;
    powerUpsLabel->setColor(ccWHITE);
    unlockAllMonLabel->setColor(ccBLACK);
    powerUpsMenuLayer->setColor(ccc3(100,100,100));
    unlockAllMonMenuLayer->setColor(ccc3(200, 200, 200));
    powerUpsMainLayer->setVisible(true);
    unlockAllMonumentsMainLayer->setVisible(false);
}

void InAppPurchaseLayer::onBuyButtonClicked(cocos2d::CCObject *sender,int tag){
    CCMenuItemImage *coinMenuSpr = (CCMenuItemImage*)sender;
    isConnectToInternet = ObjCCalls::tryIsInternetConnection();
    if(isConnectToInternet ==false)
    {
        ObjCCalls::openToastAlert();
        return;
    }
    
    isMonumentPurchased=true;
    int coinMenuSprTag;
    
    if(sender==NULL ||coinMenuSpr==NULL)
        coinMenuSprTag=tag;
    else
        coinMenuSprTag=coinMenuSpr->getTag();
    
    switch (coinMenuSprTag) {
        case 11:{
            ObjCCalls::purchaseEffielTower();
        }
            break;
        case 12:{
            ObjCCalls::purchaseStatueueOfLiberty();
        }
            break;
        case 13:{
            ObjCCalls::purchaseTowerOfPisa();
        }
            break;
        case 14:{
            ObjCCalls::purchaseBigBen();
        }
            break;
        case 15:{
            ObjCCalls::purchaseColosseum();
            
        }
            break;
        case 16:{
            ObjCCalls::purchaseOperaHouse();
        }
            break;
        case 17:{
            ObjCCalls::purchaseEasterStone();
            
        }
            break;
            
        default:
            break;
    }
}

void InAppPurchaseLayer::onCoinPurchaseClicked(cocos2d::CCObject *pSender,int tag)
{
    isConnectToInternet = ObjCCalls::tryIsInternetConnection();
    if(isConnectToInternet ==false)
    {
        ObjCCalls::openToastAlert();
        return;
    }
    int resolution = GameManager::sharedGameManager()->get_devise_resolution();
    CCMenuItemImage *coinMenuSpr = (CCMenuItemImage*)pSender;
    int totalCoins = CCUserDefault::sharedUserDefault()->getIntegerForKey("COINCOUNT");
    
    int coinMenuSprTag;
    if(pSender==NULL || coinMenuSpr==NULL)
        coinMenuSprTag = tag;
    else
        coinMenuSprTag=coinMenuSpr->getTag();
    
    if(totalCoins<40){
        isCoinRequireUpdate=true;
        ObjCCalls::alertForCoinsBuy();
        return;}
    
    switch (coinMenuSprTag) {
        case 11:{
            //Bullet Timer Setting
            int loacldollerLabel1Int = dollerLabel1Int;
            if(totalCoins<loacldollerLabel1Int){
                isCoinRequireUpdate=true;
                ObjCCalls::alertForCoinsBuy();
                return;}
            int localbulletTimerCount = bulletTimerCount;
            if(localbulletTimerCount>8){
                coinMenuSpr1->setOpacity(100);
                dollerLabel1->setString("Limit exceeds");
                if(resolution==1 || resolution==6)
                    dollerLabel1->setFontSize(35);
                else
                    dollerLabel1->setFontSize(20);
                return;
            }
            
            totalCoins = totalCoins-loacldollerLabel1Int;
            localbulletTimerCount = localbulletTimerCount+1;
            loacldollerLabel1Int = loacldollerLabel1Int+100;
            dollerLabel1->setString(CCString::createWithFormat("%d Coins",loacldollerLabel1Int)->getCString());
            bulletLabel->setString(CCString::createWithFormat("%d Seconds",localbulletTimerCount)->getCString());
            CCUserDefault::sharedUserDefault()->setIntegerForKey("BULLETTIMERCOUNTER",localbulletTimerCount);
            CCUserDefault::sharedUserDefault()->setIntegerForKey("DOLLERLABEL1", loacldollerLabel1Int);
            bulletTimerCount=localbulletTimerCount;
            dollerLabel1Int=loacldollerLabel1Int;
        }
            break;
        case 12:{
            //Extra Multi Ball Setting
            int loacldollerLabel2Int = dollerLabel2Int;
            if(totalCoins<loacldollerLabel2Int)
            {
                isCoinRequireUpdate=true;
                ObjCCalls::alertForCoinsBuy();
                return;}
            int localmultiBallCount = multiBallCount;
            if(localmultiBallCount>2){
                coinMenuSpr2->setOpacity(100);
                dollerLabel2->setString("Limit exceeds");
                if(resolution==1 || resolution==6)
                    dollerLabel2->setFontSize(35);
                else
                    dollerLabel2->setFontSize(20);
                return;
            }
            totalCoins = totalCoins-loacldollerLabel2Int;
            localmultiBallCount=localmultiBallCount+1;
            loacldollerLabel2Int = loacldollerLabel2Int+160;
            dollerLabel2->setString(CCString::createWithFormat("%d Coins",loacldollerLabel2Int)->getCString());
            multiBallLabel->setString(CCString::createWithFormat("%d Ball Extra",localmultiBallCount)->getCString());
            CCUserDefault::sharedUserDefault()->setIntegerForKey("EXTRAMULTIBALLCOUNTER",localmultiBallCount);
            CCUserDefault::sharedUserDefault()->setIntegerForKey("DOLLERLABEL2",loacldollerLabel2Int);
            multiBallCount=localmultiBallCount;
            dollerLabel2Int= loacldollerLabel2Int;
            
        }
            break;
        case 13:{
            //Auto Play Timer Setting
            int loacldollerLabel3Int = dollerLabel3Int;
            if(totalCoins<loacldollerLabel3Int)
            {isCoinRequireUpdate=true;
                ObjCCalls::alertForCoinsBuy();
                return;}
            int localautoPlayCount = autoPlayCount;
            if(localautoPlayCount>8){
                dollerLabel3->setString("Limit exceeds");
                coinMenuSpr3->setOpacity(100);
                if(resolution==1 || resolution==6)
                    dollerLabel3->setFontSize(35);
                else
                    dollerLabel3->setFontSize(20);
                
                return;
            }
            totalCoins = totalCoins-loacldollerLabel3Int;
            loacldollerLabel3Int = loacldollerLabel3Int+40;
            localautoPlayCount=localautoPlayCount+1;
            autoPlayLabel->setString(CCString::createWithFormat("%d Seconds",localautoPlayCount)->getCString());
            
            dollerLabel3->setString(CCString::createWithFormat("%d Coins",loacldollerLabel3Int)->getCString());
            CCUserDefault::sharedUserDefault()->setIntegerForKey("AUTOPLAYTIMERCOUNTER",localautoPlayCount);
            CCUserDefault::sharedUserDefault()->setIntegerForKey("DOLLERLABEL3",loacldollerLabel3Int);
            autoPlayCount= localautoPlayCount;
            dollerLabel3Int=loacldollerLabel3Int;
            
            
        }
            break;
        case 14:{
            //Bonus Life Setting
            int loacldollerLabel4Int = dollerLabel4Int;
            
            if(totalCoins<loacldollerLabel4Int)
            {
                isCoinRequireUpdate=true;
                ObjCCalls::alertForCoinsBuy();
                return;}
            
            int localbonusLifeCount = bonusLifeCount;
            if(localbonusLifeCount>5)
            {
                dollerLabel4->setString("Limit exceeds");
                coinMenuSpr4->setOpacity(100);
                if(resolution==1 || resolution==6)
                    dollerLabel4->setFontSize(35);
                else
                    dollerLabel4->setFontSize(20);
                
                return;
            }
            totalCoins = totalCoins-loacldollerLabel4Int;
            loacldollerLabel4Int = loacldollerLabel4Int+80;
            localbonusLifeCount = localbonusLifeCount+1;
            bonusLifeLabel->setString(CCString::createWithFormat("%d Life Bonus",localbonusLifeCount)->getCString());
            dollerLabel4->setString(CCString::createWithFormat("%d Coins",loacldollerLabel4Int)->getCString());
            CCUserDefault::sharedUserDefault()->setIntegerForKey("DOLLERLABEL4",loacldollerLabel4Int);
            CCUserDefault::sharedUserDefault()->setIntegerForKey("BONUSLIFECOUNTER",localbonusLifeCount);
            bonusLifeCount= localbonusLifeCount;
            dollerLabel4Int=loacldollerLabel4Int;
            
        }
            break;
        case 15:{
            //Bonus Points Setting
            int localdollerLabel5Int = dollerLabel5Int;
            int localbonusPointsCount = bonusPointsCount;
            if(totalCoins<=100)
            {
                isCoinRequireUpdate=true;
                ObjCCalls::alertForCoinsBuy();
                return;}
            totalCoins = totalCoins-100;
            localbonusPointsCount = localbonusPointsCount+100;
            bonusPointLabel->setString(CCString::createWithFormat("%d Bonus",localbonusPointsCount)->getCString());
            CCUserDefault::sharedUserDefault()->setIntegerForKey("DOLLERLABEL5",localdollerLabel5Int);
            CCUserDefault::sharedUserDefault()->setIntegerForKey("BONUSPOINTCOUNTER",localbonusPointsCount);
            bonusPointsCount=localbonusPointsCount;
            dollerLabel5Int=localdollerLabel5Int;
        }
            break;
        case 16:{
            //Large Paddle Setting
            int loacldollerLabel6Int = dollerLabel6Int;
            if(totalCoins<loacldollerLabel6Int)
            {   isCoinRequireUpdate=true;
                ObjCCalls::alertForCoinsBuy();
                return;}
            int locallargePaddleCount = largePaddleCounter;
            if(locallargePaddleCount>8){
                dollerLabel6->setString("Limit exceeds");
                coinMenuSpr6->setOpacity(100);
                if(resolution==1 || resolution==6)
                    dollerLabel6->setFontSize(35);
                else
                    dollerLabel6->setFontSize(20);
                return;
            }
            
            totalCoins=totalCoins-loacldollerLabel6Int;
            loacldollerLabel6Int = loacldollerLabel6Int+160;
            locallargePaddleCount = locallargePaddleCount+1;
            largePaddleLabel->setString(CCString::createWithFormat("%d Seconds",locallargePaddleCount)->getCString());
            
            dollerLabel6->setString(CCString::createWithFormat("%d Coins",loacldollerLabel6Int)->getCString());
            CCUserDefault::sharedUserDefault()->setIntegerForKey("DOLLERLABEL6",loacldollerLabel6Int);
            CCUserDefault::sharedUserDefault()->setIntegerForKey("LARGEPADDLECOUNTER",locallargePaddleCount);
            largePaddleCounter=locallargePaddleCount;
            dollerLabel6Int=loacldollerLabel6Int;
            
        }
            break;
            
        default:
            break;
    }
    
    SoundManager::sharedSoundManager()->playSoundEffect("Sound/Coin Pickup 2 Final.wav", false);
    
    CCUserDefault::sharedUserDefault()->setIntegerForKey("COINCOUNT",totalCoins);
    CCUserDefault::sharedUserDefault()->flush();
    totalCoinsCollected->setString(CCString::createWithFormat("%d",totalCoins)->getCString());
}


void InAppPurchaseLayer::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent)
{
    CCTouch *myTouch = (CCTouch*) pTouches->anyObject();
    CCPoint location = myTouch->getLocationInView();
    location = CCDirector::sharedDirector()->convertToGL(location);
    if(GameManager::sharedGameManager()->isNodeAtPoint(powerUpsMenuLayer, location))
    {
        onPowerUpsClicked(NULL);
    }
    if (GameManager::sharedGameManager()->isNodeAtPoint(unlockAllMonMenuLayer, location)) {
        onUnlockAllMonumentsClicked(NULL);
    }
    
    if(GameManager::sharedGameManager()->isNodeAtPoint(menuBackLayer, location))
    {
        onBackClicked(NULL);
        return;
    }
    if(isPowerLayerVisible==true)
    {
        if(GameManager::sharedGameManager()->isNodeAtPoint(coinLayer6, location)){
            onCoinPurchaseClicked(NULL, 11);
            return;
        }
        if(GameManager::sharedGameManager()->isNodeAtPoint(coinLayer5, location)){
            onCoinPurchaseClicked(NULL, 12);
            return;
        }
        if(GameManager::sharedGameManager()->isNodeAtPoint(coinLayer4, location)){
            onCoinPurchaseClicked(NULL, 13);
            return;
        }
        if(GameManager::sharedGameManager()->isNodeAtPoint(coinLayer3, location)){
            onCoinPurchaseClicked(NULL, 14);
            return;
            
        }
        if(GameManager::sharedGameManager()->isNodeAtPoint(coinLayer2, location)){
            onCoinPurchaseClicked(NULL, 15);
            return;
            
        }
        if(GameManager::sharedGameManager()->isNodeAtPoint(coinLayer1, location)){
            onCoinPurchaseClicked(NULL, 16);
            return;
        }
    }
    else
    {
        bool inAppEffielTower = CCUserDefault::sharedUserDefault()->getBoolForKey("com.r3app.bricksbreaker.unlock_eiffel_tower");
        bool inAppStatueOfLiberty = CCUserDefault::sharedUserDefault()->getBoolForKey("com.r3app.bricksbreaker.unlock_statue_of_liberty");
        bool inAppTowerOfPisa = CCUserDefault::sharedUserDefault()->getBoolForKey("com.r3app.bricksbreaker.unlock_leaning_tower");
        bool inAppBigBen = CCUserDefault::sharedUserDefault()->getBoolForKey("com.r3app.bricksbreaker.unlock_big_ban");
        bool inAppColosseum = CCUserDefault::sharedUserDefault()->getBoolForKey("com.r3app.bricksbreaker.unlock_colosseum");
        bool inAppOperaHouse = CCUserDefault::sharedUserDefault()->getBoolForKey("com.r3app.bricksbreaker.unlock_sydney_opera_house");
        bool inAppEasterStone = CCUserDefault::sharedUserDefault()->getBoolForKey("com.r3app.bricksbreaker.unlock_easter_island_stone");
        //============================Monument Purchase=================
        if(GameManager::sharedGameManager()->isNodeAtPoint(buyLayer1, location)){
            if(inAppEffielTower==true)
                return;
            onBuyButtonClicked(NULL, 11);
            return;
        }
        if(GameManager::sharedGameManager()->isNodeAtPoint(buyLayer2, location)){
            if(inAppStatueOfLiberty==true)
                return;
            onBuyButtonClicked(NULL, 12);
            return;
        }
        if(GameManager::sharedGameManager()->isNodeAtPoint(buyLayer3, location)){
            if(inAppTowerOfPisa==true)
                return;
            onBuyButtonClicked(NULL, 13);
            return;
        }
        if(GameManager::sharedGameManager()->isNodeAtPoint(buyLayer4, location)){
            if(inAppBigBen==true)
                return;
            onBuyButtonClicked(NULL, 14);
            return;
        }
        if(GameManager::sharedGameManager()->isNodeAtPoint(buyLayer5, location)){
            if(inAppColosseum==true)
                return;
            onBuyButtonClicked(NULL, 15);
            return;
        }
        if(GameManager::sharedGameManager()->isNodeAtPoint(buyLayer6, location)){
            if(inAppOperaHouse==true)
                return;
            onBuyButtonClicked(NULL, 16);
            return;
        }
        if(GameManager::sharedGameManager()->isNodeAtPoint(buyLayer7, location)){
            if(inAppEasterStone==true)
                return;
            onBuyButtonClicked(NULL, 17);
            return;
        }
    }
    
}



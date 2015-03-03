

#ifndef ITEM_H_
#define ITEM_H_

#include "cocos2d.h"
#include <string>
#define PTM_RATIO 32.0

using namespace cocos2d;
using namespace std;
class Item: public CCSprite {
public:
    Item();
    virtual ~Item();
    CCRect rect();
    void frameAddOne();
    int getFrameLasted();
    string getFunction();
    CCSprite* itemSprite;
    
    static int randomValueBetween(int low, int high);
protected:
    int frameLasted;
    string function;
//    CC_SYNTHESIZE(CCSprite*, itemSprite,itemSprite);
};

static void changeLableSizeAndPos(CCSprite* stageSpr,CCLabelTTF *stageLbl,CCSprite*scoreSpr,CCLabelTTF *scoreLbl,CCSprite*coinSpr,CCLabelTTF *coinLabel,CCSprite*ballTopSpr,CCLabelTTF *globalPlayerLifeCountLabel,int deviceResolution){
    
    CCLabelTTF *localstageLbl=stageLbl;
    CCSprite* localscoreSpr=scoreSpr;
    CCLabelTTF *localscoreLbl=scoreLbl;
    CCSprite*localcoinSpr=coinSpr;
    CCLabelTTF *localcoinLabel= coinLabel;
    CCLabelTTF *localglobalPlayerLifeCountLabel= globalPlayerLifeCountLabel;
    

    float localscoreSprPosX = scoreSpr->getPositionX();
    float localcoinSprPosX =  localcoinSpr->getPositionX();
    float localscoreLblPosX =  localscoreLbl->getPositionX();
     float localscoreLblPosY=  localscoreLbl->getPositionY();
    float localcoinLabelPosX = localcoinLabel->getPositionX();
    float localstageLblPosX = localstageLbl->getPositionX();
    float localcoinLabelPosY = coinLabel->getPositionY();
    float localglobalPlayerLifeCountLabelPosX = localglobalPlayerLifeCountLabel->getPositionX();
    localglobalPlayerLifeCountLabel->setPositionX(localglobalPlayerLifeCountLabelPosX+2);\
    //levels Label
    localstageLbl->setPositionX(localstageLblPosX+14);
    //Score Spr
    localcoinSpr->setPositionX(localcoinSprPosX-5);
    localcoinLabel->setPositionY(localcoinLabelPosY-5);
     localcoinLabel->setPositionX(localcoinLabelPosX-5);
    localscoreSpr->setPositionX(localscoreSprPosX+13);
    localscoreLbl->setPositionX(localscoreLblPosX+15);
    CCLOG("deviceResolution %d",deviceResolution);
    switch (deviceResolution)
    {
        case 1:
//            if(brickBreakTotalPoint>=1000){
//                localscoreLbl->setPositionX(localscoreLblPosX+15);
//            }
//            else if(brickBreakTotalPoint>=10000){
//                localscoreLbl->setPositionX(localscoreLblPosX+15);
//            }
//            else if(brickBreakTotalPoint>=100000){
//                localscoreLbl->setPositionX(localscoreLblPosX+15);
//            }
//            else if(brickBreakTotalPoint>100){
//                localscoreLbl->setPositionX(localscoreLblPosX+15);
//            }
//            
//            if(coinTotalCount>=1000){
//                localcoinSpr->setPositionX(localcoinSprPosX-5);
//                localcoinLabel->setPositionX(localcoinLabelPosX-5);
//            }
//            else if(coinTotalCount>=10000){
//                localcoinSpr->setPositionX(localcoinSprPosX-5);
//                localcoinLabel->setPositionX(localcoinLabelPosX-5);
//            }
//           
//            else{
//                localcoinSpr->setPositionX(localcoinSprPosX-5);
//                localcoinLabel->setPositionX(localcoinLabelPosX-5);
//            }

            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136){
                localcoinLabel->setFontSize(30);
                localscoreLbl->setFontSize(30);
                localglobalPlayerLifeCountLabel->setFontSize(30);
                localstageLbl->setFontSize(30);
                localscoreLbl->setPositionY(localscoreLblPosY-5);
                
//                if(brickBreakTotalPoint>=1000){
//                    localscoreLbl->setPositionX(localscoreLblPosX+65);
//                }
//                else if(brickBreakTotalPoint>=100){
//                    localscoreLbl->setPositionX(localscoreLblPosX+55);
//                }
//                else if(brickBreakTotalPoint>=10000){
//                    localscoreLbl->setPositionX(localscoreLblPosX+85);
//                }
//                else if(brickBreakTotalPoint>=100000){
//                    localscoreLbl->setPositionX(localscoreLblPosX+100);
//                }
//                else{
//                    localscoreLbl->setPositionX(localscoreLblPosX+45);
//                }
//                if(coinTotalCount>=1000){
//                    localcoinSpr->setPositionX(localcoinSprPosX-55);
//                    localcoinLabel->setPositionX(localcoinLabelPosX-35);
//                }
//                else if(coinTotalCount>=10000){
//                    localcoinSpr->setPositionX(localcoinSprPosX-85);
//                    localcoinLabel->setPositionX(localcoinLabelPosX-55);
//                }
//                else{
//                    localcoinSpr->setPositionX(localcoinSprPosX-45);
//                    localcoinLabel->setPositionX(localcoinLabelPosX-30);
//                }
            }
            else{
                localscoreLbl->setPositionY(localscoreLblPosY-5);
                localcoinLabel->setFontSize(30);
                localscoreLbl->setFontSize(30);
                localglobalPlayerLifeCountLabel->setFontSize(30);
                localstageLbl->setFontSize(30);
                
//                if(brickBreakTotalPoint>=1000){
//                    localscoreLbl->setPositionX(localscoreLblPosX+65);
//                }
//                else if(brickBreakTotalPoint>=10000){
//                    localscoreLbl->setPositionX(localscoreLblPosX+85);
//                }
//                else if(brickBreakTotalPoint>=100){
//                    localscoreLbl->setPositionX(localscoreLblPosX+55);
//                }
//                else if(brickBreakTotalPoint>=100000){
//                    localscoreLbl->setPositionX(localscoreLblPosX+100);
//                }
//                else{
//                    localscoreLbl->setPositionX(localscoreLblPosX+45);
//                }
                
//                if(coinTotalCount>=1000){
//                    localcoinSpr->setPositionX(localcoinSprPosX-80);
//                    localcoinLabel->setPositionX(localcoinLabelPosX-55);
//                }
//                else if(coinTotalCount>=10000){
//                    localcoinSpr->setPositionX(localcoinSprPosX-85);
//                    localcoinLabel->setPositionX(localcoinLabelPosX-70);
//                }
//                else{
//                    localcoinSpr->setPositionX(localcoinSprPosX-60);
//                    localcoinLabel->setPositionX(localcoinLabelPosX-50);
//                }
            }
        }
            break;
        case 3:
            localscoreLbl->setPositionY(localscoreLblPosY-5);
            localcoinLabel->setFontSize(30);
            localscoreLbl->setFontSize(30);
            localglobalPlayerLifeCountLabel->setFontSize(30);
            localstageLbl->setFontSize(30);
            
//            if(brickBreakTotalPoint>=1000){
//                localscoreLbl->setPositionX(localscoreLblPosX+55);
//            }
//            else if(brickBreakTotalPoint>=10000){
//                localscoreLbl->setPositionX(localscoreLblPosX+75);
//            }
//            else if(brickBreakTotalPoint>=100000){
//                localscoreLbl->setPositionX(localscoreLblPosX+95);
//            }
//            else{
//                localscoreLbl->setPositionX(localscoreLblPosX+45);
//            }
//            if(coinTotalCount>=1000){
//                localcoinSpr->setPositionX(localcoinSprPosX-70);
//                localcoinLabel->setPositionX(localcoinLabelPosX-55);
//            }
//            else if(coinTotalCount>=10000){
//                localcoinSpr->setPositionX(localcoinSprPosX-85);
//                localcoinLabel->setPositionX(localcoinLabelPosX-70);
//            }
//            else{
//                localcoinSpr->setPositionX(localcoinSprPosX-55);
//                localcoinLabel->setPositionX(localcoinLabelPosX-45);
//            }
            break;
        case 4:
            localscoreLbl->setPositionY(localscoreLblPosY-5);
            localcoinLabel->setFontSize(30);
            localscoreLbl->setFontSize(30);
            localglobalPlayerLifeCountLabel->setFontSize(30);
            localstageLbl->setFontSize(30);
            
//            if(brickBreakTotalPoint>=1000){
//                localscoreLbl->setPositionX(localscoreLblPosX+55);
//            }
//            else if(brickBreakTotalPoint>=10000)
//            {
//                localscoreLbl->setPositionX(localscoreLblPosX+75);
//            }
//            else if(brickBreakTotalPoint>=100000){
//                localscoreLbl->setPositionX(localscoreLblPosX+100);
//            }
//            else if(brickBreakTotalPoint>=100){
//                localscoreLbl->setPositionX(localscoreLblPosX+55);
//            }
//            else{
//                localscoreLbl->setPositionX(localscoreLblPosX+45);
//            }
            
//            if(coinTotalCount>=1000){
//                localcoinSpr->setPositionX(localcoinSprPosX-70);
//                localcoinLabel->setPositionX(localcoinLabelPosX-55);
//            }
//            else if(coinTotalCount>=10000){
//                localcoinSpr->setPositionX(localcoinSprPosX-85);
//                localcoinLabel->setPositionX(localcoinLabelPosX-70);
//            }
//            else{
//                localcoinSpr->setPositionX(localcoinSprPosX-55);
//                localcoinLabel->setPositionX(localcoinLabelPosX-45);
//            }

            break;
        case 5:
            localscoreLbl->setPositionY(localscoreLblPosY-5);
            localcoinLabel->setFontSize(30);
            localscoreLbl->setFontSize(30);
            localglobalPlayerLifeCountLabel->setFontSize(30);
            localstageLbl->setFontSize(30);
//            if(brickBreakTotalPoint>=1000){
//                localscoreLbl->setPositionX(localscoreLblPosX+65);
//            }
//            else if(brickBreakTotalPoint>=10000)
//            {
//                localscoreLbl->setPositionX(localscoreLblPosX+75);
//            }
//            else if(brickBreakTotalPoint>=100000){
//                localscoreLbl->setPositionX(localscoreLblPosX+90);
//            }
//            else if(brickBreakTotalPoint>=100){
//                localscoreLbl->setPositionX(localscoreLblPosX+55);
//            }
//            else{
//                
//                localscoreLbl->setPositionX(localscoreLblPosX+45);
//            }
//            if(coinTotalCount>=1000)
//            {
//                localcoinSpr->setPositionX(localcoinSprPosX-70);
//                localcoinLabel->setPositionX(localcoinLabelPosX-55);
//            }
//            else if(coinTotalCount>=10000)
//            {
//                localcoinSpr->setPositionX(localcoinSprPosX-85);
//                localcoinLabel->setPositionX(localcoinLabelPosX-70);
//            }
//            else{
//                localcoinSpr->setPositionX(localcoinSprPosX-55);
//                localcoinLabel->setPositionX(localcoinLabelPosX-45);
//            }

            break;
        case 6:
//            if(brickBreakTotalPoint>=1000){
//                localscoreLbl->setPositionX(localscoreLblPosX+65);
//            }
//            else if(brickBreakTotalPoint>=10000){
//                localscoreLbl->setPositionX(localscoreLblPosX+85);
//            }
//            else if(brickBreakTotalPoint>=100000){
//                localscoreLbl->setPositionX(localscoreLblPosX+105);
//            }
//            else if(brickBreakTotalPoint>=100){
//                localscoreLbl->setPositionX(localscoreLblPosX+55);
//            }
//            else{
//                
//                localscoreLbl->setPositionX(localscoreLblPosX+45);
//            }
            
//            if(coinTotalCount>=1000){
//                localcoinSpr->setPositionX(localcoinSprPosX-70);
//                localcoinLabel->setPositionX(localcoinLabelPosX-55);
//            }
//            else if(coinTotalCount>=10000){
//                localcoinSpr->setPositionX(localcoinSprPosX-85);
//                localcoinLabel->setPositionX(localcoinLabelPosX-70);
//            }
//            else{
//                localcoinSpr->setPositionX(localcoinSprPosX-55);
//                localcoinLabel->setPositionX(localcoinLabelPosX-45);
//            }
            break;
            
        default:
            break;
    }
}

#endif /* ITEM_H_ */

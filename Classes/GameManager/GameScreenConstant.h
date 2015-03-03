
#ifndef BreakingBricks_GameScreenConstant_h
#define BreakingBricks_GameScreenConstant_h

static bool backGroundSetting(int currentLevel,CCSprite *mainBG,CCSprite *referenceBG,CCLayerColor *shapeBackLyr,int deviceResolution)
{
    CCSprite *localMainBg=(CCSprite *)mainBG;
    if(deviceResolution==5)
        localMainBg->setScaleY(1.6);
    bool isblackBgPresent;
    int playedLevel=currentLevel;
    
    if(playedLevel>0 && playedLevel<9){
        isblackBgPresent=false;
        localMainBg->setDisplayFrame(CCSpriteFrame::create("bg_1.png",localMainBg->getTextureRect()));
    }
    if(playedLevel>8 && playedLevel<17){
        isblackBgPresent=true;
        shapeBackLyr->setColor(ccc3(8, 8, 8));
        localMainBg->setDisplayFrame(CCSpriteFrame::create("bg_2.png",localMainBg->getTextureRect()));
    }
    if(playedLevel>16 && playedLevel<25){
        isblackBgPresent=true;
        localMainBg->setDisplayFrame(CCSpriteFrame::create("bg_4.png",localMainBg->getTextureRect()));
    }
    if(playedLevel>24 && playedLevel<33){
        isblackBgPresent=true;
        localMainBg->setDisplayFrame(CCSpriteFrame::create("bg_3.png",localMainBg->getTextureRect()));
    }
    if(playedLevel>32 && playedLevel<41){
        isblackBgPresent=false;
        localMainBg->setDisplayFrame(CCSpriteFrame::create("bg_5.png",localMainBg->getTextureRect()));
        shapeBackLyr->setColor(ccc3(239,239,239));
    }
    if(playedLevel>40 && playedLevel<49){
        isblackBgPresent=true;
        localMainBg->setDisplayFrame(CCSpriteFrame::create("bg_3.png",localMainBg->getTextureRect()));
    }
    if(playedLevel>48 && playedLevel<57){
        isblackBgPresent=false;
        localMainBg->setDisplayFrame(CCSpriteFrame::create("bg_7.png",localMainBg->getTextureRect()));
    }
    if((playedLevel>8 && playedLevel<17) ||(playedLevel>32 && playedLevel<41) ){
    }
    else{
        shapeBackLyr->setVisible(false);
    }
    return isblackBgPresent;
}

static CCSprite *shapeBackColorAndVisiblity(int currentLevel,CCSize winSize,CCSprite *localshapeSpr,int deviceResolution)
{
    int playedLevel=currentLevel;
    CCSize windowSize = winSize;
    CCSprite *shapeSpr =  localshapeSpr;
    switch (deviceResolution)
    {
        case 1:
            shapeSpr->setPosition(ccp(shapeSprPosX[playedLevel], shapeSprPosY[playedLevel]));
            break;
        case 2:
            if (CCDirector::sharedDirector()->getWinSize().height==1136){
                shapeSpr->setPosition(ccp(((shapeSprPosX[playedLevel]/1.8))-110, (shapeSprPosY[playedLevel])/1.8));
            }
            else{
                shapeSpr->setPosition(ccp(((shapeSprPosX[playedLevel]/2)), (shapeSprPosY[playedLevel]/2)));
                
            }
            break;
        case 3:
            shapeSpr->setPosition(ccp(((shapeSprPosX[playedLevel]/2))-80, (shapeSprPosY[playedLevel]/2)-50));
            
            break;
        case 4:
            shapeSpr->setPosition(ccp(((shapeSprPosX[playedLevel]/2.54))-60, (shapeSprPosY[playedLevel]/2.54)-33));
            break;
        case 5:
            shapeSpr->setPosition(ccp(shapeSprPosX[playedLevel]/2, (shapeSprPosY[playedLevel]/2)+250));
            break;
        case 6:
            shapeSpr->setPosition(ccp((shapeSprPosX[playedLevel]*1.082)-200, (shapeSprPosY[playedLevel]*1.082)-40));
        default:
            break;
    }
    
    if(!(playedLevel==9 || playedLevel==10 || playedLevel==11 || playedLevel==12 || playedLevel==13 || playedLevel==14 || playedLevel==15 ||playedLevel==16 || playedLevel==33 || playedLevel==34 || playedLevel==35 || playedLevel==36 || playedLevel==37|| playedLevel==38 || playedLevel==39|| playedLevel==40))
        shapeSpr->setVisible(false);
    else
        shapeSpr->setVisible(true);
    if(playedLevel>8 && playedLevel<17){
        shapeSpr->setColor(ccc3(8, 8, 8));
    }
    if(playedLevel>32 && playedLevel<41){
        shapeSpr->setColor(ccc3(239,239,239));
    }
    return shapeSpr;
}

#endif

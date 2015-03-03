
#ifndef BreakingBricks_BrickPosSetting_h
#define BreakingBricks_BrickPosSetting_h

static CCSprite *brickPositionOnTheScreenDisplay(int localLevel,TargetPlatform device,CCSize windowSize,CCSprite *brickSpr,int index,int deviceResolution)
{
    switch (localLevel) {
        case 1:
            
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level1BrickXPos[index-11], level1BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level1BrickXPos[index-11]/1.8))-110, (level1BrickYPos[index-11]/1.8)));
                }
                else
                {
                    brickSpr->setPosition(ccp(level1BrickXPos[index-11]/2, level1BrickYPos[index-11]/2));
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level1BrickXPos[index-11]/2))-80, (level1BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level1BrickXPos[index-11]/2.54))-60, (level1BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level1BrickXPos[index-11]/2, (level1BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                
                brickSpr->setPosition(ccp((level1BrickXPos[index-11]*1.082)-200, (level1BrickYPos[index-11]*1.082)-40));
                break;
                
            default:
                break;
        }
            break;
            
            
        case 2:
            
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level2BrickXPos[index-11], level2BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level2BrickXPos[index-11]/1.8))-110, (level2BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level2BrickXPos[index-11]/2, level2BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level2BrickXPos[index-11]/2))-80, (level2BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level2BrickXPos[index-11]/2.54))-60, (level2BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level2BrickXPos[index-11]/2, (level2BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level2BrickXPos[index-11]*1.082)-200, (level2BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
        case 3:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level3BrickXPos[index-11], level3BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level3BrickXPos[index-11]/1.8))-110, (level3BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level3BrickXPos[index-11]/2, level3BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level3BrickXPos[index-11]/2))-80, (level3BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level3BrickXPos[index-11]/2.54))-60, (level3BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level3BrickXPos[index-11]/2, (level3BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level3BrickXPos[index-11]*1.082)-200, (level3BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
        case 4:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level4BrickXPos[index-11], level4BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level4BrickXPos[index-11]/1.8))-110, (level4BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level4BrickXPos[index-11]/2, level4BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level4BrickXPos[index-11]/2))-80, (level4BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level4BrickXPos[index-11]/2.54))-60, (level4BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level4BrickXPos[index-11]/2, (level4BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level4BrickXPos[index-11]*1.082)-200, (level4BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 5:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level5BrickXPos[index-11], level5BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level5BrickXPos[index-11]/1.8))-110, (level5BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level5BrickXPos[index-11]/2, level5BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level5BrickXPos[index-11]/2))-80, (level5BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level5BrickXPos[index-11]/2.54))-60, (level5BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level5BrickXPos[index-11]/2, (level5BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level5BrickXPos[index-11]*1.082)-200, (level5BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
        case 6:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level6BrickXPos[index-11], level6BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level6BrickXPos[index-11]/1.8))-110, (level6BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level6BrickXPos[index-11]/2, level6BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level6BrickXPos[index-11]/2))-80, (level6BrickYPos[index-11]/2)-50));
                break;
            case 4:
                brickSpr->setPosition(ccp(((level6BrickXPos[index-11]/2.54))-60, (level6BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level6BrickXPos[index-11]/2, (level6BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level6BrickXPos[index-11]*1.082)-200, (level6BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
        case 7:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level7BrickXPos[index-11], level7BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level7BrickXPos[index-11]/1.8))-110, (level7BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level7BrickXPos[index-11]/2, level7BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level7BrickXPos[index-11]/2))-80, (level7BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level7BrickXPos[index-11]/2.54))-60, (level7BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level7BrickXPos[index-11]/2, (level7BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level7BrickXPos[index-11]*1.082)-200, (level7BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
        case 8:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level8BrickXPos[index-11], level8BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level8BrickXPos[index-11]/1.8))-110, (level8BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level8BrickXPos[index-11]/2, level8BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level8BrickXPos[index-11]/2))-80, (level8BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level8BrickXPos[index-11]/2.54))-60, (level8BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level8BrickXPos[index-11]/2, (level8BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level8BrickXPos[index-11]*1.082)-200, (level8BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 9:
            
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level9BrickXPos[index-11], level9BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level9BrickXPos[index-11]/1.8))-110, (level9BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level9BrickXPos[index-11]/2, level9BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level9BrickXPos[index-11]/2))-80, (level9BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level9BrickXPos[index-11]/2.54))-60, (level9BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level9BrickXPos[index-11]/2, (level9BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level9BrickXPos[index-11]*1.082)-200, (level9BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
        case 10:
            
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level10BrickXPos[index-11], level10BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level10BrickXPos[index-11]/1.8))-110, (level10BrickYPos[index-11]/1.8)));
                }
                else
                {
                    brickSpr->setPosition(ccp(level10BrickXPos[index-11]/2, level10BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level10BrickXPos[index-11]/2))-80, (level10BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level10BrickXPos[index-11]/2.54))-60, (level10BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level10BrickXPos[index-11]/2, (level10BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level10BrickXPos[index-11]*1.082)-200, (level10BrickYPos[index-11]*1.082)-40));
                break;
                
            default:
                break;
        }
            break;
            
        case 11:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level11BrickXPos[index-11], level11BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level11BrickXPos[index-11]/1.8))-110, (level11BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level11BrickXPos[index-11]/2, level11BrickYPos[index-11]/2));
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level11BrickXPos[index-11]/2))-80, (level11BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level11BrickXPos[index-11]/2.54))-60, (level11BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level11BrickXPos[index-11]/2, (level11BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level11BrickXPos[index-11]*1.082)-200, (level11BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
        case 12:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level12BrickXPos[index-11], level12BrickYPos[index-11]));
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level12BrickXPos[index-11]/1.8))-110, (level12BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level12BrickXPos[index-11]/2, level12BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level12BrickXPos[index-11]/2))-80, (level12BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level12BrickXPos[index-11]/2.54))-60, (level12BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level12BrickXPos[index-11]/2, (level12BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level12BrickXPos[index-11]*1.082)-200, (level12BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
        case 13:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level13BrickXPos[index-11], level13BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level13BrickXPos[index-11]/1.8))-110, (level13BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level13BrickXPos[index-11]/2, level13BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level13BrickXPos[index-11]/2))-80, (level13BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level13BrickXPos[index-11]/2.54))-60, (level13BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level13BrickXPos[index-11]/2, (level13BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level13BrickXPos[index-11]*1.082)-200, (level13BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 14:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level14BrickXPos[index-11], level14BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level14BrickXPos[index-11]/1.8))-110, (level14BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level14BrickXPos[index-11]/2, level14BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level14BrickXPos[index-11]/2))-80, (level14BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level14BrickXPos[index-11]/2.54))-60, (level14BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level14BrickXPos[index-11]/2, (level14BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level14BrickXPos[index-11]*1.082)-200, (level14BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 15:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level15BrickXPos[index-11], level15BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level15BrickXPos[index-11]/1.8))-110, (level15BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level15BrickXPos[index-11]/2, level15BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level15BrickXPos[index-11]/2))-80, (level15BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level15BrickXPos[index-11]/2.54))-60, (level15BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level15BrickXPos[index-11]/2, (level15BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level15BrickXPos[index-11]*1.082)-200, (level15BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
        case 16:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level16BrickXPos[index-11], level16BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136){
                    brickSpr->setPosition(ccp(((level16BrickXPos[index-11]/1.8))-110, (level16BrickYPos[index-11]/1.8)));
                }
                else
                {
                    brickSpr->setPosition(ccp(level16BrickXPos[index-11]/2, level16BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level16BrickXPos[index-11]/2))-80, (level16BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level16BrickXPos[index-11]/2.54))-60, (level16BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level16BrickXPos[index-11]/2, (level16BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level16BrickXPos[index-11]*1.082)-200, (level16BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 17:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level17BrickXPos[index-11], level17BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level17BrickXPos[index-11]/1.8))-110, (level17BrickYPos[index-11]/1.8)));
                }
                else
                {
                    brickSpr->setPosition(ccp(level17BrickXPos[index-11]/2, level17BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level17BrickXPos[index-11]/2))-80, (level17BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level17BrickXPos[index-11]/2.54))-60, (level17BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level17BrickXPos[index-11]/2, (level17BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level17BrickXPos[index-11]*1.082)-200, (level17BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 18:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level18BrickXPos[index-11], level18BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level18BrickXPos[index-11]/1.8))-110, (level18BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level18BrickXPos[index-11]/2, level18BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level18BrickXPos[index-11]/2))-80, (level18BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level18BrickXPos[index-11]/2.54))-60, (level18BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level18BrickXPos[index-11]/2, (level18BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level18BrickXPos[index-11]*1.082)-200, (level18BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
        case 19:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level19BrickXPos[index-11], level19BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level19BrickXPos[index-11]/1.8))-110, (level19BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level19BrickXPos[index-11]/2, level19BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level19BrickXPos[index-11]/2))-80, (level19BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level19BrickXPos[index-11]/2.54))-60, (level19BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level19BrickXPos[index-11]/2, (level19BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level19BrickXPos[index-11]*1.082)-200, (level19BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 20:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level20BrickXPos[index-11], level20BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level20BrickXPos[index-11]/1.8))-110, (level20BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level20BrickXPos[index-11]/2, level20BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level20BrickXPos[index-11]/2))-80, (level20BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level20BrickXPos[index-11]/2.54))-60, (level20BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level20BrickXPos[index-11]/2, (level20BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level20BrickXPos[index-11]*1.082)-200, (level20BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 21:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level21BrickXPos[index-11], level21BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level21BrickXPos[index-11]/1.8))-110, (level21BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level21BrickXPos[index-11]/2, level21BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level21BrickXPos[index-11]/2))-80, (level21BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level21BrickXPos[index-11]/2.54))-60,(level21BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level21BrickXPos[index-11]/2, (level21BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level21BrickXPos[index-11]*1.082)-200, (level21BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 22:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level22BrickXPos[index-11], level22BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level22BrickXPos[index-11]/1.8))-110, (level22BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level22BrickXPos[index-11]/2, level22BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level22BrickXPos[index-11]/2))-80, (level22BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level22BrickXPos[index-11]/2.54))-60, (level22BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level22BrickXPos[index-11]/2, (level22BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level22BrickXPos[index-11]*1.082)-200, (level22BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 23:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level23BrickXPos[index-11], level23BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level23BrickXPos[index-11]/1.8))-110, (level23BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level23BrickXPos[index-11]/2, level23BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level23BrickXPos[index-11]/2))-80, (level23BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level23BrickXPos[index-11]/2.54))-60, (level23BrickYPos[index-11]/2.54)-33));
                break;
            case 5:
                brickSpr->setPosition(ccp(level23BrickXPos[index-11]/2, (level23BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level23BrickXPos[index-11]*1.082)-200, (level23BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
        case 24:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level24BrickXPos[index-11], level24BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level24BrickXPos[index-11]/1.8))-110, (level24BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level24BrickXPos[index-11]/2, level24BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level24BrickXPos[index-11]/2))-80, (level24BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level24BrickXPos[index-11]/2.54))-60, (level24BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level24BrickXPos[index-11]/2, (level24BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level24BrickXPos[index-11]*1.082)-200, (level24BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
            
        case 25:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level25BrickXPos[index-11], level25BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level25BrickXPos[index-11]/1.8))-110, (level25BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level25BrickXPos[index-11]/2, level25BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level25BrickXPos[index-11]/2))-80, (level25BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level25BrickXPos[index-11]/2.54))-60, (level25BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level25BrickXPos[index-11]/2, (level25BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level25BrickXPos[index-11]*1.082)-200, (level25BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 26:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level26BrickXPos[index-11], level26BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level26BrickXPos[index-11]/1.8))-110, (level26BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level26BrickXPos[index-11]/2, level26BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level26BrickXPos[index-11]/2))-80, (level26BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level26BrickXPos[index-11]/2.54))-60, (level26BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level26BrickXPos[index-11]/2, (level26BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level26BrickXPos[index-11]*1.082)-200, (level26BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 27:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level27BrickXPos[index-11], level27BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level27BrickXPos[index-11]/1.8))-110, (level27BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level27BrickXPos[index-11]/2, level27BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level27BrickXPos[index-11]/2))-80, (level27BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level27BrickXPos[index-11]/2.54))-60, (level27BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level27BrickXPos[index-11]/2, (level27BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level27BrickXPos[index-11]*1.082)-200, (level27BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 28:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level28BrickXPos[index-11], level28BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level28BrickXPos[index-11]/1.8))-110, (level28BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level28BrickXPos[index-11]/2, level28BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level28BrickXPos[index-11]/2))-80, (level28BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level28BrickXPos[index-11]/2.54))-60, (level28BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level28BrickXPos[index-11]/2, (level28BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level28BrickXPos[index-11]*1.082)-200, (level28BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 29:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level29BrickXPos[index-11], level29BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level29BrickXPos[index-11]/1.8))-110, (level29BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level29BrickXPos[index-11]/2, level29BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level29BrickXPos[index-11]/2))-80, (level29BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level29BrickXPos[index-11]/2.54))-60, (level29BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level29BrickXPos[index-11]/2, (level29BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level29BrickXPos[index-11]*1.082)-200, (level29BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 30:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level30BrickXPos[index-11], level30BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level30BrickXPos[index-11]/1.8))-110, (level30BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level30BrickXPos[index-11]/2, level30BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level30BrickXPos[index-11]/2))-80, (level30BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level30BrickXPos[index-11]/2.54))-60, (level30BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level30BrickXPos[index-11]/2, (level30BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level30BrickXPos[index-11]*1.082)-200, (level30BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 31:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level31BrickXPos[index-11], level31BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level31BrickXPos[index-11]/1.8))-110, (level31BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level31BrickXPos[index-11]/2, level31BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level31BrickXPos[index-11]/2))-80, (level31BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level31BrickXPos[index-11]/2.54))-60, (level31BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level31BrickXPos[index-11]/2, (level31BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level31BrickXPos[index-11]*1.082)-200, (level31BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
        case 32:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level32BrickXPos[index-11], level32BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level32BrickXPos[index-11]/1.8))-110, (level32BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level32BrickXPos[index-11]/2, level32BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level32BrickXPos[index-11]/2))-80, (level32BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level32BrickXPos[index-11]/2.54))-60, (level32BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level32BrickXPos[index-11]/2, (level32BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level32BrickXPos[index-11]*1.082)-200, (level32BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
            
            
        case 33:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level33BrickXPos[index-11], level33BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level33BrickXPos[index-11]/1.8))-110, (level33BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level33BrickXPos[index-11]/2, level33BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level33BrickXPos[index-11]/2))-80, (level33BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level33BrickXPos[index-11]/2.54))-60, (level33BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level33BrickXPos[index-11]/2, (level33BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level33BrickXPos[index-11]*1.082)-200, (level33BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 34:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level34BrickXPos[index-11], level34BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level34BrickXPos[index-11]/1.8))-110, (level34BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level34BrickXPos[index-11]/2, level34BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level34BrickXPos[index-11]/2))-80, (level34BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level34BrickXPos[index-11]/2.54))-60, (level34BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level34BrickXPos[index-11]/2, (level34BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level34BrickXPos[index-11]*1.082)-200, (level34BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 35:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level35BrickXPos[index-11], level35BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level35BrickXPos[index-11]/1.8))-110, (level35BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level35BrickXPos[index-11]/2, level35BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level35BrickXPos[index-11]/2))-80, (level35BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level35BrickXPos[index-11]/2.54))-60, (level35BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level35BrickXPos[index-11]/2, (level35BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level35BrickXPos[index-11]*1.082)-200, (level35BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 36:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level36BrickXPos[index-11], level36BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level36BrickXPos[index-11]/1.8))-110, (level36BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level36BrickXPos[index-11]/2, level36BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level36BrickXPos[index-11]/2))-80, (level36BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level36BrickXPos[index-11]/2.54))-60, (level36BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level36BrickXPos[index-11]/2, (level36BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level36BrickXPos[index-11]*1.082)-200, (level36BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 37:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level37BrickXPos[index-11], level37BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level37BrickXPos[index-11]/1.8))-110, (level37BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level37BrickXPos[index-11]/2, level37BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level37BrickXPos[index-11]/2))-80, (level37BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level37BrickXPos[index-11]/2.54))-60, (level37BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level37BrickXPos[index-11]/2, (level37BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level37BrickXPos[index-11]*1.082)-200, (level37BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 38:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level38BrickXPos[index-11], level38BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level38BrickXPos[index-11]/1.8))-110, (level38BrickYPos[index-11]/1.8)));
                }
                else
                {
                    brickSpr->setPosition(ccp(level38BrickXPos[index-11]/2, level38BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level38BrickXPos[index-11]/2))-80, (level38BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level38BrickXPos[index-11]/2.54))-60, (level38BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level38BrickXPos[index-11]/2, (level38BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level38BrickXPos[index-11]*1.082)-200, (level38BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 39:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level39BrickXPos[index-11], level39BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level39BrickXPos[index-11]/1.8))-110, (level39BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level39BrickXPos[index-11]/2, level39BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level39BrickXPos[index-11]/2))-80, (level39BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level39BrickXPos[index-11]/2.54))-60, (level39BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level39BrickXPos[index-11]/2, (level39BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level39BrickXPos[index-11]*1.082)-200, (level39BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
        case 40:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level40BrickXPos[index-11], level40BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level40BrickXPos[index-11]/1.8))-110, (level40BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level40BrickXPos[index-11]/2, level40BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level40BrickXPos[index-11]/2))-80, (level40BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level40BrickXPos[index-11]/2.54))-60, (level40BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level40BrickXPos[index-11]/2, (level40BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level40BrickXPos[index-11]*1.082)-200, (level40BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 41:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level41BrickXPos[index-11], level41BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level41BrickXPos[index-11]/1.8))-110, (level41BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level41BrickXPos[index-11]/2, level41BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level41BrickXPos[index-11]/2))-80, (level41BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level41BrickXPos[index-11]/2.54))-60, (level41BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level41BrickXPos[index-11]/2, (level41BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level41BrickXPos[index-11]*1.082)-200, (level41BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 42:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level42BrickXPos[index-11], level42BrickYPos[index-11]));
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level42BrickXPos[index-11]/1.8))-110, (level42BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level42BrickXPos[index-11]/2, level42BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level42BrickXPos[index-11]/2))-80, (level42BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level42BrickXPos[index-11]/2.54))-60, (level42BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level42BrickXPos[index-11]/2, (level42BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level42BrickXPos[index-11]*1.082)-200, (level42BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 43:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level43BrickXPos[index-11], level43BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level43BrickXPos[index-11]/1.8))-110, (level43BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level43BrickXPos[index-11]/2, level43BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level43BrickXPos[index-11]/2))-80, (level43BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level43BrickXPos[index-11]/2.54))-60, (level43BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level43BrickXPos[index-11]/2, (level43BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level43BrickXPos[index-11]*1.082)-200, (level43BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 44:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level44BrickXPos[index-11], level44BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level44BrickXPos[index-11]/1.8))-110, (level44BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level44BrickXPos[index-11]/2, level44BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level44BrickXPos[index-11]/2))-80, (level44BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level44BrickXPos[index-11]/2.54))-60, (level44BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level44BrickXPos[index-11]/2, (level44BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level44BrickXPos[index-11]*1.082)-200, (level44BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 45:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level45BrickXPos[index-11], level45BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level45BrickXPos[index-11]/1.8))-110, (level45BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level45BrickXPos[index-11]/2, level45BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level45BrickXPos[index-11]/2))-80, (level45BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level45BrickXPos[index-11]/2.54))-60, (level45BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level45BrickXPos[index-11]/2, (level45BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level45BrickXPos[index-11]*1.082)-200, (level45BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 46:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level46BrickXPos[index-11], level46BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level46BrickXPos[index-11]/1.8))-110, (level46BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level46BrickXPos[index-11]/2, level46BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level46BrickXPos[index-11]/2))-80, (level46BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level46BrickXPos[index-11]/2.54))-60, (level46BrickYPos[index-11]/2.54)-33));
                break;
            case 5:
                brickSpr->setPosition(ccp(level46BrickXPos[index-11]/2, (level46BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level46BrickXPos[index-11]*1.082)-200, (level46BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
            
        case 47:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level47BrickXPos[index-11], level47BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level47BrickXPos[index-11]/1.8))-110, (level47BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level47BrickXPos[index-11]/2, level47BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level47BrickXPos[index-11]/2))-80, (level47BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level47BrickXPos[index-11]/2.54))-60, (level47BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level47BrickXPos[index-11]/2, (level47BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level47BrickXPos[index-11]*1.082)-200, (level47BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
        case 48:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level48BrickXPos[index-11], level48BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level48BrickXPos[index-11]/1.8))-110, (level48BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level48BrickXPos[index-11]/2, level48BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level48BrickXPos[index-11]/2))-80, (level48BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level48BrickXPos[index-11]/2.54))-60, (level48BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level48BrickXPos[index-11]/2, (level48BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level48BrickXPos[index-11]*1.082)-200, (level48BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 49:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level49BrickXPos[index-11], level49BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level49BrickXPos[index-11]/1.8))-110, (level49BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level49BrickXPos[index-11]/2, level49BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level49BrickXPos[index-11]/2))-80, (level49BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level49BrickXPos[index-11]/2.54))-60, (level49BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level49BrickXPos[index-11]/2, (level49BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level49BrickXPos[index-11]*1.082)-200, (level49BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 50:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level50BrickXPos[index-11], level50BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level50BrickXPos[index-11]/1.8))-110, (level50BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level50BrickXPos[index-11]/2, level50BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level50BrickXPos[index-11]/2))-80, (level50BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level50BrickXPos[index-11]/2.54))-60, (level50BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level50BrickXPos[index-11]/2, (level50BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level50BrickXPos[index-11]*1.082)-200, (level50BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 51:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level51BrickXPos[index-11], level51BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level51BrickXPos[index-11]/1.8))-110, (level51BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level51BrickXPos[index-11]/2, level51BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level51BrickXPos[index-11]/2))-80, (level51BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level51BrickXPos[index-11]/2.54))-60, (level51BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level51BrickXPos[index-11]/2, (level51BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level51BrickXPos[index-11]*1.082)-200, (level51BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 52:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level52BrickXPos[index-11], level52BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level52BrickXPos[index-11]/1.8))-110, (level52BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level52BrickXPos[index-11]/2, level52BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level52BrickXPos[index-11]/2))-80, (level52BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level52BrickXPos[index-11]/2.54))-60, (level52BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level52BrickXPos[index-11]/2, (level52BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level52BrickXPos[index-11]*1.082)-200, (level52BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 53:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level53BrickXPos[index-11], level53BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level53BrickXPos[index-11]/1.8))-110, (level53BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level53BrickXPos[index-11]/2, level53BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level53BrickXPos[index-11]/2))-80, (level53BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level53BrickXPos[index-11]/2.54))-60, (level53BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level53BrickXPos[index-11]/2, (level53BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level53BrickXPos[index-11]*1.082)-200, (level53BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 54:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level54BrickXPos[index-11], level54BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level54BrickXPos[index-11]/1.8))-110, (level54BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level54BrickXPos[index-11]/2, level54BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level54BrickXPos[index-11]/2))-80, (level54BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level54BrickXPos[index-11]/2.54))-60, (level54BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level54BrickXPos[index-11]/2, (level54BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level54BrickXPos[index-11]*1.082)-200, (level54BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 55:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level55BrickXPos[index-11], level55BrickYPos[index-11]));
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level55BrickXPos[index-11]/1.8))-110,( level55BrickYPos[index-11]/1.8)));
                    
                }
                else
                { brickSpr->setPosition(ccp(level55BrickXPos[index-11]/2, level55BrickYPos[index-11]/2));
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level55BrickXPos[index-11]/2))-80, (level55BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level55BrickXPos[index-11]/2.54))-60, (level55BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level55BrickXPos[index-11]/2, (level55BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level55BrickXPos[index-11]*1.082)-200, (level55BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
        case 56:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level56BrickXPos[index-11], level56BrickYPos[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level56BrickXPos[index-11]/1.8))-110, (level56BrickYPos[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level56BrickXPos[index-11]/2, level56BrickYPos[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level56BrickXPos[index-11]/2))-80, (level56BrickYPos[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level56BrickXPos[index-11]/2.54))-60, (level56BrickYPos[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level56BrickXPos[index-11]/2, (level56BrickYPos[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level56BrickXPos[index-11]*1.082)-200, (level56BrickYPos[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        default:
            break;
    }
    
    return brickSpr;
}


static CCSprite *halfBrickPositionOnTheScreenDisplay(int localLevel,TargetPlatform device,CCSize windowSize,CCSprite *brickSpr,int index,int deviceResolution)
{   switch (localLevel) {
    case 1:
        
        switch (deviceResolution)
    {
        case 1:
            brickSpr->setPosition(ccp(level1BrickX500Pos[index-11], level1BrickY500Pos[index-11]));
            
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136)
            {
                brickSpr->setPosition(ccp(((level1BrickX500Pos[index-11]/1.8))-110, (level1BrickY500Pos[index-11]/1.8)));
            }
            else
            {
                brickSpr->setPosition(ccp(level1BrickX500Pos[index-11]/2, level1BrickY500Pos[index-11]/2));
            }
        }
            break;
        case 3:
            brickSpr->setPosition(ccp(((level1BrickX500Pos[index-11]/2))-80, (level1BrickY500Pos[index-11]/2)-50));
            
            break;
        case 4:
            brickSpr->setPosition(ccp(((level1BrickX500Pos[index-11]/2.54))-60, (level1BrickY500Pos[index-11]/2.54)-33));
            
            break;
        case 5:
            brickSpr->setPosition(ccp(level1BrickX500Pos[index-11]/2, (level1BrickY500Pos[index-11]/2)+250));
            
            break;
        case 6:
            
            brickSpr->setPosition(ccp((level1BrickX500Pos[index-11]*1.082)-200, (level1BrickY500Pos[index-11]*1.082)-40));
            
            
            break;
            
        default:
            break;
    }
        break;
        
        
    case 2:
        
        switch (deviceResolution)
    {
        case 1:
            brickSpr->setPosition(ccp(level2BrickX500Pos[index-11], level2BrickY500Pos[index-11]));
            
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136)
            {
                brickSpr->setPosition(ccp(((level2BrickX500Pos[index-11]/1.8))-110, (level2BrickY500Pos[index-11]/1.8)));
                
            }
            else
            {
                brickSpr->setPosition(ccp(level2BrickX500Pos[index-11]/2, level2BrickY500Pos[index-11]/2));
                
            }
        }
            break;
        case 3:
            brickSpr->setPosition(ccp(((level2BrickX500Pos[index-11]/2))-80, (level2BrickY500Pos[index-11]/2)-50));
            
            break;
        case 4:
            brickSpr->setPosition(ccp(((level2BrickX500Pos[index-11]/2.54))-60, (level2BrickY500Pos[index-11]/2.54)-33));
            
            break;
        case 5:
            brickSpr->setPosition(ccp(level2BrickX500Pos[index-11]/2, (level2BrickY500Pos[index-11]/2)+250));
            
            break;
        case 6:
            brickSpr->setPosition(ccp((level2BrickX500Pos[index-11]*1.082)-200, (level2BrickY500Pos[index-11]*1.082)-40));
            
            break;
            
        default:
            break;
    }
        break;
    case 3:
        switch (deviceResolution)
    {
        case 1:
            brickSpr->setPosition(ccp(level3BrickX500Pos[index-11], level3BrickY500Pos[index-11]));
            
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136)
            {
                brickSpr->setPosition(ccp(((level3BrickX500Pos[index-11]/1.8))-110, (level3BrickY500Pos[index-11]/1.8)));
                
            }
            else
            {
                brickSpr->setPosition(ccp(level3BrickX500Pos[index-11]/2, level3BrickY500Pos[index-11]/2));
                
            }
        }
            break;
        case 3:
            brickSpr->setPosition(ccp(((level3BrickX500Pos[index-11]/2))-80, (level3BrickY500Pos[index-11]/2)-50));
            
            break;
        case 4:
            brickSpr->setPosition(ccp(((level3BrickX500Pos[index-11]/2.54))-60, (level3BrickY500Pos[index-11]/2.54)-33));
            
            break;
        case 5:
            brickSpr->setPosition(ccp(level3BrickX500Pos[index-11]/2, (level3BrickY500Pos[index-11]/2)+250));
            
            break;
        case 6:
            brickSpr->setPosition(ccp((level3BrickX500Pos[index-11]*1.082)-200, (level3BrickY500Pos[index-11]*1.082)-40));
            
            break;
            
        default:
            break;
    }
        break;
        
    case 4:
        switch (deviceResolution)
    {
        case 1:
            brickSpr->setPosition(ccp(level4BrickX500Pos[index-11], level4BrickY500Pos[index-11]));
            
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136)
            {
                brickSpr->setPosition(ccp(((level4BrickX500Pos[index-11]/1.8))-110, (level4BrickY500Pos[index-11]/1.8)));
                
            }
            else
            {
                brickSpr->setPosition(ccp(level4BrickX500Pos[index-11]/2, level4BrickY500Pos[index-11]/2));
                
            }
        }
            break;
        case 3:
            brickSpr->setPosition(ccp(((level4BrickX500Pos[index-11]/2))-80, (level4BrickY500Pos[index-11]/2)-50));
            
            break;
        case 4:
            brickSpr->setPosition(ccp(((level4BrickX500Pos[index-11]/2.54))-60, (level4BrickY500Pos[index-11]/2.54)-33));
            
            break;
        case 5:
            brickSpr->setPosition(ccp(level4BrickX500Pos[index-11]/2, (level4BrickY500Pos[index-11]/2)+250));
            
            break;
        case 6:
            brickSpr->setPosition(ccp((level4BrickX500Pos[index-11]*1.082)-200, (level4BrickY500Pos[index-11]*1.082)-40));
            
            break;
            
        default:
            break;
    }
        break;
        
        
    case 5:
        switch (deviceResolution)
    {
        case 1:
            brickSpr->setPosition(ccp(level5BrickX500Pos[index-11], level5BrickY500Pos[index-11]));
            
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136)
            {
                brickSpr->setPosition(ccp(((level5BrickX500Pos[index-11]/1.8))-110, (level5BrickY500Pos[index-11]/1.8)));
                
            }
            else
            {
                brickSpr->setPosition(ccp(level5BrickX500Pos[index-11]/2, level5BrickY500Pos[index-11]/2));
                
            }
        }
            break;
        case 3:
            brickSpr->setPosition(ccp(((level5BrickX500Pos[index-11]/2))-80, (level5BrickY500Pos[index-11]/2)-50));
            
            break;
        case 4:
            brickSpr->setPosition(ccp(((level5BrickX500Pos[index-11]/2.54))-60, (level5BrickY500Pos[index-11]/2.54)-33));
            
            break;
        case 5:
            brickSpr->setPosition(ccp(level5BrickX500Pos[index-11]/2, (level5BrickY500Pos[index-11]/2)+250));
            
            break;
        case 6:
            brickSpr->setPosition(ccp((level5BrickX500Pos[index-11]*1.082)-200, (level5BrickY500Pos[index-11]*1.082)-40));
            
            break;
            
        default:
            break;
    }
        break;
        
    case 6:
        switch (deviceResolution)
    {
        case 1:
            brickSpr->setPosition(ccp(level6BrickX500Pos[index-11], level6BrickY500Pos[index-11]));
            
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136)
            {
                brickSpr->setPosition(ccp(((level6BrickX500Pos[index-11]/1.8))-110, (level6BrickY500Pos[index-11]/1.8)));
                
            }
            else
            {
                brickSpr->setPosition(ccp(level6BrickX500Pos[index-11]/2, level6BrickY500Pos[index-11]/2));
                
            }
        }
            break;
        case 3:
            brickSpr->setPosition(ccp(((level6BrickX500Pos[index-11]/2))-80, (level6BrickY500Pos[index-11]/2)-50));
            break;
        case 4:
            brickSpr->setPosition(ccp(((level6BrickX500Pos[index-11]/2.54))-60, (level6BrickY500Pos[index-11]/2.54)-33));
            
            break;
        case 5:
            brickSpr->setPosition(ccp(level6BrickX500Pos[index-11]/2, (level6BrickY500Pos[index-11]/2)+250));
            
            break;
        case 6:
            brickSpr->setPosition(ccp((level6BrickX500Pos[index-11]*1.082)-200, (level6BrickY500Pos[index-11]*1.082)-40));
            
            break;
            
        default:
            break;
    }
        break;
        
    case 7:
        switch (deviceResolution)
    {
        case 1:
            brickSpr->setPosition(ccp(level7BrickX500Pos[index-11], level7BrickY500Pos[index-11]));
            
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136)
            {
                brickSpr->setPosition(ccp(((level7BrickX500Pos[index-11]/1.8))-110, (level7BrickY500Pos[index-11]/1.8)));
                
            }
            else
            {
                brickSpr->setPosition(ccp(level7BrickX500Pos[index-11]/2, level7BrickY500Pos[index-11]/2));
                
            }
        }
            break;
        case 3:
            brickSpr->setPosition(ccp(((level7BrickX500Pos[index-11]/2))-80, (level7BrickY500Pos[index-11]/2)-50));
            
            break;
        case 4:
            brickSpr->setPosition(ccp(((level7BrickX500Pos[index-11]/2.54))-60, (level7BrickY500Pos[index-11]/2.54)-33));
            
            break;
        case 5:
            brickSpr->setPosition(ccp(level7BrickX500Pos[index-11]/2, (level7BrickY500Pos[index-11]/2)+250));
            
            break;
        case 6:
            brickSpr->setPosition(ccp((level7BrickX500Pos[index-11]*1.082)-200, (level7BrickY500Pos[index-11]*1.082)-40));
            
            break;
            
        default:
            break;
    }
        break;
    case 8:
        switch (deviceResolution)
    {
        case 1:
            brickSpr->setPosition(ccp(level8BrickX500Pos[index-11], level8BrickY500Pos[index-11]));
            
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136)
            {
                brickSpr->setPosition(ccp(((level8BrickX500Pos[index-11]/1.8))-110, (level8BrickY500Pos[index-11]/1.8)));
                
            }
            else
            {
                brickSpr->setPosition(ccp(level8BrickX500Pos[index-11]/2, level8BrickY500Pos[index-11]/2));
                
            }
        }
            break;
        case 3:
            brickSpr->setPosition(ccp(((level8BrickX500Pos[index-11]/2))-80, (level8BrickY500Pos[index-11]/2)-50));
            
            break;
        case 4:
            brickSpr->setPosition(ccp(((level8BrickX500Pos[index-11]/2.54))-60, (level8BrickY500Pos[index-11]/2.54)-33));
            
            break;
        case 5:
            brickSpr->setPosition(ccp(level8BrickX500Pos[index-11]/2, (level8BrickY500Pos[index-11]/2)+250));
            
            break;
        case 6:
            brickSpr->setPosition(ccp((level8BrickX500Pos[index-11]*1.082)-200, (level8BrickY500Pos[index-11]*1.082)-40));
            
            break;
            
        default:
            break;
    }
        break;
        
        
    case 9:
        
        break;
        
    case 10:
        
        break;
        
    case 11:
        
        break;
    case 12:
        break;
        
    case 13:
        break;
        
    case 14:
        break;
        
        
    case 15:
        break;
        
        
    case 17:
        switch (deviceResolution)
    {
        case 1:
            brickSpr->setPosition(ccp(level17BrickX500Pos[index-11], level17BrickY500Pos[index-11]));
            
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136)
            {
                brickSpr->setPosition(ccp(((level17BrickX500Pos[index-11]/1.8))-110, (level17BrickY500Pos[index-11]/1.8)));
            }
            else
            {
                brickSpr->setPosition(ccp(level17BrickX500Pos[index-11]/2, level17BrickY500Pos[index-11]/2));
                
            }
        }
            break;
        case 3:
            brickSpr->setPosition(ccp(((level17BrickX500Pos[index-11]/2))-80, (level17BrickY500Pos[index-11]/2)-50));
            
            break;
        case 4:
            brickSpr->setPosition(ccp(((level17BrickX500Pos[index-11]/2.54))-60, (level17BrickY500Pos[index-11]/2.54)-33));
            
            break;
        case 5:
            brickSpr->setPosition(ccp(level17BrickX500Pos[index-11]/2, (level17BrickY500Pos[index-11]/2)+250));
            
            break;
        case 6:
            brickSpr->setPosition(ccp((level17BrickX500Pos[index-11]*1.082)-200, (level17BrickY500Pos[index-11]*1.082)-40));
            
            break;
            
        default:
            break;
    }
        break;
        
        
    case 18:
        switch (deviceResolution)
    {
        case 1:
            brickSpr->setPosition(ccp(level18BrickX500Pos[index-11], level18BrickY500Pos[index-11]));
            
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136)
            {
                brickSpr->setPosition(ccp(((level18BrickX500Pos[index-11]/1.8))-110, (level18BrickY500Pos[index-11]/1.8)));
                
            }
            else
            {
                brickSpr->setPosition(ccp(level18BrickX500Pos[index-11]/2, level18BrickY500Pos[index-11]/2));
                
            }
        }
            break;
        case 3:
            brickSpr->setPosition(ccp(((level18BrickX500Pos[index-11]/2))-80, (level18BrickY500Pos[index-11]/2)-50));
            
            break;
        case 4:
            brickSpr->setPosition(ccp(level18BrickX500Pos[index-11]/2, (level18BrickY500Pos[index-11]/2)+250));
            
            break;
        case 5:
            brickSpr->setPosition(ccp(level18BrickX500Pos[index-11]/2, (level18BrickY500Pos[index-11]/2)+250));
            
            break;
        case 6:
            brickSpr->setPosition(ccp(level18BrickX500Pos[index-11]/2, (level18BrickY500Pos[index-11]/2)+250));
            
            break;
            
        default:
            break;
    }
        break;
        
    case 19:
        switch (deviceResolution)
    {
        case 1:
            brickSpr->setPosition(ccp(level19BrickX500Pos[index-11], level19BrickY500Pos[index-11]));
            
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136)
            {
                brickSpr->setPosition(ccp(((level19BrickX500Pos[index-11]/1.8))-110, (level19BrickY500Pos[index-11]/1.8)));
                
            }
            else
            {
                brickSpr->setPosition(ccp(level19BrickX500Pos[index-11]/2, level19BrickY500Pos[index-11]/2));
                
            }
        }
            break;
        case 3:
            brickSpr->setPosition(ccp(((level19BrickX500Pos[index-11]/2))-80, (level19BrickY500Pos[index-11]/2)-50));
            
            break;
        case 4:
            brickSpr->setPosition(ccp(((level19BrickX500Pos[index-11]/2.54))-60, (level19BrickY500Pos[index-11]/2.54)-33));
            
            break;
        case 5:
            brickSpr->setPosition(ccp(level19BrickX500Pos[index-11]/2, (level19BrickY500Pos[index-11]/2)+250));
            
            break;
        case 6:
            brickSpr->setPosition(ccp((level19BrickX500Pos[index-11]*1.082)-200, (level19BrickY500Pos[index-11]*1.082)-40));
            
            break;
            
        default:
            break;
    }
        break;
        
        
    case 20:
        switch (deviceResolution)
    {
        case 1:
            brickSpr->setPosition(ccp(level20BrickX500Pos[index-11], level20BrickY500Pos[index-11]));
            
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136)
            {
                brickSpr->setPosition(ccp(((level20BrickX500Pos[index-11]/1.8))-110, (level20BrickY500Pos[index-11]/1.8)));
                
            }
            else
            {
                brickSpr->setPosition(ccp(level20BrickX500Pos[index-11]/2, level20BrickY500Pos[index-11]/2));
                
            }
        }
            break;
        case 3:
            brickSpr->setPosition(ccp(((level20BrickX500Pos[index-11]/2))-80, (level20BrickY500Pos[index-11]/2)-50));
            
            break;
        case 4:
            brickSpr->setPosition(ccp(((level20BrickX500Pos[index-11]/2.54))-60, (level20BrickY500Pos[index-11]/2.54)-33));
            
            break;
        case 5:
            brickSpr->setPosition(ccp(level20BrickX500Pos[index-11]/2, (level20BrickY500Pos[index-11]/2)+250));
            
            break;
        case 6:
            brickSpr->setPosition(ccp((level20BrickX500Pos[index-11]*1.082)-200, (level20BrickY500Pos[index-11]*1.082)-40));
            
            break;
            
        default:
            break;
    }
        break;
        
        
    case 21:
        switch (deviceResolution)
    {
        case 1:
            brickSpr->setPosition(ccp(level21BrickX500Pos[index-11], level21BrickY500Pos[index-11]));
            
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136)
            {
                brickSpr->setPosition(ccp(((level21BrickX500Pos[index-11]/1.8))-110, (level21BrickY500Pos[index-11]/1.8)));
                
            }
            else
            {
                brickSpr->setPosition(ccp(level21BrickX500Pos[index-11]/2, level21BrickY500Pos[index-11]/2));
                
            }
        }
            break;
        case 3:
            brickSpr->setPosition(ccp(((level21BrickX500Pos[index-11]/2))-80, (level21BrickY500Pos[index-11]/2)-50));
            
            break;
        case 4:
            brickSpr->setPosition(ccp(((level21BrickX500Pos[index-11]/2.54))-60,(level21BrickY500Pos[index-11]/2.54)-33));
            
            break;
        case 5:
            brickSpr->setPosition(ccp(level21BrickX500Pos[index-11]/2, (level21BrickY500Pos[index-11]/2)+250));
            
            break;
        case 6:
            brickSpr->setPosition(ccp((level21BrickX500Pos[index-11]*1.082)-200, (level21BrickY500Pos[index-11]*1.082)-40));
            
            break;
            
        default:
            break;
    }
        break;
        
        
    case 22:
        switch (deviceResolution)
    {
        case 1:
            brickSpr->setPosition(ccp(level22BrickX500Pos[index-11], level22BrickY500Pos[index-11]));
            
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136)
            {
                brickSpr->setPosition(ccp(((level22BrickX500Pos[index-11]/1.8))-110, (level22BrickY500Pos[index-11]/1.8)));
                
            }
            else
            {
                brickSpr->setPosition(ccp(level22BrickX500Pos[index-11]/2, level22BrickY500Pos[index-11]/2));
                
            }
        }
            break;
        case 3:
            brickSpr->setPosition(ccp(((level22BrickX500Pos[index-11]/2))-80, (level22BrickY500Pos[index-11]/2)-50));
            
            break;
        case 4:
            brickSpr->setPosition(ccp(((level22BrickX500Pos[index-11]/2.54))-60, (level22BrickY500Pos[index-11]/2.54)-33));
            
            break;
        case 5:
            brickSpr->setPosition(ccp(level22BrickX500Pos[index-11]/2, (level22BrickY500Pos[index-11]/2)+250));
            
            break;
        case 6:
            brickSpr->setPosition(ccp((level22BrickX500Pos[index-11]*1.082)-200, (level22BrickY500Pos[index-11]*1.082)-40));
            
            break;
            
        default:
            break;
    }
        break;
        
        
    case 23:
        switch (deviceResolution)
    {
        case 1:
            brickSpr->setPosition(ccp(level23BrickX500Pos[index-11], level23BrickY500Pos[index-11]));
            
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136)
            {
                brickSpr->setPosition(ccp(((level23BrickX500Pos[index-11]/1.8))-110, (level23BrickY500Pos[index-11]/1.8)));
                
            }
            else
            {
                brickSpr->setPosition(ccp(level23BrickX500Pos[index-11]/2, level23BrickY500Pos[index-11]/2));
                
            }
        }
            break;
        case 3:
            brickSpr->setPosition(ccp(((level23BrickX500Pos[index-11]/2))-80, (level23BrickY500Pos[index-11]/2)-50));
            
            break;
        case 4:
            brickSpr->setPosition(ccp(((level23BrickX500Pos[index-11]/2.54))-60, (level23BrickY500Pos[index-11]/2.54)-33));
            break;
        case 5:
            brickSpr->setPosition(ccp(level23BrickX500Pos[index-11]/2, (level23BrickY500Pos[index-11]/2)+250));
            
            break;
        case 6:
            brickSpr->setPosition(ccp((level23BrickX500Pos[index-11]*1.082)-200, (level23BrickY500Pos[index-11]*1.082)-40));
            
            break;
            
        default:
            break;
    }
        break;
        
    case 24:
        switch (deviceResolution)
    {
        case 1:
            brickSpr->setPosition(ccp(level24BrickX500Pos[index-11], level24BrickY500Pos[index-11]));
            
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136)
            {
                brickSpr->setPosition(ccp(((level24BrickX500Pos[index-11]/1.8))-110, (level24BrickY500Pos[index-11]/1.8)));
                
            }
            else
            {
                brickSpr->setPosition(ccp(level24BrickX500Pos[index-11]/2, level24BrickY500Pos[index-11]/2));
                
            }
        }
            break;
        case 3:
            brickSpr->setPosition(ccp(((level24BrickX500Pos[index-11]/2))-80, (level24BrickY500Pos[index-11]/2)-50));
            
            break;
        case 4:
            brickSpr->setPosition(ccp(((level24BrickX500Pos[index-11]/2.54))-60, (level24BrickY500Pos[index-11]/2.54)-33));
            
            break;
        case 5:
            brickSpr->setPosition(ccp(level24BrickX500Pos[index-11]/2, (level24BrickY500Pos[index-11]/2)+250));
            
            break;
        case 6:
            brickSpr->setPosition(ccp((level24BrickX500Pos[index-11]*1.082)-200, (level24BrickY500Pos[index-11]*1.082)-40));
            
            break;
            
        default:
            break;
    }
        break;
        
    case 25:
        switch (deviceResolution)
    {
        case 1:
            brickSpr->setPosition(ccp(level25BrickX500Pos[index-11], level25BrickY500Pos[index-11]));
            
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136)
            {
                brickSpr->setPosition(ccp(((level25BrickX500Pos[index-11]/1.8))-110, (level25BrickY500Pos[index-11]/1.8)));
                
            }
            else
            {
                brickSpr->setPosition(ccp(level25BrickX500Pos[index-11]/2, level25BrickY500Pos[index-11]/2));
                
            }
        }
            break;
        case 3:
            brickSpr->setPosition(ccp(((level25BrickX500Pos[index-11]/2))-80, (level25BrickY500Pos[index-11]/2)-50));
            
            break;
        case 4:
            brickSpr->setPosition(ccp(((level25BrickX500Pos[index-11]/2.54))-60, (level25BrickY500Pos[index-11]/2.54)-33));
            
            break;
        case 5:
            brickSpr->setPosition(ccp(level25BrickX500Pos[index-11]/2, (level25BrickY500Pos[index-11]/2)+250));
            
            break;
        case 6:
            brickSpr->setPosition(ccp((level25BrickX500Pos[index-11]*1.082)-200, (level25BrickY500Pos[index-11]*1.082)-40));
            
            break;
            
        default:
            break;
    }
        break;
        
        
    case 26:
        switch (deviceResolution)
    {
        case 1:
            brickSpr->setPosition(ccp(level26BrickX500Pos[index-11], level26BrickY500Pos[index-11]));
            
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136)
            {
                brickSpr->setPosition(ccp(((level26BrickX500Pos[index-11]/1.8))-110, (level26BrickY500Pos[index-11]/1.8)));
                
            }
            else
            {
                brickSpr->setPosition(ccp(level26BrickX500Pos[index-11]/2, level26BrickY500Pos[index-11]/2));
                
            }
        }
            break;
        case 3:
            brickSpr->setPosition(ccp(((level26BrickX500Pos[index-11]/2))-80, (level26BrickY500Pos[index-11]/2)-50));
            
            break;
        case 4:
            brickSpr->setPosition(ccp(((level26BrickX500Pos[index-11]/2.54))-60, (level26BrickY500Pos[index-11]/2.54)-33));
            
            break;
        case 5:
            brickSpr->setPosition(ccp(level26BrickX500Pos[index-11]/2, (level26BrickY500Pos[index-11]/2)+250));
            
            break;
        case 6:
            brickSpr->setPosition(ccp((level26BrickX500Pos[index-11]*1.082)-200, (level26BrickY500Pos[index-11]*1.082)-40));
            
            break;
            
        default:
            break;
    }
        break;
        
        
    case 27:
        switch (deviceResolution)
    {
        case 1:
            brickSpr->setPosition(ccp(level27BrickX500Pos[index-11], level27BrickY500Pos[index-11]));
            
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136)
            {
                brickSpr->setPosition(ccp(((level27BrickX500Pos[index-11]/1.8))-110, (level27BrickY500Pos[index-11]/1.8)));
                
            }
            else
            {
                brickSpr->setPosition(ccp(level27BrickX500Pos[index-11]/2, level27BrickY500Pos[index-11]/2));
                
            }
        }
            break;
        case 3:
            brickSpr->setPosition(ccp(((level27BrickX500Pos[index-11]/2))-80, (level27BrickY500Pos[index-11]/2)-50));
            
            break;
        case 4:
            brickSpr->setPosition(ccp(((level27BrickX500Pos[index-11]/2.54))-60, (level27BrickY500Pos[index-11]/2.54)-33));
            
            break;
        case 5:
            brickSpr->setPosition(ccp(level27BrickX500Pos[index-11]/2, (level27BrickY500Pos[index-11]/2)+250));
            
            break;
        case 6:
            brickSpr->setPosition(ccp((level27BrickX500Pos[index-11]*1.082)-200, (level27BrickY500Pos[index-11]*1.082)-40));
            
            break;
            
        default:
            break;
    }
        break;
        
        
    case 28:
        switch (deviceResolution)
    {
        case 1:
            brickSpr->setPosition(ccp(level28BrickX500Pos[index-11], level28BrickY500Pos[index-11]));
            
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136)
            {
                brickSpr->setPosition(ccp(((level28BrickX500Pos[index-11]/1.8))-110, (level28BrickY500Pos[index-11]/1.8)));
                
            }
            else
            {
                brickSpr->setPosition(ccp(level28BrickX500Pos[index-11]/2, level28BrickY500Pos[index-11]/2));
                
            }
        }
            break;
        case 3:
            brickSpr->setPosition(ccp(((level28BrickX500Pos[index-11]/2))-80, (level28BrickY500Pos[index-11]/2)-50));
            
            break;
        case 4:
            brickSpr->setPosition(ccp(((level28BrickX500Pos[index-11]/2.54))-60, (level28BrickY500Pos[index-11]/2.54)-33));
            
            break;
        case 5:
            brickSpr->setPosition(ccp(level28BrickX500Pos[index-11]/2, (level28BrickY500Pos[index-11]/2)+250));
            
            break;
        case 6:
            brickSpr->setPosition(ccp((level28BrickX500Pos[index-11]*1.082)-200, (level28BrickY500Pos[index-11]*1.082)-40));
            
            break;
            
        default:
            break;
    }
        break;
        
        
    case 29:
        switch (deviceResolution)
    {
        case 1:
            brickSpr->setPosition(ccp(level29BrickX500Pos[index-11], level29BrickY500Pos[index-11]));
            
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136)
            {
                brickSpr->setPosition(ccp(((level29BrickX500Pos[index-11]/1.8))-110, (level29BrickY500Pos[index-11]/1.8)));
                
            }
            else
            {
                brickSpr->setPosition(ccp(level29BrickX500Pos[index-11]/2, level29BrickY500Pos[index-11]/2));
                
            }
        }
            break;
        case 3:
            brickSpr->setPosition(ccp(((level29BrickX500Pos[index-11]/2))-80, (level29BrickY500Pos[index-11]/2)-50));
            
            break;
        case 4:
            brickSpr->setPosition(ccp(((level29BrickX500Pos[index-11]/2.54))-60, (level29BrickY500Pos[index-11]/2.54)-33));
            
            break;
        case 5:
            brickSpr->setPosition(ccp(level29BrickX500Pos[index-11]/2, (level29BrickY500Pos[index-11]/2)+250));
            
            break;
        case 6:
            brickSpr->setPosition(ccp((level29BrickX500Pos[index-11]*1.082)-200, (level29BrickY500Pos[index-11]*1.082)-40));
            
            break;
            
        default:
            break;
    }
        break;
        
        
    case 30:
        switch (deviceResolution)
    {
        case 1:
            brickSpr->setPosition(ccp(level30BrickX500Pos[index-11], level30BrickY500Pos[index-11]));
            
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136)
            {
                brickSpr->setPosition(ccp(((level30BrickX500Pos[index-11]/1.8))-110, (level30BrickY500Pos[index-11]/1.8)));
                
            }
            else
            {
                brickSpr->setPosition(ccp(level30BrickX500Pos[index-11]/2, level30BrickY500Pos[index-11]/2));
                
            }
        }
            break;
        case 3:
            brickSpr->setPosition(ccp(((level30BrickX500Pos[index-11]/2))-80, (level30BrickY500Pos[index-11]/2)-50));
            
            break;
        case 4:
            brickSpr->setPosition(ccp(((level30BrickX500Pos[index-11]/2.54))-60, (level30BrickY500Pos[index-11]/2.54)-33));
            
            break;
        case 5:
            brickSpr->setPosition(ccp(level30BrickX500Pos[index-11]/2, (level30BrickY500Pos[index-11]/2)+250));
            
            break;
        case 6:
            brickSpr->setPosition(ccp((level30BrickX500Pos[index-11]*1.082)-200, (level30BrickY500Pos[index-11]*1.082)-40));
            
            break;
            
        default:
            break;
    }
        break;
        
        
    case 31:
        switch (deviceResolution)
    {
        case 1:
            brickSpr->setPosition(ccp(level31BrickX500Pos[index-11], level31BrickY500Pos[index-11]));
            
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136)
            {
                brickSpr->setPosition(ccp(((level31BrickX500Pos[index-11]/1.8))-110, (level31BrickY500Pos[index-11]/1.8)));
                
            }
            else
            {
                brickSpr->setPosition(ccp(level31BrickX500Pos[index-11]/2, level31BrickY500Pos[index-11]/2));
                
            }
        }
            break;
        case 3:
            brickSpr->setPosition(ccp(((level31BrickX500Pos[index-11]/2))-80, (level31BrickY500Pos[index-11]/2)-50));
            
            break;
        case 4:
            brickSpr->setPosition(ccp(((level31BrickX500Pos[index-11]/2.54))-60, (level31BrickY500Pos[index-11]/2.54)-33));
            
            break;
        case 5:
            brickSpr->setPosition(ccp(level31BrickX500Pos[index-11]/2, (level31BrickY500Pos[index-11]/2)+250));
            
            break;
        case 6:
            brickSpr->setPosition(ccp((level31BrickX500Pos[index-11]*1.082)-200, (level31BrickY500Pos[index-11]*1.082)-40));
            
            break;
            
        default:
            break;
    }
        break;
        
    case 32:
        switch (deviceResolution)
    {
        case 1:
            brickSpr->setPosition(ccp(level32BrickX500Pos[index-11], level32BrickY500Pos[index-11]));
            
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136)
            {
                brickSpr->setPosition(ccp(((level32BrickX500Pos[index-11]/1.8))-110, (level32BrickY500Pos[index-11]/1.8)));
                
            }
            else
            {
                brickSpr->setPosition(ccp(level32BrickX500Pos[index-11]/2, level32BrickY500Pos[index-11]/2));
                
            }
        }
            break;
        case 3:
            brickSpr->setPosition(ccp(((level32BrickX500Pos[index-11]/2))-80, (level32BrickY500Pos[index-11]/2)-50));
            
            break;
        case 4:
            brickSpr->setPosition(ccp(((level32BrickX500Pos[index-11]/2.54))-60, (level32BrickY500Pos[index-11]/2.54)-33));
            
            break;
        case 5:
            brickSpr->setPosition(ccp(level32BrickX500Pos[index-11]/2, (level32BrickY500Pos[index-11]/2)+250));
            
            break;
        case 6:
            brickSpr->setPosition(ccp((level32BrickX500Pos[index-11]*1.082)-200, (level32BrickY500Pos[index-11]*1.082)-40));
            
            break;
            
        default:
            break;
    }
        break;
        
        
        
    case 33:
        break;
        
        
    case 34:
        break;
        
        
    case 35:
        break;
        
        
    case 36:
        break;
        
        
    case 37:
        break;
        
        
    case 38:
        break;
        
        
    case 39:
        break;
        
        
    case 41:
        
        switch (deviceResolution)
    {
        case 1:
            brickSpr->setPosition(ccp(level41BrickX500Pos[index-11], level41BrickY500Pos[index-11]));
            
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136)
            {
                brickSpr->setPosition(ccp(((level41BrickX500Pos[index-11]/1.8))-110, (level41BrickY500Pos[index-11]/1.8)));
                
            }
            else
            {
                brickSpr->setPosition(ccp(level41BrickX500Pos[index-11]/2, level41BrickY500Pos[index-11]/2));
                
            }
        }
            break;
        case 3:
            brickSpr->setPosition(ccp(((level41BrickX500Pos[index-11]/2))-80, (level41BrickY500Pos[index-11]/2)-50));
            
            break;
        case 4:
            brickSpr->setPosition(ccp(((level41BrickX500Pos[index-11]/2.54))-60, (level41BrickY500Pos[index-11]/2.54)-33));
            
            break;
        case 5:
            brickSpr->setPosition(ccp(level41BrickX500Pos[index-11]/2, (level41BrickY500Pos[index-11]/2)+250));
            
            break;
        case 6:
            brickSpr->setPosition(ccp((level41BrickX500Pos[index-11]*1.082)-200, (level41BrickY500Pos[index-11]*1.082)-40));
            
            break;
            
        default:
            break;
    }
        break;
    case 42:
        switch (deviceResolution)
    {
        case 1:
            brickSpr->setPosition(ccp(level42BrickX500Pos[index-11], level42BrickY500Pos[index-11]));
            
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136)
            {
                brickSpr->setPosition(ccp(((level42BrickX500Pos[index-11]/1.8))-110, (level42BrickY500Pos[index-11]/1.8)));
                
            }
            else
            {
                brickSpr->setPosition(ccp(level42BrickX500Pos[index-11]/2, level42BrickY500Pos[index-11]/2));
                
            }
        }
            break;
        case 3:
            brickSpr->setPosition(ccp(((level42BrickX500Pos[index-11]/2))-80, (level42BrickY500Pos[index-11]/2)-50));
            
            break;
        case 4:
            brickSpr->setPosition(ccp(((level42BrickX500Pos[index-11]/2.54))-60, (level42BrickY500Pos[index-11]/2.54)-33));
            
            break;
        case 5:
            brickSpr->setPosition(ccp(level42BrickX500Pos[index-11]/2, (level42BrickY500Pos[index-11]/2)+250));
            
            break;
        case 6:
            brickSpr->setPosition(ccp((level42BrickX500Pos[index-11]*1.082)-200, (level42BrickY500Pos[index-11]*1.082)-40));
            
            break;
            
        default:
            break;
    }
        break;
        
    case 43:
        switch (deviceResolution)
    {
        case 1:
            brickSpr->setPosition(ccp(level43BrickX500Pos[index-11], level43BrickY500Pos[index-11]));
            
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136)
            {
                brickSpr->setPosition(ccp(((level43BrickX500Pos[index-11]/1.8))-110, (level43BrickY500Pos[index-11]/1.8)));
                
            }
            else
            {
                brickSpr->setPosition(ccp(level43BrickX500Pos[index-11]/2, level43BrickY500Pos[index-11]/2));
                
            }
        }
            break;
        case 3:
            brickSpr->setPosition(ccp(((level43BrickX500Pos[index-11]/2))-80, (level43BrickY500Pos[index-11]/2)-50));
            
            break;
        case 4:
            brickSpr->setPosition(ccp(((level43BrickX500Pos[index-11]/2.54))-60, (level43BrickY500Pos[index-11]/2.54)-33));
            
            break;
        case 5:
            brickSpr->setPosition(ccp(level43BrickX500Pos[index-11]/2, (level43BrickY500Pos[index-11]/2)+250));
            
            break;
        case 6:
            brickSpr->setPosition(ccp((level43BrickX500Pos[index-11]*1.082)-200, (level43BrickY500Pos[index-11]*1.082)-40));
            
            break;
            
        default:
            break;
    }
        break;
        
        
    case 44:
        switch (deviceResolution)
    {
        case 1:
            brickSpr->setPosition(ccp(level44BrickX500Pos[index-11], level44BrickY500Pos[index-11]));
            
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136)
            {
                brickSpr->setPosition(ccp(((level44BrickX500Pos[index-11]/1.8))-110, (level44BrickY500Pos[index-11]/1.8)));
                
            }
            else
            {
                brickSpr->setPosition(ccp(level44BrickX500Pos[index-11]/2, level44BrickY500Pos[index-11]/2));
                
            }
        }
            break;
        case 3:
            brickSpr->setPosition(ccp(((level44BrickX500Pos[index-11]/2))-80, (level44BrickY500Pos[index-11]/2)-50));
            
            break;
        case 4:
            brickSpr->setPosition(ccp(((level44BrickX500Pos[index-11]/2.54))-60, (level44BrickY500Pos[index-11]/2.54)-33));
            
            break;
        case 5:
            brickSpr->setPosition(ccp(level44BrickX500Pos[index-11]/2, (level44BrickY500Pos[index-11]/2)+250));
            
            break;
        case 6:
            brickSpr->setPosition(ccp((level44BrickX500Pos[index-11]*1.082)-200, (level44BrickY500Pos[index-11]*1.082)-40));
            
            break;
            
        default:
            break;
    }
        break;
        
        
    case 45:
        switch (deviceResolution)
    {
        case 1:
            brickSpr->setPosition(ccp(level45BrickX500Pos[index-11], level45BrickY500Pos[index-11]));
            
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136)
            {
                brickSpr->setPosition(ccp(((level45BrickX500Pos[index-11]/1.8))-110, (level45BrickY500Pos[index-11]/1.8)));
                
            }
            else
            {
                brickSpr->setPosition(ccp(level45BrickX500Pos[index-11]/2, level45BrickY500Pos[index-11]/2));
                
            }
        }
            break;
        case 3:
            brickSpr->setPosition(ccp(((level45BrickX500Pos[index-11]/2))-80, (level45BrickY500Pos[index-11]/2)-50));
            
            break;
        case 4:
            brickSpr->setPosition(ccp(((level45BrickX500Pos[index-11]/2.54))-60, (level45BrickY500Pos[index-11]/2.54)-33));
            
            break;
        case 5:
            brickSpr->setPosition(ccp(level45BrickX500Pos[index-11]/2, (level45BrickY500Pos[index-11]/2)+250));
            
            break;
        case 6:
            brickSpr->setPosition(ccp((level45BrickX500Pos[index-11]*1.082)-200, (level45BrickY500Pos[index-11]*1.082)-40));
            
            break;
            
        default:
            break;
    }
        break;
        
        
    case 46:
        switch (deviceResolution)
    {
        case 1:
            brickSpr->setPosition(ccp(level46BrickX500Pos[index-11], level46BrickY500Pos[index-11]));
            
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136)
            {
                brickSpr->setPosition(ccp(((level46BrickX500Pos[index-11]/1.8))-110, (level46BrickY500Pos[index-11]/1.8)));
                
            }
            else
            {
                brickSpr->setPosition(ccp(level46BrickX500Pos[index-11]/2, level46BrickY500Pos[index-11]/2));
                
            }
        }
            break;
        case 3:
            brickSpr->setPosition(ccp(((level46BrickX500Pos[index-11]/2))-80, (level46BrickY500Pos[index-11]/2)-50));
            
            break;
        case 4:
            brickSpr->setPosition(ccp(((level46BrickX500Pos[index-11]/2.54))-60, (level46BrickY500Pos[index-11]/2.54)-33));
            break;
        case 5:
            brickSpr->setPosition(ccp(level46BrickX500Pos[index-11]/2, (level46BrickY500Pos[index-11]/2)+250));
            
            break;
        case 6:
            brickSpr->setPosition(ccp((level46BrickX500Pos[index-11]*1.082)-200, (level46BrickY500Pos[index-11]*1.082)-40));
            
            break;
            
        default:
            break;
    }
        break;
        
        
        
    case 47:
        switch (deviceResolution)
    {
        case 1:
            brickSpr->setPosition(ccp(level47BrickX500Pos[index-11], level47BrickY500Pos[index-11]));
            
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136)
            {
                brickSpr->setPosition(ccp(((level47BrickX500Pos[index-11]/1.8))-110, (level47BrickY500Pos[index-11]/1.8)));
                
            }
            else
            {
                brickSpr->setPosition(ccp(level47BrickX500Pos[index-11]/2, level47BrickY500Pos[index-11]/2));
                
            }
        }
            break;
        case 3:
            brickSpr->setPosition(ccp(((level47BrickX500Pos[index-11]/2))-80, (level47BrickY500Pos[index-11]/2)-50));
            
            break;
        case 4:
            brickSpr->setPosition(ccp(((level47BrickX500Pos[index-11]/2.54))-60, (level47BrickY500Pos[index-11]/2.54)-33));
            
            break;
        case 5:
            brickSpr->setPosition(ccp(level47BrickX500Pos[index-11]/2, (level47BrickY500Pos[index-11]/2)+250));
            
            break;
        case 6:
            brickSpr->setPosition(ccp((level47BrickX500Pos[index-11]*1.082)-200, (level47BrickY500Pos[index-11]*1.082)-40));
            
            break;
            
        default:
            break;
    }
        break;
    case 48:
        switch (deviceResolution)
    {
        case 1:
            brickSpr->setPosition(ccp(level48BrickX500Pos[index-11], level48BrickY500Pos[index-11]));
            
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136)
            {
                brickSpr->setPosition(ccp(((level48BrickX500Pos[index-11]/1.8))-110, (level48BrickY500Pos[index-11]/1.8)));
                
            }
            else
            {
                brickSpr->setPosition(ccp(level48BrickX500Pos[index-11]/2, level48BrickY500Pos[index-11]/2));
                
            }
        }
            break;
        case 3:
            brickSpr->setPosition(ccp(((level48BrickX500Pos[index-11]/2))-80, (level48BrickY500Pos[index-11]/2)-50));
            
            break;
        case 4:
            brickSpr->setPosition(ccp(((level48BrickX500Pos[index-11]/2.54))-60, (level48BrickY500Pos[index-11]/2.54)-33));
            
            break;
        case 5:
            brickSpr->setPosition(ccp(level48BrickX500Pos[index-11]/2, (level48BrickY500Pos[index-11]/2)+250));
            
            break;
        case 6:
            brickSpr->setPosition(ccp((level48BrickX500Pos[index-11]*1.082)-200, (level48BrickY500Pos[index-11]*1.082)-40));
            
            break;
            
        default:
            break;
    }
        break;
        
        
    case 49:
        switch (deviceResolution)
    {
        case 1:
            brickSpr->setPosition(ccp(level49BrickX500Pos[index-11], level49BrickY500Pos[index-11]));
            
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136)
            {
                brickSpr->setPosition(ccp(((level49BrickX500Pos[index-11]/1.8))-110, (level49BrickY500Pos[index-11]/1.8)));
                
            }
            else
            {
                brickSpr->setPosition(ccp(level49BrickX500Pos[index-11]/2, level49BrickY500Pos[index-11]/2));
                
            }
        }
            break;
        case 3:
            brickSpr->setPosition(ccp(((level49BrickX500Pos[index-11]/2))-80, (level49BrickY500Pos[index-11]/2)-50));
            
            break;
        case 4:
            brickSpr->setPosition(ccp(((level49BrickX500Pos[index-11]/2.54))-60, (level49BrickY500Pos[index-11]/2.54)-33));
            
            break;
        case 5:
            brickSpr->setPosition(ccp(level49BrickX500Pos[index-11]/2, (level49BrickY500Pos[index-11]/2)+250));
            
            break;
        case 6:
            brickSpr->setPosition(ccp((level49BrickX500Pos[index-11]*1.082)-200, (level49BrickY500Pos[index-11]*1.082)-40));
            
            break;
            
        default:
            break;
    }
        break;
        
        
    case 50:
        switch (deviceResolution)
    {
        case 1:
            brickSpr->setPosition(ccp(level50BrickX500Pos[index-11], level50BrickY500Pos[index-11]));
            
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136)
            {
                brickSpr->setPosition(ccp(((level50BrickX500Pos[index-11]/1.8))-110, (level50BrickY500Pos[index-11]/1.8)));
                
            }
            else
            {
                brickSpr->setPosition(ccp(level50BrickX500Pos[index-11]/2, level50BrickY500Pos[index-11]/2));
                
            }
        }
            break;
        case 3:
            brickSpr->setPosition(ccp(((level50BrickX500Pos[index-11]/2))-80, (level50BrickY500Pos[index-11]/2)-50));
            
            break;
        case 4:
            brickSpr->setPosition(ccp(((level50BrickX500Pos[index-11]/2.54))-60, (level50BrickY500Pos[index-11]/2.54)-33));
            
            break;
        case 5:
            brickSpr->setPosition(ccp(level50BrickX500Pos[index-11]/2, (level50BrickY500Pos[index-11]/2)+250));
            
            break;
        case 6:
            brickSpr->setPosition(ccp((level50BrickX500Pos[index-11]*1.082)-200, (level50BrickY500Pos[index-11]*1.082)-40));
            
            break;
            
        default:
            break;
    }
        break;
        
        
    case 51:
        switch (deviceResolution)
    {
        case 1:
            brickSpr->setPosition(ccp(level51BrickX500Pos[index-11], level51BrickY500Pos[index-11]));
            
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136)
            {
                brickSpr->setPosition(ccp(((level51BrickX500Pos[index-11]/1.8))-110, (level51BrickY500Pos[index-11]/1.8)));
                
            }
            else
            {
                brickSpr->setPosition(ccp(level51BrickX500Pos[index-11]/2, level51BrickY500Pos[index-11]/2));
                
            }
        }
            break;
        case 3:
            brickSpr->setPosition(ccp(((level51BrickX500Pos[index-11]/2))-80, (level51BrickY500Pos[index-11]/2)-50));
            
            break;
        case 4:
            brickSpr->setPosition(ccp(((level51BrickX500Pos[index-11]/2.54))-60, (level51BrickY500Pos[index-11]/2.54)-33));
            
            break;
        case 5:
            brickSpr->setPosition(ccp(level51BrickX500Pos[index-11]/2, (level51BrickY500Pos[index-11]/2)+250));
            
            break;
        case 6:
            brickSpr->setPosition(ccp((level51BrickX500Pos[index-11]*1.082)-200, (level51BrickY500Pos[index-11]*1.082)-40));
            
            break;
            
        default:
            break;
    }
        break;
        
        
    case 52:
        switch (deviceResolution)
    {
        case 1:
            brickSpr->setPosition(ccp(level52BrickX500Pos[index-11], level52BrickY500Pos[index-11]));
            
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136)
            {
                brickSpr->setPosition(ccp(((level52BrickX500Pos[index-11]/1.8))-110, (level52BrickY500Pos[index-11]/1.8)));
                
            }
            else
            {
                brickSpr->setPosition(ccp(level52BrickX500Pos[index-11]/2, level52BrickY500Pos[index-11]/2));
                
            }
        }
            break;
        case 3:
            brickSpr->setPosition(ccp(((level52BrickX500Pos[index-11]/2))-80, (level52BrickY500Pos[index-11]/2)-50));
            
            break;
        case 4:
            brickSpr->setPosition(ccp(((level52BrickX500Pos[index-11]/2.54))-60, (level52BrickY500Pos[index-11]/2.54)-33));
            
            break;
        case 5:
            brickSpr->setPosition(ccp(level52BrickX500Pos[index-11]/2, (level52BrickY500Pos[index-11]/2)+250));
            
            break;
        case 6:
            brickSpr->setPosition(ccp((level52BrickX500Pos[index-11]*1.082)-200, (level52BrickY500Pos[index-11]*1.082)-40));
            
            break;
            
        default:
            break;
    }
        break;
        
        
    case 53:
        switch (deviceResolution)
    {
        case 1:
            brickSpr->setPosition(ccp(level53BrickX500Pos[index-11], level53BrickY500Pos[index-11]));
            
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136)
            {
                brickSpr->setPosition(ccp(((level53BrickX500Pos[index-11]/1.8))-110, (level53BrickY500Pos[index-11]/1.8)));
                
            }
            else
            {
                brickSpr->setPosition(ccp(level53BrickX500Pos[index-11]/2, level53BrickY500Pos[index-11]/2));
                
            }
        }
            break;
        case 3:
            brickSpr->setPosition(ccp(((level53BrickX500Pos[index-11]/2))-80, (level53BrickY500Pos[index-11]/2)-50));
            
            break;
        case 4:
            brickSpr->setPosition(ccp(((level53BrickX500Pos[index-11]/2.54))-60, (level53BrickY500Pos[index-11]/2.54)-33));
            
            break;
        case 5:
            brickSpr->setPosition(ccp(level53BrickX500Pos[index-11]/2, (level53BrickY500Pos[index-11]/2)+250));
            
            break;
        case 6:
            brickSpr->setPosition(ccp((level53BrickX500Pos[index-11]*1.082)-200, (level53BrickY500Pos[index-11]*1.082)-40));
            
            break;
            
        default:
            break;
    }
        break;
        
        
    case 54:
        switch (deviceResolution)
    {
        case 1:
            brickSpr->setPosition(ccp(level54BrickX500Pos[index-11], level54BrickY500Pos[index-11]));
            
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136)
            {
                brickSpr->setPosition(ccp(((level54BrickX500Pos[index-11]/1.8))-110, (level54BrickY500Pos[index-11]/1.8)));
                
            }
            else
            {
                brickSpr->setPosition(ccp(level54BrickX500Pos[index-11]/2, level54BrickY500Pos[index-11]/2));
                
            }
        }
            break;
        case 3:
            brickSpr->setPosition(ccp(((level54BrickX500Pos[index-11]/2))-80, (level54BrickY500Pos[index-11]/2)-50));
            
            break;
        case 4:
            brickSpr->setPosition(ccp(((level54BrickX500Pos[index-11]/2.54))-60, (level54BrickY500Pos[index-11]/2.54)-33));
            
            break;
        case 5:
            brickSpr->setPosition(ccp(level54BrickX500Pos[index-11]/2, (level54BrickY500Pos[index-11]/2)+250));
            
            break;
        case 6:
            brickSpr->setPosition(ccp((level54BrickX500Pos[index-11]*1.082)-200, (level54BrickY500Pos[index-11]*1.082)-40));
            
            break;
            
        default:
            break;
    }
        break;
        
        
    case 55:
        switch (deviceResolution)
    {
        case 1:
            brickSpr->setPosition(ccp(level55BrickX500Pos[index-11], level55BrickY500Pos[index-11]));
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136)
            {
                brickSpr->setPosition(ccp(((level55BrickX500Pos[index-11]/1.8))-110,( level55BrickY500Pos[index-11]/1.8)));
                
            }
            else
            { brickSpr->setPosition(ccp(level55BrickX500Pos[index-11]/2, level55BrickY500Pos[index-11]/2));
            }
        }
            break;
        case 3:
            brickSpr->setPosition(ccp(((level55BrickX500Pos[index-11]/2))-80, (level55BrickY500Pos[index-11]/2)-50));
            
            break;
        case 4:
            brickSpr->setPosition(ccp(((level55BrickX500Pos[index-11]/2.54))-60, (level55BrickY500Pos[index-11]/2.54)-33));
            
            break;
        case 5:
            brickSpr->setPosition(ccp(level55BrickX500Pos[index-11]/2, (level55BrickY500Pos[index-11]/2)+250));
            
            break;
        case 6:
            brickSpr->setPosition(ccp((level55BrickX500Pos[index-11]*1.082)-200, (level55BrickY500Pos[index-11]*1.082)-40));
            
            break;
            
        default:
            break;
    }
        break;
    case 56:
        switch (deviceResolution)
    {
        case 1:
            brickSpr->setPosition(ccp(level56BrickX500Pos[index-11], level56BrickY500Pos[index-11]));
            
            break;
        case 2:
        {
            if (CCDirector::sharedDirector()->getWinSize().height==1136)
            {
                brickSpr->setPosition(ccp(((level56BrickX500Pos[index-11]/1.8))-110, (level56BrickY500Pos[index-11]/1.8)));
                
            }
            else
            {
                brickSpr->setPosition(ccp(level56BrickX500Pos[index-11]/2, level56BrickY500Pos[index-11]/2));
                
            }
        }
            break;
        case 3:
            brickSpr->setPosition(ccp(((level56BrickX500Pos[index-11]/2))-80, (level56BrickY500Pos[index-11]/2)-50));
            
            break;
        case 4:
            brickSpr->setPosition(ccp(((level56BrickX500Pos[index-11]/2.54))-60, (level56BrickY500Pos[index-11]/2.54)-33));
            
            break;
        case 5:
            brickSpr->setPosition(ccp(level56BrickX500Pos[index-11]/2, (level56BrickY500Pos[index-11]/2)+250));
            
            break;
        case 6:
            brickSpr->setPosition(ccp((level56BrickX500Pos[index-11]*1.082)-200, (level56BrickY500Pos[index-11]*1.082)-40));
            
            break;
            
        default:
            break;
    }
        break;
        
        
    default:
        break;
}
    return brickSpr;}




#endif

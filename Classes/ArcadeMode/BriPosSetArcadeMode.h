
#ifndef BreakingBricks_BriPosSetArcadeMode_h
#define BreakingBricks_BriPosSetArcadeMode_h

static CCSprite *brickPositionOnTheScreenDisplayArcadeMode(int localLevel,CCSprite *brickSpr,int index,int deviceResolution)
{
    switch (localLevel) {
        case 1:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level1BrickXPosArcadeMode[index-11], level1BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136){
                    brickSpr->setPosition(ccp(((level1BrickXPosArcadeMode[index-11]/1.8))-110, (level1BrickYPosArcadeMode[index-11]/1.8)));
                }
                else{
                    brickSpr->setPosition(ccp(level1BrickXPosArcadeMode[index-11]/2, level1BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level1BrickXPosArcadeMode[index-11]/2))-80, (level1BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level1BrickXPosArcadeMode[index-11]/2.54))-60, (level1BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level1BrickXPosArcadeMode[index-11]/2, (level1BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level1BrickXPosArcadeMode[index-11]*1.082)-200, (level1BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 111:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level111BrickXPosArcadeMode[index-11], level111BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136){
                    brickSpr->setPosition(ccp(((level111BrickXPosArcadeMode[index-11]/1.8))-110, (level111BrickYPosArcadeMode[index-11]/1.8)));
                }
                else{
                    brickSpr->setPosition(ccp(level111BrickXPosArcadeMode[index-11]/2, level111BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level111BrickXPosArcadeMode[index-11]/2))-80, (level111BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level111BrickXPosArcadeMode[index-11]/2.54))-60, (level111BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level111BrickXPosArcadeMode[index-11]/2, (level111BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level111BrickXPosArcadeMode[index-11]*1.082)-200, (level111BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 1111:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level1111BrickXPosArcadeMode[index-11], level1111BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136){
                    brickSpr->setPosition(ccp(((level1111BrickXPosArcadeMode[index-11]/1.8))-110, (level1111BrickYPosArcadeMode[index-11]/1.8)));
                }
                else{
                    brickSpr->setPosition(ccp(level1111BrickXPosArcadeMode[index-11]/2, level1111BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level1111BrickXPosArcadeMode[index-11]/2))-80, (level1111BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level1111BrickXPosArcadeMode[index-11]/2.54))-60, (level1111BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level1111BrickXPosArcadeMode[index-11]/2, (level1111BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level1111BrickXPosArcadeMode[index-11]*1.082)-200, (level1111BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
        case 11111:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level11111BrickXPosArcadeMode[index-11], level11111BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136){
                    brickSpr->setPosition(ccp(((level11111BrickXPosArcadeMode[index-11]/1.8))-110, (level11111BrickYPosArcadeMode[index-11]/1.8)));
                }
                else{
                    brickSpr->setPosition(ccp(level11111BrickXPosArcadeMode[index-11]/2, level11111BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level11111BrickXPosArcadeMode[index-11]/2))-80, (level11111BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level11111BrickXPosArcadeMode[index-11]/2.54))-60, (level11111BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level11111BrickXPosArcadeMode[index-11]/2, (level11111BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level11111BrickXPosArcadeMode[index-11]*1.082)-200, (level11111BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
            
        case 2:
            
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level2BrickXPosArcadeMode[index-11], level2BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level2BrickXPosArcadeMode[index-11]/1.8))-110, (level2BrickYPosArcadeMode[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level2BrickXPosArcadeMode[index-11]/2, level2BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level2BrickXPosArcadeMode[index-11]/2))-80, (level2BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level2BrickXPosArcadeMode[index-11]/2.54))-60, (level2BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level2BrickXPosArcadeMode[index-11]/2, (level2BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level2BrickXPosArcadeMode[index-11]*1.082)-200, (level2BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
        case 3:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level3BrickXPosArcadeMode[index-11], level3BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level3BrickXPosArcadeMode[index-11]/1.8))-110, (level3BrickYPosArcadeMode[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level3BrickXPosArcadeMode[index-11]/2, level3BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level3BrickXPosArcadeMode[index-11]/2))-80, (level3BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level3BrickXPosArcadeMode[index-11]/2.54))-60, (level3BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level3BrickXPosArcadeMode[index-11]/2, (level3BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level3BrickXPosArcadeMode[index-11]*1.082)-200, (level3BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
        case 4:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level4BrickXPosArcadeMode[index-11], level4BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level4BrickXPosArcadeMode[index-11]/1.8))-110, (level4BrickYPosArcadeMode[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level4BrickXPosArcadeMode[index-11]/2, level4BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level4BrickXPosArcadeMode[index-11]/2))-80, (level4BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level4BrickXPosArcadeMode[index-11]/2.54))-60, (level4BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level4BrickXPosArcadeMode[index-11]/2, (level4BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level4BrickXPosArcadeMode[index-11]*1.082)-200, (level4BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 5:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level5BrickXPosArcadeMode[index-11], level5BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level5BrickXPosArcadeMode[index-11]/1.8))-110, (level5BrickYPosArcadeMode[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level5BrickXPosArcadeMode[index-11]/2, level5BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level5BrickXPosArcadeMode[index-11]/2))-80, (level5BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level5BrickXPosArcadeMode[index-11]/2.54))-60, (level5BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level5BrickXPosArcadeMode[index-11]/2, (level5BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level5BrickXPosArcadeMode[index-11]*1.082)-200, (level5BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
        case 6:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level6BrickXPosArcadeMode[index-11], level6BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level6BrickXPosArcadeMode[index-11]/1.8))-110, (level6BrickYPosArcadeMode[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level6BrickXPosArcadeMode[index-11]/2, level6BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level6BrickXPosArcadeMode[index-11]/2))-80, (level6BrickYPosArcadeMode[index-11]/2)-50));
                break;
            case 4:
                brickSpr->setPosition(ccp(((level6BrickXPosArcadeMode[index-11]/2.54))-60, (level6BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level6BrickXPosArcadeMode[index-11]/2, (level6BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level6BrickXPosArcadeMode[index-11]*1.082)-200, (level6BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
        case 7:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level7BrickXPosArcadeMode[index-11], level7BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level7BrickXPosArcadeMode[index-11]/1.8))-110, (level7BrickYPosArcadeMode[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level7BrickXPosArcadeMode[index-11]/2, level7BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level7BrickXPosArcadeMode[index-11]/2))-80, (level7BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level7BrickXPosArcadeMode[index-11]/2.54))-60, (level7BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level7BrickXPosArcadeMode[index-11]/2, (level7BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level7BrickXPosArcadeMode[index-11]*1.082)-200, (level7BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
        case 8:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level8BrickXPosArcadeMode[index-11], level8BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level8BrickXPosArcadeMode[index-11]/1.8))-110, (level8BrickYPosArcadeMode[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level8BrickXPosArcadeMode[index-11]/2, level8BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level8BrickXPosArcadeMode[index-11]/2))-80, (level8BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level8BrickXPosArcadeMode[index-11]/2.54))-60, (level8BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level8BrickXPosArcadeMode[index-11]/2, (level8BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level8BrickXPosArcadeMode[index-11]*1.082)-200, (level8BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 9:
            
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level9BrickXPosArcadeMode[index-11], level9BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level9BrickXPosArcadeMode[index-11]/1.8))-110, (level9BrickYPosArcadeMode[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level9BrickXPosArcadeMode[index-11]/2, level9BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level9BrickXPosArcadeMode[index-11]/2))-80, (level9BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level9BrickXPosArcadeMode[index-11]/2.54))-60, (level9BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level9BrickXPosArcadeMode[index-11]/2, (level9BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level9BrickXPosArcadeMode[index-11]*1.082)-200, (level9BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
        case 10:
            
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level10BrickXPosArcadeMode[index-11], level10BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level10BrickXPosArcadeMode[index-11]/1.8))-110, (level10BrickYPosArcadeMode[index-11]/1.8)));
                }
                else
                {
                    brickSpr->setPosition(ccp(level10BrickXPosArcadeMode[index-11]/2, level10BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level10BrickXPosArcadeMode[index-11]/2))-80, (level10BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level10BrickXPosArcadeMode[index-11]/2.54))-60, (level10BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level10BrickXPosArcadeMode[index-11]/2, (level10BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level10BrickXPosArcadeMode[index-11]*1.082)-200, (level10BrickYPosArcadeMode[index-11]*1.082)-40));
                break;
                
            default:
                break;
        }
            break;
            
        case 11:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level11BrickXPosArcadeMode[index-11], level11BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level11BrickXPosArcadeMode[index-11]/1.8))-110, (level11BrickYPosArcadeMode[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level11BrickXPosArcadeMode[index-11]/2, level11BrickYPosArcadeMode[index-11]/2));
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level11BrickXPosArcadeMode[index-11]/2))-80, (level11BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level11BrickXPosArcadeMode[index-11]/2.54))-60, (level11BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level11BrickXPosArcadeMode[index-11]/2, (level11BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level11BrickXPosArcadeMode[index-11]*1.082)-200, (level11BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
        case 12:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level12BrickXPosArcadeMode[index-11], level12BrickYPosArcadeMode[index-11]));
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level12BrickXPosArcadeMode[index-11]/1.8))-110, (level12BrickYPosArcadeMode[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level12BrickXPosArcadeMode[index-11]/2, level12BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level12BrickXPosArcadeMode[index-11]/2))-80, (level12BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level12BrickXPosArcadeMode[index-11]/2.54))-60, (level12BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level12BrickXPosArcadeMode[index-11]/2, (level12BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level12BrickXPosArcadeMode[index-11]*1.082)-200, (level12BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
        case 13:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level13BrickXPosArcadeMode[index-11], level13BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level13BrickXPosArcadeMode[index-11]/1.8))-110, (level13BrickYPosArcadeMode[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level13BrickXPosArcadeMode[index-11]/2, level13BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level13BrickXPosArcadeMode[index-11]/2))-80, (level13BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level13BrickXPosArcadeMode[index-11]/2.54))-60, (level13BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level13BrickXPosArcadeMode[index-11]/2, (level13BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level13BrickXPosArcadeMode[index-11]*1.082)-200, (level13BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 14:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level14BrickXPosArcadeMode[index-11], level14BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level14BrickXPosArcadeMode[index-11]/1.8))-110, (level14BrickYPosArcadeMode[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level14BrickXPosArcadeMode[index-11]/2, level14BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level14BrickXPosArcadeMode[index-11]/2))-80, (level14BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level14BrickXPosArcadeMode[index-11]/2.54))-60, (level14BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level14BrickXPosArcadeMode[index-11]/2, (level14BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level14BrickXPosArcadeMode[index-11]*1.082)-200, (level14BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 15:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level15BrickXPosArcadeMode[index-11], level15BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level15BrickXPosArcadeMode[index-11]/1.8))-110, (level15BrickYPosArcadeMode[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level15BrickXPosArcadeMode[index-11]/2, level15BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level15BrickXPosArcadeMode[index-11]/2))-80, (level15BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level15BrickXPosArcadeMode[index-11]/2.54))-60, (level15BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level15BrickXPosArcadeMode[index-11]/2, (level15BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level15BrickXPosArcadeMode[index-11]*1.082)-200, (level15BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
        case 16:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level16BrickXPosArcadeMode[index-11], level16BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136){
                    brickSpr->setPosition(ccp(((level16BrickXPosArcadeMode[index-11]/1.8))-110, (level16BrickYPosArcadeMode[index-11]/1.8)));
                }
                else
                {
                    brickSpr->setPosition(ccp(level16BrickXPosArcadeMode[index-11]/2, level16BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level16BrickXPosArcadeMode[index-11]/2))-80, (level16BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level16BrickXPosArcadeMode[index-11]/2.54))-60, (level16BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level16BrickXPosArcadeMode[index-11]/2, (level16BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level16BrickXPosArcadeMode[index-11]*1.082)-200, (level16BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 17:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level17BrickXPosArcadeMode[index-11], level17BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level17BrickXPosArcadeMode[index-11]/1.8))-110, (level17BrickYPosArcadeMode[index-11]/1.8)));
                }
                else
                {
                    brickSpr->setPosition(ccp(level17BrickXPosArcadeMode[index-11]/2, level17BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level17BrickXPosArcadeMode[index-11]/2))-80, (level17BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level17BrickXPosArcadeMode[index-11]/2.54))-60, (level17BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level17BrickXPosArcadeMode[index-11]/2, (level17BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level17BrickXPosArcadeMode[index-11]*1.082)-200, (level17BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 18:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level18BrickXPosArcadeMode[index-11], level18BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level18BrickXPosArcadeMode[index-11]/1.8))-110, (level18BrickYPosArcadeMode[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level18BrickXPosArcadeMode[index-11]/2, level18BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level18BrickXPosArcadeMode[index-11]/2))-80, (level18BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level18BrickXPosArcadeMode[index-11]/2.54))-60, (level18BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level18BrickXPosArcadeMode[index-11]/2, (level18BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level18BrickXPosArcadeMode[index-11]*1.082)-200, (level18BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
        case 19:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level19BrickXPosArcadeMode[index-11], level19BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level19BrickXPosArcadeMode[index-11]/1.8))-110, (level19BrickYPosArcadeMode[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level19BrickXPosArcadeMode[index-11]/2, level19BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level19BrickXPosArcadeMode[index-11]/2))-80, (level19BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level19BrickXPosArcadeMode[index-11]/2.54))-60, (level19BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level19BrickXPosArcadeMode[index-11]/2, (level19BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level19BrickXPosArcadeMode[index-11]*1.082)-200, (level19BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 20:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level20BrickXPosArcadeMode[index-11], level20BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level20BrickXPosArcadeMode[index-11]/1.8))-110, (level20BrickYPosArcadeMode[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level20BrickXPosArcadeMode[index-11]/2, level20BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level20BrickXPosArcadeMode[index-11]/2))-80, (level20BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level20BrickXPosArcadeMode[index-11]/2.54))-60, (level20BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level20BrickXPosArcadeMode[index-11]/2, (level20BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level20BrickXPosArcadeMode[index-11]*1.082)-200, (level20BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 21:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level21BrickXPosArcadeMode[index-11], level21BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level21BrickXPosArcadeMode[index-11]/1.8))-110, (level21BrickYPosArcadeMode[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level21BrickXPosArcadeMode[index-11]/2, level21BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level21BrickXPosArcadeMode[index-11]/2))-80, (level21BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level21BrickXPosArcadeMode[index-11]/2.54))-60,(level21BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level21BrickXPosArcadeMode[index-11]/2, (level21BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level21BrickXPosArcadeMode[index-11]*1.082)-200, (level21BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 22:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level22BrickXPosArcadeMode[index-11], level22BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level22BrickXPosArcadeMode[index-11]/1.8))-110, (level22BrickYPosArcadeMode[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level22BrickXPosArcadeMode[index-11]/2, level22BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level22BrickXPosArcadeMode[index-11]/2))-80, (level22BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level22BrickXPosArcadeMode[index-11]/2.54))-60, (level22BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level22BrickXPosArcadeMode[index-11]/2, (level22BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level22BrickXPosArcadeMode[index-11]*1.082)-200, (level22BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 23:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level23BrickXPosArcadeMode[index-11], level23BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level23BrickXPosArcadeMode[index-11]/1.8))-110, (level23BrickYPosArcadeMode[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level23BrickXPosArcadeMode[index-11]/2, level23BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level23BrickXPosArcadeMode[index-11]/2))-80, (level23BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level23BrickXPosArcadeMode[index-11]/2.54))-60, (level23BrickYPosArcadeMode[index-11]/2.54)-33));
                break;
            case 5:
                brickSpr->setPosition(ccp(level23BrickXPosArcadeMode[index-11]/2, (level23BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level23BrickXPosArcadeMode[index-11]*1.082)-200, (level23BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
        case 24:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level24BrickXPosArcadeMode[index-11], level24BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level24BrickXPosArcadeMode[index-11]/1.8))-110, (level24BrickYPosArcadeMode[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level24BrickXPosArcadeMode[index-11]/2, level24BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level24BrickXPosArcadeMode[index-11]/2))-80, (level24BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level24BrickXPosArcadeMode[index-11]/2.54))-60, (level24BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level24BrickXPosArcadeMode[index-11]/2, (level24BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level24BrickXPosArcadeMode[index-11]*1.082)-200, (level24BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
            
        case 25:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level25BrickXPosArcadeMode[index-11], level25BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level25BrickXPosArcadeMode[index-11]/1.8))-110, (level25BrickYPosArcadeMode[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level25BrickXPosArcadeMode[index-11]/2, level25BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level25BrickXPosArcadeMode[index-11]/2))-80, (level25BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level25BrickXPosArcadeMode[index-11]/2.54))-60, (level25BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level25BrickXPosArcadeMode[index-11]/2, (level25BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level25BrickXPosArcadeMode[index-11]*1.082)-200, (level25BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 26:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level26BrickXPosArcadeMode[index-11], level26BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level26BrickXPosArcadeMode[index-11]/1.8))-110, (level26BrickYPosArcadeMode[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level26BrickXPosArcadeMode[index-11]/2, level26BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level26BrickXPosArcadeMode[index-11]/2))-80, (level26BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level26BrickXPosArcadeMode[index-11]/2.54))-60, (level26BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level26BrickXPosArcadeMode[index-11]/2, (level26BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level26BrickXPosArcadeMode[index-11]*1.082)-200, (level26BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 27:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level27BrickXPosArcadeMode[index-11], level27BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level27BrickXPosArcadeMode[index-11]/1.8))-110, (level27BrickYPosArcadeMode[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level27BrickXPosArcadeMode[index-11]/2, level27BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level27BrickXPosArcadeMode[index-11]/2))-80, (level27BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level27BrickXPosArcadeMode[index-11]/2.54))-60, (level27BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level27BrickXPosArcadeMode[index-11]/2, (level27BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level27BrickXPosArcadeMode[index-11]*1.082)-200, (level27BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 28:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level28BrickXPosArcadeMode[index-11], level28BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level28BrickXPosArcadeMode[index-11]/1.8))-110, (level28BrickYPosArcadeMode[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level28BrickXPosArcadeMode[index-11]/2, level28BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level28BrickXPosArcadeMode[index-11]/2))-80, (level28BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level28BrickXPosArcadeMode[index-11]/2.54))-60, (level28BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level28BrickXPosArcadeMode[index-11]/2, (level28BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level28BrickXPosArcadeMode[index-11]*1.082)-200, (level28BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 29:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level29BrickXPosArcadeMode[index-11], level29BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level29BrickXPosArcadeMode[index-11]/1.8))-110, (level29BrickYPosArcadeMode[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level29BrickXPosArcadeMode[index-11]/2, level29BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level29BrickXPosArcadeMode[index-11]/2))-80, (level29BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level29BrickXPosArcadeMode[index-11]/2.54))-60, (level29BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level29BrickXPosArcadeMode[index-11]/2, (level29BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level29BrickXPosArcadeMode[index-11]*1.082)-200, (level29BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
        case 30:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level30BrickXPosArcadeMode[index-11], level30BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level30BrickXPosArcadeMode[index-11]/1.8))-110, (level30BrickYPosArcadeMode[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level30BrickXPosArcadeMode[index-11]/2, level30BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level30BrickXPosArcadeMode[index-11]/2))-80, (level30BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level30BrickXPosArcadeMode[index-11]/2.54))-60, (level30BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level30BrickXPosArcadeMode[index-11]/2, (level30BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level30BrickXPosArcadeMode[index-11]*1.082)-200, (level30BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 31:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level31BrickXPosArcadeMode[index-11], level31BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level31BrickXPosArcadeMode[index-11]/1.8))-110, (level31BrickYPosArcadeMode[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level31BrickXPosArcadeMode[index-11]/2, level31BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level31BrickXPosArcadeMode[index-11]/2))-80, (level31BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level31BrickXPosArcadeMode[index-11]/2.54))-60, (level31BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level31BrickXPosArcadeMode[index-11]/2, (level31BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level31BrickXPosArcadeMode[index-11]*1.082)-200, (level31BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
        case 32:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level32BrickXPosArcadeMode[index-11], level32BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level32BrickXPosArcadeMode[index-11]/1.8))-110, (level32BrickYPosArcadeMode[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level32BrickXPosArcadeMode[index-11]/2, level32BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level32BrickXPosArcadeMode[index-11]/2))-80, (level32BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level32BrickXPosArcadeMode[index-11]/2.54))-60, (level32BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level32BrickXPosArcadeMode[index-11]/2, (level32BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level32BrickXPosArcadeMode[index-11]*1.082)-200, (level32BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
            
            
        case 33:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level33BrickXPosArcadeMode[index-11], level33BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level33BrickXPosArcadeMode[index-11]/1.8))-110, (level33BrickYPosArcadeMode[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level33BrickXPosArcadeMode[index-11]/2, level33BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level33BrickXPosArcadeMode[index-11]/2))-80, (level33BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level33BrickXPosArcadeMode[index-11]/2.54))-60, (level33BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level33BrickXPosArcadeMode[index-11]/2, (level33BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level33BrickXPosArcadeMode[index-11]*1.082)-200, (level33BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 34:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level34BrickXPosArcadeMode[index-11], level34BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level34BrickXPosArcadeMode[index-11]/1.8))-110, (level34BrickYPosArcadeMode[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level34BrickXPosArcadeMode[index-11]/2, level34BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level34BrickXPosArcadeMode[index-11]/2))-80, (level34BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level34BrickXPosArcadeMode[index-11]/2.54))-60, (level34BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level34BrickXPosArcadeMode[index-11]/2, (level34BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level34BrickXPosArcadeMode[index-11]*1.082)-200, (level34BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 35:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level35BrickXPosArcadeMode[index-11], level35BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level35BrickXPosArcadeMode[index-11]/1.8))-110, (level35BrickYPosArcadeMode[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level35BrickXPosArcadeMode[index-11]/2, level35BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level35BrickXPosArcadeMode[index-11]/2))-80, (level35BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level35BrickXPosArcadeMode[index-11]/2.54))-60, (level35BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level35BrickXPosArcadeMode[index-11]/2, (level35BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level35BrickXPosArcadeMode[index-11]*1.082)-200, (level35BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 36:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level36BrickXPosArcadeMode[index-11], level36BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level36BrickXPosArcadeMode[index-11]/1.8))-110, (level36BrickYPosArcadeMode[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level36BrickXPosArcadeMode[index-11]/2, level36BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level36BrickXPosArcadeMode[index-11]/2))-80, (level36BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level36BrickXPosArcadeMode[index-11]/2.54))-60, (level36BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level36BrickXPosArcadeMode[index-11]/2, (level36BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level36BrickXPosArcadeMode[index-11]*1.082)-200, (level36BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 37:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level37BrickXPosArcadeMode[index-11], level37BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level37BrickXPosArcadeMode[index-11]/1.8))-110, (level37BrickYPosArcadeMode[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level37BrickXPosArcadeMode[index-11]/2, level37BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level37BrickXPosArcadeMode[index-11]/2))-80, (level37BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level37BrickXPosArcadeMode[index-11]/2.54))-60, (level37BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level37BrickXPosArcadeMode[index-11]/2, (level37BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level37BrickXPosArcadeMode[index-11]*1.082)-200, (level37BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 38:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level38BrickXPosArcadeMode[index-11], level38BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level38BrickXPosArcadeMode[index-11]/1.8))-110, (level38BrickYPosArcadeMode[index-11]/1.8)));
                }
                else
                {
                    brickSpr->setPosition(ccp(level38BrickXPosArcadeMode[index-11]/2, level38BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level38BrickXPosArcadeMode[index-11]/2))-80, (level38BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level38BrickXPosArcadeMode[index-11]/2.54))-60, (level38BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level38BrickXPosArcadeMode[index-11]/2, (level38BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level38BrickXPosArcadeMode[index-11]*1.082)-200, (level38BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 39:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level39BrickXPosArcadeMode[index-11], level39BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level39BrickXPosArcadeMode[index-11]/1.8))-110, (level39BrickYPosArcadeMode[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level39BrickXPosArcadeMode[index-11]/2, level39BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level39BrickXPosArcadeMode[index-11]/2))-80, (level39BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level39BrickXPosArcadeMode[index-11]/2.54))-60, (level39BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level39BrickXPosArcadeMode[index-11]/2, (level39BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level39BrickXPosArcadeMode[index-11]*1.082)-200, (level39BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
        case 40:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level40BrickXPosArcadeMode[index-11], level40BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level40BrickXPosArcadeMode[index-11]/1.8))-110, (level40BrickYPosArcadeMode[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level40BrickXPosArcadeMode[index-11]/2, level40BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level40BrickXPosArcadeMode[index-11]/2))-80, (level40BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level40BrickXPosArcadeMode[index-11]/2.54))-60, (level40BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level40BrickXPosArcadeMode[index-11]/2, (level40BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level40BrickXPosArcadeMode[index-11]*1.082)-200, (level40BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 41:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level41BrickXPosArcadeMode[index-11], level41BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level41BrickXPosArcadeMode[index-11]/1.8))-110, (level41BrickYPosArcadeMode[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level41BrickXPosArcadeMode[index-11]/2, level41BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level41BrickXPosArcadeMode[index-11]/2))-80, (level41BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level41BrickXPosArcadeMode[index-11]/2.54))-60, (level41BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level41BrickXPosArcadeMode[index-11]/2, (level41BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level41BrickXPosArcadeMode[index-11]*1.082)-200, (level41BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 42:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level42BrickXPosArcadeMode[index-11], level42BrickYPosArcadeMode[index-11]));
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level42BrickXPosArcadeMode[index-11]/1.8))-110, (level42BrickYPosArcadeMode[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level42BrickXPosArcadeMode[index-11]/2, level42BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level42BrickXPosArcadeMode[index-11]/2))-80, (level42BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level42BrickXPosArcadeMode[index-11]/2.54))-60, (level42BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level42BrickXPosArcadeMode[index-11]/2, (level42BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level42BrickXPosArcadeMode[index-11]*1.082)-200, (level42BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 43:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level43BrickXPosArcadeMode[index-11], level43BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level43BrickXPosArcadeMode[index-11]/1.8))-110, (level43BrickYPosArcadeMode[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level43BrickXPosArcadeMode[index-11]/2, level43BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level43BrickXPosArcadeMode[index-11]/2))-80, (level43BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level43BrickXPosArcadeMode[index-11]/2.54))-60, (level43BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level43BrickXPosArcadeMode[index-11]/2, (level43BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level43BrickXPosArcadeMode[index-11]*1.082)-200, (level43BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 44:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level44BrickXPosArcadeMode[index-11], level44BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level44BrickXPosArcadeMode[index-11]/1.8))-110, (level44BrickYPosArcadeMode[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level44BrickXPosArcadeMode[index-11]/2, level44BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level44BrickXPosArcadeMode[index-11]/2))-80, (level44BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level44BrickXPosArcadeMode[index-11]/2.54))-60, (level44BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level44BrickXPosArcadeMode[index-11]/2, (level44BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level44BrickXPosArcadeMode[index-11]*1.082)-200, (level44BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 45:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level45BrickXPosArcadeMode[index-11], level45BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level45BrickXPosArcadeMode[index-11]/1.8))-110, (level45BrickYPosArcadeMode[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level45BrickXPosArcadeMode[index-11]/2, level45BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level45BrickXPosArcadeMode[index-11]/2))-80, (level45BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level45BrickXPosArcadeMode[index-11]/2.54))-60, (level45BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level45BrickXPosArcadeMode[index-11]/2, (level45BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level45BrickXPosArcadeMode[index-11]*1.082)-200, (level45BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 46:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level46BrickXPosArcadeMode[index-11], level46BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level46BrickXPosArcadeMode[index-11]/1.8))-110, (level46BrickYPosArcadeMode[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level46BrickXPosArcadeMode[index-11]/2, level46BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level46BrickXPosArcadeMode[index-11]/2))-80, (level46BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level46BrickXPosArcadeMode[index-11]/2.54))-60, (level46BrickYPosArcadeMode[index-11]/2.54)-33));
                break;
            case 5:
                brickSpr->setPosition(ccp(level46BrickXPosArcadeMode[index-11]/2, (level46BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level46BrickXPosArcadeMode[index-11]*1.082)-200, (level46BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
            
        case 47:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level47BrickXPosArcadeMode[index-11], level47BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level47BrickXPosArcadeMode[index-11]/1.8))-110, (level47BrickYPosArcadeMode[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level47BrickXPosArcadeMode[index-11]/2, level47BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level47BrickXPosArcadeMode[index-11]/2))-80, (level47BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level47BrickXPosArcadeMode[index-11]/2.54))-60, (level47BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level47BrickXPosArcadeMode[index-11]/2, (level47BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level47BrickXPosArcadeMode[index-11]*1.082)-200, (level47BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
        case 48:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level48BrickXPosArcadeMode[index-11], level48BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level48BrickXPosArcadeMode[index-11]/1.8))-110, (level48BrickYPosArcadeMode[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level48BrickXPosArcadeMode[index-11]/2, level48BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level48BrickXPosArcadeMode[index-11]/2))-80, (level48BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level48BrickXPosArcadeMode[index-11]/2.54))-60, (level48BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level48BrickXPosArcadeMode[index-11]/2, (level48BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level48BrickXPosArcadeMode[index-11]*1.082)-200, (level48BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 49:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level49BrickXPosArcadeMode[index-11], level49BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level49BrickXPosArcadeMode[index-11]/1.8))-110, (level49BrickYPosArcadeMode[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level49BrickXPosArcadeMode[index-11]/2, level49BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level49BrickXPosArcadeMode[index-11]/2))-80, (level49BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level49BrickXPosArcadeMode[index-11]/2.54))-60, (level49BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level49BrickXPosArcadeMode[index-11]/2, (level49BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level49BrickXPosArcadeMode[index-11]*1.082)-200, (level49BrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
            break;
            
            
        case 50:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level50BrickXPosArcadeMode[index-11], level50BrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136)
                {
                    brickSpr->setPosition(ccp(((level50BrickXPosArcadeMode[index-11]/1.8))-110, (level50BrickYPosArcadeMode[index-11]/1.8)));
                    
                }
                else
                {
                    brickSpr->setPosition(ccp(level50BrickXPosArcadeMode[index-11]/2, level50BrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level50BrickXPosArcadeMode[index-11]/2))-80, (level50BrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level50BrickXPosArcadeMode[index-11]/2.54))-60, (level50BrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level50BrickXPosArcadeMode[index-11]/2, (level50BrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level50BrickXPosArcadeMode[index-11]*1.082)-200, (level50BrickYPosArcadeMode[index-11]*1.082)-40));
                
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


static CCSprite *halfBrickPositionOnTheScreenDisplayArcadeMode(int localLevel,CCSprite *brickSpr,int index,int deviceResolution)
{
    switch (localLevel) {
        case 1:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level1HalfBrickXPosArcadeMode[index-11], level1HalfBrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136){
                    brickSpr->setPosition(ccp(((level1HalfBrickXPosArcadeMode[index-11]/1.8))-110, (level1HalfBrickYPosArcadeMode[index-11]/1.8)));
                }
                else{
                    brickSpr->setPosition(ccp(level1HalfBrickXPosArcadeMode[index-11]/2, level1HalfBrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level1HalfBrickXPosArcadeMode[index-11]/2))-80, (level1HalfBrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level1HalfBrickXPosArcadeMode[index-11]/2.54))-60, (level1HalfBrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level1HalfBrickXPosArcadeMode[index-11]/2, (level1HalfBrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level1HalfBrickXPosArcadeMode[index-11]*1.082)-200, (level1HalfBrickYPosArcadeMode[index-11]*1.082)-40));
                
                break;
                
            default:
                break;
        }
        case 111:
            switch (deviceResolution)
        {
            case 1:
                brickSpr->setPosition(ccp(level111HalfBrickXPosArcadeMode[index-11], level111HalfBrickYPosArcadeMode[index-11]));
                
                break;
            case 2:
            {
                if (CCDirector::sharedDirector()->getWinSize().height==1136){
                    brickSpr->setPosition(ccp(((level111HalfBrickXPosArcadeMode[index-11]/1.8))-110, (level111HalfBrickYPosArcadeMode[index-11]/1.8)));
                }
                else{
                    brickSpr->setPosition(ccp(level111HalfBrickXPosArcadeMode[index-11]/2, level111HalfBrickYPosArcadeMode[index-11]/2));
                    
                }
            }
                break;
            case 3:
                brickSpr->setPosition(ccp(((level111HalfBrickXPosArcadeMode[index-11]/2))-80, (level111HalfBrickYPosArcadeMode[index-11]/2)-50));
                
                break;
            case 4:
                brickSpr->setPosition(ccp(((level111HalfBrickXPosArcadeMode[index-11]/2.54))-60, (level111HalfBrickYPosArcadeMode[index-11]/2.54)-33));
                
                break;
            case 5:
                brickSpr->setPosition(ccp(level111HalfBrickXPosArcadeMode[index-11]/2, (level111HalfBrickYPosArcadeMode[index-11]/2)+250));
                
                break;
            case 6:
                brickSpr->setPosition(ccp((level111HalfBrickXPosArcadeMode[index-11]*1.082)-200, (level111BrickYPosArcadeMode[index-11]*1.082)-40));
                
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


#endif

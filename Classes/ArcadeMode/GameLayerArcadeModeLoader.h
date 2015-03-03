//
//  GameLayerArcadeModeLoader.h
//  BreakingBricks
//
//  Created by Victor on 7/1/14.
//
//

#ifndef BreakingBricks_GameArcadeLayerLoader_h
#define BreakingBricks_GameArcadeLayerLoader_h

#include "../ArcadeMode/GameLayerArcadeMode.h"
class CCBReader;
class GameLayerArcadeModeLoader : public cocos2d::extension::CCLayerLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(GameLayerArcadeModeLoader, loader);
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(GameLayerArcadeMode);
};

#endif

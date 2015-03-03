//
//  AnimationLayerLoaderArcadeMode.h
//  BreakingBricks
//
//  Created by Victor on 7/1/14.
//
//

#ifndef BreakingBricks_AnimationLayerLoaderArcadeMode_h
#define BreakingBricks_AnimationLayerLoaderArcadeMode_h

#include "../ArcadeMode/AnimationLayerArcadeMode.h"
class CCBReader;
class AnimationLayerLoaderArcadeMode : public cocos2d::extension::CCNodeLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(AnimationLayerLoaderArcadeMode, loader);
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(AnimationLayerArcadeMode);
};

#endif

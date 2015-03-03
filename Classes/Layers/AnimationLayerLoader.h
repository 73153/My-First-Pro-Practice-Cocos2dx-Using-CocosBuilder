//
//  AnimationLayerLoader.h
//  BreakingBricks
//
//  Created by Victor on 7/1/14.
//
//

#ifndef BreakingBricks_AnimationLayerLoader_h
#define BreakingBricks_AnimationLayerLoader_h

#include "../Layers/AnimationLayer.h"
class CCBReader;
class AnimationLayerLoader : public cocos2d::extension::CCNodeLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(AnimationLayerLoader, loader);
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(AnimationLayer);
};

#endif

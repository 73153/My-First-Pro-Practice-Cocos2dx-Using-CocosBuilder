//
//  LevelSelectionLayerLoader.h
//  BreakingBricks
//
//  Created by Victor on 7/1/14.
//
//

#ifndef BreakingBricks_LevelSelectionLayerLoader_h
#define BreakingBricks_LevelSelectionLayerLoader_h

#include "../Layers/LevelSelectionLayer.h"
class CCBReader;
class LevelSelectionLayerLoader : public cocos2d::extension::CCLayerLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(LevelSelectionLayerLoader, loader);
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(LevelSelectionLayer);
};

#endif

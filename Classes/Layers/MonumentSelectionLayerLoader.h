//
//  MonumentSelectionLayerLoader.h
//  BreakingBricks
//
//  Created by Victor on 7/1/14.
//
//

#ifndef BreakingBricks_MonumentSelectionLayerLoader_h
#define BreakingBricks_MonumentSelectionLayerLoader_h

#include "../Layers/MonumentSelectionLayer.h"

class CCBReader;
class MonumentSelectionLayerLoader : public cocos2d::extension::CCLayerLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(MonumentSelectionLayerLoader, loader);
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(MonumentSelectionLayer);
};

#endif

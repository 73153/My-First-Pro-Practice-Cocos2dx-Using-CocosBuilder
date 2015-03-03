//
//  InAppPurchaseLayerLoader.h
//  BreakingBricks
//
//  Created by Victor on 7/1/14.
//
//

#ifndef BreakingBricks_InAppPurchaseLayerLoader_h
#define BreakingBricks_InAppPurchaseLayerLoader_h

#include "../Layers/InAppPurchaseLayer.h"
class CCBReader;
class InAppPurchaseLayerLoader : public cocos2d::extension::CCLayerLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(InAppPurchaseLayerLoader, loader);
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(InAppPurchaseLayer);
};

#endif

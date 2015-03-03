//
//  LeaderBoardLayerLoader.h
//  BreakingBricks
//
//  Created by Victor on 7/1/14.
//
//

#ifndef BreakingBricks_LeaderBoardLayerLoader_h
#define BreakingBricks_LeaderBoardLayerLoader_h

#include "../Layers/LeaderBoardLayer.h"
class CCBReader;
class LeaderBoardLayerLoader : public cocos2d::extension::CCLayerLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(LeaderBoardLayerLoader, loader);
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(LeaderBoardLayer);
};

#endif

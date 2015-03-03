

#ifndef __stroke__StrokeTool__
#define __stroke__StrokeTool__

#include <iostream>

#include "cocos2d.h"

class StrokeTool{
public:
    StrokeTool(){};
    virtual ~StrokeTool(){};
    
public:
    static cocos2d::CCRenderTexture* createStroke(cocos2d::CCLabelTTF *label, int size, cocos2d::ccColor3B color, GLubyte opacity);
};
#endif /* defined(__stroke__StrokeTool__) */

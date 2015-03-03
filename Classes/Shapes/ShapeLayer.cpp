

#include "../Shapes/ShapeLayer.h"
#include "../GameManager/GameManager.h"
#include "../GameManager/common_function.h"
#include "../SoundManager/SoundManager.h"
USING_NS_CC;
USING_NS_CC_EXT;
ShapeLayer::ShapeLayer():mAnimationManager(NULL)
{
   CCLog("constructor called");
}
ShapeLayer::~ShapeLayer()
{
    CCLog("destracture called");
}
void ShapeLayer::onExit()
{
    CCTextureCache::sharedTextureCache()->removeUnusedTextures();
    CCLayer::onExit();
}
void ShapeLayer::onEnter()
{
    this->setTouchEnabled(true);

    CCLayer::onEnter();
}
#pragma mark -
#pragma mark ccb methods
void ShapeLayer::onNodeLoaded(cocos2d::CCNode * pNode,  cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    ObjCCalls::hideActivityIndicator();

    CCLOG("on loaded called");
}
SEL_CallFuncN ShapeLayer::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{
    return NULL;
}
SEL_MenuHandler ShapeLayer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
  
    return NULL;
}
SEL_CCControlHandler ShapeLayer::onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}
bool ShapeLayer::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
  
    return false;
}
bool ShapeLayer::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue)
{
    bool bRet = false;
    return bRet;
}

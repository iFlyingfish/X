//
//  XPlayerMoveButton.cpp
//  X
//
//  Created by leo on 15/3/10.
//
//

#include "XPlayerMoveButton.h"
#include "XMessagePool.h"

XPlayerMoveButton* XPlayerMoveButton::create(const std::string &filename)
{
    XPlayerMoveButton* button = new (std::nothrow) XPlayerMoveButton();
    if (button && button->initWithFile(filename))
    {
        button->autorelease();
        button->registerTouchListener();
        return button;
    }
    CC_SAFE_DELETE(button);
    return nullptr;
}

XPlayerMoveButton* XPlayerMoveButton::createWithSpriteFrameName(const std::string& spriteFrameName)
{
    SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameName);
    
#if COCOS2D_DEBUG > 0
    char msg[256] = {0};
    sprintf(msg, "Invalid spriteFrameName: %s", spriteFrameName.c_str());
    CCASSERT(frame != nullptr, msg);
#endif
    
    return createWithSpriteFrame(frame);
}

XPlayerMoveButton* XPlayerMoveButton::createWithSpriteFrame(SpriteFrame* spriteFrame)
{
    XPlayerMoveButton *button = new (std::nothrow) XPlayerMoveButton();
    if (button && spriteFrame && button->initWithSpriteFrame(spriteFrame))
    {
        button->autorelease();
        button->registerTouchListener();
        return button;
    }
    CC_SAFE_DELETE(button);
    return nullptr;
}

void XPlayerMoveButton::registerTouchListener()
{
    EventDispatcher* eventDptr = getEventDispatcher();
    
    if (eventDptr) {
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        
        listener->onTouchBegan = CC_CALLBACK_2(XPlayerMoveButton::onTouchBegan, this);
        listener->onTouchMoved = CC_CALLBACK_2(XPlayerMoveButton::onTouchMoved, this);
        listener->onTouchEnded = CC_CALLBACK_2(XPlayerMoveButton::onTouchEnded, this);
        listener->onTouchCancelled = CC_CALLBACK_2(XPlayerMoveButton::onTouchCanceled, this);
    }
}

bool XPlayerMoveButton::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    auto target = static_cast<XPlayerMoveButton*>(event->getCurrentTarget());
    
    Point locationInNode = target->convertToNodeSpace(touch->getLocation());
    Size btnSize = target->getContentSize();
    
    Rect leftRect = Rect(0, 0, btnSize.width * 0.5f, btnSize.height);
    Rect rightRect = Rect(btnSize.width * 0.5f, 0, btnSize.width * 0.5f, btnSize.height);
    
    if (leftRect.containsPoint(locationInNode)) {
        XMessagePool::getInstance()->setPlayerMoveDirection(XCharacterMoveDirectionLeft);
        return true;
    }
    else if (rightRect.containsPoint(locationInNode))
    {
        XMessagePool::getInstance()->setPlayerMoveDirection(XCharacterMoveDirectionRight);
        return true;
    }
    
    return false;
}

void XPlayerMoveButton::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
{
    auto target = static_cast<XPlayerMoveButton*>(event->getCurrentTarget());
    
    Point locationInNode = target->convertToNodeSpace(touch->getLocation());
    Size btnSize = target->getContentSize();
    
    Rect leftRect = Rect(0, 0, btnSize.width * 0.5f, btnSize.height);
    Rect rightRect = Rect(btnSize.width * 0.5f, 0, btnSize.width * 0.5f, btnSize.height);
    
    if (leftRect.containsPoint(locationInNode)) {
        XMessagePool::getInstance()->setPlayerMoveDirection(XCharacterMoveDirectionLeft);
    }
    else if (rightRect.containsPoint(locationInNode))
    {
        XMessagePool::getInstance()->setPlayerMoveDirection(XCharacterMoveDirectionRight);
    }
    else
    {
        XMessagePool::getInstance()->setPlayerMoveDirection(XCharacterMoveDirectionStatic);
    }
}

void XPlayerMoveButton::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
{
    XMessagePool::getInstance()->setPlayerMoveDirection(XCharacterMoveDirectionStatic);
}

void XPlayerMoveButton::onTouchCanceled(cocos2d::Touch *touch, cocos2d::Event *event)
{
    XMessagePool::getInstance()->setPlayerMoveDirection(XCharacterMoveDirectionStatic);
}
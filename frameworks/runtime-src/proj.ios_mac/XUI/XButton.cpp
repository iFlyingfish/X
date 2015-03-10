//
//  XButton.cpp
//  X
//
//  Created by leo on 15/3/10.
//
//

#include "XButton.h"

XButton::XButton(void)
{
    eventDispatcher = Director::getInstance()->getEventDispatcher();
}

XButton::~XButton(void)
{
    eventDispatcher = nullptr;
}

// MARK: create, init

XButton* XButton::create()
{
    XButton* button = new (std::nothrow) XButton();
    if (button && button->init()) {
        button->autorelease();
        return button;
    }
    CC_SAFE_DELETE(button);
    return nullptr;
}

XButton* XButton::create(const std::string& filename)
{
    XButton *button = new (std::nothrow) XButton();
    if (button && button->initWithFile(filename))
    {
        button->autorelease();
        return button;
    }
    CC_SAFE_DELETE(button);
    return nullptr;

}

XButton* XButton::create(const std::string& filename, const Rect& rect)
{
    XButton *button = new (std::nothrow) XButton();
    if (button && button->initWithFile(filename,rect))
    {
        button->autorelease();
        return button;
    }
    CC_SAFE_DELETE(button);
    return nullptr;

}

XButton* XButton::createWithTexture(Texture2D* texture)
{
    XButton *button = new (std::nothrow) XButton();
    if (button && button->initWithTexture(texture))
    {
        button->autorelease();
        return button;
    }
    CC_SAFE_DELETE(button);
    return nullptr;
}

XButton* XButton::createWithTexture(Texture2D* texture, const Rect& rect, bool rotated)
{
    XButton *button = new (std::nothrow) XButton();
    if (button && button->initWithTexture(texture, rect, rotated))
    {
        button->autorelease();
        return button;
    }
    CC_SAFE_DELETE(button);
    return nullptr;

}
XButton* XButton::createWithSpriteFrame(SpriteFrame* spriteFrame)
{
    XButton *button = new (std::nothrow) XButton();
    if (button && spriteFrame && button->initWithSpriteFrame(spriteFrame))
    {
        button->autorelease();
        return button;
    }
    CC_SAFE_DELETE(button);
    return nullptr;
}

XButton* XButton::createWithSpriteFrameName(const std::string& spriteFrameName)
{
    SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameName);
    
#if COCOS2D_DEBUG > 0
    char msg[256] = {0};
    sprintf(msg, "Invalid spriteFrameName: %s", spriteFrameName.c_str());
    CCASSERT(frame != nullptr, msg);
#endif
    
    return createWithSpriteFrame(frame);
}

bool XButton::init(void)
{
    return Sprite::init();
}

bool XButton::initWithTexture(Texture2D* texture)
{
    return Sprite::initWithTexture(texture);
}

bool XButton::initWithTexture(Texture2D* texture, const Rect& rect)
{
    return Sprite::initWithTexture(texture, rect);
}

bool XButton::initWithSpriteFrame(SpriteFrame* pSpriteFrame)
{
    return Sprite::initWithSpriteFrame(pSpriteFrame);
}
bool XButton::intiWithSpriteFrameName(const std::string& spriteFrameName)
{
    return Sprite::initWithSpriteFrameName(spriteFrameName);
}

bool XButton::initWithFile(const std::string& filename)
{
    return Sprite::initWithFile(filename);
}

bool XButton::initWithFile(const std::string& filename, const Rect& rect)
{
    return initWithFile(filename, rect);
}

// designated initializer
bool XButton::initWithTexture(Texture2D *texture, const Rect& rect, bool rotated)
{
    return Sprite::initWithTexture(texture, rect, rotated);
}



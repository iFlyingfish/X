//
//  XPlayerSprite.cpp
//  X
//
//  Created by leo on 15/1/6.
//
//

#include "XPlayerSprite.h"

XPlayerSprite* XPlayerSprite::createWithTexture(Texture2D *texture)
{
    XPlayerSprite* playerSprite = new (std::nothrow) XPlayerSprite();
    if (playerSprite && playerSprite->initWithTexture(texture))
    {
        playerSprite->autorelease();
        return playerSprite;
    }
    CC_SAFE_DELETE(playerSprite);
    return nullptr;
}

XPlayerSprite* XPlayerSprite::createWithTexture(Texture2D* texture, const Rect& rect, bool rotated)
{
    XPlayerSprite* playerSprite = new (std::nothrow) XPlayerSprite();
    if (playerSprite && playerSprite->initWithTexture(texture, rect, rotated))
    {
        playerSprite->autorelease();
        return playerSprite;
    }
    CC_SAFE_DELETE(playerSprite);
    return nullptr;
}

XPlayerSprite* XPlayerSprite::create(const std::string &filename)
{
    XPlayerSprite* playerSprite = new (std::nothrow) XPlayerSprite();
    if (playerSprite && playerSprite->initWithFile(filename)) {
        playerSprite->autorelease();
        return  playerSprite;
    }
    CC_SAFE_DELETE(playerSprite);
    return nullptr;
}

XPlayerSprite* XPlayerSprite::create(const std::string &filename, const cocos2d::Rect &rect)
{
    XPlayerSprite* playerSprite = new (std::nothrow) XPlayerSprite();
    if (playerSprite && playerSprite->initWithFile(filename, rect))
    {
        playerSprite->autorelease();
        return playerSprite;
    }
    CC_SAFE_DELETE(playerSprite);
    return nullptr;
}

XPlayerSprite* XPlayerSprite::createWithSpriteFrame(cocos2d::SpriteFrame *spriteFrame)
{
    XPlayerSprite* playerSprite = new (std::nothrow) XPlayerSprite();
    if (playerSprite && spriteFrame && playerSprite->initWithSpriteFrame(spriteFrame))
    {
        playerSprite->autorelease();
        return playerSprite;
    }
    CC_SAFE_DELETE(playerSprite);
    return nullptr;
}

XPlayerSprite* XPlayerSprite::createWithSpriteFrameName(const std::string& spriteFrameName)
{
    SpriteFrame* frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameName);

#if COCOS2D_DEBUG > 0
    char msg[256] = {0};
    sprintf(msg, "Invalid spriteFrameName: %s", spriteFrameName.c_str());
    CCASSERT(frame != nullptr, msg);
#endif
    
    return createWithSpriteFrame(frame);
    
}

XPlayerSprite* XPlayerSprite::create()
{
    XPlayerSprite* playerSprite = new (std::nothrow) XPlayerSprite();
    if (playerSprite && playerSprite->init())
    {
        playerSprite->autorelease();
        return playerSprite;
    }
    CC_SAFE_DELETE(playerSprite);
    return nullptr;
}
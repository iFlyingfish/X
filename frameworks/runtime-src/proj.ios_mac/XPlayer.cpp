//
//  XPlayer.cpp
//  X
//
//  Created by leo on 15/1/6.
//
//

#include "XPlayer.h"

XPlayer* XPlayer::createWithTexture(Texture2D *texture)
{
    XPlayer* player = new (std::nothrow) XPlayer();
    if (player && player->initWithTexture(texture))
    {
        player->autorelease();
        return player;
    }
    CC_SAFE_DELETE(player);
    return nullptr;
}

XPlayer* XPlayer::createWithTexture(Texture2D* texture, const Rect& rect, bool rotated)
{
    XPlayer* xplayer = new (std::nothrow) XPlayer();
    if (xplayer && xplayer->initWithTexture(texture, rect, rotated))
    {
        xplayer->autorelease();
        return xplayer;
    }
    CC_SAFE_DELETE(xplayer);
    return nullptr;
}

XPlayer* XPlayer::create(const std::string &filename)
{
    XPlayer* xplayer = new (std::nothrow) XPlayer();
    if (xplayer && xplayer->initWithFile(filename)) {
        xplayer->autorelease();
        return  xplayer;
    }
    CC_SAFE_DELETE(xplayer);
    return nullptr;
}

XPlayer* XPlayer::create(const std::string &filename, const cocos2d::Rect &rect)
{
    XPlayer* xplayer = new (std::nothrow) XPlayer();
    if (xplayer && xplayer->initWithFile(filename, rect))
    {
        xplayer->autorelease();
        return xplayer;
    }
    CC_SAFE_DELETE(xplayer);
    return nullptr;
}

XPlayer* XPlayer::createWithSpriteFrame(cocos2d::SpriteFrame *spriteFrame)
{
    XPlayer* player = new (std::nothrow) XPlayer();
    if (player && spriteFrame && player->initWithSpriteFrame(spriteFrame))
    {
        player->autorelease();
        return player;
    }
    CC_SAFE_DELETE(player);
    return nullptr;
}

XPlayer* XPlayer::createWithSpriteFrameName(const std::string& spriteFrameName)
{
    SpriteFrame* frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameName);

#if COCOS2D_DEBUG > 0
    char msg[256] = {0};
    sprintf(msg, "Invalid spriteFrameName: %s", spriteFrameName.c_str());
    CCASSERT(frame != nullptr, msg);
#endif
    
    return createWithSpriteFrame(frame);
    
}

XPlayer* XPlayer::create()
{
    XPlayer* player = new (std::nothrow) XPlayer();
    if (player && player->init())
    {
        player->autorelease();
        return player;
    }
    CC_SAFE_DELETE(player);
    return nullptr;
}
//
//  XPlayerSprite.h
//  X
//
//  Created by leo on 15/1/6.
//
//

#ifndef __X__XPlayerSprite__
#define __X__XPlayerSprite__

#include <stdio.h>
#include "cocos2d.h"
#include "XCharacterSprite.h"

using namespace cocos2d;

class XPlayerSprite : public XCharacterSprite
{
public:
    
    static XPlayerSprite* create();
    static XPlayerSprite* create(const std::string& filename);
    static XPlayerSprite* create(const std::string& filename, const Rect& rect);
    static XPlayerSprite* createWithTexture(Texture2D* texture);
    static XPlayerSprite* createWithTexture(Texture2D* texture, const Rect& rect, bool rotated=false);
    static XPlayerSprite* createWithSpriteFrame(SpriteFrame* spriteFrame);
    static XPlayerSprite* createWithSpriteFrameName(const std::string& spriteFrameName);
    
};

#endif /* defined(__X__XPlayerSprite__) */

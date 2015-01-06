//
//  XPlayer.h
//  X
//
//  Created by leo on 15/1/6.
//
//

#ifndef __X__XPlayer__
#define __X__XPlayer__

#include <stdio.h>
#include "cocos2d.h"
#include "XCharacter.h"

using namespace cocos2d;

class XPlayer : public XCharacter
{
public:
    
    static XPlayer* create();
    static XPlayer* create(const std::string& filename);
    static XPlayer* create(const std::string& filename, const Rect& rect);
    static XPlayer* createWithTexture(Texture2D* texture);
    static XPlayer* createWithTexture(Texture2D* texture, const Rect& rect, bool rotated=false);
    static XPlayer* createWithSpriteFrame(SpriteFrame* spriteFrame);
    static XPlayer* createWithSpriteFrameName(const std::string& spriteFrameName);
    
};

#endif /* defined(__X__XPlayer__) */

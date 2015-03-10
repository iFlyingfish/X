//
//  XButton.h
//  X
//
//  Created by leo on 15/3/10.
//
//

#ifndef __X__XButton__
#define __X__XButton__

#include <stdio.h>
#include <cocos2d.h>

using namespace::cocos2d;

class XButton : public Sprite
{
public:
    
    static XButton* create();
    static XButton* create(const std::string& filename);
    static XButton* create(const std::string& filename, const Rect& rect);
    static XButton* createWithTexture(Texture2D* texture);
    static XButton* createWithTexture(Texture2D* texture, const Rect& rect, bool rotated=false);
    static XButton* createWithSpriteFrame(SpriteFrame* spriteFrame);
    static XButton* createWithSpriteFrameName(const std::string& spriteFrameName);
    
protected:
    
    EventDispatcher* eventDispatcher;
    
    XButton(void);
    virtual ~XButton(void);
    
    virtual bool init(void);
    virtual bool initWithTexture(Texture2D* texture);
    virtual bool initWithTexture(Texture2D* texture, const Rect& rect);
    virtual bool initWithTexture(Texture2D *texture, const Rect& rect, bool rotated);
    virtual bool initWithSpriteFrame(SpriteFrame* pSpriteFrame);
    virtual bool intiWithSpriteFrameName(const std::string& spriteFrameName);
    virtual bool initWithFile(const std::string& filename);
    virtual bool initWithFile(const std::string& filename, const Rect& rect);
    
    
};

#endif /* defined(__X__XButton__) */

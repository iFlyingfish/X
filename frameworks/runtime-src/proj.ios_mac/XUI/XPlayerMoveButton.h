//
//  XPlayerMoveButton.h
//  X
//
//  Created by leo on 15/3/10.
//
//

#ifndef __X__XPlayerMoveButton__
#define __X__XPlayerMoveButton__

#include <stdio.h>
#include "XButton.h"

class XPlayerMoveButton : public XButton
{
public:
    
    static XPlayerMoveButton* create(const std::string& filename);
    static XPlayerMoveButton* createWithSpriteFrameName(const std::string& spriteFrameName);
    static XPlayerMoveButton* createWithSpriteFrame(SpriteFrame* spriteFrame);
    
    virtual void registerTouchListener();
    
    virtual bool onTouchBegan(Touch* touch, Event* event);
    virtual void onTouchMoved(Touch* touch, Event* event);
    virtual void onTouchEnded(Touch* touch, Event* event);
    virtual void onTouchCanceled(Touch* touch, Event* event);

};

#endif /* defined(__X__XPlayerMoveButton__) */
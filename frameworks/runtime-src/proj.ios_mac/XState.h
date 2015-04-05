//
//  XState.h
//  X
//
//  Created by leo on 15/2/16.
//
//

#ifndef __X__XState__
#define __X__XState__

#include <stdio.h>
#include "cocos2d.h"
#include <vector>

class XCharacter;
class XCharcterSprite;
class XTransition;

using namespace::cocos2d;

class XState
{
public:
    typedef std::vector<XTransition*> TransitionVector;
    
    XState(const std::string& name);
    virtual ~XState();
    
    virtual void enter(XCharacter* character) = 0;
    virtual void tick(XCharacter* character, float dt) = 0;
    virtual void end(XCharacter* character) = 0;
    
    void addTransition(XTransition* transition);
    const TransitionVector& getTransitions() const;
    
    const std::string& getName() const;
    
protected:
    
    std::string mName;
    TransitionVector mTransitionVector;
    
};

#endif /* defined(__X__XState__) */

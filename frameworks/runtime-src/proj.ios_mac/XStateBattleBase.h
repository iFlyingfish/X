//
//  XStateBattleBase.h
//  X
//
//  Created by Leo on 15/3/3.
//
//

#ifndef __X__XStateBattleBase__
#define __X__XStateBattleBase__

#include <stdio.h>
#include "XState.h"

class XStateBattleBase : public XState
{
public:
    XStateBattleBase(const std::string& name);
    
    virtual void enter(XCharacter* character) = 0;
    virtual void tick(XCharacter* character, float dt) = 0;
    virtual void end(XCharacter* character) = 0;
};

#endif /* defined(__X__XStateBattleBase__) */

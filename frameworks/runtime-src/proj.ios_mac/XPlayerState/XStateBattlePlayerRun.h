//
//  XStateBattlePlayerRun.h
//  X
//
//  Created by Leo on 15/3/3.
//
//

#ifndef __X__XStateBattlePlayerRun__
#define __X__XStateBattlePlayerRun__

#include <stdio.h>
#include "XStateBattleBase.h"

class XStateBattlePlayerRun : public XStateBattleBase
{
public:
    XStateBattlePlayerRun(const std::string& name);
    
    virtual void enter(XCharacter* character);
    virtual void tick(XCharacter* character);
    virtual void exit(XCharacter* character);
};

#endif /* defined(__X__XStateBattlePlayerRun__) */

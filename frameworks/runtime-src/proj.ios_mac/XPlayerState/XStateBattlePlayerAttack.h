//
//  XStateBattlePlayerAttack.h
//  X
//
//  Created by Leo on 15/3/3.
//
//

#ifndef __X__XStateBattlePlayerAttack__
#define __X__XStateBattlePlayerAttack__

#include <stdio.h>
#include "XStateBattleBase.h"

class XStateBattlePlayerAttack : public XStateBattleBase
{
public:
    XStateBattlePlayerAttack(const std::string& name);
    
    virtual void enter(XCharacter* character);
    virtual void tick(XCharacter* character);
    virtual void exit(XCharacter* character);
};

#endif /* defined(__X__XStateBattlePlayerAttack__) */

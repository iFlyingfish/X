//
//  XStateBattleHeroIdle.h
//  X
//
//  Created by Leo on 15/4/5.
//
//

#ifndef __X__XStateBattleHeroIdle__
#define __X__XStateBattleHeroIdle__

#include <stdio.h>
#include "XStateBattleBase.h"
//#include "base/CCEventListener.h"

class XStateBattleHeroIdle : public XStateBattleBase
{
public:
    
    XStateBattleHeroIdle(const std::string& name);
    
    virtual void enter(XCharacter* character);
    virtual void tick(XCharacter* character, float dt);
    virtual void end(XCharacter* character);

private:
    
    
};

#endif /* defined(__X__XStateBattleHeroIdle__) */

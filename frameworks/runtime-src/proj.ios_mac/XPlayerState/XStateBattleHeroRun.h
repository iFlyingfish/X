//
//  XStateBattleHeroRun.h
//  X
//
//  Created by Leo on 15/4/5.
//
//

#ifndef __X__XStateBattleHeroRun__
#define __X__XStateBattleHeroRun__

#include <stdio.h>
#include "XStateBattleBase.h"


class XStateBattleHeroRun : public XStateBattleBase
{
public:
    
    XStateBattleHeroRun(const std::string& name);
    
    virtual void enter(XCharacter* character);
    virtual void tick(XCharacter* character, float dt);
    virtual void end(XCharacter* character);

private:
    
    
};

#endif /* defined(__X__XStateBattleHeroRun__) */

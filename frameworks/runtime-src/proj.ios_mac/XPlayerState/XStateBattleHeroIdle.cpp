//
//  XStateBattleHeroIdle.cpp
//  X
//
//  Created by Leo on 15/4/5.
//
//

#include "XStateBattleHeroIdle.h"
#include "XPlayer.h"
#include "XMessage.h"

XStateBattleHeroIdle::XStateBattleHeroIdle(const std::string& name)
: XStateBattleBase(name)
{
    
}

void XStateBattleHeroIdle::enter(XCharacter * character)
{
    character->stop();
}

void XStateBattleHeroIdle::tick(XCharacter *character, float dt)
{
    
}

void XStateBattleHeroIdle::end(XCharacter *character)
{
    
}

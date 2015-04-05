//
//  XStateBattleHeroRun.cpp
//  X
//
//  Created by Leo on 15/4/5.
//
//

#include "XStateBattleHeroRun.h"
#include "XPlayer.h"
#include "XMessage.h"

XStateBattleHeroRun::XStateBattleHeroRun(const std::string& name)
: XStateBattleBase(name)
{
    
}

void XStateBattleHeroRun::enter(XCharacter *character)
{
    character->run(character->getRunDirection());
}

void XStateBattleHeroRun::tick(XCharacter *character, float dt)
{
    ((XPlayer*)character)->updatePos(dt);
}

void XStateBattleHeroRun::end(XCharacter *character)
{

}
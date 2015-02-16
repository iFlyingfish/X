//
//  XCharacter.cpp
//  X
//
//  Created by leo on 15/2/16.
//
//

#include "XCharacter.h"
#include "XCharacterSprite.h"
#include "XStateMachine.h"

XCharacter::XCharacter(XCharcterSprite* characterSprite,int HP)
:mCharcterSprite(characterSprite)
,mHP(HP)
{
   
}

XCharacter::~XCharacter()
{
    XStateMachineListItr it = mStateMachineList.begin();
    while (it != mStateMachineList.end()) {
        ++it;
    }
}


bool XCharacter::init()
{
    return true;
}

void XCharacter::tick()
{
    XStateMachineListItr it = mStateMachineList.begin();
    while (it != mStateMachineList.end()) {
       // (*it)->tick();
        ++it;
    }
}

XCharcterSprite* XCharacter::getCharacterSprtie()
{
    return mCharcterSprite;
}

void XCharacter::setHP(int HP)
{
    mHP = HP;
}

int XCharacter::getHP() const
{
    return mHP;
}
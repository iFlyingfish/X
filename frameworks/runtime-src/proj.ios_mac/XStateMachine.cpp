//
//  XStateMachine.cpp
//  X
//
//  Created by leo on 15/2/16.
//
//

#include "XStateMachine.h"
#include "XState.h"

XStateMachine::XStateMachine(const Value& name, XCharacter* characterRef)
: mActiveState(nullptr)
, mCharacterRef(characterRef)
{
    
}

XStateMachine::~XStateMachine()
{
    XStateMapItr it = mStateMap.begin();
    while (it != mStateMap.end()) {
        ++it;
    }
    mStateMap.clear();
}


void XStateMachine::enter(XCharacter* chartacter)
{
    
}

void XStateMachine::tick(XCharacter* chartacter)
{
    
}

void XStateMachine::exit(XCharacter* chartacter)
{
    
}
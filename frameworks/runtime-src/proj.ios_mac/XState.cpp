//
//  XState.cpp
//  X
//
//  Created by leo on 15/2/16.
//
//

#include "XState.h"
#include "XCharacter.h"

XState::XState(const std::string& name)
: mName(name)
{
    
}

XState::~XState()
{
    
}

const std::string& XState::getName() const
{
    return mName;
}


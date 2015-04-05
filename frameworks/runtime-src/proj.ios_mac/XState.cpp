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

void XState::addTransition(XTransition* transition)
{
    for (auto transRecord : mTransitionVector) {
        if (transition == transRecord) {
            return;
        }
    }
    mTransitionVector.push_back(transition);
}

const XState::TransitionVector& XState::getTransitions() const
{
    return mTransitionVector;
}


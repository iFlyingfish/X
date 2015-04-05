//
//  XStateMachine.cpp
//  X
//
//  Created by leo on 15/2/16.
//
//

#include "XStateMachine.h"
#include "XState.h"
#include "XTransition.h"

XStateMachine::XStateMachine(const std::string& name, XCharacter* characterRef)
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

bool XStateMachine::addState(XState *state, bool isRootState)
{
    const std::string stateName = state->getName();
    if (mStateMap.find(stateName) != mStateMap.end()) {
        return false;
    }
    
    mStateMap.insert(XStateMap::value_type(stateName,state));
    if (isRootState) {
        mRootState = state;
    }
    
    return true;
}

void XStateMachine::enter(XCharacter* chartacter)
{
    mActiveState = mRootState;
    mActiveState->enter(chartacter);
    
}

void XStateMachine::tick(XCharacter* chartacter, float dt)
{
    updateActiveState(dt);
    
    evaluateTransitions();
}

void XStateMachine::exit(XCharacter* chartacter)
{
    
}

void XStateMachine::updateActiveState(float dt)
{
    if (mActiveState) {
        mActiveState->tick(mCharacterRef, dt);
    }
}

void XStateMachine::evaluateTransitions()
{
    if (mActiveState) {
        XState::TransitionVector transitions = mActiveState->getTransitions();
        
        for (auto transition : transitions) {
            
            XStateMapItr itr;
            
            if (transition && transition->isMeetCondition(mCharacterRef)) {
                const std::string nextStateName = transition->GetYesNextStateName();
                itr = mStateMap.find(nextStateName);
            }
            else
            {
                const std::string nextStateName = transition->GetNoNextStateName();
                itr = mStateMap.find(nextStateName);
            }
            
            if (itr != mStateMap.end()) {
                mActiveState->end(mCharacterRef);
                mPreState = mActiveState;
                
                mActiveState = itr->second;
                mActiveState->enter(mCharacterRef);
                
                break;
            }
        }
    }
}
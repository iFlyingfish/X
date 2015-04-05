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
#include "XState.h"
#include "XTransition.h"

XCharacter::XCharacter(XCharcterSprite* characterSprite,int HP)
:mCharcterSprite(characterSprite)
,mBattleHP(HP)
,mReceivedMessageList(new XMessageList())
,mStateMachineList(XStateMachineList(0))
{
   
}

XCharacter::~XCharacter()
{
    XStateMachineListItr it = mStateMachineList.begin();
    while (it != mStateMachineList.end()) {
        ++it;
    }
}

void XCharacter::sLinkState(XState *firstState, XTransition *transition, XState *secondYesState, XState *secondNoState)
{
    firstState->addTransition(transition);
    
    if (secondYesState) {
        transition->SetYesStateName(secondYesState->getName());
    }
    
    if (secondNoState) {
        transition->SetNoStateName(secondNoState->getName());
    }
}


bool XCharacter::init()
{
    return true;
}

void XCharacter::tick(float dt)
{
    XStateMachineListItr it = mStateMachineList.begin();
    while (it != mStateMachineList.end()) {
        (*it)->tick(this, dt);
        ++it;
    }
    
    if (mReceivedMessageList) {
        mReceivedMessageList->clear();
    }
}

void XCharacter::firstEnter()
{
    for (auto stateMachine : mStateMachineList ) {
        stateMachine->enter(this);
    }
}

XCharcterSprite* XCharacter::getCharacterSprtie()
{
    return mCharcterSprite;
}

void XCharacter::setHP(int HP)
{
    mBattleHP = HP;
}

int XCharacter::getHP() const
{
    return mBattleHP;
}

void XCharacter::receiveMessage(const XMessage &message)
{
    mReceivedMessageList->push_back(message);
}

void XCharacter::cleanupMessage(const XMessage &message)
{
    XMessageListLtr itr = mReceivedMessageList->begin();
    
    while (itr != mReceivedMessageList->end()) {
        if (itr->mMessageType == message.mMessageType) {
            break;
        }
        ++itr;
    }
    
    mReceivedMessageList->erase(itr);
}

bool XCharacter::isReceivedMessage(const XMessage &message) const
{
    if (mReceivedMessageList) {
        XMessageListLtr itr = mReceivedMessageList->begin();
        
        while (itr != mReceivedMessageList->end()) {
            if (itr->mMessageType == message.mMessageType) {
                return true;
            }
            ++itr;
        }

    }
    
    return false;

}
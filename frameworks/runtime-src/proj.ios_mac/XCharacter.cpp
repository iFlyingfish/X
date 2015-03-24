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
    XMessageListLtr itr = mReceivedMessageList->begin();
    
    while (itr != mReceivedMessageList->end()) {
        if (itr->mMessageType == message.mMessageType) {
            return true;
        }
        ++itr;
    }
    
    return false;

}
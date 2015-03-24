//
//  XTransitionMessage.cpp
//  X
//
//  Created by Leo on 15/3/25.
//
//

#include "XTransitionMessage.h"
#include "XCharacter.h"

XTransitionMessage::XTransitionMessage(XMessageType messageType)
:mMessageType(mMessageType)
{
    
}

XTransitionMessage::~XTransitionMessage()
{
    
}

bool XTransitionMessage::isMeetCondition(XCharacter *character)
{
    if (character == nullptr) {
        return false;
    }
    
    XMessage message = XMessage(mMessageType);
    if (character->isReceivedMessage(message)) {
        character->cleanupMessage(message);
        
        return true;
    }
    
    return false;
}
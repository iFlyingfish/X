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
:mMessageType(messageType)
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
        
        switch (mMessageType) {
            case XMessageType::XMessageTypeCharacterMoveLeft:
                character->setRunDirection(XDirection::XDirectionLeft);
                break;
            case XMessageType::XMessageTypeCharacterMoveRight:
                character->setRunDirection(XDirection::XDirectionRight);
                break;
            case XMessageType::XMessageTypeCharacterStop:
                character->setRunDirection(XDirection::XDirectionDefault);
            default:
                break;
        }
        
        character->cleanupMessage(message);
        
        return true;
    }
    
    return false;
}
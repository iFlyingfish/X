//
//  XMessage.h
//  X
//
//  Created by Leo on 15/3/25.
//
//

#ifndef X_XMessage_h
#define X_XMessage_h

#include <list>

typedef enum
{
    XMessageTypeDefault = 0,
    XMessageTypeCharacterAttack,
    XMessageTypeCharacterMoveLeft,
    XMessageTypeCharacterMoveRight
} XMessageType;

typedef struct XMessage
{
public:
    XMessage(XMessageType messageType)
    :mMessageType(mMessageType)
    {
    
    }
    XMessageType mMessageType;
}XMessage;

typedef std::list<XMessage> XMessageList;
typedef std::list<XMessage>::iterator XMessageListLtr;

#endif

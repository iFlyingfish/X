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

#define XHeroRunLeft "hero_run_left"
#define XHeroRunRight "hero_run_right"
#define XHeroRunStop "hero_run_stop"

enum class XMessageType
{
    XMessageTypeDefault = 0,
    XMessageTypeCharacterAttack,
    XMessageTypeCharacterMoveLeft,
    XMessageTypeCharacterMoveRight,
    XMessageTypeCharacterStop
};

typedef struct XMessage
{
public:
    XMessage(XMessageType messageType)
    :mMessageType(messageType)
    {
    
    }
    XMessageType mMessageType;
}XMessage;

typedef std::list<XMessage> XMessageList;
typedef std::list<XMessage>::iterator XMessageListLtr;

#endif

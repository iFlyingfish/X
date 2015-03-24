//
//  XTransitionMessage.h
//  X
//
//  Created by Leo on 15/3/25.
//
//

#ifndef __X__XTransitionMessage__
#define __X__XTransitionMessage__

#include <stdio.h>
#include "XTransition.h"
#include "XMessage.h"

class XTransitionMessage : public XTransition
{
public:
    
    XTransitionMessage(XMessageType messageType);
    virtual ~XTransitionMessage();
    
    virtual bool isMeetCondition(XCharacter* character);
    
private:
    XMessageType mMessageType;
};

#endif /* defined(__X__XTransitionMessage__) */

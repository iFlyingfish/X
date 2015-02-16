//
//  XStateMachine.h
//  X
//
//  Created by leo on 15/2/16.
//
//

#ifndef __X__XStateMachine__
#define __X__XStateMachine__

#include <stdio.h>
#include <map>

class XCharacter;
class XState;

#include "cocos2d.h"

using namespace cocos2d;

class XStateMachine
{
public:
    typedef std::map<std::string,XState*> XStateMap;
    typedef XStateMap::iterator    XStateMapItr;
    
    XStateMachine(const Value& name, XCharacter* characterRef);
    virtual ~XStateMachine();
    
    virtual void enter(XCharacter* chartacter);
    virtual void tick(XCharacter* chartacter);
    virtual void exit(XCharacter* chartacter);

private:
    XStateMap mStateMap;
  
    XState* mActiveState;
    
    XCharacter* mCharacterRef;
};

#endif /* defined(__X__XStateMachine__) */



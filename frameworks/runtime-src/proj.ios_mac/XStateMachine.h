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
    
    XStateMachine(const std::string& name, XCharacter* characterRef);
    virtual ~XStateMachine();
    
    bool addState(XState* state, bool isRootState = false);
    void enter(XCharacter* chartacter);
    void tick(XCharacter* chartacter, float dt);
    void exit(XCharacter* chartacter);
    
    void updateActiveState(float dt);
    void evaluateTransitions();
    
private:
    
    XStateMap mStateMap;
    XState* mRootState;
    XState* mActiveState;
    XState* mPreState;
    
    XCharacter* mCharacterRef;
};

#endif /* defined(__X__XStateMachine__) */



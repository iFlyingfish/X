//
//  XCharacter.h
//  X
//
//  Created by leo on 15/2/16.
//
//

#ifndef __X__XCharacter__
#define __X__XCharacter__

#include <stdio.h>
#include <list>
#include <XMessage.h>
#include "cocostudio/CCArmature.h"

class XCharcterSprite;
class XStateMachine;
class XState;
class XTransition;

using namespace cocostudio;

enum class XDirection
{
    XDirectionDefault = 0,
    XDirectionLeft,
    XDirectionRight
};

class XCharacter
{
public:
    
    typedef std::list<XStateMachine*> XStateMachineList;
    typedef XStateMachineList::iterator XStateMachineListItr;
    
    XCharacter(XCharcterSprite* characterSprite,int HP);
    virtual ~XCharacter();
    
    static void sLinkState(XState* firstState, XTransition* transition, XState* secondYesState, XState* secondNoState);
    
    virtual void setupStateMachine() = 0;
    virtual bool init();
    virtual void tick(float dt);
    
    void firstEnter();
    
    virtual void run(const XDirection& direction) = 0;
    virtual void stop() = 0;
    virtual void setRunDirection(const XDirection& runDirection) = 0;
    virtual const XDirection& getRunDirection() const = 0;
    XCharcterSprite* getCharacterSprtie();
    
    virtual Armature* getArmaturePlayer() const = 0;
    void setHP(int HP);
    int getHP() const;
    
    void receiveMessage(const XMessage& message);
    void cleanupMessage(const XMessage& message);
    bool isReceivedMessage(const XMessage& message) const;
    
protected:

    XStateMachineList mStateMachineList;
    
    XCharcterSprite* mCharcterSprite;
    
    
    XMessageList* mReceivedMessageList;
    
    int mBattleHP;
};

#endif /* defined(__X__XCharacter__) */

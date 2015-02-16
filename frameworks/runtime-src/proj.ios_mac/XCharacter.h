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

class XCharcterSprite;
class XStateMachine;

class XCharacter
{
public:
    
    typedef std::list<XStateMachine*> XStateMachineList;
    typedef XStateMachineList::iterator XStateMachineListItr;
    
    XCharacter(XCharcterSprite* characterSprite,int HP);
    virtual ~XCharacter();
    
    virtual void setupStateMachine() = 0;
    virtual bool init();
    virtual void tick();
    
    XCharcterSprite* getCharacterSprtie();
    void setHP(int HP);
    int getHP();
    
protected:

    XStateMachineList mStateMachineList;
    
    XCharcterSprite* mCharcterSprite;
    
    int mHP;
};

#endif /* defined(__X__XCharacter__) */

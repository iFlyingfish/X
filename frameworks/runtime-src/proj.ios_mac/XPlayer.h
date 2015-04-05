//
//  XPlayer.h
//  X
//
//  Created by leo on 15/1/19.
//
//

#ifndef __X__XPlayer__
#define __X__XPlayer__

#include "cocos2d.h"
#include <stdio.h>
#include "XCharacter.h"

class XPlayerSprite;

using namespace cocostudio;
using namespace cocos2d;

class XPlayer : public XCharacter
{
public:
    
    XPlayer(XCharcterSprite* sprite, int battleHP);
    virtual ~XPlayer();
    
    virtual void setupStateMachine();
    virtual bool init();
    virtual void run(const XDirection& direction);
    virtual void stop();
    virtual void updatePos(float dt);
    virtual bool checkPlayerInScreen(const Point& pos) const;
    void setRunDirection(const XDirection& runDirection);
    const XDirection& getRunDirection() const;
    
    Armature* getArmaturePlayer() const;
    
    Armature* mArmaturePlayer;
    
    
private:
    int mbattleHP;
    XDirection mRunDirection;
    
    EventListener* mRunLeftListener;
    EventListener* mRunRightListener;
    EventListener* mStopListener;
};

#endif /* defined(__X__XPlayer__) */

//
//  XPlayer.h
//  X
//
//  Created by leo on 15/1/19.
//
//

#ifndef __X__XPlayer__
#define __X__XPlayer__

#include <stdio.h>

class XHallInfo;
class XBattleInfo;
class XPlayerSprite;

typedef enum
{
    stateHall = 0,       //大厅状态
    stateBattle = 1,     //战斗状态
    
}State;

class XPlayer
{
public:
    XPlayer(int battleHP);
    virtual ~XPlayer();
private:
    State mState;
    XHallInfo* mHallInfo;
    XBattleInfo* mBattleInfo;
    XPlayerSprite* mPlayerSprite;
    
};

#endif /* defined(__X__XPlayer__) */

//
//  XBattleInfo.h
//  X
//
//  Created by leo on 15/1/19.
//
//

#ifndef __X__XBattleInfo__
#define __X__XBattleInfo__

#include <stdio.h>

typedef enum
{
    battleStateIdle = 0,
    battleStateAttack,
    battleStateDefend,
    battleStateHurt,
    battleStateFailed,
    battleStateWin
    
}BattleState;

class XBattleInfo
{
public:
    XBattleInfo(int HP);
private:
    int mHP;
    BattleState mState;
};


#endif /* defined(__X__XBattleInfo__) */



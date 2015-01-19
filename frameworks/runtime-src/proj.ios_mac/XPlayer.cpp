//
//  XPlayer.cpp
//  X
//
//  Created by leo on 15/1/19.
//
//

#include "XPlayer.h"
#include "XBattleInfo.h"
#include "XHallInfo.h"

XPlayer::XPlayer(int battleHP)
:mState(stateHall),
mBattleInfo(new XBattleInfo(battleHP)),
mHallInfo(new XHallInfo())
{

}

XPlayer::~XPlayer()
{
    delete mBattleInfo;
    delete mHallInfo;
}
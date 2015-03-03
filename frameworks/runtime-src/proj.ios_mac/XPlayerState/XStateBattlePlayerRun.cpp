//
//  XStateBattlePlayerRun.cpp
//  X
//
//  Created by Leo on 15/3/3.
//
//

#include "XStateBattlePlayerRun.h"

XStateBattlePlayerRun::XStateBattlePlayerRun(const std::string& name)
: XStateBattleBase(name)
{
    
}

void XStateBattlePlayerRun::enter(XCharacter *character)
{
    if (character == nullptr) {
        return;
    }
    //开始监测JoyStick操控方向
}

void XStateBattlePlayerRun::tick(XCharacter* character)
{
    if (character == nullptr) {
        return;
    }
    
    //监测JoyStick操控方向，设置角色跑动方向速度
}

void XStateBattlePlayerRun::exit(XCharacter* character)
{
    if (character == nullptr) {
        return;
    }
    //结束监测JoyStick操控方向
}


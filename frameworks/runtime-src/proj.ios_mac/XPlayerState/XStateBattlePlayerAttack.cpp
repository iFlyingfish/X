//
//  XStateBattlePlayerAttack.cpp
//  X
//
//  Created by Leo on 15/3/3.
//
//

#include "XStateBattlePlayerAttack.h"

XStateBattlePlayerAttack::XStateBattlePlayerAttack(const std::string& name)
: XStateBattleBase(name)
{
    
}

void XStateBattlePlayerAttack::enter(XCharacter* character)
{
    if (character == nullptr) {
        return;
    }
    
    //播放攻击动画
    
}

void XStateBattlePlayerAttack::tick(XCharacter *character)
{
    if (character == nullptr) {
        
        //判断攻击动画是否播完，进入发射阶段和碰撞检测阶段
    }
}

void XStateBattlePlayerAttack::exit(XCharacter *character)
{
    if (character == nullptr) {
        
        //如果被打断或者发射完毕，结素攻击状态
    }
}
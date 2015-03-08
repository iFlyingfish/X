//
//  UIBattleLayer.h
//  X
//
//  Created by Leo on 15/3/8.
//
//

#ifndef __X__UIBattleLayer__
#define __X__UIBattleLayer__

#include <stdio.h>
#include "cocos2d.h"
class Joystick;

using namespace cocos2d;

class UIBattleLayer : public Layer
{
public:
    
    virtual bool init();
    
    CREATE_FUNC(UIBattleLayer);

private:
    
    Menu* playerACtionBtnMenu;
    Joystick* playerMoveStick;
};

#endif /* defined(__X__UIBattleLayer__) */

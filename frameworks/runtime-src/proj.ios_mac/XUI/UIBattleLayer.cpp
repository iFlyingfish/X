//
//  UIBattleLayer.cpp
//  X
//
//  Created by Leo on 15/3/8.
//
//

#include "UIBattleLayer.h"
#include "Joystick.h"

bool UIBattleLayer::init()
{
    
    if(Layer::init())
    {
        playerACtionBtnMenu = Menu::create();
        this->addChild(playerACtionBtnMenu);
        playerACtionBtnMenu->setPosition(Point::ZERO);
        
        playerMoveStick = Joystick::create();
        this->addChild(playerMoveStick);
        playerMoveStick->setPosition(Point::ZERO);
    }
    
    return false;
}
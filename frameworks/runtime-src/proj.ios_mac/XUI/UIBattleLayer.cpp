//
//  UIBattleLayer.cpp
//  X
//
//  Created by Leo on 15/3/8.
//
//

#include "UIBattleLayer.h"
//#include "Joystick.h"
#include "XPlayerMoveButton.h"

bool UIBattleLayer::init()
{
    
    if(Layer::init())
    {
        SpriteFrameCache::getInstance()->addSpriteFramesWithFile("UI_Battle_Public.plist");
        
        
        playerACtionBtnMenu = Menu::create();
        this->addChild(playerACtionBtnMenu);
        playerACtionBtnMenu->setPosition(Point::ZERO);
        
//        playerMoveStick = Joystick::create();
//        this->addChild(playerMoveStick);
//        playerMoveStick->setPosition(Point::ZERO);
        
        playerMoveBtn = XPlayerMoveButton::createWithSpriteFrameName("UI_Battle_Public_56.png");
        playerMoveBtn->setPosition(Point(500,50));
        this->addChild(playerMoveBtn);
        
        return true;
    }
    
    return false;
}
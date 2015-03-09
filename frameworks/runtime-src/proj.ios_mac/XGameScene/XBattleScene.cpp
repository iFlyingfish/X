//
//  XBattleScene.cpp
//  X
//
//  Created by Leo on 15/3/8.
//
//

#include "XBattleScene.h"
#include "UIBattleLayer.h"

Scene* XBattleScene::createScene()
{
    auto scene = Scene::create();
    
    auto layer = XBattleScene::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool XBattleScene::init()
{
    if (Layer::init()) {
        uiBattleLayer = UIBattleLayer::create();
        uiBattleLayer->setPosition(Point::ZERO);
        this->addChild(uiBattleLayer);
        
        return true;
    }
    
    return false;
}
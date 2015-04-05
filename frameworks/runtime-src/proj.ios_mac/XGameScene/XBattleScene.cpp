//
//  XBattleScene.cpp
//  X
//
//  Created by Leo on 15/3/8.
//
//

#define TEMP_PLAYER_SPEED 500

#include "XBattleScene.h"
#include "UIBattleLayer.h"
#include "XPlayer.h"

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
        
        LayerColor* bgColorLayer = LayerColor::create(Color4B(255, 255, 255, 255));
        this->addChild(bgColorLayer);
        
//        ArmatureDataManager::getInstance()->addArmatureFileInfo("TongBase0.png","TongBase0.plist","TongBase.ExportJson");
//        armaturePlayer = Armature::create("TongBase");
//        armaturePlayer->retain();
//        
        Size visableSize = Director::getInstance()->getVisibleSize();
//
//        armaturePlayer->setPosition(Point(visableSize.width * 0.5f, visableSize.height * 0.5f));
//        this->addChild(armaturePlayer);
//        
//        lastDirec = XCharacterMoveDirectionStatic;
//        
//        scheduleUpdate();
        
        mHero = new XPlayer(nullptr,100);
        if (mHero->init()) {
            
            Armature* armaturePlayer = mHero->getArmaturePlayer();
            armaturePlayer->setPosition(Point(visableSize.width * 0.5f, visableSize.height * 0.5f));
            addChild(armaturePlayer);
            
            mHero->setupStateMachine();
            mHero->firstEnter();
            
            uiBattleLayer = UIBattleLayer::create();
            uiBattleLayer->setPosition(Point::ZERO);
            this->addChild(uiBattleLayer);
            
            schedule(schedule_selector(XBattleScene::tick));
            
        }
        
        
        return true;
    }
    
    return false;
}

void XBattleScene::tick(float dt)
{
    if (mHero) {
        mHero->tick(dt);
    }
  
}

void XBattleScene::update(float dt)
{
    XCharacterMoveDirection curMoveDirec = XMessagePool::getInstance()->getPlayerMoveDirection();
    
    if(curMoveDirec != XCharacterMoveDirectionStatic)
    {
        float direc = 1.0f;
        if (curMoveDirec == XCharacterMoveDirectionLeft) {
            armaturePlayer->setScale(-1.0f, 1.0f);
            direc = -1.0f;
            
        }
        else
        {
            armaturePlayer->setScale(1.0f, 1.0f);
        }
        
        Point destPos = Point(armaturePlayer->getPosition().x + TEMP_PLAYER_SPEED * dt * direc,armaturePlayer->getPosition().y);
        if (checkPlayerInScreen(destPos)) {
            armaturePlayer->setPosition(destPos);
        }
    }

    
    if (lastDirec == XCharacterMoveDirectionStatic && curMoveDirec != lastDirec) {
        
        armaturePlayer->getAnimation()->play("Run");
    }
    else if(curMoveDirec == XCharacterMoveDirectionStatic && lastDirec != curMoveDirec)
    {
        armaturePlayer->getAnimation()->stop();
    }
    
    lastDirec = curMoveDirec;
}

bool XBattleScene::checkPlayerInScreen(Point playerPos)
{
    Size visableSize = Director::getInstance()->getVisibleSize();
    
    if ((playerPos.x + armaturePlayer->getContentSize().width * 0.5f < visableSize.width)
        && (playerPos.x - armaturePlayer->getContentSize().width * 0.5f > 0)) {
        return true;
    }
    
    return false;
}

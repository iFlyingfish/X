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
#include "XStateMachine.h"
#include "XStateBattleHeroIdle.h"
#include "XStateBattleHeroRun.h"
#include "XTransitionMessage.h"

namespace  {
    const int X_PLAYER_SEED = 300;
}



XPlayer::XPlayer(XCharcterSprite* sprite, int battleHP)
:XCharacter(sprite, battleHP)
,mRunDirection(XDirection::XDirectionDefault)
{
    EventDispatcher* eventDispatcher = Director::getInstance()->getEventDispatcher();
    
    mRunLeftListener = EventListenerCustom::create(XHeroRunLeft, [=](EventCustom* event){
        
        //        if (this  == static_cast<XPlayer*>(event->getUserData())) {
        
        receiveMessage(XMessage(XMessageType::XMessageTypeCharacterMoveLeft));
        //        run(XDirection::XDirectionLeft);
        //        }
        
    });
    
    eventDispatcher->addEventListenerWithFixedPriority(mRunLeftListener, 1);
    
    mRunRightListener= EventListenerCustom::create(XHeroRunRight, [=](EventCustom* event){
        
        //         if (this == static_cast<XPlayer*>(event->getUserData())) {
        receiveMessage(XMessage(XMessageType::XMessageTypeCharacterMoveRight));
        //        this->run(XDirection::XDirectionRight);
        //         }
    });
    eventDispatcher->addEventListenerWithFixedPriority(mRunRightListener, 1);
    
    
    mStopListener = EventListenerCustom::create(XHeroRunStop, [=](EventCustom* event){
        
        //        if (character == static_cast<XPlayer*>(event->getUserData())) {
        receiveMessage(XMessage(XMessageType::XMessageTypeCharacterStop));
        //        character->stop();
        //        }
    });
    eventDispatcher->addEventListenerWithFixedPriority(mStopListener, 1);

}

XPlayer::~XPlayer()
{
    EventDispatcher* eventDispatcher = Director::getInstance()->getEventDispatcher();
    if (eventDispatcher) {
        if (mRunLeftListener) {
            eventDispatcher->removeEventListener(mRunLeftListener);
            mRunLeftListener = nullptr;
        }
        if (mRunRightListener) {
            eventDispatcher->removeEventListener(mRunRightListener);
            mRunRightListener = nullptr;
        }
        
        if (mStopListener) {
            eventDispatcher->removeEventListener(mStopListener);
            mStopListener = nullptr;

        }
    }
}

bool XPlayer::init()
{
    
    ArmatureDataManager::getInstance()->addArmatureFileInfo("TongBase0.png","TongBase0.plist","TongBase.ExportJson");
    mArmaturePlayer = Armature::create("TongBase");
    mArmaturePlayer->retain();
    
    if (mArmaturePlayer) {
        return true;
    }
    
    return false;

}

Armature* XPlayer::getArmaturePlayer() const
{
    return mArmaturePlayer;
}

void XPlayer::setupStateMachine()
{
    XStateMachine* stateMachine_Hero = new XStateMachine("stateMachine_Hero",this);
    XState* stateMachine_hero_state_0 = new XStateBattleHeroIdle("stateMachine_hero_state_0");
    stateMachine_Hero->addState(stateMachine_hero_state_0,true);
    XState* stateMachine_hero_state_1 = new XStateBattleHeroRun("stateMachine_hero_state_1");
    stateMachine_Hero->addState(stateMachine_hero_state_1);
    
    XTransition* transition_0_1 = new XTransitionMessage(XMessageType::XMessageTypeCharacterMoveLeft);
    XTransition* transition_0_2 = new XTransitionMessage(XMessageType::XMessageTypeCharacterMoveRight);
    XTransition* transition_1_0 = new XTransitionMessage(XMessageType::XMessageTypeCharacterStop);
    
    sLinkState(stateMachine_hero_state_0, transition_0_1, stateMachine_hero_state_1, nullptr);
    sLinkState(stateMachine_hero_state_0, transition_0_2, stateMachine_hero_state_1, nullptr);
    sLinkState(stateMachine_hero_state_1, transition_1_0, stateMachine_hero_state_0, nullptr);
    
    sLinkState(stateMachine_hero_state_1, transition_0_1, stateMachine_hero_state_1, nullptr);
    sLinkState(stateMachine_hero_state_1, transition_0_2, stateMachine_hero_state_1, nullptr);

    
    mStateMachineList.push_back(stateMachine_Hero);
    
}

void XPlayer::setRunDirection(const XDirection &runDirection)
{
    mRunDirection = runDirection;
}

const XDirection& XPlayer::getRunDirection() const
{
    return mRunDirection;
}

void XPlayer::run(const XDirection& direction)
{
    if (mArmaturePlayer) {
        mArmaturePlayer->getAnimation()->stop();
        if (direction == XDirection::XDirectionLeft) {
            mArmaturePlayer->setScaleX(-1.0f);
            mRunDirection = XDirection::XDirectionLeft;
        }
        else if (direction == XDirection::XDirectionRight)
        {
            mArmaturePlayer->setScaleX(1.0f);
            mRunDirection = XDirection::XDirectionRight;
        }
        mArmaturePlayer->getAnimation()->play("Run");
        CCLOG("runrunrun");
    }
}

void XPlayer::stop()
{
    if (mArmaturePlayer) {
        mArmaturePlayer->getAnimation()->stop();
        mRunDirection = XDirection::XDirectionDefault;
    }
}

void XPlayer::updatePos(float dt)
{
    float dirction = 1.0f;
    if (mRunDirection == XDirection::XDirectionLeft) {
        dirction = -1.0f;
    }
    else if (mRunDirection == XDirection::XDirectionRight)
    {
        dirction = 1.0f;
    }
    else
    {
        dirction = 0.0f;
    }
    
    Point destPos = Point(mArmaturePlayer->getPosition().x + X_PLAYER_SEED * dt * dirction,mArmaturePlayer->getPosition().y);
    
    if (checkPlayerInScreen(destPos)) {
        mArmaturePlayer->setPosition(destPos);
    }
}

bool XPlayer::checkPlayerInScreen(const Point& pos) const
{
    Size visibleSize = Director::getInstance()->getVisibleSize();

    if ((pos.x + mArmaturePlayer->getContentSize().width * 0.5f < visibleSize.width)
        && (pos.x - mArmaturePlayer->getContentSize().width * 0.5f > 0)) {
        return true;
    }

    return false;
}


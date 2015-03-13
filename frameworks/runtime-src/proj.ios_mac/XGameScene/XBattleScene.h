//
//  XBattleScene.h
//  X
//
//  Created by Leo on 15/3/8.
//
//

#ifndef __X__XBattleScene__
#define __X__XBattleScene__

#include <stdio.h>
#include "cocos2d.h"
#include "cocostudio/CCArmature.h"
#include "XMessagePool.h"

class UIBattleLayer;

using namespace cocos2d;
using namespace cocostudio;

class XBattleScene : public Layer
{
public:
    
    void update(float dt);
    bool checkPlayerInScreen(Point playerPos);
    
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(XBattleScene);
    
private:
    
    Armature* armaturePlayer;
    XCharacterMoveDirection lastDirec;
    UIBattleLayer* uiBattleLayer;
    
};

#endif /* defined(__X__XBattleScene__) */

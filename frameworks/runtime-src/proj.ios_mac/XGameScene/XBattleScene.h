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

class UIBattleLayer;

using namespace cocos2d;

class XBattleScene : public Layer
{
public:
    
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(XBattleScene);
    
private:
    
    UIBattleLayer* uiBattleLayer;
};

#endif /* defined(__X__XBattleScene__) */

//
//  XPlayer.h
//  X
//
//  Created by leo on 15/1/19.
//
//

#ifndef __X__XPlayer__
#define __X__XPlayer__

#include <stdio.h>
#include "XCharacter.h"
class XPlayerSprite;


class XPlayer : public XCharacter
{
public:
    
    XPlayer(int battleHP);
    virtual ~XPlayer();
private:
   
};

#endif /* defined(__X__XPlayer__) */

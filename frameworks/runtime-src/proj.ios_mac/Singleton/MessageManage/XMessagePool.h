//
//  XMessagePool.h
//  X
//
//  Created by leo on 15/3/13.
//
//

#ifndef __X__XMessagePool__
#define __X__XMessagePool__

#include <stdio.h>

typedef enum
{
  XCharacterMoveDirectionStatic = 0,
  XCharacterMoveDirectionRight,
  XCharacterMoveDirectionLeft
    
} XCharacterMoveDirection;  //游戏角色的移动方向

typedef struct XPlayerControlInfo
{
    XCharacterMoveDirection mToMoveDirec;
} XPlayerControlInfo;

class XMessagePool
{
public:
    
    XMessagePool(void);
    virtual ~XMessagePool(void);
    virtual bool init();
    
    inline void setPlayerMoveDirection(XCharacterMoveDirection toMoveDirect)
    {
        mPlayerControlInfo->mToMoveDirec = toMoveDirect;
    }
    
    inline XCharacterMoveDirection getPlayerMoveDirection() const
    {
        return mPlayerControlInfo->mToMoveDirec;
    }
    
    static XMessagePool* getInstance();
    
private:
    
    XPlayerControlInfo* mPlayerControlInfo;
};

#endif /* defined(__X__XMessagePool__) */

//
//  XHallInfo.h
//  X
//
//  Created by leo on 15/1/19.
//
//

#ifndef __X__XHallInfo__
#define __X__XHallInfo__

#include <stdio.h>
typedef enum
{
    hallStateIdle = 0,
    hallStateTask,
    hallStateComplete,
    hallStateDialogue
}HallState;

class XHallInfo
{
public:
    XHallInfo();
private:
    HallState mState;
};

#endif /* defined(__X__XHallInfo__) */

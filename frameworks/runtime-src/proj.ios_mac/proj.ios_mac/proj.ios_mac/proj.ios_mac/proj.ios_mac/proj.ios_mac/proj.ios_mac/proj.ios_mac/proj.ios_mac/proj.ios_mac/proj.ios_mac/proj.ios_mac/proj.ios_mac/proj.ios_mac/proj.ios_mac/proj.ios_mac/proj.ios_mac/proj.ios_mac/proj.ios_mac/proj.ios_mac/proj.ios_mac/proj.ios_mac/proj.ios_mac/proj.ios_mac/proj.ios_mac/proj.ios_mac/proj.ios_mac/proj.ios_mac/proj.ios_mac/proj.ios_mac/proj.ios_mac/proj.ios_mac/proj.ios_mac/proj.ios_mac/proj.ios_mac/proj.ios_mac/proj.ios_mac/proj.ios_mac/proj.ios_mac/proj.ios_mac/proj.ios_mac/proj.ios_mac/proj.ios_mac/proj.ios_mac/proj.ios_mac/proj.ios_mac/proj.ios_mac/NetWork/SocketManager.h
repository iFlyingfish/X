//
//  SocketManager.h
//  X
//
//  Created by leo on 15/3/17.
//
//

#ifndef __X__SocketManager__
#define __X__SocketManager__

#include <stdio.h>

class SocketManager
{
public:
    static SocketManager* getInstance();
    bool init();
    int connectToServerTest();
};

#endif /* defined(__X__SocketManager__) */

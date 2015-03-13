//
//  XMessagePool.cpp
//  X
//
//  Created by leo on 15/3/13.
//
//

#include "XMessagePool.h"

#include "base/ccMacros.h"

static XMessagePool* s_SharedMessagePool = nullptr;

XMessagePool* XMessagePool::getInstance()
{
    if (! s_SharedMessagePool) {
        
        s_SharedMessagePool = new XMessagePool();
        CCASSERT(s_SharedMessagePool, "FATAL: Not enough memory");
        s_SharedMessagePool->init();
    }
    
    return s_SharedMessagePool;
}

XMessagePool::XMessagePool(void)
{
    
}

bool XMessagePool::init()
{
    mPlayerControlInfo = new XPlayerControlInfo();
    mPlayerControlInfo->mToMoveDirec = XCharacterMoveDirectionStatic;
    
    return true;
}

XMessagePool::~XMessagePool(void)
{
    CC_SAFE_DELETE(mPlayerControlInfo);
    s_SharedMessagePool = nullptr;
}
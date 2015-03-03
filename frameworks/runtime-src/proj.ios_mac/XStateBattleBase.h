//
//  XStateBattleBase.h
//  X
//
//  Created by Leo on 15/3/3.
//
//

#ifndef __X__XStateBattleBase__
#define __X__XStateBattleBase__

#include <stdio.h>
#include "XState.h"

class XStateBattleBase : public XState
{
public:
    XStateBattleBase(const std::string& name);
};

#endif /* defined(__X__XStateBattleBase__) */

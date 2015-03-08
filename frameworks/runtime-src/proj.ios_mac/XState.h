//
//  XState.h
//  X
//
//  Created by leo on 15/2/16.
//
//

#ifndef __X__XState__
#define __X__XState__

#include <stdio.h>
#include "cocos2d.h"

class XCharacter;

using namespace::cocos2d;

class XState
{
public:
    XState(const std::string& name);
    virtual ~XState();
    
    
    
    
    const std::string& getName() const;
protected:
    std::string mName;
};

#endif /* defined(__X__XState__) */

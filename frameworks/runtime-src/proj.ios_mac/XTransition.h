//
//  XTransition.h
//  X
//
//  Created by Leo on 15/3/25.
//
//

#ifndef __X__XTransition__
#define __X__XTransition__

#include <stdio.h>
#include <iostream>

class XCharacter;

class XTransition
{
public:
    XTransition();
    virtual ~XTransition();
    
    virtual bool isMeetCondition(XCharacter* character) = 0;
    
    void SetNoStateName (const std::string& stateName)
    {
        mNoNextStateName = stateName;
    }
    
    const std::string& GetNoNextStateName() const
    {
        return mNoNextStateName;
    }
    
    void SetYesStateName (const std::string& stateName)
    {
        mYesNextStateName = stateName;
    }
    
    const std::string& GetYesNextStateName() const
    {
        return mYesNextStateName;
    }
    
protected:
    std::string mNoNextStateName;
    std::string mYesNextStateName;
    
};

#endif /* defined(__X__XTransition__) */

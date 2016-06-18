//
//  ObjectBuilder.hpp
//  folder system
//
//  Created by daniel luzgarten on 15/06/2016.
//  Copyright © 2016 daniel luzgarten. All rights reserved.
//

#ifndef ObjectBuilder_h
#define ObjectBuilder_h

#include <stdio.h>
#include "Object.h"
class ObjectBuilder{
public:
    virtual Object* getObj()=0;
};
#endif /* ObjectBuilder_h */

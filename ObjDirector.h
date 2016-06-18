//
//  ObjDirector.hpp
//  folder system
//
//  Created by daniel luzgarten on 15/06/2016.
//  Copyright © 2016 daniel luzgarten. All rights reserved.
//

#ifndef ObjDirector_h
#define ObjDirector_h

#include <stdio.h>
#include "ObjectBuilder.h"
#include "Object.h"
class ObjDirector{
private:
    ObjectBuilder* objb;
public:
    ObjDirector(ObjectBuilder* obj);
    Object* getObj();
    
};
#endif /* ObjDirector_h */

//
//  DirBuilder.hpp
//  folder system
//
//  Created by daniel luzgarten on 15/06/2016.
//  Copyright © 2016 daniel luzgarten. All rights reserved.
//

#ifndef DirBuilder_h
#define DirBuilder_h

#include <stdio.h>
#include "Dir.h"
#include "ObjectBuilder.h"
class DirBuilder: public ObjectBuilder{
private:
    Object* obj;
public:
    DirBuilder();
    Object* getObj();
    
};
#endif /* DirBuilder_h */

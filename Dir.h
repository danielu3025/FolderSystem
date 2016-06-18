//
//  Dir.hpp
//  folder system
//
//  Created by daniel luzgarten on 13/06/2016.
//  Copyright © 2016 daniel luzgarten. All rights reserved.
//

#ifndef Dir_h
#define Dir_h

#include <stdio.h>
#include "Object.h"
class Dir: public Object{
    vector<Object*> content;
public:
    Dir();
    virtual ~Dir();
    void setName(string txt);
    string getName();
    bool setContent(Object* obj);
    void showContent();
    bool deleteObj();
    Object* makeCopy();

};
#endif /* Dir_h */

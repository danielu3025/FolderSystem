//
//  File.hpp
//  folder system
//
//  Created by daniel luzgarten on 13/06/2016.
//  Copyright © 2016 daniel luzgarten. All rights reserved.
//

#ifndef File_h
#define File_h

#include <stdio.h>
#include "Object.h"
class File: public Object{
    string content;
public:
    File();
    virtual ~File();
    void setName(string txt);
    string getName();
    void setContent(string txt);
    void showContent();
    bool deleteObj();
    Object* makeCopy();
};
#endif /* File_h */

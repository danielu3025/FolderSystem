//
//  ClonAble.hpp
//  folder system
//
//  Created by daniel luzgarten on 13/06/2016.
//  Copyright © 2016 daniel luzgarten. All rights reserved.
//

#ifndef ClonAble_h
#define ClonAble_h
#include <stdio.h>
#include "Object.h"
#include "Dir.h"
#include "File.h"
class ClonAble{
    static Object* dirType;
    static Object* fileType;
    
public:
    static void initialize(){
        dirType = new Dir();
        fileType = new File();
    }
    static Object* getDirType(){
        return dirType->makeCopy();
    }
    static Object* getFileType(){
        return fileType->makeCopy();
    }
    
};

#endif /* ClonAble_h */

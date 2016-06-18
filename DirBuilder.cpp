//
//  DirBuilder.cpp
//  folder system
//
//  Created by daniel luzgarten on 15/06/2016.
//  Copyright © 2016 daniel luzgarten. All rights reserved.
//

#include "DirBuilder.h"
DirBuilder::DirBuilder(){
    obj = new Dir();
}
Object* DirBuilder::getObj(){

    return  obj;
}
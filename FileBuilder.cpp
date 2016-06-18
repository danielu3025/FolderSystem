//
//  FileBuilder.cpp
//  folder system
//
//  Created by daniel luzgarten on 16/06/2016.
//  Copyright © 2016 daniel luzgarten. All rights reserved.
//

#include "FileBuilder.h"
FileBuilder::FileBuilder(){
    obj = new File();
}
Object* FileBuilder::getObj(){
    
    return  obj;
}

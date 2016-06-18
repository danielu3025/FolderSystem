//
//  FileBuilder.hpp
//  folder system
//
//  Created by daniel luzgarten on 16/06/2016.
//  Copyright © 2016 daniel luzgarten. All rights reserved.
//

#ifndef FileBuilder_h
#define FileBuilder_h

#include "File.h"
#include "ObjectBuilder.h"
class FileBuilder: public ObjectBuilder{
private:
    Object* obj;
public:
    FileBuilder();
    Object* getObj();
    
};

#endif /* FileBuilder_h*/

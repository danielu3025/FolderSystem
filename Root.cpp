//
//  Root.cpp
//  folder system
//
//  Created by daniel luzgarten on 14/06/2016.
//  Copyright © 2016 daniel luzgarten. All rights reserved.
//

#include "Root.h"
Dir* Root::folder = 0;
Dir Root::getInstance()
{
    if(!folder){
        folder = new Dir();
        folder->setName("ROOT");
    }
    return *folder;
}
//
//  Root.hpp
//  folder system
//
//  Created by daniel luzgarten on 14/06/2016.
//  Copyright © 2016 daniel luzgarten. All rights reserved.
//

#ifndef Root_h
#define Root_h
#include "Dir.h"
#include <stdio.h>
class Root: Dir{
public:
    static Dir getInstance();
    inline ~Root();
private:
    static Dir* folder;
    Root();
};
#endif /* Root_h */

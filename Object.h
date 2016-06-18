//
//  Object.hpp
//  folder system
//
//  Created by daniel luzgarten on 13/06/2016.
//  Copyright © 2016 daniel luzgarten. All rights reserved.
//

#ifndef Object_h
#define Object_h

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Object{
public:
    string name;
    virtual ~Object();
    virtual void setName(string txt)  ;
    virtual string getName();
    virtual void showContent();
    virtual bool deleteObj();
    virtual Object* makeCopy();
};




#endif /* Object_h */

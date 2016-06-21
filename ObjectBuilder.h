#ifndef ObjectBuilder_h
#define ObjectBuilder_h

#include <stdio.h>
#include "Object.h"
class ObjectBuilder{
public:
    virtual Object* getObj()=0;
};
#endif /* ObjectBuilder_h */

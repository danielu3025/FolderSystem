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
    vector<Object*> getContent();
    Object* makeCopy();

};
#endif /* Dir_h */

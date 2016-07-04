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
    void showContent(int space);
    void deleteObj();
    void printToFile(ofstream &os, int space);
    vector<Object*> getContent();
    Object* makeCopy();

};
#endif /* Dir_h */

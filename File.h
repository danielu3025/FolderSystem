#ifndef File_h
#define File_h

#include <stdio.h>
#include "Object.h"
class File: public Object{
    string content;
public:
    File();
    virtual ~File();
    void setName(string txt);
    string getName();
    void setContent(string txt);
    void showContent(int space);
    void deleteObj();
    void printToFile(ofstream &of, int space);
    ClonAble* clon();
};
#endif /* File_h */

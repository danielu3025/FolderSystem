#ifndef Object_h
#define Object_h

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>


using namespace std;

class Object{
public:
    bool isAfile = false;
    string name;
    virtual void printToFile(ofstream &os, int space);
    virtual ~Object();
    virtual void setName(string txt)  ;
    virtual string getName();
    virtual void showContent(int space);
    virtual void deleteObj();
    virtual Object* makeCopy();
    virtual vector<Object*> getContent();
    virtual bool gekind();
    virtual void setKind(bool status);
};




#endif /* Object_h */

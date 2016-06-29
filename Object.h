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
    string name;
    virtual void printToFile(ofstream &os, int space);
    virtual ~Object();
    virtual void setName(string txt)  ;
    virtual string getName();
    virtual void showContent(int space);
    virtual void deleteObj();
    virtual Object* makeCopy();
    virtual vector<Object*> getContent();
};




#endif /* Object_h */

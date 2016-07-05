#ifndef HW1U_MENU_H
#define HW1U_MENU_H

#include <iostream>
#include <string>
#include "Dir.h"
#include "File.h"
#include "ClonAble.h"
#include "Root.h"
#include "DirBuilder.h"
#include "FileBuilder.h"
#include "ObjDirector.h"

using namespace std;

class Menu {
private:
    bool inSystem;
    char choice;
    string location;
    ofstream myFile;
public:
    ~Menu();
    Object* findObj(string path,Dir Root);
    Object* findObjFather(string path,Dir Root);
    void setInSystem(bool inSystem);
    bool seeIfExist(string objName, Dir Root);
    vector<string>split(string str, char delimiter);
    Menu();
    void program();
    void printMenu();
};


#endif //HW1U_MENU_H

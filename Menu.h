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
    void setInSystem(bool inSystem);
    Menu();
    void program();
    void printMenu();
};


#endif //HW1U_MENU_H

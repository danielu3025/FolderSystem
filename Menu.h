#ifndef HW1U_MENU_H
#define HW1U_MENU_H

#include <iostream>
#include <string>
#include "Dir.h"
#include "File.h"
#include "ClonAble.h"
#include "Root.h"

using namespace std;

class Menu {
private:
    bool inSystem;
    char choice;
    Dir* masterRoot;

public:
    Menu();
   void setInSystem(bool inSystem);
   void program();
    void printMenu();
    ~Menu();
};

class System: public Menu{
private:
    System();
    static Menu* sys;
public:
    static Menu getInstance();
    ~System();
    
};




#endif //HW1U_MENU_H

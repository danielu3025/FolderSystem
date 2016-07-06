#ifndef HW1U_MENU_H
#define HW1U_MENU_H

#include <iostream>
#include <string>
#include "Dir.h"
#include "File.h"
#include "ClonAble.h"
#include "Root.h"

using namespace std;
class System{
public:
    ~System();
    virtual void program();

};
class Menu{
private:
    Menu();
    static System* sys;
    bool inSystem;
    char choice;
    string location;
    ofstream myFile;
public:
    void setInSystem(bool inSystem);
    void program();
    void printMenu();
    static System getInstance();
    inline~Menu();
};




#endif //HW1U_MENU_H

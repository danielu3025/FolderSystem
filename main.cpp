// make type in objects for copying

#include <iostream>
#include "Menu.h"
#include <sstream>


int main(int argc, const char * argv[]) {
     
/*
    
    Object* obj = ClonAble::getDirType();
    Dir* home = dynamic_cast<Dir*>(obj);
    home->setName("home");
    
    File hello; hello.setName("hello.txt");
    
    root.setContent(home);
    home->setContent(&hello);
    
    root.showContent();
    
    Object* user; user = home->makeCopy();
    user->setName("user");
    
    root.setContent(user);
    root.showContent();
    
    FileBuilder* doc = new (FileBuilder);
    ObjDirector* manger =new ObjDirector(doc);
    
    Object* realFolder = manger->getObj();
    
    realFolder->setName("mydoc");
     
    */
    
    Menu foldersystem ;
    foldersystem.program();
    //Dir rooti = Root::getInstance();
   // Object* zibi = &rooti;
   // Dir* f ;
   // f = dynamic_cast<Dir*>(zibi);
    
    
    
    
    return 0;
}

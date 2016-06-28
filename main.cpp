// make type in objects for copying

#include <iostream>
#include "Menu.h"
#include <sstream>


int main(int argc, const char * argv[]) {
    //Dir root = Root::getInstance();
    /*Dir *s = new Dir;
    s->setName("shahar");
    root.setContent(s);
    Dir *l = new Dir;
    l->setName("liron");
    Dir *e = new Dir;
    e->setName("eyal");
    s->setContent(l);
    s->setContent(e);
    Dir *b = new Dir;
    b->setName("baba");
    File *f = new File;
    f->setName("ff");
    f->setContent("ffff");
    root.setContent(f);
    root.setContent(b);
    root.showContent(0);

    root.deleteObj();


    
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

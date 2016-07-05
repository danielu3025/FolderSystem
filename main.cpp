// make type in objects for copying

#include <iostream>
#include "Menu.h"
#include <sstream>
#include <memory>


int main(int argc, const char * argv[]) {
    shared_ptr<int> a(new int(10));
    a.make_shared(10);
    shared_ptr<int>x  new shared_ptr<int>;
    a = x;
    cout<<x;

    
    
/*    Dir root = Root::getInstance();
    Dir *s = new Dir;
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
    ofstream myfile;
    myfile.open ("systemContent");
    root.printToFile(myfile,0);
    myfile.close();
    root.deleteObj();*/


/*
    
    Object* obj = ClonAble::getDirType();
    Dir* home = dynamic_cast<Dir*>(obj);
    home->setName("home");
    
    File hello; hello.setName("hello.txt");
    
    root.setContent(home);
    home->setContent(&hello);
    
    root.showContent(0);
    
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

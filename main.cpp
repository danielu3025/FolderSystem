//
//  main.cpp
//  folder system
//
//  Created by daniel luzgarten on 13/06/2016.
//  Copyright © 2016 daniel luzgarten. All rights reserved.
//

// make type in objects for copying

#include <iostream>
#include "Dir.h"
#include "File.h"
#include "ClonAble.h"
#include "Root.h"
#include "DirBuilder.h"
#include "FileBuilder.h"
#include "ObjDirector.h"

Object* ClonAble::dirType = 0;
Object* ClonAble::fileType = 0;



int main(int argc, const char * argv[]) {
    // insert code here...
    /*Dir root = Root::getInstance();
    ClonAble::initialize();
    
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
    root.showContent();*/
    
    FileBuilder* doc = new (FileBuilder);
    ObjDirector* manger =new ObjDirector(doc);
    
    Object* realFolder = manger->getObj();
    
    realFolder->setName("mydoc");
    
    

    
    
    return 0;
}

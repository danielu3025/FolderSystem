#include "DirBuilder.h"
DirBuilder::DirBuilder(){
    obj = new Dir();
}
Object* DirBuilder::getObj(){
    string name;
    cout<<"enter Folder name:";
    cin>>name;
    obj->setName(name);
    return obj;
}

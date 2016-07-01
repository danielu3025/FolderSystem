#include "FileBuilder.h"
FileBuilder::FileBuilder(){
    obj = new File();
}
Object* FileBuilder::getObj(){
    string namei;
    cout<<"enter file name:";
    cin>>namei;
    obj->name = namei;
    return  obj;
}

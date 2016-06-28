#include "File.h"
File::File(){
    name = "new-file";
}
File::~File(){
    cout<< "~" << this->name << endl;
}
void File::setName(string txt){
    name = txt;
}
string File::getName(){
    return name;
}
void File::setContent(string txt){
    content = txt;
}
void File::showContent(int tabs){
    for(int i=0; i<tabs; i++){
        cout<<"\t";
    }
    cout<<this->name<<"\n";
}
void File::deleteObj(){
    delete this;
}
Object* File::makeCopy(){
    cout<<"copy "<<this->name<<endl;
    File* clon = new File(*this);
    clon->setName(this->name);
    return clon;
}

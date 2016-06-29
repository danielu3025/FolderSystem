#include "File.h"
File::File(){
    name = "new-file";
}
File::~File(){
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
void File::showContent(int space){
    for(int i=0; i<space; i++){
        cout<<"   ";
    }
    cout<<this->name<<"\n";
}
void File::printToFile(ofstream &of, int space) {
    for(int i=0; i<space; i++){
        of<<"   ";
    }
    of<<this->name<<"\n";
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

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
ClonAble* File::clon(){
    File* copy =  new File(*this);
    cout<<"enter file name:";
    cin>>copy->name;
    return copy;
}
void File::showContent(int space){
    for(int i=0; i<space; i++){
        cout<<"   ";
    }
    cout<<this->name<<"\n";
}
void File::printToFile(ofstream &of, int space) {
    of.open("systemContent.txt",of.app);
    if (of.is_open()) {
        for (int i = 0; i < space; i++) {
            of << "   ";
        }
        of<<this->name<<".file\n";
        of.close();
    }
}

void File::deleteObj(){
    delete this;
}

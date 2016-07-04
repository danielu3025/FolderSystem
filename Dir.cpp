#include "Dir.h"
Dir::Dir(){
    name = "folder";
}
Dir::~Dir(){
}
void Dir::setName(string txt){
    this->name = txt;
}
string Dir::getName(){
    return name;
}
bool Dir::setContent(Object* obj){
    try {
        content.push_back(obj);
    } catch (bad_alloc e) {
        cout<<&e<<endl;;
        return false;
    }
    return true;

}
void Dir::showContent(int space){
    for(int i=0; i<space; i++){
        cout<<"   ";
    }
    cout<<this->name<<"\n";
    for (int i = 0; i < content.size(); i++){
        content[i]->showContent(space+1);
    }
}
void Dir::deleteObj(){
    for (int i = 0; i < content.size(); i++){
        content[i]->deleteObj();
    }
    if(this->name!="ROOT") {
        delete this;
    }
}
Object* Dir::makeCopy(){
    cout<<"copy "<<this->name<<"\n";
    Dir* clone =  new Dir(*this);
    clone->setName(this->getName());
    for (int i = 0; i < content.size(); i++){
        content[i]->makeCopy();
    }
    return clone;
}
vector<Object*> Dir::getContent(){
    return this->content;
}

void Dir::printToFile(ofstream &of, int space) {
    of.open("systemContent.txt",of.app);
    if (of.is_open()) {
        for(int i=0; i<space; i++){
            of<<"   ";
        }
        of<<this->name<<"\n";
        for (int i = 0; i < content.size(); i++){
            of.close();
            content[i]->printToFile(of,space+1);
        }
    }
    of.close();
}

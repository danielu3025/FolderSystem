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
void Dir::showContent(int tabs){
    for(int i=0; i<tabs; i++){
        cout<<"\t";
    }
    cout<<this->name<<"\n";
    for (int i = 0; i < content.size(); i++){
        content[i]->showContent(++tabs);
    }
}
bool Dir::deleteObj(){
    return true;
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

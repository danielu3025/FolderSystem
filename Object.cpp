#include "Object.h"


Object::~Object(){
    
}
void Object::setName(string txt){
    
}
string Object::getName(){
    return "object";
}
void Object::showContent(int space){
    
}
void Object::deleteObj(){
}
Object* Object::makeCopy(){
    return nullptr  ;
}
vector<Object*> Object::getContent(){
    vector<Object*>x;
    return x;
}

void Object::printToFile(ofstream &os, int space) {

}
void Object::setKind(bool status){
    isAfile = status;
}
bool Object::gekind(){
    return isAfile;
}

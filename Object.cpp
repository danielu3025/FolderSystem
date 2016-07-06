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
vector<Object*> Object::getContent(){
    vector<Object*>x;
    return x;
}

void Object::printToFile(ofstream &os, int space) {

}

ClonAble* Object::clon(){
    return this;
}
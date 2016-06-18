//
//  Dir.cpp
//  folder system
//
//  Created by daniel luzgarten on 13/06/2016.
//  Copyright © 2016 daniel luzgarten. All rights reserved.
//

#include "Dir.h"
Dir::Dir(){
    name = " new-folder";
}
Dir::~Dir(){
    cout<<name<<" distractor\n";
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
void Dir::showContent(){
    cout<<this->name<<"\n\t";
    for (int i = 0; i < content.size(); i++){
        content[i]->showContent();

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
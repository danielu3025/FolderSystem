//
//  File.cpp
//  folder system
//
//  Created by daniel luzgarten on 13/06/2016.
//  Copyright © 2016 daniel luzgarten. All rights reserved.
//

#include "File.h"
File::File(){
    name = "new-file";
}
File::~File(){
    cout<<"File distractor\n";
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
void File::showContent(){
    cout<<this->name<<endl;
}
bool File::deleteObj(){
    return true;
}
Object* File::makeCopy(){
    cout<<"copy "<<this->name<<endl;
    File* clon = new File(*this);
    clon->setName(this->name);
    return clon;
}

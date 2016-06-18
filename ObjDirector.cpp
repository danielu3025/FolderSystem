//
//  ObjDirector.cpp
//  folder system
//
//  Created by daniel luzgarten on 15/06/2016.
//  Copyright © 2016 daniel luzgarten. All rights reserved.
//

#include "ObjDirector.h"

ObjDirector::ObjDirector(ObjectBuilder* obj){
    this->objb = obj  ;
}
Object* ObjDirector::getObj(){
    return objb->getObj();
}
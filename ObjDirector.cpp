#include "ObjDirector.h"

ObjDirector::ObjDirector(ObjectBuilder* obj){
    this->objb = obj  ;
}
Object* ObjDirector::getObj(){
    return objb->getObj();
}
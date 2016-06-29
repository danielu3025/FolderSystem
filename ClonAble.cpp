#include "ClonAble.h"
ClonAble::~ClonAble(){
    delete dirType;
    delete fileType;
}
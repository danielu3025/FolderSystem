#ifndef PrototypeMaker_h
#define PrototypeMaker_h

#include <stdio.h>
#include "Dir.h"
#include "File.h"
class PrototypeMaker{
private:
    static ClonAble* dirPrototype;
    static ClonAble* filePrototype;
public:
    static void initialize(){
        dirPrototype = new Dir();
        filePrototype = new File();
    }
    static ClonAble* getDirType(){
        return dirPrototype->clon();
    }
    static ClonAble* getFileType(){
        return filePrototype->clon();
    }
};
#endif /* PrototypeMaker_h */

#ifndef FileBuilder_h
#define FileBuilder_h

#include "File.h"
#include "ObjectBuilder.h"
class FileBuilder: public ObjectBuilder{
private:
    Object* obj;
public:
    FileBuilder();
    Object* getObj();
    
};

#endif /* FileBuilder_h*/

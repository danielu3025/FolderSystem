#include "Root.h"
Dir* Root::folder = 0;
Dir Root::getInstance()
{
    if(!folder){
        folder = new Dir();
        folder->setName("ROOT");
    }
    return *folder;
}
Root::~Root() {
}

#ifndef Root_h
#define Root_h
#include "Dir.h"
#include <stdio.h>
class Root: Dir{
private:
    Root();
    static Dir* folder;
public:
    static Dir getInstance();
    inline ~Root();
};
#endif /* Root_h */

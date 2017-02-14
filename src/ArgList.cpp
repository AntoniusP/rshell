#include "Arglist.h"


void addArg(cmdComponent* a) // appends argument  “a” to ArgList
{
    ArgVec.push_back(a);
}


void deleteArg()			      // removes arg at last index
{
    ArgVec.pop_back();
}


cmdComponent* at(int i) // returns “argument” at index “i”
{
    return ArgVec.at(i);
}
#include "ArgList.h"

ArgList::ArgList()
{
    
}

ArgList::ArgList(unsigned size)
{
    arguments = new char*[size];
}

ArgList::~ArgList()
{
    delete[] arguments;
}

char** ArgList::getArgs() 
{
    return arguments;
}


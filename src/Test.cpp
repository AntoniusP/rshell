#include "Test.h"

Test::Test() 
{
    
}

bool Test::execute() 
{
    struct stat buf;
    bool exists = false;
    
    stat(Args[1], &buf);
    
    if (S_ISREG(buf.st_mode)) 
    {
        return exists;
    }
    
    if (S_ISREG(buf.st_mode)) 
    {
        return exists;
    }
    return false;
}
#include "And.h"

bool And::execute() 
{
    if(left->execute())
    {
        if(right->execute())
        {
            return true;
        }
        return false;
    }
    return false;
}
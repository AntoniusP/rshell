#include "And.h"

bool And::execute(int in, int out) 
{
    if(left->execute(in, out))
    {
        if(right->execute(in, out))
        {
            return true;
        }
        return false;
    }
    return false;
}
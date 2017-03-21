#include "Or.h"

bool Or::execute(int in, int out) 
{
    if (!left->execute(in, out))
    {
        if (right->execute(in, out))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return true;
}
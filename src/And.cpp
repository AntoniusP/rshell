#include "And.h"

bool And::execute() 
{
    cout << "and ex" << endl;
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
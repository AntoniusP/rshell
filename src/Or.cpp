#include "Or.h"

bool Or::execute() 
{
    cout << "Or ex" << endl;
    if (!left->execute())
    {
        if (right->execute())
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
#include "Or.h"

bool Or::execute() {
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
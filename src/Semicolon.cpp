#include "Semicolon.h"

bool Semicolon::execute()
{
    left->execute();
    if (right->execute())
    {
        return true;
    }
    return false;
}
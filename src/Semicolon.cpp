#include "Semicolon.h"

bool Semicolon::execute(int in, int out)
{
    left->execute(in, out);
    if (right->execute(in, out))
    {
        return true;
    }
    return false;
}
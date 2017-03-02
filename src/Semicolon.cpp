#include "Semicolon.h"

bool Semicolon::execute()
{
    cout << "semicolon ex" << endl;
    left->execute();
    if (right->execute())
    {
        return true;
    }
    return false;
}
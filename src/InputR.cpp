#include "InputR.h"

bool InputR::execute(int in, int out)
{
    string inputF = right->getData();
    
    in = open(inputF.c_str(), O_RDONLY);
    return left->execute(in, 1);
}

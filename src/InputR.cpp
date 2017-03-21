#include "InputR.h"

bool InputR::execute(int in, int out)
{
    //take in the data on the right as the input file
    string inputF = right->getData();
    
    in = open(inputF.c_str(), O_RDONLY);
    return left->execute(in, 1);
}

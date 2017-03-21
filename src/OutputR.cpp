#include "OutputR.h"

bool OutputR::execute(int in, int out)
{
    //take in the data on the right as the output file to truncate and add
    string outputF = right->getData();
    out = open(outputF.c_str(), O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
    return left->execute(0, out);
}
#include "OutputR.h"

bool OutputR::execute(int in, int out)
{
    string outputF = right->getData();
    out = open(outputF.c_str(), O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
    return left->execute(0, out);
}
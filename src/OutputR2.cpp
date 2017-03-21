#include "OutputR2.h"

bool OutputR2::execute(int in, int out)
{
    //take in the data on the right as the output file to append
    string outputF = right->getData();
    out = open(outputF.c_str(), O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
    return left->execute(0, out);
}
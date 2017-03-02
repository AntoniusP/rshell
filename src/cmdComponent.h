#ifndef CMDCOMPONENT_H
#define CMDCOMPONENT_H

#include <unistd.h>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

class cmdComponent {
    public:
    virtual bool execute() = 0;
};

#endif
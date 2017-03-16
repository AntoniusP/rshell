#ifndef CMDCOMPONENT_H
#define CMDCOMPONENT_H
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

class cmdComponent {
    public:
    virtual bool execute(int in, int out) = 0;
};

#endif
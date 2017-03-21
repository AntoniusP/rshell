#ifndef OUTPUTR2_H
#define OUTPUTR2_H

#include "Connector.h"

class OutputR2 : public Connector {
    public:
    OutputR2() : Connector() {}
    OutputR2(cmdComponent* l, cmdComponent* r) : Connector(l,r) {}
    bool execute(int in, int out);
};

#endif
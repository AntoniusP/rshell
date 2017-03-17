#ifndef OUTPUTR_H
#define OUTPUTR_H

#include "Connector.h"

class OutputR : public Connector {
    public:
    OutputR() : Connector() {}
    OutputR(cmdComponent* l, cmdComponent* r) : Connector(l,r) {}
    bool execute(int in, int out);
};

#endif
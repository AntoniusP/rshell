#ifndef INPUTR_H
#define INPUTR_H

#include "Connector.h"

class InputR : public Connector {
    public:
    InputR() : Connector() {}
    InputR(cmdComponent* l, cmdComponent* r) : Connector(l,r) {}
    bool execute(int in, int out);
};

#endif
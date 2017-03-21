#ifndef PIPE_H
#define PIPE_H

#include "Connector.h"

class Pipe : public Connector {
    public:
    Pipe() : Connector() {}
    Pipe(cmdComponent* l, cmdComponent* r) : Connector(l,r) {}
    bool execute(int in, int out);
};

#endif
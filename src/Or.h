#ifndef OR_H
#define OR_H

#include "Connector.h"

class Or: public Connector {
    
    public:
    Or() : Connector() {}
    Or(cmdComponent* l, cmdComponent* r) : Connector(l,r) {}
    bool execute(int in, int out);
};

#endif
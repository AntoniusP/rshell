#ifndef AND_H
#define AND_H

#include "Connector.h"

class And: public Connector {
    
    public:
    And() : Connector() {}
    And(cmdComponent* l, cmdComponent* r) : Connector(l,r) {}
    bool execute(int in, int out);
};

#endif
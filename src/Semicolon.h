#ifndef SEMICOLON_H
#define SEMICOLON_H

#include "Connector.h"

class Semicolon: public Connector {
    
    public:
    Or() : Connector() {}
    Or(cmdComponent* l, cmdComponent* r) : Connector(l,r) {}
    bool execute();
};

#endif
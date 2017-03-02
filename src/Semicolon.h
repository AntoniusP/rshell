#ifndef SEMICOLON_H
#define SEMICOLON_H

#include "Connector.h"

class Semicolon: public Connector {
    
    public:
    Semicolon() : Connector() {}
    Semicolon(cmdComponent* l, cmdComponent* r) : Connector(l,r) {}
    bool execute();
};

#endif
#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "cmdComponent.h"

class Connector: public cmdComponent {
    protected:
    cmdComponent* left;
    cmdComponent* right;
    
    public:
    Connector() : left(0), right(0) {}
    Connector(cmdComponent* l, cmdComponent* r) : left(l), right(r) {}
    ~Connector();
    virtual bool execute() = 0;
};
#endif
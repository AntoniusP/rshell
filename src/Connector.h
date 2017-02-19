#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "cmdComponent.h"

class Connector: cmdComponent {
    protected:
    string type;
    
    public:
    string getType();
}

#endif
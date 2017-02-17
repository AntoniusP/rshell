#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "cmdComponent.h"

class Connector: cmdComponent {
    public:
    
    string type;
    string getType();
}

#endif
#include "Connector.h"

Connector::~Connector() 
{
    delete left;
    delete right;
    left = 0; 
    right = 0;
}
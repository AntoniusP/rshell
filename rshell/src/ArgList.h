#ifndef ARGLIST_H
#define ARGLIST_H

#include "cmdComponent.h"

class ArgList : public cmdComponent {
    protected:
    char** arguments;        // container of argument
	
	public:
	ArgList();
	ArgList(unsigned size);
	~ArgList();
	char** getArgs();		// returns the object 

};

#endif
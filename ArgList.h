#ifndef ARGLIST_H
#define ARGLIST_H

#include <vector>
#include "cmdComponent.h"


class ArgList : public cmdComponent {
    
    protected:
    vector <cmdComponent*> ArgVec   // container of argument
	
	public:
	void addArg(cmdComponent a);	      // appends argument  “a” to ArgList
    void deleteArg();			      // removes arg at last index
	cmdComponent* at(int i); 		  // returns “argument” at index “i”

};

#endif
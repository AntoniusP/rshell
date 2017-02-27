#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#include "cmdComponent.h"

class Test : public cmdComponent 
{
	protected:
	char** Args;
	
	public:
	Test();
	bool execute();		// runs the program with arguments 
};

#endif
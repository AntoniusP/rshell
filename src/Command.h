#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include "ArgList.h"

class Command : public cmdComponent 
{
	protected:
	ArgList Args;			// arguments
	cmdComponent end;		// connector
	
	public:
	Command();
	Command(ArgList a, cmdComponent e);
	void execute();		// runs the program with arguments 
	ArgList getArgs();
};

#endif
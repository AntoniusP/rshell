#ifndef COMMAND_H
#define COMMAND_H

#include <sys/types.h>
#include <sys/wait.h>

#include "cmdComponent.h"

class Command : public cmdComponent 
{
	protected:
	char** Args;
	
	public:
	Command();
	void setCommand(char** a);
	bool execute();		// runs the program with arguments 
	char** getArgs();
};

#endif
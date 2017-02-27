#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include "ArgList.h"

class Command : public cmdComponent 
{
	protected:
	char** Args;
	string end;		// connector
	
	public:
	Command();
	void setCommand(char** a, string e);
	bool execute();		// runs the program with arguments 
	char** getArgs();
};

#endif
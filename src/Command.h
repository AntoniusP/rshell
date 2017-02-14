#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <string>
#include <sys/types.h>
#include "cmdComponent.h"

class Command : public cmdComponent 
{
	protected:
	cmdComponent* ex;	// executable string from /usr/bin
	ArgList Args;		// arguments 
	Connector end;		// connector
	
	public:
	Command();
	Command(cmdComponent x, ArgList a, connector e) : ex(x), Args(a), end(e) {}
	cmdComponent* getCommand();
	void execute();		// runs the program with arguments 
};

#endif
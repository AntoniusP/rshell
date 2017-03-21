#ifndef COMMAND_H
#define COMMAND_H

#include "cmdComponent.h"

class Command : public cmdComponent 
{
	protected:
	char** Args;
	
	public:
	Command();
	~Command();
	void setCommand(char** a);
	bool execute(int in, int out);		// runs the program with arguments 
	string getData();
};

#endif
#ifndef TEST_H
#define TEST_H

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
#ifndef TEST_H
#define TEST_H

#include <sys/stat.h>

#include "cmdComponent.h"

class Test : public cmdComponent 
{
	protected:
	char** Args;
	
	public:
	Test();
	~Test();
	void setTest(char** a);
	bool execute(int in, int out);		// runs the program with arguments 
};

#endif
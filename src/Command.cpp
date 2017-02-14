#include "Command.h"


cmdComponent* Command::getCommand() 
{
    return ex;
}


void Command::execute() 
{
    // run program with arguments
    // this only runs the 1 command passed in 
    pid_t pid; 
    int status;
    
    //execvp();
    //fork();
    //waitpid();
    return;
}
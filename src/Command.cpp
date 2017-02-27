#include "Command.h"
#include <stdio.h>

Command::Command()
{
    
}

void Command::setCommand(char** a, string e) 
{
    
}

bool Command::execute() 
{
    // uses the command data to execute single command 
    pid_t pid; 
    int status;
    
    if ( (pid = fork()) < 0)                        // fork child process
    {
        perror("Fork Failed");
        exit(1);
    }
    else if (pid == 0)
    {
        if (execvp(Args[0], Args) < 0)  // execute on child
        {
            perror("ERROR: exec failed");
            exit(1);
        }
    }
    else 
    {
        while (wait(&status) != pid)                // parent waits for child;
            ;                                       // do nothing
    }
    return true;
}

char** Command::getArgs() 
{
    return Args;
}

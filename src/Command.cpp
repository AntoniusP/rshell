#include "Command.h"
#include <stdio.h>

Command::Command()
{
    
}

void Command::setCommand(char** a) 
{
    Args = a;
}

bool Command::execute() 
{
    // uses the command data to execute single command 
    pid_t pid; 
    int status;
    bool success = true;
    
    if ( (pid = fork()) < 0)                        // fork child process
    {
        perror("Fork Failed");
        exit(1);
    }
    else if (pid == 0)
    {
        if (execvp(Args[0], Args) < 0)  // execute on child
        {
            success = false;
            perror("ERROR: exec failed");
            exit(1);
        }
    }
    else 
    {
        while (wait(&status) != pid)
        {                                       // parent waits for child;
            if (WEXITSTATUS(status) == 1)
            {
                return false;   
            }
        }                                   // do nothing
    }
    return success;
}

char** Command::getArgs() 
{
    return Args;
}

#include "Command.h"
#include <stdio.h>

Command::Command()
{
    
}

Command::~Command()
{
    delete[] Args;    
}

void Command::setCommand(char** a) 
{
    Args = a;
}

bool Command::execute(int in, int out) 
{
    // uses the command data to execute single command 
    int status;
    bool success = true;
    pid_t pid = fork();
    
    if (pid < 0)                        // fork child process
    {
        perror("Fork Failed");
        exit(1);
    }
    else if (pid == 0)
    {
        if (dup2(in, 0) < 0)
        {
            perror("ERROR: dup2in");
            return false;
        }
        
        if (dup2(out, 1) < 0)
        {
            perror("ERROR: dup2out");
        }
        
        if (execvp(Args[0], Args) < 0)  // execute on child
        {
            success = false;
            perror("ERROR: exec >");    
            exit(1);
        }
    }
    else 
    {
        while (wait(&status) != pid)
        {                                       // parent waits for child;
            if (WEXITSTATUS(status) != 0)
            {
                success = false;
            }
        }                                   // do nothing
    }
    return success;
}

char** Command::getArgs() 
{
    return Args;
}

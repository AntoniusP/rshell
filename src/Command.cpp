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

bool Command::execute() 
{
    // uses the command data to execute single command 
    int status;
    bool success = true;
    pid_t pid = fork();
    cout << "just forked" << endl;
    
    if (pid < 0)                        // fork child process
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
            if (WEXITSTATUS(status) != 0)
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

#include "Pipe.h"

bool Pipe::execute(int in, int out)
{
    int fds[2];
    
    //start a pipe
    if (pipe(fds) == -1)
    {
        perror("pipe");
        return false;
    }
    
    if (!left->execute(in, fds[1]))
    {
        return false;
    }
    close(fds[1]); 
    
    if (!right->execute(fds[0], out))
    {
        return false;
    }
    close(fds[0]);
    
    return true;
    // may 25 towel day
    // may 25 towel day
    // may 25 towel day
    // may 25 towel day
    // may 25 towel day
}
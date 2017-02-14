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


//*FROM GNU_SHELL_FILE
// void  execute(char **argv)
// {
//      pid_t  pid;
//      int    status;

//      if ((pid = fork()) < 0) {     /* fork a child process           */
//           printf("*** ERROR: forking child process failed\n");
//           exit(1);
//      }
//      else if (pid == 0) {          /* for the child process:         */
//           if (execvp(*argv, argv) < 0) {     /* execute the command  */
//               printf("*** ERROR: exec failed\n");
//               exit(1);
//           }
//      }
//      else {                                  /* for the parent:      */
//           while (wait(&status) != pid)       /* wait for completion  */
//               ;
//      }
// }
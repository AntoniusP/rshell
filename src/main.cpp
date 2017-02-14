#include <iostream>
#include <string>
using namespace std;

#include "Command.h"
#include "ArgList.h"

int main() 
{
    string input = "";
    
    while(1)                                                // shell should run indefinitly unless exited 
    {                                       
        cout << "$ ";
        getline(cin, input);                                // get whole command line
        cout << endl;
        
        
        cmdComponent sentence(input);                       // create cmdComponent object
        vector<cmdComponents> keywords;

        //keywords = sentence.parse();                      // parse whole word(strtok)
        
        vector<cmdComponent*> commands;                     // *WIP* vector to store the list of commands
        
        //create commands from keywords
        
        if(commands.at(i).getWord() = "exit")               // if user input exit, then exit
        {
            exit(0);
        }        
        else
        {
            for(usigned i = 0; i < commands.size(); i++)    //else execute the command(s)
            {
                commands.at(i)->execute();  
            }
        }
    }
    
    return 0;
}



//*FROM GNU_SHELL_FILE 
// void  main(void)
// {
//      char  line[1024];             /* the input line                 */
//      char  *argv[64];              /* the command line argument      */

//      while (1) {                   /* repeat until done ....         */
//           printf("Shell -> ");     /*   display a prompt             */
//           gets(line);              /*   read in the command line     */
//           printf("\n");
//           parse(line, argv);       /*   parse the line               */
//           if (strcmp(argv[0], "exit") == 0)  /* is it an "exit"?     */
//               exit(0);            /*   exit if it is                */
//           execute(argv);           /* otherwise, execute the command */
//      }
// }



// #include  <stdio.h>
// #include  <sys/types.h>

// void  parse(char *line, char **argv)
// {
//      while (*line != '\0') {       /* if not the end of line ....... */ 
//           while (*line == ' ' || *line == '\t' || *line == '\n')
//               *line++ = '\0';     /* replace white spaces with 0    */
//           *argv++ = line;          /* save the argument position     */
//           while (*line != '\0' && *line != ' ' && 
//                  *line != '\t' && *line != '\n') 
//               line++;             /* skip the argument until ...    */
//      }
//      *argv = '\0';                 /* mark the end of argument list  */
// }

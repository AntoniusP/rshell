#include "Command.h"
#include <sys/stat.h>

// split word into tokens and put them in a vector of char*
void parse(string keyword, vector<char*> &wordList)
{
    char *cs = new char[keyword.length()];
    for (unsigned i = 0; i < keyword.length(); i++)
    {
        cs[i] = keyword[i];
    }
    cs[keyword.length()] = '\0';        //add the null terminator at the end of

    char *tokens = strtok(cs, " ");
    while (tokens) 
    {
        wordList.push_back(tokens);
        tokens = strtok(NULL, " ");
    }
}

int main() 
{
    string input;
    
    while (1)           // shell should run indefinitly unless exited 
    {  
        cout << "$ ";
        getline(cin, input);                        // get whole command line
        
        if(input == "exit") {
            exit(0);
            break;
        }
        
        vector<char*> words;
        parse(input, words);                      // parse whole word(strtok)
        
        vector<Command> commands;             // vector to store the list of commands
        for (unsigned i = 0; i < words.size(); i++)
        {
            char** args = new char*[words.size()];
            unsigned j = 0;
            char *sc  = (char*) memchr (words.at(i), ';', strlen(words.at(i)));
            char *And = (char*) memchr (words.at(i), '&', strlen(words.at(i)));
            char *Or  = (char*) memchr (words.at(i), '|', strlen(words.at(i)));
            char *com = (char*) memchr (words.at(i), '#', strlen(words.at(i)));
            
            if (com != NULL)
            {
                break;
            }
            else if (sc == NULL && Or == NULL && And == NULL)
            {
                args[j] = words.at(i);
            }
            else
            {
                string type;
                if (sc) { type = ";"; }
                else if (And) { type = "&&"; }
                else { type = "||"; }
                Command com;
                com.setCommand(args, type);
                commands.push_back(com);
            }
            j++;
        }
        
        
    
        // for(unsigned i = 0; i < commands.size(); i++)   //execute 
        // {
        //     if(commands.at(i).getArgs().getArgs()[0] == "exit")                 // exit case
        //     {
        //         exit(0);
        //     }
        //     commands.at(i).execute();  
        // }
        
        
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

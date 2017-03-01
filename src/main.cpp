#include "Command.h"
#include <sys/stat.h>
#include <stack>
#include <queue>

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
        
        if(input == "exit") 
        {
            exit(0);
            break;
        }
        vector<string> connectors;
        vector<Command> commands;
        vector<char*> words;
        // parse input with strtok
        parse(input, words);
        
        unsigned j = 0;
        for (unsigned i = 0; i < words.size(); i++)
        {
            char** args = new char*[words.size()];
            char *sc  = (char*) memchr (words.at(i), ';', strlen(words.at(i)));
            char *And = (char*) memchr (words.at(i), '&', strlen(words.at(i)));
            char *Or  = (char*) memchr (words.at(i), '|', strlen(words.at(i)));
            char *com = (char*) memchr (words.at(i), '#', strlen(words.at(i)));
            
            if ( (sc == NULL && Or == NULL && And == NULL) ) 
            {
                if ( (com == NULL) && (i == (words.size() - 1)) )
                {
                    args[j] = words.at(i);
                    Command com;
                    com.setCommand(args);
                    commands.push_back(com);
                }
                else if (com == NULL)
                {
                    args[j] = words.at(i);
                    j++;
                }
                else
                {
                    Command com;
                    com.setCommand(args);
                    commands.push_back(com);
                    break;
                }
            }
            else
            {
                j = 0;
                string type = "";
                if (sc)
                {
                    type = ";";
                    connectors.push_back(type);
                }
                else if (And)
                {
                    type = "&&";
                    connectors.push_back(type);
                }
                else 
                { 
                    type = "||";
                    connectors.push_back(type);
                }
                
                Command com;
                com.setCommand(args);
                commands.push_back(com);
            }
        }
        
        cout << "command vector size: " << commands.size() << endl;
        // add connectors to vector
        // take two commands and connect them 
        // push to stack 
        // take commands from stack and connect them
    }
    
    return 0;
}


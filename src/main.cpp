#include "Command.h"
#include "Or.h"
#include "And.h"
#include "Semicolon.h"

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
        
        
        vector<char*> words;
        parse(input, words);
        
        queue<string> connectors;
        vector<cmdComponent*> commands;
        
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
                    cout << "tokens" << endl;
                    args[j] = words.at(i);
                    Command* com = new Command();
                    com->setCommand(args);
                    commands.push_back(com);
                }
                else if (com == NULL)
                {
                    cout << "tokens" << endl;
                    args[j] = words.at(i);
                    j++;
                }
                else
                {
                    Command* com = new Command();
                    com->setCommand(args);
                    commands.push_back(com);
                    break;
                }
            }
            else
            {
                cout << "connector" << endl;
                j = 0;
                string type = "";
                if (sc)
                {
                    type = ";";
                    connectors.push(type);
                }
                else if (And)
                {
                    type = "&&";
                    connectors.push(type);
                }
                else 
                { 
                    type = "||";
                    connectors.push(type);
                }
                cout << "connector" << endl;
                //Command com;
                Command* com = new Command();
                com->setCommand(args);
                commands.push_back(com);
            }
        }
        
        cout << "command vector size: " << commands.size() << endl;
        stack<cmdComponent*> stack;
        
        for (unsigned i = commands.size() - 1; i <= 0; i--)
        {
            stack.push(commands.at(i));
        }
        
        cout << "Test4" << endl;
        while ((!connectors.empty()) && (!stack.empty()))
        {
                cmdComponent* tleft = stack.top();
                stack.pop();
                cmdComponent* tright = stack.top();
                stack.pop();
                
                cmdComponent* tmp;
                
                if (connectors.front() == ";")
                {
                    tmp = new Semicolon(tleft, tright);
                }
                else if (connectors.front() == "&&")
                {
                    tmp = new And(tleft, tright);
                }
                else
                {
                    tmp = new Or(tleft, tright);
                }
                stack.push(tmp);
        }
        
        cout << "execute test" << endl;
        // finally execute tree of commands
        stack.top()->execute();
        cout << "after ex" << endl;
        
    }
    
    return 0;
}


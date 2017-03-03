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

void copy(char** &arr, vector<char*>& v)
{
    v.push_back(NULL);
    arr = new char*[v.size()];
    for (unsigned i = 0; i < v.size(); i++)
    {
        arr[i] = v.at(i);
    }
}

int main() 
{
    string input;
    
    while (1)           // shell should run indefinitely unless exited 
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
        stack<Command*> commands;
        
        for (unsigned a = 0; a < words.size(); a++)
        {
            cout << words.at(a) << endl;    
        }
        
        vector<char*> argv;
        for (unsigned i = 0; i < words.size(); i++)
        {
            char *sc  = (char*) memchr (words.at(i), ';', strlen(words.at(i)));
            char *And = (char*) memchr (words.at(i), '&', strlen(words.at(i)));
            char *Or  = (char*) memchr (words.at(i), '|', strlen(words.at(i)));
            char *com = (char*) memchr (words.at(i), '#', strlen(words.at(i)));
            
            
            if ( (sc == NULL && Or == NULL && And == NULL) ) 
            {
                if ( (com == NULL) && (i == (words.size() - 1)) )
                {
                    argv.push_back(words.at(i));
                    char** args;
                    copy(args, argv);
                    Command* com = new Command();
                    com->setCommand(args);
                    commands.push(com);
                    argv.clear();
                }
                else if (com == NULL)
                {
                    argv.push_back(words.at(i));
                }
                else
                {
                    char** args;
                    copy(args, argv);
                    Command* com = new Command();
                    com->setCommand(args);
                    commands.push(com);
                    argv.clear();
                    break;
                } 
            }
            else
            {
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
                
                char** args;
                copy(args, argv);
                Command* com = new Command();
                com->setCommand(args);
                commands.push(com);
                argv.clear();
            }
        }
        
        if ((commands.size() > connectors.size()) && !commands.empty())
        {
            cout << "command queue size: " << commands.size() << endl;
            stack<cmdComponent*> stack;
            
            while (!commands.empty())
            {
                cout << "pushing command -> " << commands.top()->getArgs()[0];
                
                stack.push(commands.top());
                commands.pop();
                cout << " -stack size now: " << stack.size() << endl; 
            }
            
            cout <<"stack size before tree:" << stack.size() << endl;
            cout << "creating ex tree..." << endl;
            while ((!connectors.empty()) && !stack.empty())
            {
                cmdComponent* tleft = stack.top();
                stack.pop();
                cmdComponent* tright = stack.top();
                stack.pop();
                
                cmdComponent* tmp;
                
                if (connectors.front() == ";")
                {
                    cout << "made ';' connector" << endl;
                    tmp = new Semicolon(tleft, tright);
                }
                else if (connectors.front() == "&&")
                {
                    cout << "made '&&' connector" << endl;
                    tmp = new And(tleft, tright);
                }
                else
                {
                    cout << "made '||' connector" << endl;
                    tmp = new Or(tleft, tright);
                }
                stack.push(tmp);
                connectors.pop();
            }
            
            cout << "before ex" << endl;
            // finally execute tree of commands
            cout << "stack size: " << stack.size() << endl;
            if (!stack.empty())
            {
                stack.top()->execute();
            }
            
        }
        else
        {
            perror("Input error");
        }
        
    }
    
    return 0;
}


#include "Command.h"
#include "Test.h"
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
        stack<cmdComponent*> commands;
        
        // for (unsigned a = 0; a < words.size(); a++)
        // {
        //     cout << words.at(a) << endl;    
        // }
        
        //break up the vector of words into commands
        //strcmp(args[0], "test") || strcmp(args[0], "[")
        //(argv.at(0) == "test") || (argv.at(0) == "[")
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
                    if((string(argv.at(0)) == "test") || (string(argv.at(0)) == "["))
                    {
                        Test* tst = new Test();
                        tst->setTest(args);
                        commands.push(tst);
                    }
                    else
                    {
                        Command* com = new Command();
                        com->setCommand(args);
                        commands.push(com);
                    }
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
                    if((string(argv.at(0)) == "test") || (string(argv.at(0)) == "["))
                    {
                        Test* tst = new Test();
                        tst->setTest(args);
                        commands.push(tst);
                    }
                    else
                    {
                        Command* com = new Command();
                        com->setCommand(args);
                        commands.push(com);
                    }
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
                if((string(argv.at(0)) == "test") || (string(argv.at(0)) == "["))
                {
                    Test* tst = new Test();
                    tst->setTest(args);
                    commands.push(tst);
                }
                else
                {
                    Command* com = new Command();
                    com->setCommand(args);
                    commands.push(com);
                }
                argv.clear();
            }
        }
        
        //cout << "commands size:" << commands.size() << endl;
        //set up the command tree
        if (commands.size() > connectors.size())
        {
            //cout << "command queue size: " << commands.size() << endl;
            stack<cmdComponent*> stack;
            
            while (!commands.empty())
            {
                stack.push(commands.top());
                commands.pop();
            }
            
            //cout <<"stack size before tree:" << stack.size() << endl;
            while ((!connectors.empty()) && !stack.empty())
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
                connectors.pop();
            }
            
            // finally execute tree of commands
            if (!stack.empty())
            {
                stack.top()->execute();
            }
            
        }
        else
        {
            if (commands.size() == 0)
            {
                
            }
            else
            {
                cout << "Error: Invalid input" << endl;
            }
        }
        
    }
    
    return 0;
}


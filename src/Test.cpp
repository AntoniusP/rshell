#include "Test.h"

Test::Test() 
{
    
}

Test::~Test()
{
    delete[] Args;    
}

void Test::setTest(char** a) 
{
    Args = a;
}

bool Test::execute(int in, int out) 
{
    struct stat buf;
    vector<string> v;
    string flag = "";
    string path = "";
    
    //cout << "inside Test::execute()" << endl;
    int i = 0;
    while (Args[i] != NULL)
    {
        v.push_back(string(Args[i]));
        i++;
    }
    
    if (dup2(out, 1) < 0)
    {
        perror("ERROR: dup2out");
        return false;
    }
    
    // set flag and path
    if (v.at(0) == "test")
    {
        if ((v.size() > 3) || (v.size() <= 1))
        {
            flag = ""; 
        }
        else if (v.size() == 2)
        {
            flag = "-e";
            path = v.at(1);
        }
        else if (v.at(1) == "-e")
        {
            flag = "-e";
            path = v.at(2);
        }
        else if (v.at(1) == "-f")
        {
            flag ="-f";
            path = v.at(2);
        }
        else if (v.at(1) == "-d")
        {
            flag = "-d";
            path = v.at(2);
        }
        else
        {
            flag = "";
        }
    }
    else
    {
        if ((v.size() > 4) || (v.size() <= 2))
        {
            flag == "";
        }
        else if (v.size() == 3)
        {
            if (v.at(2) == "]")
            {
                flag = "-e";
                path = v.at(1);
            }
        }
        else 
        {
            if (v.at(3) == "]")
            {
                if (v.at(1) == "-e")
                {
                    flag = "-e";
                    path = v.at(2);
                }
                else if (v.at(1) == "-f")
                {
                    flag ="-f";
                    path = v.at(2);
                }
                else if (v.at(1) == "-d")
                {
                    flag = "-d";
                    path = v.at(2);
                }
                else
                {
                    flag = "";
                }
            }
        }
    }
    
    //get buf
    stat(path.c_str(), &buf);
    
    if (flag == "-e")
    {
        if (S_ISREG(buf.st_mode) || S_ISDIR(buf.st_mode))
        {
            cout << "(True)" << endl;
            return true;
        }
        else
        {
            cout << "(False)" << endl;
            return false;
        }
    }
    else if (flag == "-f")   
    {
        if (S_ISREG(buf.st_mode)) 
        {
            cout << "(True)" << endl;
            return true;
        }
        else
        {
            cout << "(False)" << endl;
            return false;
        }
    }
    else if (flag == "-d")
    {
        if (S_ISDIR(buf.st_mode))
        {
            cout << "(True)" << endl;
            return true;
        }
        else
        {
            cout << "(False)" << endl;
            return false;
        }
    }
    else 
    {
        cout << "Error: invalid test" << endl;
        return false;
    }
}
#ifndef CMDCOMPONENT_H
#define CMDCOMPONENT_H

#include <unistd.h>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

class cmdComponent {
    protected:
    string keyword;
    
    public:
    cmdComponent() : keyword("") {}
    cmdComponent(string s) : keyword(s) {}
    void parse(vector<char*> &wordList);
    bool is_connector();
    string getWord();
};

#endif
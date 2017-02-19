#include "cmdComponent.h"


void cmdComponent::parse(vector<char*> &wordList)
{
    char *cs = new char[keyword.length()];
    for (unsigned index = 0; index < keyword.length(); index++)
    {
        cs[index] = keyword[index];
    }
    cs[keyword.length()] = '\0';        //add the null terminator at the end of

    char *tokens = strtok(cs, " ");
    while (tokens) 
    {
        wordList.push_back(tokens);
        tokens = strtok(NULL, " ");
    }
}

bool cmdComponent::is_connector(){
    if(keyword=="||" || keyword=="&&" || keyword == ";") return true;
    else return false;
}

string cmdComponent::getWord(){
    return keyword;
}
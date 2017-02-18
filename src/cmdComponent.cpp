#include "cmdComponent.h"

    bool isParsed(){
        return (keyword.find_first_of(" \&;")==-1);
    }
    void parse(){
        return keyword;
    }
    bool is_connector(){
        if(keyword=="||" || keyword=="&&" || keyword == ";") return true;
        else return false;
    }
    string getWord(){
        return keyword;
    }
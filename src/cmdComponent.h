#ifndef CMDCOMPONENT_H
#define CMDCOMPONENT_H

class cmdComponent {
    public:
    
    string keyword;
    bool isParsed();
    void parse();
    bool is_connector();
    string getWord();
}

#endif
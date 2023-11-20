#include "Value.h"
#ifndef CPPJSONPARSER_KEYWORD_H
#define CPPJSONPARSER_KEYWORD_H

enum valType {
    TRUE, FALSE, NULLVAL
};

class Keyword : public Value {
public:
    valType type;
    Keyword(string s){
        if(s.compare("true")){
            type = TRUE;
        }
        else if(s.compare("false")){
            type = FALSE;
        }
        else{
            type = NULLVAL;
        }
    }
};


#endif //CPPJSONPARSER_KEYWORD_H

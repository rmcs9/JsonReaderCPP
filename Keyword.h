#include "Value.h"
#include "Lexer.h"
#ifndef CPPJSONPARSER_KEYWORD_H
#define CPPJSONPARSER_KEYWORD_H


class Keyword : public Value {
public:
     segmentType type;
    Keyword(segmentType s){
        type = s;
    }
    string getType() override {
        if(type == TRUE){
            return "true";
        }
        else if(type == FALSE){
            return "false";
        }
        else{
            return "null";
        }
    };
};

#endif //CPPJSONPARSER_KEYWORD_H

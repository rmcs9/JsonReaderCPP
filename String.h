#include "Value.h"
#ifndef CPPJSONPARSER_STRING_H
#define CPPJSONPARSER_STRING_H


class String : public Value {
public:
    string value;
    String(string s){
        value = s;
    }
    string getType() override {
        return "string";
    };
};


#endif //CPPJSONPARSER_STRING_H

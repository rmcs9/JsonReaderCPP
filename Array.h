
#ifndef CPPJSONPARSER_ARRAY_H
#define CPPJSONPARSER_ARRAY_H


#include "Value.h"

class Array : public Value{
public:
    vector<unique_ptr<Value>> arrayContents;
    string getType() override {
        return "array";
    };
};


#endif //CPPJSONPARSER_ARRAY_H

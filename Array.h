
#ifndef CPPJSONPARSER_ARRAY_H
#define CPPJSONPARSER_ARRAY_H


#include "Value.h"

class Array : public Value{
public:
    vector<Value> arrayContents;
};


#endif //CPPJSONPARSER_ARRAY_H

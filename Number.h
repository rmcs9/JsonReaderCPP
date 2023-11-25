#include "Value.h"
#ifndef CPPJSONPARSER_NUMBER_H
#define CPPJSONPARSER_NUMBER_H


class Number : public Value{
public:
    double value;
    Number(double n){
        value = n;
    }
    string getType() override {
        return "number";
    };
};


#endif //CPPJSONPARSER_NUMBER_H

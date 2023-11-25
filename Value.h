#include <string>
using namespace std;

#ifndef CPPJSONPARSER_VALUE_H
#define CPPJSONPARSER_VALUE_H


class Value {
public:
    virtual string getType(){
        return "value";
    }
};


#endif //CPPJSONPARSER_VALUE_H

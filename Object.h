#include "Value.h"
#include "String.h"
#ifndef CPPJSONPARSER_OBJECT_H
#define CPPJSONPARSER_OBJECT_H


class Object : public Value{
public:
   unordered_map<string, unique_ptr<Value>> objectContents;
   string getType() override {
       return "object";
   };
};



#endif //CPPJSONPARSER_OBJECT_H

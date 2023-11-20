#include "Value.h"
#ifndef CPPJSONPARSER_OBJECT_H
#define CPPJSONPARSER_OBJECT_H


class Object : public Value{
public:
   unordered_map<string, Value> objectContents;
};


#endif //CPPJSONPARSER_OBJECT_H

#include "Lexer.h"
#include "Value.h"
#include "Object.h"
#include "Array.h"
#include "String.h"
#include "Number.h"
#include "Keyword.h"

#ifndef CPPJSONPARSER_PARSER_H
#define CPPJSONPARSER_PARSER_H


class Parser {
public:
    Parser(vector<segment> lexed){
        segments = lexed;
        current = segments.begin();
    }
    unique_ptr<Value> json;
    void parse();
private:
    vector<segment> segments;
    vector<segment>::iterator current;
    unique_ptr<Value> parseValue();
    unique_ptr<Object> parseObject();
    unique_ptr<Array> parseArray();
    unique_ptr<String> parseString();
    unique_ptr<Number> parseNumber();
    unique_ptr<Keyword> parseKeyword();
};


#endif CPPJSONPARSER_PARSER_H

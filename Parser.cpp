#include "Parser.h"
#include "Lexer.h"
#include "Value.h"
#include "Object.h"
#include "Array.h"
#include "String.h"
#include "Number.h"
#include "Keyword.h"



unique_ptr<Keyword> Parser::parseKeyword() {
    if(current->type != TRUE
    && current->type != FALSE
    && current->type != NULLKEYWORD){
        throw runtime_error("unexpected segment found at line " + current->linenum);
    }

    auto k = make_unique<Keyword>(current->type);
    current++;
    return k;
}

unique_ptr<Number> Parser::parseNumber() {
    double val;
    try {
        val = stod(current->value);
    }
    catch(std::invalid_argument e){
        throw e;
    }
    auto n = make_unique<Number>(val);
    current++;
    return n;
}

unique_ptr<String> Parser::parseString(){
    auto s = make_unique<String>(current->value);
    current++;
    return s;
}

unique_ptr<Array> Parser::parseArray() {
    auto arr = make_unique<Array>();
    //dispose of the open bracket
    current++;
    while(current->type != RBRACKET){
       arr->arrayContents.push_back(std::move(parseValue()));
       if(current->type == COMMA){
            current++;
            if(current->type == RBRACKET){
                throw runtime_error("comma found with no following element in array declaration at line " + current->linenum);
            }
       }
    }
    //dispose of closing bracket
    current++;
    return arr;
}

unique_ptr<Object> Parser::parseObject() {
    auto obj = make_unique<Object>();
    string key;
    //dispose of the open bracket
    current++;
    //loop while we are not at the end of this object
    while(current->type != RBRACE){
        //perform the key value gathering sequence
        if(current->type != LITERAL){
            throw runtime_error("key expected in object definition at line " + current->linenum);
        }
        key = current->value;
        current++;
        if(current->type != COLON){
            throw runtime_error("colon expected after key definition in object at line " + current->linenum);
        }
        current++;
        unique_ptr<Value> subval = parseValue();
        obj->objectContents[key] = std::move(subval);
        //current++;
        //ensure that the key value pairs are comma seperated
        if(current->type == COMMA){
           current++;
           if(current->type == RBRACE){
               throw runtime_error("comma found with no following element found in object definition at line " + current->linenum);
           }
        }
    }
    //dispose of the closing brace
    current++;
    return obj;
}

unique_ptr<Value> Parser::parseValue(){
    if(current->type == LBRACE){
        return parseObject();
    }
    else if(current->type == LBRACKET){
        return parseArray();
    }
    else if(current->type == LITERAL){
        return parseString();
    }
    else if(current->type == NUMBER){
        return parseNumber();
    }
    else{
        return parseKeyword();
    }
}

void Parser::parse(){
   json = std::move(parseValue());
}


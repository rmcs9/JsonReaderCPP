//
// Created by Ryan McSweeney on 11/19/23.
//
#include <string>

using namespace std;

#ifndef CPPJSONPARSER_LEXER_H
#define CPPJSONPARSER_LEXER_H




enum segmentType{LBRACE, RBRACE, LBRACKET, RBRACKET, LITERAL, COMMA, COLON, TRUE, FALSE, NULLKEYWORD, NUMBER,};

struct segment{
    string value;
    segmentType type;
    int linenum;
};

class Lexer {
private:
    string filestring;
    int currentInd;
    int linenum;
    unordered_map<string, segmentType> knownWords;
    segment processLiteral();
    segment processOther();

public:
    Lexer(string fp);
    vector<segment> lex();
    vector<segment> seglist;
};

#endif CPPJSONPARSER_LEXER_H

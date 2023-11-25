#include <iostream>
#include <fstream>
#include "Lexer.h"
#include "Parser.h"

using namespace std;

//https://www.json.org/json-en.html

int main() {
    Lexer lex("../testfile.json");

    Parser parse(lex.seglist);
    parse.parse();

    cout << parse.json->getType();
}
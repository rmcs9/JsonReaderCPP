#include <iostream>
#include <fstream>
#include "Lexer.h"

using namespace std;

//https://www.json.org/json-en.html

int main() {
    Lexer lex("../testfile.json");
    lex.seglist;

}
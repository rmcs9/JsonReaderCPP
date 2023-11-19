#include "Lexer.h"
#include <fstream>


/*
 * Constructor for a lexer
 * sets the filepath
 * also sets the mappings for the known word values
 */
Lexer::Lexer(string fp) {
    knownWords["true"] = TRUE;
    knownWords["false"] = FALSE;
    knownWords["null"] = NULLKEYWORD;

    ifstream file(fp);

    filestring = "";
    string linestring;
    while(getline(file, linestring)){
        filestring += linestring + "\n";
    }

    currentInd = 0;
    linenum = 1;
    file.close();

    seglist = this->lex();
}

/*
 * function for processing string literals in a json file
 */
segment Lexer::processLiteral(){
    string accum = "";
    currentInd++;

    while(filestring[currentInd] != '"' && filestring[currentInd] != '\0'){
        accum += filestring[currentInd];
        currentInd++;
    }
    //increment the closing double quote
    currentInd++;

    //creates a new segment struct for the literal
    segment literal;
    literal.value = accum;
    literal.type = LITERAL;
    literal.linenum = linenum;


    return literal;
}

segment Lexer::processOther(){
    string accum = "";
    segment seg;

    while(filestring[currentInd] != ','
          && filestring[currentInd] != ' '
          && filestring[currentInd] != '\n'
          && filestring[currentInd] != '\0'){
        accum += filestring[currentInd];
        currentInd++;
    }

    if(knownWords[accum] != NULL){
        seg.value = "";
        seg.type = knownWords[accum];
        seg.linenum = linenum;
    }
    else{
        seg.value = accum;
        seg.type = NUMBER;
        seg.linenum = linenum;
    }

    return seg;
}

/*
 * main lex function for the lexer
 * reads from the file at filepath and creates a new list of segments
 */
vector<segment> Lexer::lex() {
    vector<segment> segList;
    int lineNum = 1; //todo fix this

    while(currentInd < filestring.length() && filestring[currentInd] != '\0'){
        segment currentSeg;
        switch(filestring[currentInd]){
            case '{':
                currentSeg.value ="";
                currentSeg.type = LBRACE;
                currentSeg.linenum = lineNum;
                currentInd++;
                break;
            case '}':
                currentSeg.value ="";
                currentSeg.type = RBRACE;
                currentSeg.linenum = lineNum;
                currentInd++;
                break;
            case '[':
                currentSeg.value ="";
                currentSeg.type = LBRACKET;
                currentSeg.linenum = lineNum;
                currentInd++;
                break;
            case ']':
                currentSeg.value ="";
                currentSeg.type = RBRACKET;
                currentSeg.linenum = lineNum;
                currentInd++;
                break;
            case ',':
                currentSeg.value ="";
                currentSeg.type = COMMA;
                currentSeg.linenum = lineNum;
                currentInd++;
                break;
            case ':':
                currentSeg.value ="";
                currentSeg.type = COLON;
                currentSeg.linenum = lineNum;
                currentInd++;
                break;
            case '\n':
                lineNum++;
                currentInd++;
                continue;
            case ' ':
                currentInd++;
                continue;
            case '"':
                currentSeg = processLiteral();
                break;
            default:
               currentSeg = processOther();
               break;
        }
        segList.push_back(currentSeg);
    }
    return segList;
}





#include <iostream>

#include "tokenSys.hpp"

char* typeToString(TokenType t){
    switch(t){
        case alph_number: return "number";
        case alph_string: return "string";
        case alph_command: return "string";
        case alph_variable: return "string";
        case alph_marker: return "string";
        case alph_undefined: return "string";
        default: return "undefined";
    }
}

void printToken(Token t){
    std::cout << "Token[type=" << typeToString(t.type) << ", value=" << t.value << "]";
}
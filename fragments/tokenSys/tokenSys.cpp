#include <iostream>

#include "tokenSys.hpp"

/*
 * 2 constructor functions for the Token struct
 * so a Token can be defined using nothing wich will create a
 * empty Token
 *
 * and a another one so Token can be defined with a char* representing
 * the value it will get
 */
Token::Token(){
    this->value = "";
    this->type = alph_undefined;
}

Token::Token(std::string str){
    this->value = str;
    this->type = alph_undefined;
}


/*
 * typeToString is a function that transforms a TokenType in a
 * string representation of that type, so it can be printed to the console
 */
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

/*
 * printToken is a function that can be used to print the value
 * type pair of a token to the console in a neat template
 */
void printToken(Token t){
    std::cout << "Token[type=" << typeToString(t.type) << ", value=" << t.value << "]\n";
}
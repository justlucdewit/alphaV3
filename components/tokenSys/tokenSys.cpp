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
    value = "";
    type = alph_undefined;
}

Token::Token(std::string str){
    value = str;
    type = alph_undefined;
}


/*
 * typeToString is a function that transforms a TokenType in a
 * string representation of that type, so it can be printed to the console
 */
const char* typeToString(alph_TokenType t){
    switch(t){
        case alph_number: return "number";
        case alph_string: return "string";
        case alph_command: return "command";
        case alph_variable: return "variable";
        case alph_marker: return "marker";
        case alph_undefined: return "undefined";
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

/*
 * function to turn a abstractly named type from acconfig into
 * a TokenType
 */
alph_TokenType typeConvert(std::string s){
    if (s == "var") return alph_variable;
    if (s == "str") return alph_string;
    if (s == "num") return alph_number;
    if (s == "mark") return alph_marker;
    return alph_undefined;
}
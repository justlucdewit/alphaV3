#pragma once

/*
 * TokenType is typed enumeration that keeps track
 * of what type a token is, this is only used for checking
 * what type a token is, and inside the Token struct
 */
typedef enum TokenType : unsigned char
{
    alph_number,
    alph_string,
    alph_command,
    alph_variable,
    alph_marker,
    alph_undefined
}TokenType;

/*
 * Token is a struct, that stores all of the value type pairs
 * that the token splitter produces, that list of tokens will then
 * be passed to the interpreter which then runs the code
 */
struct Token
{
    std::string value;
    TokenType type;
    Token();
    Token(std::string);
};

void printToken(Token);
char* typeToString(TokenType);
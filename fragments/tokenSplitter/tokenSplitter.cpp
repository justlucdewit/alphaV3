#include "tokenSplitter.hpp"

std::vector<Token> tokenSplitter(std::string sourceCode)
{
    /*
     * isEmpty is a small lambda, used for checking if
     * a character can be considered empty, and can thereby split a word
     */


    auto CharIsEmpty = [](const char c) -> bool
    {
        return c==' '||c=='\t'||c=='\n';
    };


    std::vector<Token> tokens;
    std::string tempstring;
    char stringMode = 0;

    for (int i = 0; i<sourceCode.size(); i++)
    {
        const char c = sourceCode[i];

        if (stringMode){

        }else {
            if (CharIsEmpty(c)) {
                if (!tempstring.empty() && !stringMode) {
                    tokens.push_back(Token(tempstring));
                    tempstring = "";
                }
            } else {
                tempstring += c;
            }
        }
    }

    if (!tempstring.empty()){
        tokens.push_back(Token(tempstring));
        tempstring = "";
    }

    return tokens;
}
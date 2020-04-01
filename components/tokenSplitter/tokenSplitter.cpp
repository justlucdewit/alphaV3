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
    bool commentMode = false;
    char stringMode = 0;
    char lastChar = 0;
    int lineNr = 1;

    for (unsigned int i = 0; i<sourceCode.size(); i++)
    {
        const char c = sourceCode[i];
        if (c == '\n'){
            lineNr++;
        }

        if (stringMode == 2){
            if (c == '"' && lastChar != '\\'){
                stringMode = 0;
            }
            tempstring += c;
        }else if(stringMode == 1){
            if (c == '\'' && lastChar != '\\'){
                stringMode = 0;
            }
            tempstring += c;
        }else{

            if (commentMode){
                if (c == '\n'){
                    commentMode = false;
                }
            }else {
                if (c == '#') {
                    commentMode = true;

                    if (tempstring != "") {
                        Token newToken = Token(tempstring);
                        newToken.lineFound = lineNr;
                        tokens.push_back(newToken);
                        tempstring = "";
                    }

                    continue;
                }

                if (c == '"') {
                    stringMode = 2;
                    tempstring += c;
                } else if (c == '\'') {
                    stringMode = 1;
                    tempstring += c;
                } else if (CharIsEmpty(c)) {
                    if (tempstring != "") {
                        Token newToken = Token(tempstring);
                        newToken.lineFound = lineNr;
                        tokens.push_back(newToken);
                        tempstring = "";
                    }
                } else {
                    tempstring += c;
                }
            }
        }

        lastChar = c;
    }

    if (!tempstring.empty()){
        tokens.push_back(Token(tempstring));
        tempstring = "";
    }

    return tokens;
}
#include "validator.hpp"
void validate(std::vector<Token> tokens, std::map<std::string, std::vector<std::vector<TokenType>>> argData)
{
    int i = 0;
    while (i < tokens.size()-1)
    {
        Token command = tokens[i];
        std::vector<Token> arguments;
        i++;
        while(tokens[i].type != alph_command && i < tokens.size()-1){
            arguments.push_back(tokens[i]);
            i++;
        }

        std::cout << "arguments found: " << arguments.size() << "\n";
    }
}
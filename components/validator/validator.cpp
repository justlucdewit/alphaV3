#include "validator.hpp"

void validate(std::vector<Token>& tokens, std::map<std::string, std::vector<std::vector<alph_TokenType>>> argData)
{
    unsigned int i = 0;
    while (i < tokens.size()-1)
    {
        Token& command = tokens[i];

        i++;
        while(i < tokens.size() && tokens[i].type != alph_command) {
            command.arguments.push_back(tokens[i++]);
        }

        // check argument count
        if (command.arguments.size() != argData[command.value].size()){
            std::string errorMsg;
            if (command.arguments.size() > argData[command.value].size()) {
                errorMsg += "[ERROR 100] command \"";
                errorMsg += command.value += "\", on line ";
                errorMsg += std::to_string(command.lineFound) += " has too many arguments";
            }else{
                errorMsg += "[ERROR 101] command \"";
                errorMsg += command.value += "\" on line ";
                errorMsg += std::to_string(command.lineFound) += " has too few arguments";
            }
            throwError(errorMsg);
        }

        // check argument type
        int argi = 0;
        for (const auto arg : command.arguments){
            std::vector<alph_TokenType> allowedArgs = argData[command.value][argi++];
            if (std::find(allowedArgs.begin(), allowedArgs.end(), arg.type) == allowedArgs.end()){
                std::string errorMsg;
                errorMsg += "[ERROR 102] argument of type ";
                errorMsg += typeToString(arg.type);
                if (argi == 1){
                    errorMsg += " isnt allowed as 1st argument of command ";
                }else if (argi == 2){
                    errorMsg += " isnt allowed as 2nd argument of command ";
                }else if(argi == 3){
                    errorMsg += " isnt allowed as 3rd argument of command ";
                }else{
                    errorMsg += " isnt allowed as ";
                    errorMsg += std::to_string(argi) += "th";
                    errorMsg += " argument of command ";
                }

                errorMsg += command.value;

                throwError(errorMsg);
            }
        }
    }
}
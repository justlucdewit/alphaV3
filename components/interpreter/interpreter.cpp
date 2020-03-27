#include "interpreter.hpp"

void interpret(std::vector<Token> tokens, std::map<std::string, std::function<void(ARGUMENTS)>> functions, std::map<std::string, int> markerMemory){
    unsigned int lineNumber = 0;
    while (lineNumber < tokens.size()-1){

        Token command = tokens[lineNumber];
        lineNumber += 1+command.arguments.size();

        functions[command.value](command.arguments, lineNumber, markerMemory);
    }
    std::exit(0);
}
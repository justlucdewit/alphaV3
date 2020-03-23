#include "interpreter.hpp"

void interpret(std::vector<Token> tokens, std::map<std::string, std::function<void(ARGUMENTS)>> functions, std::map<std::string, int> markerMemory){
    unsigned int lineNumber = 0;
    while (lineNumber < tokens.size()-1){
        Token command = tokens[lineNumber];

        std::vector<Token> arguments;
        lineNumber++;

        while(lineNumber < tokens.size() && tokens[lineNumber].type != alph_command)
            arguments.push_back(tokens[lineNumber++]);

        functions[command.value](arguments, lineNumber, markerMemory);
    }
}
#include "compiler.hpp"

void compile(std::vector<Token>& tokens, std::string& exeName){
    std::ofstream compiledFile;
    compiledFile.open(exeName);

    unsigned int i = 0;
    while(i < tokens.size() -1){
        Token& command = tokens[i];
        std::vector<Token> arguments;
        i++;
        while(i < tokens.size() && tokens[i].type != alph_command && tokens[i].type != alph_marker) {
            arguments.push_back(tokens[i++]);
        }

        if (command.value == "let"){
        }
    }

    compiledFile.close();
    std::cout << "compilation completed";
}
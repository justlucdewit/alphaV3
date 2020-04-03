#include "compiler.hpp"

void compile(std::vector<Token>& tokens, std::string& exeName){
    std::ofstream compiledFile;
    compiledFile.open(exeName);
    compiledFile << "// this code is automaticly generated\n// by the alpha engine\n#include <stdio.h>\n\nint main(){\n";

    unsigned int i = 0;
    while(i < tokens.size() -1){
        Token& command = tokens[i];
        std::vector<Token> arguments;
        i++;
        while(i < tokens.size() && tokens[i].type != alph_command && tokens[i].type != alph_marker) {
            arguments.push_back(tokens[i++]);
        }

        if (command.type == alph_marker) {
            command.value.erase(0, 1);
            compiledFile << "\t" << command.value << ": ;\n";
        }else if (command.value == "print"){
            if(arguments[0].type == alph_string){
                compiledFile << "\tfputs(\"" << arguments[0].value << "\",stdout);\n";
            }
        }else if (command.value == "goto"){
            compiledFile << "\tgoto " << arguments[0].value << ";\n";
        }else if (command.value == "let"){
            if (arguments[1].type == alph_string){
                compiledFile << "\tchar " << arguments[0].value << "[] = \"" << arguments[1].value << "\";\n";
            }else if(arguments[1].type == alph_number){
                compiledFile << "\tdouble " << arguments[0].value << " = " << arguments[1].value << ";\n";
            }
        }else{
            std::cout << "[ERROR] cannot compile " << command.value << " command it is currently unsupported by the alpha compiler";
        }
    }

    compiledFile << "\treturn 0;\n}";
    compiledFile.close();
    std::cout << "compilation completed";
}
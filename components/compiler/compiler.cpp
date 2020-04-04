#include "compiler.hpp"

bool isInteger(std::string num){
    if (num.find('.') == std::string::npos)
        return true;
    return false;
}

// this function will take any int literal and give their aasm code as
// long as the int is less then 2147483648
std::string compileInt(std::string n){
    char newCode[10];
    if (std::stoul(n) >= 2147483648){
        std::cout << "[ERROR] cannot compile int literal bigger then 2147483647";
        std::exit(1);
    }
    std::sprintf(newCode, "%07X", std::stoi(n));
    std::string ret = newCode;
    ret = "0x0" + ret;
    return ret;
}

void compile(std::vector<Token>& tokens, std::string& exeName){
    std::ofstream compiledFile;
    compiledFile.open(exeName);

    unsigned int i = 0;
    unsigned int opcodes = 0;
    while(i < tokens.size() -1){
        Token& command = tokens[i];
        std::vector<Token> arguments;
        i++;
        while(i < tokens.size() && tokens[i].type != alph_command && tokens[i].type != alph_marker) {
            arguments.push_back(tokens[i++]);
        }

        if (command.value == "let"){
            if (arguments[1].type == alph_number && isInteger(arguments[1].value)){
                compiledFile << compileInt(arguments[1].value) << " ";
                opcodes++;
            }else{
                continue;
            }
        }else{
            continue;
        }

        if (opcodes % 4 == 0){
            compiledFile << "\n";
        }
    }

    compiledFile << "0x40000000";
    compiledFile.close();
    std::cout << "compilation completed";
}
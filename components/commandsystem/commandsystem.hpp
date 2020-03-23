#pragma once

#include <vector>
#include <functional>
#include <map>
#include <iostream>
#include <string>

#include "../tokenSys/tokenSys.hpp"

#define ARGUMENTS std::vector<Token> arguments, unsigned int& lineNumber, std::map<std::string, int> markerMemory

std::map<std::string, std::vector<std::vector<alph_TokenType>>> argData;// list of arguments used by commands


std::map<std::string, std::function<void(ARGUMENTS)>> functions;

void initCommands(){
    argData["print"] = {{alph_number, alph_string, alph_variable}};
    argData["goto"] = {{alph_marker}};

    functions["print"] = [](ARGUMENTS){
        if (arguments[0].type == alph_string || arguments[0].type == alph_variable){
            std::cout << arguments[0].value;
        }
    };

    functions["goto"] = [](ARGUMENTS){
        lineNumber = markerMemory[arguments[0].value];
    };
}
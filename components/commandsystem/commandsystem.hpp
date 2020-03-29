#pragma once

#include <vector>
#include <functional>
#include <map>
#include <iostream>
#include <string>

#include "../tokenSys/tokenSys.hpp"
#include "../variableSystem/variableSyste.hpp"
#include "../errorSys/errorSys.hpp"

#define ARGUMENTS const std::vector<Token>& arguments, unsigned int& lineNumber, std::map<std::string, int>& markerMemory

std::map<std::string, std::vector<std::vector<alph_TokenType>>> argData;// list of arguments used by commands
std::map<std::string, Var> memory;

std::map<std::string, std::function<void(ARGUMENTS)>> functions;

void testVar(const std::string s){
    if(!memory.count(s)){
        std::string errorMsg =  "undefined variable ";
        errorMsg+=s;
        throwError(errorMsg);
    }
}

void initCommands(){
    argData["more"] = {{alph_variable}};
    argData["print"] = {{alph_number, alph_string, alph_variable}};
    argData["let"] = {{alph_variable},{alph_number, alph_string, alph_variable}};
    argData["less"] = {{alph_variable}};
    argData["goto"] = {{alph_marker}};

    functions["print"] = [](ARGUMENTS){
        if (arguments[0].type == alph_string || arguments[0].type == alph_number){
            std::cout << arguments[0].value << std::flush;
        }else{//its a variable
            testVar(arguments[0].value);
            if (memory[arguments[0].value].isNum){
                std::cout << memory[arguments[0].value].numVal << std::flush;
            }else{
                std::cout << memory[arguments[0].value].strVal << std::flush;
            }
        }
    };

    functions["goto"] = [](ARGUMENTS){
        lineNumber = markerMemory[arguments[0].value];
    };

    functions["let"] = [](ARGUMENTS){
        Var newvar;
        if (arguments[1].type == alph_number){
            newvar.numVal = std::stod(arguments[1].value);
            newvar.isNum = true;
            memory[arguments[0].value] = newvar;
        }else if (arguments[1].type == alph_string){
            newvar.strVal = arguments[1].value;
            newvar.isNum = false;
            memory[arguments[0].value] = newvar;
        }else if (arguments[1].type == alph_variable){
            testVar(arguments[1].value);
            if (memory[arguments[1].value].isNum){
                newvar.isNum = true;
                newvar.numVal = memory[arguments[1].value].numVal;
            }else{
                newvar.isNum = false;
                newvar.strVal = memory[arguments[1].value].strVal;
            }
            memory[arguments[0].value] = newvar;
        }
    };

    functions["more"] = [](ARGUMENTS){
        testVar(arguments[0].value);

        if (memory[arguments[0].value].isNum)
            memory[arguments[0].value].numVal++;
        else
            std::cout << "error[400] can not increment string value";
    };

    functions["less"] = [](ARGUMENTS){
        testVar(arguments[0].value);

        if (memory[arguments[0].value].isNum)
            memory[arguments[0].value].numVal--;
        else
            std::cout << "error[400] can not increment string value";
    };
}
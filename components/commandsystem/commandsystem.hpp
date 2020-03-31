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

void testVar(const std::string string, std::map<std::string, Var>& memory){
    if(!memory.count(string)){
        std::string errorMsg =  "[ERROR] undefined variable ";
        errorMsg+=string;
        throwError(errorMsg);
    }
}

void testMark(const std::string string, std::map<std::string, int>& markerMemory){
    if(!markerMemory.count(string)){
        std::string errorMsg =  "[ERROR] undefined marker ";
        errorMsg+=string;
        throwError(errorMsg);
    }
}

void initCommands(){
    argData["more"] = {{alph_variable}};
    argData["print"] = {{alph_number, alph_string, alph_variable}};
    argData["let"] = {{alph_variable},{alph_number, alph_string, alph_variable}};
    argData["less"] = {{alph_variable}};
    argData["exit"] = {{alph_number, alph_variable}};
    argData["goto"] = {{alph_variable}};
    argData["add"] = {{alph_variable}, {alph_number, alph_variable}};
    argData["sub"] = {{alph_variable}, {alph_number, alph_variable}};
    argData["div"] = {{alph_variable}, {alph_number, alph_variable}};
    argData["mul"] = {{alph_variable}, {alph_number, alph_variable}};
    argData["gotoiflss"] = {{alph_variable, alph_number}, {alph_variable, alph_number}, {alph_variable}};
    argData["gotoifgtr"] = {{alph_variable, alph_number}, {alph_variable, alph_number}, {alph_variable}};

    functions["exit"] = [](ARGUMENTS){
        if (arguments[0].type == alph_variable){
            testVar(arguments[0].value, memory);
            if (!memory[arguments[0].value].isNum){
                throwError("[ERROR 404] cannot exit with a string value");
            }
            std::exit((int) memory[arguments[0].value].numVal);
        }else{
            std::exit(std::stoi(arguments[0].value));
        }
    };

    functions["gotoiflss"] = [](ARGUMENTS){
        double v1, v2;

        if(arguments[0].type == alph_variable){
            testVar(arguments[0].value, memory);
            if (!memory[arguments[0].value].isNum)
                throwError("error[403] can not do math with string variable");
            v1 = memory[arguments[0].value].numVal;
        }else{
            v1 = std::stod(arguments[0].value);
        }

        if(arguments[1].type == alph_variable){
            testVar(arguments[1].value, memory);
            if (!memory[arguments[1].value].isNum)
                throwError("error[403] can not do math with string variable");
            v2 = memory[arguments[1].value].numVal;
        }else{
            v2 = std::stod(arguments[1].value);
        }

        if (v1 < v2){
            lineNumber = markerMemory[arguments[2].value];
        }
    };

    functions["gotoifgtr"] = [](ARGUMENTS){
        double v1, v2;

        if(arguments[0].type == alph_variable){
            testVar(arguments[0].value, memory);
            if (!memory[arguments[0].value].isNum)
                throwError("error[403] can not do math with string variable");
            v1 = memory[arguments[0].value].numVal;
        }else{
            v1 = std::stod(arguments[0].value);
        }

        if(arguments[1].type == alph_variable){
            testVar(arguments[1].value, memory);
            if (!memory[arguments[1].value].isNum)
                throwError("error[403] can not do math with string variable");
            v2 = memory[arguments[1].value].numVal;
        }else{
            v2 = std::stod(arguments[1].value);
        }

        if (v1 > v2){
            lineNumber = markerMemory[arguments[2].value];
        }
    };

    functions["add"] = [](ARGUMENTS){
        testVar(arguments[0].value, memory);

        if (!memory[arguments[0].value].isNum)
            throwError("error[403] can not do math with string variable");

        if(arguments[1].type == alph_variable){
            testVar(arguments[1].value, memory);

            if (!memory[arguments[1].value].isNum)
                throwError("error[403] can not do math with string variable");

            memory[arguments[0].value].numVal += memory[arguments[1].value].numVal;
        }else{
            memory[arguments[0].value].numVal += std::stod(arguments[1].value);
        }
    };

    functions["sub"] = [](ARGUMENTS){
        testVar(arguments[0].value, memory);

        if (!memory[arguments[0].value].isNum)
            throwError("error[403] can not do math with string variable");

        if(arguments[1].type == alph_variable){
            testVar(arguments[1].value, memory);

            if (!memory[arguments[1].value].isNum)
                throwError("error[403] can not do math with string variable");

            memory[arguments[0].value].numVal -= memory[arguments[1].value].numVal;
        }else{
            memory[arguments[0].value].numVal -= std::stod(arguments[1].value);
        }
    };

    functions["div"] = [](ARGUMENTS){
        testVar(arguments[0].value, memory);

        if (!memory[arguments[0].value].isNum)
            throwError("error[403] can not do math with string variable");

        if(arguments[1].type == alph_variable){
            testVar(arguments[1].value, memory);

            if (!memory[arguments[1].value].isNum)
                throwError("error[403] can not do math with string variable");

            memory[arguments[0].value].numVal /= memory[arguments[1].value].numVal;
        }else{
            memory[arguments[0].value].numVal /= std::stod(arguments[1].value);
        }
    };

    functions["mul"] = [](ARGUMENTS){
        testVar(arguments[0].value, memory);

        if (!memory[arguments[0].value].isNum)
            throwError("error[403] can not do math with string variable");

        if(arguments[1].type == alph_variable){
            testVar(arguments[1].value, memory);

            if (!memory[arguments[1].value].isNum)
                throwError("error[403] can not do math with string variable");

            memory[arguments[0].value].numVal *= memory[arguments[1].value].numVal;
        }else{
            memory[arguments[0].value].numVal *= std::stod(arguments[1].value);
        }
    };

    functions["print"] = [](ARGUMENTS){
        if (arguments[0].type == alph_variable){
            testVar(arguments[0].value, memory);
            if (memory[arguments[0].value].isNum){
                std::cout << memory[arguments[0].value].numVal << std::flush;
            }else {
                std::cout << memory[arguments[0].value].strVal << std::flush;
            }
        }else{//its a number, or a string, so just print the value
            std::cout << arguments[0].value << std::flush;
        }
    };


    functions["goto"] = [](ARGUMENTS){
        testMark(arguments[0].value, markerMemory);
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
            testVar(arguments[1].value, memory);
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
        testVar(arguments[0].value, memory);

        if (memory[arguments[0].value].isNum)
            memory[arguments[0].value].numVal++;
        else
            throwError("error[400] can not increment string value");
    };

    functions["less"] = [](ARGUMENTS){
        testVar(arguments[0].value, memory);

        if (memory[arguments[0].value].isNum)
            memory[arguments[0].value].numVal--;
        else
            throwError("error[401] can not decrement string value");
    };
}
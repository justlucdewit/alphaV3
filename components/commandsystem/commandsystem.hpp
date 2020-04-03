#pragma once

#include <vector>
#include <functional>
#include <map>
#include <iostream>
#include <string>
#include <cmath>
#include <random>
#include <fstream>

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

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<> dis(0.0, 1.0);

void initCommands(){
    //others
    argData["get"] = {{alph_variable}};
    argData["print"] = {{alph_number, alph_string, alph_variable}};
    argData["let"] = {{alph_variable},{alph_number, alph_string, alph_variable}};
    argData["num"] = {{alph_variable}};
    argData["str"] = {{alph_variable}};

    // single variable math
    argData["less"] = {{alph_variable}};
    argData["more"] = {{alph_variable}};
    argData["sqrt"] = {{alph_variable}};
    argData["cos"] = {{alph_variable}};
    argData["sin"] = {{alph_variable}};
    argData["tan"] = {{alph_variable}};
    argData["rand"] = {{alph_variable}};
    argData["round"] = {{alph_variable}};

    // double variable math
    argData["add"] = {{alph_variable}, {alph_number, alph_variable}};
    argData["sub"] = {{alph_variable}, {alph_number, alph_variable}};
    argData["div"] = {{alph_variable}, {alph_number, alph_variable}};
    argData["mul"] = {{alph_variable}, {alph_number, alph_variable}};
    argData["pow"] = {{alph_variable}, {alph_number, alph_variable}};
    argData["mod"] = {{alph_variable}, {alph_number, alph_variable}};

    // flow controll
    argData["goto"] = {{alph_variable}};
    argData["gotoifis"] = {{alph_variable, alph_number}, {alph_variable, alph_number}, {alph_variable}};
    argData["gotoifisnt"] = {{alph_variable, alph_number}, {alph_variable, alph_number}, {alph_variable}};
    argData["gotoiflss"] = {{alph_variable, alph_number}, {alph_variable, alph_number}, {alph_variable}};
    argData["gotoifgtr"] = {{alph_variable, alph_number}, {alph_variable, alph_number}, {alph_variable}};
    argData["skipifis"] = {{alph_variable, alph_number}, {alph_variable, alph_number}};
    argData["skipifisnt"] = {{alph_variable, alph_number}, {alph_variable, alph_number}};
    argData["skipiflss"] = {{alph_variable, alph_number}, {alph_variable, alph_number}};
    argData["skipifgtr"] = {{alph_variable, alph_number}, {alph_variable, alph_number}};

    argData["fappend"] = {{alph_variable, alph_string}, {alph_variable, alph_string}};

    argData["cat"] = {{alph_variable}, {alph_variable, alph_string}};

    argData["exit"] = {{alph_number, alph_variable}};

    functions["cat"] = [](ARGUMENTS){
        testVar(arguments[0].value, memory);
        if (arguments[1].type == alph_variable){
            testVar(arguments[1].value, memory);

            if (memory[arguments[1].value].isNum){
                memory[arguments[0].value].strVal += std::to_string(memory[arguments[1].value].numVal);
            }else {
                memory[arguments[0].value].strVal += memory[arguments[1].value].strVal;
            }
        }else{
            memory[arguments[0].value].strVal += arguments[1].value;
        }
    };

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

    functions["gotoifis"] = [](ARGUMENTS){
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

        if (v1 == v2){
            lineNumber = markerMemory[arguments[2].value];
        }
    };

    functions["gotoifisnt"] = [](ARGUMENTS){
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

        if (v1 != v2){
            lineNumber = markerMemory[arguments[2].value];
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

    functions["skipifgtr"] = [](ARGUMENTS){
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
            lineNumber++;
        }
    };

    functions["skipiflss"] = [](ARGUMENTS){
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
            lineNumber++;
        }
    };

    functions["skipifis"] = [](ARGUMENTS){
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

        if (v1 == v2){
            lineNumber++;
        }
    };

    functions["skipifisnt"] = [](ARGUMENTS){
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

        if (v1 != v2){
            lineNumber++;
        }
    };

    functions["sqrt"] = [](ARGUMENTS){
        testVar(arguments[0].value, memory);

        if (!memory[arguments[0].value].isNum)
            throwError("error[403] can not do math with string variable");

        memory[arguments[0].value].numVal = std::sqrt(memory[arguments[0].value].numVal);
    };

    functions["cos"] = [](ARGUMENTS){
        testVar(arguments[0].value, memory);

        if (!memory[arguments[0].value].isNum)
            throwError("error[403] can not do math with string variable");

        memory[arguments[0].value].numVal = std::cos(memory[arguments[0].value].numVal);
    };

    functions["sin"] = [](ARGUMENTS){
        testVar(arguments[0].value, memory);

        if (!memory[arguments[0].value].isNum)
            throwError("error[403] can not do math with string variable");

        memory[arguments[0].value].numVal = std::sin(memory[arguments[0].value].numVal);
    };

    functions["tan"] = [](ARGUMENTS){
        testVar(arguments[0].value, memory);

        if (!memory[arguments[0].value].isNum)
            throwError("error[403] can not do math with string variable");

        memory[arguments[0].value].numVal = std::tan(memory[arguments[0].value].numVal);
    };

    functions["pow"] = [](ARGUMENTS){
        testVar(arguments[0].value, memory);

        if (!memory[arguments[0].value].isNum)
            throwError("error[403] can not do math with string variable");

        if(arguments[1].type == alph_variable){
            testVar(arguments[1].value, memory);

            if (!memory[arguments[1].value].isNum)
                throwError("error[403] can not do math with string variable");

            memory[arguments[0].value].numVal = std::pow(memory[arguments[0].value].numVal, memory[arguments[1].value].numVal);
        }else{
            memory[arguments[0].value].numVal = std::pow(memory[arguments[0].value].numVal, std::stod(arguments[1].value));
        }
    };

    functions["mod"] = [](ARGUMENTS){
        testVar(arguments[0].value, memory);

        if (!memory[arguments[0].value].isNum)
            throwError("error[403] can not do math with string variable");

        if(arguments[1].type == alph_variable){
            testVar(arguments[1].value, memory);

            if (!memory[arguments[1].value].isNum)
                throwError("error[403] can not do math with string variable");

            memory[arguments[0].value].numVal = std::fmod(memory[arguments[0].value].numVal, memory[arguments[1].value].numVal);
        }else{
            memory[arguments[0].value].numVal = std::fmod(memory[arguments[0].value].numVal, std::stod(arguments[1].value));
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

    functions["rand"] = [](ARGUMENTS){
        Var newvar;
        newvar.isNum = true;
        newvar.numVal = dis(gen);
        memory[arguments[0].value] = newvar;
    };

    functions["round"] = [](ARGUMENTS){
        testVar(arguments[0].value, memory);
        if (!memory[arguments[0].value].isNum)
            throwError("[ERROR] cant do math on string variable");
        memory[arguments[0].value].numVal = std::round(memory[arguments[0].value].numVal);
    };

    functions["str"] = [](ARGUMENTS){
        testVar(arguments[0].value, memory);
        if (!memory[arguments[0].value].isNum)
            return;

        memory[arguments[0].value].isNum = false;
        memory[arguments[0].value].strVal = std::to_string(memory[arguments[0].value].numVal);
    };

    functions["num"] = [](ARGUMENTS){
        testVar(arguments[0].value, memory);
        if (memory[arguments[0].value].isNum)
            return;

        memory[arguments[0].value].isNum = true;
        memory[arguments[0].value].numVal = std::stod(memory[arguments[0].value].strVal);
    };

    functions["get"] = [](ARGUMENTS){
        Var newvar;
        newvar.isNum = false;
        std::getline(std::cin,  newvar.strVal);
        memory[arguments[0].value] = newvar;
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

    functions["fappend"] = [](ARGUMENTS){
        std::ofstream file;
        if (arguments[0].type == alph_string) {
            file.open(arguments[0].value, std::ios::app);
        }else{
            testVar(arguments[0].value, memory);
            if (memory[arguments[0].value].isNum)
                throwError("[ERROR] files can only have string names");
            file.open(memory[arguments[0].value].strVal, std::ios::app);
        }

        if (arguments[1].type == alph_string){
            file << arguments[1].value;
        }else{
            testVar(arguments[1].value, memory);
            file << memory[arguments[1].value].strVal;
        }

        file.close();
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
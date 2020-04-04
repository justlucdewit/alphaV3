#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>

#include "components/tokenSplitter/tokenSplitter.hpp"
#include "components/fileReader/fileReader.hpp"
#include "components/tokenSys/tokenSys.hpp"
#include "components/typeIdentifier/typeIdentifier.hpp"
#include "components/markerExtracter/markerExtracter.hpp"
#include "components/validator/validator.hpp"
#include "components/commandsystem/commandsystem.hpp"
#include "components/interpreter/interpreter.hpp"
#include "components/compiler/compiler.hpp"
#include "components/avm32/avm32.hpp"

/*
	alpha is the interpreter CLI for the alphacode language
	the V3 CLI started development on 14-3-2020 and was made by Luc de wit

	it is meant to be faster and way more optimized then the V2 engine
*/

/*
	this is the main CLI, it will figure out what to do
	based on the arguments passed
*/

#define VERSION "alpha CLI v3.0.3"

int main(int argc, char** argv)
{
    bool debug = true;
    std::ios_base::sync_with_stdio(false);
    if (argc >= 2)
	{
        if (strcmp(argv[1], "avm")==0){
            if (argc >= 3){
                AVM32 vm;
                std::fstream file;
                std::vector<int32_t> prog;
                file.open(argv[2]);

                std::string word;
                while(file >> word){
                    prog.insert(prog.begin(), std::stoi(word, 0, 16));
                }

                std::cout << prog[0];

                file.close();
                vm.loadProgram(prog);
                vm.run();
            }else{
                std::cout << "please give a aasm file to be ran in avm";
            }
        }
        //define the command functions
        initCommands();

        //extract the source code from the file
        std::string sourceCode = fileReader(argv[1]);

        //split the source code into tokens according to spaces and strings
        std::vector<Token> tokens = tokenSplitter(sourceCode);

        //read the tokens and assign a type
        typeIdentifier(tokens, argData, !(argc >= 3 && strcmp(argv[2], "-c") == 0));

        //validate the token, throw error if error found
        validate(tokens, argData);

        if (argc >= 3 && strcmp(argv[2], "-c") == 0){
            std::string exename;
            if (argc >= 4){
                exename = argv[3];
            }else{
                exename = "out.aasm";
            }
            compile(tokens, exename);
        }else {
            //run the code
            std::map<std::string, int> markerMemory = extractMarkers(tokens);
            interpret(tokens, functions, markerMemory);
        }
    }
    else
    {//print the version name
		std::cout << VERSION;
    }
}

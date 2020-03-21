#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "components/tokenSplitter/tokenSplitter.hpp"
#include "components/fileReader/fileReader.hpp"
#include "components/tokenSys/tokenSys.hpp"
#include "components/configLoader/configLoader.hpp"
#include "components/typeIdentifier/typeIdentifier.hpp"

/*
	alpha is the interpreter CLI for the alphacode language
	the V3 CLI started development on 14-3-2020 and was made by Luc de wit

	it is meant to be faster and way more optimized then the V2 engine
*/

/*
	this is the main CLI, it will figure out what to do
	based on the arguments passed
*/

#define VERSION "alpha CLI v3.0.0"

int main(int argc, char** argv)
{
    if (argc >= 2)
	{//assume the argument is a file name to be ran
        std::map<std::string, std::vector<std::vector<TokenType>>> argData;// list of arguments used by commands

        //extract config data from acconfig.json
        loadConfig(argv[1], argData);

        //extract the source code from the file
		std::string sourceCode = fileReader(argv[1]);

		//split the source code into tokens according to spaces and strings
        std::vector<Token> tokens = tokenSplitter(sourceCode);

        //read the tokens and assign a type
        typeIdentifier(tokens, argData);

        //go over every token and print it to console
		for (unsigned int i = 0; i < tokens.size(); i++)
		{
		    std::cout << i+1 << " ";
            printToken(tokens[i]);
		}
		std::cout << "\nend";
    }
    else
    {//print the version name
		std::cout << VERSION;
    }
}

#include <iostream>
#include <vector>
#include <string>

#include "fragments/tokenSplitter/tokenSplitter.hpp"
#include "fragments/fileReader/fileReader.hpp"
#include "fragments/tokenSys/tokenSys.hpp"

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

        //extract the source code from the file
		const char* sourceCode = fileReader(argv[1]);

		//split the source code into tokens according to spaces and strings
        std::vector<Token> tokens = tokenSplitter(sourceCode);

		for (int i = 0; i <= tokens.size(); i++)
		{
            printToken(tokens[i]);
		}
    }
    else
    {//print the version name
		std::cout << VERSION;
    }
}

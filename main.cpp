#include <iostream>
#include <string>

#include "fragments/fileReader/fileReader.hpp"

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
		std::string sourceCode = fileReader(std::string(argv[1]));
		std::cout << sourceCode;
    }
    else
    {//print the version name
		std::cout << VERSION;
    }
}

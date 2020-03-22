#include <iostream>
#include <fstream>
#include <string>

#include "fileReader.hpp"
#include "../errorSys/errorSys.hpp"

/*
	the fileReader is a very simple engine fragment. that is
	able to open a file, given its path. and return its content
	as a std::string.

	it will throw an error if the file cant be opened for any reason
*/
std::string fileReader(const char* filepath)
{
    std::string path = std::string(filepath);
	std::ifstream ifs(path);

    if (!ifs.is_open())
    {
		if (path.compare(path.length()-3, 3, ".ac") == 0)
		{
			throwError("[ERROR 000] the .ac file could not be read, did you spell it correctly?");
		}
		else if(path.compare(path.length()-5, 5, ".json") == 0)
		{
			throwError("[ERROR 001] no acconfig.json file has been found");
		}
    }

    std::string content((std::istreambuf_iterator<char>(ifs)),(std::istreambuf_iterator<char>()));

    return content;
}

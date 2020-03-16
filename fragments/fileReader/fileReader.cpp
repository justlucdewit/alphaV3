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
std::string fileReader(std::string path)
{
	std::ifstream ifs(path);

    if (!ifs.is_open())
    {
		if (path.compare(path.length()-3, 3, ".ac") == 0)
		{
			throwError(0);
		}
		else if(path.compare(path.length()-5, 5, ".json") == 0)
		{
			throwError(1);
		}
    }

    std::string content((std::istreambuf_iterator<char>(ifs)),(std::istreambuf_iterator<char>()));
    return content;
}

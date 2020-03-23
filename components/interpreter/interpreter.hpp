#pragma once

#define ARGUMENTS std::vector<Token>, unsigned int&, std::map<std::string, int>

#include <vector>
#include <map>
#include <string>
#include <functional>

#include "../tokenSys/tokenSys.hpp"

void interpret(std::vector<Token>, std::map<std::string, std::function<void(ARGUMENTS)>>, std::map<std::string, int>);
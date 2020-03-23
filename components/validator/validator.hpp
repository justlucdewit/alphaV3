#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <map>

#include "../tokenSys/tokenSys.hpp"
#include "../errorSys/errorSys.hpp"

void validate(std::vector<Token>, std::map<std::string, std::vector<std::vector<alph_TokenType>>>);
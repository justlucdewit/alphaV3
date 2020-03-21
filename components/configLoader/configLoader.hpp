#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "../tokenSys/tokenSys.hpp"

void loadConfig(std::string, std::map<std::string, std::vector<std::vector<TokenType>>>&);
#pragma once
#include <string>
#include <vector>
#include <map>

#include "../tokenSys/tokenSys.hpp"

bool isNumber(std::string);
bool isMarker(std::string);
bool isString(std::string);
bool isCommand(std::string, std::map<std::string, std::vector<std::vector<TokenType>>>);

void typeIdentifier(std::vector<Token>&, std::map<std::string, std::vector<std::vector<TokenType>>>);
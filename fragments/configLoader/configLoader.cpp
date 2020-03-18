#include "configLoader.h"

#include "../fileReader/fileReader.hpp"
#include "../../headers/json.h"

using namespace nlohmann;

void loadConfig(std::string source){
    size_t found = source.find_last_of("/\\");
    source.erase(found+1).append("acconfig.json");

    std::string rawJSON = fileReader(source.c_str());

    json config = json::parse(rawJSON);
    std::cout << "loading " << config["commands"].size() <<  " commands";
};
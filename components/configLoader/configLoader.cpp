#include "configLoader.h"

#include "../fileReader/fileReader.hpp"
#include "../../headers/json.h"

using namespace nlohmann;

void loadConfig(std::string source, std::vector<std::string>& commands, std::map<std::string, std::vector<std::vector<TokenType>>>& argData){
    // get path to ac config
    size_t found = source.find_last_of("/\\");
    source.erase(found+1).append("acconfig.json");

    //extract raw JSON
    std::string rawJSON = fileReader(source.c_str());

    //parse the JSON
    json config = json::parse(rawJSON);

    //extract command data
    for (auto i : config["commands"]){
        commands.push_back((i["name"]));
        std::vector<std::vector<TokenType>> newArgData;

        for (auto j : i["args"]){
            std::vector<TokenType> newArg;
            for (unsigned int k = 0; k < j.size(); k++){
                newArg.push_back(typeConvert(j[k]));
            }
            newArgData.push_back(newArg);
        }

        argData[i["name"]] = newArgData;
    }
};
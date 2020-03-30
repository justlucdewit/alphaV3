#include "markerExtracter.hpp"

std::map<std::string, int> extractMarkers(std::vector<Token>& tokens)
{
    std::map<std::string, int> markerMemory;
    std::vector<int> toBeRemoved;

    int i = 0;
    int offset = 0;
    for (const auto& t : tokens)
    {
        if (t.type == alph_marker)
        {
            markerMemory[t.value.substr(1, t.value.size()-1)] = i-offset;
            toBeRemoved.push_back(i);
            offset++;
        }
        i++;
    }

//    for (auto& t : tokens)
//    {
//        if (t.type == alph_variable && markerMemory.count(t.value))
//            t.type = alph_marker;
//    }

    offset = 0;
    for (const auto& j : toBeRemoved){
        tokens.erase(tokens.begin()+j-offset);
        offset++;
    }

    return markerMemory;
}
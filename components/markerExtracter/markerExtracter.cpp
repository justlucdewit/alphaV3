#include "markerExtracter.hpp"
#include <algorithm>

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
            //std::cout << "[debug] found marker named " << t.value << ", must be deleted at index " << i << "\n";
            markerMemory[t.value.substr(1, t.value.size()-1)] = i-offset;
            toBeRemoved.push_back(i-offset++);
        }
        i++;
    }

    for (const auto& j : toBeRemoved){
        tokens.erase(tokens.begin()+j);
    }

    return markerMemory;
}
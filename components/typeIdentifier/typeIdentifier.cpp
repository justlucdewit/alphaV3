#include "typeIdentifier.hpp"

std::string substrReplace(std::string data, std::string toSearch, std::string replaceStr){
    size_t pos = data.find(toSearch);
    while( pos != std::string::npos)
    {
        data.replace(pos, toSearch.size(), replaceStr);
        pos =data.find(toSearch, pos + replaceStr.size());
    }

    return data;
}

bool isNumber(std::string s)
{
    std::size_t char_pos(0);

    // skip the whilespaces
    char_pos = s.find_first_not_of(' ');
    if (char_pos == s.size()) return false;

    // check the significand
    if (s[char_pos] == '+' || s[char_pos] == '-') ++char_pos; // skip the sign if exist

    int n_nm, n_pt;
    for (n_nm = 0, n_pt = 0; std::isdigit(s[char_pos]) || s[char_pos] == '.'; ++char_pos) {
        s[char_pos] == '.' ? ++n_pt : ++n_nm;
    }
    if (n_pt>1 || n_nm<1) // no more than one point, at least one digit
        return false;

    // skip the trailing whitespaces
    while (s[char_pos] == ' ') {
        ++ char_pos;
    }

    return char_pos == s.size();  // must reach the ending 0 of the string
}

bool isMarker(std::string s)
{
    return s.front() == ':';
}

bool isString(std::string s)
{
    return (s.front() == '\'' && s.back() == '\'') || (s.front() == '"' && s.back() == '"');
}

bool isCommand(std::string s, std::map<std::string, std::vector<std::vector<alph_TokenType>>> commands)
{
    return commands.find(s) != commands.end();
}

void typeIdentifier(std::vector<Token>& tokens, std::map<std::string, std::vector<std::vector<alph_TokenType>>> commands)
{
    for (auto& t : tokens)
    {
        t.type = alph_variable;

        if (isNumber(t.value))
        {
            t.type = alph_number;
        }

        else if(isMarker(t.value))
        {
            t.type = alph_marker;
        }

        else if(isString(t.value))
        {
            t.type = alph_string;

            // remove quotes
            t.value.pop_back();
            t.value.erase(0, 1);

            //replace escape chars
            t.value = substrReplace(t.value, "\\n", "\n");
            t.value = substrReplace(t.value, "\\t", "\t");
            t.value = substrReplace(t.value, "\\a", "\a");
            t.value = substrReplace(t.value, "\\b", "\b");
            t.value = substrReplace(t.value, "\\r", "\r");
            t.value = substrReplace(t.value, "\\v", "\v");
            t.value = substrReplace(t.value, "\\\\", "\\");
            t.value = substrReplace(t.value, "\\\'", "\'");
            t.value = substrReplace(t.value, "\\\"", "\"");
            t.value = substrReplace(t.value, "\\\'", "\'");
        }

        else if(isCommand(t.value, commands))
        {
            t.type = alph_command;
        }
    }
}
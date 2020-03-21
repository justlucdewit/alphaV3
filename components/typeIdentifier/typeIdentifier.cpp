#include "typeIdentifier.hpp"

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

bool isCommand(std::string s, std::map<std::string, std::vector<std::vector<TokenType>>> commands)
{
    return commands.find(s) != commands.end();
}

void typeIdentifier(std::vector<Token>& tokens, std::map<std::string, std::vector<std::vector<TokenType>>> commands)
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
        }

        else if(isCommand(t.value, commands))
        {
            t.type = alph_command;
        }
    }
}
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

void typeIdentifier(std::vector<Token>& tokens){
    for (auto& t : tokens){
        t.type = alph_variable;
        if (isNumber(t.value)){
            t.type = alph_number;
        }
    }
}
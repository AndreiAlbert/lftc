
#ifndef HASHTABLE_LEXER
#define HASHTABLE_LEXER

#include <vector>
#include <string>
#include <map>

class Lexer
{
public:
    Lexer(std::string path_to_tokens);
    bool is_token(const std::string &token);
    bool is_numerical_constant(const std::string &numerical_constant);

private:
    std::vector<std::string> tokens;
    std::map<int, int> pif;
};

#endif
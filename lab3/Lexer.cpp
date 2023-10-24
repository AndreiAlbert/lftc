#include "Lexer.h"
#include <fstream>
#include <iostream>
#include <algorithm>

Lexer::Lexer(std::string path_to_tokens)
{
    std::string read_text;
    std::ifstream tokens_file(path_to_tokens);
    while (getline(tokens_file, read_text))
    {
        read_text.erase(std::remove_if(read_text.begin(), read_text.end(), ::isspace), read_text.end());
        this->tokens.push_back(read_text);
    }
}

bool Lexer::is_token(const std::string &token)
{
    const auto exists = std::find(this->tokens.begin(), this->tokens.end(), token);
    return exists != this->tokens.end();
}

bool Lexer::is_numerical_constant(const std::string &numerical_constant)
{
    return false;
}

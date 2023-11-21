#ifndef HASHTABLE_LEXER
#define HASHTABLE_LEXER

#include <vector>
#include <string>
#include <map>
#include "SymbolTable.h"

class Lexer
{
public:
    Lexer(std::string path_to_tokens, std::string path_to_source_file);
    void scan();
    void print_to_file();

private:
    std::vector<std::pair<std::string, int>> pif;
    SymbolTable st{10};
    std::size_t current_index;
    std::size_t current_line;
    std::string source_program;
    std::vector<std::string> errors;
    std::vector<std::string> tokens;
    bool check_boolean();
    void skip_whitespace();
    void skip_comments();
    bool check_if_string_const();
    bool check_if_int_constant();
    bool check_identifier();
    bool check_token();
    void next_token();
};

#endif
#include "Lexer.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <regex>

Lexer::Lexer(std::string path_to_tokens, std::string path_to_source_file)
{
    std::string read_text;
    std::ifstream tokens_file(path_to_tokens);
    while (getline(tokens_file, read_text))
    {
        read_text.erase(std::remove_if(read_text.begin(), read_text.end(), ::isspace), read_text.end());
        this->tokens.push_back(read_text);
    }
    std::ifstream source_file(path_to_source_file);
    std::ostringstream ss;
    ss << source_file.rdbuf();
    this->pif = std::vector<std::pair<std::string, int>>{};
    this->source_program = ss.str();
    this->current_index = 0;
    this->current_line = 1;
}

void Lexer::print_pif()
{
    std::cout << "PIF:\n";
    for (const auto &pair : this->pif)
    {
        std::cout << pair.first << ' ' << pair.second << '\n';
    }
}

void Lexer::print_to_file()
{
    std::fstream f("./dist/pif.out");
    std::fstream f2("./dist/st.out");
    for(const auto& pair: this->pif){
        f << pair.first << ' ' << pair.second << '\n';
    }
    for(int i = 0; i < this->st.hash_table.table.size(); i++)
    {
        f2 << "Bucket " << i << ": ";
        for (const auto& element : this->st.hash_table.table[i])
        {
            f2 << "[Name: " << element.name << ", Type: " << (element.type == identifier ? "Identifier" : "Constant") << ", Position: " << element.position << "] ";
        }
        f2 << std::endl;  
    }
    if(this->errors.size())
    {
        for(const auto& error: this->errors)
        {
            f << error;
        }
    }
}

void Lexer::skip_whitespace()
{
    if(this->source_program[this->current_index] == '\n')
    {
        this->current_index++;
        this->current_line++;
    }
    while (this->current_index < this->source_program.size() &&
           (this->source_program[this->current_index] == ' ' ||
            this->source_program[this->current_index] == '\t' ||
            this->source_program[this->current_index] == '\n'))
    {
        if (this->source_program[this->current_index] == '\n')
        {
            this->current_line++; // Increment line count when a newline is encountered.
        }
        this->current_index++; // Move to the next character.
    }
}

void Lexer::skip_comments()
{
    if (this->source_program.find("//", this->current_index) == this->current_index)
    {
        while (this->current_index < this->source_program.size() && this->source_program[this->current_index] != '\n')
        {
            this->current_index++;
        }
        if (this->current_index < this->source_program.size())
        {
            this->current_index++; // Skip the newline character as well
        }
        this->current_line++;
    }
}

bool Lexer::check_if_string_const()
{
    std::regex pattern("^\"(.*?)\"");
    std::smatch match;
    auto input = this->source_program.substr(this->current_index);
    if (!std::regex_search(input, match, pattern))
    {
        return false;
    }
    this->current_index += match[0].length();
    this->st.add(match[0], constant);
    this->pif.push_back(std::make_pair(match[0], this->st.get_current_position()));
    return true;
}

bool Lexer::check_if_int_constant()
{
    // TODO DONT FORGET ABOUT CARROT
    std::regex pattern("^([+-]?[1-9][0-9]*|0)");
    auto input = this->source_program.substr(this->current_index);
    std::smatch match;
    if (std::regex_search(input, match, pattern))
    {
        this->current_index += match[0].length();
        return true;
    }
    this->st.add(match[0], constant);
    this->pif.push_back(std::make_pair(match[0], this->st.get_current_position()));
    return false;
}

bool Lexer::check_identifier()
{
    // TODO DONT FORGET ABOUT CARROT
    std::regex pattern("^([a-zA-Z_][a-zA-Z0-9_]*)");
    auto input = this->source_program.substr(this->current_index);
    std::smatch match;
    if (std::regex_search(input, match, pattern))
    {
        for (const auto &token : this->tokens)
        {
            if (token == match[0])
            {
                return false;
            }
        }
        if (match[0] == "false" || match[0] == "true")
        {
            return false;
        }
        this->current_index += match[0].length();
        this->st.add(match[0], identifier);
        this->pif.push_back(std::make_pair(match[0], this->st.get_current_position()));
        return true;
    }
    return false;
}

bool Lexer::check_token()
{
    for (const auto &token : this->tokens)
    {
        auto substring = this->source_program.substr(this->current_index, token.size());
        if (substring == token)
        {
            this->current_index += substring.size();
            this->pif.push_back(std::make_pair(substring, -1));
            return true;
        }
    }
    return false;
}

bool Lexer::check_boolean()
{
    auto true_substr = this->source_program.substr(this->current_index, 4);
    if (true_substr == "true")
    {
        this->current_index += 4;
        this->st.add("true", constant);
        this->pif.push_back(std::make_pair("true", this->st.get_current_position()));
        return true;
    }
    auto false_substr = this->source_program.substr(this->current_index, 5);
    if (false_substr == "false")
    {
        this->current_index += 5;
        this->st.add("false", constant);
        this->pif.push_back(std::make_pair("false", this->st.get_current_position()));
        return true;
    }
    return false;
}

void Lexer::next_token()
{
    this->skip_whitespace();
    this->skip_comments();
    if (this->check_token())
    {
        return;
    }
    if (this->check_identifier())
    {
        return;
    }
    if (this->check_if_int_constant())
    {
        return;
    }
    if (this->check_if_string_const())
    {
        return;
    }
    if (this->check_boolean())
    {
        return;
    }
    this->current_index++;
    this->errors.push_back("Token not recognized on line " + std::to_string(this->current_line) + '\n');
}

void Lexer::debug()
{
    std::cout << this->st;
}

void Lexer::scan()
{
    while (this->current_index < this->source_program.size())
    {
        this->next_token();
    }
}

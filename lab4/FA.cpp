#include "FA.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <tuple>

std::vector<std::string> FA::split(const std::string &str, char delim)
{
    std::vector<std::string> tokens; 
    std::stringstream ss(str);
    std::string token;

    while(getline(ss, token, delim)) 
    {
       tokens.push_back(token); 
    }
    return tokens;
}

void FA::parse_states(std::string &input)
{
    input.erase(std::remove(input.begin(), input.end(), '('), input.end());
    input.erase(std::remove(input.begin(), input.end(), ')'), input.end());
    std::vector<std::string> triplets = split(input, ';');
    for(const auto& triplet: triplets)
    {
        std::vector<std::string> elements = split(triplet, ',');
        if(elements.size() == 3)
        {
            std::string f_state = elements[0];
            std::string s_state = elements[1];
            char weight = elements[2][0];
            auto tuple = std::make_tuple(f_state, s_state, weight);
            this->transitions.push_back(tuple);
        }
    }
}

void FA::show_menu()
{
    std::cout << "1. Display the set of states\n";
    std::cout << "2. Display the alphabet\n";
    std::cout << "3. Display the transitions\n";
    std::cout << "4. Display the initial state\n";
    std::cout << "5. Display the final state\n";
    std::cout << "6. Exit<<\n";
}

void FA::debug()
{
    std::cout << "[STATES]: ";
    for(const auto& state: this -> states)
    {
        std::cout << state << ' ';
    }
    std::cout << '\n';

    std::cout << "[ALPHABET]: ";
    for(const auto& letter: this -> alphabet)
    {
        std::cout << letter << ' ';
    }
    std::cout << '\n';

    std::cout << "[INITIAL STATE]: ";
    std::cout << this -> initial_state << '\n';

    std::cout << "[FINAL STATE]:";
    std::cout << this -> final_state << '\n';

    std::cout << "[TRANSITIONS]:";
    for(const auto& transition: this -> transitions)
    {
        std::cout << std::get<0>(transition) << ',' << std::get<1>(transition) << ' ' << std::get<2>(transition) << '\t';
    }
}


void FA::run()
{
    std::cout << "Hei there\n";
    while(true)
    {
        unsigned int user_input; 
        this->show_menu();
        std::cout << "Your input:";
        std::cin >> user_input;
        switch (user_input)
        {
            case 1: 
                std::cout << "states\n";
                break;
            case 2: 
                std::cout << "alphabet\n";
                break;
            case 3:
                std::cout << "transitions\n";
                break;
            case 4: 
                std::cout << "Initial state: " << this->initial_state << '\n';
                break;
            case 5: 
                std::cout << "Final state: " << this -> final_state << '\n';
                break;
            case 6: 
                exit(0);
                break;
            default:
                std::cout << "Invalid\n";
                break;
        }
    }
}

FA::FA(const std::string &file_name)
{
    this->file_name = file_name;
    std::ifstream file(file_name);
    std::string line;
    while(getline(file, line))
    {
        std::size_t pos = line.find(":");
        if(pos != std::string::npos)
        {
            std::string key = line.substr(0, pos);
            std::string value = line.substr(pos + 2);
            if(key == "states")
            {
                this -> states = this -> split(value, ',');
            }
            else if (key == "alphabet")
            {
                this -> alphabet = this -> split(value, ',');
            }
            else if(key == "initial state")
            {
                this->initial_state = value;
            }
            else if(key == "final state")
            {
                this -> final_state = value;
            }
            else {
                this->parse_states(value);
            }
        }
    }
}

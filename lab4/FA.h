#ifndef FA_H
#define FA_H

#include <vector>
#include <string>

class FA {
private:
    std::string file_name;
    std::vector<std::string> states; 
    std::vector<std::string> alphabet;
    std::string initial_state; 
    std::vector<std::string> final_states;
    std::vector<std::tuple<std::string, std::string, char>> transitions;
    std::vector<std::string> split(const std::string& str, char delim);
    void parse_states(std::string& input);
    void show_menu();
    bool verify_sequence(const std::string& sequence);
public:
    FA(const std::string& file_name);
    void debug();
    void run();
};

#endif
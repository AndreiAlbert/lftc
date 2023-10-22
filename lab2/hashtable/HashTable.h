//
// Created by andrei on 10/22/23.
//

#ifndef HASHTABLEV2_HASHTABLE_H
#define HASHTABLEV2_HASHTABLE_H


#include <cstddef>
#include <list>
#include <vector>
#include <optional>
#include <string>

class HashTable{
public:
    void insert(const std::string& key, const int value);
    explicit HashTable(std::size_t size);
    HashTable() {};
    std::optional<int> get_value(const std::string& key);
    friend std::ostream& operator << (const std::ostream& os, const HashTable &ht);
private:
    std::vector<std::list<std::pair<std::string, int>>> table;
    std::size_t hash(const std::string& value);
    std::size_t size{};
};




#endif //HASHTABLEV2_HASHTABLE_H

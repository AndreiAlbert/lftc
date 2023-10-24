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
#include <variant>

class HashTable
{
public:
    void insert(const std::variant<std::string, int> &key, const int value);
    explicit HashTable(std::size_t size);
    HashTable(){};
    std::optional<int> get_value(const std::variant<std::string, int> &key);

private:
    std::vector<std::list<std::pair<std::variant<std::string, int>, int>>> table;
    std::size_t hash(const std::variant<std::string, int> &key);
    std::size_t size{};
};

#endif // HASHTABLEV2_HASHTABLE_H

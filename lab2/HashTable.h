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

enum TYPE {identifier, constant};

struct HashTableData {
    std::string name;
    TYPE type;
    std::size_t position;
};

class HashTable
{
public:
    void insert(const std::string& value, TYPE type, std::size_t position);
    explicit HashTable(std::size_t size);
    HashTable(){};
    std::optional<HashTableData> get_value(const std::string& element, TYPE type);

private:
    //std::vector<std::list<std::pair<std::string, TYPE>>> table;
    std::vector<std::list<HashTableData>> table;
    std::size_t hash(const std::string& key);
    std::size_t size{};
};

#endif // HASHTABLEV2_HASHTABLE_H

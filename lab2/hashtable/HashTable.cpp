#include <functional>
#include <string>
#include "HashTable.h"

HashTable::HashTable(std::size_t size) : size(size) {
    this->table = std::vector<std::list<std::pair<std::string, int>>>(this->size);
}

std::size_t HashTable::hash(const std::string &value) {
    return std::hash<std::string>{}(value) % this->size;
}

void HashTable::insert(const std::string &key, const int value) {
    const int index = this->hash(key);
    const std::optional element = this->get_value(key);
    this->table[index].push_back(std::make_pair(key, value));
}

std::optional<int> HashTable::get_value(const std::string &key) {
    const int index = this->hash(key);
    for (const auto &pair: this->table[index]) {
        if (pair.first == key) {
            return std::make_optional(pair.second);
        }
    }
    return std::nullopt;
}
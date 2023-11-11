#include <functional>
#include <string>
#include <iostream>
#include "HashTable.h"

HashTable::HashTable(std::size_t size) : size(size)
{
    this->table = std::vector<std::list<HashTableData>>(this->size);
}

std::size_t HashTable::hash(const std::string& key)
{
    return std::hash<std::string>{}(key) % this -> size;
}

void HashTable::insert(const std::string& element, TYPE type, std::size_t position )
{
    const std::size_t index = this->hash(element);
    this->table[index].push_back(HashTableData{element, type, position});
}

std::optional<HashTableData> HashTable::get_value(const std::string& element, TYPE type) 
{
    const std::size_t hash = this->hash(element);
    for(const auto& data: this->table[hash])
    {
        if(data.name == element && data.type == type)
        {
            return std::make_optional(data);
        }
        
    }
    return {};
}

std::ostream& operator<<(std::ostream& os, const HashTable& hashTable) {
    for (std::size_t i = 0; i < hashTable.table.size(); ++i) {
        os << "Bucket " << i << ": ";
        for (const auto& data : hashTable.table[i]) {
            os << "{ Name: " << data.name << ", Type: " << (data.type == TYPE::identifier ? "Identifier" : "Constant") 
               << ", Position: " << data.position << " } ";
        }
        os << std::endl; // End the line after each bucket
    }
    return os;
}
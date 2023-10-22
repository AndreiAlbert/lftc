//
// Created by andrei on 10/22/23.
//

#include "SymbolTable.h"

SymbolTable::SymbolTable(std::size_t size)
{
    this -> hash_table = HashTable{size};
    this -> current_position = 0;
}

void SymbolTable::add(const std::string &key)
{
    std::optional result = this -> hash_table.get_value(key);
    if(result.has_value()) 
    {
        return;
    }
    this -> current_position++;
    this -> hash_table.insert(key, this -> current_position);
}

std::optional<int> SymbolTable::get_value(const std::string& key)
{
    return this -> hash_table.get_value(key);
}

int SymbolTable::get_current_position()
{
    return this -> current_position;
}

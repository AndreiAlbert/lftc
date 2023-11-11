//
// Created by andrei on 10/22/23.
//

#include "SymbolTable.h"
#include <iostream>

SymbolTable::SymbolTable(std::size_t size)
{
    this->hash_table = HashTable{size};
    this->current_position = 0;
}

void SymbolTable::add(const std::string& element, TYPE type)
{
    std::optional result = this->hash_table.get_value(element, type);
    if (result.has_value())
    {
        return;
    }
    this->current_position++;
    this->hash_table.insert(element, type, current_position);
}

std::optional<HashTableData> SymbolTable::get_value(const std::string& element, TYPE type)
{
    return this->hash_table.get_value(element, type);
}

int SymbolTable::get_current_position()
{
    return this->current_position;
}

std::ostream &operator<<(std::ostream &os, const SymbolTable &table)
{
    // TODO: insert return statement here
    os << table.hash_table << std::endl;
    return os;
}


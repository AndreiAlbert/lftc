//
// Created by andrei on 10/22/23.
//

#ifndef HASHTABLEV2_SYMBOLTABLE_H
#define HASHTABLEV2_SYMBOLTABLE_H
#include "HashTable.h"
#include <string>

class SymbolTable
{
public:
    SymbolTable(std::size_t size);
    void add(const std::string& element, TYPE type);
    std::optional<HashTableData> get_value(const std::string& key, TYPE type);
    int get_current_position();
private:
    HashTable hash_table;
    int current_position;
};

#endif // HASHTABLEV2_SYMBOLTABLE_H

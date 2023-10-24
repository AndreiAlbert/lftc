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
    void add(const std::variant<std::string, int> &key);
    std::optional<int> get_value(const std::variant<std::string, int> &key);
    int get_current_position();

private:
    HashTable hash_table;
    int current_position;
};

#endif // HASHTABLEV2_SYMBOLTABLE_H

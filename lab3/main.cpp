#include <string>
#include <iostream>
#include <assert.h>
#include "SymbolTable.h"
#include "lexer.h"
#define ST_SIZE 100

void test_lexer()
{
    Lexer l{"../lab1b/tokens.txt"};
    std::cout << l.is_token("declare");
}

void test_identifier_table()
{
    SymbolTable identifier_table{ST_SIZE};
    std::optional<int> search;

    identifier_table.add("x");
    identifier_table.add("y");
    identifier_table.add("z");
    identifier_table.add("HELLO");
    assert(identifier_table.get_current_position() == 4);
    assert(identifier_table.get_current_position() != 3);
    search = identifier_table.get_value("x");
    assert(search.has_value() == true);
    assert(search.value() == 1);

    search = identifier_table.get_value("y");
    assert(search.has_value() == true);
    assert(search.value() == 2);

    search = identifier_table.get_value("NU");
    assert(search.has_value() == false);
}

void test_constants_table()
{
    SymbolTable constants_table{ST_SIZE};
    std::optional<int> search;
    constants_table.add(10);
    constants_table.add(20);
    constants_table.add(30);
    constants_table.add("string constant");
    assert(constants_table.get_current_position() == 4);
    assert(constants_table.get_current_position() != 3);
    search = constants_table.get_value(10);
    assert(search.has_value() == true);
    assert(search.value() == 1);

    search = constants_table.get_value(20);
    assert(search.has_value() == true);
    assert(search.value() == 2);

    search = constants_table.get_value("asta o sa crape");
    assert(search.has_value() == false);

    search = constants_table.get_value("string constant");
    assert(search.has_value() == true);
    assert(search.value() == 4);
}

int main()
{
    test_lexer();
    test_identifier_table();
    test_constants_table();
    std::cout << "Tests good\n";
    return 0;
}

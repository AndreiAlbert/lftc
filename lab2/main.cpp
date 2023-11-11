#include <string>
#include <iostream>
#include <assert.h>
#include "SymbolTable.h"
#define ST_SIZE 100

void test_st()
{
    SymbolTable st{ST_SIZE};
    st.add("a", identifier);
    assert(st.get_current_position() == 1);
    auto optional = st.get_value("a", identifier);
    assert(optional.has_value() == true);
    auto optional2 = st.get_value("a", constant);
    assert(optional2.has_value() == false);
    st.add("234", constant);
    auto optional3 = st.get_value("234", constant);
    assert(optional3.has_value()); 
    auto optional4 = st.get_value("234", identifier);
    assert(optional4.has_value() == false);
}

int main()
{
    test_st();
    std::cout << "Tests good\n";
    return 0;
}

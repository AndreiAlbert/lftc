#include <string>
#include <iostream>
#include <assert.h>
#include <fstream>
#include "SymbolTable.h"
#include "Lexer.h"
#include "FA.h"
#define ST_SIZE 100

void test_FA() 
{
    auto f = FA("./resources/fa.in");
    f.run();
}

void program1()
{
    Lexer l{"../lab1b/tokens.txt", "../lab1a/p1.txt"};
    l.scan();
    l.print_to_file();
}

void program2()
{
    Lexer l{"../lab1b/tokens.txt", "../lab1a/p2.txt"};
    l.scan();
    l.print_to_file();
}

void program3()
{
    Lexer l{"../lab1b/tokens.txt", "../lab1a/p3.txt"};
    l.scan();
    l.print_to_file();
}

void program_error()
{
    Lexer l{"../lab1b/tokens.txt", "../lab1a/perr.txt"};
    l.scan();
    l.print_to_file();
}

int main()
{
    test_FA();
    return 0;
}

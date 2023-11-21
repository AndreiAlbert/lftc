CXX = g++
CXXFLAGS = -Wall -std=c++17

SRCS = HashTable.cpp main.cpp SymbolTable.cpp Lexer.cpp FA.cpp
HEADERS = HashTable.h SymbolTable.h Lexer.h FA.h

OBJDIR = obj/
OBJS = $(SRCS:%.cpp=$(OBJDIR)%.o)
EXECUTABLE = main

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

$(OBJDIR)%.o: %.cpp $(HEADERS)
	mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJDIR) $(EXECUTABLE)

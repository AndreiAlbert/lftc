CXX = g++
CXXFLAGS = -Wall -std=c++17

SRCS = HashTable.cpp main.cpp SymbolTable.cpp
HEADERS = HashTable.h SymbolTable.h

OBJS = $(SRCS:.cpp=.o)
EXECUTABLE = main

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(EXECUTABLE)

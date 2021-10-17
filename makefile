# Definition of Particular Target
.PHONY: clear

# Disabling fo implicit rules
.SUFFIXES:

CXX = g++
CXXFLAGS = -Wall -Wextra -g -std=c++11

# Object directory
OBJ = obj

# Sources
SRC = src/

all: make_dir main.out

main.out: $(OBJ)/main.o $(OBJ)/col.o $(OBJ)/table.o 
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJ)/main.o: $(SRC)/main.cpp $(SRC)/col.hpp $(SRC)/table.hpp 
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ)/table.o: $(SRC)/table.hpp 
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ)/col.o: $(SRC)/col.hpp 
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean: 
	rm -r obj

veryclean:
	rm -r obj
	rm *.out


make_dir:
	test -d $(OBJ) || mkdir -p $(OBJ)
	test -d $(BIN) || mkdir -p $(BIN)
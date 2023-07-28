# Compiler
CXX := g++
# Compiler flags
CXXFLAGS := -std=c++11 -Wall -Wextra
# Include directories
INCLUDE := -IHeaders -Idatastructure -IVtypes -IGlobVals
# Source files
SRC := $(wildcard Source/*.cpp) GlobVals/Globals.cpp main.cpp
# Output binary
OUTPUT := simulation

# Rule to build the binary
$(OUTPUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(SRC) -o $(OUTPUT)

# Rule to clean the binary
clean:
	rm -f $(OUTPUT)


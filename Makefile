# Compiler and linker settings
CXX = g++
CXXFLAGS = -Isrc/include
LDFLAGS =

# Targets and prerequisites
EXEC = main.exe
OBJS = main.o Lexer.o

# Phony targets
.PHONY: all clean run

# Default target
all: $(EXEC)
	.\$(EXEC)

# Linking the final executable
$(EXEC): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

# Compiling main.o
main.o: main.cpp lexer.h tokentype.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o $@

# Compiling Lexer.o
Lexer.o: lexer.cpp lexer.h tokentype.h
	$(CXX) $(CXXFLAGS) -c lexer.cpp -o $@

# Running the executable
run: $(EXEC)
	./$(EXEC)

# Cleaning up
clean:
	del $(OBJS) $(EXEC)

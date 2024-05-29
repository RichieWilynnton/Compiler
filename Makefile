# Compiler and linker settings
CXX = g++
CXXFLAGS = -Isrc/include -IUtils
LDFLAGS =

# Targets and prerequisites
EXEC = main.exe
OBJS = main.o Lexer.o Keywords.o Testing.o Utils/TokenUtils.o

# Phony targets
.PHONY: all clean run

# Default target
all: $(EXEC)
	./$(EXEC)

# Linking the final executable
$(EXEC): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

# Compiling main.o
main.o: main.cpp Lexer.h Token.h Tokentype.h Keywords.h Testing.h Utils/TokenUtils.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o $@

# Compiling Lexer.o
Lexer.o: Lexer.cpp Lexer.h Token.h Tokentype.h Keywords.h Testing.h Utils/TokenUtils.h
	$(CXX) $(CXXFLAGS) -c Lexer.cpp -o $@

# Compiling Keywords.o
Keywords.o: Keywords.cpp Keywords.h
	$(CXX) $(CXXFLAGS) -c Keywords.cpp -o $@

# Compiling Testing.o
Testing.o: Testing.cpp Testing.h
	$(CXX) $(CXXFLAGS) -c Testing.cpp -o $@

# Compiling TokenUtils.o
Utils/TokenUtils.o: Utils/TokenUtils.cpp Utils/TokenUtils.h
	$(CXX) $(CXXFLAGS) -c Utils/TokenUtils.cpp -o $@

# Running the executable
run: $(EXEC)
	./$(EXEC)

# Cleaning up
clean:
	del /f /q main.o Lexer.o Keywords.o Testing.o Utils\TokenUtils.o main.exe

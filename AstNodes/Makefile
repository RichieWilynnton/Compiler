# Compiler and linker settings
CXX = g++
CXXFLAGS = -I. -IAstNodes -IAstNodes/BinaryExp -IAstNodes/Lit -IAstNodes/Statement -IUtils
LDFLAGS =

# Source directories
SRCDIRS = . AstNodes AstNodes/BinaryExp AstNodes/Lit AstNodes/Statement

# Object files
OBJS = $(patsubst %.cpp,%.o,$(wildcard $(SRCDIRS:=/*.cpp)))

# Phony targets
.PHONY: all clean

# Default target
all: main.exe

main.exe: $(OBJS)
    $(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

# Cleaning up
clean:
    del /f /q *.o *.exe
# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -g

# Directories
SRC_DIR = .
OBJ_DIR = .

# Source files
SRCS = $(SRC_DIR)/output.c $(SRC_DIR)/UtilFunctions.c

# Object files
OBJS = $(OBJ_DIR)/output.o $(OBJ_DIR)/UtilFunctions.o

# Header files
HEADERS = $(SRC_DIR)/UtilFunctions.h

# Output executable
TARGET = out

# Default rule
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to build object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean rule
clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)

# Phony targets
.PHONY: all clean

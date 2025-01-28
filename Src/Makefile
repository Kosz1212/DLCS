CC = g++
CFLAGS = -Wall -Wextra -std=c++17
SRC_DIR = Src
OBJ_DIR = Obj
BIN_DIR = Bin
EXEC = $(BIN_DIR)/DLCS

# Find all .cpp files in the source directory
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

# Default target
all: $(EXEC)

# Linking the final executable
$(EXEC): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@
	@echo "Build successful!"

# Compiling source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Debug mode
DEBUG_FLAGS = -g
debug: CFLAGS += $(DEBUG_FLAGS)
debug: rebuild

# Release mode with optimization
OPT_FLAGS = -O2
release: CFLAGS += $(OPT_FLAGS)
release: rebuild

# Running tests
TEST_EXEC = $(BIN_DIR)/test

test: $(EXEC)
	$(EXEC) --test

# Cleaning compiled files
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
	@echo "Cleaned build files."

# Rebuild the project
rebuild: clean all

# Enable parallel compilation
.PHONY: all clean rebuild debug release test

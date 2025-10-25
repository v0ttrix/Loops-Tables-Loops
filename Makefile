# Makefile for Loops, Tables, and Conversion Utilities
# Author: Jaden Mardini

CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -Werror -O2 -g
LDFLAGS = 
LDLIBS = -lm

# Directories
SRC_DIR = src
BIN_DIR = bin
DOCS_DIR = docs

# Source files
LOOPS_SRC = $(SRC_DIR)/loops.c
TABLES_SRC = $(SRC_DIR)/tables.c
CONVERSION_SRC = $(SRC_DIR)/conversion.c

# Executables
LOOPS_EXEC = $(BIN_DIR)/loops
TABLES_EXEC = $(BIN_DIR)/tables
CONVERSION_EXEC = $(BIN_DIR)/conversion

.PHONY: all clean directories loops tables conversion test help

# Default target
all: directories $(LOOPS_EXEC) $(TABLES_EXEC) $(CONVERSION_EXEC)

# Create directories
directories:
	@mkdir -p $(BIN_DIR) $(DOCS_DIR)

# Individual executables
$(LOOPS_EXEC): $(LOOPS_SRC)
	@echo "Building loops utility..."
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $< $(LDLIBS)

$(TABLES_EXEC): $(TABLES_SRC)
	@echo "Building tables utility..."
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $< $(LDLIBS)

$(CONVERSION_EXEC): $(CONVERSION_SRC)
	@echo "Building conversion utility..."
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $< $(LDLIBS)

# Individual targets
loops: directories $(LOOPS_EXEC)

tables: directories $(TABLES_EXEC)

conversion: directories $(CONVERSION_EXEC)

# Test target
test: all
	@echo "Testing loops utility:"
	@echo "5" | $(LOOPS_EXEC)
	@echo ""
	@echo "Testing tables utility:"
	@echo -e "1\n5" | $(TABLES_EXEC)
	@echo ""
	@echo "Testing conversion utility:"
	@echo -e "14\n0" | $(CONVERSION_EXEC)

# Clean build artifacts
clean:
	@echo "Cleaning build artifacts..."
	rm -rf $(BIN_DIR)
	@echo "Clean complete"

# Help target
help:
	@echo "Available targets:"
	@echo "  all        - Build all utilities (default)"
	@echo "  loops      - Build loops utility only"
	@echo "  tables     - Build tables utility only"
	@echo "  conversion - Build conversion utility only"
	@echo "  test       - Run basic functionality tests"
	@echo "  clean      - Remove build artifacts"
	@echo "  help       - Show this help message"

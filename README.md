# Loops, Tables, and Conversion Utilities

## Overview

Professional C programming utilities demonstrating loops, mathematical calculations, and data conversion. This project showcases fundamental programming concepts implemented with professional coding standards.

## Project Structure

```
Loops-Tables-Loops/
├── src/                    # Source code
│   ├── loops.c            # Number range generator
│   ├── tables.c           # Mathematical tables
│   └── conversion.c       # Days to weeks converter
├── bin/                   # Compiled executables
├── Makefile              # Build configuration
└── README.md             # This file
```

## Utilities

### 1. Number Range Generator (loops)

Generates a sequence of numbers starting from a user-specified value.

**Features:**
- Input validation and overflow protection
- Configurable range (default: 16 numbers)
- Professional error handling

**Usage:**
```bash
./bin/loops
Enter starting number: 10
```

### 2. Mathematical Tables Generator (tables)

Creates formatted tables showing numbers, squares, cubes, and square roots.

**Features:**
- Customizable range (1-100)
- Formatted table output
- Mathematical calculations with proper data types
- Input validation

**Usage:**
```bash
./bin/tables
Enter lower limit (1-100): 1
Enter upper limit (1-100): 10
```

### 3. Days to Weeks Converter (conversion)

Converts days to weeks and remaining days with proper pluralization.

**Features:**
- Interactive conversion loop
- Proper pluralization handling
- Overflow protection
- Decimal week calculation

**Usage:**
```bash
./bin/conversion
Enter number of days (positive to convert, 0 or negative to quit): 14
```

## Building the Project

### Prerequisites
- GCC compiler (C11 standard)
- Make utility
- Math library (libm)

### Compilation
```bash
# Build all utilities
make all

# Build individual utilities
make loops
make tables
make conversion

# Run tests
make test

# Clean build artifacts
make clean
```

## Technical Features

### Error Handling
- Comprehensive input validation
- Overflow and underflow protection
- Clear error messages
- Graceful failure handling

### Code Quality
- C11 standard compliance
- Professional naming conventions
- Comprehensive documentation
- Consistent formatting

### Mathematical Safety
- Proper data type usage for large calculations
- Overflow prevention in arithmetic operations
- Accurate floating-point calculations

## Examples

### Loops Output
```
=== Number Range Generator ===
Author: Jaden Mardini

Enter starting number: 5

Numbers from 5 to 21:
------------------------
5
6
7
...
21
------------------------
Total numbers: 17
```

### Tables Output
```
=== Mathematical Tables Generator ===
Author: Jaden Mardini

Enter lower limit (1-100): 1
Enter upper limit (1-100): 5

+-----+----------+----------+---------+
| Num |  Square  |   Cube   |  Sqrt   |
+-----+----------+----------+---------+
|   1 |        1 |        1 |    1.00 |
|   2 |        4 |        8 |    1.41 |
|   3 |        9 |       27 |    1.73 |
|   4 |       16 |       64 |    2.00 |
|   5 |       25 |      125 |    2.24 |
+-----+----------+----------+---------+
```

### Conversion Output
```
=== Days to Weeks Converter ===
Author: Jaden Mardini

Enter number of days (positive to convert, 0 or negative to quit): 14

Conversion Result:
-----------------
14 days = 2 weeks and 0 days
That's approximately 2.00 weeks total
```

## Design Principles

1. **Input Validation** - All user input is validated
2. **Error Handling** - Comprehensive error checking
3. **Code Clarity** - Self-documenting code with clear logic
4. **Professional Standards** - Industry-standard practices
5. **Mathematical Accuracy** - Proper handling of calculations

## Author

Jaden Mardini - Computer Science Student

## License

This project is for educational purposes.

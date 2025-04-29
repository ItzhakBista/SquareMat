# Square Matrix Implementation in C++

This project implements a Square Matrix class with various operators and functionality as required by the assignment.

## Project Structure

- `square_mat.h` - Header file with class declaration
- `square_mat.cpp` - Implementation of all class methods
- `test_square_mat.cpp` - Unit tests for the SquareMat class
- `main.cpp` - Example usage of the SquareMat class
- `Makefile` - Build instructions

## Features

- All required arithmetic operators (+, -, *, /, %)
- Unary operators (-, ~, !)
- Increment/decrement operators (++, --)
- Comparison operators (==, !=, <, >, <=, >=)
- Compound assignment operators (+=, -=, *=, /=, %=)
- Access operators ([][])
- Determinant calculation
- Matrix transposition
- Matrix exponentiation

## Building and Testing

**To build the project:**
```bash
make
```

**To run the example:**
```bash
make Main
```

**To run the tests:**
```bash
make test
```

**To check for memory leaks:**
```bash
make valgrind
```

**To clean up:**
```bash
make clean
```

##Implementation Notes:
- The matrix is implemented using a 2D array of doubles.
- Memory is managed carefully to avoid leaks.
- All operators check for valid input sizes.
- The determinant is calculated recursively.

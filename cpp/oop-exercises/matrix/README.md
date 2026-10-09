# Matrix (C++)

OOP exercise demonstrating a `Matrix` class with separate header and implementation files using a modular structure (include/src).

## Files
- `include/Matrix.h` — Class declaration
- `src/Matrix.cpp` — Class implementation
- `main.cpp` — Main program
- `Matrix.cbp` — Code::Blocks project file

## Class Design
**Matrix**
- Private: `number[2][2]` (int array), `row`, `column` (global int)
- Public:
  - `Matrix()` — Default constructor
  - `input()` — Prompts for matrix dimensions and elements
  - `display()` — Prints the matrix

## Build & Run
```bash
g++ -Iinclude main.cpp src/Matrix.cpp -o matrix
./matrix
```

Or open `Matrix.cbp` in Code::Blocks.

## Example Output
```
2 X 2 MATRIX DISPLAY SOFTWARE
===========================
Enter number for row size: 2
Enter number for column size: 2
Elements of Matrix
Number [0][0]=1
Number [0][1]=2
Number [1][0]=3
Number [1][1]=4

Elements of Matrix
1 2
3 4
```

## Python Version
See `../../../python/oop-exercises/matrix/`
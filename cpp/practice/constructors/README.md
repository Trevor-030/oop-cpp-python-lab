# Constructors Practice (C++)

Practice exercise demonstrating constructor syntax with separate header and implementation files.

## Files
- `Constructors.h` — Class declaration
- `Constructors.cpp` — Constructor implementation
- `main.cpp` — Main program

## Class Design
**Constructors**
- Public: `name` (string)
- Constructor: `Constructors(string n)` — Initializes name

## Build & Run
```bash
g++ -g main.cpp Constructors.cpp -o constructors
./constructors
```

(Note: The program compiles but produces no output as the constructor only initializes the name member.)

## Key Concepts
- Separate header/implementation files
- Constructor with parameter
- Member initialization in constructor body
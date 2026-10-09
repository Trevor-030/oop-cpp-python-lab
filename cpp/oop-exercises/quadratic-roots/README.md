# Quadratic Roots (C++)

OOP exercise demonstrating a `Quadratic` class that finds roots of a quadratic equation ax² + bx + c = 0.

## Files
- `Quadratic.h` — Class declaration
- `Quadratic.cpp` — Class implementation
- `main.cpp` — Main program
- `singlefile.cpp` — Single-file version
- `single_file_implementation.cpp` — Alternative single-file version

## Class Design
**Quadratic**
- Private: `a`, `b`, `c` (double) — coefficients
- Public:
  - `getInput()` — Prompts for coefficients a, b, c
  - `findRoots()` — Calculates and displays roots using discriminant:
    - `discriminant = b² - 4ac`
    - If > 0: Two distinct real roots
    - If = 0: One repeated real root
    - If < 0: No real roots

## Build & Run
```bash
g++ -g Quadratic.cpp main.cpp -o quadratic
./quadratic
```

## Example Output
```
Enter coefficient a: 1
Enter coefficient b: -5
Enter coefficient c: 6
Root 1 = 3
Root 2 = 2
```

## Python Version
See `../../../python/oop-exercises/quadratic-roots/`
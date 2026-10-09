# Area of Triangle (C++)

OOP exercise demonstrating a `Triangle` class with separate header and implementation files.

## Files
- `Triangle.h` — Class declaration
- `Triangle.cpp` — Class implementation
- `main.cpp` — Main program

## Class Design
**Triangle**
- Private: `base`, `height` (double)
- Public:
  - `Triangle(double b, double h)` — Constructor
  - `calculateArea()` — Returns `0.5 * base * height`
  - `display()` — Prints base, height, and area

## Build & Run
```bash
g++ -g Triangle.cpp main.cpp -o area_triangle
./area_triangle
```

## Python Version
See `../../../python/oop-exercises/area-of-triangle/`
# Area of Rectangle (C++)

OOP exercise demonstrating a `Rectangle` class with private data members and public member functions.

## Files
- `main.cpp` — Contains the `Rectangle` class and main program

## Class Design
**Rectangle**
- Private: `length`, `width` (double)
- Public:
  - `getInput()` — Prompts user for length and width
  - `calculateArea()` — Returns `length * width`
  - `display()` — Prints length, width, and calculated area

## Build & Run
```bash
g++ -g main.cpp -o area_rectangle
./area_rectangle
```

## Example Output
```
Enter Length: 5
Enter Width: 3

****Area of a Rectangle****
Length: 5
Width: 3
Area: 15
```

## Python Version
See `../../../python/oop-exercises/area-of-rectangle/`
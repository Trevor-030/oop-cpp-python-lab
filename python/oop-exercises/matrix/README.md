# Matrix (Python)

OOP exercise demonstrating a `Matrix` class for dynamic matrix input and display.

## Files
- `matrix.py` — `Matrix` class with `__init__`, `input_matrix()`, `display_matrix()`
- `main.py` — Main program
- `alt-version/` — Alternative implementation

## Class Design
**Matrix**
- `__init__(self, rows, columns)` — Initializes dimensions and empty matrix list
- `input_matrix()` — Prompts for each element
- `display_matrix()` — Prints matrix row by row

## Run
```bash
python main.py
```

## Example Output
```
Enter number of rows: 2
Enter number of columns: 3
Enter matrix elements:
Element [0][0]: 1
Element [0][1]: 2
Element [0][2]: 3
Element [1][0]: 4
Element [1][1]: 5
Element [1][2]: 6
Matrix:
[1, 2, 3]
[4, 5, 6]
```

## C++ Version
See `../../../cpp/oop-exercises/matrix/`
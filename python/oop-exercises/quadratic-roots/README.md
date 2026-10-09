# Quadratic Roots (Python)

OOP exercise demonstrating a `Quadratic` class that finds roots of a quadratic equation ax² + bx + c = 0, including complex roots.

## Files
- `quadratic.py` — `Quadratic` class with `__init__` and `calculate()`
- `main.py` — Main program that gets coefficients from user

## Class Design
**Quadratic**
- `__init__(self, a, b, c)` — Stores coefficients
- `calculate()` — Computes discriminant and prints roots:
  - `d = b² - 4ac`
  - If `d > 0`: Two distinct real roots
  - If `d == 0`: One repeated real root
  - If `d < 0`: Two complex conjugate roots

## Run
```bash
python main.py
```

## Example Output
```
Enter a: 1
Enter b: -5
Enter c: 6
Roots are Real and Distinct
Root 1 = 3.0
Root 2 = 2.0
```

## C++ Version
See `../../../cpp/oop-exercises/quadratic-roots/`
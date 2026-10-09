# Matrix — Alternative Version (Python)

Alternative implementation of the Matrix exercise with a different class design.

## Files
- `matrix.py` — `Matrix` class with fixed 2×2 initialization, dynamic input
- `main.py` — Main program

## Differences from Main Version
- **Main version** (`../matrix.py`): Takes rows/columns in constructor, builds matrix on input
- **Alt version** (`matrix.py`): Pre-initializes 2×2 zero matrix in constructor, then resizes on input

## Class Design (Alt)
**Matrix**
- `__init__()` — Creates 2×2 zero matrix, initializes row/col to 0
- `input()` — Prompts for dimensions, then elements
- `display()` — Prints matrix

## Run
```bash
python main.py
```

## Related
Main version: `../README.md`
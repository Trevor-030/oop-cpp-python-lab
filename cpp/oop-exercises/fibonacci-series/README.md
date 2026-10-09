# Fibonacci Series (C++)

OOP exercise demonstrating a `Fibonacci` class that generates the Fibonacci sequence.

## Files
- `main.cpp` — Contains the `Fibonacci` class and main program

## Class Design
**Fibonacci**
- Private: `n` (int) — number of terms
- Public:
  - `setNumber(int num)` — Sets the number of terms
  - `displaySeries()` — Prints the first `n` Fibonacci numbers

## Build & Run
```bash
g++ -g main.cpp -o fibonacci
./fibonacci
```

## Example Output
```
Enter the number of terms: 10
Fibonacci Series: 0 1 1 2 3 5 8 13 21 34
```

## Python Version
See `../../../python/oop-exercises/fibonacci-series/`
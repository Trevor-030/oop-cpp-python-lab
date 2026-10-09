# Simple Interest (C++)

OOP exercise demonstrating a `SimpleInterest` class for financial calculation.

## Files
- `main.cpp` — Contains the `SimpleInterest` class and main program

## Class Design
**SimpleInterest**
- Private: `principal`, `time`, `rate`, `interest` (double)
- Public:
  - `input()` — Prompts for principal, rate (%), and time (years)
  - `calculate()` — Computes interest using formula: `(P * R * T) / 100`
  - `display()` — Prints the calculated simple interest

## Build & Run
```bash
g++ -g main.cpp -o simple_interest
./simple_interest
```

## Example Output
```
Enter Principal: 1000
Enter Rate(%): 5
Enter Time(years): 2
Simple Interest = 100
```

## Python Version
See `../../../python/oop-exercises/simple-interest/`
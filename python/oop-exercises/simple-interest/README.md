# Simple Interest (Python)

OOP exercise demonstrating a `SimpleInterest` class for financial calculation.

## Files
- `simple_interest.py` — `SimpleInterest` class with `__init__` and `calculate_interest()`
- `main.py` — Main program that gets input from user

## Class Design
**SimpleInterest**
- `__init__(self, principal, rate, time)` — Stores principal, rate (%), time (years)
- `calculate_interest()` — Returns `(principal * rate * time) / 100`

## Run
```bash
python main.py
```

## Example Output
```
Enter Principal: 1000
Enter Rate: 5
Enter Time: 2
Simple Interest = 100.0
```

## C++ Version
See `../../../cpp/oop-exercises/simple-interest/`
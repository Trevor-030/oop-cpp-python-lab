# C++ Practice Files

Miscellaneous practice exercises and scratch work in C++.

## Files

### `classes-book-person/`
Basic class syntax exercises:
- `book.cpp` — `Book` class with public members and constructor
- `person.cpp` — `Person` class with private members, getters/setters

### `constructors/`
Constructor practice with separate header/implementation:
- `Constructors.h` / `Constructors.cpp` — Class with parameterized constructor
- `main.cpp` — Usage example

### Single-file exercises in root:
- `payroll_system_single_file.cpp` — Complete payroll system with inheritance (Employee → SalariedStaff, HourlyStaff, CommissionedStaff) in one file. Demonstrates single-level inheritance without polymorphism.
- `prime_numbers.cpp` — Prints all prime numbers from 2 to 99 using trial division.
- `reincarnated.cpp` — Work-rate calculation (incomplete): calculates men needed for a different time period.

## Build & Run
```bash
# Payroll system
g++ -g payroll_system_single_file.cpp -o payroll
./payroll

# Prime numbers
g++ -g prime_numbers.cpp -o primes
./primes

# Work rate (incomplete)
g++ -g reincarnated.cpp -o reincarnated
./reincarnated
```

## Related
- Modular payroll with polymorphism: `../oop-exercises/payroll-system-polymorphism/`
- Python payroll: `../../python/oop-exercises/payroll-system/`
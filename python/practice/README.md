# Python Practice Files

Miscellaneous practice exercises in Python.

## Files

### `fibonacci_class.py`
Fibonacci sequence generator class (similar to the one in `../oop-exercises/fibonacci-series/`).

**Class: `Fibonacci`**
- `__init__(self, n)` — Stores number of terms
- `display()` — Prints first `n` Fibonacci numbers

Note: The file has a usage error at the bottom (`fib = Fibonacci` should be `fib = Fibonacci(n)`).

### `salary_calculator.py`
Interactive salary calculator with three staff categories.

**Class: `Salary`**
- `compute_salary_a()` — Basic: 641.2, Allowance: 146%, Tax: 20%
- `compute_salary_b()` — Basic: 70% of 641.2, Allowance: 112.2%, Tax: 10%
- `compute_salary_c()` — Basic: 62.2% of 641.2, Allowance: 150.8%, Tax: 8.1%

Each calculates: `salary = basic + allowance - tax`

**Menu-driven interface** — Loops until user selects "Exit".

## Run
```bash
python fibonacci_class.py
python salary_calculator.py
```

## Example Output (salary_calculator)
```
Salary Calculator
1. Staff A
2. Staff B
3. Staff C
4. Exit
Enter a Number: 1
926.152
```
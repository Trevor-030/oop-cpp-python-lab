# C++ OOP Exercises

Individual class-based exercises, one per directory. Each demonstrates a specific OOP concept.

## Exercises

| Exercise | Directory | Key Concept |
|---|---|---|
| Area of Rectangle | `area-of-rectangle/` | Basic class with private members |
| Area of Triangle | `area-of-triangle/` | Header/implementation separation |
| Fahrenheit to Centigrade | `fahrenheit-to-centigrade/` | Unit conversion class |
| Fibonacci Series | `fibonacci-series/` | Sequence generation |
| Matrix | `matrix/` | Modular structure (include/src), Code::Blocks |
| Simple Interest | `simple-interest/` | Financial calculation |
| Quadratic Roots | `quadratic-roots/` | Math with discriminant, multiple files |
| Payroll (Inheritance) | `payroll-system-inheritance/` | Single inheritance, separate arrays |
| Payroll (Polymorphism) | `payroll-system-polymorphism/` | Abstract base, virtual functions, polymorphism |

## Python Versions
Each exercise has a Python counterpart in `../../python/oop-exercises/`

## Build
Most single-file exercises:
```bash
g++ -g main.cpp -o exe_name
./exe_name
```

Multi-file exercises (matrix, payroll):
```bash
g++ -Iinclude main.cpp src/*.cpp -o exe_name
./exe_name
```

Or open the `.cbp` file in Code::Blocks.
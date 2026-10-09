# OOP Practice: C++ and Python

Object-oriented programming coursework and practice code by **Michael Agyenim Boateng Anning** (SRI.41.008.026.25), University of Mines and Technology.

The same exercises are implemented in both C++ and Python so the two languages can be compared side by side.

## Structure

```
.
├── cpp/
│   ├── oop-exercises/     # Class-based exercises (one folder each)
│   ├── projects/
│   │   ├── bank-account-system/   # Group 8 project (modular, single-file, drafts)
│   │   └── fare-system/           # Practical exam: ticket fare calculator
│   └── practice/          # Small experiments and scratch work
├── python/
│   ├── oop-exercises/     # Python versions of the exercises
│   └── practice/
├── docs/
│   └── bank-account-system/   # Project reports (.docx)
└── .vscode/tasks.json     # g++ build task
```

## Exercises

| Exercise | C++ | Python |
|---|---|---|
| Area of a rectangle | `cpp/oop-exercises/area-of-rectangle` | `python/oop-exercises/area-of-rectangle` |
| Area of a triangle | `cpp/oop-exercises/area-of-triangle` | `python/oop-exercises/area-of-triangle` |
| Fahrenheit to centigrade | `cpp/oop-exercises/fahrenheit-to-centigrade` | `python/oop-exercises/fahrenheit-to-centigrade` |
| Fibonacci series | `cpp/oop-exercises/fibonacci-series` | `python/oop-exercises/fibonacci-series` |
| Matrix | `cpp/oop-exercises/matrix` | `python/oop-exercises/matrix` |
| Simple interest | `cpp/oop-exercises/simple-interest` | `python/oop-exercises/simple-interest` |
| Quadratic roots | `cpp/oop-exercises/quadratic-roots` | `python/oop-exercises/quadratic-roots` |
| Payroll (inheritance) | `cpp/oop-exercises/payroll-system-inheritance` | `python/oop-exercises/payroll-system` |
| Payroll (polymorphism) | `cpp/oop-exercises/payroll-system-polymorphism` | n/a |

## Projects

- **Bank Account Management System** (Group 8, CE1A): `cpp/projects/bank-account-system`
  - `modular/` is the final multi-file Code::Blocks project.
  - `single-file/` is the final single-file version.
  - `drafts/` holds earlier iterations. Reports are in `docs/bank-account-system`.
- **Fare System** (practical exam): `cpp/projects/fare-system`, with modular and single-file versions.

## Building and running

C++ (single file):

```bash
g++ -g path/to/main.cpp -o main
./main
```

C++ (multi-file projects such as `matrix` or `modular/`):

```bash
g++ -Iinclude main.cpp src/*.cpp -o app
```

Some exercises keep `.h`/`.cpp` pairs in the same folder, so compile every `.cpp` there instead.

Python:

```bash
cd python/oop-exercises/matrix
python main.py
```

Code::Blocks users can open the `.cbp` files directly.

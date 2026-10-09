# Single-File Fare System Iterations

Progressive single-file versions of the fare calculator.

## Files
- `fare_system_v1.cpp` — Initial version
- `fare_system_v2.cpp` — Improved version with reuse of calculated values
- `fare_system_commented.cpp` — Heavily commented educational version

## Build & Run
```bash
g++ fare_system_v2.cpp -o fare_system
./fare_system
```

## Evolution
Each version refines the menu system, input validation, and the ability to reuse previously calculated values (base fare, luggage charge, discount) when computing the final ticket price.
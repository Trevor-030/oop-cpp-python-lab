# Single-File Bank Account System

Final consolidated single-file implementation.

## Files
- `bank_account_system_v3.cpp` — Complete v3 implementation (multi-account, password masking, transaction log, transfers)

## Build & Run
```bash
g++ bank_account_system_v3.cpp -o bank_system
./bank_system
```

## Features
Identical to modular version but contained in one file for easy portability.
- Cross-platform password masking (Windows `_getch()` / Linux `termios`)
- ANSI color codes with Windows console mode enable
- Loading screen with progress bar
- All banking operations

## Version History
- v1: Single account, basic operations
- v2: Multi-account support added
- v3: Final — transaction history, transfers, password validation, credits menu
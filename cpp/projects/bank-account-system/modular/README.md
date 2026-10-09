# Modular Bank Account System

Final multi-file implementation for Code::Blocks.

## Structure
```
modular/
├── BankAccountSystem.cbp    # Code::Blocks project file
├── main.cpp                 # Menu-driven main program
├── include/
│   ├── Bank.h               # Bank class declaration
│   ├── BankAccount.h        # BankAccount class declaration
│   ├── Console.h            # Console utilities (colors, input)
│   ├── Credits.h            # Credits display
│   ├── Customer.h           # Customer class declaration
│   └── Utils.h              # Helper functions (format, validation)
└── src/
    ├── Bank.cpp
    ├── BankAccount.cpp
    ├── Console.cpp
    ├── Credits.cpp
    ├── Customer.cpp
    └── Utils.cpp
```

## Build & Run
```bash
g++ -Iinclude main.cpp src/*.cpp -o bank_system
./bank_system
```

Or open `BankAccountSystem.cbp` in Code::Blocks.

## Features
See parent `../README.md` for full feature list.
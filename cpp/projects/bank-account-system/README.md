# Bank Account Management System (C++)

Group 8 OOP Project — University of Mines and Technology

## Team Members
- Michael Agyenim Boateng Anning (SRI.41.008.026.25)
- Christian David Takyi (SRI.41.008.108.25)
- Dawuda Kashafatu (SRI.41.008.053.25)
- Maame Esi Ohenewaa Andoh (SRI.41.008.025.25)
- Rita Awuviri (SRI.41.008.039.25)
- Oduro Appiah Kwaku (SRI.41.008.089.25)

## Project Structure
```
bank-account-system/
├── modular/          # Final multi-file Code::Blocks project
│   ├── BankAccountSystem.cbp
│   ├── main.cpp
│   ├── include/
│   │   ├── Bank.h
│   │   ├── BankAccount.h
│   │   ├── Console.h
│   │   ├── Credits.h
│   │   ├── Customer.h
│   │   └── Utils.h
│   └── src/
│       ├── Bank.cpp
│       ├── BankAccount.cpp
│       ├── Console.cpp
│       ├── Credits.cpp
│       ├── Customer.cpp
│       └── Utils.cpp
├── single-file/      # Final single-file version
│   └── bank_account_system_v3.cpp
└── drafts/           # Earlier iterations
    ├── v1_single_file.cpp
    ├── v2_multi_account.cpp
    ├── v2_multi_account_revised.cpp
    └── early-modular/
```

## Features
- **Multi-account support** — Each customer can have multiple accounts
- **Password protection** — Masked input with validation (min 6 chars, 1 number)
- **Transaction history** — Timestamped logs for all operations
- **Core operations:**
  - Create new account
  - Deposit / Withdraw funds
  - Check balance
  - Change password
  - Transfer funds between accounts
  - View transaction history
  - View account details
  - List all accounts
  - Bank summary (total accounts & funds)
- **Secret credits menu** (enter 777)

## Class Design
- **Customer** — Name, ID
- **BankAccount** — Customer, account number (auto-generated), balance, password, transaction log
- **Bank** — Manages vector of BankAccount objects, routes menu actions

## Build & Run

### Modular (Code::Blocks)
Open `modular/BankAccountSystem.cbp` in Code::Blocks, or:
```bash
cd modular
g++ -Iinclude main.cpp src/*.cpp -o bank_system
./bank_system
```

### Single-file
```bash
cd single-file
g++ bank_account_system_v3.cpp -o bank_system
./bank_system
```

## Reports
Project reports are in `../../docs/bank-account-system/`
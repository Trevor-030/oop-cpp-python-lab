# Modular Fare System

Multi-file implementation with inheritance hierarchy for the Ghana Railway Ticketing System.

## Structure
```
modular/
├── Practical Exams.cbp      # Code::Blocks project file
├── main.cpp                 # Menu-driven calculator
├── include/
│   ├── TicketComponent.h    # Base class
│   ├── BaseFareCalculation.h
│   ├── DiscountCalculation.h
│   ├── FinalTicketCalculation.h
│   └── LuggageChargeCalculation.h
└── src/
    ├── TicketComponent.cpp
    ├── BaseFareCalculation.cpp
    ├── DiscountCalculation.cpp
    ├── FinalTicketCalculation.cpp
    └── LuggageChargeCalculation.cpp
```

## Class Hierarchy
- **TicketComponent** (base) — Shared display logic
- **BaseFareCalculation** — Distance × Rate
- **LuggageChargeCalculation** — Rate × Weight × Multiplier
- **DiscountCalculation** — Fare × (Student + Loyalty rates)
- **FinalTicketCalculation** — Base + Luggage - Discount

## Build & Run
```bash
g++ -Iinclude main.cpp src/*.cpp -o fare_system
./fare_system
```

Or open `Practical Exams.cbp` in Code::Blocks.
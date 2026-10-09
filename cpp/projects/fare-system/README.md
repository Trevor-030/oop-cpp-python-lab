# Fare System (C++)

Practical Exam — Ghana Railway Ticketing System

## Author
Michael Agyenim Boateng Anning (SRI.41.008.026.25)

## Project Structure
```
fare-system/
├── modular/          # Multi-file version with inheritance hierarchy
│   ├── Practical Exams.cbp
│   ├── main.cpp
│   ├── include/
│   │   ├── TicketComponent.h
│   │   ├── BaseFareCalculation.h
│   │   ├── DiscountCalculation.h
│   │   ├── FinalTicketCalculation.h
│   │   └── LuggageChargeCalculation.h
│   └── src/
│       ├── BaseFareCalculation.cpp
│       ├── DiscountCalculation.cpp
│       ├── FinalTicketCalculation.cpp
│       ├── LuggageChargeCalculation.cpp
│       └── TicketComponent.cpp
└── single-file/      # Iterative versions
    ├── fare_system_v1.cpp
    ├── fare_system_v2.cpp
    └── fare_system_commented.cpp
```

## Features
Menu-driven calculator for railway ticket pricing:
1. **Base Fare** — Distance × Rate per km
2. **Excess Luggage Charge** — Rate × Weight × Multiplier
3. **Discount** — Student + Loyalty rates on fare amount
4. **Final Ticket Price** — Base + Luggage - Discount (reuses previous values)

## Class Hierarchy
- **TicketComponent** (base)
  - `componentName`, `resultValue`
  - `displayHeader()`, `showResult(unit)`
- **BaseFareCalculation** — `distance`, `ratePerKm`; `calculate()` = distance × rate
- **LuggageChargeCalculation** — `ratePerKg`, `weight`, `multiplier`; `calculate()` = rate × weight × multiplier
- **DiscountCalculation** — `fare`, `studentRate`, `loyaltyRate`; `calculate()` = fare × (student + loyalty)
- **FinalTicketCalculation** — `baseFare`, `luggageCharge`, `discount`; `calculate()` = base + luggage - discount

## Build & Run

### Modular (Code::Blocks)
Open `modular/Practical Exams.cbp` in Code::Blocks, or:
```bash
cd modular
g++ -Iinclude main.cpp src/*.cpp -o fare_system
./fare_system
```

### Single-file
```bash
cd single-file
g++ fare_system_v2.cpp -o fare_system
./fare_system
```

## Example Session
```
Welcome to the Ghana Railway Ticketing System

------------------------------------------------------------------
1. Calculate Base Fare
2. Calculate Excess Luggage Charge
3. Calculate Discount
4. Calculate Final Ticket Price
5. Exit
Enter your choice: 1
Enter distance travelled (km): 150
Enter rate per km (GHS): 0.50
--- Base Fare ---
Result: 75.00 GHS
```
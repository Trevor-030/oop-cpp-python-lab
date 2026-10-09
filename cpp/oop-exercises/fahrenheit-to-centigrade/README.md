# Fahrenheit to Centigrade (C++)

OOP exercise demonstrating a `Temperature` class for unit conversion.

## Files
- `main.cpp` — Contains the `Temperature` class and main program

## Class Design
**Temperature**
- Private: `fahrenheit`, `centigrade` (double)
- Public:
  - `input()` — Prompts user for Fahrenheit value
  - `convert()` — Converts using formula: `(F - 32) * 5/9`
  - `display()` — Prints the Centigrade result

## Build & Run
```bash
g++ -g main.cpp -o fahrenheit_to_centigrade
./fahrenheit_to_centigrade
```

## Example Output
```
Enter temperature in Fahrenheit: 98.6
Temperature in Centigrade: 37 Degree Celsius
```

## Python Version
See `../../../python/oop-exercises/fahrenheit-to-centigrade/`
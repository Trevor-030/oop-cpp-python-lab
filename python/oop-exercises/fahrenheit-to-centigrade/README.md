# Fahrenheit to Centigrade (Python)

OOP exercise demonstrating a `Temperature` class for unit conversion.

## Files
- `temperature.py` — `Temperature` class with `__init__` and `to_centigrade()`
- `main.py` — Main program that gets user input and converts temperature

## Class Design
**Temperature**
- `__init__(self, fahrenheit)` — Stores Fahrenheit value
- `to_centigrade()` — Returns `(fahrenheit - 32) * 5 / 9`

## Run
```bash
python main.py
```

## Example Output
```
Enter temperature in Fahrenheit: 98.6
Temperature in Centigrade = 37.0
```

## C++ Version
See `../../../cpp/oop-exercises/fahrenheit-to-centigrade/`
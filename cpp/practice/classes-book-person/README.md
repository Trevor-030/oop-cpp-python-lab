# Classes: Book & Person (C++)

Practice exercises demonstrating basic class syntax in C++.

## Files
- `book.cpp` — `Book` class with public members and constructor
- `person.cpp` — `Person` class with private members, getters/setters

## Book Class
- Public: `title`, `author` (string)
- Constructor: `Book(string t, string a)`
- `display()` — Prints title and author

## Person Class
- Private: `name` (string), `age` (int)
- Setters: `setName()`, `setAge()`
- Getters: `getName()`, `getAge()`
- `display()` — Prints name and age

## Build & Run
```bash
g++ -g book.cpp -o book
./book

g++ -g person.cpp -o person
./person
```

## Example Output (book)
```
Title: Atomic Habits
Author: James Clear
```

## Example Output (person)
```
Name: Michael
Age: 18
```
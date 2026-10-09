#ifndef UTILS_H
#define UTILS_H

#include <string>

// Formats a double as a 2-decimal string with thousands separators (1,250.00).
std::string formatAmount(double amount);

// Formats an amount as "GHS 1,250.00".
std::string formatGHS(double amount);

// Validates a password: minimum 6 characters and at least one number.
bool isValidPassword(const std::string &pwd);

// Reads a line that must contain at least one non-whitespace character.
std::string readNonEmptyString(const std::string &prompt);

// Returns the current date and time as "YYYY-MM-DD HH:MM".
std::string getTimestamp();

// Reads a whole number safely; re-prompts on invalid input instead of crashing.
int readInt(const std::string &prompt);

// Same as readInt but for money; also refuses negative amounts.
double readAmount(const std::string &prompt);

// Masked password input (shows '*', supports Backspace).
std::string getMaskedPassword(const std::string &prompt);

#endif // UTILS_H

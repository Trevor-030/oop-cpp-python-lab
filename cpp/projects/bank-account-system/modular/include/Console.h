#ifndef CONSOLE_H
#define CONSOLE_H

#include <string>

// ANSI colour codes for clearer output (headers, prompts, success, errors).
extern const std::string RESET;
extern const std::string RED;
extern const std::string GREEN;
extern const std::string YELLOW;
extern const std::string CYAN;
extern const std::string BOLD;

// Switches on ANSI colour support on Windows terminals (no-op elsewhere).
void enableConsoleColours();

// Cosmetic startup screens shown once when the program launches.
void showLoadingScreen();
void showWelcomeScreen();

#endif // CONSOLE_H

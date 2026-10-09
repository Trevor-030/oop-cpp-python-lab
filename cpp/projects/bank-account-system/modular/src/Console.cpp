#include "Console.h"
#include <iostream>
#include <thread>
#include <chrono>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string CYAN = "\033[36m";
const string BOLD = "\033[1m";

#ifdef _WIN32
void enableConsoleColours()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode = 0;
    GetConsoleMode(hOut, &mode);
    SetConsoleMode(hOut, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}
#else
void enableConsoleColours()
{
    // Linux/Mac terminals support ANSI colours natively.
}
#endif

void showLoadingScreen()
{
    cout << CYAN << BOLD;
    cout << "\n  ============================================\n";
    cout << "         BANK ACCOUNT MANAGEMENT SYSTEM\n";
    cout << "                   Group 8\n";
    cout << "  ============================================\n";
    cout << RESET << "\n";

    cout << YELLOW << "  Loading Banking Services" << RESET;
    for (int i = 0; i < 3; i++)
    {
        this_thread::sleep_for(chrono::milliseconds(350));
        cout << YELLOW << "." << RESET << flush;
    }
    cout << "\n\n";

    const int barWidth = 30;
    for (int i = 0; i <= barWidth; i++)
    {
        cout << "\r  [" << GREEN;
        for (int j = 0; j < barWidth; j++)
            cout << (j < i ? "#" : " ");
        cout << RESET << "] " << (i * 100 / barWidth) << "%  " << flush;
        this_thread::sleep_for(chrono::milliseconds(25));
    }
    cout << endl;

    cout << GREEN << BOLD << "\n  System Ready." << RESET << endl;
    cout << YELLOW << "  Press Enter to Continue..." << RESET << endl;
    cin.get();
    this_thread::sleep_for(chrono::milliseconds(200));

    cout << "\033[2J\033[1;1H"; // clear the screen before the real menu appears
}

void showWelcomeScreen()
{
    cout << BOLD << CYAN;
    cout << "==========================================\n";
    cout << "      BANK ACCOUNT MANAGEMENT SYSTEM\n";
    cout << "==========================================\n"
         << RESET << endl;
    cout << "Object Oriented Programming Project\n\n";
    cout << "Developed by:\n";
    cout << "Group 8\n\n";
    cout << YELLOW << "Press ENTER to continue..." << RESET;
    cin.get();
    cout << "\033[2J\033[1;1H";
}

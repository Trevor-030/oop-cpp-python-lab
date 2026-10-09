#include "Utils.h"
#include "Console.h"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <limits>
#include <cctype>

// Password masking needs different tools on Windows vs Linux/Mac.
#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

using namespace std;

string formatAmount(double amount)
{
    ostringstream oss;
    oss << fixed << setprecision(2) << amount;
    string s = oss.str();

    size_t dot = s.find('.');
    string intPart = (dot == string::npos) ? s : s.substr(0, dot);
    string fracPart = (dot == string::npos) ? "" : s.substr(dot);

    string withCommas;
    int len = (int)intPart.length();
    for (int i = 0; i < len; ++i)
    {
        if (i > 0 && (len - i) % 3 == 0)
            withCommas += ',';
        withCommas += intPart[i];
    }
    return withCommas + fracPart;
}

string formatGHS(double amount)
{
    return "GHS " + formatAmount(amount);
}

bool isValidPassword(const string &pwd)
{
    if (pwd.length() < 6)
        return false;
    for (char c : pwd)
        if (isdigit(static_cast<unsigned char>(c)))
            return true;
    return false;
}

string readNonEmptyString(const string &prompt)
{
    string value;
    while (true)
    {
        cout << YELLOW << prompt << RESET;
        getline(cin, value);
        bool hasContent = false;
        for (char c : value)
            if (!isspace(static_cast<unsigned char>(c)))
                hasContent = true;
        if (hasContent)
            return value;
        cout << RED << "Customer name cannot be empty. Please enter a valid name." << RESET << endl;
    }
}

string getTimestamp()
{
    time_t now = time(nullptr);
    tm *lt = localtime(&now);
    ostringstream oss;
    oss << (1900 + lt->tm_year) << "-"
        << setw(2) << setfill('0') << (1 + lt->tm_mon) << "-"
        << setw(2) << setfill('0') << lt->tm_mday << " "
        << setw(2) << setfill('0') << lt->tm_hour << ":"
        << setw(2) << setfill('0') << lt->tm_min;
    return oss.str();
}

int readInt(const string &prompt)
{
    int value;
    while (true)
    {
        cout << YELLOW << prompt << RESET;
        cin >> value;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << RED << "Please enter a whole number.\n"
                 << RESET;
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

double readAmount(const string &prompt)
{
    double value;
    while (true)
    {
        cout << YELLOW << prompt << RESET;
        cin >> value;
        if (cin.fail() || value < 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << RED << "Please enter a valid, non-negative amount.\n"
                 << RESET;
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

// Platform-specific: Windows uses conio.h, Linux/Mac uses termios.
string getMaskedPassword(const string &prompt)
{
    cout << YELLOW << prompt << RESET;
    string password;

#ifdef _WIN32
    char ch;
    while ((ch = _getch()) != '\r')
    { // Enter key on Windows
        if (ch == '\b')
        { // Backspace
            if (!password.empty())
            {
                password.pop_back();
                cout << "\b \b"; // erase the last '*' on screen
            }
        }
        else
        {
            password.push_back(ch);
            cout << '*';
        }
    }
    cout << endl;
#else
    termios oldSettings;
    if (tcgetattr(STDIN_FILENO, &oldSettings) != 0)
    {
        // Not a real interactive terminal (e.g. input piped from a file
        // during testing) - just fall back to a normal, visible read so the
        // program still works.
        getline(cin, password);
        return password;
    }

    termios rawSettings = oldSettings;
    rawSettings.c_lflag &= ~(ICANON | ECHO); // turn off line-buffering + echo
    tcsetattr(STDIN_FILENO, TCSANOW, &rawSettings);

    char ch;
    while (read(STDIN_FILENO, &ch, 1) == 1 && ch != '\n')
    {
        if (ch == 127 || ch == 8)
        { // Backspace/Delete
            if (!password.empty())
            {
                password.pop_back();
                cout << "\b \b";
            }
        }
        else
        {
            password.push_back(ch);
            cout << '*';
        }
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &oldSettings); // restore normal terminal mode
    cout << endl;
#endif
    return password;
}

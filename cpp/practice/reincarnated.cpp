#include <iostream>

using namespace std;

int main() {
    double first_number_of_men, second_number_of_men, first_time_period, second_time_period;
    
    cout << "Enter the number of men working: ";
    cin >> first_number_of_men;

    cout << "Enter the time period they worked in: ";
    cin >> first_time_period;

    second_number_of_men = (first_number_of_men*first_time_period)/second_time_period;
}
#include <iostream>

using namespace std;

int main() {

    for (int i = 2; i < 100; i++) {

        int j;

        for (j = 2; j <= (i / j); j++) {
            if (!(i % j))
                break;  // Factor found → not prime
        }

        if (j > (i / j)) {
            cout << i << " is prime\n";
        }
    }

    return 0;
}
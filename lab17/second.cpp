#include <cmath>
#include <iostream>
using namespace std;

bool isPrime(int num) {
    if (num < 2) {
        return false;
    }

    for (int divisor = 2; divisor <= sqrt(num); ++divisor) {
        if (num % divisor == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    for (int i = 0; i <= 21; ++i) {
        if (isPrime(i)) {
            cout << i << " ";
        }
    }

    cout << endl;
    return 0;
}

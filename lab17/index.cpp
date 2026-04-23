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
    int number;

    cout << "Enter a number: ";
    cin >> number;

    cout << number << " -> " << isPrime(number) << endl;

    return 0;
}

#include <iomanip>
#include <iostream>
using namespace std;

int nextSeed(int seed) {
    return (seed * 73 + 41) % 10000;
}

double nextDouble(int &seed) {
    seed = nextSeed(seed);
    return (seed % 399 - 199) / 100.0;
}

int main() {
    const int size = 10;
    double *array = new double[size];
    int seed = 123;

    for (double *current = array; current < array + size; ++current) {
        *current = nextDouble(seed);
    }

    int positiveCount = 0;
    int negativeCount = 0;

    cout << fixed << setprecision(2);
    cout << "Array:" << endl;
    for (double *current = array; current < array + size; ++current) {
        cout << setw(7) << *current;

        if (*current > 0) {
            ++positiveCount;
        } else if (*current < 0) {
            ++negativeCount;
        }
    }

    cout << "\nPositive numbers: " << positiveCount << endl;
    cout << "Negative numbers: " << negativeCount << endl;

    delete[] array;

    return 0;
}

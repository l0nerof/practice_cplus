#include <iomanip>
#include <iostream>
using namespace std;

int nextSeed(int seed) {
    return (seed * 73 + 41) % 10000;
}

int nextInt(int &seed) {
    seed = nextSeed(seed);
    return seed % 90 + 10;
}

int main() {
    const int size = 3;
    int **matrix = new int *[size];
    int seed = 321;

    for (int row = 0; row < size; ++row) {
        *(matrix + row) = new int[size];
    }

    for (int row = 0; row < size; ++row) {
        for (int column = 0; column < size; ++column) {
            *(*(matrix + row) + column) = nextInt(seed);
        }
    }

    cout << "Matrix:" << endl;
    for (int row = 0; row < size; ++row) {
        for (int column = 0; column < size; ++column) {
            cout << setw(4) << *(*(matrix + row) + column);
        }
        cout << endl;
    }

    cout << "\nMain diagonal: ";
    for (int index = 0; index < size; ++index) {
        cout << *(*(matrix + index) + index) << ' ';
    }

    cout << "\nSecondary diagonal: ";
    for (int index = 0; index < size; ++index) {
        cout << *(*(matrix + index) + size - index - 1) << ' ';
    }

    int evenCount = 0;
    int oddCount = 0;

    for (int row = 0; row < size; ++row) {
        for (int column = 0; column < size; ++column) {
            int value = *(*(matrix + row) + column);
            if (value % 2 == 0) {
                ++evenCount;
            } else {
                ++oddCount;
            }
        }
    }

    cout << "\nEven elements: " << evenCount << endl;
    cout << "Odd elements: " << oddCount << endl;

    for (int row = 0; row < size; ++row) {
        delete[] *(matrix + row);
    }
    delete[] matrix;

    return 0;
}

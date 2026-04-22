#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    const int size = 10;
    int matrix[size][size] = {};

    int *cell = *matrix;

    for (int row = 1; row <= size; ++row) {
        for (int column = 1; column <= size; ++column) {
            *cell = row * column;
            ++cell;
        }
    }

    cell = *matrix;

    for (int row = 1; row <= size; ++row) {
        for (int column = 1; column <= size; ++column) {
            cout << setw(4) << *cell;
            ++cell;
        }
        cout << endl;
    }

    return 0;
}

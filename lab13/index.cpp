#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    const int size = 4;
    int matrix[size][size] = {};
    int values[] = {
        12, 23, 34, 45,
        56, 67, 78, 89,
        90, 11, 22, 33,
        44, 55, 66, 77
    };

    int *source = values;
    for (int *cell = *matrix; cell < *matrix + size * size; ++cell, ++source) {
        *cell = *source;
    }

    cout << "Matrix:" << endl;
    int *cell = *matrix;
    for (int row = 0; row < size; ++row) {
        for (int column = 0; column < size; ++column) {
            cout << setw(4) << *cell;
            ++cell;
        }
        cout << endl;
    }

    cout << "\nMain diagonal: ";
    for (int *diagonal = *matrix; diagonal < *matrix + size * size; diagonal += size + 1) {
        cout << *diagonal << ' ';
    }

    cout << "\nSecondary diagonal: ";
    for (int *diagonal = *matrix + size - 1;
         diagonal <= *matrix + (size - 1) * size;
         diagonal += size - 1) {
        cout << *diagonal << ' ';
    }

    int evenCount = 0;
    int oddCount = 0;

    for (int *current = *matrix; current < *matrix + size * size; ++current) {
        if (*current % 2 == 0) {
            ++evenCount;
        } else {
            ++oddCount;
        }
    }

    cout << "\nEven elements: " << evenCount << endl;
    cout << "Odd elements: " << oddCount << endl;

    return 0;
}

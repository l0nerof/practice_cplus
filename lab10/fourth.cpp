#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    const int m = 4, n = 6;
    int a[m][n];

    srand(time(nullptr));

    cout << "Масив 4x6:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = rand() % 21 - 10;
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nСума елементiв кожного стовпчика:\n";
    for (int j = 0; j < n; ++j) {
        int sum = 0;
        for (int i = 0; i < m; ++i)
            sum += a[i][j];

        cout << "Стовпчик " << j + 1 << ": " << sum << endl;
    }
    return 0;
}

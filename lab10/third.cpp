#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    const int m = 5, n = 7;
    int a[m][n];

    srand(time(nullptr));

    cout << "Масив 5x7:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = rand() % 21 - 10;
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nСума елементiв кожного рядка:\n";
    for (int i = 0; i < m; ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j)
            sum += a[i][j];

        cout << "Рядок " << i + 1 << ": " << sum << endl;
    }
    return 0;
}

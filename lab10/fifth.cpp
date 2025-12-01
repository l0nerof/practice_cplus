#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    const int m = 3, n = 4;
    int a[m][n];

    srand(time(nullptr));

    cout << "Масив 3x4:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = rand() % 21 - 10;
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    int maxVal = a[0][0];
    int maxRow = 0, maxCol = 0;

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (a[i][j] > maxVal) {
                maxVal  = a[i][j];
                maxRow = i;
                maxCol = j;
            }

    cout << "\nМаксимальний елемент: " << maxVal << endl;
    cout << "Його позицiя: рядок " << maxRow + 1
         << ", стовпчик " << maxCol + 1 << endl;

    return 0;
}

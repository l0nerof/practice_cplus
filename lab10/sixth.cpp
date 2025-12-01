#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    const int m = 4, n = 7;
    int a[m][n];

    srand(time(nullptr));

    cout << "Масив 4x7:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = rand() % 21 - 10;
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    int minVal = a[0][0];
    int minRow = 0, minCol = 0;

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (a[i][j] < minVal) {
                minVal = a[i][j];
                minRow = i;
                minCol = j;
            }

    cout << "\nМiнiмальний елемент: " << minVal << endl;
    cout << "Його позицiя: рядок " << minRow + 1
         << ", стовпчик " << minCol + 1 << endl;

    return 0;
}

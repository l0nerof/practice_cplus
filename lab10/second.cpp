#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    const int m = 6, n = 4;
    int a[m][n];

    srand(time(nullptr));

    cout << "Масив 6x4:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = rand() % 21 - 10;
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nКiлькiсть парних чисел у кожному стовпчику:\n";
    for (int j = 0; j < n; ++j) {
        int cnt = 0;
        for (int i = 0; i < m; ++i)
            if (a[i][j] % 2 == 0) ++cnt;

        cout << "Стовпчик " << j + 1 << ": " << cnt << endl;
    }
    return 0;
}

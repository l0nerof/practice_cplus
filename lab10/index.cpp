#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    const int m = 4, n = 3;
    int a[m][n];

    srand(time(nullptr));

    cout << "Масив 4x3:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = rand() % 21 - 10;    
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nКiлькiсть парних чисел у кожному рядку:\n";
    for (int i = 0; i < m; ++i) {
        int cnt = 0;
        for (int j = 0; j < n; ++j)
            if (a[i][j] % 2 == 0) ++cnt;

        cout << "Рядок " << i + 1 << ": " << cnt << endl;
    }
    return 0;
}

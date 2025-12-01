#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    const int m = 3, n = 3;
    int a[m][n];

    srand(time(nullptr));

    cout << "Масив 3x3:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = rand() % 21 - 10;
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    int mainDiag = 0;   
    int sideDiag = 0;      

    for (int i = 0; i < m; ++i) {
        mainDiag += a[i][i];
        sideDiag += a[i][n - 1 - i];
    }

    cout << "\nСума по головнiй дiагоналi: " << mainDiag << endl;
    cout << "Сума по побiчнiй дiагоналi: " << sideDiag << endl;

    return 0;
}

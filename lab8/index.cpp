#include <iostream>
using namespace std;

int main() {
    const int M = 12;
    int a[M];

    cout << "Введiть " << M << " цiлих чисел:\n";
    for (int i = 0; i < M; ++i)
        cin >> a[i];

    for (int i = 0; i < M - 1; ++i) {
        for (int j = i + 1; j < M; ++j) {
            if (a[j] < a[i]) {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }

    cout << "Масив, упорядкований за зростанням:\n";
    for (int i = 0; i < M; ++i)
        cout << a[i] << " ";
    cout << endl;

    cout << "Масив, упорядкований за спаданням:\n";
    for (int i = M - 1; i >= 0; --i)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}
#include <iostream>
using namespace std;

int main() {
    const int M = 12;
    int a[M];

    cout << "Введiть " << M << " елементiв масиву:\n";
    for (int i = 0; i < M; ++i)
        cin >> a[i];

    int maxVal = a[0];
    int maxIndex = 0;
    for (int i = 1; i < M; ++i) {
        if (a[i] > maxVal) {
            maxVal = a[i];
            maxIndex = i;      
        }
    }

    for (int i = 0; i < maxIndex; ++i) {
        if (a[i] < 0)
            a[i] = 0;
    }

    cout << "Масив пiсля змiн:\n";
    for (int i = 0; i < M; ++i)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}

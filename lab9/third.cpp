#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    const int N = 12;
    int a[N];

    srand(time(nullptr));

    for (int i = 0; i < N; ++i) {
        int x;
        bool unique;
        do {
            x = rand() % 41 - 20;
            unique = true;
            for (int j = 0; j < i; ++j)
                if (a[j] == x) unique = false;
        } while (!unique);
        a[i] = x;
    }

    cout << "Масив:\n";
    for (int i = 0; i < N; ++i) cout << a[i] << " ";
    cout << endl;

    if (N < 2) {
        cout << "Недостатньо елементiв для другого максимального.\n";
        return 0;
    }

    int max1 = a[0];
    int max2 = a[1];
    if (max2 > max1) swap(max1, max2);

    for (int i = 2; i < N; ++i) {
        if (a[i] > max1) {
            max2 = max1;
            max1 = a[i];
        } else if (a[i] > max2) {
            max2 = a[i];
        }
    }

    cout << "Найбiльший елемент: " << max1 << endl;
    cout << "Другий за величиною елемент: " << max2 << endl;

    return 0;
}
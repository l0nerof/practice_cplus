#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    const int N = 12;
    int a[N];

    srand(time(nullptr));

    for (int i = 0; i < N; ++i)
        a[i] = rand() % 41 - 20;   

    cout << "Масив:\n";
    for (int i = 0; i < N; ++i) cout << a[i] << " ";
    cout << endl;

    int A;
    cout << "Введiть число A: ";
    cin >> A;

    int count = 0;
    for (int i = 0; i < N; ++i)
        if (a[i] > A) ++count;

    cout << "Кiлькiсть елементiв > " << A << " дорiвнює " << count << endl;

    return 0;
}
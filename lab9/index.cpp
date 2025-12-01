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

    cout << "Початковий масив:\n";
    for (int i = 0; i < N; ++i) cout << a[i] << " ";
    cout << endl;

    int minIndex = 0, maxIndex = 0;
    for (int i = 1; i < N; ++i) {
        if (a[i] < a[minIndex]) minIndex = i;
        if (a[i] > a[maxIndex]) maxIndex = i;
    }

    int tmp = a[minIndex];
    a[minIndex] = a[maxIndex];
    a[maxIndex] = tmp;

    cout << "Пiсля обмiну min i max:\n";
    for (int i = 0; i < N; ++i) cout << a[i] << " ";
    cout << endl;

    return 0;
}

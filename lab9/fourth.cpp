
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    const int N = 12;
    int a[N];

    srand(time(nullptr));
    
    for (int i = 0; i < N; ++i)
        a[i] = rand() % 11 - 5;   

    cout << "Масив:\n";
    for (int i = 0; i < N; ++i) cout << a[i] << " ";
    cout << endl;

    int index = -1;
    for (int i = 0; i < N; ++i) {
        if (a[i] == 0) {
            index = i;        
            break;
        }
    }

    if (index == -1)
        cout << "Масив не мiстить нульових елементiв.\n";
    else
        cout << "Перший нульовий елемент має номер (iндекс) "
             << index << " або позицiю " << index + 1 << endl;

    return 0;
}

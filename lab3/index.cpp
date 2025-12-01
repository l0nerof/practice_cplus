#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Введiть трьохзначне додатне число N: ";
    cin >> N;

    if (N < 100 || N > 999) {
        cout << "Число не є трьохзначним додатним!" << endl;
        return 0;
    }

  
    int a = N / 100;        
    int b = (N / 10) % 10;  
    int c = N % 10;         

    int sum = 0;

    if (a > 5) sum += a;
    if (b > 5) sum += b;
    if (c > 5) sum += c;

    cout << "Сума цифр числа " << N
         << ", якi бiльшi за 5, дорiвнює " << sum << endl;

    return 0;
}

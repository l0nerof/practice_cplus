#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Введiть натуральне число N: ";
    cin >> N;

    int sum = 0;
    int temp = N;

    do {
        int digit = temp % 10; 
        if (digit > 5)          
            sum += digit;
        temp /= 10;             
    } while (temp > 0);

    cout << "Сума цифр числа " << N << ", якi бiльшi за 5, дорiвнює " << sum << endl;

    return 0;
}

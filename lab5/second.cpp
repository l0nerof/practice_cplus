#include <iostream>
using namespace std;

int main() {
    int n;
    long long sum = 0;      

    cout << "Введiть 10 натуральних чисел:\n";

    for (int i = 1; i <= 10; ++i) {
        cin >> n;
        sum += 1LL * n * n; 
    }

    cout << "Сума квадратiв = " << sum << endl;

    return 0;
}

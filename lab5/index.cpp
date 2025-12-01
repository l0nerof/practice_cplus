#include <iostream>
#include <cmath>    
using namespace std;

int main() {
    double x, y;

    cout << "Обчислення y = sin^5(x) + |5x - 1.5| для 5 значень x\n";

    for (int i = 1; i <= 5; ++i) {           
        cout << "Введiть x" << i << ": ";
        cin >> x;

        y = pow(sin(x), 5) + fabs(5 * x - 1.5);

        cout << "y(" << x << ") = " << y << endl;
    }

    return 0;
}

#include <iostream>
using namespace std;

int main() {
    double x, a, c, y;

    cout << "Введіть x: ";
    cin >> x;
    cout << "Введіть a: ";
    cin >> a;
    cout << "Введіть c: ";
    cin >> c;

    if (x <= 0) {
        y = 2 * x * x + a;
    } else {
        y = (x + 3 * a) * c;
    }

    cout << "Y = " << y << endl;
    return 0;
}
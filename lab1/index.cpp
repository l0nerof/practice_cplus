#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a = 2;
    double b = 14.36;

    double numerator = 8.15 * cbrt(b) * log(a);
    double denominator = 24.38 * cos(b);

    double y = numerator / denominator;

    cout << "y = " << y << endl;

    return 0;
}

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a = 2;
    double b = 200.0;

    double numerator = 11.21 * (1 + log(b / a));
    double angle = (a / b) * M_PI;  
    double denominator = 1 - sin(angle) * cos(angle);

    double y = pow(numerator / denominator, 2.0 / 3.0);

    cout << "y = " << y << endl;

    return 0;
}

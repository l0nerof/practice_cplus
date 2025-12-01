#include <iostream>
#include <iomanip>   
using namespace std;

int main() {
    double a = 2.3;
    double b = 2.3;
    double c = 2.123456;
    double d = 2.123456;
    double e = 2.123456;

    cout << fixed;

    cout << setprecision(1) << a << endl;

    cout << setprecision(2) << b << endl;

    cout << setprecision(6) << c << endl;

    cout << setprecision(2) << d << endl;

    cout << setprecision(0) << e << endl;

    return 0;
}

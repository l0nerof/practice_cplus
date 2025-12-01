#include <iostream>
#include <cmath>    
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;  

    const double epsilon = 0.000001;

    double r1 = 1.0 / a;
    double r2 = 1.0 / b;

    if (fabs(r1 - r2) < epsilon)
        cout << "Results are equal (by 0.000001 epsilon)" << endl;
    else
        cout << "Results are not equal (by 0.000001 epsilon)" << endl;

    return 0;
}

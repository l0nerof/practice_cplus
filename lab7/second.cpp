#include <iostream>
using namespace std;

int main(void) {
    double pi4 = 0.0;  
    long n;

    cout << "Number of iterations? ";
    cin >> n;

    for (long k = 0; k < n; ++k) {
        double term;

        if (k % 2 == 0)          
            term = 1.0 / (2 * k + 1);
        else                     
            term = -1.0 / (2 * k + 1);

        pi4 += term;
    }

    cout.precision(20);
    cout << "Pi = " << (pi4 * 4.0) << endl; 

    return 0;
}

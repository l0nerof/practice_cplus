#include <iostream>
#include <iomanip>  
#include <cmath>     
using namespace std;

int main() {
    double a, b, h;

    cout << "Введiть a, b i h: ";
    cin >> a >> b >> h;

   
    double x = a;

    cout << "---------------------------\n";
    cout << ":    X    :      Y        :\n";
    cout << "---------------------------\n";

          
    while (x <= b) {
        
        if (fabs(x - 4.0) < 1e-9) {    
            cout << "x = " << x
                 << " не належить ОДЗ (x != 4). Виведення припинено." << endl;
            break;
        }

        double y = 1.0 / ((x - 4.0) * (x - 4.0)) + 6.0;

        cout << ": " << setw(7) << fixed << setprecision(3) << x
             << " : " << setw(10) << fixed << setprecision(6) << y << " :" << endl;

        x += h;
    }

    cout << "---------------------------\n";

    return 0;
}

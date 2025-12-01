#include <iostream>
using namespace std;

int main() {
    long long c0;      
    cin >> c0;         

    int steps = 0;     

    
    while (c0 != 1 && c0 > 0) {
        if (c0 % 2 == 0) {
            c0 = c0 / 2;
        } else {
            c0 = 3 * c0 + 1;
        }

        cout << c0 << endl;  
        steps++;             
    }

    cout << "steps = " << steps << endl;

    return 0;
}

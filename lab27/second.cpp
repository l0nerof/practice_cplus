#include <iostream>
using namespace std;

int main(void) {
    int a = 0, b = 0, c = 0;
    cin >> a;
    cin >> b;

    try {
        if (b == 0) {
            throw b;
        }
        c = a / b;
        cout << c << endl;
    } catch (int) {
        cout << "Your input is not valid, you can't divide by zero." << endl;
    }

    return 0;
}

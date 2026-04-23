#include <iostream>
using namespace std;

const int DivideByZero = 111;

float internaldiv(float arg1, float arg2) {
    if (arg2 == 0.0f) {
        throw DivideByZero;
    }
    return arg1 / arg2;
}

float div(float arg1, float arg2) {
    if (arg2 == 0.0f) {
        throw DivideByZero;
    }
    return internaldiv(arg1, arg2);
}

int main(void) {
    float a, b;

    while (cin >> a >> b) {
        try {
            cout << div(a, b) << endl;
        } catch (int) {
            cout << "Are you kidding me?" << endl;

            try {
                internaldiv(a, b);
            } catch (int) {
                cout << "Your input is not valid. You can't divide by zero." << endl;
            }
        }
    }

    return 0;
}

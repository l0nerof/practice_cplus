#include <iostream>
using namespace std;

int main() {
    double x, y;

    cout << "Введiть координати точки x та y: ";
    cin >> x >> y;


    if (x >= 0 && y >= 0 && x + y <= 2) {
        cout << "Точка належить заштрихованiй областi." << endl;
    } else {
        cout << "Точка НЕ належить заштрихованiй областi." << endl;
    }

    return 0;
}

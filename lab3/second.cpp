#include <iostream>
using namespace std;

int main() {
    int model;
    cout << "Введiть номер моделi автомобiля (1-4): ";
    cin >> model;

    switch (model) {
        case 1:
            cout << "Модель 1: рiк випуску 2015, цiна 20000 $" << endl;
            break;
        case 2:
            cout << "Модель 2: рiк випуску 2018, цiна 25000 $" << endl;
            break;
        case 3:
            cout << "Модель 3: рiк випуску 2020, цiна 30000 $" << endl;
            break;
        case 4:
            cout << "Модель 4: рiк випуску 2022, цiна 35000 $" << endl;
            break;
        default:
            cout << "Моделi з таким номером не iснує!" << endl;
    }

    return 0;
}

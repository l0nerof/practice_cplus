#include <iostream>
using namespace std;

bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int monthLength(int year, int month) {
    int daysInMonths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month < 1 || month > 12) {
        return 0;
    }

    if (month == 2 && isLeap(year)) {
        return 29;
    }

    return daysInMonths[month - 1];
}

int main() {
    for (int yr = 2000; yr < 2002; ++yr) {
        for (int mo = 1; mo <= 12; ++mo) {
            cout << monthLength(yr, mo) << " ";
        }
        cout << endl;
    }

    return 0;
}

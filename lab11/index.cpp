#include <iostream>
using namespace std;

struct Date {
    int hours{0};
    int minutes{0};
};

bool isValidTime(const Date &t) {
    return t.hours >= 0 && t.hours < 24 &&
           t.minutes >= 0 && t.minutes < 60;
}

int main() {
    Date start;
    int deltaMinutes;

    cout << "Початковий час (години): ";
    cin >> start.hours;
    cout << "Початковий час (хвилини): ";
    cin >> start.minutes;

    cout << "Кiлькiсть хвилин, що пройшло: ";
    cin >> deltaMinutes;

    if (!isValidTime(start) || deltaMinutes < 0) {
        cout << "Некоректнi вхiднi данi!" << endl;
        return 0;
    }

    int total = start.hours * 60 + start.minutes + deltaMinutes;

    total %= 24 * 60;

    Date result;
    result.hours = total / 60;
    result.minutes = total % 60;

    cout << result.hours << ":" << result.minutes << endl;

    return 0;
}

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
    Date start, finish;

    cout << "Час початку (години i хвилини): ";
    cin >> start.hours >> start.minutes;

    cout << "Час завершення (години i хвилини): ";
    cin >> finish.hours >> finish.minutes;

    if (!isValidTime(start) || !isValidTime(finish)) {
        cout << "Некоректнi вхiднi данi!" << endl;
        return 0;
    }

    int startTotal  = start.hours  * 60 + start.minutes;
    int finishTotal = finish.hours * 60 + finish.minutes;

    int diff = finishTotal - startTotal;
    if (diff < 0) {
        diff += 24 * 60;
    }

    Date duration;
    duration.hours   = diff / 60;
    duration.minutes = diff % 60;

    cout << duration.hours << ":" << duration.minutes << endl;

    return 0;
}

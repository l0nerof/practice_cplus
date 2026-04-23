#include <ctime>
#include <iostream>
using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int monthLength(int year, int month) {
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            return isLeap(year) ? 29 : 28;
        default:
            return 0;
    }
}

bool isValidDate(const Date &date) {
    if (date.year < 1 || date.month < 1 || date.month > 12) {
        return false;
    }

    int daysInMonth = monthLength(date.year, date.month);
    return date.day >= 1 && date.day <= daysInMonth;
}

Date today() {
    time_t currentTime = time(NULL);
    tm localDate = *localtime(&currentTime);

    Date result;
    result.year = localDate.tm_year + 1900;
    result.month = localDate.tm_mon + 1;
    result.day = localDate.tm_mday;
    return result;
}

long long daysFromStart(const Date &date) {
    long long totalDays = 0;

    for (int year = 1; year < date.year; ++year) {
        totalDays += isLeap(year) ? 366 : 365;
    }

    for (int month = 1; month < date.month; ++month) {
        totalDays += monthLength(date.year, month);
    }

    totalDays += date.day;
    return totalDays;
}

int main() {
    Date birthDate;

    cout << "Enter birth date (year month day): ";
    cin >> birthDate.year >> birthDate.month >> birthDate.day;

    Date currentDate = today();

    if (!isValidDate(birthDate)) {
        cout << "Invalid birth date." << endl;
        return 0;
    }

    if (daysFromStart(birthDate) > daysFromStart(currentDate)) {
        cout << "Birth date cannot be in the future." << endl;
        return 0;
    }

    long long daysPassed = daysFromStart(currentDate) - daysFromStart(birthDate);

    cout << "Today: "
         << currentDate.year << "-"
         << currentDate.month << "-"
         << currentDate.day << endl;

    cout << "Days passed: " << daysPassed << endl;

    return 0;
}

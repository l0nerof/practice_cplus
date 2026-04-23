#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);

    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }

    return a == 0 ? 1 : a;
}

class Fraction {
public:
    Fraction(int numerator, int denominator);
    string toString();
    string toOriginalString() const;
    double toDouble() const;
    bool isGreaterThan(Fraction that);
    bool isLessThan(Fraction that);
    bool isEqual(Fraction that);

private:
    int numerator;
    int denominator;
    void reduce();
};

Fraction::Fraction(int numerator, int denominator) {
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }

    this->numerator = numerator;
    this->denominator = denominator;
}

void Fraction::reduce() {
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }

    int divisor = gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;
}

string Fraction::toOriginalString() const {
    if (numerator == 0) {
        return "0";
    }

    int absNumerator = abs(numerator);
    int wholePart = absNumerator / denominator;
    int remainder = absNumerator % denominator;
    string sign = numerator < 0 ? "-" : "";

    if (remainder == 0) {
        return sign + to_string(wholePart);
    }

    if (wholePart == 0) {
        return sign + to_string(absNumerator) + "/" + to_string(denominator);
    }

    return sign + to_string(wholePart) + " " +
           to_string(remainder) + "/" + to_string(denominator);
}

string Fraction::toString() {
    reduce();

    if (numerator == 0) {
        return "0";
    }

    int absNumerator = abs(numerator);
    int wholePart = absNumerator / denominator;
    int remainder = absNumerator % denominator;
    string sign = numerator < 0 ? "-" : "";

    if (remainder == 0) {
        return sign + to_string(wholePart);
    }

    if (wholePart == 0) {
        return sign + to_string(absNumerator) + "/" + to_string(denominator);
    }

    return sign + to_string(wholePart) + " " +
           to_string(remainder) + "/" + to_string(denominator);
}

double Fraction::toDouble() const {
    return static_cast<double>(numerator) / denominator;
}

bool Fraction::isGreaterThan(Fraction that) {
    long long left = static_cast<long long>(numerator) * that.denominator;
    long long right = static_cast<long long>(that.numerator) * denominator;
    return left > right;
}

bool Fraction::isLessThan(Fraction that) {
    long long left = static_cast<long long>(numerator) * that.denominator;
    long long right = static_cast<long long>(that.numerator) * denominator;
    return left < right;
}

bool Fraction::isEqual(Fraction that) {
    long long left = static_cast<long long>(numerator) * that.denominator;
    long long right = static_cast<long long>(that.numerator) * denominator;
    return left == right;
}

Fraction readFraction() {
    int num = 0;
    int den = 1;
    char slash = '/';
    string input;

    getline(cin, input);
    istringstream parser(input);
    parser >> num >> slash >> den;

    return Fraction(num, den);
}

int main() {
    Fraction first = readFraction();
    Fraction second = readFraction();

    cout << first.toOriginalString() << " ";

    if (first.isGreaterThan(second)) {
        cout << ">";
    } else if (first.isLessThan(second)) {
        cout << "<";
    } else {
        cout << "=";
    }

    cout << " " << second.toOriginalString() << endl;

    return 0;
}
